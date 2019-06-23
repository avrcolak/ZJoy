// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "IRollsBack.h"
#include "NetPlayGameState.generated.h"

/**
 * 
 */

#define NETPLAY_HISTORY 360

struct ReadAndRecieved
{
	int Read;
	int Recieved;
};

UCLASS()
class ZJOY_API ANetPlayGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ANetPlayGameState();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnSync", ScriptName = "OnSync"))
	void ReceiveSync();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnPeerSync", ScriptName = "OnPeerSync"))
	void ReceivePeerSync(int PlayerId);

	UFUNCTION(BlueprintCallable)
	void RegisterForRollback(AActor* Actor);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual TArray<uint8> State();

	virtual void SyncState(const TArray<uint8>&);

	virtual void PeerSync(int Frame, int PlayerId);

	virtual void Sync(const TArray<uint8>& State, int Seed, int PlayerId, int Frame);

	void PeerInput(const TArray<uint8>& Input, int PlayerId, int Frame);

	int EarliestUnread();

	int MinimumRead();

	UPROPERTY(BlueprintReadOnly)
	int CurrentFrame;

	UPROPERTY(BlueprintReadWrite)
	FRandomStream RandomStream;

	TArray<AActor*> NetPlayRelevant;

	TMap<int, ReadAndRecieved> ReadAndRecievedForPlayer;
};
