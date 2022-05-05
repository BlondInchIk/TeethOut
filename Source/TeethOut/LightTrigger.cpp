// Fill out your copyright notice in the Description page of Project Settings.


#include "LightTrigger.h"
#include "Components/RectLightComponent.h"

// Sets default values
ALightTrigger::ALightTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyLightComponent = CreateDefaultSubobject<URectLightComponent>(TEXT("LightComponent"));
	MyLightComponent->SetupAttachment(RootComponent);

	MyLightComponent->Intensity = 100000.0f;
}

// Called when the game starts or when spawned
void ALightTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

