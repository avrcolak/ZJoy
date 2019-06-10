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

	auto CurrentState = GameState->State();

	ClientSync(CurrentState, CurrentFrame, CurrentSeed);

	for (auto Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		auto Other = Cast<ANetPlayPlayerController>(Iterator->Get());

		if (Other != nullptr && Other != this && Cast<UChildConnection>(Other->Player) == nullptr)
		{
			Other->ClientPeerSync(CurrentFrame);
		}
	}
}

void ANetPlayPlayerController::ClientSync_Implementation(const TArray<uint8>& State, int Frame, int Seed)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->Sync(State, Frame, Seed);
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

bool ANetPlayPlayerController::ServerInput_Validate(int PlayerId, int Frame, const TArray<uint8>& Input)
{
	return true;
}

void ANetPlayPlayerController::ServerInput_Implementation(int PlayerId, int Frame, const TArray<uint8>& Input)
{
	return;
}

void ANetPlayPlayerController::ClientPeerInput_Implementation(int PlayerId, int Frame, const TArray<uint8>& Input)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->PeerInput(PlayerId, Frame, Input);
}
