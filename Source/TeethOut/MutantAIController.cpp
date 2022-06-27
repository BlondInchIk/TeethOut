// Fill out your copyright notice in the Description page of Project Settings.


#include "MutantAIController.h"

#include "NavigationSystem.h"

//При начале игры, линк со зоной ходьбы
void AMutantAIController::BeginPlay()
{
    Super::BeginPlay();

    NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);

    RandomPatrol();
}

//Случайный путь
void AMutantAIController::RandomPatrol()
{    
    if (NavArea)
    {
        NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), GetPawn()->GetActorLocation(),
            RandomLocation, 15000.0f);

        MoveToLocation(RandomLocation);
    }
}

