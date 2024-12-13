#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Sensors/ISensor.h"
#include "UnrealMLAgents/Sensors/ObservationWriter.h"
#include "UnrealMLAgents/Sensors/IBuiltInSensor.h"
#include "VectorSensor.generated.h"

/**
 * @class UVectorSensor
 * @brief A sensor implementation for capturing vector-based observations in reinforcement learning environments.
 *
 * This class represents a vector sensor used for capturing observations, such as scalar values or multi-dimensional
 * vectors, to be used by agents in reinforcement learning environments. The sensor is capable of handling various
 * types of observations, including floats, integers, vectors, quaternions, and one-hot encoded values.
 */
UCLASS(Blueprintable)
class UNREALMLAGENTS_API UVectorSensor : public UObject, public IISensor, public IBuiltInSensor
{
	GENERATED_BODY()

public:
	/**
	 * @brief Default constructor for the vector sensor.
	 */
	UVectorSensor();

	/**
	 * @brief Initializes the vector sensor with a given observation size and optional name.
	 *
	 * @param ObservationSize The number of observations that the sensor will capture.
	 * @param Name The name of the sensor (optional).
	 * @param ObservationType The type of observation being captured (default: EObservationType::Default).
	 */
	void Initialize(
		int32 ObservationSize, FString Name = "", EObservationType ObservationType = EObservationType::Default);

	/**
	 * @brief Writes the sensor's observations to the provided ObservationWriter.
	 *
	 * This method is called during each environment step to write the observations captured by the sensor.
	 * It pads the observations if the number of observations is less than the expected size and truncates if
	 * there are too many.
	 *
	 * @param Writer The observation writer that will record the sensor's observations.
	 * @return The number of observations written.
	 */
	virtual int32 Write(ObservationWriter& Writer) override;

	/**
	 * @brief Updates the sensor state (clears observations).
	 *
	 * This function is called each time the environment is updated, typically before a new observation
	 * is captured, to clear any previous data.
	 */
	virtual void Update() override;

	/**
	 * @brief Resets the sensor to its initial state (clears observations).
	 *
	 * This function is used to reset the sensor between episodes, clearing any accumulated data.
	 */
	virtual void Reset() override;

	/**
	 * @brief Gets the observation specification for the sensor.
	 *
	 * The observation specification defines the shape and dimension properties of the observations collected
	 * by this sensor.
	 *
	 * @return The observation specification (`FObservationSpec`).
	 */
	virtual FObservationSpec GetObservationSpec() override;

	/**
	 * @brief Returns the name of the sensor.
	 *
	 * @return The name of the sensor.
	 */
	virtual FString GetName() const override;

	/**
	 * @brief Returns the built-in sensor type for this sensor.
	 *
	 * @return The built-in sensor type (`EBuiltInSensorType::VectorSensor`).
	 */
	virtual EBuiltInSensorType GetBuiltInSensorType() const override;

	// Methods for adding different types of observations
	/**
	 * @brief Adds a float observation to the sensor.
	 *
	 * @param Observation The float value to be added to the sensor's observations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddFloatObservation(float Observation);

	/**
	 * @brief Adds an integer observation to the sensor.
	 *
	 * @param Observation The integer value to be added (converted to float).
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddIntObservation(int32 Observation);

	/**
	 * @brief Adds a vector observation (3D) to the sensor.
	 *
	 * @param Observation The 3D vector to be added to the sensor's observations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddVectorObservation(FVector Observation);

	/**
	 * @brief Adds a 2D vector observation to the sensor.
	 *
	 * @param Observation The 2D vector to be added to the sensor's observations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddVector2DObservation(FVector2D Observation);

	/**
	 * @brief Adds an array of float observations to the sensor.
	 *
	 * @param Observation The array of floats to be added.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddFloatArrayObservation(const TArray<float>& Observation);

	/**
	 * @brief Adds a quaternion observation to the sensor.
	 *
	 * @param Observation The quaternion to be added to the sensor's observations.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddQuatObservation(FQuat Observation);

	/**
	 * @brief Adds a boolean observation to the sensor (converted to float).
	 *
	 * @param Observation The boolean value (converted to 1.0 for true, 0.0 for false).
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddBoolObservation(bool Observation);

	/**
	 * @brief Adds a one-hot encoded observation to the sensor.
	 *
	 * @param Observation The index of the active "hot" observation.
	 * @param Range The number of possible values in the one-hot encoding.
	 */
	UFUNCTION(BlueprintCallable, Category = "Observations")
	void AddOneHotObservation(int32 Observation, int32 Range);

private:
	/** Clears all current observations from the sensor. */
	void Clear();

	/** Adds a single float observation to the sensor's internal buffer. */
	void AddFloatObs(float Obs);

	/** The array of float values representing the sensor's observations. */
	UPROPERTY()
	TArray<float> Observations;

	/** The name of the sensor. */
	FString Name;

	/** The observation specification (shape and dimension properties). */
	FObservationSpec ObservationSpec;
};
