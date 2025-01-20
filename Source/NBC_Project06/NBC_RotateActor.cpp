// Fill out your copyright notice in the Description page of Project Settings.


#include "NBC_RotateActor.h"

// Sets default values
ANBC_RotateActor::ANBC_RotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ANBC_RotateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANBC_RotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator CurrentRot = GetActorRotation();
	FQuat CurrentQuat = FQuat(CurrentRot);
	
	FQuat YawQuat = FQuat::Identity;
	FQuat PitchQuat = FQuat::Identity;
	FQuat RollQuat = FQuat::Identity;

	if (isYaw)
	{
		YawQuat = FQuat(FVector(0, 0, 1), FMath::DegreesToRadians(RotationSpeed * DeltaTime));
	}

	if (isPitch)
	{
		PitchQuat = FQuat(FVector(1, 0, 0), FMath::DegreesToRadians(RotationSpeed * DeltaTime));
	}

	if (isRoll)
	{
		RollQuat = FQuat(FVector(0, 1, 0), FMath::DegreesToRadians(RotationSpeed * DeltaTime));
	}

	FQuat CombinedQuat = CurrentQuat * YawQuat * PitchQuat * RollQuat;

	SetActorRotation(CombinedQuat.Rotator());
}

