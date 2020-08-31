// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "InventoryComponent.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"



// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	//GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("Weapon"));
	Gun->SetOwner(this);
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0;
}

float AShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this , &AShooterCharacter::MoveForward);
	
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"),this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"),this, &AShooterCharacter::LookRightRate);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Shoot);
	PlayerInputComponent->BindAction("DropItem",  EInputEvent::IE_Pressed, this, &AShooterCharacter::DropItem);

}

float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) 
{
float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	 DamageToApply= FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

	

	

	if(IsDead())
	{
	
		ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		
		
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
	
	
	DetachFromControllerPendingDestroy();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	}

	return DamageToApply;

}


void AShooterCharacter::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}


void AShooterCharacter::MoveRight(float AxisValue) 
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}


void AShooterCharacter::LookUpRate(float AxisValue) 
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}


void AShooterCharacter::LookRightRate(float AxisValue) 
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::Shoot() 
{
	Gun->PullTrigger();
}

void AShooterCharacter::DropItem() 
{
	  if (MyInventory->CurrentInventory.Num() == 0)
    {
        return;
    }
    AInventoryActor* Item = MyInventory->CurrentInventory.Last();
    MyInventory->RemoveFromInventory(Item);


    FVector ItemOrigin;
    FVector ItemBounds;
    Item->GetActorBounds(false, ItemOrigin, ItemBounds);

    FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());

    Item->PutDown(PutDownLocation);
}

void AShooterCharacter::TakeItem(AInventoryActor* InventoryItem) 
{
	InventoryItem->PickUp();
    MyInventory->AddToInventory(InventoryItem);
}

void AShooterCharacter::NotifyHit(class UPrimitiveComponent* MyComp,
		AActor* Other, class UPrimitiveComponent* OtherComp, 
		bool bSelfMoved, FVector HitLocation, FVector
		HitNormal, FVector NormalImpulse, const FHitResult&
		Hit) 
{
	 AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
    if (InventoryItem != nullptr)
    {
        TakeItem(InventoryItem);
    }
}