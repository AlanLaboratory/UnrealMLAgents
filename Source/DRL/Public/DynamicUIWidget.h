// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "DynamicUIWidget.generated.h"


USTRUCT(BlueprintType)
struct FAlgorithmData
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Algorithm Data")
    FString AlgorithmName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Algorithm Data")
    TMap<FString, FString> Parameters;
};

/**
 * 
 */
UCLASS()
class DRL_API UDynamicUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UComboBoxString* AlgorithmComboBox;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox* ParametersBox;

    UPROPERTY(meta = (BindWidget))
    UButton* SendButton;

    // In the UMyDynamicWidget class
	UPROPERTY()
	TArray<FAlgorithmData> StoredAlgorithms;

    UFUNCTION()
    void OnAlgorithmSelected(FString SelectedItem, ESelectInfo::Type SelectionType);

    UFUNCTION(BlueprintCallable, Category = "UI")
	FString OnSendButtonClicked();

    UFUNCTION(BlueprintCallable, Category = "Data")
    void PopulateUIFromJson(const FString& JsonData);
};
