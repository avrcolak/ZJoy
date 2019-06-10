// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "NetPlayGameState.h"
#include "ZJoyGameState.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API AZJoyGameState : public ANetPlayGameState
{
	GENERATED_BODY()
	
	virtual TArray<uint8> State() override;

	virtual void SyncState(const TArray<uint8>&) override;
};
