// All Rights reserved I Love IceCream LTD.

#include "Factories/BAFrameMetadataModelFactory.h"
#include "Model/BAFrameMetadataModel.h"

UBAFrameMetadataModelFactory::UBAFrameMetadataModelFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	SupportedClass = UBAFrameMetadataModel::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UBAFrameMetadataModelFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	UBAFrameMetadataModel* NewAsset = NewObject<UBAFrameMetadataModel>(InParent, Class, Name, Flags);
	return NewAsset;
}


