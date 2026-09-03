#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CHallwayManager.generated.h"

UCLASS()
class INFINITEHALLWAY_API ACHallwayManager : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	TArray<AActor*> m_HallwaySegments;

	ACHallwayManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
