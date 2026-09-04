#include "CHallwaySegment.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ACHallwaySegment::ACHallwaySegment()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = m_SceneRoot;
	m_SegmentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SegmentMesh"));
	m_SegmentMesh->SetupAttachment(m_SceneRoot);
}

void ACHallwaySegment::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACHallwaySegment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

