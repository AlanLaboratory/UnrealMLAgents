// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRLClientComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRL_API UDRLClientComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDRLClientComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	int32 Port; 

	void Initialize();
	void ParseCommandLineArgs();
		
};
