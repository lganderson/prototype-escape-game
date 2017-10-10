// Copyright Kinsman & Co 2017

#pragma once

#include "CoreMinimal.h"
#include <Engine/TriggerVolume.h>
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	float GetTotalMassOfActorsOnPlate();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BluePrintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BluePrintAssignable)
	FDoorEvent OnClose;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float ActivationMass = 30.f;

	AActor* Owner = nullptr; // The owning door
};
