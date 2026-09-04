#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFogAnchor.generated.h"

class ACPlayerCharacter;
class ACFogBlocker;

UCLASS()
class INFINITEHALLWAY_API ACFogAnchor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACFogAnchor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fog")
	TSubclassOf<ACFogBlocker> m_FogBlockerClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fog")
	TArray<ACFogBlocker*> m_FogBlockers;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fog")
	ACPlayerCharacter* m_PlayerToFollow = nullptr;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
