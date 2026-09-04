#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFloatingBox.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class INFINITEHALLWAY_API ACFloatingBox : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* m_SceneRoot = nullptr;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_FloatingBox = nullptr;

	ACFloatingBox();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
