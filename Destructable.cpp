// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "Destructable.h"

// Sets default values
ADestructable::ADestructable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));

	DestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Destrcutible Component"));
	DestructibleComponent->SetupAttachment(RootComponent);
	DestructibleComponent->SetNotifyRigidBodyCollision(true);

	TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Component"));
	TriggerComponent->SetupAttachment(RootComponent);

	IsDestroyed = false;
	IsTriggerEnabled = false;

	MaxHealth = 10.f;

	DefaultDamage = 1.f;
	DefaultImpulse = 1.f;

}

// Called when the game starts or when spawned
void ADestructable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructable::Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	if (!IsDestroyed && OtherComp->ComponentHasTag("Weapon"))
	{		
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, "Hit By: " + OtherComp->GetName());

		CurrentHealth = CurrentHealth - 1.f;
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, "Current Health: " + FString::SanitizeFloat(CurrentHealth));

		if (CurrentHealth <= 0.f)
		{
			Destroy(DefaultDamage, Hit.Location, NormalImpulse, DefaultImpulse);
		}
	}
}

void ADestructable::Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if (!IsDestroyed && IsTriggerEnabled && OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, __FUNCTION__);

		Destroy(DefaultDamage, DestructibleComponent->GetComponentLocation(), OtherActor->GetActorForwardVector(), DefaultImpulse);
	}
}

void ADestructable::Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse) 
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, __FUNCTION__);

	if (!IsDestroyed)
	{
		IsDestroyed = true;

		DestructibleComponent->ApplyDamage(Damage, HitLocation, ImpulseDir, Impulse);
	}
}



