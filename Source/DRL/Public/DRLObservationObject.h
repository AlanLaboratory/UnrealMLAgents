
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DRLObservationObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDRLObservationObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * If an object implements this interface, it should be saved.
 */
class DRL_API IDRLObservationObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Observation")
	TArray<int32> OnGetObservationState();

	UFUNCTION(BlueprintNativeEvent, Category = "Observation")
	int32 OnGetActionSpace();
};
