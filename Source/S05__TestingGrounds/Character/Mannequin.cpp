// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "../Weapons/Gun.h"


// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //TODO Check if it's needed

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	CameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Arms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPCharacterArms"));
	Arms->SetOnlyOwnerSee(true);
	Arms->SetupAttachment(CameraComponent);
	Arms->bCastDynamicShadow = false;
	Arms->CastShadow = false;
	Arms->RelativeRotation = FRotator(1.9f, -19.19f, 20.f);
	Arms->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
}



// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if (BPGun == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun Blueprint is missing"));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(BPGun);
	if (IsPlayerControlled()) {
		Gun->AttachToComponent(Arms, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	}
	else {
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint_0"));
	}

	Gun->AnimInstance1P = Arms->GetAnimInstance();
	Gun->AnimInstance3P = GetMesh()->GetAnimInstance();

	if(InputComponent != nullptr){
		InputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::PullTrigger);
	}
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMannequin::UnPossessed()
{
	Super::UnPossessed();
	if (!ensure(Gun)) {
		UE_LOG(LogTemp, Warning, TEXT("Gun is not available"))
		return;
	}
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint_0"));
}


void AMannequin::PullTrigger()
{
	Gun->OnFire();
}


