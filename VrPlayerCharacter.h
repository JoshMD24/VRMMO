// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "Components/BoxComponent.h"

#include "VrPlayerCharacter.generated.h"

UCLASS()
class VRMMO_API AVrPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVrPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Woodcutting
	void LevelUpWoodCutting();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int woodcuttingLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int woodcuttingXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForWoodcuttingLevel;

	UFUNCTION(BlueprintCallable)
		void gatherLog();
	UFUNCTION(BlueprintCallable)
		void gatherOakLog();
	UFUNCTION(BlueprintCallable)
		void gatherWillowLog();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerOakLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerWillowLogs;

	//Mining
	void LevelUpMining();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int miningLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int miningXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForMiningLevel;

	UFUNCTION(BlueprintCallable)
		void gatherCopperOre();
	UFUNCTION(BlueprintCallable)
		void gatherTinOre();
	UFUNCTION(BlueprintCallable)
		void gatherIronOre();
	UFUNCTION(BlueprintCallable)
		void gatherCoalOre();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerCopperOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerTinOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronOre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerCoalOre;

	//Fishing
	void LevelUpFishing();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int fishingLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int fishingXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForFishingLevel;

	UFUNCTION(BlueprintCallable)
		void GatherShrimp();
	UFUNCTION(BlueprintCallable)
		void GatherAnchovies();
	UFUNCTION(BlueprintCallable)
		void GatherTrout();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerTrout;

	//Fletching
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedOakLogs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedWillowLogs;

	UFUNCTION(BlueprintCallable)
		void DepositLog();
	UFUNCTION(BlueprintCallable)
		void DepositOakLogs();
	UFUNCTION(BlueprintCallable)
		void DepositWillowLogs();
	UFUNCTION(BlueprintCallable)
		void DepositFiveLogs();
	UFUNCTION(BlueprintCallable)
		void DepositFiveOakLogs();
	UFUNCTION(BlueprintCallable)
		void DepositFiveWillowLogs();
	UFUNCTION(BlueprintCallable)
		void DepositTenLogs();
	UFUNCTION(BlueprintCallable)
		void DepositTenOakLogs();
	UFUNCTION(BlueprintCallable)
		void DepositTenWillowLogs();

	void LevelUpFletching();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int fletchingLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int fletchingXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForFletchingLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerOakBows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerWillowBows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerArrowShafts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerOakArrowShafts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerWillowArrowShafts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingOakBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingWillowBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingArrowShaft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingOakArrowShaft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingWillowArrowShaft;

	UFUNCTION(BlueprintCallable)
		void SelectToFletchBow();
	UFUNCTION(BlueprintCallable)
		void SelectToFletchOakBow();
	UFUNCTION(BlueprintCallable)
		void SelectToFletchWillowBow();
	UFUNCTION(BlueprintCallable)
		void SelectToFletchArrowShafts();
	UFUNCTION(BlueprintCallable)
		void SelectToFletchOakArrowShafts();
	UFUNCTION(BlueprintCallable)
		void SelectToFletchWillowArrowShafts();

	UFUNCTION(BlueprintCallable)
		void CraftBow();
	UFUNCTION(BlueprintCallable)
		void CraftOakBow();
	UFUNCTION(BlueprintCallable)
		void CraftWillowBow();
	UFUNCTION(BlueprintCallable)
		void CraftArrowShaft();
	UFUNCTION(BlueprintCallable)
		void CraftOakArrowShaft();
	UFUNCTION(BlueprintCallable)
		void CraftWillowArrowShaft();

	//Smithing
	void LevelUpSmithing();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int smithingLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int smithingXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForSmithingLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeBars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronBars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelBars;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeSwords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzePlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBronzeArrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzePlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingBronzeArrows;

	UFUNCTION(BlueprintCallable)
		void DepositBronzeBar();
	UFUNCTION(BlueprintCallable)
		void DepositFiveBronzeBars();
	UFUNCTION(BlueprintCallable)
		void DepositTenBronzeBars();

	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeSword();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeShield();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeHelmet();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzePlatelegs();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzePlatebody();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeGloves();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeBoots();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftBronzeArrowheads();

	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronSword();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronShield();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronHelmet();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronPlatelegs();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronPlatebody();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronGloves();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronBoots();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftIronArrowheads();

	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelSword();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelShield();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelHelmet();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelPlatelegs();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelPlatebody();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelGloves();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelBoots();
	UFUNCTION(BlueprintCallable)
		void SelectToCraftSteelArrowheads();

	UFUNCTION(BlueprintCallable)
		void CraftBronzeSword();
	UFUNCTION(BlueprintCallable)
		void CraftBronzePlateLegs();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeChestPlate();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeShield();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeGloves();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeBoots();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeHelmet();
	UFUNCTION(BlueprintCallable)
		void CraftBronzeArrow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronSwords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronPlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerIronArrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronPlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingIronArrows;

	UFUNCTION(BlueprintCallable)
		void DepositIronBar();
	UFUNCTION(BlueprintCallable)
		void DepositFiveIronBars();
	UFUNCTION(BlueprintCallable)
		void DepositTenIronBars();

	UFUNCTION(BlueprintCallable)
		void CraftIronSword();
	UFUNCTION(BlueprintCallable)
		void CraftIronPlateLegs();
	UFUNCTION(BlueprintCallable)
		void CraftIronChestPlate();
	UFUNCTION(BlueprintCallable)
		void CraftIronShield();
	UFUNCTION(BlueprintCallable)
		void CraftIronGloves();
	UFUNCTION(BlueprintCallable)
		void CraftIronBoots();
	UFUNCTION(BlueprintCallable)
		void CraftIronHelmet();
	UFUNCTION(BlueprintCallable)
		void CraftIronArrow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelSwords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelPlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerSteelArrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelPlateLegs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelChestPlate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelGloves;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelBoots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCraftingSteelArrows;

	UFUNCTION(BlueprintCallable)
		void DepositSteelBar();
	UFUNCTION(BlueprintCallable)
		void DepositFiveSteelBars();
	UFUNCTION(BlueprintCallable)
		void DepositTenSteelBars();

	UFUNCTION(BlueprintCallable)
		void CraftSteelSword();
	UFUNCTION(BlueprintCallable)
		void CraftSteelShield();
	UFUNCTION(BlueprintCallable)
		void CraftSteelHelmet();
	UFUNCTION(BlueprintCallable)
		void CraftSteelPlateLegs();
	UFUNCTION(BlueprintCallable)
		void CraftSteelChestPlate();
	UFUNCTION(BlueprintCallable)
		void CraftSteelGloves();
	UFUNCTION(BlueprintCallable)
		void CraftSteelBoots();
	UFUNCTION(BlueprintCallable)
		void CraftSteelArrow();

	//Cooking
	void LevelUpCooking();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int cookingXP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XpNeededForCookingLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int cookingLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int depositedTrout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerCookedShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerCookedAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerCookedTrout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCookingShrimp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCookingAnchovies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isCookingTrout;

	UFUNCTION(BlueprintCallable)
		void DepositShrimp();
	UFUNCTION(BlueprintCallable)
		void DepositAnchovies();
	UFUNCTION(BlueprintCallable)
		void DepositTrout();
	UFUNCTION(BlueprintCallable)
		void DepositFiveShrimp();
	UFUNCTION(BlueprintCallable)
		void DepositFiveAnchovies();
	UFUNCTION(BlueprintCallable)
		void DepositFiveTrout();
	UFUNCTION(BlueprintCallable)
		void DepositTenShrimp();
	UFUNCTION(BlueprintCallable)
		void DepositTenAnchovies();
	UFUNCTION(BlueprintCallable)
		void DepositTenTrout();

	UFUNCTION(BlueprintCallable)
		void SelectToCookShrimp();
	UFUNCTION(BlueprintCallable)
		void SelectToCookAnchovies();
	UFUNCTION(BlueprintCallable)
		void SelectToCookTrout();

	UFUNCTION(BlueprintCallable)
		void CookShrimp();
	UFUNCTION(BlueprintCallable)
		void CookAnchovies();
	UFUNCTION(BlueprintCallable)
		void CookTrout();

	//Inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> InventorySlots = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerMaxWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int InventorySlotInt;

	UFUNCTION(BlueprintCallable)
		void DropItem();

	//Combat
	//Skills
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int attackLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int strengthLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int defenceLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int constitutionLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int archeryLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int attackXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int strengthXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int defenceXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int constitutionXp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int archeryXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int xpNeededForStrengthLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int xpNeededForDefenceLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int xpNeededForAttackLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int xpNeededForConstitutionLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int xpNeededForArcheryLevel;

	UFUNCTION(BlueprintCallable)
		void LevelUpAttack();
	UFUNCTION(BlueprintCallable)
		void LevelUpStrength();
	UFUNCTION(BlueprintCallable)
		void LevelUpDefence();
	UFUNCTION(BlueprintCallable)
		void LevelUpConstitution();
	UFUNCTION(BlueprintCallable)
		void LevelUpArchery();

	//Combat related

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerMaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int equippedSwordType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int combatXpToGain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int archeryXpToGain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerBowDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isBronzeSwordEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isIronSwordEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isSteelSwordEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasSwordOnBack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasArrows;

	UFUNCTION(BlueprintCallable)
		void EquipSword();
	UFUNCTION(BlueprintCallable)
		void CheckSwordOnBack();
	UFUNCTION(BlueprintCallable)
		void TakeSwordFromBack();
	UFUNCTION(BlueprintCallable)
		void PutSwordOnBack();
	UFUNCTION(BlueprintCallable)
		void GainCombatXp();
	UFUNCTION(BlueprintCallable)
		void GainArcheryXp();
	UFUNCTION(BlueprintCallable)
		void CheckArrows();
	UFUNCTION(BlueprintCallable)
		void ShotArrow();
	UFUNCTION(BlueprintCallable)
		void Die();

	//Gold
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int playerGoldCoins;
};