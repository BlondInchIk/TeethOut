// // Fill out your copyright notice in the Description page of Project Settings.

// #pragma once

// #include "CoreMinimal.h"
// #include "GameFramework/Actor.h"
// #include "Components/BoxComponent.h"
// #include "Tooth.generated.h"

// UCLASS()
// class TEETHOUT_API ATooth : public AActor
// {
// 	GENERATED_BODY()
	
// public:	
// 	// Sets default values for this actor's properties
// 	ATooth();

// protected:
// 	// Called when the game starts or when spawned
// 	virtual void BeginPlay() override;

// 	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

// public:	

// 	UFUNCTION(BlueprintCallable)
// 		bool SpawnActor();

// 	void ScheduleActorSpawn();

// private:
// 	UFUNCTION(BlueprintCallable)
// 		void SpawnActorScheduled();

// public:
// 	UPROPERTY(EditDefaultsOnly)
// 		UBoxComponent* SpawnBox;

// 	UPROPERTY(EditAnywhere)
// 		TSubclassOf<AActor> ActorClassToBeSpawned;

// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 		bool ShouldSpawn = true;


// 	UPROPERTY(EditAnywhere)
// 		float AvgSpawnTime = 5.f;

// 	UPROPERTY(EditAnywhere)
// 		float RandomSpawnTimeOffset = 1.f;

// private:

// 	FTimerHandle SpawnTimerHandle;

// };
