// Created by Bionic Ape. All Rights Reserved.

#include "TypeActions/BAFrameMetadataModelTypeActions.h"
#include "BAFrameMetadataModel.h"

#define LOCTEXT_NAMESPACE "BAFrameMetadataModel_TypeActions"

FBAFrameMetadataModelTypeActions::FBAFrameMetadataModelTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{
}

FText FBAFrameMetadataModelTypeActions::GetName() const
{
	return LOCTEXT("FBAFrameMetadataModelTypeActionsName", "BAFrameMetadataModel");
}

FColor FBAFrameMetadataModelTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

UClass* FBAFrameMetadataModelTypeActions::GetSupportedClass() const
{
	return UBAFrameMetadataModel::StaticClass();
}

uint32 FBAFrameMetadataModelTypeActions::GetCategories()
{
	return AssetCategory;
}

#undef LOCTEXT_NAMESPACE