// Fill out your copyright notice in the Description page of Project Settings.


#include "ZJoyBlueprintFunctionLibrary.h"
#include "Gameframework/Pawn.h"
#include "Engine/LocalPlayer.h"

FVector2D UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D Point, float SemiAxisLengthX, float SemiAxisLengthY)
{
	auto numerator = SemiAxisLengthX * SemiAxisLengthY;

	auto square =
		FMath::Square(SemiAxisLengthY) * FMath::Square(Point.X) +
		FMath::Square(SemiAxisLengthX) * FMath::Square(Point.Y);

	auto denominator = FMath::Sqrt(square);

	auto ratio = numerator / denominator;

	auto x = FMath::Abs(ratio * Point.X);

	auto y = FMath::Abs(ratio * Point.Y);

	return FVector2D(FMath::Sign(Point.X) * x, FMath::Sign(Point.Y) * y);
}

void UZJoyBlueprintFunctionLibrary::MaintainMinorAxisFov(APawn* Pawn)
{
	auto player = Cast<ULocalPlayer>(Pawn->GetNetOwningPlayer());

	if (player)
	{
		FVector2D viewportSize;

		player->ViewportClient->GetViewportSize(viewportSize);

		player->AspectRatioAxisConstraint = viewportSize.X > viewportSize.Y 
			? EAspectRatioAxisConstraint::AspectRatio_MaintainYFOV
			: EAspectRatioAxisConstraint::AspectRatio_MaintainXFOV;
	}
}

FIntPoint UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(FVector2D Point, float CellSize)
{
	FIntPoint index;

	auto CellWidth = CellSize * UE_SQRT_3;
	auto CellHeight = CellSize * 1.5;

	index.Y = FMath::FloorToInt(Point.Y / CellHeight);

	auto offset = IsEven(index.Y) ? 0.0f : 0.5;

	index.X = FMath::FloorToInt(Point.X / CellWidth - offset);

	return index;
}

bool UZJoyBlueprintFunctionLibrary::IsEven(int n)
{
	return n % 2 == 0;
}

bool UZJoyBlueprintFunctionLibrary::IsOdd(int n)
{
	return n % 2 == 1;
}

FBox2D UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(FIntPoint Index, float CellSize)
{
	FBox2D box;

	box.Min = StaggeredCellMinAtIndex(Index, CellSize);

	box.Max.X = box.Min.X + CellSize * UE_SQRT_3;
	box.Max.Y = box.Min.Y + CellSize * 1.5;

	return box;
}

FBox2D UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtPoint(FVector2D Point, float CellSize)
{
	return StaggeredCellBoundsAtIndex(StaggeredCellIndexAtPoint(Point, CellSize), CellSize);
}

TSet<FIntPoint> UZJoyBlueprintFunctionLibrary::StaggeredCellNeighborsAtIndex(FIntPoint Index)
{
	auto set = TSet<FIntPoint>();

	set.Add(FIntPoint(Index.X + 1, Index.Y));
	set.Add(FIntPoint(Index.X - 1, Index.Y));

	int X = IsEven(Index.Y) ? Index.X - 1 : Index.X;

	set.Add(FIntPoint(X, Index.Y - 1));
	set.Add(FIntPoint(X + 1, Index.Y - 1));
	set.Add(FIntPoint(X, Index.Y + 1));
	set.Add(FIntPoint(X + 1, Index.Y + 1));

	return set;
}

FVector2D UZJoyBlueprintFunctionLibrary::StaggeredCellCenterAtIndex(FIntPoint Index, float CellSize)
{
	auto min = StaggeredCellMinAtIndex(Index, CellSize);

	return FVector2D(min.X + CellSize * UE_SQRT_3 * 0.5, min.Y + CellSize * 0.75);
}

FVector2D UZJoyBlueprintFunctionLibrary::StaggeredCellMinAtIndex(FIntPoint Index, float CellSize)
{
	FVector2D min;

	auto CellWidth = CellSize * UE_SQRT_3;
	auto CellHeight = CellSize * 1.5;

	auto offset = IsEven(Index.Y) ? 0.0f : 0.5;
	min.X = (Index.X + offset) * CellWidth;
	min.Y = Index.Y * CellHeight;

	return min;
}
