// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"

#include "VrPlayerCharacter.h"

#include "MineableOre.generated.h"

UCLASS()
class VRMMO_API AMineableOre : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMineableOre();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AVrPlayerCharacter* Player;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int oresRemaining;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int requiredPickaxeLevel;

	UFUNCTION(BlueprintCallable)
		void LoseCopperOre();
	UFUNCTION(BlueprintCallable)
		void LoseTinOre();
	UFUNCTION(BlueprintCallable)
		void LoseIronOre();
	UFUNCTION(BlueprintCallable)
		void LoseCoalOre();
	UFUNCTION(BlueprintCallable)
		void SetOresRemaining();

	FTimerHandle OreTimer;
};
