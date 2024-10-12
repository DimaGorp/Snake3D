// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SnakePlayerController.h"
#include "GameFramework/Pawn.h"
#include "SnakePawn/Snake.h"
#include "Kismet/GameplayStatics.h"
void ASnakePlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer * LocalPlayer = Cast<ULocalPlayer>(Player)) {
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
			if (InputMapping) {
				InputSystem->AddMappingContext(InputMapping,0);
			}
		}
	}
}

void ASnakePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	GetWorld()->GetTimerManager().SetTimer(MovementHandler, [this]() {
		GetPawn()->AddMovementInput(GetPawn()->GetActorForwardVector(), 1.0f);
	},
	0.0001f, true);
}



void ASnakePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* Component = Cast<UEnhancedInputComponent>(InputComponent)) {
		if (MoveInput) {
			Component->BindAction(MoveInput, ETriggerEvent::Started, this, &ASnakePlayerController::TurnPlayer);
		}
	}
}

void ASnakePlayerController::TurnPlayer(const FInputActionValue& Value)
{
	if (GetWorld()->GetTimerManager().IsTimerActive(TurnHandler))
	{
		return;
	}
	float Direction = Value.Get<float>();
	if (APawn* PlayerPawn = GetPawn()) {
		FRotator StartRotation = PlayerPawn->GetActorRotation();
		FRotator DesiredRotation = PlayerPawn->GetActorRotation();
		DesiredRotation.Yaw += FMath::RoundToInt(90 * Direction);
		DesiredRotation.Yaw = FMath::UnwindDegrees(DesiredRotation.Yaw);
		GetWorld()->GetTimerManager().SetTimer(TurnHandler,[this,StartRotation,DesiredRotation,PlayerPawn]() {
			FRotator CurrentRotation = PlayerPawn->GetActorRotation();
			CurrentRotation.Yaw = FMath::UnwindDegrees(CurrentRotation.Yaw);

			// Interpolate towards the desired rotation using constant speed
			FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, DesiredRotation, GetWorld()->DeltaTimeSeconds, 3.0f); // Adjust speed as needed

			// Set the new interpolated rotation
			PlayerPawn->SetActorRotation(NewRotation);
			if (FMath::IsNearlyEqual(CurrentRotation.Yaw, DesiredRotation.Yaw,0.1f)) {
				PlayerPawn->SetActorRotation(DesiredRotation);
				GetWorld()->GetTimerManager().ClearTimer(TurnHandler);
				GEngine->AddOnScreenDebugMessage(0, 9.0f, FColor::Blue, *FString::Printf(TEXT("%s"), *CurrentRotation.ToString()));
				return;
			}
		},
		0.0001f, true);
	}
}
