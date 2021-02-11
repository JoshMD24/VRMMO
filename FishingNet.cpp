// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingNet.h"

// Sets default values
AFishingNet::AFishingNet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFishingNet::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	isNetInWater = false;
}

// Called every frame
void AFishingNet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AFishingNet::Fishing()
{
	GetWorldTimerManager().SetTimer(FishingTimer, this, &AFishingNet::CatchFish, FMath::RandRange(1, 10), false);
}

void AFishingNet::CatchFish()
{
	if (Player)
	{
		if (Player->fishingLevel < 15)
		{
			Player->GatherShrimp();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Shrimp"));
		}
		if (Player->fishingLevel >= 15 && Player->fishingLevel < 30)
		{
			fishType = FMath::RandRange(1, 10);
			if (fishType <= 5)
			{
				Player->GatherShrimp();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Shrimp"));
			}
			if (fishType >= 6)
			{
				Player->GatherAnchovies();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Anchovies"));
			}
		}
		if (Player->fishingLevel >= 30)
		{
			fishType = FMath::RandRange(1, 10);
			if (fishType <= 2)
			{
				Player->GatherShrimp();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Shrimp"));
			}
			if (fishType <= 6 && fishType > 2)
			{
				Player->GatherAnchovies();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Anchovies"));
			}
			if (fishType >= 7)
			{
				Player->GatherTrout();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Trout"));
			}
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Caught Fish"));
}

void AFishingNet::StopFishing()
{
	GetWorld()->GetTimerManager().ClearTimer(FishingTimer);
}