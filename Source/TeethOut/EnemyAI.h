// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAI.generated.h"

UCLASS()
class ENEMY_AI_API AEnemyAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Вызов функции для установки default
	AEnemyAI();

protected:
	// Вызывается при начале игры
	virtual void BeginPlay() override;

public:	
	// Вызывается тик
	virtual void Tick(float DeltaTime) override;

	// Биндинг
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//Объявление переменных
	bool PlayerDetected;
	bool CanAttackPlayer;
	bool CanDealDamage;

	//объявление класса
	class Enemy_AICharacter* PlayerREF;

	//Объявление зон для ИИ(обнаружение игрока)
	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerCollisionDetection;

	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerAttackCollisionDetection;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;

};
