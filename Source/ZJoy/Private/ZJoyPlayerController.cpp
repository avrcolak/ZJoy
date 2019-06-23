// This is free and unencumbered software released into the public domain.


#include "ZJoyPlayerController.h"
#include "Ship.h"
#include "ShipMove.h"
#include "ZJoyGameState.h"
#include "Engine/World.h"
#include "GameFramework/PlayerState.h"


void AZJoyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveUp", this, &AZJoyPlayerController::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &AZJoyPlayerController::MoveRight);
}

void AZJoyPlayerController::MoveUp(float AxisValue)
{
	Pending.Up = AxisValue;
}

void AZJoyPlayerController::MoveRight(float AxisValue)
{
	Pending.Right = AxisValue;
}

void AZJoyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bSynced)
	{
		return;
	}

	auto GameState = GetWorld()->GetGameState<AZJoyGameState>();

	GameState->AddShipMoveForNextFrame(PlayerState->PlayerId, Pending);

	Pending = FShipMove();
}
