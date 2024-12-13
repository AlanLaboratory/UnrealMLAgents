#pragma once

#include "CoreMinimal.h"
#include "IBuiltInSensor.generated.h"

/**
 * @enum EBuiltInSensorType
 * @brief Identifiers for built-in sensor types used in the reinforcement learning system.
 *
 * This enumeration provides identifiers for different types of sensors built into the system.
 * These types are primarily used for analytics purposes and should not be used for runtime decisions.
 */
UENUM(BlueprintType)
enum class EBuiltInSensorType : uint8
{
	/**
	 * @brief Default sensor type if the specific sensor type cannot be determined.
	 */
	Unknown UMETA(DisplayName = "Unknown"),

	/**
	 * @brief The vector sensor used by the agent for vector-based observations.
	 */
	VectorSensor UMETA(DisplayName = "Vector Sensor"),

	/**
	 * @brief The stacking sensor type.
	 *
	 * This type indicates that the sensor stacks observations across multiple frames.
	 * Note that the `StackingSensor` typically returns the type of the wrapped sensor.
	 */
	StackingSensor UMETA(DisplayName = "Stacking Sensor"),

	/**
	 * @brief The ray perception sensor used for detecting objects in the environment using raycasts.
	 *
	 * This sensor includes both 2D and 3D ray perception sensors.
	 */
	RaySensor UMETA(DisplayName = "Ray Sensor")
};

/**
 * @interface IBuiltInSensor
 * @brief Interface for built-in sensors in the reinforcement learning system.
 *
 * The IBuiltInSensor interface is used for sensors provided as part of the built-in reinforcement learning system.
 * It provides a method to retrieve the type of the sensor, which is primarily used for analytics purposes.
 */
UINTERFACE(MinimalAPI)
class UBuiltInSensor : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IBuiltInSensor
 * @brief Interface for built-in sensor types in the reinforcement learning system.
 *
 * This interface defines a method to retrieve the built-in sensor type for any sensor that implements it.
 * The type is used for identifying the sensor, primarily for analytics tracking and classification.
 */
class UNREALMLAGENTS_API IBuiltInSensor
{
	GENERATED_BODY()

public:
	/**
	 * @brief Retrieves the built-in sensor type for the sensor.
	 *
	 * This method returns the type of the built-in sensor, represented as an `EBuiltInSensorType`.
	 * The type is used for identifying and classifying sensors for analytics.
	 *
	 * @return The type of the built-in sensor.
	 */
	virtual EBuiltInSensorType GetBuiltInSensorType() const = 0;
};
