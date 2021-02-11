// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "Engine/StaticMesh.h"

#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"

#include "VrPlayerCharacter.h"

#include "LongSword.generated.h"

UCLASS()
class VRMMO_API ALongSword : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALongSword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UBoxComponent* CollisionComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UAudioComponent* AudioComp;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	AVrPlayerCharacter* Player;

	FTimerHandle sheathTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int swordType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isBeingHeld;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isNotSheath;

	UFUNCTION(BlueprintCallable)
		void PickedUp();
	UFUNCTION(BlueprintCallable)
		void Dropped();
	UFUNCTION(BlueprintCallable)
		void Sheath();

	void DestroySword();
};
