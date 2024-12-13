#include "UnrealMLAgents/Policies/RemotePolicy.h"
#include "UnrealMLAgents/Academy.h"

void URemotePolicy::Initialize(
	UActuatorManager* InActuatorManager, const FActionSpec& InActionSpec, const FString& InFullyQualifiedBehaviorName)
{
	FullyQualifiedBehaviorName = InFullyQualifiedBehaviorName;
	Communicator = UAcademy::GetInstance()->RpcCommunicator;
	if (Communicator)
	{
		Communicator->SubscribeBrain(FullyQualifiedBehaviorName, InActionSpec);
	}
	ActionSpec = InActionSpec;
}

void URemotePolicy::RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors)
{
	AgentId = Info.EpisodeId;
	if (Communicator)
	{
		Communicator->PutObservations(FullyQualifiedBehaviorName, Info, Sensors);
	}
}

const FActionBuffers& URemotePolicy::DecideAction()
{
	if (Communicator)
	{
		Communicator->DecideBatch();
		const FActionBuffers Actions = Communicator->GetActions(FullyQualifiedBehaviorName, AgentId);
		LastActionBuffer = Actions.IsEmpty() ? FActionBuffers::Empty : Actions;
	}
	return LastActionBuffer;
}
