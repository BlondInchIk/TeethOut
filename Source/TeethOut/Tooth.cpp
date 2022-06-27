// // Fill out your copyright notice in the Description page of Project Settings.


// #include "Tooth.h"

// // Sets default values
// ATooth::ATooth()
// {
//  	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
// 	PrimaryActorTick.bCanEverTick = false;

// 	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
// 	RootComponent = SpawnBox;
// }

// // Called when the game starts or when spawned
// void ATooth::BeginPlay()
// {
// 	Super::BeginPlay();
	
// 	if (ShouldSpawn)
// 	{
// 		ScheduleActorSpawn();
// 	}
// }

// void ATooth::EndPlay(const EEndPlayReason::Type EndPlayReason)
// {
// 	Super::EndPlay(EndPlayReason);
	
// 	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
// }

// bool ATooth::SpawnActor()
// {
// 	bool SpawnedActor = false;
// 	if (ActorClassToBeSpawned)
// 	{
// 		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());


// 		FVector SpawnLocation = BoxBounds.Origin;
// 		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
// 		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
// 		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

// 		SpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &SpawnLocation);
// 	}
// 	return SpawnedActor;
// }

// void ATooth::ScheduleActorSpawn()
// {
// 	float DektaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());

// 	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ATooth::SpawnActorScheduled, DeltaToNextSpawn, false);
	 

// }


// void ATooth::SpawnActorScheduled()
// {
// 	if (!SpawnActor)
// 	{
// 		if (ShouldSpawn)
// 		{
// 			ScheduleActorSpawn();
// 		} 
// 	}
// 	else
// 	{

// 	}
	
// }