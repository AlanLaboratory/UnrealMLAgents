#pragma once

#include "CoreMinimal.h"
#include "IActuator.h"
#include "IBuiltInActuator.h"
#include "IHeuristicProvider.h"
#include "VectorActuator.generated.h"

/**
 * @class UVectorActuator
 * @brief A vector-based actuator for reinforcement learning that forwards actions to an `IActionReceiver` and
 * `IHeuristicProvider`.
 *
 * The `UVectorActuator` class is responsible for managing agent actions and forwarding them to the appropriate
 * interfaces. It supports both continuous and discrete actions and can be initialized with or without a heuristic
 * provider for manual control.
 */
UCLASS(Blueprintable)
class UNREALMLAGENTS_API UVectorActuator : public UObject, public IActuator, public IBuiltInActuator
{
	GENERATED_BODY()

public:
	/**
	 * @brief Initializes the actuator with an action receiver and heuristic provider.
	 *
	 * This function initializes the actuator by associating it with an action receiver for receiving agent actions
	 * and a heuristic provider for manual action control during heuristic policies.
	 *
	 * @param InActionReceiver The action receiver for processing actions.
	 * @param InHeuristicProvider The heuristic provider for manual action control.
	 * @param InActionSpec The specification of the action space (continuous/discrete actions).
	 * @param InName The name of the actuator (default: "VectorActuator").
	 */
	void Initialize(TScriptInterface<IActionReceiver> InActionReceiver,
		TScriptInterface<IHeuristicProvider> InHeuristicProvider, const FActionSpec& InActionSpec,
		const FString& InName = "VectorActuator");

	/**
	 * @brief Initializes the actuator with an action receiver only (no heuristic provider).
	 *
	 * This overload of `Initialize` is used when the heuristic provider is not needed. The actuator will only forward
	 * actions to the provided action receiver.
	 *
	 * @param InActionReceiver The action receiver for processing actions.
	 * @param InActionSpec The specification of the action space (continuous/discrete actions).
	 * @param InName The name of the actuator (default: "VectorActuator").
	 */
	void Initialize(TScriptInterface<IActionReceiver> InActionReceiver, const FActionSpec& InActionSpec,
		const FString& InName = "VectorActuator");

	/**
	 * @brief Resets the actuator's internal state.
	 *
	 * This function clears any stored action buffers and resets the actuator's internal state to its default.
	 */
	virtual void ResetData() override;

	/**
	 * @brief Receives actions and forwards them to the associated `IActionReceiver`.
	 *
	 * This function is called when actions are received from the policy (e.g., from the reinforcement learning
	 * algorithm). It forwards the received actions to the associated action receiver for processing.
	 *
	 * @param ActionBuffers The action buffers containing the agent's actions.
	 */
	virtual void OnActionReceived(const FActionBuffers& ActionBuffers) override;

	/**
	 * @brief Fills the action buffers with heuristic actions (manual control).
	 *
	 * This function allows manual control over the agent by filling the action buffers using the heuristic provider.
	 * This is typically used when the agent is not following a trained policy but is instead controlled manually.
	 *
	 * @param ActionBuffersOut The action buffers to be filled with heuristic actions.
	 */
	virtual void Heuristic(FActionBuffers& ActionBuffersOut) override;

	/**
	 * @brief Writes a mask to disable certain discrete actions.
	 *
	 * This function allows the actuator to modify the action mask, disabling certain actions for the agent
	 * during discrete control.
	 *
	 * @param ActionMask The action mask used to disable specific actions.
	 */
	virtual void WriteDiscreteActionMask(const TScriptInterface<IDiscreteActionMask>& ActionMask) override;

	/**
	 * @brief Returns the built-in actuator type for this actuator.
	 *
	 * @return The built-in actuator type (`VectorActuator`).
	 */
	virtual EBuiltInActuatorType GetBuiltInActuatorType() const override;

	/**
	 * @brief Retrieves the action specification for this actuator.
	 *
	 * @return The action specification (`FActionSpec`) associated with this actuator.
	 */
	const FActionSpec GetActionSpec() const { return ActionSpec; }

	/**
	 * @brief Retrieves the name of this actuator.
	 *
	 * @return The name of the actuator.
	 */
	const FString GetName() const { return Name; }

private:
	/** The action receiver for handling received actions. */
	UPROPERTY()
	TScriptInterface<IActionReceiver> ActionReceiver;

	/** The heuristic provider for generating heuristic actions (manual control). */
	UPROPERTY()
	TScriptInterface<IHeuristicProvider> HeuristicProvider;

	/** The action buffers storing the agent's actions. */
	UPROPERTY()
	FActionBuffers ActionBuffers;

	/** The specification of the action space (continuous or discrete). */
	UPROPERTY()
	FActionSpec ActionSpec;

	/** The name of the actuator. */
	FString Name;
};
