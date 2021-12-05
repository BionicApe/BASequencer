// Created by Bionic Ape. All Rights Reserved.

#include "BASequencerEditor.h"
#include "TypeActions/BASequencerHelperTypeActions.h"
#include "IAssetTools.h"

#define LOCTEXT_NAMESPACE "FBASequencerEditorModule"

void FBASequencerEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	EAssetTypeCategories::Type AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("BASequencerEditor")), LOCTEXT("BionicApeUI", "BionicApeUI"));
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FBASequencerHelperTypeActions(AssetCategoryBit)));
}

void FBASequencerEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBASequencerEditorModule, BASequencerEditor)