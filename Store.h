// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Engine/StaticMesh.h"

#include "VrPlayerCharacter.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

#include "Store.generated.h"

UCLASS()
class VRMMO_API AStore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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

	UFUNCTION(BlueprintCallable)
		void BuyLog();
	UFUNCTION(BlueprintCallable)
		void BuyOakLog();
	UFUNCTION(BlueprintCallable)
		void BuyWillowLog();
	UFUNCTION(BlueprintCallable)
		void BuyCopperOre();
	UFUNCTION(BlueprintCallable)
		void BuyTinOre();
	UFUNCTION(BlueprintCallable)
		void BuyIronOre();
	UFUNCTION(BlueprintCallable)
		void BuyCoalOre();
	UFUNCTION(BlueprintCallable)
		void BuyShrimp();
	UFUNCTION(BlueprintCallable)
		void BuyAnchovies();
	UFUNCTION(BlueprintCallable)
		void BuyTrout();
	UFUNCTION(BlueprintCallable)
		void BuyBow();
	UFUNCTION(BlueprintCallable)
		void BuyOakBow();
	UFUNCTION(BlueprintCallable)
		void BuyWillowBow();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeSword();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeShield();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeHelmet();
	UFUNCTION(BlueprintCallable)
		void BuyBronzePlatelegs();
	UFUNCTION(BlueprintCallable)
		void BuyBronzePlatebody();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeGloves();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeBoots();
	UFUNCTION(BlueprintCallable)
		void BuyBronzeArrow();
	UFUNCTION(BlueprintCallable)
		void BuyIronSword();
	UFUNCTION(BlueprintCallable)
		void BuyIronShield();
	UFUNCTION(BlueprintCallable)
		void BuyIronHelmet();
	UFUNCTION(BlueprintCallable)
		void BuyIronPlatelegs();
	UFUNCTION(BlueprintCallable)
		void BuyIronPlatebody();
	UFUNCTION(BlueprintCallable)
		void BuyIronGloves();
	UFUNCTION(BlueprintCallable)
		void BuyIronBoots();
	UFUNCTION(BlueprintCallable)
		void BuyIronArrow();
	UFUNCTION(BlueprintCallable)
		void BuySteelSword();
	UFUNCTION(BlueprintCallable)
		void BuySteelShield();
	UFUNCTION(BlueprintCallable)
		void BuySteelHelmet();
	UFUNCTION(BlueprintCallable)
		void BuySteelPlatelegs();
	UFUNCTION(BlueprintCallable)
		void BuySteelPlatebody();
	UFUNCTION(BlueprintCallable)
		void BuySteelGloves();
	UFUNCTION(BlueprintCallable)
		void BuySteelBoots();
	UFUNCTION(BlueprintCallable)
		void BuySteelArrows();

	UFUNCTION(BlueprintCallable)
		void SellLog();
	UFUNCTION(BlueprintCallable)
		void SellOakLog();
	UFUNCTION(BlueprintCallable)
		void SellWillowLog();
	UFUNCTION(BlueprintCallable)
		void SellCopperOre();
	UFUNCTION(BlueprintCallable)
		void SellTinOre();
	UFUNCTION(BlueprintCallable)
		void SellIronOre();
	UFUNCTION(BlueprintCallable)
		void SellCoalOre();
	UFUNCTION(BlueprintCallable)
		void SellShrimp();
	UFUNCTION(BlueprintCallable)
		void SellAnchovies();
	UFUNCTION(BlueprintCallable)
		void SellTrout();
	UFUNCTION(BlueprintCallable)
		void SellBow();
	UFUNCTION(BlueprintCallable)
		void SellOakBow();
	UFUNCTION(BlueprintCallable)
		void SellWillowBow();
	UFUNCTION(BlueprintCallable)
		void SellBronzeSword();
	UFUNCTION(BlueprintCallable)
		void SellBronzeShield();
	UFUNCTION(BlueprintCallable)
		void SellBronzeHelmet();
	UFUNCTION(BlueprintCallable)
		void SellBronzePlatelegs();
	UFUNCTION(BlueprintCallable)
		void SellBronzePlatebody();
	UFUNCTION(BlueprintCallable)
		void SellBronzeGloves();
	UFUNCTION(BlueprintCallable)
		void SellBronzeBoots();
	UFUNCTION(BlueprintCallable)
		void SellBronzeArrow();
	UFUNCTION(BlueprintCallable)
		void SellIronSword();
	UFUNCTION(BlueprintCallable)
		void SellIronShield();
	UFUNCTION(BlueprintCallable)
		void SellIronHelmet();
	UFUNCTION(BlueprintCallable)
		void SellIronPlatelegs();
	UFUNCTION(BlueprintCallable)
		void SellIronPlatebody();
	UFUNCTION(BlueprintCallable)
		void SellIronGloves();
	UFUNCTION(BlueprintCallable)
		void SellIronBoots();
	UFUNCTION(BlueprintCallable)
		void SellIronArrow();
	UFUNCTION(BlueprintCallable)
		void SellSteelSword();
	UFUNCTION(BlueprintCallable)
		void SellSteelShield();
	UFUNCTION(BlueprintCallable)
		void SellSteelHelmet();
	UFUNCTION(BlueprintCallable)
		void SellSteelPlatelegs();
	UFUNCTION(BlueprintCallable)
		void SellSteelPlatebody();
	UFUNCTION(BlueprintCallable)
		void SellSteelGloves();
	UFUNCTION(BlueprintCallable)
		void SellSteelBoots();
	UFUNCTION(BlueprintCallable)
		void SellSteelArrows();
};
