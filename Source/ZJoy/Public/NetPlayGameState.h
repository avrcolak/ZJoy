// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NetPlayGameState.generated.h"

/**
 * 
 */
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

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void PeerSync(int Frame);

	void Sync(int Frame, int Seed);

	UPROPERTY(BlueprintReadOnly)
	int CurrentFrame;

	UPROPERTY(BlueprintReadWrite)
	FRandomStream RandomStream;
};
