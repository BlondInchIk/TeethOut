// Copyright Epic Games, Inc. All Rights Reserved.

#include "Enemy_AICharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//Установка параметров по умолчанию
AEnemy_AICharacter::AEnemy_AICharacter()
{
	// Установка размера капсуля
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Установка параметров для мышки
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Установка осей для мыши
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Установка параметрова передвижения
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Создание Camera Boom (рука для фиксации камеры) (компонент)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Создание Follow camera (компонент)
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}

void AEnemy_AICharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Биндинг прыжка
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Биндинг осей передвижения
	PlayerInputComponent->BindAxis("MoveForward", this, &AEnemy_AICharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEnemy_AICharacter::MoveRight);

	// Биндинг осей для мыши
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AEnemy_AICharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AEnemy_AICharacter::LookUpAtRate);

	// Отслеживание нажатие клавиши
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AEnemy_AICharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AEnemy_AICharacter::TouchStopped);

	// VR
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AEnemy_AICharacter::OnResetVR);
}

// VR
void AEnemy_AICharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

// Функция прыжка
void AEnemy_AICharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

// Функция прекращения прыжка
void AEnemy_AICharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

// Высчитывание угла наклона камеры
void AEnemy_AICharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

// Высчитывание угла наклона камеры
void AEnemy_AICharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Функция движения по X (через вектор)
void AEnemy_AICharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// Функция движения по Y (через вектор)
void AEnemy_AICharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
