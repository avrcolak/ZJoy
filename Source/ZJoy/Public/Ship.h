// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IRecordable.h"
#include "Ship.generated.h"

UCLASS()
class ZJOY_API AShip : public APawn, public IRecordable
{
	GENERATED_BODY()

public:
	virtual union FSnapshot Snapshot() override;

	virtual void LoadSnapshot(FSnapshot) override;
};
