#include "CFogAnchor.h"
#include "CPlayerCharacter.h"
#include "CFogBlocker.h"

ACFogAnchor::ACFogAnchor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACFogAnchor::BeginPlay()
{
	Super::BeginPlay();
	ACFogBlocker* FogBlockerA = GetWorld()->SpawnActor<ACFogBlocker>(m_FogBlockerClass, FVector(500.0f, 0.0f, 400.0f), FRotator::ZeroRotator);
	FogBlockerA->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	m_FogBlockers.Add(FogBlockerA);
	ACFogBlocker* FogBlockerB = GetWorld()->SpawnActor<ACFogBlocker>(m_FogBlockerClass, FVector(-500.0f, 0.0f, 400.0f), FRotator::ZeroRotator);
	FogBlockerB->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	m_FogBlockers.Add(FogBlockerB);
	ACFogBlocker* FogBlockerC = GetWorld()->SpawnActor<ACFogBlocker>(m_FogBlockerClass, FVector(0.0f, 500.0f, 400.0f), FRotator(0.0f, 90.0f, 0.0f));
	FogBlockerC->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	m_FogBlockers.Add(FogBlockerC);
	ACFogBlocker* FogBlockerD = GetWorld()->SpawnActor<ACFogBlocker>(m_FogBlockerClass, FVector(0.0f, -500.0f, 400.0f), FRotator(0.0f, 90.0f, 0.0f));
	FogBlockerD->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	m_FogBlockers.Add(FogBlockerD);
}

void ACFogAnchor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_PlayerToFollow)
	{
		SetActorLocation(m_PlayerToFollow->GetActorLocation());
	}
}

