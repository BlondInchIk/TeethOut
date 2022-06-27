// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_AICharacter.generated.h"

UCLASS(config=Game)
class AEnemy_AICharacter : public ACharacter
{
	GENERATED_BODY()

	// Объявление руки для камеры(ссылка) и объявление отображения и доступа
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Объявление камеры(ссылка) и объявление отображения и доступа
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AEnemy_AICharacter();

	// Объявление осей для камеры
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	// VR
	void OnResetVR();

	// Объявление движения по X
	void MoveForward(float Value);

	// Объявление движения по Y
	void MoveRight(float Value);

	// Объявление движения по Yaw
	void TurnAtRate(float Rate);

	// Объявление движения по Pitch
	void LookUpAtRate(float Rate);

	// Отслеживание начала нажатия
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	// Отслеживание конца нажатия
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn интерфейс
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// return CameraBoom
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	// return FollowCamera
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

