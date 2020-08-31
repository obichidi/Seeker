// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "triggerBoxdialogue.h"

// Sets default values
AtriggerBoxdialogue::AtriggerBoxdialogue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TriggerDialogue = CreateDefaultSubobject<UBoxComponent>("TriggerDialogue");
    
	TriggerDialogue->SetBoxExtent(FVector(200, 200, 100));

}

// Called when the game starts or when spawned
void AtriggerBoxdialogue::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtriggerBoxdialogue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AtriggerBoxdialogue::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	
}

void AtriggerBoxdialogue::NotifyActorEndOverlap(AActor* OtherActor) 
{
	
}

void AtriggerBoxdialogue::Speak() 
{
	
}

