// Created by Bionic Ape. All Rights Reserved.

#include "Factories/BASequencerHelperFactory.h"
#include "BASequencerHelper.h"

UBASequencerHelperFactory::UBASequencerHelperFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	SupportedClass = UBASequencerHelper::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UBASequencerHelperFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	UBASequencerHelper* NewAsset = NewObject<UBASequencerHelper>(InParent, Class, Name, Flags);
	return NewAsset;
}


