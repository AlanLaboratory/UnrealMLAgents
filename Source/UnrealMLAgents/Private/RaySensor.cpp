#include "RaySensor.h"
#include "DrawDebugHelpers.h"

void URaySensor::Initialize(FString Name, UWorld* World, FRayInput& RayInput)
{
	_Name = Name;
	_RayInput = RayInput;
	_World = World;
	SetNumObservations(_RayInput.OutputSize());
}

/// <inheritdoc/>
EBuiltInSensorType URaySensor::GetBuiltInSensorType() const
{
	return EBuiltInSensorType::RaySensor;
}

FObservationSpec URaySensor::GetObservationSpec()
{
	return _ObservationSpec;
}

void URaySensor::SetNumObservations(int32 NumberObservations)
{
	_ObservationSpec = FObservationSpec::Vector(NumberObservations);
	_Observations.SetNum(NumberObservations);
}

int32 URaySensor::Write(ObservationWriter& Writer)
{
	_Observations.Empty(_Observations.Num());

	// Write all the logic to update observations based on HitResults
	for (const FHitResult& HitResult : _HitResults)
	{
		float	ActorHash;
		AActor* HitActor = HitResult.GetActor();
		ActorHash = GetActorHash(HitActor);
		_Observations.Add(HitResult.Distance);
		_Observations.Add(ActorHash);
	}

	Writer.AddList(_Observations);
	return _Observations.Num();
}

void URaySensor::Update()
{
	PerformRaycasts();
}

void URaySensor::Reset() {}

FString URaySensor::GetName() const
{
	return _Name;
}

void URaySensor::PerformRaycasts()
{
	// Clean _HitResuls before performing new RayCast
	_HitResults.Empty();

	FCollisionQueryParams Params;

	// Ignore the specified actor if provided
	if (_RayInput.IgnoredActor)
	{
		Params.AddIgnoredActor(_RayInput.IgnoredActor);
	}

	FVector Origin = _RayInput.IgnoredActor->GetActorLocation();
	Origin.Z += _RayInput.StartOffset;

	FRotator ActorRotation = _RayInput.IgnoredActor->GetActorRotation();
	ActorRotation.Yaw += _RayInput.YawOffset;

	for (float Angle : _RayInput.Angles)
	{
		// Calculate the direction using Cartesian coordinates relative to the actor's rotation
		float	   RadAngle = FMath::DegreesToRadians(Angle);
		FVector	   LocalDirection = CalculateDirectionForAxis(RadAngle, _RayInput.RayAxis);
		FVector	   Direction = ActorRotation.RotateVector(LocalDirection);
		FVector	   End = Origin + Direction * _RayInput.RayLength;
		FHitResult HitResult;

		if (_World->LineTraceSingleByChannel(HitResult, Origin, End, ECC_Visibility, Params))
		{
			DrawDebugLine(_World, Origin, HitResult.Location, FColor::Green, false, -1, 0, 5);
			_HitResults.Add(HitResult);
		}
		else
		{
			DrawDebugLine(_World, Origin, End, FColor::Red, false, -1, 0, 5);
			HitResult.Distance = _RayInput.RayLength;
			_HitResults.Add(HitResult);
		}
	}
}

float URaySensor::GetActorHash(AActor* Actor)
{
	if (!Actor)
	{
		return -1.0f;
	}

	// Get the object path
	FString ObjectPath = Actor->GetPathName();

	// Generate the MD5 hash
	FMD5 Md5;
	Md5.Update((const uint8*)TCHAR_TO_ANSI(*ObjectPath), ObjectPath.Len());
	uint8 Hash[16];
	Md5.Final(Hash);

	// Convert the hash to a hex string
	FString HashString = BytesToHex(Hash, 16);
	FString ShortHashString = HashString.Left(4);

	return HashToFloat(ShortHashString);
}

float URaySensor::HashToFloat(const FString& HashString)
{
	// Convert the first 8 characters of the hash string to an integer
	int32 IntValue = FCString::Strtoi(*HashString.Left(8), nullptr, 16);

	// Normalize the integer to a float between 0 and 1
	float NormalizedValue = static_cast<float>(IntValue) / static_cast<float>(0xFFFFFFFF);

	return NormalizedValue;
}

FVector URaySensor::CalculateDirectionForAxis(float RadAngle, ERayAxis RayAxis)
{
	FVector LocalDirection;

	switch (RayAxis)
	{
		case ERayAxis::X:
			LocalDirection = FVector(FMath::Cos(RadAngle), FMath::Sin(RadAngle), 0.0f); // XY Plane
			break;
		case ERayAxis::Y:
			LocalDirection = FVector(0.0f, FMath::Cos(RadAngle), FMath::Sin(RadAngle)); // YZ Plane
			break;
		case ERayAxis::Z:
			LocalDirection = FVector(FMath::Cos(RadAngle), 0.0f, FMath::Sin(RadAngle)); // XZ Plane
			break;
		default:
			LocalDirection = FVector(FMath::Cos(RadAngle), FMath::Sin(RadAngle), 0.0f); // Default to XY Plane
			break;
	}

	return LocalDirection;
}
