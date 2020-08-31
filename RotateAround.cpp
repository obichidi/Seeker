// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateAround.h"

// Sets default values
ARotateAround::ARotateAround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Dimensions = FVector (300, 0, 0);
	AxisVector = FVector (0, 0, 1);
	Multiplier = 50.f;

}

// Called when the game starts or when spawned
void ARotateAround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateAround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector (0,0,400);

	// rotate around player
	// FVector NewLocation = GetWorld()->GetShooterAiController()->GetPawn()->GetActorLocation();
	
	AngleAxis += DeltaTime * Multiplier;

	if(AngleAxis >= 360.0f) 
	{
		AngleAxis = 0;
	}

	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	FRotator NewRotation = FRotator(0, AngleAxis, 0);
	
	FQuat QuatRotation = FQuat(NewRotation);

	SetActorLocationAndRotation(NewLocation, QuatRotation, false, 0, ETeleportType::None);


}

