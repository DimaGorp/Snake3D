#include "SnakePawn/Snake.h"

ASnakePawn::ASnakePawn()
{
	
}

void ASnakePawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hi!"));
}
