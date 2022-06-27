// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tooth.generated.h"
#include "Components/BoxComponent.h"

UCLASS()
class TEETHOUT_API ATooth : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATooth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprtintCallable)
		bool SpawnActor();

	void ScheduleActorSpawn();

private:
	UPROPERTY(EditDefaultOnly)
		UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> ActorClassToBeSpawned;

	UPROPERTY(EditAnywhere)
		float AvgSpawnTime = 5.f;

	UPROPERTY(EditAnywhere)
		float RandomSpawnTimeOffset = 1.f;

};
