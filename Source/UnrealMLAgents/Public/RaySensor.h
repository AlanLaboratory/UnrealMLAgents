#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISensor.h"
#include "IBuiltinSensor.h"
#include "RaySensor.generated.h"

UENUM(BlueprintType)
enum class ERayAxis : uint8
{
	X UMETA(DisplayName = "X Axis"),
	Y UMETA(DisplayName = "Y Axis"),
	Z UMETA(DisplayName = "Z Axis")
};

USTRUCT(BlueprintType)
struct UNREALMLAGENTS_API FRayInput
{
	GENERATED_BODY()

public:
	// Transform of the Actor
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray Perception")
	FTransform Transform;

	// The length of the ray
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray Perception")
	float RayLength;

	/// List of angles (in degrees) used to define the rays.
	/// 90 degrees is considered "forward" relative to the game object.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	TArray<float> Angles;

	// Ignore character
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Raycast")
	AActor* IgnoredActor;

	/// Whether to draw debug lines
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	bool bDrawDebugLines;

	/// The axis relative to which rays will be cast (e.g., X, Y, Z)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	ERayAxis RayAxis;

	/// Starting height offset of ray from center of actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float StartOffset;

	/// Yaw offset to compensate for initial rotation of the mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float YawOffset;

	// Uniform pitch angle for all rays
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ray Perception")
	float PitchAngle;

	// Get the number of observations
	int32 OutputSize() { return Angles.Num() * 2; }
};

UCLASS(Blueprintable)
class UNREALMLAGENTS_API URaySensor : public UObject, public IISensor, public IBuiltInSensor
{
	GENERATED_BODY()

public:
	void Initialize(FString Name, UWorld* World, FRayInput& RayInput);

	// IISensor

	virtual FObservationSpec GetObservationSpec() override;
	virtual int32			 Write(ObservationWriter& Writer) override;
	virtual void			 Update() override;
	virtual void			 Reset() override;
	virtual FString			 GetName() const override;

	// IBuildItSensor

	virtual EBuiltInSensorType GetBuiltInSensorType() const override;

private:
	void	PerformRaycasts();
	FVector GetForwardVector() const;
	float	GetActorTag(AActor* Actor);
	float	HashToFloat(const FString& HashString);
	void	SetNumObservations(int32 NumberObservations);
	FVector CalculateDirectionForAxis(float RadAngle, ERayAxis RayAxis, float PitchAngle);

	FObservationSpec   _ObservationSpec;
	TArray<float>	   _Observations;
	FString			   _Name;
	TArray<FHitResult> _HitResults;
	FRayInput		   _RayInput;
	UWorld*			   _World;
};
