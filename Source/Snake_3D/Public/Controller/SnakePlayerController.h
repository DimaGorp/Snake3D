// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "SnakePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SNAKE_3D_API ASnakePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* aPawn) override;
protected:
	void SetupInputComponent();
	void TurnPlayer(const FInputActionValue& Value);
protected:
	UPROPERTY(EditDefaultsOnly)
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly)
	class UInputAction* MoveInput;
private:
	FTimerHandle MovementHandler;
	FTimerHandle TurnHandler;
	
};
