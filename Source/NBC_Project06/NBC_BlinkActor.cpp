// Fill out your copyright notice in the Description page of Project Settings.


#include "NBC_BlinkActor.h"

// Sets default values
ANBC_BlinkActor::ANBC_BlinkActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ChangeTime = 5.f;
	isVisible = true;
}

// Called when the game starts or when spawned
void ANBC_BlinkActor::BeginPlay()
{
	Super::BeginPlay();
	
	//게임 시작 시 Visibility 세팅
	if (isVisible)
	{
		Mesh->SetVisibility(true);
		Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		Mesh->SetVisibility(false);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	//n초마다 블럭이 사라졌다 생겼다를 반복
	GetWorld()->GetTimerManager().SetTimer(ChageStateTimerHandle, this, &ANBC_BlinkActor::ChangeState, ChangeTime, true);
}

// Called every frame
void ANBC_BlinkActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANBC_BlinkActor::ChangeState()
{
	if (isVisible)
	{
		Mesh->SetVisibility(false);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		isVisible = false;
	}
	else
	{
		Mesh->SetVisibility(true);
		Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		isVisible = true;
	}
}

