// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DRLObservationDataHandler.h"
#include "DRLSubsystem.generated.h"


/**
 *
 */
UCLASS()
class DRL_API UDRLSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UDRLSubsystem();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "DRLPlugin|DataHandler")
	FString GatherObservarionData();

	UFUNCTION(BlueprintCallable, Category = "DRLPlugin|DataHandler")
	FString GetEnvironmentSpace();

	UPROPERTY(BlueprintReadWrite)
	bool bDone = false;

	UPROPERTY(BlueprintReadWrite)
	int32 Reward = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 ActionSpace = 0;

	UFUNCTION(BlueprintCallable, Category = "DRLPlugin|Initialize")
	void SetDataHandlerClass(TSubclassOf<UObservationDataHandler> HandlerClass);

protected:
	void OnWorldInitialized(UWorld* World, const UWorld::InitializationValues);
	void OnWorldCleanup(UWorld* World, bool, bool);

	void OnActorsInitialized(const FActorsInitializedParams& Params);
	void OnActorPreSpawn(AActor* Actor);
	void OnActorDestroyed(AActor* Actor);


private:

    UPROPERTY()
    UObservationDataHandler* DataHandlerInstance;

	/* List of actors that implement the UDRLObservationObject interface */
	TSet<TWeakObjectPtr<AActor>> GameActors;

	/* Serialize FJsonObject to a FString */
	FString JsonObjectToFString(TSharedPtr<FJsonObject> JsonObject);

	/* Previous done. Use to de-bounce the send observation with two done = True */
	bool bPreviousDone = false;

};
