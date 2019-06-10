// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IRollsBack.h"
#include "Bullet.generated.h"

UCLASS()
class ZJOY_API ABullet : public AActor, public IRollsBack
{
	GENERATED_BODY()
	
public:	
	ABullet();

	virtual void Rollback(int Frames) override;
};
