// This is free and unencumbered software released into the public domain.

#include "NetPlayGameState.h"
#include "NetPlayPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"

ANetPlayGameState::ANetPlayGameState()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ANetPlayGameState::BeginPlay()
{
	Super::BeginPlay();

	ANetPlayPlayerController* FirstLocalPlayerController = nullptr;

	for (auto Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		auto PlayerController = Cast<ANetPlayPlayerController>(Iterator->Get());

		if (PlayerController)
		{
			AddTickPrerequisiteActor(PlayerController);

			ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);

			if (LocalPlayer && FirstLocalPlayerController == nullptr)
			{
				FirstLocalPlayerController = PlayerController;
			}
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

	auto Unread = EarliestUnread();

	if (Unread <= CurrentFrame)
	{
		auto OneBeforeUnread = Unread - 1;

		for (auto& Relevant : NetPlayRelevant)
		{
			auto RollsBack = Cast<IRollsBack>(Relevant);

			RollsBack->Rollback(CurrentFrame - OneBeforeUnread);
		}

		auto ReplayFrame = CurrentFrame;

		for (int CurrentFrame = Unread; CurrentFrame <= ReplayFrame; CurrentFrame++)
		{
			for (auto& Relevant : NetPlayRelevant)
			{
				Relevant->Tick(DeltaSeconds);
			}
		}
	}
	else
	{
		CurrentFrame++;
	}
}

TArray<uint8> ANetPlayGameState::State()
{
	return TArray<uint8>();
}

void ANetPlayGameState::SyncState(const TArray<uint8>& State)
{
	return;
}

void ANetPlayGameState::Sync(const TArray<uint8>& State, int Frame, int Seed)
{
	SetActorTickEnabled(true);

	SyncState(State);
	
	CurrentFrame = Frame;

	RandomStream.Initialize(Seed);

	ReceiveSync();
}

void ANetPlayGameState::PeerSync(int Frame)
{
	ReceivePeerSync();
}

void ANetPlayGameState::PeerInput(int Player, int Frame, const TArray<uint8>& Input)
{
	// This needs to be handled more gracefully at some point.
	check(Frame < MinimumRead() + NETPLAY_HISTORY);

	ReadAndRecievedForPlayer[Player].Recieved = Frame;
}

int ANetPlayGameState::MinimumRead()
{
	int Min = INT_MAX;

	for (auto& Pair : ReadAndRecievedForPlayer)
	{
		Min = FMath::Min(Pair.Value.Read, Min);
	}

	return Min;
}

int ANetPlayGameState::EarliestUnread()
{
	int Min = INT_MAX;

	for (auto& Pair : ReadAndRecievedForPlayer)
	{
		if (Pair.Value.Recieved > Pair.Value.Read)
		{
			Min = FMath::Min(Pair.Value.Read + 1, Min);
		}
	}

	return Min;
}

void ANetPlayGameState::RegisterForRollback(AActor* Actor)
{
	NetPlayRelevant.Add(Actor);
	Actor->AddTickPrerequisiteActor(this);
}
