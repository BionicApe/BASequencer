// Created by Bionic Ape. All Rights Reserved.

#include "Factories/BAKeypointFactory.h"
#include "BAKeypoint.h"

UBAKeypointFactory::UBAKeypointFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	SupportedClass = UBAKeypoint::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UBAKeypointFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	UBAKeypoint* NewAsset = NewObject<UBAKeypoint>(InParent, Class, Name, Flags);
	return NewAsset;
}