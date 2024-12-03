#include "VectorSensor.h"
#include "ObservationWriter.h"

UVectorSensor::UVectorSensor() {}

void UVectorSensor::Initialize(int32 ObservationSize, FString InName, EObservationType ObservationType)
{
	if (InName.IsEmpty())
	{
		InName = FString::Printf(TEXT("VectorSensor_size%d"), ObservationSize);
		if (ObservationType != EObservationType::Default)
		{
			InName += FString::Printf(TEXT("_%s"), *UEnum::GetValueAsString(ObservationType));
		}
	}

	Observations.SetNum(ObservationSize);
	Name = InName;
	ObservationSpec = FObservationSpec::Vector(ObservationSize, ObservationType);
}

int32 UVectorSensor::Write(ObservationWriter& Writer)
{
	int32 ExpectedObservations = ObservationSpec.GetShape()[0];
	if (Observations.Num() > ExpectedObservations)
	{
		// Too many observations, truncate
		UE_LOG(LogTemp, Warning,
			TEXT("More observations (%d) made than vector observation size (%d). The observations will be truncated."),
			Observations.Num(), ExpectedObservations);
		Observations.SetNum(ExpectedObservations);
	}
	else if (Observations.Num() < ExpectedObservations)
	{
		// Not enough observations; pad with zeros.
		UE_LOG(LogTemp, Warning,
			TEXT("Fewer observations (%d) made than vector observation size (%d). The observations will be padded."),
			Observations.Num(), ExpectedObservations);
		Observations.SetNumZeroed(ExpectedObservations);
	}
	Writer.AddList(Observations);
	return ExpectedObservations;
}

void UVectorSensor::Update()
{
	Clear();
}

void UVectorSensor::Reset()
{
	Clear();
}

FObservationSpec UVectorSensor::GetObservationSpec()
{
	return ObservationSpec;
}

FString UVectorSensor::GetName() const
{
	return Name;
}

EBuiltInSensorType UVectorSensor::GetBuiltInSensorType() const
{
	return EBuiltInSensorType::VectorSensor;
}

void UVectorSensor::Clear()
{
	Observations.Empty();
}

void UVectorSensor::AddFloatObs(float Obs)
{
	Observations.Add(Obs);
}

void UVectorSensor::AddFloatObservation(float Observation)
{
	AddFloatObs(Observation);
}

void UVectorSensor::AddIntObservation(int32 Observation)
{
	AddFloatObs(static_cast<float>(Observation));
}

void UVectorSensor::AddVectorObservation(FVector Observation)
{
	AddFloatObs(Observation.X);
	AddFloatObs(Observation.Y);
	AddFloatObs(Observation.Z);
}

void UVectorSensor::AddVector2DObservation(FVector2D Observation)
{
	AddFloatObs(Observation.X);
	AddFloatObs(Observation.Y);
}

void UVectorSensor::AddFloatArrayObservation(const TArray<float>& Observation)
{
	for (float Obs : Observation)
	{
		AddFloatObs(Obs);
	}
}

void UVectorSensor::AddQuatObservation(FQuat Observation)
{
	AddFloatObs(Observation.X);
	AddFloatObs(Observation.Y);
	AddFloatObs(Observation.Z);
	AddFloatObs(Observation.W);
}

void UVectorSensor::AddBoolObservation(bool Observation)
{
	AddFloatObs(Observation ? 1.0f : 0.0f);
}

void UVectorSensor::AddOneHotObservation(int32 Observation, int32 Range)
{
	for (int32 i = 0; i < Range; i++)
	{
		AddFloatObs(i == Observation ? 1.0f : 0.0f);
	}
}
