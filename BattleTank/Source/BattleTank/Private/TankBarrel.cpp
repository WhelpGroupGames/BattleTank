// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate( float RelativeSpeed )
{
    
    // move barrel the right abount this frame given a max elevation speed and frame rate
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0 );
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegrees,MaxElevationDegrees);
    
    SetRelativeRotation(FRotator(Elevation,0.0,0.0));
    
}