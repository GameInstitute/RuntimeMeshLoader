// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProceduralMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LatentActions.h"
#include "RuntimeMeshLoaderLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRuntimeMeshLoader, Log, All)

UENUM(BlueprintType)
enum class EPathType : uint8
{
    Absolute,
    ProjectRelative,
    ContentRelative,
};

UENUM(BlueprintType)
enum class EImportMethod : uint8
{
    KeepSections,
    CombineSectionsSameMaterial,
    CombineAllSections
};

USTRUCT(BlueprintType)
struct FRuntimeMeshLoaderMeshInfo
{
    GENERATED_BODY()

    // Index of the material that is applied to this section of the mesh.
    // Will be -1 when all sections get combined.
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 materialIndex = INDEX_NONE;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FVector> vertices;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<int32> triangles;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FVector> normals;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FVector2D> uv0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FLinearColor> vertexColors;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FProcMeshTangent> tangents;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTransform relativeTransform;
};

USTRUCT(BlueprintType)
struct FRuntimeMeshLoaderResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bSuccess;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FRuntimeMeshLoaderMeshInfo> meshInfos;
};

class FLoadMeshAsyncAction : public FPendingLatentAction
{
public:
    FName executionFunction;
    int32 outputLink;
    FWeakObjectPtr callbackTarget;
    FString file;

    FLoadMeshAsyncAction(const FLatentActionInfo& LatentInfo, const FString filepath, const FTransform& transform, FRuntimeMeshLoaderResult& result, const EPathType pathType
                         , const EImportMethod importMethod, const bool normalizeMesh);

    virtual void UpdateOperation(FLatentResponse& Response) override
    {
        if (bTaskDone)
        {
            resultRef = MoveTemp(myResult);
            Response.FinishAndTriggerIf(bTaskDone, executionFunction, outputLink, callbackTarget);
        }
    }

#if WITH_EDITOR
    // Returns a human readable description of the latent operation's current state
    virtual FString GetDescription() const override
    {
        return FString::Printf(TEXT("FLoadMeshAsyncAction, loading file: %s"), *file);
    }
#endif

private:
	// Reference to the outer result of the user
    FRuntimeMeshLoaderResult& resultRef;
	// Temporary result during async process
    FRuntimeMeshLoaderResult myResult; 
    bool bTaskDone = false;
};


/**
 * Library to import meshes from disk at runtime using Assimp library.
 */
UCLASS()
class RUNTIMEMESHLOADER_API URuntimeMeshLoaderLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     *	Load (import) a mesh from various scene description files like fbx, gltf, obj, ... . Supported formats
     *	are all formats that can be imported by the Assimp library.
     *
     *	@param filePath			Depending on 'pathType'
     *	@param pathType			Choose of the 'filePath' provided is absolut or relative
     *	@param importMethod		Choose if multiple mesh sections should get combined
     *	@param transform		A transform that is applied to the imported mesh
     *	@param bNormalizeMesh	When checked, the object is transformed to fit into a 100cm cube, vertices placed around the center.
     */
    UFUNCTION(BlueprintCallable, Category = "RuntimeMeshLoader")
    static void LoadMesh(const FString filepath, const FTransform& transform, FRuntimeMeshLoaderResult& result, const EPathType pathType = EPathType::Absolute
                         , const EImportMethod importMethod = EImportMethod::CombineSectionsSameMaterial, const bool bNormalizeMesh = false);

    /**
     *	Load (import) a mesh from various scene description files like fbx, gltf, obj, ... . Supported formats
     *	are all formats that can be imported by the Assimp library.
     *
     *  @param worldContext		World context.
     *	@param filePath			Depending on 'pathType'
     *	@param pathType			Choose of the 'filePath' provided is absolut or relative
     *	@param importMethod		Choose if multiple mesh sections should get combined
     *	@param transform		A transform that is applied to the imported mesh
	 *	@param bNormalizeMesh	When checked, the object is transformed to fit into a 100cm cube, vertices placed around the center.
     */
    UFUNCTION(BlueprintCallable, Category = "RuntimeMeshLoader", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo"))
    static void	LoadMesh_Async(UObject* worldContextObject, FLatentActionInfo latentInfo, const FString filepath, const FTransform& transform
                               , FRuntimeMeshLoaderResult& result, const EPathType pathType = EPathType::Absolute
                               , const EImportMethod importMethod = EImportMethod::CombineSectionsSameMaterial, const bool bNormalizeMesh = false);

    /**
     *	returns whether a file extension is supported by Assimp library.
     *	The extension must include the '.', e.g.: ".fbx"
     *
     *	@param extension   Extension with dot, e.g.: ".fbx"
     */
    UFUNCTION(BlueprintCallable, Category = "RuntimeMeshLoader")
    static bool GetIsExtensionSupported(const FString extension);

    /**
     *	returns the supported extensions of Assimp library
     */
    UFUNCTION(BlueprintCallable, Category = "RuntimeMeshLoader")
    static void GetSupportedExtensions(FString& extensions);
};
