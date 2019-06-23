// This is free and unencumbered software released into the public domain.


#include "ShipBehavior.h"
#include "Engine/World.h"

AShipBehavior::AShipBehavior()
{
	bCanPossessWithoutAuthority = true;
}

void AShipBehavior::PossessQuickAndDirty_Implementation(APawn* InPawn)
{
	SetPawn(InPawn);
	InPawn->Controller = this;
}

FShipMove AShipBehavior::GetShipMove()
{
	return Pending;
}