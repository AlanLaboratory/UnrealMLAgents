// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DRLObservationDataHandler.generated.h"


UCLASS(Blueprintable)
class DRL_API UObservationDataHandler : public UObject
{
	GENERATED_BODY()

public:
	virtual void HandleData(const TSharedPtr<FJsonObject>& Data);

};

