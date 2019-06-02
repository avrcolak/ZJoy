// This is free and unencumbered software released into the public domain.


#include "NetPlayPlayerController.h"
#include "NetPlayGameState.h"
#include "Engine/World.h"

ANetPlayPlayerController::ANetPlayPlayerController()
{
	bCanPossessWithoutAuthority = true;
}

bool ANetPlayPlayerController::ServerSync_Validate()
{
	return true;
}

void ANetPlayPlayerController::ServerSync_Implementation()
{
	ClientSync(GetWorld()->GetGameState<ANetPlayGameState>()->CurrentFrame);
}

void ANetPlayPlayerController::ClientSync_Implementation(int Frame)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->Sync(Frame);
}

void ANetPlayPlayerController::PossessQuickAndDirty(APawn* InPawn)
{
	SetPawn(InPawn);
	InPawn->Controller = this;

	if (bAutoManageActiveCameraTarget)
	{
		AutoManageActiveCameraTarget(GetPawn());
		ResetCameraMode();
	}
}
