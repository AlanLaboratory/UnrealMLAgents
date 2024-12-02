#include "RecursionChecker.h"
#include "Misc/AssertionMacros.h"

void URecursionChecker::Initialize(FString InMethodName)
{
	MethodName = InMethodName;
	bIsRunning = false;
}

bool URecursionChecker::Start()
{
	if (bIsRunning)
	{
		checkf(false, TEXT("%s called recursively. This might happen if you call EnvironmentStep() or EndEpisode() from custom code such as CollectObservations() or OnActionReceived()."), *MethodName);
		return false;
	}
	bIsRunning = true;
	return true;
}

void URecursionChecker::Dispose()
{
	// Reset the flag when we're done (or if an exception occurred).
	bIsRunning = false;
}