// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IPossesses.h"
#include "NetPlayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API ANetPlayPlayerController : public APlayerController, public IPossesses
{
	GENERATED_BODY()
	
public:
	ANetPlayPlayerController();

	virtual void PossessQuickAndDirty_Implementation(class APawn* InPawn) override;

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerSync();

	UFUNCTION(Client, Reliable)
	void ClientSync(const TArray<uint8>&State, int Seed, int PlayerId, int Frame);

	UFUNCTION(Client, Reliable)
	void ClientPeerSync(int Frame, int PlayerId);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerInput(int PlayerId, int Frame, const TArray<uint8>& Input);

	UFUNCTION(Client, Reliable)
	void ClientPeerInput(int PlayerId, int Frame, const TArray<uint8>& Input);

	UPROPERTY(BlueprintReadOnly)
	bool bSynced;

	// PlayerState might be NULL when bSynced is true, but this won't be.
	UPROPERTY(BlueprintReadOnly)
	int Id;
};

