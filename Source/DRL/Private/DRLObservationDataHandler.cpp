// Fill out your copyright notice in the Description page of Project Settings.


#include "DRLObservationDataHandler.h"


void UObservationDataHandler::HandleData(const TSharedPtr<FJsonObject>& Data)
{
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(Data.ToSharedRef(), Writer);

    UE_LOG(LogTemp, Warning, TEXT("resulting jsonString -> %s"), *OutputString);
}

