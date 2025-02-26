// Copyright Epic Games, Inc. All Rights Reserved.

#include "CTRLInputModifiers.h"

#include "EnhancedPlayerInput.h"
// #include "CTRLAimSensitivityData.h"

#include "GameFramework/PlayerController.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CTRLInputModifiers)

DEFINE_LOG_CATEGORY_STATIC(LogCTRLInputModifiers, Log, All);

//////////////////////////////////////////////////////////////////////
// CTRLInputModifiersHelpers

namespace CTRLInputModifiersHelpers
{
	/** Returns the owning CTRLLocalPlayer of an Enhanced Player Input pointer */
	static ULocalPlayer* GetLocalPlayer(UEnhancedPlayerInput const* PlayerInput)
	{
		if (!PlayerInput) return nullptr;
		if (auto const* PC = Cast<APlayerController>(PlayerInput->GetOuter()))
		{
			return PC->GetLocalPlayer();
		}
	}
}

//////////////////////////////////////////////////////////////////////
// UCTRLSettingBasedScalar

FInputActionValue UCTRLSettingBasedScalar::ModifyRaw_Implementation(UEnhancedPlayerInput const* PlayerInput, FInputActionValue const CurrentValue, float DeltaTime)
{
	return CurrentValue;
	// if (ensureMsgf(CurrentValue.GetValueType() != EInputActionValueType::Boolean, TEXT("Setting Based Scalar modifier doesn't support boolean values.")))
	// {
	// 	// if (auto* LocalPlayer = CTRLInputModifiersHelpers::GetLocalPlayer(PlayerInput))
	// 	// {
	// 	// 	// UClass const* SettingsClass = UCTRLSettingsShared::StaticClass();
	// 	// 	// UCTRLSettingsShared* SharedSettings = LocalPlayer->GetSharedSettings();
	// 	//
	// 	// 	bool const bHasCachedProperty = PropertyCache.Num() == 3;
	// 	//
	// 	// 	FProperty const* XAxisValue = bHasCachedProperty ? PropertyCache[0] : SettingsClass->FindPropertyByName(XAxisScalarSettingName);
	// 	// 	FProperty const* YAxisValue = bHasCachedProperty ? PropertyCache[1] : SettingsClass->FindPropertyByName(YAxisScalarSettingName);
	// 	// 	FProperty const* ZAxisValue = bHasCachedProperty ? PropertyCache[2] : SettingsClass->FindPropertyByName(ZAxisScalarSettingName);
	// 	//
	// 	// 	if (PropertyCache.IsEmpty())
	// 	// 	{
	// 	// 		PropertyCache.Emplace(XAxisValue);
	// 	// 		PropertyCache.Emplace(YAxisValue);
	// 	// 		PropertyCache.Emplace(ZAxisValue);
	// 	// 	}
	// 	//
	// 	// 	FVector ScalarToUse = FVector(1.0, 1.0, 1.0);
	// 	//
	// 	// 	switch (CurrentValue.GetValueType())
	// 	// 	{
	// 	// 		case EInputActionValueType::Axis3D:
	// 	// 			ScalarToUse.Z = ZAxisValue ? *ZAxisValue->ContainerPtrToValuePtr<double>(SharedSettings) : 1.0;
	// 	// 		//[[fallthrough]];
	// 	// 		case EInputActionValueType::Axis2D:
	// 	// 			ScalarToUse.Y = YAxisValue ? *YAxisValue->ContainerPtrToValuePtr<double>(SharedSettings) : 1.0;
	// 	// 		//[[fallthrough]];
	// 	// 		case EInputActionValueType::Axis1D:
	// 	// 			ScalarToUse.X = XAxisValue ? *XAxisValue->ContainerPtrToValuePtr<double>(SharedSettings) : 1.0;
	// 	// 			break;
	// 	// 	}
	// 	//
	// 	// 	ScalarToUse.X = FMath::Clamp(ScalarToUse.X, MinValueClamp.X, MaxValueClamp.X);
	// 	// 	ScalarToUse.Y = FMath::Clamp(ScalarToUse.Y, MinValueClamp.Y, MaxValueClamp.Y);
	// 	// 	ScalarToUse.Z = FMath::Clamp(ScalarToUse.Z, MinValueClamp.Z, MaxValueClamp.Z);
	// 	//
	// 	// 	return CurrentValue.Get<FVector>() * ScalarToUse;
	// 	// }
	// }

	// return CurrentValue;
}

//////////////////////////////////////////////////////////////////////
// UCTRLInputModifierDeadZone

FInputActionValue UCTRLInputModifierDeadZone::ModifyRaw_Implementation(UEnhancedPlayerInput const* PlayerInput, FInputActionValue const CurrentValue, float DeltaTime)
{
	return CurrentValue;
	// EInputActionValueType ValueType = CurrentValue.GetValueType();
	// UCTRLLocalPlayer* LocalPlayer = CTRLInputModifiersHelpers::GetLocalPlayer(PlayerInput);
	// if (ValueType == EInputActionValueType::Boolean || !LocalPlayer)
	// {
	// 	return CurrentValue;
	// }
	//
	// UCTRLSettingsShared* Settings = LocalPlayer->GetSharedSettings();
	// ensure(Settings);
	//
	// float LowerThreshold =
	// 	(DeadzoneStick == EDeadzoneStick::MoveStick) ? Settings->GetGamepadMoveStickDeadZone() : Settings->GetGamepadLookStickDeadZone();
	//
	// LowerThreshold = FMath::Clamp(LowerThreshold, 0.0f, 1.0f);
	//
	// auto DeadZoneLambda = [LowerThreshold, this](float const AxisVal)
	// {
	// 	// We need to translate and scale the input to the +/- 1 range after removing the dead zone.
	// 	return FMath::Min(1.f, (FMath::Max(0.f, FMath::Abs(AxisVal) - LowerThreshold) / (UpperThreshold - LowerThreshold))) * FMath::Sign(AxisVal);
	// };
	//
	// FVector NewValue = CurrentValue.Get<FVector>();
	// switch (Type)
	// {
	// 	case EDeadZoneType::Axial:
	// 		NewValue.X = DeadZoneLambda(NewValue.X);
	// 		NewValue.Y = DeadZoneLambda(NewValue.Y);
	// 		NewValue.Z = DeadZoneLambda(NewValue.Z);
	// 		break;
	// 	case EDeadZoneType::Radial:
	// 		if (ValueType == EInputActionValueType::Axis3D)
	// 		{
	// 			NewValue = NewValue.GetSafeNormal() * DeadZoneLambda(NewValue.Size());
	// 		}
	// 		else if (ValueType == EInputActionValueType::Axis2D)
	// 		{
	// 			NewValue = NewValue.GetSafeNormal2D() * DeadZoneLambda(NewValue.Size2D());
	// 		}
	// 		else
	// 		{
	// 			NewValue.X = DeadZoneLambda(NewValue.X);
	// 		}
	// 		break;
	// }
	//
	// return NewValue;
}

FLinearColor UCTRLInputModifierDeadZone::GetVisualizationColor_Implementation(FInputActionValue SampleValue, FInputActionValue const FinalValue) const
{
	// Taken from UInputModifierDeadZone::GetVisualizationColor_Implementation
	if (FinalValue.GetValueType() == EInputActionValueType::Boolean || FinalValue.GetValueType() == EInputActionValueType::Axis1D)
	{
		return FLinearColor(FinalValue.Get<float>() == 0.f ? 1.f : 0.f, 0.f, 0.f);
	}
	return FLinearColor((FinalValue.Get<FVector2D>().X == 0.f ? 0.5f : 0.f) + (FinalValue.Get<FVector2D>().Y == 0.f ? 0.5f : 0.f), 0.f, 0.f);
}

//////////////////////////////////////////////////////////////////////
// UCTRLInputModifierGamepadSensitivity

FInputActionValue UCTRLInputModifierGamepadSensitivity::ModifyRaw_Implementation(UEnhancedPlayerInput const* PlayerInput, FInputActionValue const CurrentValue, float DeltaTime)
{
	return CurrentValue;
	// // You can't scale a boolean action type
	// auto* LocalPlayer = CTRLInputModifiersHelpers::GetLocalPlayer(PlayerInput);
	// if (CurrentValue.GetValueType() == EInputActionValueType::Boolean || !LocalPlayer || !SensitivityLevelTable)
	// {
	// 	return CurrentValue;
	// }
	//
	// UCTRLSettingsShared* Settings = LocalPlayer->GetSharedSettings();
	// ensure(Settings);
	//
	// ECTRLGamepadSensitivity const Sensitivity = (TargetingType == ECTRLTargetingType::Normal) ? Settings->GetGamepadLookSensitivityPreset() : Settings->GetGamepadTargetingSensitivityPreset();
	//
	// float const Scalar = SensitivityLevelTable->SensitivtyEnumToFloat(Sensitivity);
	//
	// return CurrentValue.Get<FVector>() * Scalar;
}

//////////////////////////////////////////////////////////////////////
// UCTRLInputModifierAimInversion

FInputActionValue UCTRLInputModifierAimInversion::ModifyRaw_Implementation(UEnhancedPlayerInput const* PlayerInput, FInputActionValue const CurrentValue, float DeltaTime)
{
	return CurrentValue;
	// UCTRLLocalPlayer* LocalPlayer = CTRLInputModifiersHelpers::GetLocalPlayer(PlayerInput);
	// if (!LocalPlayer)
	// {
	// 	return CurrentValue;
	// }
	//
	// UCTRLSettingsShared* Settings = LocalPlayer->GetSharedSettings();
	// ensure(Settings);
	//
	// FVector NewValue = CurrentValue.Get<FVector>();
	//
	// if (Settings->GetInvertVerticalAxis())
	// {
	// 	NewValue.Y *= -1.0f;
	// }
	//
	// if (Settings->GetInvertHorizontalAxis())
	// {
	// 	NewValue.X *= -1.0f;
	// }
	//
	// return NewValue;
}
