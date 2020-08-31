// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "delegateListener.h"

// Sets default values
AdelegateListener::AdelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}


	

// Called when the game starts or when spawned
void AdelegateListener::BeginPlay()
{
	Super::BeginPlay();


   
}

// Called every frame
void AdelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

