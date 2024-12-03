#pragma once

#include "CoreMinimal.h"
#include "ActuatorManager.h"
#include "IPolicy.h"
#include "AgentInfo.h"
#include "ISensor.h"
#include "IActuator.h"
#include "RpcCommunicator.h"
#include "RemotePolicy.generated.h"

/**
 * @class URemotePolicy
 * @brief A policy that communicates with a remote server (such as a Python backend) for decision making.
 *
 * The `URemotePolicy` class implements a policy that sends agent observations to a remote server
 * (typically used during training with a Python backend). The remote server processes the observations
 * and sends back the appropriate actions for the agent. This class is responsible for sending requests
 * and receiving decisions from the server.
 */
UCLASS()
class UNREALMLAGENTS_API URemotePolicy : public UObject, public IIPolicy
{
	GENERATED_BODY()

private:
	/** The ID of the agent requesting the decision. */
	int32 AgentId;

	/** The fully qualified name of the behavior used for training and communication. */
	FString FullyQualifiedBehaviorName;

	/** Specification of the action space for the agent. */
	UPROPERTY()
	FActionSpec ActionSpec;

	/** The last action buffer received from the remote server. */
	UPROPERTY()
	FActionBuffers LastActionBuffer;

	/** The communicator used to send and receive data from the remote server. */
	UPROPERTY()
	URpcCommunicator* Communicator;

public:
	/**
	 * @brief Initializes the remote policy with the given action space and behavior name.
	 *
	 * This method sets up the communicator and subscribes the agent's brain (policy) to the remote server
	 * with the specified action space and fully qualified behavior name.
	 *
	 * @param InActuatorManager The actuator manager for managing agent actuators.
	 * @param InActionSpec The specification of the action space for the agent.
	 * @param InFullyQualifiedBehaviorName The fully qualified name of the behavior being used.
	 */
	void Initialize(UActuatorManager* InActuatorManager, const FActionSpec& InActionSpec,
		const FString& InFullyQualifiedBehaviorName);

	/**
	 * @brief Requests a decision from the remote server based on the agent's current observations.
	 *
	 * This method sends the current agent state (observations) to the remote server and requests a decision.
	 * The decision will be made by the server and retrieved later when actions are required.
	 *
	 * @param Info Information about the agent's current state.
	 * @param Sensors A list of sensors providing observations about the agent's environment.
	 */
	virtual void RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) override;

	/**
	 * @brief Retrieves the decision (action) from the remote server.
	 *
	 * This method retrieves the action decision made by the remote server based on the agent's previous request.
	 * If no decision has been made, this method waits until the decision is available.
	 *
	 * @return A constant reference to the last action buffer, containing the actions to be performed by the agent.
	 */
	virtual const FActionBuffers& DecideAction() override;
};
