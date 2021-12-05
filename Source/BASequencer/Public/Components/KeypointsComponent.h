// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Model/BAKeypointValue.h"
#include "KeypointsComponent.generated.h"

class UBAFrameMetadataModel;
class USkeletalMeshComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASEQUENCER_API UKeypointsComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBAFrameMetadataModel* FrameMetadataModel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FName, USkeletalMeshComponent*> SkeletalsByTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName RootBone;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* RootComp;

public:

	UFUNCTION(BlueprintCallable)
	void GetCurrentKeypointValues(TArray<FBAKeypointValue>& OutKeypointValues) const;

	UFUNCTION(BlueprintCallable)
	USkeletalMeshComponent* GetSkelMeshCompByTag(const FName& Tag) const;

};
