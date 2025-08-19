// AAcademyStepper.cpp
#include "UnrealMLAgents/AcademyStepper.h"
#include "UnrealMLAgents/Academy.h"

/* static analysis note: ensure this matches your module include path */

AAcademyStepper::AAcademyStepper()
{
	// Be a silent, transient helper Actor.
	SetActorHiddenInGame(true);
	SetCanBeDamaged(false);
	SetActorEnableCollision(false);
	SetReplicates(false);
	SetFlags(RF_Transient);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Unity's FixedUpdate analogue: run BEFORE physics simulation so forces/inputs apply this frame.
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void AAcademyStepper::BeginPlay()
{
	Super::BeginPlay();
}

void AAcademyStepper::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// If Academy isn't ready yet, do nothing.
	if (!UAcademy::IsInitialized())
	{
		return;
	}

	UAcademy* Academy = UAcademy::GetInstance();

	// Leak-proofing (PIE restarts/world switches): if we don't belong to the current Academy, self-destruct.
	if (!Academy->IsStepperOwner(this))
	{
		Destroy();
		return;
	}

	Academy->EnvironmentStep();
}
