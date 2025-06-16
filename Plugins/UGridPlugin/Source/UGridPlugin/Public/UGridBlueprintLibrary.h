// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UGridPluginSettings.h"
#include "UObject/Object.h"
#include "UGridBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UGRIDPLUGIN_API UUGridBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Blueprint Utills")
	static UMaterialInterface* GetBaseMaterial() { return GetMutableDefault<UUGridPluginSettings>()->BaseMaterial.Get(); }
};
