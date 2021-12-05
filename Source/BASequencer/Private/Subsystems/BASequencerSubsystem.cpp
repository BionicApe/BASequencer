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

void UBASequencerSubsystem::CreateJson(UWorld* MyWorld, ULevelSequence* MySequence, AActor* MyActor)
{

#pragma region Checks

	if (!MyActor)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): MyActor is null"));
		return;
	}

	UKeypointsComponent* KeypointsComponent = Cast<UKeypointsComponent>(MyActor->GetComponentByClass(UKeypointsComponent::StaticClass()));
	if (!MyActor)
	{
		UE_LOG(LogTemp, Log, TEXT("CreateJson(): MyActor is null"));
		return;
	}

#pragma endregion

	TArray<FBAKeypointValue> OutKeypointValues;
	KeypointsComponent->GetCurrentKeypointValues(OutKeypointValues);
	for (FBAKeypointValue Kpv : OutKeypointValues)
	{
		
	}

	//TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	//JsonObject->SetStringField(TEXT("PK"), Inventory->Id);
	//JsonObject->SetStringField(TEXT("SK"), TEXT("Inventory"));
	//JsonObject->SetNumberField(TEXT("Coins"), Inventory->GetCoins());

	//TArray<TSharedPtr<FJsonValue>> EntriesArray;
	//for (UInventoryItemEntry* Entry : Inventory->GetEntries())
	//{
	//	TSharedPtr<FJsonObject> JsonObjectEntry = MakeShareable(new FJsonObject());
	//	JsonObjectEntry->SetStringField(TEXT("Item"), FStringAssetReference(Entry->Item).ToString());
	//	JsonObjectEntry->SetNumberField(TEXT("Amount"), Entry->GetAmount());
	//	JsonObjectEntry->SetNumberField(TEXT("Price"), Entry->Price);
	//	EntriesArray.Add(MakeShareable(new FJsonValueObject(JsonObjectEntry)));
	//}
	//JsonObject->SetArrayField(TEXT("Entries"), EntriesArray);

}
