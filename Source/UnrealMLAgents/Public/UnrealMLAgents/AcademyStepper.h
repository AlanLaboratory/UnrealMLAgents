// AAcademyStepper.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AcademyStepper.generated.h"

/**
 * @class AAcademyStepper
 * @brief Hidden helper Actor that ticks during the physics phase and advances the ML environment.
 *
 * This class mirrors Unity's "hidden GameObject with a MonoBehaviour.FixedUpdate()" pattern.
 * It is spawned by UAcademy when automatic stepping is enabled, and destroyed when disabled or on teardown.
 *
 * The Actor:
 * - Ticks in the physics phase (TG_PostPhysics by default) to emulate Unity's FixedUpdate timing.
 * - Calls UAcademy::EnvironmentStep() every physics tick.
 * - Verifies it still belongs to the current UAcademy instance; if not, it self-destructs to avoid leaks
 *   across PIE restarts or world transitions (akin to Unity's IsStepperOwner check).
 */
UCLASS()
class UNREALMLAGENTS_API AAcademyStepper : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * @brief Construct the stepper with physics-phase ticking enabled.
	 *
	 * The Actor is configured to be hidden, transient, non-replicated, and collisionless.
	 * We disable the Actor's own tick in favor of PrimaryActorTick, and set TickGroup to TG_PrePhysics.
	 */
	AAcademyStepper();

	/**
	 * @brief Per-frame callback in the chosen tick group (physics phase).
	 * @param DeltaSeconds Time in seconds since last tick.
	 */
	virtual void Tick(float DeltaSeconds) override;

protected:
	/**
	 * @brief Called when play begins for the stepper Actor.
	 */
	virtual void BeginPlay() override;
};
