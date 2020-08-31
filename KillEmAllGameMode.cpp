// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "ShooterAiController.h"
#include "Pickup.h"
#include "GameFramework/Controller.h"



void AKillEmAllGameMode::BeginPlay()
{
    Super::BeginPlay();
     GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning")); 


    FTransform SpawnLocation;

    SpawnedActor = GetWorld()->SpawnActor<APickup>(APickup::StaticClass(), SpawnLocation);      

     FTimerHandle Timer; 
    GetWorldTimerManager().SetTimer(Timer, this, &AKillEmAllGameMode::DestroyActorFunction, 10);    
}


void AKillEmAllGameMode::DestroyActorFunction() 
{ 
  if (SpawnedActor != nullptr) 
  { 
    // Displays a red message on the screen for 10 seconds
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,  TEXT("Actor Destroyed")); 
    SpawnedActor->Destroy(); 
  } 
} 

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

    if(PlayerController != nullptr)
    {
       

          EndGame(false);
    }

    for (AShooterAiController* Controller : TActorRange<AShooterAiController>(GetWorld()))
    {
        if(!Controller->IsDead())
        {
            return;
        }
      
    }
      EndGame(true);
}

    


void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner) 

{
for (AController* Controller : TActorRange<AController>(GetWorld()))
{
    bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
    Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
   
}
}


   

