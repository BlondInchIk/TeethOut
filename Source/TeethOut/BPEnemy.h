// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BPEnemy.generated.h"

UCLASS()
 class TEETHOUT_API ABPEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// ABPEnemy();

protected:
	// virtual void BeginPlay() override;

public:
	// virtual void Tick(float DeltaTime) override;

	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// bool PlayerDetected;
	// bool CanAttackPlayer;

	// UPROPERTY(BlueprintReadWrite)
	// 	bool CanDealDamage;

	// class AMainCharacter* PlayerREF;

	// UPROPERTY(EditAnywhere)
	// 	class USphereComponent* PlayerCollisionDetection;

	// UPROPERTY(EditAnywhere)
	// 	class USphereComponent* PlayerAttackCollisionDetection;

	// UPROPERTY(EditAnywhere)
	// 	class UBoxComponent* DamageCollision;

	// class AMutantAIController* MutantAIController;

	// void OnAIMoveCompleted(struct FAIRequestID RequestID, const struct FPathFollowingResult& Result);

	// UPROPERTY(EditAnywhere)
	// 	float StoppingDistance = 100.0f;

	// FTimerHandle SeekPlayerTimerHandle;

	// UFUNCTION()
	// 	void MoveToPlayer();

	// UFUNCTION()
	// 	void SeekPlayer();

	// UFUNCTION()
	// 	void StopSeekingPlayer();

	// UFUNCTION()
	// 	void OnPlayerDetectedOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// UFUNCTION()
	// 	void OnPlayerDetectedOverlapEnd(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex);

	// UFUNCTION()
	// 	void OnPlayerAttackOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// UFUNCTION()
	// 	void OnPlayerAttackOverlapEnd(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex);

	// UFUNCTION()
	// 	void OnDealDamageOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// UPROPERTY(EditAnywhere)
	// 	class UAnimMontage* EnemyAttackAnimation;

	// class UAnimInstance* AnimInstance;

	// UFUNCTION(BlueprintCallable)
	// 	void AttackAnimationEnded();

};

