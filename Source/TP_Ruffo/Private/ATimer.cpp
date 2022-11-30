// Fill out your copyright notice in the Description page of Project Settings.


#include "ATimer.h"

// Sets default values
AATimer::AATimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATimer::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AATimer::MyTimer, 1.0f, true, 0.0f);
	
}

// Called every frame
void AATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AATimer::MyTimer()
{
	if (!inStop)
	{
		if (seconds != 0)
		{
			seconds = seconds - 1;
		}
		else
		{
			if (minutes == 0)
			{
				endTimer.Broadcast();
			}
			else
			{
				minutes = minutes - 1;
				seconds = 59;
			}
		}
	}
}