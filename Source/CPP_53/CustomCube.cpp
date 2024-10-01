#include "CustomCube.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ACustomCube::ACustomCube()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create a static mesh component for the cube
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    // Set the default mesh (replace with your own cube mesh)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }

    // Set initial values for the timer and the material
    TimeBetweenColorChanges = 1.0f;  // 1 second between color changes
}

// Called when the game starts or when spawned
void ACustomCube::BeginPlay()
{
    Super::BeginPlay();

    // Create a dynamic material instance
    if (CubeMesh)
    {
        UMaterialInterface* Material = CubeMesh->GetMaterial(0);
        if (Material)
        {
            DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
            CubeMesh->SetMaterial(0, DynamicMaterial);
        }
    }

    // Start the color change timer
    GetWorld()->GetTimerManager().SetTimer(ColorChangeTimerHandle, this, &ACustomCube::ChangeColor, TimeBetweenColorChanges, true);
}

// Called every frame
void ACustomCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function to change the color of the cube
void ACustomCube::ChangeColor()
{
    if (DynamicMaterial)
    {
        // Generate a random color
        FLinearColor NewColor = FLinearColor::MakeRandomColor();

        // Set the color parameter in the dynamic material
        DynamicMaterial->SetVectorParameterValue(FName("Color"), NewColor);
    }
}
