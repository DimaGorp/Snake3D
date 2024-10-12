// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/Snake3DGameMode.h"
#include "Controller/SnakePlayerController.h"
#include "SnakePawn/Snake.h"

ASnake3DGameMode::ASnake3DGameMode()
{
}

void ASnake3DGameMode::BeginPlay()
{
	Super::BeginPlay();
	DefaultPawnClass = DefaultSnakePawn;
	PlayerControllerClass = DefaultSnakePawnController;
}

