#include "RaySensorComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

TArray<TScriptInterface<IISensor>> URaySensorComponent::CreateSensors_Implementation()
{
	URaySensor* RaySensor = NewObject<URaySensor>();
	FRayInput	RayInput = GetRayInput();
	RaySensor->Initialize(SensorName, GetWorld(), RayInput);
	return TArray<TScriptInterface<IISensor>>{ RaySensor };
}

FRayInput URaySensorComponent::GetRayInput()
{

	FRayInput RayInput;
	RayInput.IgnoredActor = GetOwner();
	RayInput.RayLength = RayLength;
	RayInput.Transform = GetOwner()->GetActorTransform();
	RayInput.Angles = GetRayAngles();
	RayInput.RayAxis = RayAxis;
	RayInput.StartOffset = StartOffset;
	RayInput.YawOffset = YawOffset;
	return RayInput;
}

TArray<float> URaySensorComponent::GetRayAngles()
{
	TArray<float> AnglesOut;
	float		  Delta = MaxRayDegrees / RaysPerDirection;

	for (int32 i = 0; i < 2 * RaysPerDirection + 1; i++)
	{
		AnglesOut.Add(90.f + (i - RaysPerDirection) * Delta);
	}

	return AnglesOut;
}
