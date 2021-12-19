// All Rights reserved I Love IceCream LTD.

#include "Factories/BAKeypointFactory.h"
#include "Model/BAKeypoint.h"

UBAKeypointFactory::UBAKeypointFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	SupportedClass = UBAKeypoint::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UBAKeypointFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	UBAKeypoint* NewAsset = NewObject<UBAKeypoint>(InParent, Class, Name, Flags);
	return NewAsset;
}