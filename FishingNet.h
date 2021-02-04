// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"

#include "VrPlayerCharacter.h"

#include "FishingNet.generated.h"

UCLASS()
class VRMMO_API AFishingNet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFishingNet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AVrPlayerCharacter* Player;

	int fishType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isNetInWater;

	UFUNCTION(BlueprintCallable)
		void Fishing();
	UFUNCTION(BlueprintCallable)
		void CatchFish();
	UFUNCTION(BlueprintCallable)
		void StopFishing();

	FTimerHandle FishingTimer;
};
