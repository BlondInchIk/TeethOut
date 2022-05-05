// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTrigger.h"
#include "LightTrigger.h"
#include "Components/BoxComponent.h"
#include "Containers/Array.h"

// Sets default values
AMyTrigger::AMyTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyTriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	MyTriggerComponent->SetupAttachment(RootComponent);

	MyTriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyTrigger::Triggered);
	MyTriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AMyTrigger::UnTriggered);
}

// Called when the game starts or when spawned
void AMyTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTrigger::Triggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepREsult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		for (ALightTrigger* Light : ListOfLights)
		{
			Light->SetLightEnabled();
		}
	}
}

void AMyTrigger::UnTriggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		for (ALightTrigger* Light : ListOfLights)
		{
			Light->SetLightDisabled();
		}
	}
}

