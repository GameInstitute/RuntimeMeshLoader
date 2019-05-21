// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/RuntimeMeshLoaderLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRuntimeMeshLoaderLibrary() {}
// Cross Module References
	RUNTIMEMESHLOADER_API UEnum* Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod();
	UPackage* Z_Construct_UPackage__Script_RuntimeMeshLoader();
	RUNTIMEMESHLOADER_API UEnum* Z_Construct_UEnum_RuntimeMeshLoader_EPathType();
	RUNTIMEMESHLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult();
	RUNTIMEMESHLOADER_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	RUNTIMEMESHLOADER_API UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary_NoRegister();
	RUNTIMEMESHLOADER_API UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	RUNTIMEMESHLOADER_API UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetIsExtensionSupported();
	RUNTIMEMESHLOADER_API UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetSupportedExtensions();
	RUNTIMEMESHLOADER_API UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh();
	RUNTIMEMESHLOADER_API UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh_Async();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	static UEnum* EImportMethod_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod, Z_Construct_UPackage__Script_RuntimeMeshLoader(), TEXT("EImportMethod"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EImportMethod(EImportMethod_StaticEnum, TEXT("/Script/RuntimeMeshLoader"), TEXT("EImportMethod"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod_CRC() { return 1747447971U; }
	UEnum* Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeMeshLoader();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EImportMethod"), 0, Get_Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EImportMethod::KeepSections", (int64)EImportMethod::KeepSections },
				{ "EImportMethod::CombineSectionsSameMaterial", (int64)EImportMethod::CombineSectionsSameMaterial },
				{ "EImportMethod::CombineAllSections", (int64)EImportMethod::CombineAllSections },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RuntimeMeshLoader,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EImportMethod",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EImportMethod",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPathType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RuntimeMeshLoader_EPathType, Z_Construct_UPackage__Script_RuntimeMeshLoader(), TEXT("EPathType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPathType(EPathType_StaticEnum, TEXT("/Script/RuntimeMeshLoader"), TEXT("EPathType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RuntimeMeshLoader_EPathType_CRC() { return 1323336765U; }
	UEnum* Z_Construct_UEnum_RuntimeMeshLoader_EPathType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeMeshLoader();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPathType"), 0, Get_Z_Construct_UEnum_RuntimeMeshLoader_EPathType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPathType::Absolute", (int64)EPathType::Absolute },
				{ "EPathType::ProjectRelative", (int64)EPathType::ProjectRelative },
				{ "EPathType::ContentRelative", (int64)EPathType::ContentRelative },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RuntimeMeshLoader,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EPathType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EPathType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FRuntimeMeshLoaderResult::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RUNTIMEMESHLOADER_API uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult, Z_Construct_UPackage__Script_RuntimeMeshLoader(), TEXT("RuntimeMeshLoaderResult"), sizeof(FRuntimeMeshLoaderResult), Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRuntimeMeshLoaderResult(FRuntimeMeshLoaderResult::StaticStruct, TEXT("/Script/RuntimeMeshLoader"), TEXT("RuntimeMeshLoaderResult"), false, nullptr, nullptr);
static struct FScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderResult
{
	FScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderResult()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RuntimeMeshLoaderResult")),new UScriptStruct::TCppStructOps<FRuntimeMeshLoaderResult>);
	}
} ScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderResult;
	UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeMeshLoader();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RuntimeMeshLoaderResult"), sizeof(FRuntimeMeshLoaderResult), Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRuntimeMeshLoaderResult>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_meshInfos_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderResult" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_meshInfos = { UE4CodeGen_Private::EPropertyClass::Array, "meshInfos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderResult, meshInfos), METADATA_PARAMS(NewProp_meshInfos_MetaData, ARRAY_COUNT(NewProp_meshInfos_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_meshInfos_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "meshInfos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderResult" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			auto NewProp_bSuccess_SetBit = [](void* Obj){ ((FRuntimeMeshLoaderResult*)Obj)->bSuccess = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuccess = { UE4CodeGen_Private::EPropertyClass::Bool, "bSuccess", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FRuntimeMeshLoaderResult), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bSuccess_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bSuccess_MetaData, ARRAY_COUNT(NewProp_bSuccess_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_meshInfos,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_meshInfos_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bSuccess,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_RuntimeMeshLoader,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"RuntimeMeshLoaderResult",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FRuntimeMeshLoaderResult),
				alignof(FRuntimeMeshLoaderResult),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult_CRC() { return 2068852644U; }
class UScriptStruct* FRuntimeMeshLoaderMeshInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RUNTIMEMESHLOADER_API uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo, Z_Construct_UPackage__Script_RuntimeMeshLoader(), TEXT("RuntimeMeshLoaderMeshInfo"), sizeof(FRuntimeMeshLoaderMeshInfo), Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRuntimeMeshLoaderMeshInfo(FRuntimeMeshLoaderMeshInfo::StaticStruct, TEXT("/Script/RuntimeMeshLoader"), TEXT("RuntimeMeshLoaderMeshInfo"), false, nullptr, nullptr);
static struct FScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderMeshInfo
{
	FScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderMeshInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RuntimeMeshLoaderMeshInfo")),new UScriptStruct::TCppStructOps<FRuntimeMeshLoaderMeshInfo>);
	}
} ScriptStruct_RuntimeMeshLoader_StaticRegisterNativesFRuntimeMeshLoaderMeshInfo;
	UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_RuntimeMeshLoader();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RuntimeMeshLoaderMeshInfo"), sizeof(FRuntimeMeshLoaderMeshInfo), Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRuntimeMeshLoaderMeshInfo>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_relativeTransform_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_relativeTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "relativeTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, relativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(NewProp_relativeTransform_MetaData, ARRAY_COUNT(NewProp_relativeTransform_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_tangents_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_tangents = { UE4CodeGen_Private::EPropertyClass::Array, "tangents", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, tangents), METADATA_PARAMS(NewProp_tangents_MetaData, ARRAY_COUNT(NewProp_tangents_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_tangents_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "tangents", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_vertexColors_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_vertexColors = { UE4CodeGen_Private::EPropertyClass::Array, "vertexColors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, vertexColors), METADATA_PARAMS(NewProp_vertexColors_MetaData, ARRAY_COUNT(NewProp_vertexColors_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_vertexColors_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "vertexColors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_uv0_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_uv0 = { UE4CodeGen_Private::EPropertyClass::Array, "uv0", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, uv0), METADATA_PARAMS(NewProp_uv0_MetaData, ARRAY_COUNT(NewProp_uv0_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_uv0_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "uv0", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_normals_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_normals = { UE4CodeGen_Private::EPropertyClass::Array, "normals", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, normals), METADATA_PARAMS(NewProp_normals_MetaData, ARRAY_COUNT(NewProp_normals_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_normals_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "normals", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_triangles_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_triangles = { UE4CodeGen_Private::EPropertyClass::Array, "triangles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, triangles), METADATA_PARAMS(NewProp_triangles_MetaData, ARRAY_COUNT(NewProp_triangles_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_triangles_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "triangles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_vertices_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_vertices = { UE4CodeGen_Private::EPropertyClass::Array, "vertices", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, vertices), METADATA_PARAMS(NewProp_vertices_MetaData, ARRAY_COUNT(NewProp_vertices_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_vertices_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "vertices", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_materialIndex_MetaData[] = {
				{ "Category", "RuntimeMeshLoaderMeshInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "Index of the material that is applied to this section of the mesh.\nWill be -1 when all sections get combined." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_materialIndex = { UE4CodeGen_Private::EPropertyClass::Int, "materialIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRuntimeMeshLoaderMeshInfo, materialIndex), METADATA_PARAMS(NewProp_materialIndex_MetaData, ARRAY_COUNT(NewProp_materialIndex_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_relativeTransform,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_tangents,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_tangents_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_vertexColors,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_vertexColors_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_uv0,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_uv0_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_normals,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_normals_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_triangles,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_triangles_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_vertices,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_vertices_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_materialIndex,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_RuntimeMeshLoader,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"RuntimeMeshLoaderMeshInfo",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FRuntimeMeshLoaderMeshInfo),
				alignof(FRuntimeMeshLoaderMeshInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo_CRC() { return 2570459657U; }
	void URuntimeMeshLoaderLibrary::StaticRegisterNativesURuntimeMeshLoaderLibrary()
	{
		UClass* Class = URuntimeMeshLoaderLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIsExtensionSupported", &URuntimeMeshLoaderLibrary::execGetIsExtensionSupported },
			{ "GetSupportedExtensions", &URuntimeMeshLoaderLibrary::execGetSupportedExtensions },
			{ "LoadMesh", &URuntimeMeshLoaderLibrary::execLoadMesh },
			{ "LoadMesh_Async", &URuntimeMeshLoaderLibrary::execLoadMesh_Async },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetIsExtensionSupported()
	{
		struct RuntimeMeshLoaderLibrary_eventGetIsExtensionSupported_Parms
		{
			FString extension;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RuntimeMeshLoaderLibrary_eventGetIsExtensionSupported_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RuntimeMeshLoaderLibrary_eventGetIsExtensionSupported_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_extension_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_extension = { UE4CodeGen_Private::EPropertyClass::Str, "extension", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventGetIsExtensionSupported_Parms, extension), METADATA_PARAMS(NewProp_extension_MetaData, ARRAY_COUNT(NewProp_extension_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_extension,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RuntimeMeshLoader" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "returns whether a file extension is supported by Assimp library.\nThe extension must include the '.', e.g.: \".fbx\"\n\n@param extension   Extension with dot, e.g.: \".fbx\"" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeMeshLoaderLibrary, "GetIsExtensionSupported", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(RuntimeMeshLoaderLibrary_eventGetIsExtensionSupported_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetSupportedExtensions()
	{
		struct RuntimeMeshLoaderLibrary_eventGetSupportedExtensions_Parms
		{
			FString extensions;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_extensions = { UE4CodeGen_Private::EPropertyClass::Str, "extensions", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventGetSupportedExtensions_Parms, extensions), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_extensions,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RuntimeMeshLoader" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "returns the supported extensions of Assimp library" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeMeshLoaderLibrary, "GetSupportedExtensions", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(RuntimeMeshLoaderLibrary_eventGetSupportedExtensions_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh()
	{
		struct RuntimeMeshLoaderLibrary_eventLoadMesh_Parms
		{
			FString filepath;
			FTransform transform;
			FRuntimeMeshLoaderResult result;
			EPathType pathType;
			EImportMethod importMethod;
			bool bNormalizeMesh;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNormalizeMesh_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			auto NewProp_bNormalizeMesh_SetBit = [](void* Obj){ ((RuntimeMeshLoaderLibrary_eventLoadMesh_Parms*)Obj)->bNormalizeMesh = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNormalizeMesh = { UE4CodeGen_Private::EPropertyClass::Bool, "bNormalizeMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bNormalizeMesh_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bNormalizeMesh_MetaData, ARRAY_COUNT(NewProp_bNormalizeMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_importMethod_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_importMethod = { UE4CodeGen_Private::EPropertyClass::Enum, "importMethod", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms, importMethod), Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod, METADATA_PARAMS(NewProp_importMethod_MetaData, ARRAY_COUNT(NewProp_importMethod_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_importMethod_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pathType_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_pathType = { UE4CodeGen_Private::EPropertyClass::Enum, "pathType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms, pathType), Z_Construct_UEnum_RuntimeMeshLoader_EPathType, METADATA_PARAMS(NewProp_pathType_MetaData, ARRAY_COUNT(NewProp_pathType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_pathType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_result = { UE4CodeGen_Private::EPropertyClass::Struct, "result", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms, result), Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_transform = { UE4CodeGen_Private::EPropertyClass::Struct, "transform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(NewProp_transform_MetaData, ARRAY_COUNT(NewProp_transform_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_filepath_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_filepath = { UE4CodeGen_Private::EPropertyClass::Str, "filepath", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms, filepath), METADATA_PARAMS(NewProp_filepath_MetaData, ARRAY_COUNT(NewProp_filepath_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bNormalizeMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_importMethod,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_importMethod_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pathType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pathType_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_result,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_transform,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_filepath,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RuntimeMeshLoader" },
				{ "CPP_Default_bNormalizeMesh", "false" },
				{ "CPP_Default_importMethod", "CombineSectionsSameMaterial" },
				{ "CPP_Default_pathType", "Absolute" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "Load (import) a mesh from various scene description files like fbx, gltf, obj, ... . Supported formats\nare all formats that can be imported by the Assimp library.\n\n@param filePath                 Depending on 'pathType'\n@param pathType                 Choose of the 'filePath' provided is absolut or relative\n@param importMethod             Choose if multiple mesh sections should get combined\n@param transform                A transform that is applied to the imported mesh\n@param bNormalizeMesh   When checked, the object is transformed to fit into a 100cm cube, vertices placed around the center." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeMeshLoaderLibrary, "LoadMesh", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(RuntimeMeshLoaderLibrary_eventLoadMesh_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh_Async()
	{
		struct RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms
		{
			UObject* worldContextObject;
			FLatentActionInfo latentInfo;
			FString filepath;
			FTransform transform;
			FRuntimeMeshLoaderResult result;
			EPathType pathType;
			EImportMethod importMethod;
			bool bNormalizeMesh;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNormalizeMesh_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			auto NewProp_bNormalizeMesh_SetBit = [](void* Obj){ ((RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms*)Obj)->bNormalizeMesh = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNormalizeMesh = { UE4CodeGen_Private::EPropertyClass::Bool, "bNormalizeMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bNormalizeMesh_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bNormalizeMesh_MetaData, ARRAY_COUNT(NewProp_bNormalizeMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_importMethod_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_importMethod = { UE4CodeGen_Private::EPropertyClass::Enum, "importMethod", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, importMethod), Z_Construct_UEnum_RuntimeMeshLoader_EImportMethod, METADATA_PARAMS(NewProp_importMethod_MetaData, ARRAY_COUNT(NewProp_importMethod_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_importMethod_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pathType_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_pathType = { UE4CodeGen_Private::EPropertyClass::Enum, "pathType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, pathType), Z_Construct_UEnum_RuntimeMeshLoader_EPathType, METADATA_PARAMS(NewProp_pathType_MetaData, ARRAY_COUNT(NewProp_pathType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_pathType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_result = { UE4CodeGen_Private::EPropertyClass::Struct, "result", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, result), Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_transform = { UE4CodeGen_Private::EPropertyClass::Struct, "transform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(NewProp_transform_MetaData, ARRAY_COUNT(NewProp_transform_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_filepath_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_filepath = { UE4CodeGen_Private::EPropertyClass::Str, "filepath", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, filepath), METADATA_PARAMS(NewProp_filepath_MetaData, ARRAY_COUNT(NewProp_filepath_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_latentInfo = { UE4CodeGen_Private::EPropertyClass::Struct, "latentInfo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, latentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_worldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "worldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms, worldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bNormalizeMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_importMethod,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_importMethod_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pathType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pathType_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_result,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_transform,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_filepath,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_latentInfo,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_worldContextObject,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RuntimeMeshLoader" },
				{ "CPP_Default_bNormalizeMesh", "false" },
				{ "CPP_Default_importMethod", "CombineSectionsSameMaterial" },
				{ "CPP_Default_pathType", "Absolute" },
				{ "Latent", "" },
				{ "LatentInfo", "LatentInfo" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "Load (import) a mesh from various scene description files like fbx, gltf, obj, ... . Supported formats\nare all formats that can be imported by the Assimp library.\n\n @param worldContext            World context.\n@param filePath                 Depending on 'pathType'\n@param pathType                 Choose of the 'filePath' provided is absolut or relative\n@param importMethod             Choose if multiple mesh sections should get combined\n@param transform                A transform that is applied to the imported mesh\n     @param bNormalizeMesh   When checked, the object is transformed to fit into a 100cm cube, vertices placed around the center." },
				{ "WorldContext", "WorldContextObject" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeMeshLoaderLibrary, "LoadMesh_Async", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(RuntimeMeshLoaderLibrary_eventLoadMesh_Async_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary_NoRegister()
	{
		return URuntimeMeshLoaderLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_RuntimeMeshLoader,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetIsExtensionSupported, "GetIsExtensionSupported" }, // 2080202550
				{ &Z_Construct_UFunction_URuntimeMeshLoaderLibrary_GetSupportedExtensions, "GetSupportedExtensions" }, // 1279992494
				{ &Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh, "LoadMesh" }, // 3061675878
				{ &Z_Construct_UFunction_URuntimeMeshLoaderLibrary_LoadMesh_Async, "LoadMesh_Async" }, // 3557235028
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RuntimeMeshLoaderLibrary.h" },
				{ "ModuleRelativePath", "Public/RuntimeMeshLoaderLibrary.h" },
				{ "ToolTip", "Library to import meshes from disk at runtime using Assimp library." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URuntimeMeshLoaderLibrary>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URuntimeMeshLoaderLibrary::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URuntimeMeshLoaderLibrary, 1967669862);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URuntimeMeshLoaderLibrary(Z_Construct_UClass_URuntimeMeshLoaderLibrary, &URuntimeMeshLoaderLibrary::StaticClass, TEXT("/Script/RuntimeMeshLoader"), TEXT("URuntimeMeshLoaderLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URuntimeMeshLoaderLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
