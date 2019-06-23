// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "NetPlayPlayerController.h"
#include "ShipMove.h"
#include "ZJoyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API AZJoyPlayerController : public ANetPlayPlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	void MoveUp(float AxisValue);

	void MoveRight(float AxisValue);

	struct FShipMove Pending;
};
