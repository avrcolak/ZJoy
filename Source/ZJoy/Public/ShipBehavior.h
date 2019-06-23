// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "IPossesses.h"
#include "ShipMove.h"
#include "ShipBehavior.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ZJOY_API AShipBehavior : public AController, public IPossesses
{
	GENERATED_BODY()

public:
	AShipBehavior();

	virtual FShipMove GetShipMove();

	virtual void PossessQuickAndDirty_Implementation(class APawn* InPawn) override;

protected:
	FShipMove Pending;
};
