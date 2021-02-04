// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "Components/BoxComponent.h"

#include "VrPlayerCharacter.h"

#include "LongSword.generated.h"

UCLASS()
class VRMMO_API ALongSword : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALongSword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AVrPlayerCharacter* Player;

	int swordType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isBeingHeld;

	UFUNCTION(BlueprintCallable)
		void PickedUp();
};
