// All Rights reserved I Love IceCream LTD.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BAKeypoint.generated.h"

UENUM(BlueprintType)
enum class EKeypointType : uint8
{
	BONE = 0 UMETA(DisplayName = "Bone"),
	SOCKET = 1 UMETA(DisplayName = "Socket"),
	VERTEX = 2 UMETA(DisplayName = "Vertex"),
};


/**
 *
 */
UCLASS()
class BASEQUENCER_API UBAKeypoint : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString KeypointName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EKeypointType KeypointType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MeshTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName BoneSocketName;
};