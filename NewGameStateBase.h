// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NewGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API ANewGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	

public: 

ANewGameStateBase();


 UFUNCTION() 
    void SetScore(float NewScore); 

UFUNCTION() 
    float GetScore();

private: 
   
 UPROPERTY() 
    float CurrentScore;

	
};
