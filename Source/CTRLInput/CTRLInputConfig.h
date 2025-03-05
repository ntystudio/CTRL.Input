// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "GameplayTagContainer.h"

#include "Engine/DataAsset.h"

#include "CTRLInputConfig.generated.h"

class UInputAction;
class UObject;
struct FFrame;

/**
 * FCTRLInputAction
 *
 *	Struct used to map an input action to a gameplay input tag.
 */
USTRUCT(BlueprintType, DisplayName="Input Action [CTRL]")
struct FCTRLInputAction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction const> InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

/**
 * UCTRLInputConfig
 *
 *	Non-mutable data asset that contains input configuration properties.
 */
UCLASS(BlueprintType, Const, DisplayName="Input Config Data [CTRL]")
class CTRLINPUT_API UCTRLInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "CTRL|Pawn")
	// ReSharper disable once CppEnforceCVQualifiersPlacement
	const UInputAction* FindNativeInputActionForTag(FGameplayTag const& FindInputTag, bool bLogNotFound = true) const;

	UFUNCTION(BlueprintCallable, Category = "CTRL|Pawn")
	// ReSharper disable once CppEnforceCVQualifiersPlacement
	const UInputAction* FindAbilityInputActionForTag(FGameplayTag const& FindInputTag, bool bLogNotFound = true) const;

public:
	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FCTRLInputAction> NativeInputActions;

	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and are automatically bound to abilities with matching input tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FCTRLInputAction> AbilityInputActions;
};
