// This is free and unencumbered software released into the public domain.


#include "ZJoyGameState.h"
#include "IRecordable.h"
#include "Snapshot.h"
#include "Bullet.h"
#include "ConstructorHelpers.h"
#include "Engine\World.h"

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
