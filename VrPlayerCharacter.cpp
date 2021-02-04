// Fill out your copyright notice in the Description page of Project Settings.


#include "VrPlayerCharacter.h"

// Sets default values
AVrPlayerCharacter::AVrPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVrPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	woodcuttingLevel = 1;
	miningLevel = 1;
	fishingLevel = 1;
	fletchingLevel = 1;
	smithingLevel = 1;
	cookingLevel = 1;
	XpNeededForWoodcuttingLevel = 80;
	XpNeededForMiningLevel = 80;
	XpNeededForFishingLevel = 80;
	XpNeededForFletchingLevel = 80;
	XpNeededForSmithingLevel = 80;
	XpNeededForCookingLevel = 80;
	playerMaxWeight = 100;
	isCraftingBow = true;
	isCraftingBronzeSword = true;
	isCookingShrimp = true;
	attackLevel = 1;
	strengthLevel = 1;
	defenceLevel = 1;
	constitutionLevel = 1;
	xpNeededForAttackLevel = 80;
	xpNeededForStrengthLevel = 80;
	xpNeededForDefenceLevel = 80;
	xpNeededForConstitutionLevel = 80;
	playerDamage = 1;
	playerMaxHealth = 100;
	playerHealth = 100;
}

// Called every frame
void AVrPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVrPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Woodcutting
void AVrPlayerCharacter::LevelUpWoodCutting()
{
	woodcuttingLevel++;
	XpNeededForWoodcuttingLevel = XpNeededForWoodcuttingLevel * 2.2;
	XpNeededForWoodcuttingLevel = round(XpNeededForWoodcuttingLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForWoodcuttingLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(woodcuttingLevel));
}

void AVrPlayerCharacter::gatherLog()
{
	if (playerWeight < playerMaxWeight)
	{
		playerLogs++;
		woodcuttingXp = woodcuttingXp + 25;
		playerWeight = playerWeight + 1;
	}

	if (woodcuttingXp >= XpNeededForWoodcuttingLevel)
	{
		LevelUpWoodCutting();
	}

	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 1;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 1)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(woodcuttingXp));
}

void AVrPlayerCharacter::gatherOakLog()
{
	if (playerWeight < playerMaxWeight)
	{
		playerOakLogs++;
		woodcuttingXp = woodcuttingXp + 50;
		playerWeight = playerWeight + 1;
	}

	if (woodcuttingXp >= XpNeededForWoodcuttingLevel)
	{
		LevelUpWoodCutting();
	}

	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 2;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 2)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(woodcuttingXp));
}

void AVrPlayerCharacter::gatherWillowLog()
{
	if (playerWeight < playerMaxWeight)
	{
		playerWillowLogs++;
		woodcuttingXp = woodcuttingXp + 75;
		playerWeight = playerWeight + 1;
	}

	if (woodcuttingXp >= XpNeededForWoodcuttingLevel)
	{
		LevelUpWoodCutting();
	}

	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 3;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 3)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(woodcuttingXp));
}


//Mining
void AVrPlayerCharacter::LevelUpMining()
{
	miningLevel++;
	XpNeededForMiningLevel = XpNeededForMiningLevel * 2.2;
	XpNeededForMiningLevel = round(XpNeededForMiningLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForMiningLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(miningLevel));
}

void AVrPlayerCharacter::gatherCopperOre()
{
	if (playerWeight < playerMaxWeight)
	{
		playerCopperOre++;
		miningXp = miningXp + 25;
		playerWeight = playerWeight + 1;
	}

	if (miningXp >= XpNeededForMiningLevel)
	{
		LevelUpMining();
	}

	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 4;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 4)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(miningXp));
}

void AVrPlayerCharacter::gatherTinOre()
{
	if (playerWeight < playerMaxWeight)
	{
		playerTinOre++;
		miningXp = miningXp + 25;
		playerWeight = playerWeight + 1;
	}
	if (miningXp >= XpNeededForMiningLevel)
	{
		LevelUpMining();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 5;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 5)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(miningXp));
}

void AVrPlayerCharacter::gatherIronOre()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronOre++;
		miningXp = miningXp + 50;
		playerWeight = playerWeight + 1;
	}
	if (miningXp >= XpNeededForMiningLevel)
	{
		LevelUpMining();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 6;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 6)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(miningXp));
}

void AVrPlayerCharacter::gatherCoalOre()
{
	if (playerWeight < playerMaxWeight)
	{
		playerCoalOre++;
		miningXp = miningXp + 75;
		playerWeight = playerWeight + 1;
	}
	if (miningXp >= XpNeededForMiningLevel)
	{
		LevelUpMining();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 40;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 40)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(miningXp));
}

//Fishing
void AVrPlayerCharacter::LevelUpFishing()
{
	fishingLevel++;
	XpNeededForFishingLevel = XpNeededForFishingLevel * 2.2;
	XpNeededForFishingLevel = round(XpNeededForFishingLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForFishingLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(fishingLevel));
}

void AVrPlayerCharacter::GatherShrimp()
{
	if (playerWeight < playerMaxWeight)
	{
		playerShrimp++;
		fishingXp = fishingXp + 25;
		playerWeight = playerWeight + 1;
	}
	if (fishingXp >= XpNeededForFishingLevel)
	{
		LevelUpFishing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 7;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 7)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fishingXp));
}

void AVrPlayerCharacter::GatherAnchovies()
{
	if (playerWeight < playerMaxWeight)
	{
		playerAnchovies++;
		fishingXp = fishingXp + 50;
		playerWeight = playerWeight + 1;
	}
	if (fishingXp >= XpNeededForFishingLevel)
	{
		LevelUpFishing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 8;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 8)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fishingXp));
}

void AVrPlayerCharacter::GatherTrout()
{
	if (playerWeight < playerMaxWeight)
	{
		playerTrout++;
		fishingXp = fishingXp + 75;
		playerWeight = playerWeight + 1;
	}
	if (fishingXp >= XpNeededForFishingLevel)
	{
		LevelUpFishing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 9;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 9)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fishingXp));
}

void AVrPlayerCharacter::DepositLog()
{
	if (playerLogs >= 1)
	{
		playerLogs--;
		depositedLogs++;
		playerWeight--;

		if (playerLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 1)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositOakLogs()
{
	if (playerOakLogs >= 1)
	{
		playerOakLogs--;
		depositedOakLogs++;
		playerWeight--;

		if (playerOakLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 2)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositWillowLogs()
{
	if (playerWillowLogs >= 1)
	{
		playerWillowLogs--;
		depositedWillowLogs++;
		playerWeight--;

		if (playerWillowLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 3)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveLogs()
{
	if (playerLogs >= 5)
	{
		playerLogs = playerLogs - 5;
		depositedLogs = depositedLogs + 5;
		playerWeight = playerWeight - 5;

		if (playerLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 1)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveOakLogs()
{
	if (playerOakLogs >= 5)
	{
		playerOakLogs = playerOakLogs - 5;
		depositedOakLogs = depositedOakLogs + 5;
		playerWeight = playerWeight - 5;

		if (playerOakLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 2)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveWillowLogs()
{
	if (playerWillowLogs >= 5)
	{
		playerWillowLogs = playerWillowLogs - 5;
		depositedWillowLogs = depositedWillowLogs + 5;
		playerWeight = playerWeight - 5;

		if (playerWillowLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 3)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenLogs()
{
	if (playerLogs >= 10)
	{
		playerLogs = playerLogs - 10;
		depositedLogs = depositedLogs + 10;
		playerWeight = playerWeight - 10;

		if (playerLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 1)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenOakLogs()
{
	if (playerOakLogs >= 10)
	{
		playerOakLogs = playerOakLogs - 10;
		depositedOakLogs = depositedOakLogs + 10;
		playerWeight = playerWeight - 10;

		if (playerOakLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 2)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenWillowLogs()
{
	if (playerWillowLogs >= 10)
	{
		playerWillowLogs = playerWillowLogs - 10;
		depositedWillowLogs = depositedWillowLogs + 10;
		playerWeight = playerWeight - 10;

		if (playerWillowLogs >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 3)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

//Fletching
void AVrPlayerCharacter::LevelUpFletching()
{
	fletchingLevel++;
	XpNeededForFletchingLevel = XpNeededForFletchingLevel * 2.2;
	XpNeededForFletchingLevel = round(XpNeededForFletchingLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForFletchingLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(fletchingLevel));
}

void AVrPlayerCharacter::SelectToFletchBow()
{
	isCraftingBow = true;
	isCraftingOakBow = false;
	isCraftingWillowBow = false;
	isCraftingArrowShaft = false;
	isCraftingOakArrowShaft = false;
	isCraftingWillowArrowShaft = false;
}

void AVrPlayerCharacter::SelectToFletchOakBow()
{
	if (fletchingLevel >= 15)
	{
		isCraftingBow = false;
		isCraftingOakBow = true;
		isCraftingWillowBow = false;
		isCraftingArrowShaft = false;
		isCraftingOakArrowShaft = false;
		isCraftingWillowArrowShaft = false;
	}
}

void AVrPlayerCharacter::SelectToFletchWillowBow()
{
	if (fletchingLevel >= 30)
	{
		isCraftingBow = false;
		isCraftingOakBow = false;
		isCraftingWillowBow = true;
		isCraftingArrowShaft = false;
		isCraftingOakArrowShaft = false;
		isCraftingWillowArrowShaft = false;
	}
}

void AVrPlayerCharacter::SelectToFletchArrowShafts()
{
	isCraftingBow = false;
	isCraftingOakBow = false;
	isCraftingWillowBow = false;
	isCraftingArrowShaft = true;
	isCraftingOakArrowShaft = false;
	isCraftingWillowArrowShaft = false;
}

void AVrPlayerCharacter::SelectToFletchOakArrowShafts()
{
	if (fletchingLevel >= 15)
	{
		isCraftingBow = false;
		isCraftingOakBow = false;
		isCraftingWillowBow = false;
		isCraftingArrowShaft = false;
		isCraftingOakArrowShaft = true;
		isCraftingWillowArrowShaft = false;
	}
}

void AVrPlayerCharacter::SelectToFletchWillowArrowShafts()
{
	if (fletchingLevel >= 30)
	{
		isCraftingBow = false;
		isCraftingOakBow = false;
		isCraftingWillowBow = false;
		isCraftingArrowShaft = false;
		isCraftingOakArrowShaft = false;
		isCraftingWillowArrowShaft = true;
	}
}

void AVrPlayerCharacter::CraftBow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBows++;
		depositedLogs = depositedLogs - 5;
		fletchingXp = fletchingXp + 25;
		playerWeight = playerWeight + 5;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 10;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 10)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

void AVrPlayerCharacter::CraftOakBow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerOakBows++;
		depositedOakLogs = depositedOakLogs - 5;
		fletchingXp = fletchingXp + 50;
		playerWeight = playerWeight + 5;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 11;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 11)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

void AVrPlayerCharacter::CraftWillowBow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerWillowBows++;
		depositedWillowLogs = depositedWillowLogs - 5;
		fletchingXp = fletchingXp + 75;
		playerWeight = playerWeight + 5;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 12;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 12)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

void AVrPlayerCharacter::CraftArrowShaft()
{
	if (playerWeight < playerMaxWeight)
	{
		playerArrowShafts++;
		depositedLogs--;
		fletchingXp = fletchingXp + 10;
		playerWeight = playerWeight + 1;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 13;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 13)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

void AVrPlayerCharacter::CraftOakArrowShaft()
{
	if (playerWeight < playerMaxWeight)
	{
		playerOakArrowShafts++;
		depositedOakLogs--;
		fletchingXp = fletchingXp + 20;
		playerWeight = playerWeight + 5;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 14;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 14)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

void AVrPlayerCharacter::CraftWillowArrowShaft()
{
	if (playerWeight < playerMaxWeight)
	{
		playerWillowArrowShafts++;
		depositedWillowLogs--;
		fletchingXp = fletchingXp + 30;
		playerWeight = playerWeight + 5;
	}
	if (fletchingXp >= XpNeededForFletchingLevel)
	{
		LevelUpFletching();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 15;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 15)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(fletchingXp));
}

//Smithing
void AVrPlayerCharacter::LevelUpSmithing()
{
	smithingLevel++;
	XpNeededForSmithingLevel = XpNeededForSmithingLevel * 2.2;
	XpNeededForSmithingLevel = round(XpNeededForSmithingLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForSmithingLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(smithingLevel));
}

void AVrPlayerCharacter::DepositBronzeBar()
{
	if (playerCopperOre >= 1 && playerTinOre >= 1)
	{
		playerCopperOre--;
		playerTinOre--;
		playerBronzeBars++;
		playerWeight = playerWeight - 2;

		if (playerCopperOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 4)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
		if (playerTinOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 5)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveBronzeBars()
{
	if (playerCopperOre >= 5 && playerTinOre >= 5)
	{
		playerCopperOre = playerCopperOre - 5;
		playerTinOre = playerTinOre - 5;
		playerBronzeBars = playerBronzeBars + 5;
		playerWeight = playerWeight - 10;

		if (playerCopperOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 4)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
		if (playerTinOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 5)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenBronzeBars()
{
	if (playerCopperOre >= 10 && playerTinOre >= 10)
	{
		playerCopperOre = playerCopperOre - 10;
		playerTinOre = playerTinOre - 10;
		playerBronzeBars = playerBronzeBars + 10;
		playerWeight = playerWeight - 20;

		if (playerCopperOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 4)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
		if (playerTinOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 5)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

//Select what to craft
#pragma region
void AVrPlayerCharacter::SelectToCraftBronzeSword()
{
	isCraftingBronzeSword = true;
	isCraftingBronzeShield = false;
	isCraftingBronzeHelmet = false;
	isCraftingBronzePlateLegs = false;
	isCraftingBronzeChestPlate = false;
	isCraftingBronzeGloves = false;
	isCraftingBronzeBoots = false;
	isCraftingBronzeArrows = false;

	isCraftingIronSword = false;
	isCraftingIronShield = false;
	isCraftingIronHelmet = false;
	isCraftingIronPlateLegs = false;
	isCraftingIronChestPlate = false;
	isCraftingIronGloves = false;
	isCraftingIronBoots = false;
	isCraftingIronArrows = false;

	isCraftingSteelSword = false;
	isCraftingSteelShield = false;
	isCraftingSteelHelmet = false;
	isCraftingSteelPlateLegs = false;
	isCraftingSteelChestPlate = false;
	isCraftingSteelGloves = false;
	isCraftingSteelBoots = false;
	isCraftingSteelArrows = false;
}

void AVrPlayerCharacter::SelectToCraftBronzeShield()
{
	if (smithingLevel >= 5)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = true;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzeHelmet()
{
	if (smithingLevel >= 10)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = true;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzePlatelegs()
{
	if (smithingLevel >= 15)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = true;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzePlatebody()
{
	if (smithingLevel >= 20)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = true;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzeGloves()
{
	if (smithingLevel >= 25)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = true;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzeBoots()
{
	if (smithingLevel >= 25)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = true;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftBronzeArrowheads()
{
	isCraftingBronzeSword = false;
	isCraftingBronzeShield = false;
	isCraftingBronzeHelmet = false;
	isCraftingBronzePlateLegs = false;
	isCraftingBronzeChestPlate = false;
	isCraftingBronzeGloves = false;
	isCraftingBronzeBoots = false;
	isCraftingBronzeArrows = true;

	isCraftingIronSword = false;
	isCraftingIronShield = false;
	isCraftingIronHelmet = false;
	isCraftingIronPlateLegs = false;
	isCraftingIronChestPlate = false;
	isCraftingIronGloves = false;
	isCraftingIronBoots = false;
	isCraftingIronArrows = false;

	isCraftingSteelSword = false;
	isCraftingSteelShield = false;
	isCraftingSteelHelmet = false;
	isCraftingSteelPlateLegs = false;
	isCraftingSteelChestPlate = false;
	isCraftingSteelGloves = false;
	isCraftingSteelBoots = false;
	isCraftingSteelArrows = false;
}

void AVrPlayerCharacter::SelectToCraftIronSword()
{
	if (smithingLevel >= 30)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = true;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronShield()
{
	if (smithingLevel >= 35)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = true;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronHelmet()
{
	if (smithingLevel >= 40)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = true;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronPlatelegs()
{
	if (smithingLevel >= 45)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = true;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronPlatebody()
{
	if (smithingLevel >= 50)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = true;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronGloves()
{
	if (smithingLevel >= 55)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = true;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronBoots()
{
	if (smithingLevel >= 55)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = true;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftIronArrowheads()
{
	if (smithingLevel >= 30)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = true;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelSword()
{
	if (smithingLevel >= 60)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = true;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelShield()
{
	if (smithingLevel >= 65)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = true;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelHelmet()
{
	if (smithingLevel >= 70)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = true;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelPlatelegs()
{
	if (smithingLevel >= 75)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = true;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelPlatebody()
{
	if (smithingLevel >= 80)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = true;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelGloves()
{
	if (smithingLevel >= 85)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = true;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelBoots()
{
	if (smithingLevel >= 85)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = true;
		isCraftingSteelArrows = false;
	}
}

void AVrPlayerCharacter::SelectToCraftSteelArrowheads()
{
	if (smithingLevel >= 60)
	{
		isCraftingBronzeSword = false;
		isCraftingBronzeShield = false;
		isCraftingBronzeHelmet = false;
		isCraftingBronzePlateLegs = false;
		isCraftingBronzeChestPlate = false;
		isCraftingBronzeGloves = false;
		isCraftingBronzeBoots = false;
		isCraftingBronzeArrows = false;

		isCraftingIronSword = false;
		isCraftingIronShield = false;
		isCraftingIronHelmet = false;
		isCraftingIronPlateLegs = false;
		isCraftingIronChestPlate = false;
		isCraftingIronGloves = false;
		isCraftingIronBoots = false;
		isCraftingIronArrows = false;

		isCraftingSteelSword = false;
		isCraftingSteelShield = false;
		isCraftingSteelHelmet = false;
		isCraftingSteelPlateLegs = false;
		isCraftingSteelChestPlate = false;
		isCraftingSteelGloves = false;
		isCraftingSteelBoots = false;
		isCraftingSteelArrows = true;
	}
}
#pragma endregion

//craft functions
#pragma region
void AVrPlayerCharacter::CraftBronzeSword()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeSwords++;
		playerBronzeBars--;
		smithingXp = smithingXp + 25;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 16;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 16)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzePlateLegs()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzePlateLegs++;
		playerBronzeBars = playerBronzeBars - 4;
		smithingXp = smithingXp + 100;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 17;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 17)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeChestPlate()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeChestPlate++;
		playerBronzeBars = playerBronzeBars - 5;
		smithingXp = smithingXp + 125;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 18;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 18)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeShield()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeShield++;
		playerBronzeBars = playerBronzeBars - 3;
		smithingXp = smithingXp + 50;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 19;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 19)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeGloves()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeGloves++;
		playerBronzeBars = playerBronzeBars - 2;
		smithingXp = smithingXp + 50;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 20;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 20)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeBoots()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeBoots++;
		playerBronzeBars = playerBronzeBars - 2;
		smithingXp = smithingXp + 50;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 21;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 21)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeHelmet()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeHelmet++;
		playerBronzeBars = playerBronzeBars - 3;
		smithingXp = smithingXp + 75;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 22;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 22)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftBronzeArrow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerBronzeArrows++;
		playerBronzeBars--;
		playerArrowShafts--;
		smithingXp = smithingXp + 10;
		playerWeight = playerWeight + 1;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 23;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 23)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::DepositIronBar()
{
	if (playerIronOre >= 1)
	{
		playerIronOre--;
		playerIronBars++;
		playerWeight--;

		if (playerIronOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 6)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveIronBars()
{
	if (playerIronBars >= 5)
	{
		playerIronOre = playerIronOre - 5;
		playerIronBars = playerIronBars + 5;
		playerWeight = playerWeight - 5;

		if (playerIronOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 6)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenIronBars()
{
	if (playerIronBars >= 10)
	{
		playerIronOre = playerIronOre - 10;
		playerIronBars = playerIronBars + 10;
		playerWeight = playerWeight - 10;

		if (playerIronOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 6)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::CraftIronSword()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronSwords++;
		playerIronBars--;
		smithingXp = smithingXp + 100;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 24;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 24)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronPlateLegs()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronPlateLegs++;
		playerIronBars = playerIronBars - 4;
		smithingXp = smithingXp + 250;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 27;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 27)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronChestPlate()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronChestPlate++;
		playerIronBars = playerIronBars - 5;
		smithingXp = smithingXp + 300;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 28;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 28)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronShield()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronShield++;
		playerIronBars = playerIronBars - 3;
		smithingXp = smithingXp + 170;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 25;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 25)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronGloves()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronGloves++;
		playerIronBars = playerIronBars - 2;
		smithingXp = smithingXp + 130;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 29;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 29)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronBoots()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronBoots++;
		playerIronBars = playerIronBars - 2;
		smithingXp = smithingXp + 130;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 30;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 30)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronHelmet()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronHelmet++;
		playerIronBars = playerIronBars - 3;
		smithingXp = smithingXp + 170;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 26;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 26)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftIronArrow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerIronArrows++;
		playerIronBars--;
		smithingXp = smithingXp + 100;
		playerWeight = playerWeight + 1;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 31;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 31)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::DepositSteelBar()
{
	if (playerIronBars >= 1 && playerCoalOre >= 1)
	{
		playerIronBars--;
		playerCoalOre--;
		playerSteelBars++;
		playerWeight--;

		if (playerCoalOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 40)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveSteelBars()
{
	if (playerIronBars >= 5 && playerCoalOre >= 5)
	{
		playerIronBars = playerIronBars - 5;
		playerCoalOre = playerCoalOre - 5;
		playerSteelBars = playerSteelBars + 5;
		playerWeight = playerWeight - 5;

		if (playerCoalOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 40)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenSteelBars()
{
	if (playerIronBars >= 10 && playerCoalOre >= 10)
	{
		playerIronBars = playerIronBars - 10;
		playerCoalOre = playerCoalOre - 10;
		playerSteelBars = playerSteelBars + 10;
		playerWeight = playerWeight - 10;

		if (playerCoalOre >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 40)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::CraftSteelSword()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelSwords++;
		playerSteelBars--;
		smithingXp = smithingXp + 300;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 32;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 32)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelShield()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelShield++;
		playerSteelBars = playerSteelBars - 3;
		smithingXp = smithingXp + 500;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 33;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 33)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelHelmet()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelHelmet++;
		playerSteelBars = playerSteelBars - 3;
		smithingXp = smithingXp + 500;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 34;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 34)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelPlateLegs()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelPlateLegs++;
		playerSteelBars = playerSteelBars - 4;
		smithingXp = smithingXp + 600;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 35;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 35)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelChestPlate()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelChestPlate++;
		playerSteelBars = playerSteelBars - 5;
		smithingXp = smithingXp + 700;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 36;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 36)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelGloves()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelGloves++;
		playerSteelBars = playerSteelBars - 2;
		smithingXp = smithingXp + 400;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 37;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 37)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelBoots()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelBoots++;
		playerSteelBars = playerSteelBars - 2;
		smithingXp = smithingXp + 400;
		playerWeight = playerWeight + 5;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 38;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 38)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}

void AVrPlayerCharacter::CraftSteelArrow()
{
	if (playerWeight < playerMaxWeight)
	{
		playerSteelArrows++;
		playerSteelBars--;
		smithingXp = smithingXp + 300;
		playerWeight = playerWeight + 1;
	}
	if (smithingXp >= XpNeededForSmithingLevel)
	{
		LevelUpSmithing();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 39;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 39)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(smithingXp));
}
#pragma endregion

//cooking
void AVrPlayerCharacter::LevelUpCooking()
{
	cookingLevel++;
	XpNeededForCookingLevel = XpNeededForCookingLevel * 2.2;
	XpNeededForCookingLevel = round(XpNeededForCookingLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForCookingLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(cookingLevel));
}

void AVrPlayerCharacter::DepositShrimp()
{
	if (playerShrimp >= 1)
	{
		playerShrimp--;
		depositedShrimp++;
		playerWeight = playerWeight--;

		if (playerShrimp >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 7)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositAnchovies()
{
	if (playerAnchovies >= 1)
	{
		playerAnchovies--;
		depositedAnchovies++;
		playerWeight = playerWeight--;

		if (playerAnchovies >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 8)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTrout()
{
	if (playerTrout >= 1)
	{
		playerTrout--;
		depositedTrout++;
		playerWeight = playerWeight--;

		if (playerTrout >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 9)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveShrimp()
{
	if (playerShrimp >= 5)
	{
		playerShrimp = playerShrimp - 5;
		depositedShrimp = depositedShrimp + 5;
		playerWeight = playerWeight - 5;

		if (playerShrimp >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 7)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveAnchovies()
{
	if (playerAnchovies >= 5)
	{
		playerAnchovies = playerAnchovies - 5;
		depositedAnchovies = depositedAnchovies + 5;
		playerWeight = playerWeight - 5;

		if (playerAnchovies >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 8)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositFiveTrout()
{
	if (playerTrout >= 5)
	{
		playerTrout = playerTrout - 5;
		depositedTrout = depositedTrout + 5;
		playerWeight = playerWeight - 5;

		if (playerTrout >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 9)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenShrimp()
{
	if (playerShrimp >= 10)
	{
		playerShrimp = playerShrimp - 10;
		depositedShrimp = depositedShrimp + 10;
		playerWeight = playerWeight - 10;

		if (playerShrimp >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 7)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenAnchovies()
{
	if (playerAnchovies >= 10)
	{
		playerAnchovies = playerAnchovies - 10;
		depositedAnchovies = depositedAnchovies + 10;
		playerWeight = playerWeight - 10;

		if (playerAnchovies >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 8)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::DepositTenTrout()
{
	if (playerTrout >= 10)
	{
		playerTrout = playerTrout - 10;
		depositedTrout = depositedTrout + 10;
		playerWeight = playerWeight - 10;

		if (playerTrout >= 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (InventorySlots[i] == 9)
				{
					InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AVrPlayerCharacter::SelectToCookShrimp()
{
	isCookingShrimp = true;
	isCookingAnchovies = false;
	isCookingTrout = false;
}

void AVrPlayerCharacter::SelectToCookAnchovies()
{
	if (cookingLevel >= 15)
	{
		isCookingAnchovies = true;
		isCookingShrimp = false;
		isCookingTrout = false;
	}
}

void AVrPlayerCharacter::SelectToCookTrout()
{
	if (cookingLevel >= 30)
	{
		isCookingTrout = true;
		isCookingAnchovies = false;
		isCookingShrimp = false;
	}
}

void AVrPlayerCharacter::CookShrimp()
{
	if (playerWeight < playerMaxWeight)
	{
		playerCookedShrimp++;
		depositedShrimp--;
		cookingXP = cookingXP + 25;
		playerWeight = playerWeight + 1;
	}
	if (cookingXP >= XpNeededForCookingLevel)
	{
		LevelUpCooking();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 41;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 41)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(cookingXP));
}

void AVrPlayerCharacter::CookAnchovies()
{
	if (playerWeight < playerMaxWeight)
	{
		playerCookedAnchovies++;
		depositedAnchovies--;
		cookingXP = cookingXP + 50;
		playerWeight = playerWeight + 1;
	}
	if (cookingXP >= XpNeededForCookingLevel)
	{
		LevelUpCooking();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 42;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 42)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(cookingXP));
}

void AVrPlayerCharacter::CookTrout()
{
	if (playerWeight < playerMaxWeight)
	{
		playerCookedTrout++;
		depositedTrout--;
		cookingXP = cookingXP + 75;
		playerWeight = playerWeight + 1;
	}
	if (cookingXP >= XpNeededForCookingLevel)
	{
		LevelUpCooking();
	}
	for (int32 i = 0; i < 20; i++)
	{
		if (InventorySlots[i] == 0)
		{
			InventorySlots[i] = 43;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (InventorySlots[i] == 43)
		{
			break;
		}
		else
		{

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(cookingXP));
}

//Inventory
void AVrPlayerCharacter::DropItem()
{
	if (InventorySlots[InventorySlotInt] == 1)
	{
		playerWeight = playerWeight - playerLogs;
		playerLogs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 2)
	{
		playerWeight = playerWeight - playerOakLogs;
		playerOakLogs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 3)
	{
		playerWeight = playerWeight - playerWillowLogs;
		playerWillowLogs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 4)
	{
		playerWeight = playerWeight - playerCopperOre;
		playerCopperOre = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 5)
	{
		playerWeight = playerWeight - playerTinOre;
		playerTinOre = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 6)
	{
		playerWeight = playerWeight - playerIronOre;
		playerIronOre = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 7)
	{
		playerWeight = playerWeight - playerShrimp;
		playerShrimp = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 8)
	{
		playerWeight = playerWeight - playerAnchovies;
		playerAnchovies = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 9)
	{
		playerWeight = playerWeight - playerTrout;
		playerTrout = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 10)
	{
		playerWeight = playerWeight - playerBows * 5;
		playerBows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 11)
	{
		playerWeight = playerWeight - playerOakBows * 5;
		playerOakBows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 12)
	{
		playerWeight = playerWeight - playerWillowBows * 5;
		playerWillowBows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 13)
	{
		playerWeight = playerWeight - playerArrowShafts;
		playerArrowShafts = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 14)
	{
		playerWeight = playerWeight - playerOakArrowShafts;
		playerOakArrowShafts = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 15)
	{
		playerWeight = playerWeight - playerWillowArrowShafts;
		playerWillowArrowShafts = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 16)
	{
		playerWeight = playerWeight - playerBronzeSwords * 5;
		playerBronzeSwords = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 17)
	{
		playerWeight = playerWeight - playerBronzePlateLegs * 5;
		playerBronzePlateLegs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 18)
	{
		playerWeight = playerWeight - playerBronzeChestPlate * 5;
		playerBronzeChestPlate = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 19)
	{
		playerWeight = playerWeight - playerBronzeShield * 5;
		playerBronzeShield = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 20)
	{
		playerWeight = playerWeight - playerBronzeGloves * 5;
		playerBronzeGloves = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 21)
	{
		playerWeight = playerWeight - playerBronzeBoots * 5;
		playerBronzeBoots = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 22)
	{
		playerWeight = playerWeight - playerBronzeHelmet * 5;
		playerBronzeHelmet = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 23)
	{
		playerWeight = playerWeight - playerBronzeArrows;
		playerBronzeArrows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 24)
	{
		playerWeight = playerWeight - playerIronSwords * 5;
		playerIronSwords = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 25)
	{
		playerWeight = playerWeight - playerIronShield * 5;
		playerIronShield = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 26)
	{
		playerWeight = playerWeight - playerIronHelmet * 5;
		playerIronHelmet = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 27)
	{
		playerWeight = playerWeight - playerIronPlateLegs * 5;
		playerIronPlateLegs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 28)
	{
		playerWeight = playerWeight - playerIronChestPlate * 5;
		playerIronChestPlate = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 29)
	{
		playerWeight = playerWeight - playerIronGloves * 5;
		playerIronGloves = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 30)
	{
		playerWeight = playerWeight - playerIronBoots * 5;
		playerIronBoots = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 31)
	{
		playerWeight = playerWeight - playerIronArrows;
		playerIronArrows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 32)
	{
		playerWeight = playerWeight - playerSteelSwords * 5;
		playerSteelSwords = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 33)
	{
		playerWeight = playerWeight - playerSteelShield * 5;
		playerSteelShield = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 34)
	{
		playerWeight = playerWeight - playerSteelHelmet * 5;
		playerSteelHelmet = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 35)
	{
		playerWeight = playerWeight - playerSteelPlateLegs * 5;
		playerSteelPlateLegs = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 36)
	{
		playerWeight = playerWeight - playerSteelChestPlate * 5;
		playerSteelChestPlate = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 37)
	{
		playerWeight = playerWeight - playerSteelGloves * 5;
		playerSteelGloves = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 38)
	{
		playerWeight = playerWeight - playerSteelBoots * 5;
		playerSteelBoots = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 39)
	{
		playerWeight = playerWeight - playerSteelArrows;
		playerSteelArrows = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 40)
	{
		playerWeight = playerWeight - playerCoalOre;
		playerCoalOre = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 41)
	{
		playerWeight = playerWeight - playerCookedShrimp;
		playerCookedShrimp = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 42)
	{
		playerWeight = playerWeight - playerCookedAnchovies;
		playerCookedAnchovies = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
	else if (InventorySlots[InventorySlotInt] == 43)
	{
		playerWeight = playerWeight - playerCookedTrout;
		playerCookedTrout = 0;
		InventorySlots[InventorySlotInt] = 0;
	}
}

//Combat
//Skills
void AVrPlayerCharacter::LevelUpAttack()
{
	attackLevel++;
	xpNeededForAttackLevel = xpNeededForAttackLevel * 2.2;
	xpNeededForAttackLevel = round(xpNeededForAttackLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(xpNeededForAttackLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(attackLevel));
}

void AVrPlayerCharacter::LevelUpStrength()
{
	strengthLevel++;
	xpNeededForStrengthLevel = xpNeededForStrengthLevel * 2.2;
	xpNeededForStrengthLevel = round(xpNeededForStrengthLevel);

	playerDamage++;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(xpNeededForStrengthLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(strengthLevel));
}

void AVrPlayerCharacter::LevelUpDefence()
{
	defenceLevel++;
	xpNeededForDefenceLevel = xpNeededForDefenceLevel * 2.2;
	xpNeededForDefenceLevel = round(xpNeededForDefenceLevel);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(xpNeededForDefenceLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(defenceLevel));
}

void AVrPlayerCharacter::LevelUpConsitiution()
{
	constitutionLevel++;
	xpNeededForConstitutionLevel = xpNeededForConstitutionLevel * 2.2;
	xpNeededForConstitutionLevel = round(xpNeededForConstitutionLevel);

	playerHealth = playerHealth + 10;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(xpNeededForConstitutionLevel));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::FromInt(constitutionLevel));
}

//Combat reltaed
void AVrPlayerCharacter::EquipSword()
{
	if (equippedSwordType == 1)
	{
		playerDamage = playerDamage + 10;
		isBronzeSwordEquipped = true;
	}
	else if (equippedSwordType == 2)
	{
		playerDamage = playerDamage + 25;
		isIronSwordEquipped = true;
	}
	else if (equippedSwordType == 3)
	{
		playerDamage = playerDamage + 50;
		isSteelSwordEquipped = true;
	}
}

//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(XpNeededForWoodcuttingLevel));