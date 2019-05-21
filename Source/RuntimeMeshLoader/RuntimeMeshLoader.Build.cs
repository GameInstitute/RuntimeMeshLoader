// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
    public class RuntimeMeshLoader : ModuleRules
    {
        private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        private string ThirdPartyPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
        }


        public RuntimeMeshLoader(ReadOnlyTargetRules Target) : base(Target)
        {
            //Log.TraceInformation("ModulePath: " + ModulePath);
            //Log.TraceInformation("ThirdPartyPath: " + ThirdPartyPath);
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.AddRange(
                new string[] {
                "RuntimeMeshLoader/Public",
                Path.Combine(ThirdPartyPath, "assimp/include")
                    // ... add public include paths required here ...
                }
            );

            foreach(string Pathad in PublicIncludePaths)
            {
                Log.TraceInformation("PublicIncludePaths: " + Pathad);
            }

            PrivateIncludePaths.AddRange(
                new string[] {
                "RuntimeMeshLoader/Private",
                    // ... add other private include paths required here ...
                }
                );


            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                "Core",
                "CoreUObject",
                "Engine",
                "ProceduralMeshComponent"
               // "RHI",
               // "RenderCore",
                    // ... add other public dependencies that you statically link with here ...
                }
                );


            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    //	"Slate",
                    //	"SlateCore",
                    // ... add private dependencies that you statically link with here ...	
                    // 
                    "Projects"
                }
                );


            DynamicallyLoadedModuleNames.AddRange(
                new string[]
                {
                }
                );

            if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
            {
                string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32";
                PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "assimp/lib", PlatformString, "assimp-vc140-mt.lib"));

                // Does only declare the file as dependency and seems important for packaging. Though it does not load the file.
                RuntimeDependencies.Add(Path.Combine(ThirdPartyPath, "assimp/bin", PlatformString, "assimp-vc140-mt.dll"));
                // The .dll is loaded manually with the start of the module. See the AnswerHub entry.
                // https://answers.unrealengine.com/questions/427772/adding-dll-path-for-plugin.html
                PublicDelayLoadDLLs.Add("assimp-vc140-mt.dll");
            }
            else if (Target.Platform == UnrealTargetPlatform.Mac)
            {
                string PlatformString = "Mac";
                PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "assimp/lib", PlatformString, "libassimp.4.1.0.dylib"));
            }
        }
    }
}