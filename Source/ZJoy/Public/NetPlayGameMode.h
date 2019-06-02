// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetPlayGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API ANetPlayGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void RestartPlayer(AController* NewPlayer) override;
};
