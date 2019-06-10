// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IRollsBack.generated.h"

UINTERFACE(MinimalAPI)
class URollsBack : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ZJOY_API IRollsBack
{
	GENERATED_BODY()

public:
	virtual void Rollback(int Frames) = 0;
};
