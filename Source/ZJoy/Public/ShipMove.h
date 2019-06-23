// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "ShipMove.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct ZJOY_API FShipMove
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float Up;

	UPROPERTY(BlueprintReadWrite)
	float Right;
};
