// This is free and unencumbered software released into the public domain.


#include "ZJoyGameState.h"
#include "IRecordable.h"
#include "NetPlayPlayerController.h"
#include "ShipMove.h"
#include "ShipBehavior.h"
#include "Snapshot.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerState.h"

TArray<uint8> AZJoyGameState::State()
{
	auto Snapshots = TArray<FSnapshot, TInlineAllocator<100>>();

	Snapshots.Reserve(NetPlayRelevant.Num());

	for (auto Iterator = NetPlayRelevant.CreateIterator(); Iterator; ++Iterator)
	{
		auto Recordable = Cast<IRecordable>(*Iterator);

		auto Snapshot = Recordable->Snapshot();

		Snapshots.Add(Snapshot);
	}

	auto Ptr = (uint8*) Snapshots.GetData();

	auto Size = Snapshots.Num() * Snapshots.GetTypeSize();

	return TArray<uint8>(Ptr, Size);
}

void AZJoyGameState::SyncState(const TArray<uint8>& State)
{
	auto Snapshots = (FSnapshot*) State.GetData();

	auto Num = State.Num() / sizeof(FSnapshot);

	for (int i = 0; i < Num; i++)
	{
		auto Snapshot = Snapshots[i];

		auto Class = FindObject<UClass>(ANY_PACKAGE, Snapshot.Name);

		if (Class)
		{
			auto Recordable = GetWorld()->SpawnActor<IRecordable>(Class);

			Recordable->LoadSnapshot(Snapshot);
		}
	}
}

void AZJoyGameState::Sync(const TArray<uint8>& State, int Seed, int PlayerId, int Frame)
{
	Super::Sync(State, Seed, Frame, PlayerId);

	auto& NewMovesHistory = ShipMoves.Add(PlayerId);
	NewMovesHistory.SetNum(NETPLAY_HISTORY);
}

void AZJoyGameState::PeerSync(int Frame, int PlayerId)
{
	auto& NewMovesHistory = ShipMoves.Add(PlayerId);
	NewMovesHistory.SetNum(NETPLAY_HISTORY);

	Super::PeerSync(Frame, PlayerId);
}

void AZJoyGameState::AddShipMove(int PlayerId, int Frame, FShipMove Move)
{
	ShipMoves[PlayerId][Frame % NETPLAY_HISTORY] = Move;
}

void AZJoyGameState::AddShipMoveForNextFrame(int PlayerId, FShipMove Move)
{
	ShipMoves[PlayerId][(CurrentFrame + 1) % NETPLAY_HISTORY] = Move;
}

FShipMove AZJoyGameState::GetShipMove(int PlayerId)
{
	return ShipMoves[PlayerId][CurrentFrame % NETPLAY_HISTORY];
}