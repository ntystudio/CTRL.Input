// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Components/ActorComponent.h"

#include "CTRLInputSetupComponent.generated.h"

class UInputComponent;
class APlayerController;

UCLASS(ClassGroup=(Input), DisplayName="Input Setup Component [CTRL]", meta=(BlueprintSpawnableComponent))
class CTRLINPUT_API UCTRLInputSetupComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCTRLInputSetupComponent();

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent(APlayerController* PlayerController, UInputComponent* PlayerInputComponent);

	UFUNCTION()
	void OnInput_AbilityInputTagPressed(FGameplayTag InputTag);

	UFUNCTION()
	void OnInput_AbilityInputTagReleased(FGameplayTag InputTag);

protected:
	TArray<uint32> BindHandles;
};
