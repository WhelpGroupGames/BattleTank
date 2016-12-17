// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());    
}


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    ControlledTank = GetControlledTank();
    TargettedTank = GetPlayerTank();
    
    if ( ! ControlledTank )
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController possesing [ %s ]"), *ControlledTank->GetName());
    }
    
    
    if ( TargettedTank )
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank [ %s ] Target [ %s ]"), *ControlledTank->GetName(), *TargettedTank->GetName() );
    }
    
    
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto WorldPlayerController = GetWorld()->GetFirstPlayerController();
    
    // if for some reason there was no controller, we'd crash
    if ( ! WorldPlayerController ) { return nullptr; }
    
    return Cast<ATank>(WorldPlayerController->GetPawn());
}