// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IRecordable.h"
#include "NetPlayPlayerId.h"
#include "ShipMove.h"
#include "Ship.generated.h"

UCLASS()
class ZJOY_API AShip : public APawn, public IRecordable
{
	GENERATED_BODY()

public:
	AShip();

	virtual union FSnapshot Snapshot() override;

	virtual void LoadSnapshot(FSnapshot) override;

	UFUNCTION(BlueprintCallable)
	FShipMove GetShipMove();

	UPROPERTY(BlueprintReadWrite)
	UNetPlayPlayerId* PlayerId;
};
