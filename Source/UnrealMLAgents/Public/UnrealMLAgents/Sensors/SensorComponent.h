#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnrealMLAgents/Sensors/ISensor.h"
#include "SensorComponent.generated.h"

/**
 * @class USensorComponent
 * @brief Abstract base class for sensor components in Unreal Engine.
 *
 * This class is responsible for creating sensor instances that can be used by agents
 * in reinforcement learning environments. Derived classes must implement the `CreateSensors`
 * function to instantiate and return specific sensors.
 */
UCLASS(Abstract, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALMLAGENTS_API USensorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * @brief Creates sensor instances.
	 *
	 * This function must be overridden in derived classes to create and return
	 * sensor instances that will be used by agents for collecting observations.
	 *
	 * @return An array of sensors implementing the IISensor interface.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Sensors")
	TArray<TScriptInterface<IISensor>> CreateSensors();

	/**
	 * @brief Implementation of the CreateSensors function.
	 *
	 * This function provides the base implementation for creating sensors. Derived
	 * classes can override this function to customize sensor creation.
	 *
	 * @return An array of sensors implementing the IISensor interface.
	 */
	virtual TArray<TScriptInterface<IISensor>> CreateSensors_Implementation();
};
