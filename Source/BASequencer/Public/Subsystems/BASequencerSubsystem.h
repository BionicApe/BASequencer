// Created by Bionic Ape. All Rights Reserved.

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
UCLASS()
class BASEQUENCER_API UBASequencerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	FString ExportFilePath;

public:

	virtual void RenderSequences(const UBASequencerHelper* const SequenceHelper, FTransform Transform);

	UFUNCTION()
	void OnLevelSequenceFinished();

	UFUNCTION(BlueprintCallable)
	void CreateJson(AActor* MyActor, ULevelSequence* MySequence, ULevelSequencePlayer* LevelSequencePlayer, int32 const Frame);

};
