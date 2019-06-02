// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetPlayAIController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ZJOY_API ANetPlayAIController : public AController
{
	GENERATED_BODY()

public:
	ANetPlayAIController();

	UFUNCTION(BlueprintCallable)
	void PossessQuickAndDirty(class APawn* InPawn);
};
