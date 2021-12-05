#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BAFrameMetadata.generated.h"


USTRUCT(BlueprintType)
struct BASEQUENCER_API FBASequenceCamera
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 num_keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 num_keyps_3d;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> keyps_3d;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString img_name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString type;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> visible_keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> occluded_keyps;

};

USTRUCT(BlueprintType)
struct BASEQUENCER_API FBASequenceFrameMetadata
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 num_keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 num_keyps_3d;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> keyps_3d;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString img_name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString type;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> visible_keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<float> occluded_keyps;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FBASequenceCamera camera;
};