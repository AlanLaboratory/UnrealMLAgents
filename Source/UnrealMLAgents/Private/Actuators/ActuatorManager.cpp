#include "UnrealMLAgents/Actuators/ActuatorManager.h"

// Initialize with a preset capacity
void UActuatorManager::Initialize(int32 Capacity)
{
	Actuators.Reserve(Capacity);
}

// Ready actuators for execution
void UActuatorManager::ReadyActuatorsForExecution()
{
	ReadyActuatorsForExecution(Actuators, NumContinuousActions, SumOfDiscreteBranchSizes, NumDiscreteActions);
}

const UActuatorDiscreteActionMask& UActuatorManager::GetDiscreteActionMask() const
{
	return *DiscreteActionMask;
}

// Helper method for readying actuators
void UActuatorManager::ReadyActuatorsForExecution(const TArray<TScriptInterface<IActuator>>& InActuators,
	int32 InNumContinuousActions, int32 InSumOfDiscreteBranchSizes, int32 InNumDiscreteBranches)
{
	if (bReadyForExecution)
	{
		return;
	}

#if UE_BUILD_DEBUG
	// Make sure the names are actually unique
	ValidateActuators();
#endif

	// Sort the Actuators by name to ensure determinism
	SortActuators(Actuators);

	TSharedPtr<TArray<int32>> DiscreteActionArray = MakeShared<TArray<int32>>();
	DiscreteActionArray->Init(0, InNumDiscreteBranches);

	TSharedPtr<TArray<float>> ContinuousActionArray = MakeShared<TArray<float>>();
	ContinuousActionArray->Init(0.0f, InNumContinuousActions);

	FActionSegment<int32> DiscreteActions =
		(InNumDiscreteBranches == 0) ? FActionSegment<int32>::Empty : FActionSegment<int32>(DiscreteActionArray);

	FActionSegment<float> ContinuousActions =
		(InNumContinuousActions == 0) ? FActionSegment<float>::Empty : FActionSegment<float>(ContinuousActionArray);

	StoredActions = FActionBuffers(ContinuousActions, DiscreteActions);
	CombinedActionSpec = CombineActionSpecs(InActuators);
	DiscreteActionMask = NewObject<UActuatorDiscreteActionMask>();
	DiscreteActionMask->Initialize(
		InActuators, InSumOfDiscreteBranchSizes, InNumDiscreteBranches, CombinedActionSpec.BranchSizes);
	bReadyForExecution = true;
}

// Combine action specs
FActionSpec UActuatorManager::CombineActionSpecs(const TArray<TScriptInterface<IActuator>>& InActuators)
{
	int32 NumContinuousActions = 0;
	int32 NumDiscreteActions = 0;

	for (const auto& Actuator : InActuators)
	{
		NumContinuousActions += Actuator->GetActionSpec().NumContinuousActions;
		NumDiscreteActions += Actuator->GetActionSpec().GetNumDiscreteActions();
	}

	TArray<int32> CombinedBranchSizes;
	if (NumDiscreteActions == 0)
	{
		CombinedBranchSizes.Empty();
	}
	else
	{
		CombinedBranchSizes.SetNum(NumDiscreteActions);
		int32 Start = 0;
		for (const auto& Actuator : InActuators)
		{
			const TArray<int32>& BranchSizes = Actuator->GetActionSpec().BranchSizes;
			if (BranchSizes.Num() > 0)
			{
				FMemory::Memcpy(
					CombinedBranchSizes.GetData() + Start, BranchSizes.GetData(), BranchSizes.Num() * sizeof(int32));
				Start += BranchSizes.Num();
			}
		}
	}

	return FActionSpec(NumContinuousActions, CombinedBranchSizes);
}

// Returns an ActionSpec representing the concatenation of all IActuator's ActionSpecs
FActionSpec UActuatorManager::GetCombinedActionSpec()
{
	ReadyActuatorsForExecution();
	return CombinedActionSpec;
}

// Updates the local action buffer
void UActuatorManager::UpdateActions(const FActionBuffers& Actions)
{
	ReadyActuatorsForExecution();
	UpdateActionArray<float>(Actions.ContinuousActions, StoredActions.ContinuousActions);
	UpdateActionArray<int32>(Actions.DiscreteActions, StoredActions.DiscreteActions);
}

template <typename T>
void UActuatorManager::UpdateActionArray(const FActionSegment<T>& SourceActionBuffer, FActionSegment<T>& Destination)
{
	if (SourceActionBuffer.Length <= 0)
	{
		Destination.Clear();
	}
	else
	{
		if (SourceActionBuffer.Length != Destination.Length)
		{
			checkf(SourceActionBuffer.Length == Destination.Length,
				TEXT("sourceActionBuffer: %d is a different size than destination: %d."), SourceActionBuffer.Length,
				Destination.Length);
		}

		// Ensure both source and destination arrays are valid
		check(SourceActionBuffer.Array.IsValid() && Destination.Array.IsValid());

		// Perform memory copy
		FMemory::Memcpy(Destination.Array->GetData() + Destination.Offset,
			SourceActionBuffer.Array->GetData() + SourceActionBuffer.Offset, SourceActionBuffer.Length * sizeof(T));
	}
}

// Validate actuators
void UActuatorManager::ValidateActuators()
{
	// Implementation logic to validate actuators...
	for (int32 i = 0; i < Actuators.Num() - 1; i++)
	{
		checkf(!Actuators[i]->GetName().Equals(Actuators[i + 1]->GetName()), TEXT("Actuator names must be unique."));
	}
}

// Sort actuators
void UActuatorManager::SortActuators(TArray<TScriptInterface<IActuator>>& InActuators)
{
	// Implementation logic to sort actuators...
	InActuators.Sort([](const TScriptInterface<IActuator>& A, const TScriptInterface<IActuator>& B) {
		return A->GetName() < B->GetName();
	});
}

// Write action mask
void UActuatorManager::WriteActionMask()
{
	ReadyActuatorsForExecution();
	DiscreteActionMask->ResetMask();
	int32 Offset = 0;
	for (const auto& Actuator : Actuators)
	{
		if (Actuator->GetActionSpec().GetNumDiscreteActions() > 0)
		{
			DiscreteActionMask->CurrentBranchOffset = Offset;
			Actuator->WriteDiscreteActionMask(DiscreteActionMask);
			Offset += Actuator->GetActionSpec().GetNumDiscreteActions();
		}
	}
}

// Apply heuristic
void UActuatorManager::ApplyHeuristic(const FActionBuffers& ActionBuffersOut)
{
	int32 ContinuousStart = 0;
	int32 DiscreteStart = 0;
	for (const auto& Actuator : Actuators)
	{
		int32 NumberContinuousActions = Actuator->GetActionSpec().NumContinuousActions;
		int32 NumberDiscreteActions = Actuator->GetActionSpec().GetNumDiscreteActions();

		if (NumberContinuousActions == 0 && NumberDiscreteActions == 0)
		{
			continue;
		}

		FActionSegment<float> ContinuousActions = FActionSegment<float>::Empty;
		if (NumberContinuousActions > 0)
		{
			ContinuousActions = FActionSegment<float>(
				ActionBuffersOut.ContinuousActions.Array, ContinuousStart, NumberContinuousActions);
		}

		FActionSegment<int32> DiscreteActions = FActionSegment<int32>::Empty;
		if (NumberDiscreteActions > 0)
		{
			DiscreteActions =
				FActionSegment<int32>(ActionBuffersOut.DiscreteActions.Array, DiscreteStart, NumberDiscreteActions);
		}
		FActionBuffers TempActionBuffersOut(ContinuousActions, DiscreteActions);
		Actuator->Heuristic(TempActionBuffersOut);
		ContinuousStart += NumberContinuousActions;
		DiscreteStart += NumberDiscreteActions;
	}
}

void UActuatorManager::ExecuteActions()
{
	ReadyActuatorsForExecution();

	int32 ContinuousStart = 0;
	int32 DiscreteStart = 0;
	for (int32 i = 0; i < Actuators.Num(); i++)
	{
		const auto& Actuator = Actuators[i];
		int32		NumberContinuousActions = Actuator->GetActionSpec().NumContinuousActions;
		int32		NumberDiscreteActions = Actuator->GetActionSpec().GetNumDiscreteActions();

		if (NumberContinuousActions == 0 && NumberDiscreteActions == 0)
		{
			continue;
		}

		FActionSegment<float> ContinuousActions = FActionSegment<float>::Empty;
		if (NumberContinuousActions > 0)
		{
			ContinuousActions =
				FActionSegment<float>(StoredActions.ContinuousActions.Array, ContinuousStart, NumberContinuousActions);
		}

		FActionSegment<int32> DiscreteActions = FActionSegment<int32>::Empty;
		if (NumberDiscreteActions > 0)
		{
			DiscreteActions =
				FActionSegment<int32>(StoredActions.DiscreteActions.Array, DiscreteStart, NumberDiscreteActions);
		}

		Actuator->OnActionReceived(FActionBuffers(ContinuousActions, DiscreteActions));
		ContinuousStart += NumberContinuousActions;
		DiscreteStart += NumberDiscreteActions;
	}
}

void UActuatorManager::ResetData()
{
	if (!bReadyForExecution)
	{
		return;
	}
	StoredActions.Clear();
	for (int32 i = 0; i < Actuators.Num(); i++)
	{
		Actuators[i]->ResetData();
	}
	DiscreteActionMask->ResetMask();
}

void UActuatorManager::AddToBufferSizes(const TScriptInterface<IActuator>& ActuatorItem)
{
	if (!ActuatorItem)
	{
		return;
	}

	NumContinuousActions += ActuatorItem->GetActionSpec().NumContinuousActions;
	NumDiscreteActions += ActuatorItem->GetActionSpec().GetNumDiscreteActions();
	SumOfDiscreteBranchSizes += ActuatorItem->GetActionSpec().GetSumOfDiscreteBranchSizes();
}

void UActuatorManager::SubtractFromBufferSizes(const TScriptInterface<IActuator>& ActuatorItem)
{
	if (!ActuatorItem)
	{
		return;
	}

	NumContinuousActions -= ActuatorItem->GetActionSpec().NumContinuousActions;
	NumDiscreteActions -= ActuatorItem->GetActionSpec().GetNumDiscreteActions();
	SumOfDiscreteBranchSizes -= ActuatorItem->GetActionSpec().GetSumOfDiscreteBranchSizes();
}

void UActuatorManager::ClearBufferSizes()
{
	NumContinuousActions = 0;
	NumDiscreteActions = 0;
	SumOfDiscreteBranchSizes = 0;
}

void UActuatorManager::AddActuators(const TArray<TScriptInterface<IActuator>>& InActuators)
{
	for (const TScriptInterface<IActuator>& Actuator : InActuators)
	{
		Add(Actuator);
	}
}

TScriptInterface<IActuator> UActuatorManager::Get(int32 Index) const
{
	return Actuators[Index];
}

void UActuatorManager::Set(int32 Index, const TScriptInterface<IActuator>& Value)
{
	check(!bReadyForExecution && "Cannot modify the ActuatorManager after its buffers have been initialized");
	TScriptInterface<IActuator> Old = Actuators[Index];
	SubtractFromBufferSizes(Old);
	Actuators[Index] = Value;
	AddToBufferSizes(Value);
}

void UActuatorManager::Add(const TScriptInterface<IActuator>& Item)
{
	check(!bReadyForExecution && "Cannot add to the ActuatorManager after its buffers have been initialized");
	Actuators.Add(Item);
	AddToBufferSizes(Item);
}

void UActuatorManager::Clear()
{
	check(!bReadyForExecution && "Cannot clear the ActuatorManager after its buffers have been initialized");
	Actuators.Empty();
	ClearBufferSizes();
}

bool UActuatorManager::Contains(const TScriptInterface<IActuator>& Item) const
{
	return Actuators.Contains(Item);
}

void UActuatorManager::CopyTo(TArray<TScriptInterface<IActuator>>& OutArray, int32 ArrayIndex) const
{
	OutArray.SetNum(ArrayIndex + Actuators.Num());
	for (int32 i = 0; i < Actuators.Num(); ++i)
	{
		OutArray[ArrayIndex + i] = Actuators[i];
	}
}

bool UActuatorManager::Remove(const TScriptInterface<IActuator>& Item)
{
	check(!bReadyForExecution && "Cannot remove from the ActuatorManager after its buffers have been initialized");
	if (Actuators.Remove(Item) > 0)
	{
		SubtractFromBufferSizes(Item);
		return true;
	}
	return false;
}

int32 UActuatorManager::Count() const
{
	return Actuators.Num();
}

bool UActuatorManager::IsReadOnly() const
{
	return false;
}

int32 UActuatorManager::IndexOf(const TScriptInterface<IActuator>& Item) const
{
	return Actuators.IndexOfByKey(Item);
}

void UActuatorManager::Insert(int32 Index, const TScriptInterface<IActuator>& Item)
{
	check(!bReadyForExecution && "Cannot insert into the ActuatorManager after its buffers have been initialized");
	Actuators.Insert(Item, Index);
	AddToBufferSizes(Item);
}

void UActuatorManager::RemoveAt(int32 Index)
{
	check(!bReadyForExecution && "Cannot remove from the ActuatorManager after its buffers have been initialized");
	TScriptInterface<IActuator> Actuator = Actuators[Index];
	SubtractFromBufferSizes(Actuator);
	Actuators.RemoveAt(Index);
}

TScriptInterface<IActuator> UActuatorManager::operator[](int32 Index) const
{
	return Get(Index);
}

TScriptInterface<IActuator>& UActuatorManager::operator[](int32 Index)
{
	return Actuators[Index];
}

TArray<TScriptInterface<IActuator>>::TConstIterator UActuatorManager::CreateConstIterator() const
{
	return Actuators.CreateConstIterator();
}

TArray<TScriptInterface<IActuator>>::TIterator UActuatorManager::CreateIterator()
{
	return Actuators.CreateIterator();
}
