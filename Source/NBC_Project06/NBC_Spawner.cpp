// Fill out your copyright notice in the Description page of Project Settings.


#include "NBC_Spawner.h"
#include "NBC_RotateActor.h"

// Sets default values
ANBC_Spawner::ANBC_Spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>("SceneRoot");
	RootComponent = SceneRoot;

	Count = 1;
	SpawnXRange = 100;
	SpawnYRange = 100;
	SpawnZRange = 20;
}

// Called when the game starts or when spawned
void ANBC_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < Count; ++i)
	{
		SpawnActor();
	}
}

// Called every frame
void ANBC_Spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANBC_Spawner::SpawnActor()
{
	if (ActorToSpawn)
	{
		FVector OriginLoc = GetActorLocation();
		FVector RandomLocation = FVector(
			OriginLoc.X + FMath::RandRange(-SpawnXRange, SpawnXRange),
			OriginLoc.Y + FMath::RandRange(-SpawnYRange, SpawnYRange),
			OriginLoc.Z + FMath::RandRange(-SpawnZRange, SpawnZRange)
		);

		FRotator RandomRotation = FRotator(
			FMath::RandRange(0.0f, 360.0f),
			FMath::RandRange(0.0f, 360.0f),
			FMath::RandRange(0.0f, 360.0f)
		);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ANBC_RotateActor* SpawnedActor = GetWorld()->SpawnActor<ANBC_RotateActor>(ActorToSpawn, RandomLocation, RandomRotation, SpawnParams);

		if (SpawnedActor)
		{
			SpawnedActor->SetRotationSpeed(FMath::RandRange(0.f, 360.f));
			SpawnedActor->SetYawRotate(FMath::RandBool());
			SpawnedActor->SetPitchRotate(FMath::RandBool());
			SpawnedActor->SetRollRotate(FMath::RandBool());
		}
	}
}

