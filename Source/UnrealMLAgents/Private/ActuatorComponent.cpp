#include "ActuatorComponent.h"

UActuatorComponent::UActuatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<TScriptInterface<IActuator>> UActuatorComponent::CreateActuators_Implementation()
{
	// This should be implemented in the derived classes.
	return TArray<TScriptInterface<IActuator>>();
}

FActionSpec UActuatorComponent::GetActionSpec_Implementation() const
{
	// This should be implemented in the derived classes.
	return FActionSpec();
}