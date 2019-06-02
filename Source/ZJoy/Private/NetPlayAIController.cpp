// This is free and unencumbered software released into the public domain.


#include "NetPlayAIController.h"
#include "Engine/World.h"

ANetPlayAIController::ANetPlayAIController()
{
	bCanPossessWithoutAuthority = true;
}

void ANetPlayAIController::PossessQuickAndDirty(APawn* InPawn)
{
	SetPawn(InPawn);
	InPawn->Controller = this;
}
