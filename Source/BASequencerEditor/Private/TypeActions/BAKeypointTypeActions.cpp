// All Rights reserved I Love IceCream LTD.

#include "TypeActions/BAKeypointTypeActions.h"
#include "Model/BAKeypoint.h"

#define LOCTEXT_NAMESPACE "BAKeypoint_TypeActions"

FBAKeypointTypeActions::FBAKeypointTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{
}

FText FBAKeypointTypeActions::GetName() const
{
	return LOCTEXT("FBAKeypointTypeActionsName", "BAKeypoint");
}

FColor FBAKeypointTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

UClass* FBAKeypointTypeActions::GetSupportedClass() const
{
	return UBAKeypoint::StaticClass();
}

uint32 FBAKeypointTypeActions::GetCategories()
{
	return AssetCategory;
}

#undef LOCTEXT_NAMESPACE