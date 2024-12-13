#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Actuators/IActionReceiver.h"
#include "AgentInfo.generated.h"

/**
 * @struct FAgentInfo
 * @brief Contains all the information for an Agent, including its observations, actions, and current status.
 *
 * The FAgentInfo struct stores the relevant data for an agent during its lifecycle in the UnrealMLAgents environment.
 * This includes the agent's reward, the actions it can or cannot take, and whether the agent has completed its episode.
 */
USTRUCT(BlueprintType)
struct UNREALMLAGENTS_API FAgentInfo
{
	GENERATED_BODY()

	/** @brief The current reward for the agent. */
	UPROPERTY(BlueprintReadWrite)
	float Reward;

	/** @brief The current group reward received by the agent. */
	UPROPERTY(BlueprintReadWrite)
	float GroupReward;

	/** @brief Whether the agent is done (i.e., whether it has completed its episode). */
	UPROPERTY(BlueprintReadWrite)
	bool bDone;

	/** @brief Whether the agent has reached its maximum step count for the current episode. */
	UPROPERTY(BlueprintReadWrite)
	bool bMaxStepReached;

	/** @brief The episode identifier assigned to the agent at each reset. */
	UPROPERTY(BlueprintReadWrite)
	int32 EpisodeId;

	/** @brief The MultiAgentGroup identifier for the agent. */
	UPROPERTY(BlueprintReadWrite)
	int32 GroupId;

	/** @brief The action buffers containing the most recent actions taken by the agent. */
	UPROPERTY(BlueprintReadWrite)
	FActionBuffers StoredActions;

	/** @brief For discrete control, specifies the actions that the agent cannot take. */
	UPROPERTY(BlueprintReadWrite)
	TArray<bool> DiscreteActionMasks;

	/**
	 * @brief Clears the stored actions for the agent.
	 *
	 * This method resets the stored actions in the `StoredActions` buffer.
	 */
	void ClearActions() { StoredActions.Clear(); }

	/**
	 * @brief Copies the actions from the given action buffer into the stored actions.
	 *
	 * This method copies both continuous and discrete actions from the provided action buffer to the agent's stored
	 * actions.
	 *
	 * @param ActionBuffers The action buffers containing the actions to copy.
	 */
	void CopyActions(FActionBuffers ActionBuffers)
	{
		// Copy continuous actions
		FActionSegment<float>& ContinuousAction = StoredActions.ContinuousActions;
		for (int i = 0; i < ActionBuffers.ContinuousActions.Length; i++)
		{
			ContinuousAction[i] = ActionBuffers.ContinuousActions[i];
		}

		// Copy discrete actions
		FActionSegment<int32>& DiscreteAction = StoredActions.DiscreteActions;
		for (int i = 0; i < ActionBuffers.DiscreteActions.Length; i++)
		{
			DiscreteAction[i] = ActionBuffers.DiscreteActions[i];
		}
	}
};
