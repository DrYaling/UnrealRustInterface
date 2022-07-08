// Copyright Epic Games, Inc. All Rights Reserved.

#include "unreal_rs.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "RustApi.h"

#define LOCTEXT_NAMESPACE "Funreal_rsModule"

void Funreal_rsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LogTemp, Display, TEXT("unreal_rs module starting..."));
	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("unreal_rs")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/UnrealRsLibrary/Win64/unreal_rs.dll"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/unreal_rsLibrary/Mac/Release/unreal_rs.dylib"));
#endif // PLATFORM_WINDOWS

	_rust_api_handle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (_rust_api_handle)
	{
		// Call the test function in the third party library that opens a message box
		RustApi::InitRustEngine();
		UE_LOG(LogTemp, Display, TEXT("unreal_rs module loaded"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("unreal_rs module load fail"));
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load unreal_rs"));
	}
}

void Funreal_rsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(_rust_api_handle);
	_rust_api_handle = nullptr;
	UE_LOG(LogTemp, Display, TEXT("unreal_rs module unloaded"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Funreal_rsModule, unreal_rs)
