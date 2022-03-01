// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"

#include "DamageableActor.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPSCharacter::FireWeapon()
{
	const FHitResult Hit = Shot();
	ADamageableActor* HitActor = Cast<ADamageableActor>(Hit.Actor);
	if(HitActor && HitActor->IsAttackable)
	{
		HitActor->TakeDamage();
	}
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

FHitResult AFPSCharacter::Shot() const
{
	FVector CameraPos;
	FRotator CameraRot;
	FVector EndTrace = FVector::ZeroVector;

	APlayerController* const PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->GetPlayerViewPoint(CameraPos, CameraRot);
		EndTrace = CameraPos + CameraRot.Vector() * WeaponRange;
	}

	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(Shot), true, GetInstigator());
	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, CameraPos, EndTrace, ECC_Visibility);

	return Hit;
}

// Public methods

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AFPSCharacter::GetMovementSpeed() const
{
	return this->MovementSpeed;
}

