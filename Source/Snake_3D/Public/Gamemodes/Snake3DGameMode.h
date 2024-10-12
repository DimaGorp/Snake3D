// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Snake3DGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SNAKE_3D_API ASnake3DGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ASnake3DGameMode();
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "GameModes Classes")
	TSubclassOf<class ASnakePawn> DefaultSnakePawn;
	UPROPERTY(EditDefaultsOnly, Category = "GameModes Classes")
	TSubclassOf<class ASnakePlayerController> DefaultSnakePawnController;

};
