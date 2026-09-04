#include "CHallwayManager.h"
#include "CPlayerCharacter.h"
#include "CHallwaySegment.h"
#include "GameFramework/CharacterMovementComponent.h"

ACHallwayManager::ACHallwayManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACHallwayManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACHallwayManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(m_PlayerCharacter)
	{
		TArray<ACHallwaySegment*> TempSegments = m_HallwaySegments;
		if (TempSegments.Num() == 0)
		{
			return;
		}

		FVector PlayerLocation = m_PlayerCharacter->GetActorLocation();
		FVector EndLocation = TempSegments.Last()->GetActorLocation();
		FVector FirstLocation = TempSegments[0]->GetActorLocation();
		
		// Check if the player has reached the end of the hallway
		if(PlayerLocation.X >= EndLocation.X + 400.0f)
		{
			// move both the player and last segment back to the start of the hallway
			UCharacterMovementComponent* Movement = m_PlayerCharacter->GetCharacterMovement();
			if(Movement->IsMovingOnGround())
			{
				UPrimitiveComponent* Base = Movement->GetMovementBase();
				if (Base)
				{
					// Player is standing on this component
				}
			}
			else
			{
			}
			
			for (int32 i = 0; i < TempSegments.Num(); ++i)
			{
				ACHallwaySegment* ThisSegment = TempSegments[i];
				FVector SegmentLocation = ThisSegment->GetActorLocation();
				SegmentLocation.X = (i + 2) * 1000.0f;
				if (i == TempSegments.Num() - 1)
				{
					SegmentLocation.X = 1000.0f;
					TempSegments.RemoveAt(i);
					TempSegments.Insert(ThisSegment, 0);
				}
				ThisSegment->SetActorLocation(SegmentLocation);
			}
			m_HallwaySegments = TempSegments;
		}
	}
}

void ACHallwayManager::SetupManager()
{
}

