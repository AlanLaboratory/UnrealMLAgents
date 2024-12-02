#include "DecisionRequester.h"
#include "Agent.h"
#include "Academy.h"

UDecisionRequester::UDecisionRequester()
{
	PrimaryComponentTick.bCanEverTick = false; // Disable tick as we hook into Academy's step event
}

void UDecisionRequester::BeginPlay()
{
	Super::BeginPlay();

	check(DecisionStep < DecisionPeriod);

	Agent = GetOwner()->GetComponentByClass<UAgent>();
	check(Agent); // Ensure the Agent component is attached

	UAcademy::GetInstance()->OnAgentPreStep.AddDynamic(this, &UDecisionRequester::OnAcademyPreStep);
}

void UDecisionRequester::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UAcademy::IsInitialized())
	{
		UAcademy::GetInstance()->OnAgentPreStep.RemoveDynamic(this, &UDecisionRequester::OnAcademyPreStep);
	}

	Super::EndPlay(EndPlayReason);
}

void UDecisionRequester::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (UAcademy::IsInitialized())
	{
		UAcademy::GetInstance()->OnAgentPreStep.RemoveDynamic(this, &UDecisionRequester::OnAcademyPreStep);
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UDecisionRequester::OnAcademyPreStep(int AcademyStepCount)
{
	MakeRequests(AcademyStepCount);
}

void UDecisionRequester::MakeRequests(int AcademyStepCount)
{
	if (bStopRequestDecision)
	{
		return;
	}

	if (ShouldRequestDecision(AcademyStepCount))
	{
		Agent->RequestDecision();
	}

	if (ShouldRequestAction())
	{
		Agent->RequestAction();
	}
}

bool UDecisionRequester::ShouldRequestDecision(int AcademyStepCount) const
{
	return (AcademyStepCount % DecisionPeriod == DecisionStep);
}

bool UDecisionRequester::ShouldRequestAction() const
{
	return bTakeActionsBetweenDecisions;
}