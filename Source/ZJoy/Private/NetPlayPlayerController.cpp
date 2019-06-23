// This is free and unencumbered software released into the public domain.


#include "NetPlayPlayerController.h"
#include "NetPlayGameState.h"
#include "NetPlayPlayerId.h"
#include "Engine/ChildConnection.h"
#include "Engine/World.h"
#include "GameFramework/PlayerState.h"

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

	Id = PlayerState->PlayerId;

	ClientSync(CurrentState, CurrentSeed, Id, CurrentFrame);

	for (auto Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		auto Other = Cast<ANetPlayPlayerController>(Iterator->Get());

		if (Other != nullptr && Other != this && Cast<UChildConnection>(Other->Player) == nullptr)
		{
			Other->ClientPeerSync(CurrentFrame, Id);
		}
	}
}

void ANetPlayPlayerController::ClientSync_Implementation(const TArray<uint8>& State, int Seed, int PlayerId, int Frame)
{
	Id = PlayerId;

	GetWorld()->GetGameState<ANetPlayGameState>()->Sync(State, Seed, PlayerId, Frame);

	bSynced = true;
}

void ANetPlayPlayerController::ClientPeerSync_Implementation(int Frame, int PlayerId)
{
	GetWorld()->GetGameState<ANetPlayGameState>()->PeerSync(Frame, PlayerId);
}

void ANetPlayPlayerController::PossessQuickAndDirty_Implementation(APawn* InPawn)
{
	SetPawn(InPawn);
	InPawn->Controller = this;

	UNetPlayPlayerId* PlayerId = Cast<UNetPlayPlayerId>(InPawn->GetComponentByClass(UNetPlayPlayerId::StaticClass()));

	if (PlayerId)
	{
		PlayerId->Id = Id;
	}

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
	GetWorld()->GetGameState<ANetPlayGameState>()->PeerInput(Input, PlayerId, Frame);
}
