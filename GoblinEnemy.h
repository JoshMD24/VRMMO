// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "VrPlayerCharacter.h"
#include "GoblinAIController.h"
#include "VrHatchet.h"

#include "Components/BoxComponent.h"

#include "GoblinEnemy.generated.h"

UCLASS()
class VRMMO_API AGoblinEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblinEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBoxComponent* DamageBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBoxComponent* PunchBox;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void BeginPunchOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndPunchOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	AVrPlayerCharacter* Player;

	AGoblinAIController* GoblinAIController;

	AVrHatchet* Hatchet;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> DeathLootOne;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> DeathLootTwo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector Location;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int lootNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int killedXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool hasBeenAttacked;
	//used for animation state machine
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isPunching;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isDead;

	bool hasPunched;
	bool diedToSword;
	bool diedToArrow;

	int damageTaken;
	

	FTimerHandle punchTimer;
	FTimerHandle deathTimer;

	void Punch();
	void StopPunching();
	void HasPunchedPlayer();
	void AllowedToPunchPlayer();
	void HitPlayer();

	void GoblinTakeDamage();
	void GoblinTakeArrowDamage();
	void Die();
	void SpawnDeathLoot();
	void DestroyGoblin();
};
