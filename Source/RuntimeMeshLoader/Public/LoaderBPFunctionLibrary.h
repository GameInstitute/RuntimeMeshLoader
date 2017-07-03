// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProceduralMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LoaderBPFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EPathType : uint8
{
	Absolute,
	Relative
};


USTRUCT(BlueprintType)
struct FMeshInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Vertices;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<int32> Triangles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Normals;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector2D> UV0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FLinearColor> VertexColors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FProcMeshTangent> Tangents;
};

USTRUCT(BlueprintType)
struct FReturnedData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		bool bSuccess;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FMeshInfo meshInfo;
};




/**
 * 
 */
UCLASS()
class RUNTIMEMESHLOADER_API ULoaderBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable,Category="MeshLoader")
	static FReturnedData LoadMesh(FString filepath,EPathType type= EPathType:: Absolute);

	
};
