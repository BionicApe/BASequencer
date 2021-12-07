// Created by Bionic Ape. All Rights Reserved.


#include "Subsystems/BASequencerSubsystem.h"
#include "Engine/SkeletalMesh.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/World.h"
#include "Animation/AnimationAsset.h"
#include "BASequencerHelper.h"
#include "LevelSequence/Public/DefaultLevelSequenceInstanceData.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "Actors/BALevelSequenceActor.h"
#include "Components/KeypointsComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Model/BAFrameMetadataModel.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h"


void UBASequencerSubsystem::RenderSequences(const UBASequencerHelper* const SequenceHelper, FTransform Transform)
{
	ASkeletalMeshActor* Performer = GetWorld()->SpawnActor<ASkeletalMeshActor>(ABALevelSequenceActor::StaticClass(), Transform);

	for (TSoftObjectPtr<UWorld> Level : SequenceHelper->Levels)
	{
		for (USkeletalMesh* SkeletalMesh : SequenceHelper->SkeletalMesh)
		{
			Performer->GetSkeletalMeshComponent()->SetSkeletalMesh(SkeletalMesh);

			for (ULevelSequence* Sequence : SequenceHelper->Sequences)
			{
				for (UAnimationAsset* Animation : SequenceHelper->Animations)
				{
					ABALevelSequenceActor* SequenceActor = GetWorld()->SpawnActor<ABALevelSequenceActor>(ABALevelSequenceActor::StaticClass(), Transform);
					SequenceActor->SetSequence(Sequence);
					SequenceActor->bOverrideInstanceData = true;

					if (UDefaultLevelSequenceInstanceData* DefaultInstanceData = Cast<UDefaultLevelSequenceInstanceData>(SequenceActor->DefaultInstanceData))
					{
						//TODO: Take this actor from the Level that is being streamed
						//DefaultInstanceData->TransformOriginActor = SequenceRootActor;
					}

					if (ULevelSequencePlayer* LevelSequencePlayer = SequenceActor->GetSequencePlayer())
					{
						LevelSequencePlayer->OnFinished.AddDynamic(this, &UBASequencerSubsystem::OnLevelSequenceFinished);
					}

					//////////////
					SequenceActor->ResetBindings();
					SequenceActor->AddBindingByTag(TEXT("Performer"), Performer);

					//SequenceRootActor->SetActorTransform(ArenaPerformance.Receiver->GetActorTransform());//Again, we take this from the UWorld

					if (ULevelSequencePlayer* LevelSequencePlayer = SequenceActor->GetSequencePlayer())
					{
						LevelSequencePlayer->Play();
					}
					//////////////
				}
			}
		}
	}
}


void UBASequencerSubsystem::OnLevelSequenceFinished()
{

	//We play the next Sequence
}

void UBASequencerSubsystem::CreateJson(AActor* MyActor, ULevelSequence* MySequence, ULevelSequencePlayer* LevelSequencePlayer, int32 const Frame)
{

#pragma region Checks

	if (!MyActor)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): MyActor is null"));
		return;
	}

	UKeypointsComponent* KeypointsComponent = Cast<UKeypointsComponent>(MyActor->GetComponentByClass(UKeypointsComponent::StaticClass()));
	if (!KeypointsComponent)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): KeypointsComponent is null"));
		return;
	}
	
	if (!LevelSequencePlayer)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): LevelSequencePlayer is null"));
		return;
	}

	UCameraComponent* CameraComponent = LevelSequencePlayer->GetActiveCameraComponent();
	if (!CameraComponent)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): CameraComponent is null"));
		return;
	}



#pragma endregion

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	TArray<FBAKeypointValue> KeypointValues;
	KeypointsComponent->GetCurrentKeypointValues(KeypointValues);

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	JsonObject->SetNumberField(TEXT("num_keyps"), KeypointValues.Num());
	
	FString const FileName = FString::Printf(TEXT("%s%s"), *LevelSequencePlayer->GetName(), *FString::FromInt(Frame));
	FString const ImageFileName = FString::Printf(TEXT("%s%s"), *LevelSequencePlayer->GetName(), *FString::FromInt(Frame));


	JsonObject->SetStringField(TEXT("img_name"), *FString::Printf(TEXT("%s%s%s"), *FileName, TEXT(".png")));

	TArray<TSharedPtr<FJsonValue>> KeypointsValues;
	TArray<TSharedPtr<FJsonValue>> KeypointsScreen;
	TArray<TSharedPtr<FJsonValue>> VisibleKeypoints;
	TArray<TSharedPtr<FJsonValue>> OccludedKeypoints;


	for (FBAKeypointValue Kpv : KeypointValues)
	{
		FVector const KpWorldLocation = Kpv.WorldTransform.GetLocation();

		KeypointsValues.Add(MakeShared<FJsonValueNumber>(KpWorldLocation.X));
		KeypointsValues.Add(MakeShared<FJsonValueNumber>(KpWorldLocation.Y));
		KeypointsValues.Add(MakeShared<FJsonValueNumber>(KpWorldLocation.Z));

		FVector2D ScreenPosition;
		UGameplayStatics::ProjectWorldToScreen(PC, KpWorldLocation, ScreenPosition);
		KeypointsScreen.Add(MakeShared<FJsonValueNumber>(ScreenPosition.X));
		KeypointsScreen.Add(MakeShared<FJsonValueNumber>(ScreenPosition.Y));
	}

	JsonObject->SetArrayField(TEXT("keyps"), KeypointsScreen);
	JsonObject->SetArrayField(TEXT("keyps_3d"), KeypointsValues);
	JsonObject->SetStringField(TEXT("type"), KeypointsComponent->FrameMetadataModel->Type);
	JsonObject->SetArrayField(TEXT("visible_keyps"), VisibleKeypoints);
	JsonObject->SetArrayField(TEXT("occluded_keyps"), OccludedKeypoints);	

	TSharedPtr<FJsonObject> CameraJson = MakeShareable(new FJsonObject());
	CameraJson->SetNumberField(TEXT("fovy"), CameraComponent->FieldOfView);
	CameraJson->SetNumberField(TEXT("aspect_ratio"), CameraComponent->AspectRatio);
	FIntPoint ScreenResolution = GEngine->GetGameUserSettings()->GetScreenResolution();
	CameraJson->SetNumberField(TEXT("width"), ScreenResolution.X);
	CameraJson->SetNumberField(TEXT("height"), ScreenResolution.Y);
	JsonObject->SetObjectField(TEXT("camera"),CameraJson);

	TSharedPtr<FJsonObject> ObjectPose = MakeShareable(new FJsonObject());
	//			"obj_pose": {
	//				"rot_mat": [1.0, 0.0, ...] , ## 9 values rotation matrix openGL format
	//					"quat" : [] , ## quaternion(4 values)
	//					"position”: [],     ## object position (3 values) in the camera CS
	//					"scale" : [1.0, 1.0, 1.0] ,
	//			}
	JsonObject->SetObjectField(TEXT("obj_pose"), ObjectPose);

	//Save it to a file
	//FFileHelper::SaveStringToFile(LoadedBoilerplates	, *FString::Printf(TEXT("%s%s%hs"), *ExportFilePath, *NewModuleName, ".h"));

}
