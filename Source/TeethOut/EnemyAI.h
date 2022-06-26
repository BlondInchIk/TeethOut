// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAI.generated.h"

UCLASS()
class TEETHOUT_API AEnemyAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	bool PlayerDetected;
	bool CanAttackPlayer;
	bool CanDealDamage;

	class MainCharacter* PlayerREF;

	UPROPERTY(EditAnyWhere)
		class USphereComponent* PlayerCollisionDetection;

	UPROPERTY(EditAnyWhere)
		class USphereComponent* PlayerAttackCollisionDetection;

	UPROPERTY(EditAnyWhere)
		class UBoxComponent* DamageCollision;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
