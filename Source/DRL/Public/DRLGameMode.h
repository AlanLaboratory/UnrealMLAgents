// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DRLGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DRL_API ADRLGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Environment")
	bool bLearningMode = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Environment")
	float DelayOnDeath = 2;
};
