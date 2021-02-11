// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldCoins.h"

// Sets default values
AGoldCoins::AGoldCoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBoxComp"));
	BoxComp->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	BoxComp->CanCharacterStepUpOn = ECB_No;
	SetRootComponent(BoxComp);

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	CoinMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGoldCoins::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGoldCoins::BeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AGoldCoins::EndOverlap);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AGoldCoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoldCoins::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("Backpack")))
	{
		AddToInventory();
	}
}

void AGoldCoins::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AGoldCoins::AddToInventory()
{
	//Add three gold coins to player, gold coins are not stored in the regular inventory like the other drops so we do not need to loop through inventory
	Player->playerGoldCoins = Player->playerGoldCoins + 3;

	DestroyGoldCoins();
}

void AGoldCoins::DestroyGoldCoins()
{
	Destroy();
}

