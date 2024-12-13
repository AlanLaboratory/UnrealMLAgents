#include "UnrealMLAgents/Actuators/VectorActuator.h"

void UVectorActuator::Initialize(
	TScriptInterface<IActionReceiver> InActionReceiver, const FActionSpec& InActionSpec, const FString& InName)
{
	TScriptInterface<IHeuristicProvider> Result;
	IHeuristicProvider*					 Temp = Cast<IHeuristicProvider>(&*InActionReceiver);
	Result.SetInterface(Temp);
	Result.SetObject(Cast<UObject>(Temp));
	Initialize(InActionReceiver, Result, InActionSpec, InName);
}

void UVectorActuator::Initialize(TScriptInterface<IActionReceiver> InActionReceiver,
	TScriptInterface<IHeuristicProvider> InHeuristicProvider, const FActionSpec& InActionSpec, const FString& InName)
{
	ActionReceiver = InActionReceiver;
	HeuristicProvider = InHeuristicProvider;
	ActionSpec = InActionSpec;

	FString Suffix;
	if (ActionSpec.NumContinuousActions == 0)
	{
		Suffix = "-Discrete";
	}
	else if (ActionSpec.GetNumDiscreteActions() == 0)
	{
		Suffix = "-Continuous";
	}
	else
	{
		Suffix = FString::Printf(
			TEXT("-Continuous-%d-Discrete-%d"), ActionSpec.NumContinuousActions, ActionSpec.GetNumDiscreteActions());
	}
	Name = InName + Suffix;
}

void UVectorActuator::ResetData()
{
	ActionBuffers = FActionBuffers::Empty;
}

void UVectorActuator::OnActionReceived(const FActionBuffers& InActionBuffers)
{
	ActionBuffers = InActionBuffers;
	if (ActionReceiver)
	{
		ActionReceiver->OnActionReceived(ActionBuffers);
	}
}

void UVectorActuator::Heuristic(FActionBuffers& ActionBuffersOut)
{
	if (HeuristicProvider)
	{
		HeuristicProvider->Heuristic(ActionBuffersOut);
	}
}

void UVectorActuator::WriteDiscreteActionMask(const TScriptInterface<IDiscreteActionMask>& ActionMask)
{
	if (ActionReceiver)
	{
		ActionReceiver->WriteDiscreteActionMask(ActionMask);
	}
}

EBuiltInActuatorType UVectorActuator::GetBuiltInActuatorType() const
{
	return EBuiltInActuatorType::VectorActuator;
}
