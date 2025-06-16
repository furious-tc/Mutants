// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UGridPluginSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Engine)
class UGRIDPLUGIN_API UUGridPluginSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	TSoftObjectPtr<UMaterialInterface> BaseMaterial;
};
