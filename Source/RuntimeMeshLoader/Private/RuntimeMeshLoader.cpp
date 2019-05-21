// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RuntimeMeshLoader.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FRuntimeMeshLoaderModule"

void FRuntimeMeshLoaderModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString PluginBaseDir = IPluginManager::Get().FindPlugin("RuntimeMeshLoader")->GetBaseDir();
#if PLATFORM_WINDOWS
#if PLATFORM_32BITS
	FString platformString = "Win32";
#elif PLATFORM_64BITS
	FString platformString = "Win64";
#endif
#elif PLATFORM_MAC
	FString platformString = "Mac";
#endif
	dllHandle_assimp = FPlatformProcess::GetDllHandle(*FPaths::Combine(PluginBaseDir, FString("Source/ThirdParty/assimp/bin"), platformString, FString("assimp-vc140-mt.dll")));

}

void FRuntimeMeshLoaderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FPlatformProcess::FreeDllHandle(dllHandle_assimp);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRuntimeMeshLoaderModule, RuntimeMeshLoader)