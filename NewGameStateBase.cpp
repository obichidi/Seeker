// Fill out your copyright notice in the Description page of Project Settings.


#include "NewGameStateBase.h"

ANewGameStateBase::ANewGameStateBase() 
{
    CurrentScore = 0;
}

 float ANewGameStateBase::GetScore() 
{
    return CurrentScore;
  
}

void ANewGameStateBase::SetScore(float NewScore) 
{
     CurrentScore = NewScore;
}

 


