// All Rights reserved I Love IceCream LTD.

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ScreenPosition;

	FBAKeypointValue() :Keypoint(nullptr), RelativeTransform(FTransform()), WorldTransform(FTransform())
	{

	}
};