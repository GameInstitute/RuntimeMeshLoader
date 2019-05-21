//// Fill out your copyright notice in the Description page of Project Settings.
#include "RuntimeMeshLoaderLibrary.h"
#include "RuntimeMeshLoader.h"
#include "Engine/LatentActionManager.h"
#include <assimp/Importer.hpp>  // C++ importer interface
#include <assimp/IOSystem.hpp>
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags

DEFINE_LOG_CATEGORY(LogRuntimeMeshLoader);

FTransform aiTransformToFTransform(const aiMatrix4x4& transform)
{
    FMatrix tempMatrix;
    tempMatrix.M[0][0] = transform.a1;
    tempMatrix.M[0][1] = transform.b1;
    tempMatrix.M[0][2] = transform.c1;
    tempMatrix.M[0][3] = transform.d1;
    tempMatrix.M[1][0] = transform.a2;
    tempMatrix.M[1][1] = transform.b2;
    tempMatrix.M[1][2] = transform.c2;
    tempMatrix.M[1][3] = transform.d2;
    tempMatrix.M[2][0] = transform.a3;
    tempMatrix.M[2][1] = transform.b3;
    tempMatrix.M[2][2] = transform.c3;
    tempMatrix.M[2][3] = transform.d3;
    tempMatrix.M[3][0] = transform.a4;
    tempMatrix.M[3][1] = transform.b4;
    tempMatrix.M[3][2] = transform.c4;
    tempMatrix.M[3][3] = transform.d4;
    return FTransform(tempMatrix);
}

void FindMeshInfo(const aiScene* scene, aiNode* node, FRuntimeMeshLoaderResult& result, const FTransform *const composedParentTransform)
{
    for (uint32 nodeMeshIndex = 0; nodeMeshIndex < node->mNumMeshes; nodeMeshIndex++)
    {
        std::string TestString = node->mName.C_Str();
        FString Fs = FString(TestString.c_str());
        UE_LOG(LogRuntimeMeshLoader, Warning, TEXT("FindMeshInfo. %s\n"), *Fs);

        int sceneMeshIndex = node->mMeshes[nodeMeshIndex];
        aiMesh *mesh = scene->mMeshes[sceneMeshIndex];
        FRuntimeMeshLoaderMeshInfo &meshInfoRef = result.meshInfos[sceneMeshIndex];

        //transform
        meshInfoRef.relativeTransform = aiTransformToFTransform(node->mTransformation);

        FTransform sceneTransform = meshInfoRef.relativeTransform;
        if (composedParentTransform)
        {
            sceneTransform = sceneTransform * (*composedParentTransform);
        }

        meshInfoRef.materialIndex = mesh->mMaterialIndex;

        //vet
        for (uint32  vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex)
        {
            FVector vertex = FVector(
                                 mesh->mVertices[vertexIndex].x,
                                 mesh->mVertices[vertexIndex].y,
                                 mesh->mVertices[vertexIndex].z);

            vertex = sceneTransform.TransformPosition(vertex);
            meshInfoRef.vertices.Push(vertex);

            //Normal
            if (mesh->HasNormals())
            {
                FVector normal = FVector(
                                     mesh->mNormals[vertexIndex].x,
                                     mesh->mNormals[vertexIndex].y,
                                     mesh->mNormals[vertexIndex].z);

                normal = sceneTransform.TransformVectorNoScale(normal);
                meshInfoRef.normals.Push(normal);
            }
            else
            {
                meshInfoRef.normals.Push(FVector::ZeroVector);
            }

            //UV Coordinates - inconsistent coordinates
            if (mesh->HasTextureCoords(0))
            {
                FVector2D uv = FVector2D(mesh->mTextureCoords[0][vertexIndex].x, -mesh->mTextureCoords[0][vertexIndex].y);
                meshInfoRef.uv0.Add(uv);
            }

            //Tangent
            if (mesh->HasTangentsAndBitangents())
            {
                FProcMeshTangent meshTangent = FProcMeshTangent(
                                                   mesh->mTangents[vertexIndex].x,
                                                   mesh->mTangents[vertexIndex].y,
                                                   mesh->mTangents[vertexIndex].z
                                               );
                meshTangent.TangentX = sceneTransform.TransformVectorNoScale(meshTangent.TangentX);
                meshInfoRef.tangents.Push(meshTangent);
            }

            //Vertex color
            if (mesh->HasVertexColors(0))
            {
                FLinearColor color = FLinearColor(
                                         mesh->mColors[0][vertexIndex].r,
                                         mesh->mColors[0][vertexIndex].g,
                                         mesh->mColors[0][vertexIndex].b,
                                         mesh->mColors[0][vertexIndex].a
                                     );
                meshInfoRef.vertexColors.Push(color);
            }

        }

        //Triangle number
        const int32 numFaces = mesh->mNumFaces;
        for (int32 faceIndex = 0; faceIndex < numFaces; ++faceIndex)
        {
            const int32 numIndices = mesh->mFaces[faceIndex].mNumIndices;
            for (int32 indicesIndex = 0; indicesIndex < numIndices; ++indicesIndex)
            {
                meshInfoRef.triangles.Push(mesh->mFaces[faceIndex].mIndices[indicesIndex]);
            }
        }
    }
}


void FindMesh(const aiScene* scene, aiNode* node, FRuntimeMeshLoaderResult& retdata, const FTransform *const composedParentTransform)
{
    FindMeshInfo(scene, node, retdata, composedParentTransform);

    FTransform* transform = new FTransform(aiTransformToFTransform(node->mTransformation));
    if (composedParentTransform)
    {
        *transform = (*transform) * (*composedParentTransform);
    }

    for (uint32 m = 0; m < node->mNumChildren; ++m)
    {
        FindMesh(scene, node->mChildren[m], retdata, transform);
    }

    if (transform)
    {
        delete transform;
    }
}

void OffsetTriangleArray(int32 offset, TArray<int32>& triangles)
{
    for (int32& index : triangles)
    {
        index += offset;
    }
}

// Append meshInfo2 to MeshInfo1
void AppendMeshInfo(FRuntimeMeshLoaderMeshInfo& meshInfo1, FRuntimeMeshLoaderMeshInfo meshInfo2)
{
    OffsetTriangleArray(meshInfo1.vertices.Num(), meshInfo2.triangles);
    meshInfo1.vertices.Append(meshInfo2.vertices);
    meshInfo1.normals.Append(meshInfo2.normals);
    meshInfo1.tangents.Append(meshInfo2.tangents);
    meshInfo1.vertexColors.Append(meshInfo2.vertexColors);
    meshInfo1.uv0.Append(meshInfo2.uv0);
    meshInfo1.triangles.Append(meshInfo2.triangles);

    meshInfo1.materialIndex = meshInfo1.materialIndex == meshInfo2.materialIndex ? meshInfo1.materialIndex : INDEX_NONE;
}

void URuntimeMeshLoaderLibrary::LoadMesh(const FString filepath, const FTransform& transform, FRuntimeMeshLoaderResult& result, const EPathType pathType, const EImportMethod importMethod, const bool bNormalizeMesh)
{
    result.bSuccess = false;
    result.meshInfos.Empty();
    //bEnableCollision:: StaticMeshSection
    //result.meshInfo.Vertices.Empty();
    //result.meshInfo.Triangles.Empty();
    //result.meshInfo.Normals.Empty();
    //result.meshInfo.UV0.Empty();
    //result.meshInfo.VertexColors.Empty();
    //result.meshInfo.Tangents.Empty();

    if (filepath.IsEmpty())
    {
        UE_LOG(LogRuntimeMeshLoader, Warning, TEXT("Runtime Mesh Loader: filepath is empty.\n"));
        return;
    }

    std::string file;
    switch (pathType)
    {
    case EPathType::Absolute:
        file = TCHAR_TO_UTF8(*filepath);
        break;
    case EPathType::ProjectRelative:
        file = TCHAR_TO_UTF8(*FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), filepath));
        break;
    case EPathType::ContentRelative:
        file = TCHAR_TO_UTF8(*FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()), filepath));
        break;
    }

    Assimp::Importer mImporter;

    const aiScene* mScenePtr = mImporter.ReadFile(file, aiProcess_Triangulate | aiProcess_MakeLeftHanded | aiProcess_CalcTangentSpace | aiProcess_GenSmoothNormals | aiProcess_OptimizeMeshes);
	FString importError = FString(mImporter.GetErrorString());
	if (importError.Len()>0)
	{
		UE_LOG(LogRuntimeMeshLoader, Error, TEXT("RuntimeMeshLoader ImportError: %s \n"), *importError);
	}

    if (mScenePtr == nullptr)
    {
        UE_LOG(LogRuntimeMeshLoader, Error, TEXT("RuntimeMeshLoader: Read mesh file failure. File absolute: %s \n"), UTF8_TO_TCHAR(file.c_str()));
        return;
    }

    if (mScenePtr->HasMeshes())
    {
        result.meshInfos.SetNum(mScenePtr->mNumMeshes, false);

        FindMesh(mScenePtr, mScenePtr->mRootNode, result, &transform);

        if (importMethod == EImportMethod::KeepSections)
        {
            // do nothing
        }
        else if (importMethod == EImportMethod::CombineAllSections)
        {
            for (int32 i = 1; i < result.meshInfos.Num(); ++i)
            {
                AppendMeshInfo(result.meshInfos[0], result.meshInfos[i]);
            }
            result.meshInfos.SetNum(1);
        }
        else if (importMethod == EImportMethod::CombineSectionsSameMaterial)
        {
            TMap<int32, FRuntimeMeshLoaderMeshInfo> map_MatIndex_Mesh;
            for (int32 i = result.meshInfos.Num() - 1; i>=0; --i)
            {
                FRuntimeMeshLoaderMeshInfo& meshInfoRef = map_MatIndex_Mesh.FindOrAdd(result.meshInfos[i].materialIndex);
                if (meshInfoRef.vertices.Num() == 0)
                {
                    // Key was just added
                    meshInfoRef = MoveTemp(result.meshInfos[i]);
                }
                else
                {
                    // Already existing data on that key
                    AppendMeshInfo(meshInfoRef, result.meshInfos[i]);
                }
            }

            // Copy over the combined meshes from the map into the result
            map_MatIndex_Mesh.GenerateValueArray(result.meshInfos);
        }

		if (bNormalizeMesh)
		{
			// Get the total bounds of all mesh info
			FBox totalBounds;
			for (FRuntimeMeshLoaderMeshInfo& meshInfo : result.meshInfos)
			{
				FBox currentBounds(meshInfo.vertices);
				totalBounds += currentBounds;
			}

			// Use the bounds to transform all vertices
			float scaleFactor = 50.f / totalBounds.GetExtent().GetMax();
			FVector offset = -totalBounds.GetCenter();
			for (FRuntimeMeshLoaderMeshInfo& meshInfo : result.meshInfos)
			{
				for (FVector& vertex : meshInfo.vertices)
				{
					vertex += offset;
					vertex *= scaleFactor;
				}
			}
		}

        result.bSuccess = true;
    }

    return;
}

FLoadMeshAsyncAction::FLoadMeshAsyncAction(const FLatentActionInfo& latentInfo, const FString filepath, const FTransform& transform, FRuntimeMeshLoaderResult& result, const EPathType pathType, const EImportMethod importMethod, const bool normalizeMesh)
    : executionFunction(latentInfo.ExecutionFunction)
    , outputLink(latentInfo.Linkage)
    , callbackTarget(latentInfo.CallbackTarget)
    , file(filepath)
    , resultRef(result)
{
    AsyncTask(ENamedThreads::AnyThread, [=, this]()-> void
    {
        URuntimeMeshLoaderLibrary::LoadMesh(filepath, transform, myResult, pathType, importMethod, normalizeMesh);
        AsyncTask(ENamedThreads::GameThread, [this]() -> void
        {
            bTaskDone = true;
        });
    });
}

void URuntimeMeshLoaderLibrary::LoadMesh_Async(UObject* worldContextObject, FLatentActionInfo latentInfo, const FString filepath, const FTransform& transform, FRuntimeMeshLoaderResult& result, const EPathType pathType /*= EPathType::Absolute */, const EImportMethod importMethod /*= EImportMethod::CombineSectionsSameMaterial*/, const bool normalizeMesh /*= false*/)
{
    if (UWorld* world = GEngine->GetWorldFromContextObject(worldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        FLatentActionManager& latentActionManager = world->GetLatentActionManager();
        if (latentActionManager.FindExistingAction<FLoadMeshAsyncAction>(latentInfo.CallbackTarget, latentInfo.UUID) == NULL)
        {
            latentActionManager.AddNewAction(latentInfo.CallbackTarget, latentInfo.UUID, new FLoadMeshAsyncAction(latentInfo, filepath, transform, result, pathType, importMethod, normalizeMesh));
        }
    }
}

bool URuntimeMeshLoaderLibrary::GetIsExtensionSupported(const FString extension)
{
	Assimp::Importer importer;
	return importer.IsExtensionSupported(TCHAR_TO_ANSI(*extension));
}

void URuntimeMeshLoaderLibrary::GetSupportedExtensions(FString& extensions)
{
	std::string string;
	Assimp::Importer importer;
	importer.GetExtensionList(string);
	extensions = FString(string.c_str());
}
