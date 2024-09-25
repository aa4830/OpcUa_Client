// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <common.h>
#include "MyCustomStruct.h"
#include "MyPlayerController.generated.h"

UCLASS()
class OPCUA_UNREAL_CLIENT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	AMyPlayerController();

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	UA_Client* MyClient;
	UUserWidget* MyWidget;
	TSubclassOf<UUserWidget> MyWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Custom Structs")
	TArray<FMyCustomStruct> MyStructArray;

	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void PrintMyStructArray();

private:
	void ConnectToOpcUaServer();
	void ReadMyLevelDataFromOpcUa();
};
