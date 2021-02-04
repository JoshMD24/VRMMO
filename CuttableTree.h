// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

#include "VrPlayerCharacter.h"

#include "CuttableTree.generated.h"

UCLASS()
class VRMMO_API ACuttableTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACuttableTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AVrPlayerCharacter* Player;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int logsRemaining;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int requiredHatchetLevel;

	UFUNCTION(BlueprintCallable)
		void LoseLog();
	UFUNCTION(BlueprintCallable)
		void LoseOakLog();
	UFUNCTION(BlueprintCallable)
		void LoseWillowLog();
	UFUNCTION(BlueprintCallable)
		void SetLogsRemaining();

	FTimerHandle SetLogsTimer;
};
