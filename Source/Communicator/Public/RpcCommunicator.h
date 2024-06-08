// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "grpc++/grpc++.h"
#include "mlagents_envs/communicator_objects/unreal_to_external.grpc.pb.h"
#include "mlagents_envs/communicator_objects/unreal_message.pb.h"

/**
 * 
 */
class COMMUNICATOR_API RpcCommunicator
{
public:
	RpcCommunicator();
	bool Initialize(FString Name, int32 Port);

private:	
	bool bIsOpen;

	std::unique_ptr<communicator_objects::UnrealToExternalProto::Stub> Stub;
	std::shared_ptr<grpc::Channel> Channel;

	communicator_objects::UnrealInputProto Initialize(int32 Port, const communicator_objects::UnrealOutputProto& UnrealOutput, communicator_objects::UnrealInputProto& UnrealInput); 
    static communicator_objects::UnrealMessageProto WrapMessage(const communicator_objects::UnrealOutputProto& Content, int32 Status);
	void NotifyQuitAndShutDownChannel();
};
