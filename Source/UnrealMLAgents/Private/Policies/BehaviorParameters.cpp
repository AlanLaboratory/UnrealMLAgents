#include "UnrealMLAgents/Policies/BehaviorParameters.h"
#include "UnrealMLAgents/Policies/HeuristicPolicy.h"
#include "UnrealMLAgents/Policies/RemotePolicy.h"
#include "UnrealMLAgents/Agent.h"
#include "UnrealMLAgents/Academy.h"

// Sets default values for this component's properties
UBehaviorParameters::UBehaviorParameters()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UBehaviorParameters::BeginPlay()
{
	Super::BeginPlay();
}

void UBehaviorParameters::UpdateAgentPolicy()
{
	UAgent* Agent = Cast<UAgent>(GetOwner()->GetComponentByClass(UAgent::StaticClass()));
	if (Agent == nullptr)
	{
		return;
	}
	Agent->ReloadPolicy();
	OnPolicyUpdated.Broadcast(IsInHeuristicMode());
}

bool UBehaviorParameters::IsInHeuristicMode()
{
	if (BehaviorType == EBehaviorType::HeuristicOnly)
	{
		return true;
	}
	return false;
}

TScriptInterface<IIPolicy> UBehaviorParameters::GeneratePolicy(
	const FActionSpec& ActionSpec, UActuatorManager* ActuatorManager)
{
	switch (BehaviorType)
	{
		case EBehaviorType::HeuristicOnly:
			return InitializeHeuristicPolicy(ActionSpec, ActuatorManager);
		case EBehaviorType::Default:
			if (UAcademy::GetInstance()->IsCommunicatorOn())
			{
				URemotePolicy* RemotePolicy = NewObject<URemotePolicy>();
				RemotePolicy->Initialize(ActuatorManager, ActionSpec, GetFullyQualifiedBehaviorName());
				return RemotePolicy;
			}
			else
			{
				return InitializeHeuristicPolicy(ActionSpec, ActuatorManager);
			}
		default:
			return InitializeHeuristicPolicy(ActionSpec, ActuatorManager);
	}
}

UHeuristicPolicy* UBehaviorParameters::InitializeHeuristicPolicy(
	const FActionSpec& ActionSpec, UActuatorManager* ActuatorManager)
{
	UHeuristicPolicy* HeuristicPolicy = NewObject<UHeuristicPolicy>();
	HeuristicPolicy->Initialize(ActuatorManager, ActionSpec);
	return HeuristicPolicy;
}

FString UBehaviorParameters::GetFullyQualifiedBehaviorName()
{
	FString QualifiedName = BehaviorName + "?team=" + FString::FromInt(TeamId);
	return QualifiedName;
}
