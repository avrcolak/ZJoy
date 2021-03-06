// This is free and unencumbered software released into the public domain.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZJoyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ZJOY_API UZJoyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector2D EllipseLineIntersection(FVector2D Point, float SemiAxisLengthX, float SemiAxisLengthY);

	UFUNCTION(BlueprintCallable)
	static void MaintainMinorAxisFov(APlayerController* Controller);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FIntPoint StaggeredCellIndexAtPoint(FVector2D Point, float CellSize);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsEven(int n);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool IsOdd(int n);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FBox2D StaggeredCellBoundsAtIndex(FIntPoint Index, float CellSize);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FBox2D StaggeredCellBoundsAtPoint(FVector2D Point, float CellSize);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TSet<FIntPoint> StaggeredCellNeighborsAtIndex(FIntPoint Index);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector2D StaggeredCellCenterAtIndex(FIntPoint Index, float CellSize);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector2D StaggeredCellMinAtIndex(FIntPoint Index, float CellSize);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<FVector2D> SplitArc(FVector2D Arc, int N, float Size);
};