// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Skater_BGSCharacter.generated.h"


UCLASS(config=Game)
class ASkater_BGSCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Open Pause Menu */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PauseAction;

	/** Change between walking and skating by changing bSkating's value */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ModeChangeAction;

public:
	ASkater_BGSCharacter();
	
	/** Called for movement input */
	UFUNCTION(BlueprintNativeEvent)
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	UFUNCTION(BlueprintNativeEvent)
	void Look(const FInputActionValue& Value);

	/** Called to open pause the game and open the pause menu */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Pause();

	/** Called to open pause the game and open the pause menu */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ChangeMovementMode();

	/** Used to set bAccelerating to false when the input is let go */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StopAccelerating();

	/** Used when the pause menu is closed to set bPaused to false and resume the game */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResumeGame();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

