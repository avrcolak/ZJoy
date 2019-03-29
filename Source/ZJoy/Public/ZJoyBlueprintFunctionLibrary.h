// Fill out your copyright notice in the Description page of Project Settings.

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
	static void MaintainMinorAxisFov(APawn* Pawn);

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
};