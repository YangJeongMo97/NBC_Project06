// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_BlinkActor.generated.h"

UCLASS()
class NBC_PROJECT06_API ANBC_BlinkActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBC_BlinkActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeState();

protected:
	UPROPERTY(VisibleDefaultsOnly)
	class UStaticMeshComponent* Mesh;

	FTimerHandle ChageStateTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float ChangeTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool isVisible;
};
