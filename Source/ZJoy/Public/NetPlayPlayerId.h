// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NetPlayPlayerId.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZJOY_API UNetPlayPlayerId : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNetPlayPlayerId();

	UPROPERTY(BlueprintReadWrite)
	int Id;
};
