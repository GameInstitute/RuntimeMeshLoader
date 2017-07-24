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
	result.meshInfo.Empty();
	result.NumMeshes = 0;
	//bEnableCollision:: StaticMeshSection
	//result.meshInfo.Vertices.Empty();
	//result.meshInfo.Triangles.Empty();
	//result.meshInfo.Normals.Empty();
	//result.meshInfo.UV0.Empty();
	//result.meshInfo.VertexColors.Empty();
	//result.meshInfo.Tangents.Empty();

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
		result.meshInfo.SetNum(mScenePtr->mNumMeshes,false);

		for (uint32 i = 0; i < mScenePtr->mNumMeshes; ++i)
		{
			//deal with the relative tranformation,it is broken now.
			for (uint32 m=0;m<mScenePtr->mRootNode->mNumChildren;++m)
			{
				aiMatrix4x4 tempTrans=mScenePtr->mRootNode->mChildren[m]->mTransformation;
				FMatrix tempMatrix;
				tempMatrix.M[0][0] = tempTrans.a1; tempMatrix.M[0][1] = tempTrans.b1; tempMatrix.M[0][2] = tempTrans.c1; tempMatrix.M[0][3] = tempTrans.d1;
				tempMatrix.M[1][0] = tempTrans.a2; tempMatrix.M[1][1] = tempTrans.b2; tempMatrix.M[1][2] = tempTrans.c2; tempMatrix.M[1][3] = tempTrans.d2;
				tempMatrix.M[2][0] = tempTrans.a3; tempMatrix.M[2][1] = tempTrans.b3; tempMatrix.M[2][2] = tempTrans.c3; tempMatrix.M[2][3] = tempTrans.d3;
				tempMatrix.M[3][0] = tempTrans.a4; tempMatrix.M[3][1] = tempTrans.b4; tempMatrix.M[3][2] = tempTrans.c4; tempMatrix.M[3][3] = tempTrans.d4;

				result.meshInfo[i].RelativeTransform = FTransform(tempMatrix);
			}



			for (uint32 j = 0; j < mScenePtr->mMeshes[i]->mNumVertices; ++j)
			{

				FVector vertex = FVector(
					mScenePtr->mMeshes[i]->mVertices[j].x, 
					mScenePtr->mMeshes[i]->mVertices[j].y, 
					mScenePtr->mMeshes[i]->mVertices[j].z);
				result.meshInfo[i].Vertices.Push(vertex);

				//法线
				if (mScenePtr->mMeshes[i]->HasNormals())
				{
					FVector normal = FVector(
						mScenePtr->mMeshes[i]->mNormals[j].x,
						mScenePtr->mMeshes[i]->mNormals[j].y,
						mScenePtr->mMeshes[i]->mNormals[j].z);
					result.meshInfo[i].Normals.Push(normal);
				}
				else
				{
					result.meshInfo[i].Normals.Push(FVector::ZeroVector);
				}

				//UV坐标 - 坐标错乱
				if (mScenePtr->mMeshes[i]->HasTextureCoords(0) )
				{

					FVector2D uv = FVector2D(mScenePtr->mMeshes[i]->mTextureCoords[0][j].x, -mScenePtr->mMeshes[i]->mTextureCoords[0][j].y);
					result.meshInfo[i].UV0.Add(uv);
				}

				//切线
				if (mScenePtr->mMeshes[i]->HasTangentsAndBitangents())
				{
					FProcMeshTangent meshTangent = FProcMeshTangent(
						mScenePtr->mMeshes[i]->mTangents[j].x,
						mScenePtr->mMeshes[i]->mTangents[j].y,
						mScenePtr->mMeshes[i]->mTangents[j].z
					);
					result.meshInfo[i].Tangents.Push(meshTangent);
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
						result.meshInfo[i].VertexColors.Push(color);
				}
			}
			
			//三角面序号
			for (uint32 l = 0; l < mScenePtr->mMeshes[i]->mNumFaces; ++l)
			{
				for (uint32 m = 0; m < mScenePtr->mMeshes[i]->mFaces[l].mNumIndices; ++m)
				{
					result.meshInfo[i].Triangles.Push(mScenePtr->mMeshes[i]->mFaces[l].mIndices[m]);
				}
			}
		}
		result.bSuccess = true;
	}

	return result;
}