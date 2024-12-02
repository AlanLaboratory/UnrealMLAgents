#pragma once

#include "CoreMinimal.h"
#include "RecursionChecker.generated.h"

UCLASS()
class UNREALMLAGENTS_API URecursionChecker : public UObject
{
	GENERATED_BODY()

private:
	bool	bIsRunning;
	FString MethodName;

public:
	void Initialize(FString InMethodName);

	// Starts the recursion check
	bool Start();

	// Resets the flag
	void Dispose();
};
