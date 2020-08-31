// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Shooter_PlayerController.generated.h"


/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooter_PlayerController : public APlayerController
{
	GENERATED_BODY()
	public:

	virtual void GameHasEnded(class AActor *EndGameFocus = nullptr, bool bIsWinner = false) override;
	

	protected:
	virtual void BeginPlay() override;

	private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;

	FTimerHandle RestartTimer;

	UUserWidget *HUD;
};
