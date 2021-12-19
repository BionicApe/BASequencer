// All Rights reserved I Love IceCream LTD.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BASequencerSubsystem.generated.h"

class ULevelSequencePlayer;
class ULevelSequence;
class AActor;
class UBASequencerHelper;

/**
 * 
 */
UCLASS(Config=Engine)
class BASEQUENCER_API UBASequencerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString ExportFilePath = "C:/Dis/DeepAR/Json/";

public:

	virtual void RenderSequences(const UBASequencerHelper* const SequenceHelper, FTransform Transform);

	UFUNCTION()
	void OnLevelSequenceFinished();

	UFUNCTION(BlueprintCallable)
	void CreateJson(AActor* MyActor, ULevelSequence* MySequence, ULevelSequencePlayer* LevelSequencePlayer, int32 const Frame);

};
