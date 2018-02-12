// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05__TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05__TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AS05__TestingGroundsGameMode
{
	GENERATED_BODY()

	AInfiniteTerrainGameMode();
public:
	UFUNCTION(BluePrintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(class ANavMeshBoundsVolume * VolumeToAdd);
	
};
