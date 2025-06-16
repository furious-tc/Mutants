// Fill out your copyright notice in the Description page of Project Settings.


#include "CityBuilderActor.h"
#include "AssetViewUtils.h"
#include "EngineUtils.h"
#include "UGridPlugin.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/StaticMeshActor.h"

// Sets default values
ACityBuilderActor::ACityBuilderActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACityBuilderActor::GetAllObjectsFromDT(UDataTable* SourceDT, TArray<FSceneObject>& OutSceneObjects)
{
	if(!SourceDT)
	{
		UE_LOG(LogUGrid, Error, TEXT("Data table has no valid"))
		return;
	}

	TArray<FSceneObject*> SceneObjects;
	SourceDT->GetAllRows<FSceneObject>("Scene Object", SceneObjects);

	for(const FSceneObject* SceneObject :  SceneObjects)
	{
		OutSceneObjects.Add(*SceneObject);
	}
}

void ACityBuilderActor::GetMeshes(TArray<UStaticMesh*>& OutMeshes)
{
	if(AssetLoadingPolicy == EAssetLoadingPolicy::FromProject)
	{
		LoadAllMeshesFromDirectory(ConvertAbsolutePathToRelative(Paths), OutMeshes);
	}
	else
	{
		LoadMeshesFromLevel(OutMeshes);
	}
}

void ACityBuilderActor::SetMeshName(const FString& Name, AActor* Actor)
{
	if(Actor)
	{
		Actor->SetActorLabel(Name); 
	}
}

void ACityBuilderActor::LoadAllMeshesFromDirectory(const TArray<FString>& InPaths, TArray<UStaticMesh*>& OutMeshes)
{
	TArray<FAssetData> Assets;
	
	if (!ObjectLibrary)
	{
		ObjectLibrary = UObjectLibrary::CreateLibrary(UStaticMesh::StaticClass(), false, GIsEditor);
		ObjectLibrary->AddToRoot();
	}
	
	ObjectLibrary->LoadAssetDataFromPaths(InPaths);
	ObjectLibrary->GetAssetDataList(Assets);

	for(const FAssetData& Asset : Assets)
	{
		OutMeshes.Add(Cast<UStaticMesh>(Asset.GetAsset()));
	}
}

void ACityBuilderActor::LoadMeshesFromLevel(TArray<UStaticMesh*>& OutMeshes)
{
	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		OutMeshes.Add(ActorItr->GetStaticMeshComponent()->GetStaticMesh());
	}
}

TArray<FString> ACityBuilderActor::ConvertAbsolutePathToRelative(const TArray<FDirectoryPath>& Directories)
{
	TArray<FString> Result;
	Result.Reserve(Directories.Num());

	for (const FDirectoryPath& Directory : Directories)
	{
		FString AbsolutPath = Directory.Path;
		FString Path = Directory.Path;
		
		Result.Add(Path.Replace(*FPaths::ProjectContentDir(), TEXT("/Game/")));
	}

	return Result;
}
