// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

#include "Enemy_AICharacter.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"


// Установка дополнений(модулей)
AEnemyAI::AEnemyAI()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerCollisionDetection = 
		CreateDefaultSubobject<USphereComponent>(TEXT("Player Collision Detection"));

	PlayerCollisionDetection->SetupAttachment(RootComponent);

	PlayerAttackCollisionDetection =
		CreateDefaultSubobject<USphereComponent>(TEXT("Player Attack Collision Detection"));
	
	PlayerAttackCollisionDetection->SetupAttachment(RootComponent);

	DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Collision"));
	DamageCollision->SetupAttachment(GetMesh(), TEXT("RightHandSocket"));

}

// Начало Игры
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Тик
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// биндинг клавиш
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

