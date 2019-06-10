// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

struct FTransformSnapshot
{
	TCHAR Name[64];
	float LocationX;
	float LocationY;
	float LocationZ;
};

union FSnapshot
{
	TCHAR Name[64];
	FTransformSnapshot Transform;
};
