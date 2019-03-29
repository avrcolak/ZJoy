#include "CoreTypes.h"
#include "Containers/UnrealString.h"
#include "Misc/Timespan.h"
#include "Misc/AutomationTest.h"
#include "ZJoyBlueprintFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

#define SQRT_THREE 1.7320508f

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FZJoyBlueprintFunctionLibraryTest, "ZJoy.BlueprintFunctionLibrary.Test", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)

bool FZJoyBlueprintFunctionLibraryTest::RunTest(const FString& Parameters)
{
	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(1.0f, 0.0f), 1.0f, 1.0f);

		TestEqual("FVector2D(1.0f, 0.0f) should intersect unit circle at X = 1.0", pointOnEllipse.X, 1.0f);
		TestEqual("FVector2D(1.0f, 0.0f) should intersect unit circle at Y = 0.0", pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, 1.0f), 1.0f, 1.0f);

		TestEqual("FVector2D(0.0f, 1.0f) should intersect unit circle at X = 0.0", pointOnEllipse.X, 0.0f);
		TestEqual("FVector2D(0.0f, 1.0f) should intersect unit circle at Y = 1.0", pointOnEllipse.Y, 1.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(-1.0f, 0.0f), 1.0f, 1.0f);

		TestEqual("FVector2D(-1.0f, 0.0f) should intersect unit circle at X = -1.0", pointOnEllipse.X, -1.0f);
		TestEqual("FVector2D(-1.0f, 0.0f) should intersect unit circle at Y = 0.0", pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, -1.0f), 1.0f, 1.0f);

		TestEqual("FVector2D(0.0f, -1.0f) should intersect unit circle at X = 0.0", pointOnEllipse.X, 0.0f);
		TestEqual("FVector2D(0.0f, -1.0f) should intersect unit circle at Y = -1.0", pointOnEllipse.Y, -1.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(1.0f, 0.0f), 2.0f, 1.0f);

		TestEqual("FVector2D(1.0f, 0.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at X = 2.0",
			pointOnEllipse.X, 2.0f);

		TestEqual("FVector2D(1.0f, 0.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at Y = 0.0",
			pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, 1.0f), 2.0f, 1.0f);

		TestEqual("FVector2D(0.0f, 1.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at X = 0.0",
			pointOnEllipse.X, 0.0f);

		TestEqual("FVector2D(0.0f, 1.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at Y = 1.0",
			pointOnEllipse.Y, 1.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(-1.0f, 0.0f), 2.0f, 1.0f);

		TestEqual("FVector2D(-1.0f, 0.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at X = -2.0",
			pointOnEllipse.X, -2.0f);

		TestEqual("FVector2D(-1.0f, 0.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at Y = 0.0",
			pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, -1.0f), 2.0f, 1.0f);

		TestEqual("FVector2D(0.0f, -1.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at X = 0.0",
			pointOnEllipse.X, 0.0f);

		TestEqual("FVector2D(0.0f, -1.0f) should intersect ellipse with semiaxes of length 2.0 and 1.0 oriented along the cartesian X and Y axes at Y = -1.0",
			pointOnEllipse.Y, -1.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(1.0f, 0.0f), 1.0f, 2.0f);

		TestEqual("FVector2D(1.0f, 0.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at X = 1.0",
			pointOnEllipse.X, 1.0f);

		TestEqual("FVector2D(1.0f, 0.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at Y = 0.0",
			pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, 1.0f), 1.0f, 2.0f);

		TestEqual("FVector2D(0.0f, 1.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at X = 0.0",
			pointOnEllipse.X, 0.0f);

		TestEqual("FVector2D(0.0f, 1.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at Y = 2.0",
			pointOnEllipse.Y, 2.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(-1.0f, 0.0f), 1.0f, 2.0f);

		TestEqual("FVector2D(-1.0f, 0.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at X = -1.0",
			pointOnEllipse.X, -1.0f);

		TestEqual("FVector2D(-1.0f, 0.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at Y = 0.0",
			pointOnEllipse.Y, 0.0f);
	}

	{
		auto pointOnEllipse = UZJoyBlueprintFunctionLibrary::EllipseLineIntersection(FVector2D(0.0f, -1.0f), 2.0f, 2.0f);

		TestEqual("FVector2D(0.0f, -1.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at X = 0.0",
			pointOnEllipse.X, 0.0f);

		TestEqual("FVector2D(0.0f, -1.0f) should intersect ellipse with semiaxes of length 1.0 and 2.0 oriented along the cartesian X and Y axes at Y = -2.0",
			pointOnEllipse.Y, -2.0f);
	}

	{
		FIntPoint Index = { 0, 0 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(Index, 1.0f);

		TestEqual("Staggered cell at 0, 0 with unit size should have Min.X = 0.0", box.Min.X, 0.0f);
		TestEqual("Staggered cell at 0, 0 with unit size should have Min.Y = 0.0", box.Min.Y, 0.0f);
		TestEqual("Staggered cell at 0, 0 with unit size should have Max.X = sqrt 3", box.Max.X, SQRT_THREE);
		TestEqual("Staggered cell at 0, 0 with unit size should have Max.Y = 1.5", box.Max.Y, 1.5f);
	}

	{
		FIntPoint index = { 1, 0 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at 1, 0 with unit size should have Min.X = sqrt 3", box.Min.X, SQRT_THREE);
		TestEqual("Staggered cell at 1, 0 with unit size should have Min.Y = 0.0", box.Min.Y, 0.0f);
		TestEqual("Staggered cell at 1, 0 with unit size should have Max.X = sqrt 3", box.Max.X, SQRT_THREE* 2.0f);
		TestEqual("Staggered cell at 1, 0 with unit size should have Max.Y = 1.5", box.Max.Y, 1.5f);
	}

	{
		FIntPoint index = { -1, 0 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at -1, 0 with unit size should have Min.X = -sqrt 3", box.Min.X, -SQRT_THREE);
		TestEqual("Staggered cell at -1, 0 with unit size should have Min.Y = 0.0", box.Min.Y, 0.0f);
		TestEqual("Staggered cell at -1, 0 with unit size should have Max.X = 0.0", box.Max.X, 0.0f);
		TestEqual("Staggered cell at -1, 0 with unit size should have Max.Y = 1.5", box.Max.Y, 1.5f);
	}

	{
		FIntPoint index = { 0, 1 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at 0, 1 with unit size should have Min.X = 0.5 * sqrt 3", box.Min.X, SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at 0, 1 with unit size should have Min.Y = 1.5", box.Min.Y, 1.5f);
		TestEqual("Staggered cell at 0, 1 with unit size should have Max.X = 1.5 * sqrt 3", box.Max.X, 3.0f * SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at 0, 1 with unit size should have Max.Y = 3.0", box.Max.Y, 3.0f);
	}

	{
		FIntPoint index = { -1, 1 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at -1, 1 with unit size should have Min.X = -0.5 * sqrt 3", box.Min.X, -SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at -1, 1 with unit size should have Min.Y = 1.5", box.Min.Y, 1.5f);
		TestEqual("Staggered cell at -1, 1 with unit size should have Max.X = 0.5 * sqrt 3", box.Max.X, SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at -1, 1 with unit size should have Max.Y = 3.0", box.Max.Y, 3.0f);
	}

	{
		FIntPoint index = { 0, -1 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at 0, -1 with unit size should have Min.X = 0.5 * sqrt 3", box.Min.X, SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at 0, -1 with unit size should have Min.Y = 1.5", box.Min.Y, -1.5f);
		TestEqual("Staggered cell at 0, -1 with unit size should have Max.X = 1.5 * sqrt 3", box.Max.X, 3.0f * SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at 0, -1 with unit size should have Max.Y = 3.0", box.Max.Y, 0.0f);
	}

	{
		FIntPoint index = { -1, -1 };

		auto box = UZJoyBlueprintFunctionLibrary::StaggeredCellBoundsAtIndex(index, 1.0f);

		TestEqual("Staggered cell at -1, -1 with unit size should have Min.X = -0.5 * sqrt 3", box.Min.X, -SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at -1, -1 with unit size should have Min.Y = 0.0", box.Min.Y, -1.5f);
		TestEqual("Staggered cell at -1, -1 with unit size should have Max.X = 0.5 * sqrt 3", box.Max.X, SQRT_THREE / 2.0f);
		TestEqual("Staggered cell at -1, -1 with unit size should have Max.Y = 3.0", box.Max.Y, 0.0f);
	}

	{
		FVector2D point = { 1.0f, 1.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 1.0, 1.0 should correspond with staggered cell at X = 0", index.X, 0);
		TestEqual("Point at 1.0, 1.0 should correspond with staggered cell at Y = 0", index.Y, 0);
	}

	{
		FVector2D point = { 0.0f, 2.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 0.0, 2.0 should correspond with staggered cell at X = -1", index.X, -1);
		TestEqual("Point at 0.0, 2.0 should correspond with staggered cell at Y = 1", index.Y, 1);
	}

	{
		FVector2D point = { 2.0f, 2.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 2.0, 2.0 should correspond with staggered cell at X = 0", index.X, 0);
		TestEqual("Point at 2.0, 2.0 should correspond with staggered cell at Y = 1", index.Y, 1);
	}

	{
		FVector2D point = { 2.0f, 1.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 2.0, 1.0 should correspond with staggered cell at X = 1", index.X, 1);
		TestEqual("Point at 2.0, 1.0 should correspond with staggered cell at Y = 0", index.Y, 0);
	}
	
	{
		FVector2D point = { 1.0f, -1.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 1.0, -1.0 should correspond with staggered cell at X = 0", index.X, 0);
		TestEqual("Point at 1.0, -1.0 should correspond with staggered cell at Y = -1", index.Y, -1);
	}

	{
		FVector2D point = { 0.0f, -1.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at 0.0, -1.0 should correspond with staggered cell at X = -1", index.X, -1);
		TestEqual("Point at 0.0, -1.0 should correspond with staggered cell at Y = -1", index.Y, -1);
	}

	{
		FVector2D point = { -1.0f, 1.0f };

		auto index = UZJoyBlueprintFunctionLibrary::StaggeredCellIndexAtPoint(point, 1.0f);

		TestEqual("Point at -1.0, 1.0 should correspond with staggered cell at X = -1", index.X, -1);
		TestEqual("Point at -1.0, 1.0 should correspond with staggered cell at Y = 0", index.Y, 0);
	}

	{
		FIntPoint index = { 0, 0 };

		auto neighbors = UZJoyBlueprintFunctionLibrary::StaggeredCellNeighborsAtIndex(index);

		TestEqual("Cell at 0, 0 should have 6 neighbors", neighbors.Num(), 6);

		TestTrue("Cell at 0, 0 should neighbor cell at -1, 1", neighbors.Contains(FIntPoint(-1, 1)));
		TestTrue("Cell at 0, 0 should neighbor cell at 0, 1", neighbors.Contains(FIntPoint(0, 1)));

		TestTrue("Cell at 0, 0 should neighbor cell at -1, 0", neighbors.Contains(FIntPoint(-1, 0)));
		TestTrue("Cell at 0, 0 should neighbor cell at 1, 0", neighbors.Contains(FIntPoint(1, 0)));

		TestTrue("Cell at 0, 0 should neighbor cell at -1, -1", neighbors.Contains(FIntPoint(-1, -1)));
		TestTrue("Cell at 0, 0 should neighbor cell at 0, -1", neighbors.Contains(FIntPoint(0, -1)));
	}

	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS
