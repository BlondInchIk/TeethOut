// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MutantEnemy.generated.h"

UCLASS()
class ENEMY_AI_API AMutantEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Установка значений из функции
	AMutantEnemy();

protected:
	// Вызок при начале игры
	virtual void BeginPlay() override;

public:	
	// Вызов тика
	virtual void Tick(float DeltaTime) override;

	// Биндинг
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	// Объявление переменных
	bool PlayerDetected;
	bool CanAttackPlayer;

	UPROPERTY(BlueprintReadWrite)
		bool CanDealDamage;

	//Объявление игрока
	class AEnemy_AICharacter* PlayerREF;

	//Объявление компонентов и их доступ
	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerCollisionDetection;

	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerAttackCollisionDetection;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;

	//Объявление монстра
	class AMutantAIController* MutantAIController;

	void OnAIMoveCompleted(struct FAIRequestID RequestID, const struct FPathFollowingResult& Result);
	
	//Объявление зоны для остановки
	UPROPERTY(EditAnywhere)
		float StoppingDistance = 100.0f;

	FTimerHandle SeekPlayerTimerHandle;

	// Объявление функций
	UFUNCTION()
		void MoveToPlayer();

	UFUNCTION()
		void SeekPlayer();

	UFUNCTION()
		void StopSeekingPlayer();

	// Объявление функций зон 
	UFUNCTION()
		void OnPlayerDetectedOverlapBegin(class UPrimitiveComponent* OverlappedComp, 
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnPlayerDetectedOverlapEnd(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex);

	UFUNCTION()
		void OnPlayerAttackOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnPlayerAttackOverlapEnd(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UFUNCTION()
		void OnDealDamageOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Установка доступа
	UPROPERTY(EditAnywhere)
		class UAnimMontage* EnemyAttackAnimation;

	class UAnimInstance* AnimInstance;

	// Объявление функции
	UFUNCTION(BlueprintCallable)
		void AttackAnimationEnded();

};
