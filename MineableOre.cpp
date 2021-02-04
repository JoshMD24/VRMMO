// Fill out your copyright notice in the Description page of Project Settings.


#include "MineableOre.h"

// Sets default values
AMineableOre::AMineableOre()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMineableOre::BeginPlay()
{
	Super::BeginPlay();
	
	oresRemaining = FMath::RandRange(1, 10);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AMineableOre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMineableOre::LoseCopperOre()
{
	oresRemaining--;
	if (Player)
	{
		Player->gatherCopperOre();
	}

	if (oresRemaining <= 0)
	{
		GetWorldTimerManager().SetTimer(OreTimer, this, &AMineableOre::SetOresRemaining, 5, false);
	}
}

void AMineableOre::LoseTinOre()
{
	oresRemaining--;
	if (Player)
	{
		Player->gatherTinOre();
	}

	if (oresRemaining <= 0)
	{
		GetWorldTimerManager().SetTimer(OreTimer, this, &AMineableOre::SetOresRemaining, 5, false);
	}
}

void AMineableOre::LoseIronOre()
{
	oresRemaining--;
	if (Player)
	{
		Player->gatherIronOre();
	}

	if (oresRemaining <= 0)
	{
		GetWorldTimerManager().SetTimer(OreTimer, this, &AMineableOre::SetOresRemaining, 5, false);
	}
}

void AMineableOre::LoseCoalOre()
{
	oresRemaining--;
	if (Player)
	{
		Player->gatherCoalOre();
	}

	if (oresRemaining <= 0)
	{
		GetWorldTimerManager().SetTimer(OreTimer, this, &AMineableOre::SetOresRemaining, 5, false);
	}
}

void AMineableOre::SetOresRemaining()
{
	oresRemaining = FMath::RandRange(1, 10);
}