// Created by Bionic Ape. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BAFrameMetadataModel.generated.h"

class UBAKeypoint;

/**
 * 
 */
UCLASS()
class BASEQUENCER_API UBAFrameMetadataModel : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UBAKeypoint*> Keypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Type = "full-body-19";	
};
