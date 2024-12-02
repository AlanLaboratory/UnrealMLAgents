#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionSpec.h"
#include "IActuator.h"
#include "ActuatorComponent.generated.h"

/**
 * Editor components for creating Actuators. Generally, an IActuator component should
 * have a corresponding ActuatorComponent.
 */
UCLASS(Abstract, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALMLAGENTS_API UActuatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UActuatorComponent();

	/**
	 * Create a collection of IActuators. This is called by the Agent during
	 * initialization.
	 * @return A collection of IActuators
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Actuators")
	TArray<TScriptInterface<IActuator>>			CreateActuators();
	virtual TArray<TScriptInterface<IActuator>> CreateActuators_Implementation();

	/**
	 * The specification of the possible actions for this ActuatorComponent.
	 * This must produce the same results as the corresponding IActuator's ActionSpec.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Actuators")
	FActionSpec			GetActionSpec() const;
	virtual FActionSpec GetActionSpec_Implementation() const;
};
