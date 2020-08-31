// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "triggerBoxdialogue.generated.h"

UCLASS()
class SIMPLESHOOTER_API AtriggerBoxdialogue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AtriggerBoxdialogue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "TriggerDialogue") 
	UBoxComponent* TriggerDialogue; 


	UFUNCTION(BlueprintCallable , Category = "TriggerDialogue") 
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; 

	UFUNCTION(BlueprintCallable , Category = "TriggerDialogue") 
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable , Category = "TriggerDialogue") 
	void  Speak();



	FTimerHandle Talk;
};
