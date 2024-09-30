// Graduate work OTUS. Made by Alex Sinkin (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "CharacterBase.generated.h"


UCLASS(Config=Game)
class OTUS_GW_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()
	
public:
	ACharacterBase();
	
	// Current weapon in hands
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BaseAttack")
	class USkeletalMeshComponent* Weapon;
	
	// Unarmed bare hands damage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseAttack")
	float BaseDamage = 0.01f; 

protected:
	// Slow walk speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float SlowWalkSpeed = 94.5f;

	// Walk speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 110.f;
	
	// Sprint speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float SprintSpeed = 375.f;

	// Crouch walk speed
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float CrouchedWalkSpeed = 100.f;
	
	virtual void BeginPlay() override;

	// Movement and looking
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);
	UFUNCTION(BlueprintCallable)
	void LookUp(float Value);
	UFUNCTION(BlueprintCallable)
	void Turn(float Value);
};
