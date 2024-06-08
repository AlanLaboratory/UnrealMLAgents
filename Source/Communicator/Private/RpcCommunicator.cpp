// Fill out your copyright notice in the Description page of Project Settings.


#include "RpcCommunicator.h"

RpcCommunicator::RpcCommunicator()
	: bIsOpen(false)
{
}

bool RpcCommunicator::Initialize(FString Name, int32 Port)
{
    // Dummy initialization parameters for the example
    communicator_objects::UnrealRLInitializationOutputProto AcademyParameters;
    AcademyParameters.set_name(TCHAR_TO_UTF8(*Name));

    // Create input and output for initialization
    communicator_objects::UnrealInputProto Input;
    communicator_objects::UnrealInputProto InitializationInput;

	// Assuming we have some Initialize method to communicate with the server
	InitializationInput = Initialize(Port, communicator_objects::UnrealOutputProto(), Input);

    return true;
}

communicator_objects::UnrealInputProto RpcCommunicator::Initialize(int32 Port, const communicator_objects::UnrealOutputProto& UnrealOutput, communicator_objects::UnrealInputProto& UnrealInput)
{
    bIsOpen = true;
    FString ServerAddress = FString::Printf(TEXT("localhost:%d"), Port);
    Channel = grpc::CreateChannel(TCHAR_TO_UTF8(*ServerAddress), grpc::InsecureChannelCredentials());
    Stub = communicator_objects::UnrealToExternalProto::NewStub(Channel);

    // Send and receive messages
    grpc::ClientContext Context;
    communicator_objects::UnrealMessageProto Request = WrapMessage(UnrealOutput, 200);
    communicator_objects::UnrealMessageProto Response;

    grpc::Status Status = Stub->Exchange(&Context, Request, &Response);

    if (!Status.ok())
    {
        UE_LOG(LogTemp, Error, TEXT("gRPC error: %s"), UTF8_TO_TCHAR(Status.error_message().c_str()));
        NotifyQuitAndShutDownChannel();
        return communicator_objects::UnrealInputProto();
    }

    grpc::ClientContext Context2;
    communicator_objects::UnrealMessageProto InputRequest = WrapMessage(communicator_objects::UnrealOutputProto(), 200);
    grpc::Status InputStatus = Stub->Exchange(&Context2, InputRequest, &Response);

    if (!InputStatus.ok())
    {
        UE_LOG(LogTemp, Error, TEXT("gRPC error: %s"), UTF8_TO_TCHAR(InputStatus.error_message().c_str()));
        NotifyQuitAndShutDownChannel();
        return communicator_objects::UnrealInputProto();
    }

    UnrealInput = Response.unreal_input();

    if (Response.header().status() != 200)
    {
        bIsOpen = false;
        NotifyQuitAndShutDownChannel();
    }

    return Response.unreal_input();
}

communicator_objects::UnrealMessageProto RpcCommunicator::WrapMessage(const communicator_objects::UnrealOutputProto& Content, int32 Status)
{
    communicator_objects::UnrealMessageProto Message;
    auto* Header = Message.mutable_header();
    Header->set_status(Status);
    *Message.mutable_unreal_output() = Content;
    return Message;
}

void RpcCommunicator::NotifyQuitAndShutDownChannel()
{
    if (Channel)
    {
        Channel.reset();
    }
}
