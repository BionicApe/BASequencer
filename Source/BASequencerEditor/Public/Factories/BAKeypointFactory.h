// All Rights reserved I Love IceCream LTD.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "BAKeypointFactory.generated.h"

/**
*
*/
UCLASS()
class BASEQUENCEREDITOR_API UBAKeypointFactory : public UFactory
{
	GENERATED_BODY()


	UBAKeypointFactory(const FObjectInitializer& ObjectInitializer);

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override { return true; }
	// End of UFactory interface

};
