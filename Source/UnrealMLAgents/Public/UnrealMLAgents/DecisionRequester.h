#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnrealMLAgents/Agent.h"
#include "DecisionRequester.generated.h"

/**
 * @class UDecisionRequester
 * @brief A component that automatically requests decisions from the agent at regular intervals.
 *
 * The UDecisionRequester component is responsible for managing how frequently an agent requests decisions and performs
 * actions in a reinforcement learning environment. It hooks into the simulation's stepping mechanism and ensures that
 * agents request decisions at specified intervals.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), DefaultToInstanced)
class UNREALMLAGENTS_API UDecisionRequester : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * @brief Default constructor that sets up the component's default values.
	 */
	UDecisionRequester();

protected:
	/**
	 * @brief Called when the game begins.
	 *
	 * This function initializes the component and subscribes to the relevant events in the simulation, such as the
	 * Academy's pre-step event.
	 */
	virtual void BeginPlay() override;

public:
	/**
	 * @brief Called when the game ends.
	 *
	 * Cleans up the component, unsubscribing from any events and releasing resources.
	 *
	 * @param EndPlayReason The reason for ending play (e.g., game quit, level transition).
	 */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/**
	 * @brief Called when the component is destroyed.
	 *
	 * Handles destruction of the component, ensuring proper cleanup of its internal state.
	 *
	 * @param bDestroyingHierarchy Whether or not the destruction is cascading through a hierarchy of objects.
	 */
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	/** @brief The frequency with which the agent requests a decision, measured in Academy steps.
	 *
	 * A `DecisionPeriod` of 5 means that the agent will request a decision every 5 Academy steps.
	 * The value is clamped between 1 and 20.
	 */
	UPROPERTY(
		EditAnywhere, BlueprintReadWrite, Category = "DecisionRequester", meta = (ClampMin = "1", ClampMax = "20"))
	int DecisionPeriod = 5;

	/** @brief Controls the specific step within the decision period when the agent requests a decision.
	 *
	 * By setting this value, the timing of decision requests can be staggered among agents with the same
	 * `DecisionPeriod`. This value can range from 0 to `DecisionPeriod - 1`.
	 */
	UPROPERTY(
		EditAnywhere, BlueprintReadWrite, Category = "DecisionRequester", meta = (ClampMin = "0", ClampMax = "19"))
	int DecisionStep = 0;

	/** @brief Indicates whether the agent will take actions during the Academy steps where it does not request a
	 * decision.
	 *
	 * If this value is `true`, the agent will continue to take actions between decisions, even if it does not request a
	 * decision.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecisionRequester")
	bool bTakeActionsBetweenDecisions = true;

	/** @brief Flag to stop the agent from requesting decisions.
	 *
	 * If set to `true`, the agent will no longer request decisions, pausing its decision-making process.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecisionRequester")
	bool bStopRequestDecision = false;

private:
	/** @brief A reference to the agent this component is managing.
	 *
	 * The `UAgent` object to which this `DecisionRequester` component is attached, controlling its decision-making
	 * process.
	 */
	UPROPERTY()
	UAgent* Agent;

	/**
	 * @brief Callback function triggered before each Academy step.
	 *
	 * This function is called before every Academy step to determine whether the agent should request a decision or
	 * take an action.
	 *
	 * @param AcademyStepCount The current step count of the Academy.
	 */
	UFUNCTION()
	void OnAcademyPreStep(int AcademyStepCount);

	/**
	 * @brief Requests decisions and actions from the agent based on the current Academy step count.
	 *
	 * This function handles the logic for whether an agent should request a decision or action, based on the configured
	 * `DecisionPeriod` and `DecisionStep`.
	 *
	 * @param AcademyStepCount The current step count of the Academy.
	 */
	void MakeRequests(int AcademyStepCount);

	/**
	 * @brief Determines whether the agent should request a decision on the current Academy step.
	 *
	 * This function checks if the current step count matches the configured `DecisionPeriod` and `DecisionStep` to
	 * decide if a decision should be requested.
	 *
	 * @param AcademyStepCount The current step count of the Academy.
	 * @return True if the agent should request a decision, false otherwise.
	 */
	bool ShouldRequestDecision(int AcademyStepCount) const;

	/**
	 * @brief Determines whether the agent should take an action on the current Academy step.
	 *
	 * This function checks if the agent should take an action, depending on the `bTakeActionsBetweenDecisions` flag.
	 *
	 * @return True if the agent should take an action, false otherwise.
	 */
	bool ShouldRequestAction() const;
};
