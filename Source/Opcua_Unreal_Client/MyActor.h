#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <common.h>
#include "MyActor.generated.h"

UCLASS()
class OPCUA_UNREAL_CLIENT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    UA_Client* MyClient;
private:
    void ConnectToOpcUaServer();
    void ReadDataFromOpcUa();
};