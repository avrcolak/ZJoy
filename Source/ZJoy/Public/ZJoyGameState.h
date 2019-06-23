// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "NetPlayGameState.h"
#include "ShipMove.h"
#include "ZJoyGameState.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API AZJoyGameState : public ANetPlayGameState
{
	GENERATED_BODY()

public:
	virtual TArray<uint8> State() override;

	virtual void SyncState(const TArray<uint8>&) override;

	virtual void Sync(const TArray<uint8>& State, int Seed, int PlayerId, int Frame) override;

	virtual void PeerSync(int Frame, int PlayerId) override;

	void AddShipMoveForNextFrame(int PlayerId, FShipMove Move);

	void AddShipMove(int PlayerId, int Frame, FShipMove Move);

	UFUNCTION(BlueprintCallable)
	FShipMove GetShipMove(int PlayerId);

private:
	TMap<int, TArray<FShipMove>> ShipMoves;
};
