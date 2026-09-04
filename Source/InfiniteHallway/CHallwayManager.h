#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CHallwayManager.generated.h"

class ACPlayerCharacter;
class ACHallwaySegment;

UCLASS()
class INFINITEHALLWAY_API ACHallwayManager : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	TArray<ACHallwaySegment*> m_HallwaySegments;
	UPROPERTY()
	ACPlayerCharacter* m_PlayerCharacter = nullptr;

	ACHallwayManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void SetupManager();
};
