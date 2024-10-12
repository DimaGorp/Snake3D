#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Snake.generated.h"

UCLASS()
class SNAKE_3D_API ASnakePawn : public APawn
{
	GENERATED_BODY()
public:
	ASnakePawn();
	virtual void BeginPlay() override;
};