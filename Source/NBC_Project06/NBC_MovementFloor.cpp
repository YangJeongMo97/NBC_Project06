// Fill out your copyright notice in the Description page of Project Settings.


#include "NBC_MovementFloor.h"

// Sets default values
ANBC_MovementFloor::ANBC_MovementFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	isTrigger = false;
	LimitRange = 500.f;
	MovementSpeed = 0.2f;
}

// Called when the game starts or when spawned
void ANBC_MovementFloor::BeginPlay()
{
	Super::BeginPlay();
	
	OriginLoc = GetActorLocation();
}

// Called every frame
void ANBC_MovementFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isGoBack)
	{
		if (!isTrigger) GoForward();
		else GoBack();
	}
	else
	{
		if (!isTrigger) GoUp();
		else GoDown();
	}

	CurrentLoc = GetActorLocation();

	float MovingDistance = FVector::Distance(OriginLoc, CurrentLoc);

	if (MovingDistance <= 0.001f || MovingDistance >= LimitRange)
	{
		isTrigger = !isTrigger;
	}
}

void ANBC_MovementFloor::GoForward()
{
	CurrentLoc = GetActorLocation();
	FVector ForwardDir = GetActorForwardVector();

	SetActorLocation(CurrentLoc + ForwardDir * MovementSpeed);
}

void ANBC_MovementFloor::GoBack()
{
	CurrentLoc = GetActorLocation();
	FVector ForwardDir = GetActorForwardVector();

	SetActorLocation(CurrentLoc - ForwardDir * MovementSpeed);
}

void ANBC_MovementFloor::GoUp()
{
	CurrentLoc = GetActorLocation();
	FVector UpDir = GetActorUpVector();

	SetActorLocation(CurrentLoc + UpDir * MovementSpeed);
}

void ANBC_MovementFloor::GoDown()
{
	CurrentLoc = GetActorLocation();
	FVector UpDir = GetActorUpVector();

	SetActorLocation(CurrentLoc - UpDir * MovementSpeed);
}

