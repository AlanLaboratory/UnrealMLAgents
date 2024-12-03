#pragma once

#include "CoreMinimal.h"
#include "IPolicy.h"
#include "ActionSpec.h"
#include "HeuristicPolicy.h"
#include "ActuatorManager.h"
#include "BrainParameters.h"
#include "Components/ActorComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "BehaviorParameters.generated.h"

/**
 * @brief Delegate for receiving events about Policy Updates.
 *
 * This delegate is triggered when the agent's policy is updated, passing a boolean
 * value indicating whether the policy is running in heuristic mode.
 *
 * @param IsInHeuristicMode Boolean indicating if the policy is in heuristic mode.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPolicyUpdated, bool, IsInHeuristicMode);

/**
 * @enum EBehaviorType
 * @brief Specifies the type of behavior the Agent will use during decision making.
 *
 * The behavior type dictates whether the agent will use heuristic decisions, inference
 * via a neural network model, or a combination of both.
 */
UENUM(BlueprintType)
enum class EBehaviorType : uint8
{
	/** The Agent will use its heuristic only. */
	HeuristicOnly UMETA(DisplayName = "Heuristic Only"),

	/** The Agent will always use inference with the provided neural network model. */
	InferenceOnly UMETA(DisplayName = "Inference Only"),

	/** The Agent will use a remote process for decision making if available, otherwise will fallback to inference or
	 * heuristic. */
	Default UMETA(DisplayName = "Default")
};

/**
 * @class UBehaviorParameters
 * @brief A component that sets the behavior and brain properties for an Agent.
 *
 * The UBehaviorParameters class is responsible for defining how an Agent behaves in the environment. It
 * includes settings for the behavior type (heuristic, inference, or default), brain parameters, team assignment,
 * and the use of child sensors and actuators.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALMLAGENTS_API UBehaviorParameters : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * @brief Constructor that sets default values for this component's properties.
	 */
	UBehaviorParameters();

protected:
	/**
	 * @brief Called when the game starts.
	 *
	 * This method initializes the component when the game begins, setting up the agent's policy based on the behavior
	 * parameters.
	 */
	virtual void BeginPlay() override;

public:
	/** @brief Maximum number of steps the agent can take in an episode. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	int32 MaxStep;

	/** @brief The name of this behavior, used for identifying the agent's behavior in the environment. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	FString BehaviorName = "My Behavior";

	/** @brief The team identifier for the agent, used in multi-agent scenarios. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	int32 TeamId;

	/** @brief Determines whether child sensors attached to the agent are used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	bool bUseChildSensors = true;

	/** @brief Determines whether child actuators attached to the agent are used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	bool bUseChildActuators = true;

	/** @brief Controls whether actions are selected deterministically during inference. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	bool bDeterministicInference = false;

	/** @brief Defines the type of behavior the agent will use (heuristic, inference, or default). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MLAgents")
	EBehaviorType BehaviorType;

	/**
	 * @brief Delegate that is triggered when the agent's policy is updated.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MLAgents")
	FPolicyUpdated OnPolicyUpdated;

	/** @brief The associated BrainParameters that define the agent's brain configuration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior Parameters")
	FBrainParameters BrainParameters;

	/**
	 * @brief Checks if the agent is currently running in heuristic mode.
	 *
	 * This function determines whether the agent's policy is currently operating in heuristic mode, which
	 * means that decisions are made manually or based on predefined rules rather than using a model.
	 *
	 * @return True if the agent is in heuristic mode, false otherwise.
	 */
	UFUNCTION()
	bool IsInHeuristicMode();

private:
	/**
	 * @brief Updates the agent's policy based on the behavior parameters.
	 *
	 * This method is responsible for regenerating the agent's policy when the behavior type, model, or other
	 * parameters are changed. It ensures the agent's decisions align with the current configuration.
	 */
	void UpdateAgentPolicy();

	/**
	 * @brief Initializes the heuristic policy for the agent.
	 *
	 * This function sets up the heuristic policy, which is responsible for making decisions based on hand-crafted
	 * rules or inputs.
	 *
	 * @param ActionSpec The action specification that defines the available actions for the agent.
	 * @param ActuatorManager The actuator manager that controls the agent's actions.
	 * @return A pointer to the initialized heuristic policy.
	 */
	UHeuristicPolicy* InitializeHeuristicPolicy(const FActionSpec& ActionSpec, UActuatorManager* ActuatorManager);

	/**
	 * @brief Generates the appropriate policy for the agent based on the current behavior type.
	 *
	 * This function creates a new policy, either heuristic, inference-based, or remote, depending on the agent's
	 * configuration.
	 *
	 * @param ActionSpec The action specification for the agent.
	 * @param ActuatorManager The manager that controls the agent's actions.
	 * @return A script interface to the generated policy.
	 */
	TScriptInterface<IIPolicy> GeneratePolicy(const FActionSpec& ActionSpec, UActuatorManager* ActuatorManager);

	/**
	 * @brief Returns the fully qualified behavior name, including any metadata like the team ID.
	 *
	 * @return A string representing the fully qualified behavior name.
	 */
	FString GetFullyQualifiedBehaviorName();

	// Grant Access to UAgent
	friend class UAgent;
};
