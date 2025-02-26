// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CTRLInputConfig.h"
#include "EnhancedInputComponent.h"
#include "CTRLInputComponent.generated.h"

class UEnhancedInputLocalPlayerSubsystem;
class UInputAction;
class UObject;


/**
 * UCTRLInputComponent
 *
 *	Component used to manage input mappings and bindings using an input config data asset.
 */
UCLASS(BlueprintType, Config = Input)
class CTRLINPUT_API UCTRLInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	UCTRLInputComponent(FObjectInitializer const& ObjectInitializer);

	void AddInputMappings(UCTRLInputConfig const* InputConfig, UEnhancedInputLocalPlayerSubsystem const* InputSubsystem) const;
	void RemoveInputMappings(UCTRLInputConfig const* InputConfig, UEnhancedInputLocalPlayerSubsystem const* InputSubsystem) const;

	template<class UserClass, typename FuncType>
	void BindNativeAction(UCTRLInputConfig const* InputConfig, FGameplayTag const& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound);

	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityActions(UCTRLInputConfig const* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray<uint32>& BindHandles);

	void RemoveBinds(TArray<uint32>& BindHandles);
};


template<class UserClass, typename FuncType>
void UCTRLInputComponent::BindNativeAction(UCTRLInputConfig const* InputConfig, FGameplayTag const& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool const bLogIfNotFound)
{
	check(InputConfig);
	if (auto InputAction = InputConfig->FindNativeInputActionForTag(InputTag, bLogIfNotFound))
	{
		BindAction(InputAction, TriggerEvent, Object, Func);
	}
}

template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
void UCTRLInputComponent::BindAbilityActions(UCTRLInputConfig const* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray<uint32>& BindHandles)
{
	check(InputConfig);

	for (auto const& [InputAction, InputTag] : InputConfig->AbilityInputActions)
	{
		if (InputAction && InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindHandles.Add(BindAction(InputAction, ETriggerEvent::Triggered, Object, PressedFunc, InputTag).GetHandle());
			}

			if (ReleasedFunc)
			{
				BindHandles.Add(BindAction(InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, InputTag).GetHandle());
			}
		}
	}
}
