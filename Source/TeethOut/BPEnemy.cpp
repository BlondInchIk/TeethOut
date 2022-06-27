// Fill out your copyright notice in the Description page of Project Settings.


#include "BPEnemy.h"
#include "MainCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "MutantAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "AITypes.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"



ABPEnemy::ABPEnemy()
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


void ABPEnemy::BeginPlay()
{
	Super::BeginPlay();

	MutantAIController = Cast<AMutantAIController>(GetController());
	MutantAIController->GetPathFollowingComponent()->OnRequestFinished.AddUObject
	(this, &ABPEnemy::OnAIMoveCompleted);

	PlayerCollisionDetection->OnComponentBeginOverlap.AddDynamic(this,
		&ABPEnemy::OnPlayerDetectedOverlapBegin);

	PlayerCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&ABPEnemy::OnPlayerDetectedOverlapEnd);

	PlayerAttackCollisionDetection->OnComponentBeginOverlap.AddDynamic(this,
		&ABPEnemy::OnPlayerAttackOverlapBegin);

	PlayerAttackCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&ABPEnemy::OnPlayerAttackOverlapEnd);

	DamageCollision->OnComponentBeginOverlap.AddDynamic(this,
		&ABPEnemy::OnDealDamageOverlapBegin);

	AnimInstance = GetMesh()->GetAnimInstance();
}

// Called every frame
void ABPEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABPEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABPEnemy::OnAIMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (!PlayerDetected)
	{
		MutantAIController->RandomPatrol();
	}
	else if (PlayerDetected && CanAttackPlayer)
	{
		StopSeekingPlayer();

		// attack player
		// AnimInstance->Montage_Play(EnemyAttackAnimation);
	}
}

void ABPEnemy::MoveToPlayer()
{
	MutantAIController->MoveToLocation(PlayerREF->GetActorLocation(), StoppingDistance, true);
}

void ABPEnemy::SeekPlayer()
{
	MoveToPlayer();
	GetWorld()->GetTimerManager().SetTimer(SeekPlayerTimerHandle, this,
		&ABPEnemy::SeekPlayer, 0.25f, true);
}

void ABPEnemy::StopSeekingPlayer()
{
	GetWorld()->GetTimerManager().ClearTimer(SeekPlayerTimerHandle);
}

void ABPEnemy::OnPlayerDetectedOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AMainCharacter>(OtherActor);
	if (PlayerREF)
	{
		PlayerDetected = true;
		SeekPlayer();
	}
}

void ABPEnemy::OnPlayerDetectedOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PlayerREF = Cast<AMainCharacter>(OtherActor);
	if (PlayerREF)
	{
		PlayerDetected = false;
		StopSeekingPlayer();
		MutantAIController->RandomPatrol();
	}
}

void ABPEnemy::OnPlayerAttackOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AMainCharacter>(OtherActor);
	if (PlayerREF)
	{
		CanAttackPlayer = true;
	}
}

void ABPEnemy::OnPlayerAttackOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PlayerREF = Cast<AMainCharacter>(OtherActor);
	if (PlayerREF)
	{
		CanAttackPlayer = false;

		// stop the attack animation and chase the player
		AnimInstance->Montage_Stop(0.0f, EnemyAttackAnimation);

		SeekPlayer();
	}
}

void ABPEnemy::OnDealDamageOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AMainCharacter>(OtherActor);
	if (PlayerREF && CanDealDamage)
	{
		// deal damage to player
		UE_LOG(LogTemp, Warning, TEXT("Player Damaged"));
	}
}

void ABPEnemy::AttackAnimationEnded()
{
	if (CanAttackPlayer)
	{
		// AnimInstance->Montage_Play(EnemyAttackAnimation);
	}
}


