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
	void ReceivePeerSync();

	UFUNCTION(BlueprintCallable)
	void RegisterForRollback(AActor* Actor);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual TArray<uint8> State();

	virtual void SyncState(const TArray<uint8>&);

	void PeerSync(int Frame);

	void Sync(const TArray<uint8>& State, int Frame, int Seed);

	void PeerInput(int Player, int Frame, const TArray<uint8>& Input);

	int EarliestUnread();

	int MinimumRead();

	UPROPERTY(BlueprintReadOnly)
	int CurrentFrame;

	UPROPERTY(BlueprintReadWrite)
	FRandomStream RandomStream;

	TArray<AActor*> NetPlayRelevant;

	TMap<int, ReadAndRecieved> ReadAndRecievedForPlayer;
};
