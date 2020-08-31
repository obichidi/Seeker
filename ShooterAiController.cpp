// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAiController.h"
#include "ShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AShooterAiController::BeginPlay() 
{
    Super::BeginPlay();

   if(AIBehavior != nullptr)
   {
       RunBehaviorTree(AIBehavior);

        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

      

       

        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
       
   }


  
}

bool AShooterAiController::IsDead() const
{
     

  AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}


void AShooterAiController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);

     APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (LineOfSightTo(PlayerPawn))
    {
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    }
    else
    {
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    }

   
      
}
