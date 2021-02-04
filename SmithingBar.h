// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"

#include "VrPlayerCharacter.h"

#include "SmithingBar.generated.h"

UCLASS()
class VRMMO_API ASmithingBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASmithingBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AVrPlayerCharacter* Player;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector Location;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FRotator Rotation;

	UFUNCTION(BlueprintCallable)
		void SpawnBar();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int hitsUntilHammered;

	UFUNCTION(BlueprintCallable)
		void Hammered();
};
