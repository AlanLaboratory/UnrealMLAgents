// Fill out your copyright notice in the Description page of Project Settings.


#include "DRLClientComponent.h"
#include "RpcCommunicator.h"

// Sets default values for this component's properties
UDRLClientComponent::UDRLClientComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	Port = 5004;
}


// Called when the game starts
void UDRLClientComponent::BeginPlay()
{
	Super::BeginPlay();
    ParseCommandLineArgs();
    Initialize();
	
}

void UDRLClientComponent::ParseCommandLineArgs()
{
    FString PortString;
    if (FParse::Value(FCommandLine::Get(), TEXT("mlAgentPort="), PortString))
    {
        Port = FCString::Atoi(*PortString);
        UE_LOG(LogTemp, Log, TEXT("Using custom mlAgentPort: %d"), Port);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Using default mlAgentPort: %d"), Port);
    }
}

void UDRLClientComponent::Initialize()
{
    RpcCommunicator communicator;
    // communicator.Initialize(FString("Alan"), Port);
}

