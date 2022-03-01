// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownViewPawn.h"

// Sets default values
ATopDownViewPawn::ATopDownViewPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATopDownViewPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopDownViewPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopDownViewPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

