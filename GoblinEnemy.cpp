// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinEnemy.h"

// Sets default values
AGoblinEnemy::AGoblinEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBoxComp"));
	DamageBox->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	DamageBox->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	DamageBox->CanCharacterStepUpOn = ECB_No;
	DamageBox->SetupAttachment(RootComponent);

	PunchBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PunchBoxComp"));
	PunchBox->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	PunchBox->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	PunchBox->CanCharacterStepUpOn = ECB_No;
	PunchBox->SetupAttachment(RootComponent);
	PunchBox->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform, FName("RightHand"));

	level = 1;

	maxHealth = 50.0f * level;
	health = maxHealth;
	damage = level * 5;
	killedXP = 20 * level;
}

// Called when the game starts or when spawned
void AGoblinEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	DamageBox->OnComponentBeginOverlap.AddDynamic(this, &AGoblinEnemy::BeginOverlap);
	DamageBox->OnComponentEndOverlap.AddDynamic(this, &AGoblinEnemy::EndOverlap);

	PunchBox->OnComponentBeginOverlap.AddDynamic(this, &AGoblinEnemy::BeginPunchOverlap);
	PunchBox->OnComponentEndOverlap.AddDynamic(this, &AGoblinEnemy::EndPunchOverlap);

	Player = Cast<AVrPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	GoblinAIController = Cast<AGoblinAIController>(GetController());
}

// Called every frame
void AGoblinEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player && GoblinAIController)
	{
		//Goblins are passive and will only attack the player if they get attacked first
		if (hasBeenAttacked == true)
		{
			FRotator EnemyRot = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), Player->GetActorLocation());
			SetActorRotation(EnemyRot);

			GoblinAIController->MoveToActor(Player, 50.0f);
		}
	}
}

// Called to bind functionality to input
void AGoblinEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGoblinEnemy::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("Sword")))
	{
		GoblinTakeDamage();
	}
	if (OtherComp->ComponentHasTag(FName("Arrow")))
	{
		GoblinTakeArrowDamage();
	}
	if (OtherComp->ComponentHasTag(FName("PlayerAttackBox")))
	{
		Punch();
	}
}

void AGoblinEnemy::EndOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag(FName("PlayerAttackBox")))
	{
		StopPunching();
	}
}

void AGoblinEnemy::BeginPunchOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(FName("PlayerHitBox")))
	{
		if (hasPunched == false)
		{
			HitPlayer();
		}
	}
}

void AGoblinEnemy::EndPunchOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AGoblinEnemy::Punch()
{
	//Set isPunching true so the animation state machine starts punching
	isPunching = true;

	//set has punched to false so player takes damage
	hasPunched = false;
	//Wait 0.55 seconds for animation to punch then call stop punching so the player won't take damage when the punch is on its way back
	GetWorldTimerManager().SetTimer(punchTimer, this, &AGoblinEnemy::HasPunchedPlayer, 0.55, false);
}

//stop punching animation
void AGoblinEnemy::StopPunching()
{
	isPunching = false;
	hasPunched = false;
	GetWorld()->GetTimerManager().ClearTimer(punchTimer);
}

//stop player from taking damage so the punch does not hurt on the way back
void AGoblinEnemy::HasPunchedPlayer()
{
	hasPunched = true;
	//after 0.50 seconds the punch animation will be done so we allow the enemy to hurt the player again for the next punch animation
	GetWorldTimerManager().SetTimer(punchTimer, this, &AGoblinEnemy::AllowedToPunchPlayer, 0.50, false);
}

//Allow the player to take damage
void AGoblinEnemy::AllowedToPunchPlayer()
{
	hasPunched = false;
	//Call punch to make the enemy punch again, if the player has left attack range StopPunching would be called which would clear the timer preventing this from being a endless loop
	GetWorldTimerManager().SetTimer(punchTimer, this, &AGoblinEnemy::Punch, 0.05, false);
}

void AGoblinEnemy::HitPlayer()
{
	Player->playerHealth = Player->playerHealth - damage;

	if (Player->playerHealth <= 0)
	{
		Player->Die();
		StopPunching();
	}
}

void AGoblinEnemy::GoblinTakeDamage()
{
	damageTaken = Player->playerDamage;
	health = health - damageTaken;
	hasBeenAttacked = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(health));

	//Check to make sure it isn't already dead or else if the player hits it multiple times while below 0 hp it will die multiple times giving player a lot more xp
	if (health <= 0 && isDead == false)
	{
		diedToSword = true;
		Die();
	}
}

void AGoblinEnemy::GoblinTakeArrowDamage()
{
	damageTaken = Player->playerBowDamage;
	health = health - damageTaken;
	hasBeenAttacked = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Goblin Hit By Arrow"));

	if (health <= 0 && isDead == false)
	{
		diedToArrow = true;
		Die();
	}
}

// set isDead to true to start death animation then destroy after animation is finished
void AGoblinEnemy::Die()
{
	isDead = true;
	GetWorldTimerManager().SetTimer(deathTimer, this, &AGoblinEnemy::SpawnDeathLoot, 2.40, false);

	//Check to see how the player killed the goblin and give xp to the skill used
	if (diedToSword == true)
	{
		Player->combatXpToGain = killedXP;
		Player->GainCombatXp();
	}
	else if (diedToArrow == true)
	{
		Player->archeryXpToGain = killedXP;
		Player->GainArcheryXp();
	}
	
	GetCharacterMovement()->MaxWalkSpeed = 0;
}

void AGoblinEnemy::SpawnDeathLoot()
{
	//we need to spawn the loot before destroying the actor so we will make it so the player can't see the mesh, spawn the loot then destroy the actor
	GetMesh()->SetVisibility(false);
	//Get a random number from 1-2 and spawn the loot for that number
	lootNumber = FMath::RandRange(1, 2);
	if (lootNumber == 1)
	{
		GetWorld()->SpawnActor<AActor>(DeathLootOne, GetActorLocation(), GetActorRotation());
	}
	else if (lootNumber == 2)
	{
		GetWorld()->SpawnActor<AActor>(DeathLootTwo, GetActorLocation(), GetActorRotation());
	}
	GetWorldTimerManager().SetTimer(deathTimer, this, &AGoblinEnemy::DestroyGoblin, 0.1, false);
}

void AGoblinEnemy::DestroyGoblin()
{
	Destroy();
}