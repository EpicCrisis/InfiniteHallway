#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CHallwaySegment.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class INFINITEHALLWAY_API ACHallwaySegment : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* m_SceneRoot = nullptr;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_SegmentMesh = nullptr;

	ACHallwaySegment();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
