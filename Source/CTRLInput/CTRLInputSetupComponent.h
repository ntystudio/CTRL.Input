// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Components/ActorComponent.h"

#include "CTRLInputSetupComponent.generated.h"

class UInputComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CTRLINPUT_API UCTRLInputSetupComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCTRLInputSetupComponent();

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent(UInputComponent* PlayerInputComponent);

	UFUNCTION()
	void OnInput_AbilityInputTagPressed(FGameplayTag InputTag);

	UFUNCTION()
	void OnInput_AbilityInputTagReleased(FGameplayTag InputTag);

protected:
	TArray<uint32> BindHandles;
};
