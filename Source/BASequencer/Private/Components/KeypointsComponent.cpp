// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/KeypointsComponent.h"
#include "Model/BAFrameMetadataModel.h"
#include "Model/BAKeypoint.h"

void UKeypointsComponent::GetCurrentKeypointValues(TArray<FBAKeypointValue>& OutKeypointValues) const
{
	OutKeypointValues.Empty();


	int32 const RootBoneIndex = RootComp->GetBoneIndex(RootBone);
	FTransform const RootTransform = RootComp->GetBoneTransform(RootBoneIndex);

	for (const UBAKeypoint* const Keypoint : FrameMetadataModel->Keypoints)
	{
		int32 const KpvIndex = OutKeypointValues.Emplace();
		FBAKeypointValue& Kpv = OutKeypointValues[KpvIndex];

		Kpv.Keypoint = Keypoint;

		USkeletalMeshComponent* MeshComp = GetSkelMeshCompByTag(Keypoint->MeshTag);
		if (!MeshComp)
		{
			UE_LOG(LogTemp, Log, TEXT("No Mesh for tag %s set in keypoint: %s"), *Keypoint->MeshTag.ToString(), *Keypoint->KeypointName);
			continue;
		}

		switch (Keypoint->KeypointType)
		{
		case EKeypointType::BONE:
		{
			int32 const BoneIndex = MeshComp->GetBoneIndex(Keypoint->BoneSocketName);
			if (INDEX_NONE)
			{
				UE_LOG(LogTemp, Log, TEXT("No index for bone: %s"), *Keypoint->BoneSocketName.ToString());
				continue;
			}

			Kpv.RelativeTransform = MeshComp->GetBoneTransform(BoneIndex, RootTransform);
			Kpv.WorldTransform = MeshComp->GetBoneTransform(BoneIndex);
			break;
		}
		case EKeypointType::SOCKET:
		{
			Kpv.RelativeTransform = MeshComp->GetSocketTransform(Keypoint->BoneSocketName, ERelativeTransformSpace::RTS_Component);
			Kpv.WorldTransform = MeshComp->GetSocketTransform(Keypoint->BoneSocketName, ERelativeTransformSpace::RTS_World);
			break;
		}
		case EKeypointType::VERTEX:
		{
			break;
		}
		}
	}
}

USkeletalMeshComponent* UKeypointsComponent::GetSkelMeshCompByTag(const FName& Tag) const
{
	if (SkeletalsByTag.Contains(Tag))
	{
		return SkeletalsByTag[Tag];
	}

	return nullptr;
}
