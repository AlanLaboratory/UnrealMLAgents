#pragma once

#include "CoreMinimal.h"
#include "ActuatorManager.h"
#include "IPolicy.h"
#include "AgentInfo.h"
#include "ISensor.h"
#include "IActuator.h"
#include "RpcCommunicator.h"
#include "RemotePolicy.generated.h"

UCLASS()
class POLICIES_API URemotePolicy : public UObject, public IIPolicy
{
    GENERATED_BODY()

private:
    int32 AgentId;
    FString FullyQualifiedBehaviorName;
    FActionSpec ActionSpec;
    FActionBuffers LastActionBuffer;

    UPROPERTY()
    URpcCommunicator* Communicator;

public:
    URemotePolicy();

    void Initialize(UActuatorManager* InActuatorManager, const FActionSpec& InActionSpec, const FString& InFullyQualifiedBehaviorName);
	virtual void RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) override;
    virtual const FActionBuffers& DecideAction() override;

};