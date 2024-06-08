// Fill out your copyright notice in the Description page of Project Settings.


#include "DRLSubsystem.h"
#include "DRLObservationObject.h"

#include "EngineUtils.h"


UDRLSubsystem::UDRLSubsystem()
{
	DataHandlerInstance = NewObject<UObservationDataHandler>(this, UObservationDataHandler::StaticClass(), TEXT("DefaultDataHandler"));
}

void UDRLSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &ThisClass::OnWorldInitialized);
	FWorldDelegates::OnWorldInitializedActors.AddUObject(this, &ThisClass::OnActorsInitialized);
	FWorldDelegates::OnWorldCleanup.AddUObject(this, &ThisClass::OnWorldCleanup);

	// This example doesn't handle streaming levels, but if we did, we'd use a combination of
	// FWorldDelegates::LevelAddedToWorld and FWorldDelegates::PreLevelRemovedFromWorld
	// In these, we'd store the current state of actors within that level

	OnWorldInitialized(GetWorld(), UWorld::InitializationValues());
}

void UDRLSubsystem::Deinitialize()
{
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);
	FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
	FWorldDelegates::OnWorldCleanup.RemoveAll(this);

	FWorldDelegates::LevelAddedToWorld.RemoveAll(this);
	FWorldDelegates::PreLevelRemovedFromWorld.RemoveAll(this);
}

FString UDRLSubsystem::GatherObservarionData()
{
	UWorld* World = this->GetWorld();

	int32 NumActors;
	TArray<AActor*> Actors;

	NumActors = this->GameActors.Num();
	auto ActorsIt = this->GameActors.CreateConstIterator();
	TArray<int32> InterfaceObservationData;

	TArray<TSharedPtr<FJsonValue>> ObservationData;
	TSharedPtr<FJsonObject> RetJsonObject = MakeShareable(new FJsonObject);

	// Print the actors that are being send
	for (int32 ActorIdx = 0; ActorIdx < NumActors; ++ActorIdx)
	{
		AActor* Actor;
		FString ActorName;

		Actor = ActorsIt->Get();
		++ActorsIt;

		check(IsValid(Actor));
		InterfaceObservationData = IDRLObservationObject::Execute_OnGetObservationState(Actor);
		for (auto& Data : InterfaceObservationData)
		{
			ObservationData.Add(MakeShareable(new FJsonValueNumber(Data)));
		}
	}
	
	RetJsonObject->SetArrayField(TEXT("observation"), ObservationData);
	RetJsonObject->SetBoolField(TEXT("done"), bDone);
	RetJsonObject->SetNumberField(TEXT("reward"), (double)Reward);

	// Call the data handler.
	DataHandlerInstance->HandleData(RetJsonObject);
	FString OutputString;
	OutputString = JsonObjectToFString(RetJsonObject);

	return OutputString;

}

FString UDRLSubsystem::GetEnvironmentSpace()
{	
	FString ObservationData;
	TSharedPtr<FJsonObject> JsonObject; 
	TSharedPtr<FJsonObject> RetJsonObject = MakeShareable(new FJsonObject);

	ObservationData = GatherObservarionData();	

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ObservationData);

	//Deserialize the json data given Reader and the actual object to deserialize
	int32 ObservationSpace = 0;
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		ObservationSpace = JsonObject->GetArrayField("observation").Num();
	}
	
	RetJsonObject->SetNumberField(TEXT("action_space"), ActionSpace);
	RetJsonObject->SetNumberField(TEXT("observation_space"), ObservationSpace);

	// Call the data handler.
	FString OutputString;
	OutputString = JsonObjectToFString(RetJsonObject);

	return OutputString;
}

void UDRLSubsystem::OnWorldInitialized(UWorld* World, const UWorld::InitializationValues)
{
	if (!IsValid(World) || GetWorld() != World)
	{
		return;
	}

	World->AddOnActorPreSpawnInitialization(FOnActorSpawned::FDelegate::CreateUObject(this, &ThisClass::OnActorPreSpawn));
	World->AddOnActorDestroyedHandler(FOnActorDestroyed::FDelegate::CreateUObject(this, &ThisClass::OnActorDestroyed));
}

void UDRLSubsystem::OnActorsInitialized(const FActorsInitializedParams& Params)
{
	if (!IsValid(Params.World) || GetWorld() != Params.World)
	{
		return;
	}

	for (TActorIterator<AActor> It(Params.World); It; ++It)
	{
		AActor* Actor = *It;
		if (IsValid(Actor) && Actor->Implements<UDRLObservationObject>())
		{
			GameActors.Add(Actor);
		}
	}
}

void UDRLSubsystem::OnWorldCleanup(UWorld* World, bool, bool)
{
	if (!IsValid(World) || GetWorld() != World)
	{
		return;
	}

	GameActors.Reset();
}

void UDRLSubsystem::OnActorPreSpawn(AActor* Actor)
{
	if (IsValid(Actor) && Actor->Implements<UDRLObservationObject>())
	{
		GameActors.Add(Actor);
	}
}

void UDRLSubsystem::OnActorDestroyed(AActor* Actor)
{
	GameActors.Remove(Actor);
}


void UDRLSubsystem::SetDataHandlerClass(TSubclassOf<UObservationDataHandler> HandlerClass)
{
    if (HandlerClass != nullptr)
    {
        // Destroy the existing instance if one exists
        if (DataHandlerInstance != nullptr)
        {
            DataHandlerInstance->ConditionalBeginDestroy();
        }

        // Create a new handler instance of the specified class
        DataHandlerInstance = NewObject<UObservationDataHandler>(this, HandlerClass), TEXT("CustomDataHandler");
    }
}


FString UDRLSubsystem::JsonObjectToFString(TSharedPtr<FJsonObject> JsonObject)
{
	FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
	return OutputString;
}
