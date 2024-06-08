// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicUIWidget.h"
#include "Components/TextBlock.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"


void UDynamicUIWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    // Bind the ComboBox selection change event
    AlgorithmComboBox->OnSelectionChanged.AddDynamic(this, &UDynamicUIWidget::OnAlgorithmSelected);
}


void UDynamicUIWidget::OnAlgorithmSelected(FString SelectedItem, ESelectInfo::Type SelectionType)
{
    // Clear previous parameters
    ParametersBox->ClearChildren();

    // Find the selected algorithm in stored data
    for (const auto& Algorithm : StoredAlgorithms)
    {
        if (Algorithm.AlgorithmName == SelectedItem)
        {
            // Display parameters for the selected algorithm
            for (const auto& Param : Algorithm.Parameters)
            {
                FString ParamInfo = FString::Printf(TEXT("%s: %s"), *Param.Key, *Param.Value);
                UTextBlock* ParamText = NewObject<UTextBlock>(this);
                ParamText->SetText(FText::FromString(ParamInfo));
                ParametersBox->AddChildToVerticalBox(ParamText);
            }
            break;
        }
    }
}


void UDynamicUIWidget::PopulateUIFromJson(const FString& JsonData)
{
    TArray<TSharedPtr<FJsonValue>> JsonArray;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonData);

    if (FJsonSerializer::Deserialize(Reader, JsonArray))
    {
        AlgorithmComboBox->ClearOptions();
        ParametersBox->ClearChildren();
        StoredAlgorithms.Empty(); // Clear existing data

        // Loop through each algorithm in the array
        for (const TSharedPtr<FJsonValue>& Value : JsonArray)
        {
            TSharedPtr<FJsonObject> AlgoObj = Value->AsObject();
            if (AlgoObj.IsValid())
            {
                FAlgorithmData NewAlgo;
                NewAlgo.AlgorithmName = AlgoObj->GetStringField("name");
                AlgorithmComboBox->AddOption(NewAlgo.AlgorithmName);


                TSharedPtr<FJsonObject> ParamsObj = AlgoObj->GetObjectField("params");
                for (const auto& Param : ParamsObj->Values)
                {
                    // Add each parameter to the NewAlgo struct
                    NewAlgo.Parameters.Add(Param.Key, Param.Value->AsString());
                }

                // Add the fully constructed algorithm data to the storage
                StoredAlgorithms.Add(NewAlgo);
            }
        }
    }
}


FString UDynamicUIWidget::OnSendButtonClicked()
{
    FString SelectedAlgorithm = AlgorithmComboBox->GetSelectedOption();
    FString ResultJsonString;

    // Find the selected algorithm in the stored data
    for (const FAlgorithmData& AlgoData : StoredAlgorithms)
    {
        if (AlgoData.AlgorithmName == SelectedAlgorithm)
        {
            TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
            JsonObject->SetStringField(TEXT("algo"), AlgoData.AlgorithmName);

            TSharedPtr<FJsonObject> ParamsObject = MakeShareable(new FJsonObject);
            for (const auto& Param : AlgoData.Parameters)
            {
                ParamsObject->SetStringField(Param.Key, Param.Value);
            }

            JsonObject->SetObjectField(TEXT("params"), ParamsObject);

            TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&ResultJsonString);
            FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

            break;
        }
    }

    return ResultJsonString;
}
