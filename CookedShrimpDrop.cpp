// Fill out your copyright notice in the Description page of Project Settings.


#include "CookedShrimpDrop.h"

// Sets default values
ACookedShrimpDrop::ACookedShrimpDrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBoxComp"));
	BoxComp->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	BoxComp->CanCharacterStepUpOn = ECB_No;
	BoxComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACookedShrimpDrop::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ACookedShrimpDrop::BeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &ACookedShrimpDrop::EndOverlap);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ACookedShrimpDrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACookedShrimpDrop::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("Backpack")))
	{
		AddToInventory();
	}
}

void ACookedShrimpDrop::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ACookedShrimpDrop::AddToInventory()
{
	//Add one shrimp to player then loop through inventory to see if it is already in inventory, if not add it, if it is break since the widget will update how many player has, 
	//else if inventory is full break then call to destory the actor
	Player->playerCookedShrimp++;

	for (int32 i = 0; i < 20; i++)
	{
		if (Player->InventorySlots[i] == 0)
		{
			Player->InventorySlots[i] = 41;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
			break;
		}
		else if (Player->InventorySlots[i] == 41)
		{
			break;
		}
		else
		{
			break;
		}
	}
	DestroyShrimp();
}

void ACookedShrimpDrop::DestroyShrimp()
{
	Destroy();
}