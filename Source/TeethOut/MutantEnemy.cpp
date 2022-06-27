// Fill out your copyright notice in the Description page of Project Settings.


#include "MutantEnemy.h"
#include "Enemy_AICharacter.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "MutantAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "AITypes.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"


// Установка значений по умолчанию
AMutantEnemy::AMutantEnemy()
{
 	//Тик
	PrimaryActorTick.bCanEverTick = true;

	//Присвоение зоны обнаружения игрока
	PlayerCollisionDetection =
		CreateDefaultSubobject<USphereComponent>(TEXT("Player Collision Detection"));

	PlayerCollisionDetection->SetupAttachment(RootComponent);

	//Присвоение зоны начала атаки игрока
	PlayerAttackCollisionDetection =
		CreateDefaultSubobject<USphereComponent>(TEXT("Player Attack Collision Detection"));

	PlayerAttackCollisionDetection->SetupAttachment(RootComponent);

	//Присвоение зоны атаки игрока
	DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Collision"));
	DamageCollision->SetupAttachment(GetMesh(), TEXT("RightHandSocket"));

}

// Вызов функции при начале игры
void AMutantEnemy::BeginPlay()
{
	Super::BeginPlay();

	MutantAIController = Cast<AMutantAIController>(GetController());
	MutantAIController->GetPathFollowingComponent()->OnRequestFinished.AddUObject
	(this, &AMutantEnemy::OnAIMoveCompleted);

	PlayerCollisionDetection->OnComponentBeginOverlap.AddDynamic(this, 
		&AMutantEnemy::OnPlayerDetectedOverlapBegin);

	PlayerCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&AMutantEnemy::OnPlayerDetectedOverlapEnd);

	PlayerAttackCollisionDetection->OnComponentBeginOverlap.AddDynamic(this,
		&AMutantEnemy::OnPlayerAttackOverlapBegin);

	PlayerAttackCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&AMutantEnemy::OnPlayerAttackOverlapEnd);

	DamageCollision->OnComponentBeginOverlap.AddDynamic(this,
		&AMutantEnemy::OnDealDamageOverlapBegin);

	AnimInstance = GetMesh()->GetAnimInstance();
}

//Вызок тика
void AMutantEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Биндинг
void AMutantEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Начало анимации атаки при нахождении игрока в Player Attack Collision Detection
void AMutantEnemy::OnAIMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (!PlayerDetected)
	{
		MutantAIController->RandomPatrol();
	}
	else if (PlayerDetected && CanAttackPlayer)
	{
		StopSeekingPlayer();

		// анимация атаки
		AnimInstance->Montage_Play(EnemyAttackAnimation);
	}
}

//Получения координат игрока при его обнаружении
void AMutantEnemy::MoveToPlayer()
{
	MutantAIController->MoveToLocation(PlayerREF->GetActorLocation(), StoppingDistance, true);
}

//Движение к игроку при его обнаружении
void AMutantEnemy::SeekPlayer()
{
	MoveToPlayer();
	GetWorld()->GetTimerManager().SetTimer(SeekPlayerTimerHandle, this,
		&AMutantEnemy::SeekPlayer, 0.25f, true);
}

//Прекращение движения к игроку при его обнаружении
void AMutantEnemy::StopSeekingPlayer()
{
	GetWorld()->GetTimerManager().ClearTimer(SeekPlayerTimerHandle);
}

//Луп обнаружения
void AMutantEnemy::OnPlayerDetectedOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AEnemy_AICharacter>(OtherActor);
	if (PlayerREF)
	{
		PlayerDetected = true;
		SeekPlayer();
	}
}

//Луп обнаружения
void AMutantEnemy::OnPlayerDetectedOverlapEnd(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PlayerREF = Cast<AEnemy_AICharacter>(OtherActor);
	if (PlayerREF)
	{
		PlayerDetected = false;
		StopSeekingPlayer();
		MutantAIController->RandomPatrol();
	}
}

//Луп обнаружения
void AMutantEnemy::OnPlayerAttackOverlapBegin(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AEnemy_AICharacter>(OtherActor);
	if (PlayerREF)
	{
		CanAttackPlayer = true;
	}
}

//Луп обнаружения
void AMutantEnemy::OnPlayerAttackOverlapEnd(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PlayerREF = Cast<AEnemy_AICharacter>(OtherActor);
	if (PlayerREF)
	{
		CanAttackPlayer = false;

		//Прекращение анимации
		AnimInstance->Montage_Stop(0.0f, EnemyAttackAnimation);
		
		SeekPlayer();
	}
}

//Луп обнаружения
void AMutantEnemy::OnDealDamageOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerREF = Cast<AEnemy_AICharacter>(OtherActor);
	if (PlayerREF && CanDealDamage)
	{
		//KILL
		UE_LOG(LogTemp, Warning, TEXT("Player Damaged"));
	}
}

// Анимация атаки
void AMutantEnemy::AttackAnimationEnded()
{
	if (CanAttackPlayer)
	{
		AnimInstance->Montage_Play(EnemyAttackAnimation);
	}
}


