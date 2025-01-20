// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_MovementFloor.generated.h"

UCLASS()
class NBC_PROJECT06_API ANBC_MovementFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBC_MovementFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GoForward();
	void GoBack();
	void GoUp();
	void GoDown();

protected:
	UPROPERTY(VisibleDefaultsOnly)
	class UStaticMeshComponent* Mesh;

	FTimerHandle TimerHandle;

	FVector OriginLoc;
	FVector CurrentLoc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta=(ClampMin = "0.0", UIMin = "0.0"))
	float LimitRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool isGoBack;

	bool isTrigger;
};
