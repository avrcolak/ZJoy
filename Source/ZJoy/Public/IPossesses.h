// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPossesses.generated.h"

UINTERFACE(MinimalAPI)
class UPossesses : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZJOY_API IPossesses
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PossessQuickAndDirty(class APawn* InPawn);

	virtual void PossessQuickAndDirty_Implementation(class APawn* InPawn) = 0;
};
