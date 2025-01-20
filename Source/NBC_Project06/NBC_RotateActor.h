// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBC_RotateActor.generated.h"

UCLASS()
class NBC_PROJECT06_API ANBC_RotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBC_RotateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool isYawRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool isPitchRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool isRollRotate;

public:
	FORCEINLINE void SetRotationSpeed(float inValue) { RotationSpeed = inValue; }
	FORCEINLINE void SetYawRotate(bool inValue) { isYawRotate = inValue; }
	FORCEINLINE void SetPitchRotate(bool inValue) { isPitchRotate = inValue; }
	FORCEINLINE void SetRollRotate(bool inValue) { isRollRotate = inValue; }
};
