#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "CPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class ACHallwayManager;
class ACFogAnchor;

UCLASS()
class INFINITEHALLWAY_API ACPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayerCharacter();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//USceneComponent* m_FogAnchor = nullptr;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//UStaticMeshComponent* m_FogBlockerA = nullptr;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//UStaticMeshComponent* m_FogBlockerB = nullptr;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//UStaticMeshComponent* m_FogBlockerC = nullptr;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//UStaticMeshComponent* m_FogBlockerD = nullptr;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	//TSubclassOf<ACFogBlocker> m_FogBlockerClass;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fog")
	//TArray<ACFogBlocker*> m_FogBlockers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	TSubclassOf<ACFogAnchor> m_FogAnchorClass = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fog")
	ACFogAnchor* m_FogAnchor = nullptr;

	UPROPERTY(VisibleAnywhere)
	ACHallwayManager* m_HallwayManager = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* DefaultMappingContext = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction = nullptr;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PawnClientRestart() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
