// Fill out your copyright notice in the Description page of Project Settings.


#include "LongSword.h"

// Sets default values
ALongSword::ALongSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALongSword::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ALongSword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALongSword::PickedUp()
{
	if (swordType == 1)
	{
		Player->equippedSwordType = 1;
	}
	else if (swordType == 2)
	{
		Player->equippedSwordType = 2;
	}
	else if (swordType == 3)
	{
		Player->equippedSwordType = 3;
	}
}