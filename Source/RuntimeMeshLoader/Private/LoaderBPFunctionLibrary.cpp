// Fill out your copyright notice in the Description page of Project Settings.
#include "RuntimeMeshLoader.h"
#include "LoaderBPFunctionLibrary.h"
#include <assimp/Importer.hpp>  // C++ importer interface
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h> // Post processing flags



FReturnedData ULoaderBPFunctionLibrary::LoadMesh(FString filepath, EPathType type)
{
	FReturnedData result;
	result.bSuccess=false;
	//bEnableCollision:: StaticMeshSection
	result.meshInfo.Vertices.Empty();
	result.meshInfo.Triangles.Empty();
	result.meshInfo.Normals.Empty();
	result.meshInfo.UV0.Empty();
	result.meshInfo.VertexColors.Empty();
	result.meshInfo.Tangents.Empty();

	if (filepath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Runtime Mesh Loader: filepath is empty.\n"));
		return result;
	}

	std::string file;
	switch (type)
	{
	case EPathType::Absolute:
		file = TCHAR_TO_UTF8(*filepath);
		break;
	case EPathType::Relative:
		file = TCHAR_TO_UTF8(*FPaths::Combine(FPaths::GameContentDir(), filepath));
		break;
	}

	Assimp::Importer mImporter;

	const aiScene* mScenePtr = mImporter.ReadFile(file, aiProcess_Triangulate| aiProcess_MakeLeftHanded| aiProcess_CalcTangentSpace| aiProcess_GenSmoothNormals| aiProcess_OptimizeMeshes);

	if (mScenePtr==nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Runtime Mesh Loader: Read mesh file failure.\n"));
		return result;
	}

	if (mScenePtr->HasMeshes())
	{
		for (uint32 i = 0; i < mScenePtr->mNumMeshes; ++i)
		{
			for (uint32 j = 0; j < mScenePtr->mMeshes[i]->mNumVertices; ++j)
			{
				FVector vertex = FVector(
					mScenePtr->mMeshes[i]->mVertices[j].x, 
					mScenePtr->mMeshes[i]->mVertices[j].y, 
					mScenePtr->mMeshes[i]->mVertices[j].z);
				result.meshInfo.Vertices.Push(vertex);

				//法线
				if (mScenePtr->mMeshes[i]->HasNormals())
				{
					FVector normal = FVector(
						mScenePtr->mMeshes[i]->mNormals[j].x,
						mScenePtr->mMeshes[i]->mNormals[j].y,
						mScenePtr->mMeshes[i]->mNormals[j].z);
					result.meshInfo.Normals.Push(normal);
				}
				else
				{
					result.meshInfo.Normals.Push(FVector::ZeroVector);
				}

				//UV坐标 - 坐标错乱
				if (mScenePtr->mMeshes[i]->HasTextureCoords(0) )
				{

					FVector2D uv = FVector2D(mScenePtr->mMeshes[i]->mTextureCoords[0][j].x, -mScenePtr->mMeshes[i]->mTextureCoords[0][j].y);
					result.meshInfo.UV0.Add(uv);
				}

				//切线
				if (mScenePtr->mMeshes[i]->HasTangentsAndBitangents())
				{
					FProcMeshTangent meshTangent = FProcMeshTangent(
						mScenePtr->mMeshes[i]->mTangents[j].x,
						mScenePtr->mMeshes[i]->mTangents[j].y,
						mScenePtr->mMeshes[i]->mTangents[j].z
					);
					result.meshInfo.Tangents.Push(meshTangent);
				}

				//顶点颜色
				if (mScenePtr->mMeshes[i]->HasVertexColors(0))
				{
						FLinearColor color = FLinearColor(
							mScenePtr->mMeshes[i]->mColors[0][j].r,
							mScenePtr->mMeshes[i]->mColors[0][j].g,
							mScenePtr->mMeshes[i]->mColors[0][j].b,
							mScenePtr->mMeshes[i]->mColors[0][j].a
							);
						result.meshInfo.VertexColors.Push(color);			
				}
			}
			
			//三角面序号
			for (uint32 l = 0; l < mScenePtr->mMeshes[i]->mNumFaces; ++l)
			{
				for (uint32 m = 0; m < mScenePtr->mMeshes[i]->mFaces[l].mNumIndices; ++m)
				{
					result.meshInfo.Triangles.Push(mScenePtr->mMeshes[i]->mFaces[l].mIndices[m]);
				}
			}
		}
		result.bSuccess = true;
	}

	return result;
}