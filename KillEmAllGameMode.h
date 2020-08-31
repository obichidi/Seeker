// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "Pickup.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */



UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()

	public:
	
	virtual void PawnKilled(APawn* PawnKilled) override;

	 virtual void BeginPlay() override;

	  UPROPERTY() 
  	APickup* SpawnedActor; 

    UFUNCTION() 
   void DestroyActorFunction();

   	

	
	private :

	

	void EndGame(bool bIsPlayerWinner);
	
};
