// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Tooth.generated.h"

UCLASS()
class TEETHOUT_API ATooth : public AActor
{
	GENERATED_BODY()
	
public:	
	ATooth();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		bool SpawnActor();

	void ScheduleActorSpawn();

private:
	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> ActorClassToBeSpawned;

	UPROPERTY(EditAnywhere)
		float AvgSpawnTime = 5.f;

	UPROPERTY(EditAnywhere)
		float RandomSpawnTimeOffset = 1.f;

};
