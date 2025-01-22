// Fill out your copyright notice in the Description page of Project Settings.


#include "NBC_MovementFloor.h"

// Sets default values
ANBC_MovementFloor::ANBC_MovementFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	isHorizontal = false;
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

	//���� ���� �̵� ����
	if (isHorizontal)
	{
		ForwardOrBack(isArrive, MovementSpeed * DeltaTime);
	}
	else
	{
		//�� �Ʒ� �̵� ����
		UpOrDown(isArrive, MovementSpeed * DeltaTime);
	}

	CurrentLoc = GetActorLocation();

	float MovingDistance = FVector::Distance(OriginLoc, CurrentLoc);

	//�ִ� �̵� �Ÿ� ���� �� Trigger�� ����
	if (MovingDistance >= LimitRange)
	{
		isArrive = !isArrive;
	}
}

void ANBC_MovementFloor::ForwardOrBack(bool inTrigger, float inMovementSpeed)
{
	CurrentLoc = GetActorLocation();
	FVector ForwardDir = GetActorForwardVector();

	if (!inTrigger) SetActorLocation(CurrentLoc + ForwardDir * inMovementSpeed);
	else SetActorLocation(CurrentLoc - ForwardDir * inMovementSpeed);
}

void ANBC_MovementFloor::UpOrDown(bool inTrigger, float inMovementSpeed)
{
	CurrentLoc = GetActorLocation();
	FVector UpDir = GetActorUpVector();

	if(!inTrigger) SetActorLocation(CurrentLoc + UpDir * inMovementSpeed);
	else SetActorLocation(CurrentLoc - UpDir * inMovementSpeed);
}

