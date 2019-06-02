// This is free and unencumbered software released into the public domain.

#include "NetPlayGameState.h"
#include "NetPlayPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"

ANetPlayGameState::ANetPlayGameState()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ANetPlayGameState::BeginPlay()
{
	Super::BeginPlay();

	auto Client = GetWorld()->GetFirstPlayerController<ANetPlayPlayerController>();

	Client->ServerSync();
}

void ANetPlayGameState::Sync(int Frame)
{

	SetActorTickEnabled(true);
	SyncFrame = Frame;

	K2_OnSync();
}