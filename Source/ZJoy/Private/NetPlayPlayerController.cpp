// This is free and unencumbered software released into the public domain.


#include "NetPlayPlayerController.h"
#include "NetPlayGameState.h"
#include "Engine/ChildConnection.h"
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
	auto GameState = GetWorld()->GetGameState<ANetPlayGameState>();

	auto CurrentFrame = GameState->CurrentFrame;

	auto CurrentSeed = GameState->RandomStream.GetCurrentSeed();

	ClientSync(CurrentFrame, CurrentSeed);

	for (auto Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		auto Other = Cast<ANetPlayPlayerController>(Iterator->Get());

		if (Other != nullptr && Other != this && Cast<UChildConnection>(Other->Player) == nullptr)
		{
			Other->ClientPeerSync(CurrentFrame);
		}
	}
}

void ANetPlayPlayerController::ClientSync_Implementation(int Frame, int Seed)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->Sync(Frame, Seed);
}

void ANetPlayPlayerController::ClientPeerSync_Implementation(int Frame)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->PeerSync(Frame);
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
