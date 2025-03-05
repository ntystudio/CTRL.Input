// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCTRLInput, Log, All);

#define CTRL_INPUT_LOG(Verbosity, ...) UE_LOG(LogCTRLInput, Verbosity, ##__VA_ARGS__)

class FCTRLInputModule : public IModuleInterface
{
};
