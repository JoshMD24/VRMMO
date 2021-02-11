// Fill out your copyright notice in the Description page of Project Settings.


#include "CookingFish.h"

// Sets default values
ACookingFish::ACookingFish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACookingFish::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ACookingFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACookingFish::SpawnFish()
{
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}

void ACookingFish::Cooking()
{
	GetWorldTimerManager().SetTimer(CookingTimer, this, &ACookingFish::Cooked, 3, false);
}

void ACookingFish::StopCooking()
{
	GetWorld()->GetTimerManager().ClearTimer(CookingTimer);
}

void ACookingFish::Cooked()
{
	if (Player)
	{
		if (Player->isCookingShrimp == true && Player->depositedShrimp >= 1)
		{
			Player->CookShrimp();
			Destroy();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CookedShrimp"));
		}
		if (Player->isCookingAnchovies == true && Player->depositedAnchovies >= 1)
		{
			Player->CookAnchovies();
			Destroy();
		}
		if (Player->isCookingTrout == true && Player->depositedTrout >= 1)
		{
			Player->CookTrout();
			Destroy();
		}
	}
}