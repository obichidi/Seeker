// Fill out your copyright notice in the Description page of Project Settings.
#include "delegateListener.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "MyTriggerVolume.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
    TriggerZone->SetBoxExtent(FVector(200, 200, 100));

    PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
 	
	 RootComponent = PointLight;

	 PointLight->SetVisibility(false);

	 PointLight->SetLightColor(FLinearColor::Blue);

}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();

  
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) 
{ 
    auto Message = FString::Printf(TEXT("%s entered me"), 
                   *(OtherActor->GetName()));

    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message); 

   GetWorldTimerManager().SetTimer(SetLight, this, &AMyTriggerVolume::EnableLight,1 );
   
} 

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor) 
{ 
    auto Message = FString::Printf(TEXT("%s left me"), 
                   *(OtherActor->GetName()));

    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message); 

     GetWorldTimerManager().SetTimer(SetLight, this, &AMyTriggerVolume::DisableLight, 1 );
}

 void AMyTriggerVolume::EnableLight() 
{
    PointLight->SetVisibility(true); 
}

void AMyTriggerVolume::DisableLight() 
{
     PointLight->SetVisibility(false); 
} 