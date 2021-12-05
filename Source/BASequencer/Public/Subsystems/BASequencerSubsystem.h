// Created by Bionic Ape. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BASequencerSubsystem.generated.h"

class UBASequencerHelper;

/**
 * 
 */
UCLASS()
class BASEQUENCER_API UBASequencerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual void RenderSequences(const UBASequencerHelper* const SequenceHelper, FTransform Transform);

	UFUNCTION()
	void OnLevelSequenceFinished();

	UFUNCTION(BlueprintCallable)
	void CreateJson(UWorld* MyWorld, ULevelSequence* MySequence, AActor* MyActor);

};
