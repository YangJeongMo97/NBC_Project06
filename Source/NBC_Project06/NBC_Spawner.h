// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_Spawner.generated.h"

UCLASS()
class NBC_PROJECT06_API ANBC_Spawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBC_Spawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<class ANBC_RotateActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "50.0", UIMin = "0.0", UIMax = "50.0"))
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "10000", UIMin = "0.0", UIMax = "10000.0"))
	float SpawnXRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "10000", UIMin = "0.0", UIMax = "10000.0"))
	float SpawnYRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "10000", UIMin = "0.0", UIMax = "10000.0"))
	float SpawnZRange;

public:
	void SpawnActor();
};
