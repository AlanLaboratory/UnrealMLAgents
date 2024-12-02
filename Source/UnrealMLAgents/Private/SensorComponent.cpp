#include "SensorComponent.h"

TArray<TScriptInterface<IISensor>> USensorComponent::CreateSensors_Implementation()
{
	// Derived classes should override this method to create specific sensors
	return TArray<TScriptInterface<IISensor>>();
}