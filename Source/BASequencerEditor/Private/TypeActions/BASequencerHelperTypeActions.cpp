// All Rights reserved I Love IceCream LTD.

#include "TypeActions/BASequencerHelperTypeActions.h"
#include "BASequencerHelper.h"

#define LOCTEXT_NAMESPACE "BASequencerHelper_TypeActions"

FBASequencerHelperTypeActions::FBASequencerHelperTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{
}

FText FBASequencerHelperTypeActions::GetName() const
{
	return LOCTEXT("FBASequencerHelperTypeActionsName", "BASequencerHelper");
}

FColor FBASequencerHelperTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

UClass* FBASequencerHelperTypeActions::GetSupportedClass() const
{
	return UBASequencerHelper::StaticClass();
}

uint32 FBASequencerHelperTypeActions::GetCategories()
{
	return AssetCategory;
}

#undef LOCTEXT_NAMESPACE