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
	void K2_OnSync();

	virtual void BeginPlay() override;

	void Sync(int Frame);

	int SyncFrame;

	int CurrentFrame;
};
