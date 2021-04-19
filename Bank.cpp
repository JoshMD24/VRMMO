// Fill out your copyright notice in the Description page of Project Settings.

#include "Bank.h"

// Sets default values
ABank::ABank()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	SetRootComponent(Root);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBoxComp"));
	BoxComp->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	BoxComp->CanCharacterStepUpOn = ECB_No;
	BoxComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABank::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABank::BeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &ABank::EndOverlap);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ABank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABank::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("Player")))
	{
		Player->isInBank = true;
	}
}

void ABank::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag(FName("Player")))
	{
		Player->isInBank = false;
	}
}

//Add resources to the bank then remove the weight and the items from the player and set the inventory slot to empty
void ABank::DepositItem()
{
	if (Player->hasDepositedItem == false)
	{
		Player->CompletedDepositItemTutorial();
	}

	if (Player->InventorySlots[Player->InventorySlotInt] == 1)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 1;
				break;
			}
			else if (BankSlots[i] == 1)
			{
				break;
			}
		}
		depositedLogs = Player->playerLogs;
		Player->playerWeight = Player->playerWeight - Player->playerLogs;
		Player->playerLogs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 2)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 2;
				break;
			}
			else if (BankSlots[i] == 2)
			{
				break;
			}
		}
		depositedOakLogs = Player->playerOakLogs;
		Player->playerWeight = Player->playerWeight - Player->playerOakLogs;
		Player->playerOakLogs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 3)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 3;
				break;
			}
			else if (BankSlots[i] == 3)
			{
				break;
			}
		}
		depositedWillowLogs = Player->playerWillowLogs;
		Player->playerWeight = Player->playerWeight - Player->playerWillowLogs;
		Player->playerWillowLogs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 4)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 4;
				break;
			}
			else if (BankSlots[i] == 4)
			{
				break;
			}
		}
		depositedCopperOre = Player->playerCopperOre;
		Player->playerWeight = Player->playerWeight - Player->playerCopperOre;
		Player->playerCopperOre = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 5)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 5;
				break;
			}
			else if (BankSlots[i] == 5)
			{
				break;
			}
		}
		depositedTinOre = Player->playerTinOre;
		Player->playerWeight = Player->playerWeight - Player->playerTinOre;
		Player->playerTinOre = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 6)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 6;
				break;
			}
			else if (BankSlots[i] == 6)
			{
				break;
			}
		}
		depositedIronOre = Player->playerIronOre;
		Player->playerWeight = Player->playerWeight - Player->playerIronOre;
		Player->playerIronOre = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 7)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 7;
				break;
			}
			else if (BankSlots[i] == 7)
			{
				break;
			}
		}
		depositedShrimp = Player->playerShrimp;
		Player->playerWeight = Player->playerWeight - Player->playerShrimp;
		Player->playerShrimp = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 8)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 8;
				break;
			}
			else if (BankSlots[i] == 8)
			{
				break;
			}
		}
		depositedAnchovies = Player->playerAnchovies;
		Player->playerWeight = Player->playerWeight - Player->playerAnchovies;
		Player->playerAnchovies = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 9)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 9;
				break;
			}
			else if (BankSlots[i] == 9)
			{
				break;
			}
		}
		depositedTrout = Player->playerTrout;
		Player->playerWeight = Player->playerWeight - Player->playerTrout;
		Player->playerTrout = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 10)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 10;
				break;
			}
			else if (BankSlots[i] == 10)
			{
				break;
			}
		}
		depositedBow = Player->playerBows;
		Player->playerWeight = Player->playerWeight - Player->playerBows * 5;
		Player->playerBows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 11)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 11;
				break;
			}
			else if (BankSlots[i] == 11)
			{
				break;
			}
		}
		depositedOakBow = Player->playerOakBows;
		Player->playerWeight = Player->playerWeight - Player->playerOakBows * 5;
		Player->playerOakBows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 12)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 12;
				break;
			}
			else if (BankSlots[i] == 12)
			{
				break;
			}
		}
		depositedWillowBow = Player->playerWillowBows;
		Player->playerWeight = Player->playerWeight - Player->playerWillowBows * 5;
		Player->playerWillowBows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 13)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 13;
				break;
			}
			else if (BankSlots[i] == 13)
			{
				break;
			}
		}
		depositedArrowShaft = Player->playerArrowShafts;
		Player->playerWeight = Player->playerWeight - Player->playerArrowShafts;
		Player->playerArrowShafts = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 14)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 14;
				break;
			}
			else if (BankSlots[i] == 14)
			{
				break;
			}
		}
		depositedOakArrowShaft = Player->playerOakArrowShafts;
		Player->playerWeight = Player->playerWeight - Player->playerOakArrowShafts;
		Player->playerOakArrowShafts = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 15)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 15;
				break;
			}
			else if (BankSlots[i] == 15)
			{
				break;
			}
		}
		depositedWillowArrowShaft = Player->playerWillowArrowShafts;
		Player->playerWeight = Player->playerWeight - Player->playerWillowArrowShafts;
		Player->playerWillowArrowShafts = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 16)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 16;
				break;
			}
			else if (BankSlots[i] == 16)
			{
				break;
			}
		}
		depositedBronzeSword = Player->playerBronzeSwords;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeSwords * 5;
		Player->playerBronzeSwords = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 17)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 17;
				break;
			}
			else if (BankSlots[i] == 17)
			{
				break;
			}
		}
		depositedBronzePlatelegs = Player->playerBronzePlateLegs;
		Player->playerWeight = Player->playerWeight - Player->playerBronzePlateLegs * 5;
		Player->playerBronzePlateLegs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 18)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 18;
				break;
			}
			else if (BankSlots[i] == 18)
			{
				break;
			}
		}
		depositedBronzePlatebody = Player->playerBronzeChestPlate;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeChestPlate * 5;
		Player->playerBronzeChestPlate = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 19)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 19;
				break;
			}
			else if (BankSlots[i] == 19)
			{
				break;
			}
		}
		depositedBronzeShield = Player->playerBronzeShield;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeShield * 5;
		Player->playerBronzeShield = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 20)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 20;
				break;
			}
			else if (BankSlots[i] == 20)
			{
				break;
			}
		}
		depositedBronzeGloves = Player->playerBronzeGloves;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeGloves * 5;
		Player->playerBronzeGloves = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 21)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 21;
				break;
			}
			else if (BankSlots[i] == 21)
			{
				break;
			}
	}
		depositedBronzeBoots = Player->playerBronzeBoots;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeBoots * 5;
		Player->playerBronzeBoots = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 22)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 22;
				break;
			}
			else if (BankSlots[i] == 22)
			{
				break;
			}
		}
		depositedBronzeHelmet = Player->playerBronzeHelmet;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeHelmet * 5;
		Player->playerBronzeHelmet = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 23)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 23;
				break;
			}
			else if (BankSlots[i] == 23)
			{
				break;
			}
		}
		depositedBronzeArrows = Player->playerBronzeArrows;
		Player->playerWeight = Player->playerWeight - Player->playerBronzeArrows;
		Player->playerBronzeArrows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 24)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 24;
				break;
			}
			else if (BankSlots[i] == 24)
			{
				break;
			}
		}
		depositedIronSword = Player->playerIronSwords;
		Player->playerWeight = Player->playerWeight - Player->playerIronSwords * 5;
		Player->playerIronSwords = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 25)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 25;
				break;
			}
			else if (BankSlots[i] == 25)
			{
				break;
			}
		}
		depositedIronShield = Player->playerIronShield;
		Player->playerWeight = Player->playerWeight - Player->playerIronShield * 5;
		Player->playerIronShield = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 26)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 26;
				break;
			}
			else if (BankSlots[i] == 26)
			{
				break;
			}
		}
		depositedIronHelmet = Player->playerIronHelmet;
		Player->playerWeight = Player->playerWeight - Player->playerIronHelmet * 5;
		Player->playerIronHelmet = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 27)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 27;
				break;
			}
			else if (BankSlots[i] == 27)
			{
				break;
			}
		}
		depositedIronPlatelegs = Player->playerIronPlateLegs;
		Player->playerWeight = Player->playerWeight - Player->playerIronPlateLegs * 5;
		Player->playerIronPlateLegs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 28)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 28;
				break;
			}
			else if (BankSlots[i] == 28)
			{
				break;
			}
		}
		depositedIronPlatebody = Player->playerIronChestPlate;
		Player->playerWeight = Player->playerWeight - Player->playerIronChestPlate * 5;
		Player->playerIronChestPlate = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 29)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 29;
				break;
			}
			else if (BankSlots[i] == 29)
			{
				break;
			}
		}
		depositedIronGloves = Player->playerIronGloves;
		Player->playerWeight = Player->playerWeight - Player->playerIronGloves * 5;
		Player->playerIronGloves = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 30)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 30;
				break;
			}
			else if (BankSlots[i] == 30)
			{
				break;
			}
		}
		depositedIronBoots = Player->playerIronBoots;
		Player->playerWeight = Player->playerWeight - Player->playerIronBoots * 5;
		Player->playerIronBoots = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 31)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 31;
				break;
			}
			else if (BankSlots[i] == 31)
			{
				break;
			}
		}
		depositedIronArrows = Player->playerIronArrows;
		Player->playerWeight = Player->playerWeight - Player->playerIronArrows;
		Player->playerIronArrows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 32)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 32;
				break;
			}
			else if (BankSlots[i] == 32)
			{
				break;
			}
		}
		depositedSteelSword = Player->playerSteelSwords;
		Player->playerWeight = Player->playerWeight - Player->playerSteelSwords * 5;
		Player->playerSteelSwords = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 33)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 33;
				break;
			}
			else if (BankSlots[i] == 33)
			{
				break;
			}
		}
		depositedSteelShield = Player->playerSteelShield;
		Player->playerWeight = Player->playerWeight - Player->playerSteelShield * 5;
		Player->playerSteelShield = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 34)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 34;
				break;
			}
			else if (BankSlots[i] == 34)
			{
				break;
			}
		}
		depositedSteelHelmet = Player->playerSteelHelmet;
		Player->playerWeight = Player->playerWeight - Player->playerSteelHelmet * 5;
		Player->playerSteelHelmet = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 35)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 35;
				break;
			}
			else if (BankSlots[i] == 35)
			{
				break;
			}
		}
		depositedSteelPlatelegs = Player->playerSteelPlateLegs;
		Player->playerWeight = Player->playerWeight - Player->playerSteelPlateLegs * 5;
		Player->playerSteelPlateLegs = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 36)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 36;
				break;
			}
			else if (BankSlots[i] == 36)
			{
				break;
			}
		}
		depositedCopperOre = Player->playerCopperOre;
		Player->playerWeight = Player->playerWeight - Player->playerSteelChestPlate * 5;
		Player->playerSteelChestPlate = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 37)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 37;
				break;
			}
			else if (BankSlots[i] == 37)
			{
				break;
			}
		}
		depositedSteelGloves = Player->playerSteelGloves;
		Player->playerWeight = Player->playerWeight - Player->playerSteelGloves * 5;
		Player->playerSteelGloves = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 38)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 38;
				break;
			}
			else if (BankSlots[i] == 38)
			{
				break;
			}
		}
		depositedSteelBoots = Player->playerSteelBoots;
		Player->playerWeight = Player->playerWeight - Player->playerSteelBoots * 5;
		Player->playerSteelBoots = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 39)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 39;
				break;
			}
			else if (BankSlots[i] == 39)
			{
				break;
			}
		}
		depositedSteelArrows = Player->playerSteelArrows;
		Player->playerWeight = Player->playerWeight - Player->playerSteelArrows;
		Player->playerSteelArrows = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 40)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 40;
				break;
			}
			else if (BankSlots[i] == 40)
			{
				break;
			}
		}
		depositedCoalOre = Player->playerCoalOre;
		Player->playerWeight = Player->playerWeight - Player->playerCoalOre;
		Player->playerCoalOre = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 41)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 41;
				break;
			}
			else if (BankSlots[i] == 41)
			{
				break;
			}
		}
		depositedCookedShrimp = Player->playerCookedShrimp;
		Player->playerWeight = Player->playerWeight - Player->playerCookedShrimp;
		Player->playerCookedShrimp = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 42)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 42;
				break;
			}
			else if (BankSlots[i] == 42)
			{
				break;
			}
		}
		depositedCookedAnchovies = Player->playerCookedAnchovies;
		Player->playerWeight = Player->playerWeight - Player->playerCookedAnchovies;
		Player->playerCookedAnchovies = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
	else if (Player->InventorySlots[Player->InventorySlotInt] == 43)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (BankSlots[i] == 0)
			{
				BankSlots[i] = 43;
				break;
			}
			else if (BankSlots[i] == 43)
			{
				break;
			}
		}
		depositedCookedTrout = Player->playerCookedTrout;
		Player->playerWeight = Player->playerWeight - Player->playerCookedTrout;
		Player->playerCookedTrout = 0;
		Player->InventorySlots[Player->InventorySlotInt] = 0;
	}
}

void ABank::WithdrawItem()
{
	if (Player->hasWithdrawnItem == false)
	{
		Player->CompletedWithdrawTutorial();
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
	if (BankSlots[BankSlotInt] == 1)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 1;
				break;
			}
			else if (Player->InventorySlots[i] == 1)
			{
				break;
			}
		}
		Player->playerLogs = depositedLogs;
		Player->playerWeight = Player->playerWeight + depositedLogs;
		depositedLogs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 2)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 2;
				break;
			}
			else if (Player->InventorySlots[i] == 2)
			{
				break;
			}
		}
		Player->playerOakLogs = depositedOakLogs;
		Player->playerWeight = Player->playerWeight + depositedOakLogs;
		depositedOakLogs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 3)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 3;
				break;
			}
			else if (Player->InventorySlots[i] == 3)
			{
				break;
			}
		}
		Player->playerWillowLogs = depositedWillowLogs;
		Player->playerWeight = Player->playerWeight + depositedWillowLogs;
		depositedWillowLogs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 4)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 4;
				break;
			}
			else if (Player->InventorySlots[i] == 4)
			{
				break;
			}
		}
		Player->playerCopperOre = depositedCopperOre;
		Player->playerWeight = Player->playerWeight + depositedCopperOre;
		depositedCopperOre = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 5)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 5;
				break;
			}
			else if (Player->InventorySlots[i] == 5)
			{
				break;
			}
		}
		Player->playerTinOre = depositedTinOre;
		Player->playerWeight = Player->playerWeight + depositedTinOre;
		depositedTinOre = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 6)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 6;
				break;
			}
			else if (Player->InventorySlots[i] == 6)
			{
				break;
			}
		}
		Player->playerIronOre = depositedIronOre;
		Player->playerWeight = Player->playerWeight + depositedIronOre;
		depositedIronOre = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 7)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 7;
				break;
			}
			else if (Player->InventorySlots[i] == 7)
			{
				break;
			}
		}
		Player->playerShrimp = depositedShrimp;
		Player->playerWeight = Player->playerWeight + depositedShrimp;
		depositedShrimp = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 8)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 8;
				break;
			}
			else if (Player->InventorySlots[i] == 8)
			{
				break;
			}
		}
		Player->playerAnchovies = depositedAnchovies;
		Player->playerWeight = Player->playerWeight + depositedAnchovies;
		depositedAnchovies = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 9)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 9;
				break;
			}
			else if (Player->InventorySlots[i] == 9)
			{
				break;
			}
		}
		Player->playerTrout = depositedTrout;
		Player->playerWeight = Player->playerWeight + depositedTrout;
		depositedTrout = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 10)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 10;
				break;
			}
			else if (Player->InventorySlots[i] == 10)
			{
				break;
			}
		}
		Player->playerBows = depositedBow;
		Player->playerWeight = Player->playerWeight + depositedBow;
		depositedBow = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 11)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 11;
				break;
			}
			else if (Player->InventorySlots[i] == 11)
			{
				break;
			}
		}
		Player->playerOakBows = depositedOakBow;
		Player->playerWeight = Player->playerWeight + depositedOakBow;
		depositedOakBow = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 12)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 12;
				break;
			}
			else if (Player->InventorySlots[i] == 12)
			{
				break;
			}
		}
		Player->playerWillowBows = depositedWillowBow;
		Player->playerWeight = Player->playerWeight + depositedWillowBow;
		depositedWillowBow = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 13)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 13;
				break;
			}
			else if (Player->InventorySlots[i] == 13)
			{
				break;
			}
		}
		Player->playerArrowShafts = depositedArrowShaft;
		Player->playerWeight = Player->playerWeight + depositedArrowShaft;
		depositedArrowShaft = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 14)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 14;
				break;
			}
			else if (Player->InventorySlots[i] == 14)
			{
				break;
			}
		}
		Player->playerOakArrowShafts = depositedOakArrowShaft;
		Player->playerWeight = Player->playerWeight + depositedOakArrowShaft;
		depositedOakArrowShaft = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 15)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 15;
				break;
			}
			else if (Player->InventorySlots[i] == 15)
			{
				break;
			}
		}
		Player->playerWillowArrowShafts = depositedWillowArrowShaft;
		Player->playerWeight = Player->playerWeight + depositedWillowArrowShaft;
		depositedWillowArrowShaft = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 16)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 16;
				break;
			}
			else if (Player->InventorySlots[i] == 16)
			{
				break;
			}
		}
		Player->playerBronzeSwords = depositedBronzeSword;
		Player->playerWeight = Player->playerWeight + depositedBronzeSword;
		depositedBronzeSword = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 17)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 17;
				break;
			}
			else if (Player->InventorySlots[i] == 17)
			{
				break;
			}
		}
		Player->playerBronzePlateLegs = depositedBronzePlatelegs;
		Player->playerWeight = Player->playerWeight + depositedBronzePlatelegs;
		depositedBronzePlatelegs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 18)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 18;
				break;
			}
			else if (Player->InventorySlots[i] == 18)
			{
				break;
			}
		}
		Player->playerBronzeChestPlate = depositedBronzePlatebody;
		Player->playerWeight = Player->playerWeight + depositedBronzePlatebody;
		depositedBronzePlatebody = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 19)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 19;
				break;
			}
			else if (Player->InventorySlots[i] == 19)
			{
				break;
			}
		}
		Player->playerBronzeShield = depositedBronzeShield;
		Player->playerWeight = Player->playerWeight + depositedBronzeShield;
		depositedBronzeShield = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 20)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 20;
				break;
			}
			else if (Player->InventorySlots[i] == 20)
			{
				break;
			}
		}
		Player->playerBronzeGloves = depositedBronzeGloves;
		Player->playerWeight = Player->playerWeight + depositedBronzeGloves;
		depositedBronzeGloves = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 21)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 21;
				break;
			}
			else if (Player->InventorySlots[i] == 21)
			{
				break;
			}
		}
		Player->playerBronzeBoots = depositedBronzeBoots;
		Player->playerWeight = Player->playerWeight + depositedBronzeBoots;
		depositedBronzeBoots = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 22)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 22;
				break;
			}
			else if (Player->InventorySlots[i] == 22)
			{
				break;
			}
		}
		Player->playerBronzeHelmet = depositedBronzeHelmet;
		Player->playerWeight = Player->playerWeight + depositedBronzeHelmet;
		depositedBronzeHelmet = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 23)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 23;
				break;
			}
			else if (Player->InventorySlots[i] == 23)
			{
				break;
			}
		}
		Player->playerBronzeArrows = depositedBronzeArrows;
		Player->playerWeight = Player->playerWeight + depositedBronzeArrows;
		depositedBronzeArrows = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 24)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 24;
				break;
			}
			else if (Player->InventorySlots[i] == 24)
			{
				break;
			}
		}
		Player->playerIronSwords = depositedIronSword;
		Player->playerWeight = Player->playerWeight + depositedIronSword;
		depositedIronSword = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 25)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 25;
				break;
			}
			else if (Player->InventorySlots[i] == 25)
			{
				break;
			}
		}
		Player->playerIronShield = depositedIronShield;
		Player->playerWeight = Player->playerWeight + depositedIronShield;
		depositedIronShield = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 26)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 26;
				break;
			}
			else if (Player->InventorySlots[i] == 26)
			{
				break;
			}
		}
		Player->playerIronHelmet = depositedIronHelmet;
		Player->playerWeight = Player->playerWeight + depositedIronHelmet;
		depositedIronHelmet = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 27)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 27;
				break;
			}
			else if (Player->InventorySlots[i] == 27)
			{
				break;
			}
		}
		Player->playerIronPlateLegs = depositedIronPlatelegs;
		Player->playerWeight = Player->playerWeight + depositedIronPlatelegs;
		depositedIronPlatelegs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 28)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 28;
				break;
			}
			else if (Player->InventorySlots[i] == 28)
			{
				break;
			}
		}
		Player->playerIronChestPlate = depositedIronPlatebody;
		Player->playerWeight = Player->playerWeight + depositedIronPlatebody;
		depositedIronPlatebody = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 29)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 29;
				break;
			}
			else if (Player->InventorySlots[i] == 29)
			{
				break;
			}
		}
		Player->playerIronGloves = depositedIronGloves;
		Player->playerWeight = Player->playerWeight + depositedIronGloves;
		depositedIronGloves = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 30)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 30;
				break;
			}
			else if (Player->InventorySlots[i] == 30)
			{
				break;
			}
		}
		Player->playerIronBoots = depositedIronBoots;
		Player->playerWeight = Player->playerWeight + depositedIronBoots;
		depositedIronBoots = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 31)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 31;
				break;
			}
			else if (Player->InventorySlots[i] == 31)
			{
				break;
			}
		}
		Player->playerIronArrows = depositedIronArrows;
		Player->playerWeight = Player->playerWeight + depositedIronArrows;
		depositedIronArrows = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 32)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 32;
				break;
			}
			else if (Player->InventorySlots[i] == 32)
			{
				break;
			}
		}
		Player->playerSteelSwords = depositedSteelSword;
		Player->playerWeight = Player->playerWeight + depositedSteelSword;
		depositedSteelSword = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 33)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 33;
				break;
			}
			else if (Player->InventorySlots[i] == 33)
			{
				break;
			}
		}
		Player->playerSteelShield = depositedSteelShield;
		Player->playerWeight = Player->playerWeight + depositedSteelShield;
		depositedSteelShield = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 34)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 34;
				break;
			}
			else if (Player->InventorySlots[i] == 34)
			{
				break;
			}
		}
		Player->playerSteelHelmet = depositedSteelHelmet;
		Player->playerWeight = Player->playerWeight + depositedSteelHelmet;
		depositedSteelHelmet = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 35)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 35;
				break;
			}
			else if (Player->InventorySlots[i] == 35)
			{
				break;
			}
		}
		Player->playerSteelPlateLegs = depositedSteelPlatelegs;
		Player->playerWeight = Player->playerWeight + depositedSteelPlatelegs;
		depositedSteelPlatelegs = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 36)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 36;
				break;
			}
			else if (Player->InventorySlots[i] == 36)
			{
				break;
			}
		}
		Player->playerSteelChestPlate = depositedSteelPlatebody;
		Player->playerWeight = Player->playerWeight + depositedSteelPlatebody;
		depositedSteelPlatebody = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 37)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 37;
				break;
			}
			else if (Player->InventorySlots[i] == 37)
			{
				break;
			}
		}
		Player->playerSteelGloves = depositedSteelGloves;
		Player->playerWeight = Player->playerWeight + depositedSteelGloves;
		depositedSteelGloves = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 38)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 38;
				break;
			}
			else if (Player->InventorySlots[i] == 38)
			{
				break;
			}
		}
		Player->playerSteelBoots = depositedSteelBoots;
		Player->playerWeight = Player->playerWeight + depositedSteelBoots;
		depositedSteelBoots = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 39)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 39;
				break;
			}
			else if (Player->InventorySlots[i] == 39)
			{
				break;
			}
		}
		Player->playerSteelArrows = depositedSteelArrows;
		Player->playerWeight = Player->playerWeight + depositedSteelArrows;
		depositedSteelArrows = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 40)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 40;
				break;
			}
		else if (Player->InventorySlots[i] == 40)
		{
			break;
		}
	}
		Player->playerCoalOre = depositedCoalOre;
		Player->playerWeight = Player->playerWeight + depositedCoalOre;
		depositedCoalOre = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 41)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 41;
				break;
			}
			else if (Player->InventorySlots[i] == 41)
			{
				break;
			}
		}
		Player->playerCookedShrimp = depositedCookedShrimp;
		Player->playerWeight = Player->playerWeight + depositedCookedShrimp;
		depositedCookedShrimp = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 42)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 42;
				break;
			}
			else if (Player->InventorySlots[i] == 42)
			{
				break;
			}
		}
		Player->playerCookedAnchovies = depositedCookedAnchovies;
		Player->playerWeight = Player->playerWeight + depositedCookedAnchovies;
		depositedCookedAnchovies = 0;
		BankSlots[BankSlotInt] = 0;
	}
	else if (BankSlots[BankSlotInt] == 43)
	{
		for (int32 i = 0; i < 20; i++)
		{
			if (Player->InventorySlots[i] == 0)
			{
				Player->InventorySlots[i] = 43;
				break;
			}
			else if (Player->InventorySlots[i] == 43)
			{
				break;
			}
		}
		Player->playerCookedTrout = depositedCookedTrout;
		Player->playerWeight = Player->playerWeight + depositedCookedTrout;
		depositedCookedTrout = 0;
		BankSlots[BankSlotInt] = 0;
	}
}
