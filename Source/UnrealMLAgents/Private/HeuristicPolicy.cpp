#include "HeuristicPolicy.h"

void UHeuristicPolicy::Initialize(UActuatorManager* InActuatorManager, const FActionSpec& ActionSpec)
{
	ActuatorManager = InActuatorManager;
	int32 NumContinuousActions = ActionSpec.NumContinuousActions;
	int32 NumDiscreteActions = ActionSpec.GetNumDiscreteActions();

	TSharedPtr<TArray<float>> ContinuousActions = MakeShared<TArray<float>>();
	ContinuousActions->SetNumZeroed(NumContinuousActions);

	TSharedPtr<TArray<int32>> DiscreteActions = MakeShared<TArray<int32>>();
	DiscreteActions->SetNumZeroed(NumDiscreteActions);

	FActionSegment<float> ContinuousDecision(ContinuousActions, 0, NumContinuousActions);
	FActionSegment<int32> DiscreteDecision(DiscreteActions, 0, NumDiscreteActions);

	ActionBuffers = FActionBuffers(ContinuousDecision, DiscreteDecision);
}

void UHeuristicPolicy::RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors)
{
	for (auto Sensor : Sensors)
	{
		Sensor->Update();
	}
	bDone = Info.bDone;
	bDecisionRequested = true;
}

const FActionBuffers& UHeuristicPolicy::DecideAction()
{
	if (!bDone && bDecisionRequested)
	{
		ActionBuffers.Clear();
		ActuatorManager->ApplyHeuristic(ActionBuffers);
	}

	bDecisionRequested = false;
	return ActionBuffers;
}