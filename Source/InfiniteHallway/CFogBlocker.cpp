#include "CFogBlocker.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ACFogBlocker::ACFogBlocker()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = m_SceneRoot;
	m_FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FogMesh"));
	m_FogMesh->SetupAttachment(m_SceneRoot);

}

void ACFogBlocker::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACFogBlocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

