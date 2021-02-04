// Fill out your copyright notice in the Description page of Project Settings.


#include "FletchingLog.h"

// Sets default values
AFletchingLog::AFletchingLog()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFletchingLog::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	cutsUntilFletched = 4;
}

// Called every frame
void AFletchingLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFletchingLog::SpawnLog()
{
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}

void AFletchingLog::Cut()
{
	cutsUntilFletched--;

	if (cutsUntilFletched == 0)
	{
		if (Player)
		{
			if (Player->isCraftingBow == true && Player->depositedLogs >= 5)
			{
				Player->CraftBow();
				Destroy();
			}
			if (Player->isCraftingOakBow == true && Player->depositedOakLogs >= 5)
			{
				Player->CraftOakBow();
				Destroy();
			}
			if (Player->isCraftingWillowBow == true && Player->depositedWillowLogs >= 5)
			{
				Player->CraftWillowBow();
				Destroy();
			}
			if (Player->isCraftingArrowShaft == true && Player->depositedLogs >= 1)
			{
				Player->CraftArrowShaft();
				Destroy();
			}
			if (Player->isCraftingOakArrowShaft == true && Player->depositedOakLogs >= 1)
			{
				Player->CraftOakArrowShaft();
				Destroy();
			}
			if (Player->isCraftingWillowArrowShaft == true && Player->depositedWillowLogs >= 1)
			{
				Player->CraftWillowArrowShaft();
				Destroy();
			}
		}
	}
}