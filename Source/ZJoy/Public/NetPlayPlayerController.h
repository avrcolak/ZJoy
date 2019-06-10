// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetPlayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API ANetPlayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ANetPlayPlayerController();

	UFUNCTION(BlueprintCallable)
	void PossessQuickAndDirty(class APawn* InPawn);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerSync();

	UFUNCTION(Client, Reliable)
	void ClientSync(const TArray<uint8>&State, int Frame, int Seed);

	UFUNCTION(Client, Reliable)
	void ClientPeerSync(int Frame);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerInput(int PlayerId, int Frame, const TArray<uint8>& Input);

	UFUNCTION(Client, Reliable)
	void ClientPeerInput(int PlayerId, int Frame, const TArray<uint8>& Input);
};

