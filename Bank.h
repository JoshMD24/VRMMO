// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Engine/StaticMesh.h"

#include "VrPlayerCharacter.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

#include "Bank.generated.h"

UCLASS()
class VRMMO_API ABank : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	// Called every frame

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxComp;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	AVrPlayerCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> BankSlots = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BankSlotInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedOakLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedWillowLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedCopperOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedTinOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedTrout;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedOakBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedWillowBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedArrowShaft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedOakArrowShaft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedWillowArrowShaft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzePlatelegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzePlatebody;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedBronzeArrows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronPlatelegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronPlatebody;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedIronArrows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelPlatelegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelPlatebody;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedSteelArrows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedCoalOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedCookedShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedCookedAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedCookedTrout;

	UFUNCTION(BlueprintCallable)
		void DepositItem();
	UFUNCTION(BlueprintCallable)
		void WithdrawItem();
};