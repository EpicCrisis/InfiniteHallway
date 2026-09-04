#include "CFloatingBox.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ACFloatingBox::ACFloatingBox()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = m_SceneRoot;
	m_FloatingBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloatingBox"));
	m_FloatingBox->SetupAttachment(m_SceneRoot);
}

void ACFloatingBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACFloatingBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

