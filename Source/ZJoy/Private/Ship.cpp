// This is free and unencumbered software released into the public domain.


#include "Ship.h"
#include "Snapshot.h"

union FSnapshot AShip::Snapshot()
{
	FSnapshot Snapshot;

	auto Name = GetClass()->GetName().GetCharArray();

	FMemory::Memcpy(Snapshot.Name, Name.GetData(), Name.Num() * sizeof(TCHAR));

	auto Location = GetActorLocation();

	Snapshot.Transform.LocationX = Location.X;
	Snapshot.Transform.LocationY = Location.Y;
	Snapshot.Transform.LocationZ = Location.Z;

	return Snapshot;
}

void AShip::LoadSnapshot(FSnapshot Snapshot)
{
	FVector Location;

	Location.X = Snapshot.Transform.LocationX;
	Location.Y = Snapshot.Transform.LocationY;
	Location.Z = Snapshot.Transform.LocationZ;

	SetActorLocation(Location);
}

