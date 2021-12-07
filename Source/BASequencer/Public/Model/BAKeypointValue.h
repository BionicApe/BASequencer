// Created by Bionic Ape. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BAKeypointValue.generated.h"

class UBAKeypoint;

USTRUCT(BlueprintType)
struct BASEQUENCER_API FBAKeypointValue
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	const UBAKeypoint* Keypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform RelativeTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform WorldTransform;

	FBAKeypointValue() :Keypoint(nullptr), RelativeTransform(FTransform()), WorldTransform(FTransform())
	{

	}
};