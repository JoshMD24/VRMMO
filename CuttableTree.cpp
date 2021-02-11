// Fill out your copyright notice in the Description page of Project Settings.


#include "CuttableTree.h"

// Sets default values
ACuttableTree::ACuttableTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACuttableTree::BeginPlay()
{
	Super::BeginPlay();
	
	logsRemaining = FMath::RandRange(1, 10);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player exists"));
	}
}

// Called every frame
void ACuttableTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACuttableTree::LoseLog()
{
	logsRemaining--;
	if (Player)
	{
		Player->gatherLog();
	}
	if (logsRemaining == 0)
	{
		GetWorldTimerManager().SetTimer(SetLogsTimer, this, &ACuttableTree::SetLogsRemaining, 5, false);
	}
}

void ACuttableTree::LoseOakLog()
{
	logsRemaining--;
	if (Player)
	{
		Player->gatherOakLog();
	}
	if (logsRemaining == 0)
	{
		GetWorldTimerManager().SetTimer(SetLogsTimer, this, &ACuttableTree::SetLogsRemaining, 5, false);
	}
}

void ACuttableTree::LoseWillowLog()
{
	logsRemaining--;
	if (Player)
	{
		Player->gatherWillowLog();
	}
	if (logsRemaining == 0)
	{
		GetWorldTimerManager().SetTimer(SetLogsTimer, this, &ACuttableTree::SetLogsRemaining, 5, false);
	}
}

void ACuttableTree::SetLogsRemaining()
{
	logsRemaining = FMath::RandRange(1, 10);
}
