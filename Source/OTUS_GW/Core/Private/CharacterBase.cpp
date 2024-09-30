// Graduate work OTUS. Made by Alex Sinkin (c)

#include "OTUS_GW/Core/Public/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"


ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::MoveForward(float Value)
{
	if (Controller == nullptr || Value == 0.f) 
	{
		return;
	}

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ACharacterBase::MoveRight(float Value)
{
	if (Controller == nullptr || Value == 0.f) 
	{
		return;
	}

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ACharacterBase::LookUp(float Value)
{
	if (Value == 0.f)
	{
		return;
	}
	AddControllerPitchInput(Value);
}

void ACharacterBase::Turn(float Value)
{
	if (Value == 0.f)
	{
		return;
	}
	AddControllerYawInput(Value);
}