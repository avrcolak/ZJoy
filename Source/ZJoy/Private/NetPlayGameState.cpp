// This is free and unencumbered software released into the public domain.

#include "NetPlayGameState.h"
#include "NetPlayPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"

ANetPlayGameState::ANetPlayGameState()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	RandomStream.GenerateNewSeed();
}

void ANetPlayGameState::BeginPlay()
{
	Super::BeginPlay();

	ANetPlayPlayerController* FirstLocalPlayerController = nullptr;

	for (auto Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		FirstLocalPlayerController = Cast<ANetPlayPlayerController>(Iterator->Get());

		if (FirstLocalPlayerController != nullptr)
		{
			break;
		}
	}

	if (FirstLocalPlayerController != nullptr)
	{
		FirstLocalPlayerController->ServerSync();
	}
}

void ANetPlayGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CurrentFrame++;
}

void ANetPlayGameState::Sync(int Frame, int Seed)
{
	SetActorTickEnabled(true);
	
	CurrentFrame = Frame;

	RandomStream.Initialize(Seed);

	ReceiveSync();
}

void ANetPlayGameState::PeerSync(int Frame)
{
	ReceivePeerSync();
}