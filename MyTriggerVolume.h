// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "MyTriggerVolume.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMyTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerVolume();

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "EnableTriggerLight") 
	UBoxComponent* TriggerZone; 

	UFUNCTION(BlueprintCallable , Category = "EnableTriggerLight") 
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; 

	UFUNCTION(BlueprintCallable , Category = "EnableTriggerLight") 
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;	

	UFUNCTION(BlueprintCallable , Category = "EnableTriggerLight")
	 void EnableLight(); 

	 UFUNCTION(BlueprintCallable , Category = "EnableTriggerLight")
	 void DisableLight(); 
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "EnableTriggerLight") 
		UPointLightComponent* PointLight; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	public:
    
		FTimerHandle SetLight;

		

};
