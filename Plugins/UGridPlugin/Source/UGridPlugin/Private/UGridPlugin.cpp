// Copyright Epic Games, Inc. All Rights Reserved.

#include "UGridPlugin.h"

#include "ISettingsModule.h"
#include "UGridPluginSettings.h"

#define LOCTEXT_NAMESPACE "FUGridPluginModule"

void FUGridPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "UGridPlugin",
			LOCTEXT("RuntimeSettingsName", "UGridPluginSettings"), LOCTEXT("RuntimeSettingsDescription", "Settings for UGridPlugin"),
			GetMutableDefault<UUGridPluginSettings>());
	}
}

void FUGridPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "UGridPlugin");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUGridPluginModule, UGridPlugin)

DEFINE_LOG_CATEGORY(LogUGrid);