// All Rights reserved I Love IceCream LTD.

#include "BASequencerEditorModule.h"
#include "TypeActions/BASequencerHelperTypeActions.h"
#include "IAssetTools.h"
#include "TypeActions/BAKeypointTypeActions.h"
#include "TypeActions/BAFrameMetadataModelTypeActions.h"

#define LOCTEXT_NAMESPACE "FBASequencerEditorModule"

void FBASequencerEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	EAssetTypeCategories::Type AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("SequencerEditor")), LOCTEXT("BASequencer", "BASequencer"));
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FBASequencerHelperTypeActions(AssetCategoryBit)));
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FBAKeypointTypeActions(AssetCategoryBit)));
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FBAFrameMetadataModelTypeActions(AssetCategoryBit)));
}

void FBASequencerEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBASequencerEditorModule, BASequencerEditor)