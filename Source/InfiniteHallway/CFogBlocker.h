#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFogBlocker.generated.h"

UCLASS()
class INFINITEHALLWAY_API ACFogBlocker : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* m_SceneRoot = nullptr;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_FogMesh = nullptr;

	ACFogBlocker();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
