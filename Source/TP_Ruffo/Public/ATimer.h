// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATimer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimeEnd);
UCLASS()
class TP_RUFFO_API AATimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MyTimer();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int minutes = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int seconds = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool inStop = false;
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnTimeEnd endTimer;

};
