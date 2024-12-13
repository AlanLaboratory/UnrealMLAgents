#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UnrealMLAgents/Actuators/ActionSegment.h"
#include "UnrealMLAgents/Actuators/ActionSpec.h"
#include "UnrealMLAgents/Actuators/IDiscreteActionMask.h"
#include "IActionReceiver.generated.h"

/**
 * @struct FActionBuffers
 * @brief A structure that wraps the action segments for continuous and discrete actions.
 *
 * The FActionBuffers struct holds the continuous and discrete actions that an agent can take.
 * It is used by the `IActionReceiver` interface when the agent's actions are executed, and
 * it provides an efficient way to manage and clear action buffers.
 */
USTRUCT(BlueprintType)
struct FActionBuffers
{
	GENERATED_BODY()

public:
	/** @brief Holds the continuous actions to be used by an `IActionReceiver`. */
	FActionSegment<float> ContinuousActions;

	/** @brief Holds the discrete actions to be used by an `IActionReceiver`. */
	FActionSegment<int32> DiscreteActions;

	/** @brief An empty action buffer with no actions. */
	static FActionBuffers Empty;

	/**
	 * @brief Default constructor that initializes empty action segments.
	 *
	 * This constructor creates an FActionBuffers instance where both continuous and discrete actions are initialized to
	 * empty.
	 */
	FActionBuffers() : ContinuousActions(nullptr), DiscreteActions(nullptr) {}

	/**
	 * @brief Constructor with specified action segments for continuous and discrete actions.
	 *
	 * @param InContinuousActions The continuous action segment.
	 * @param InDiscreteActions The discrete action segment.
	 */
	FActionBuffers(FActionSegment<float> InContinuousActions, FActionSegment<int32> InDiscreteActions)
		: ContinuousActions(InContinuousActions), DiscreteActions(InDiscreteActions)
	{
	}

	/**
	 * @brief Constructor that creates action buffers from arrays of actions.
	 *
	 * This constructor initializes the action buffers using shared pointers to arrays of continuous and discrete
	 * actions.
	 *
	 * @param InContinuousActions A shared pointer to an array of continuous actions.
	 * @param InDiscreteActions A shared pointer to an array of discrete actions.
	 */
	FActionBuffers(TSharedPtr<TArray<float>> InContinuousActions, TSharedPtr<TArray<int32>> InDiscreteActions)
		: FActionBuffers(FActionSegment<float>(InContinuousActions), FActionSegment<int32>(InDiscreteActions))
	{
	}

	/**
	 * @brief Clears the continuous and discrete action segments.
	 *
	 * This function resets both the continuous and discrete actions in the buffer to zero.
	 */
	void Clear()
	{
		ContinuousActions.Clear();
		DiscreteActions.Clear();
	}

	/**
	 * @brief Checks if the action buffers are empty.
	 *
	 * @return True if both the continuous and discrete actions are empty, false otherwise.
	 */
	bool IsEmpty() const { return ContinuousActions.IsEmpty() && DiscreteActions.IsEmpty(); }

	/** @brief Equality operator to compare two action buffers. */
	bool operator==(const FActionBuffers& Other) const
	{
		return ContinuousActions == Other.ContinuousActions && DiscreteActions == Other.DiscreteActions;
	}

	/** @brief Inequality operator to compare two action buffers. */
	bool operator!=(const FActionBuffers& Other) const { return !(*this == Other); }
};

/**
 * @interface IActionReceiver
 * @brief Interface for objects that can receive actions from a reinforcement learning system.
 *
 * The IActionReceiver interface defines methods for receiving and executing actions based on action buffers.
 * It also includes functionality for modifying the action masks for discrete actions to prevent certain actions
 * from being taken by the agent.
 */
UINTERFACE(MinimalAPI)
class UActionReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IActionReceiver
 * @brief Interface for receiving and processing actions in a reinforcement learning environment.
 *
 * This interface provides methods to receive actions from a reinforcement learning system and to modify
 * action masks for discrete control. It is implemented by agents that execute actions based on the
 * `FActionBuffers` structure.
 */
class UNREALMLAGENTS_API IActionReceiver
{
	GENERATED_BODY()

public:
	/**
	 * @brief Executes actions based on the contents of the action buffers.
	 *
	 * This method is called to process the actions stored in the action buffers. The actions are defined
	 * according to the `FActionSpec`, which specifies the structure of the action space (continuous or discrete).
	 *
	 * @param ActionBuffers The buffers containing the actions to be executed by the agent.
	 */
	virtual void OnActionReceived(const FActionBuffers& ActionBuffers) = 0;

	/**
	 * @brief Modifies the masks for discrete actions.
	 *
	 * This method is used to mask certain discrete actions, preventing the agent from performing them.
	 * It interacts with the `IDiscreteActionMask` interface to enable or disable specific actions.
	 *
	 * @param ActionMask The action mask for the agent's discrete actions.
	 */
	virtual void WriteDiscreteActionMask(const TScriptInterface<IDiscreteActionMask>& ActionMask) = 0;
};
