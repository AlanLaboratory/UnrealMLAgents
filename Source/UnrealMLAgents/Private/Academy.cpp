#include "UnrealMLAgents/Academy.h"
#include "Editor/EditorEngine.h"
#include "Editor.h"
#include "GenericPlatform/GenericPlatformMisc.h"

UAcademy* UAcademy::Instance = nullptr;

UAcademy::UAcademy()
{
	FCoreDelegates::OnExit.AddUObject(this, &UAcademy::Dispose);
	StepRecursionChecker->Initialize("EnvironmentStep");
#if WITH_EDITOR
	FEditorDelegates::EndPIE.AddUObject(this, &UAcademy::Dispose);
#endif
}

// Make the Academy Tick
bool UAcademy::IsTickable() const
{
	return true;
}

void UAcademy::Tick(float DeltaTime)
{
	EnvironmentStep();
}

TStatId UAcademy::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(ThisClassName, STATGROUP_Tickables);
}

UAcademy* UAcademy::GetInstance()
{
	if (!Instance)
	{
		Instance = NewObject<UAcademy>();
		Instance->AddToRoot();
		Instance->LazyInitialize();
	}
	return Instance;
}

void UAcademy::LazyInitialize()
{
	if (!bInitialized)
	{
		InitializeEnvironment();
		bInitialized = true;
	}
}

void UAcademy::ParseCommandLineArgs()
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

void UAcademy::InitializeEnvironment()
{
	UE_LOG(LogTemp, Log, TEXT("Initialize Environement"));

	bEnableStepping = true;
	ParseCommandLineArgs();

	RpcCommunicator = NewObject<URpcCommunicator>();

	if (RpcCommunicator != nullptr)
	{
		bool						bInitSuccessful = false;
		FCommunicatorInitParameters CommunicatorInitParams;
		CommunicatorInitParams.Port = Port;
		CommunicatorInitParams.UnrealCommunicationVersion = ApiVersion;
		CommunicatorInitParams.UnrealPackageVersion = PackageVersion;
		CommunicatorInitParams.Name = TEXT("AcademySingleton");

		try
		{
			FUnrealRLInitParameters UnrealRLInitParameters;
			bInitSuccessful = RpcCommunicator->Initialize(CommunicatorInitParams, UnrealRLInitParameters);

			if (bInitSuccessful)
			{
				FMath::SRandInit(UnrealRLInitParameters.Seed);
				InferenceSeed = UnrealRLInitParameters.Seed;
				NumAreas = UnrealRLInitParameters.NumAreas;
			}
			else
			{
				UE_LOG(LogTemp, Warning,
					TEXT(
						"Couldn't connect to trainer on port %d using API version %s. Will perform inference instead."),
					Port, *CommunicatorInitParams.UnrealCommunicationVersion);
				RpcCommunicator = nullptr;
			}
		}
		catch (const std::exception& Ex)
		{
			UE_LOG(LogTemp, Error,
				TEXT(
					"Unexpected exception when trying to initialize communication: %s\nWill perform inference instead."),
				UTF8_TO_TCHAR(Ex.what()));
			RpcCommunicator = nullptr;
		}
	}

	if (RpcCommunicator != nullptr)
	{
		RpcCommunicator->OnQuitCommandReceived().AddDynamic(this, &UAcademy::OnQuitCommandReceived);
		RpcCommunicator->OnResetCommandReceived().AddDynamic(this, &UAcademy::OnResetCommand);
	}

	// If a communicator is enabled/provided, then we assume we are in
	// training mode. In the absence of a communicator, we assume we are
	// in inference mode.

	ResetActions();
}

void UAcademy::EnvironmentStep()
{

	// TODO: Recursion check

	if (!bHadFirstReset)
	{
		ForcedFullReset();
	}

	if (OnAgentPreStep.IsBound())
	{
		OnAgentPreStep.Broadcast(StepCount);
	}

	StepCount += 1;
	TotalStepCount += 1;

	if (OnAgentIncrementStep.IsBound())
	{
		OnAgentIncrementStep.Broadcast();
	}

	if (OnAgentSendState.IsBound())
	{
		OnAgentSendState.Broadcast();
	}

	if (OnDecideAction.IsBound())
	{
		OnDecideAction.Broadcast();
	}

	if (OnAgentAct.IsBound())
	{
		OnAgentAct.Broadcast();
	}
}

void UAcademy::OnQuitCommandReceived()
{
	FGenericPlatformMisc::RequestExit(false);
}

void UAcademy::OnResetCommand()
{
	ForcedFullReset();
}

void UAcademy::Dispose()
{
	Dispose(false);
}

void UAcademy::Dispose(bool bIsSimulating)
{

	// Signal to listeners that the academy is being destroyed now
	if (OnDestroyAction.IsBound())
	{
		OnDestroyAction.Broadcast();
	}

	if (RpcCommunicator != nullptr)
	{
		RpcCommunicator->Dispose();
		RpcCommunicator = nullptr;
	}

	// Clear out the actions so we're not keeping references to any old objects
	ResetActions();

	// Reset the Lazy instance
	bInitialized = false;
	Instance = nullptr;
}

void UAcademy::ForcedFullReset()
{
	EnvironmentReset();
	if (OnAgentForceReset.IsBound())
	{
		OnAgentForceReset.Broadcast();
	}
	bHadFirstReset = true;
}

void UAcademy::EnvironmentReset()
{
	StepCount = 0;
	EpisodeCount++;
	if (OnEnvironmentReset.IsBound())
	{
		OnEnvironmentReset.Broadcast();
	}
}

void UAcademy::ResetActions()
{
	OnDecideAction.Clear();
	OnDestroyAction.Clear();
	OnAgentPreStep.Clear();
	OnAgentSendState.Clear();
	OnAgentAct.Clear();
	OnAgentForceReset.Clear();
	OnEnvironmentReset.Clear();
}

bool UAcademy::IsCommunicatorOn()
{
	return RpcCommunicator != nullptr;
}
