// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FLatentActionInfo;
struct FTransform;
struct FRuntimeMeshLoaderResult;
enum class EPathType : uint8;
enum class EImportMethod : uint8;
#ifdef RUNTIMEMESHLOADER_RuntimeMeshLoaderLibrary_generated_h
#error "RuntimeMeshLoaderLibrary.generated.h already included, missing '#pragma once' in RuntimeMeshLoaderLibrary.h"
#endif
#define RUNTIMEMESHLOADER_RuntimeMeshLoaderLibrary_generated_h

#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_63_GENERATED_BODY \
	friend RUNTIMEMESHLOADER_API class UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderResult(); \
	RUNTIMEMESHLOADER_API static class UScriptStruct* StaticStruct();


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_31_GENERATED_BODY \
	friend RUNTIMEMESHLOADER_API class UScriptStruct* Z_Construct_UScriptStruct_FRuntimeMeshLoaderMeshInfo(); \
	RUNTIMEMESHLOADER_API static class UScriptStruct* StaticStruct();


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetSupportedExtensions) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_extensions); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::GetSupportedExtensions(Z_Param_Out_extensions); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsExtensionSupported) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_extension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URuntimeMeshLoaderLibrary::GetIsExtensionSupported(Z_Param_extension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadMesh_Async) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_worldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_latentInfo); \
		P_GET_PROPERTY(UStrProperty,Z_Param_filepath); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform); \
		P_GET_STRUCT_REF(FRuntimeMeshLoaderResult,Z_Param_Out_result); \
		P_GET_ENUM(EPathType,Z_Param_pathType); \
		P_GET_ENUM(EImportMethod,Z_Param_importMethod); \
		P_GET_UBOOL(Z_Param_bNormalizeMesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::LoadMesh_Async(Z_Param_worldContextObject,Z_Param_latentInfo,Z_Param_filepath,Z_Param_Out_transform,Z_Param_Out_result,EPathType(Z_Param_pathType),EImportMethod(Z_Param_importMethod),Z_Param_bNormalizeMesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadMesh) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_filepath); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform); \
		P_GET_STRUCT_REF(FRuntimeMeshLoaderResult,Z_Param_Out_result); \
		P_GET_ENUM(EPathType,Z_Param_pathType); \
		P_GET_ENUM(EImportMethod,Z_Param_importMethod); \
		P_GET_UBOOL(Z_Param_bNormalizeMesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::LoadMesh(Z_Param_filepath,Z_Param_Out_transform,Z_Param_Out_result,EPathType(Z_Param_pathType),EImportMethod(Z_Param_importMethod),Z_Param_bNormalizeMesh); \
		P_NATIVE_END; \
	}


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetSupportedExtensions) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_extensions); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::GetSupportedExtensions(Z_Param_Out_extensions); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsExtensionSupported) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_extension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URuntimeMeshLoaderLibrary::GetIsExtensionSupported(Z_Param_extension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadMesh_Async) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_worldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_latentInfo); \
		P_GET_PROPERTY(UStrProperty,Z_Param_filepath); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform); \
		P_GET_STRUCT_REF(FRuntimeMeshLoaderResult,Z_Param_Out_result); \
		P_GET_ENUM(EPathType,Z_Param_pathType); \
		P_GET_ENUM(EImportMethod,Z_Param_importMethod); \
		P_GET_UBOOL(Z_Param_bNormalizeMesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::LoadMesh_Async(Z_Param_worldContextObject,Z_Param_latentInfo,Z_Param_filepath,Z_Param_Out_transform,Z_Param_Out_result,EPathType(Z_Param_pathType),EImportMethod(Z_Param_importMethod),Z_Param_bNormalizeMesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadMesh) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_filepath); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform); \
		P_GET_STRUCT_REF(FRuntimeMeshLoaderResult,Z_Param_Out_result); \
		P_GET_ENUM(EPathType,Z_Param_pathType); \
		P_GET_ENUM(EImportMethod,Z_Param_importMethod); \
		P_GET_UBOOL(Z_Param_bNormalizeMesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URuntimeMeshLoaderLibrary::LoadMesh(Z_Param_filepath,Z_Param_Out_transform,Z_Param_Out_result,EPathType(Z_Param_pathType),EImportMethod(Z_Param_importMethod),Z_Param_bNormalizeMesh); \
		P_NATIVE_END; \
	}


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURuntimeMeshLoaderLibrary(); \
	friend RUNTIMEMESHLOADER_API class UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary(); \
public: \
	DECLARE_CLASS(URuntimeMeshLoaderLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RuntimeMeshLoader"), NO_API) \
	DECLARE_SERIALIZER(URuntimeMeshLoaderLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_INCLASS \
private: \
	static void StaticRegisterNativesURuntimeMeshLoaderLibrary(); \
	friend RUNTIMEMESHLOADER_API class UClass* Z_Construct_UClass_URuntimeMeshLoaderLibrary(); \
public: \
	DECLARE_CLASS(URuntimeMeshLoaderLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RuntimeMeshLoader"), NO_API) \
	DECLARE_SERIALIZER(URuntimeMeshLoaderLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URuntimeMeshLoaderLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URuntimeMeshLoaderLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URuntimeMeshLoaderLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URuntimeMeshLoaderLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URuntimeMeshLoaderLibrary(URuntimeMeshLoaderLibrary&&); \
	NO_API URuntimeMeshLoaderLibrary(const URuntimeMeshLoaderLibrary&); \
public:


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URuntimeMeshLoaderLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URuntimeMeshLoaderLibrary(URuntimeMeshLoaderLibrary&&); \
	NO_API URuntimeMeshLoaderLibrary(const URuntimeMeshLoaderLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URuntimeMeshLoaderLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URuntimeMeshLoaderLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URuntimeMeshLoaderLibrary)


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_PRIVATE_PROPERTY_OFFSET
#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_112_PROLOG
#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_PRIVATE_PROPERTY_OFFSET \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_RPC_WRAPPERS \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_INCLASS \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_PRIVATE_PROPERTY_OFFSET \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_INCLASS_NO_PURE_DECLS \
	ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h_115_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ThePaintProject_Plugins_RuntimeMeshLoader_Source_RuntimeMeshLoader_Public_RuntimeMeshLoaderLibrary_h


#define FOREACH_ENUM_EIMPORTMETHOD(op) \
	op(EImportMethod::KeepSections) \
	op(EImportMethod::CombineSectionsSameMaterial) \
	op(EImportMethod::CombineAllSections) 
#define FOREACH_ENUM_EPATHTYPE(op) \
	op(EPathType::Absolute) \
	op(EPathType::ProjectRelative) \
	op(EPathType::ContentRelative) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
