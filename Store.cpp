// Fill out your copyright notice in the Description page of Project Settings.


#include "Store.h"

// Sets default values
AStore::AStore()
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
void AStore::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AStore::BeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AStore::EndOverlap);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AStore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStore::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("Player")))
	{
		Player->isInStore = true;
	}
}

void AStore::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag(FName("Player")))
	{
		Player->isInStore = false;
	}
}


//Player buying
void AStore::BuyLog()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerLogs++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 10;

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
	}
}

void AStore::BuyOakLog()
{
	if (Player->playerGoldCoins >= 25)
	{
		Player->playerOakLogs++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 25;

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
	}
}

void AStore::BuyWillowLog()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerWillowLogs++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyCopperOre()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerCopperOre++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 10;

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
	}
}

void AStore::BuyTinOre()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerTinOre++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 10;

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
	}
}

void AStore::BuyIronOre()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerIronOre++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 25;

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
	}
}

void AStore::BuyCoalOre()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerCoalOre++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyShrimp()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerShrimp++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 10;

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
	}
}

void AStore::BuyAnchovies()
{
	if (Player->playerGoldCoins >= 25)
	{
		Player->playerAnchovies++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 25;

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
	}
}

void AStore::BuyTrout()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerTrout++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBow()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerBows++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyOakBow()
{
	if (Player->playerGoldCoins >= 500)
	{
		Player->playerOakBows++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 500;

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
	}
}

void AStore::BuyWillowBow()
{
	if (Player->playerGoldCoins >= 2000)
	{
		Player->playerWillowBows++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 2000;

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
	}
}

void AStore::BuyBronzeSword()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeSwords++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzeShield()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeShield++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzeHelmet()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeHelmet++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzePlatelegs()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzePlateLegs++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzePlatebody()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeChestPlate++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzeGloves()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeGloves++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzeBoots()
{
	if (Player->playerGoldCoins >= 50)
	{
		Player->playerBronzeBoots++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}

void AStore::BuyBronzeArrow()
{
	if (Player->playerGoldCoins >= 10)
	{
		Player->playerBronzeArrows++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 10;

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
	}
}

void AStore::BuyIronSword()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronSwords++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronShield()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronShield++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronHelmet()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronShield++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronPlatelegs()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronPlateLegs++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronPlatebody()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronChestPlate++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronGloves()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronGloves++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronBoots()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronBoots++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 200;

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
	}
}

void AStore::BuyIronArrow()
{
	if (Player->playerGoldCoins >= 200)
	{
		Player->playerIronArrows++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 25;

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
	}
}

void AStore::BuySteelSword()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelSwords++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelShield()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelShield++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelHelmet()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelHelmet++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelPlatelegs()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelPlateLegs++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelPlatebody()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelChestPlate++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelGloves()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelGloves++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelBoots()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelBoots++;
		Player->playerWeight = Player->playerWeight + 5;
		Player->playerGoldCoins = Player->playerGoldCoins - 1000;

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
	}
}

void AStore::BuySteelArrows()
{
	if (Player->playerGoldCoins >= 1000)
	{
		Player->playerSteelArrows++;
		Player->playerWeight++;
		Player->playerGoldCoins = Player->playerGoldCoins - 50;

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
	}
}


//Player selling
void AStore::SellLog()
{
	if (Player->playerLogs > 0)
	{
		Player->playerLogs--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 5;

		//If logs = 0 go through player inventory and set the slot with logs to empty
		if (Player->playerLogs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 1)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellOakLog()
{
	if (Player->playerOakLogs > 0)
	{
		Player->playerOakLogs--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 10;

		if (Player->playerOakLogs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 2)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellWillowLog()
{
	if (Player->playerWillowLogs > 0)
	{
		Player->playerWillowLogs--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerWillowLogs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 3)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellCopperOre()
{
	if (Player->playerCopperOre > 0)
	{
		Player->playerCopperOre--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 5;

		if (Player->playerCopperOre == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 4)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellTinOre()
{
	if (Player->playerTinOre > 0)
	{
		Player->playerTinOre--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 5;

		if (Player->playerTinOre == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 5)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronOre()
{
	if (Player->playerIronOre > 0)
	{
		Player->playerIronOre--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 10;

		if (Player->playerIronOre == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 6)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellCoalOre()
{
	if (Player->playerCoalOre > 0)
	{
		Player->playerCoalOre--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerCoalOre == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 40)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellShrimp()
{
	if (Player->playerShrimp > 0)
	{
		Player->playerShrimp--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 5;

		if (Player->playerShrimp == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 7)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellAnchovies()
{
	if (Player->playerLogs > 0)
	{
		Player->playerLogs--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 10;

		if (Player->playerAnchovies == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 8)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellTrout()
{
	if (Player->playerTrout > 0)
	{
		Player->playerTrout--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerTrout == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 9)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBow()
{
	if (Player->playerBows > 0)
	{
		Player->playerBows--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 10;

		if (Player->playerBows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 10)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellOakBow()
{
	if (Player->playerOakBows > 0)
	{
		Player->playerOakBows--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerOakBows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 11)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellWillowBow()
{
	if (Player->playerWillowBows > 0)
	{
		Player->playerWillowBows--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 100;

		if (Player->playerWillowBows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 12)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeSword()
{
	if (Player->playerBronzeSwords > 0)
	{
		Player->playerBronzeSwords--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeSwords == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 16)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeShield()
{
	if (Player->playerBronzeShield > 0)
	{
		Player->playerBronzeShield--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeShield == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 19)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeHelmet()
{
	if (Player->playerBronzeHelmet > 0)
	{
		Player->playerBronzeHelmet--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeHelmet == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 22)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzePlatelegs()
{
	if (Player->playerBronzePlateLegs > 0)
	{
		Player->playerBronzePlateLegs--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzePlateLegs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 17)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzePlatebody()
{
	if (Player->playerBronzeChestPlate > 0)
	{
		Player->playerBronzeChestPlate--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeChestPlate == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 18)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeGloves()
{
	if (Player->playerBronzeGloves > 0)
	{
		Player->playerBronzeGloves--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeGloves == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 20)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeBoots()
{
	if (Player->playerBronzeBoots > 0)
	{
		Player->playerBronzeBoots--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 20;

		if (Player->playerBronzeBoots == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 21)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellBronzeArrow()
{
	if (Player->playerBronzeArrows > 0)
	{
		Player->playerBronzeArrows--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 2;

		if (Player->playerBronzeArrows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 23)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronSword()
{
	if (Player->playerIronSwords > 0)
	{
		Player->playerIronSwords--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronSwords == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 24)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronShield()
{
	if (Player->playerIronShield > 0)
	{
		Player->playerIronShield = Player->playerIronShield--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronShield == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 25)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronHelmet()
{
	if (Player->playerIronHelmet > 0)
	{
		Player->playerIronHelmet--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronHelmet == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 26)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronPlatelegs()
{
	if (Player->playerIronPlateLegs > 0)
	{
		Player->playerIronPlateLegs--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronPlateLegs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 27)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronPlatebody()
{
	if (Player->playerIronChestPlate > 0)
	{
		Player->playerIronChestPlate--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronChestPlate == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 28)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronGloves()
{
	if (Player->playerIronHelmet > 0)
	{
		Player->playerIronHelmet--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronGloves == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 29)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronBoots()
{
	if (Player->playerIronBoots > 0)
	{
		Player->playerIronBoots--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 50;

		if (Player->playerIronBoots == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 30)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellIronArrow()
{
	if (Player->playerIronArrows > 0)
	{
		Player->playerIronArrows--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 5;

		if (Player->playerIronArrows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 31)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelSword()
{
	if (Player->playerSteelSwords > 0)
	{
		Player->playerSteelSwords--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;

		if (Player->playerSteelSwords == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 32)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelShield()
{
	if (Player->playerSteelShield > 0)
	{
		Player->playerSteelShield--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelShield == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 33)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelHelmet()
{
	if (Player->playerSteelHelmet > 0)
	{
		Player->playerSteelHelmet--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelHelmet == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 34)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelPlatelegs()
{
	if (Player->playerSteelPlateLegs > 0)
	{
		Player->playerSteelPlateLegs--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelPlateLegs == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 35)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelPlatebody()
{
	if (Player->playerSteelChestPlate > 0)
	{
		Player->playerSteelChestPlate--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelChestPlate == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 36)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelGloves()
{
	if (Player->playerSteelGloves > 0)
	{
		Player->playerSteelGloves--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelGloves == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 37)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelBoots()
{
	if (Player->playerSteelBoots > 0)
	{
		Player->playerSteelBoots--;
		Player->playerWeight = Player->playerWeight - 5;
		Player->playerGoldCoins = Player->playerGoldCoins + 150;


		if (Player->playerSteelBoots == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 38)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}

void AStore::SellSteelArrows()
{
	if (Player->playerSteelArrows > 0)
	{
		Player->playerSteelArrows--;
		Player->playerWeight--;
		Player->playerGoldCoins = Player->playerGoldCoins + 10;


		if (Player->playerSteelArrows == 0)
		{
			for (int32 i = 0; i < 20; i++)
			{
				if (Player->InventorySlots[i] == 39)
				{
					Player->InventorySlots[i] = 0;
					break;
				}
			}
		}
	}
}