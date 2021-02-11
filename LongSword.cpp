// Fill out your copyright notice in the Description page of Project Settings.


#include "LongSword.h"

// Sets default values
ALongSword::ALongSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	CollisionComp->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;
	CollisionComp->SetupAttachment(RootComponent);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALongSword::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ALongSword::BeginOverlap);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this, &ALongSword::EndOverlap);

	//unless told otherwise assume its a bronze sword
	swordType = 1;
}

// Called every frame
void ALongSword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALongSword::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherComp->ComponentHasTag(FName("SheathWeapon")))
	{
		Sheath();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sheath"));
	}
}

void ALongSword::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag(FName("SheathWeapon")))
	{
		isNotSheath = true;
		GetWorld()->GetTimerManager().ClearTimer(sheathTimer);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Not Sheath"));
	}
}

void ALongSword::PickedUp()
{
	isBeingHeld = true;
	//check sword type then set players sword type and call equip sword
	//Bronze = 1, iron = 2, steel = 3
	if (swordType == 1)
	{
		Player->equippedSwordType = 1;
		Player->EquipSword();
	}
	else if (swordType == 2)
	{
		Player->equippedSwordType = 2;
		Player->EquipSword();
	}
	else if (swordType == 3)
	{
		Player->equippedSwordType = 3;
		Player->EquipSword();
	}
}

void ALongSword::Dropped()
{
	//set the player sword type to 0 then call equip sword to let the player know its no longer holding a sword
	isBeingHeld = false;
	Player->equippedSwordType = 0;
	Player->EquipSword();
	Player->playerDamage = Player->strengthLevel;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dropped"));
}

void ALongSword::Sheath()
{
	//Check to see if isNotSheath is true, this is because the sword spawns in the same box that destroys it so we have to make sure the sword has left the box before destroying it
	if (isNotSheath == true)
	{
		GetWorldTimerManager().SetTimer(sheathTimer, this, &ALongSword::DestroySword, 1, false);
	}
}

void ALongSword::DestroySword()
{
	Player->PutSwordOnBack();
	Destroy();
}