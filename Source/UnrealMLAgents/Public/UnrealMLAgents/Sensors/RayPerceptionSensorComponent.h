#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Sensors/RayPerceptionSensor.h"
#include "UnrealMLAgents/Sensors/SensorComponent.h"
#include "RayPerceptionSensorComponent.generated.h"

/**
 * @class URaySensorComponent
 * @brief A component that creates a ray-based sensor for agents in a reinforcement learning environment.
 *
 * The `URaySensorComponent` is responsible for creating and configuring ray-based sensors that cast rays into
 * the environment to detect objects. These rays help gather information such as the distance to obstacles or
 * other environmental elements, which can then be used by agents for decision-making.
 *
 * The component supports adjusting the number of rays, their length, angle, and direction. Rays can be cast
 * from different axes and with varying degrees of offset to accommodate various actor geometries and rotations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALMLAGENTS_API URaySensorComponent : public USensorComponent
{
	GENERATED_BODY()

public:
	/**
	 * @brief Creates the sensor instances based on the component's configuration.
	 *
	 * This function overrides the base implementation of `CreateSensors_Implementation` to create ray-based
	 * sensors for the agent. It configures the rays based on properties such as ray length, number of rays
	 * per direction, and the angle of the rays.
	 *
	 * @return An array of sensor instances implementing the `IISensor` interface.
	 */
	virtual TArray<TScriptInterface<IISensor>> CreateSensors_Implementation() override;

	/**
	 * @brief Name of the ray sensor, used to identify it within the agent.
	 *
	 * This name can be used to differentiate between multiple sensors an agent might have.
	 */
	UPROPERTY(EditAnywhere, Category = "Ray Sensor")
	FString SensorName = "RaySensor";

	/**
	 * @brief The length of the ray to be cast.
	 *
	 * This property defines how far the ray will be cast into the environment.
	 * Longer rays can detect objects farther away but may increase the computational load.
	 */
	UPROPERTY(EditAnywhere, Category = "Ray Sensor")
	float RayLength;

	/**
	 * @brief The number of rays to cast per direction (left and right of the center).
	 *
	 * This determines how many rays are cast in each direction to cover a specific field of view.
	 */
	UPROPERTY(EditAnywhere, Category = "Ray Sensor")
	float RaysPerDirection;

	/**
	 * @brief The maximum degrees that the rays will spread out.
	 *
	 * This defines the angle of the cone in which the rays are cast. Higher values will cast rays in a wider
	 * spread, potentially including areas behind the actor.
	 */
	UPROPERTY(EditAnywhere, Category = "Ray Sensor")
	float MaxRayDegrees;

	/**
	 * @brief Starting height offset of the ray from the center of the actor.
	 *
	 * This offset allows for casting the ray from a higher or lower position relative to the actor's center.
	 * Useful for preventing the ray from originating inside geometry.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float StartOffset;

	/**
	 * @brief The axis relative to which the rays will be cast (e.g., X, Y, Z).
	 *
	 * Specifies the axis along which the rays will be cast. This is useful for controlling whether the rays
	 * are cast forward, sideways, or vertically relative to the actor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	ERayAxis RayAxis;

	/**
	 * @brief Yaw offset to compensate for the initial rotation of the mesh.
	 *
	 * Allows for compensating any initial rotation on the actor to ensure rays are cast correctly based
	 * on the intended forward direction.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float YawOffset;

	/**
	 * @brief The pitch angle for all rays.
	 *
	 * This property defines the uniform vertical tilt (pitch) applied to all rays.
	 * A value of 0 results in rays pointing straight forward.
	 * Negative values tilt the rays downward, and positive values tilt them upward.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float PitchAngle;

	/**
	 * @brief Activate or deactivate the raycast debug lines
	 *
	 * Display the raycast debug lines
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	bool bDebugLine;

private:
	/**
	 * @brief Generates the input data for casting the rays.
	 *
	 * This function gathers the configuration parameters (ray length, angles, etc.) and prepares the
	 * input structure used to cast the rays during sensor creation or updates.
	 *
	 * @return The input structure containing raycasting parameters.
	 */
	FRayInput GetRayInput();

	/**
	 * @brief Calculates the angles for each ray based on the number of rays and the maximum spread angle.
	 *
	 * The rays are cast at specific angles determined by the number of rays per direction and the maximum
	 * degrees for the cone in which the rays are spread. This function calculates those angles.
	 *
	 * @return An array of angles for each ray.
	 */
	TArray<float> GetRayAngles();
};
