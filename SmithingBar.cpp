// Fill out your copyright notice in the Description page of Project Settings.


#include "SmithingBar.h"

// Sets default values
ASmithingBar::ASmithingBar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	hitsUntilHammered = 4;
}

// Called when the game starts or when spawned
void ASmithingBar::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ASmithingBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASmithingBar::SpawnBar()
{
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}

void ASmithingBar::Hammered()
{
	hitsUntilHammered--;

	if (hitsUntilHammered == 0)
	{
		if (Player)
		{
			if (Player->isCraftingBronzeSword == true && Player->playerBronzeBars >= 1)
			{
				Player->CraftBronzeSword();
				Destroy();
			}
			else if (Player->isCraftingBronzePlateLegs == true && Player->playerBronzeBars >= 4)
			{
				Player->CraftBronzePlateLegs();
				Destroy();
			}
			else if (Player->isCraftingBronzeChestPlate == true && Player->playerBronzeBars >= 5)
			{
				Player->CraftBronzeChestPlate();
				Destroy();
			}
			else if (Player->isCraftingBronzeShield == true && Player->playerBronzeBars >= 3)
			{
				Player->CraftBronzeShield();
				Destroy();
			}
			else if (Player->isCraftingBronzeGloves == true && Player->playerBronzeBars >= 2)
			{
				Player->CraftBronzeGloves();
				Destroy();
			}
			else if (Player->isCraftingBronzeBoots == true && Player->playerBronzeBars >= 2)
			{
				Player->CraftBronzeBoots();
				Destroy();
			}
			else if (Player->isCraftingBronzeHelmet == true && Player->playerBronzeBars >= 3)
			{
				Player->CraftBronzeBoots();
				Destroy();
			}
			else if (Player->isCraftingBronzeArrows == true && Player->playerBronzeBars >= 1 && Player->playerArrowShafts >= 1)
			{
				Player->CraftBronzeArrow();
				Destroy();
			}
			else if (Player->isCraftingIronSword == true && Player->playerIronBars >= 1)
			{
				Player->CraftIronSword();
				Destroy();
			}
			else if (Player->isCraftingIronPlateLegs == true && Player->playerIronBars >= 4)
			{
				Player->CraftIronPlateLegs();
				Destroy();
			}
			else if (Player->isCraftingIronChestPlate == true && Player->playerIronBars >= 5)
			{
				Player->CraftIronChestPlate();
				Destroy();
			}
			else if (Player->isCraftingIronShield == true && Player->playerIronBars >= 3)
			{
				Player->CraftIronShield();
				Destroy();
			}
			else if (Player->isCraftingIronGloves == true && Player->playerIronBars >= 2)
			{
				Player->CraftIronGloves();
				Destroy();
			}
			else if (Player->isCraftingIronBoots == true && Player->playerIronBars >= 2)
			{
				Player->CraftIronBoots();
				Destroy();
			}
			else if (Player->isCraftingIronHelmet == true && Player->playerIronBars >= 3)
			{
				Player->CraftIronBoots();
				Destroy();
			}
			else if (Player->isCraftingIronArrows == true && Player->playerIronBars >= 1 && Player->playerArrowShafts >= 1)
			{
				Player->CraftIronArrow();
				Destroy();
			}
			else if (Player->isCraftingSteelSword == true && Player->playerSteelBars >= 1)
			{
				Player->CraftSteelSword();
				Destroy();
			}
			else if (Player->isCraftingSteelPlateLegs == true && Player->playerSteelBars >= 4)
			{
				Player->CraftSteelPlateLegs();
				Destroy();
			}
			else if (Player->isCraftingSteelChestPlate == true && Player->playerSteelBars >= 5)
			{
				Player->CraftSteelChestPlate();
				Destroy();
			}
			else if (Player->isCraftingSteelShield == true && Player->playerSteelBars >= 3)
			{
				Player->CraftSteelShield();
				Destroy();
			}
			else if (Player->isCraftingSteelGloves == true && Player->playerSteelBars >= 2)
			{
				Player->CraftSteelGloves();
				Destroy();
			}
			else if (Player->isCraftingSteelBoots == true && Player->playerSteelBars >= 2)
			{
				Player->CraftSteelBoots();
				Destroy();
			}
			else if (Player->isCraftingSteelHelmet == true && Player->playerSteelBars >= 3)
			{
				Player->CraftSteelBoots();
				Destroy();
			}
			else if (Player->isCraftingSteelArrows == true && Player->playerSteelBars >= 1 && Player->playerArrowShafts >= 1)
			{
				Player->CraftSteelArrow();
				Destroy();
			}
		}
	}
}
