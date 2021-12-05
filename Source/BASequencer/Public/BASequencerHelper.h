// Created by Bionic Ape. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BASequencerHelper.generated.h"

class ULevelSequence;
class UWorld;
class UAnimationAsset;
class USkeletalMesh;

/**
 * 
 */
UCLASS()
class BASEQUENCER_API UBASequencerHelper : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<USkeletalMesh*> SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UAnimationAsset*> Animations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UWorld>> Levels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<ULevelSequence*> Sequences;

};
