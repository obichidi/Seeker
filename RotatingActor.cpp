// Fill out your copyright notice in the Description page of Project Settings.
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->SetupAttachment(Root);

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();



	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	FQuat QuatRotation = FRotator(PitchValue, YawValue, RollValue).Quaternion();
	
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	

}



