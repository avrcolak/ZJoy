// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IRecordable.generated.h"

UINTERFACE(MinimalAPI)
class URecordable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZJOY_API IRecordable
{
	GENERATED_BODY()

public:
	virtual union FSnapshot Snapshot() = 0;

	virtual void LoadSnapshot(FSnapshot) = 0;
};
