#include "MyActor.h"
#include "client.h"  // open62541 클라이언트 헤더
#include "client_highlevel.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
    MyClient = nullptr;  // 클라이언트 초기화
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // OPC UA 서버에 연결
    ConnectToOpcUaServer();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 데이터 읽기 (1초마다)
    static float Timer = 0.0f;
    Timer += DeltaTime;
    if (Timer >= 1.0f)
    {
        ReadDataFromOpcUa();
        Timer = 0.0f;  // 타이머 리셋
    }
}

void AMyActor::ConnectToOpcUaServer()
{
    // OPC UA 클라이언트 생성
    MyClient = UA_Client_new();
    if (MyClient == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create UA_Client"));
        return;
    }

    // 서버에 연결 (서버 URL 변경 필요)
    UA_StatusCode status = UA_Client_connect(MyClient, "opc.tcp://uademo.prosysopc.com:53530/OPCUA/SimulationServer");
    if (status != UA_STATUSCODE_GOOD)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to connect to OPC UA server: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
        UA_Client_delete(MyClient);
        MyClient = nullptr;
    }
}

void AMyActor::ReadDataFromOpcUa()
{
    if (MyClient == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Client is not initialized"));
        return;
    }

    // 데이터 읽기 (노드 ID는 변경 필요)
    UA_Variant value;
    UA_Variant_init(&value);
    UA_NodeId nodeId = UA_NODEID_STRING(5, const_cast<char*>("Number"));  // 노드 ID

    UA_StatusCode status = UA_Client_readValueAttribute(MyClient, nodeId, &value);
    if (status == UA_STATUSCODE_GOOD)
    {
        // 실제 타입 확인 및 로그 출력
        UE_LOG(LogTemp, Log, TEXT("Value type received: %s"), *FString(UTF8_TO_TCHAR(value.type->typeName)));

        // Float 타입 처리
        if (value.type == &UA_TYPES[UA_TYPES_FLOAT])
        {
            float floatValue = *(float*)value.data;
            UE_LOG(LogTemp, Log, TEXT("Value read from OPC UA server: %f"), floatValue);
        }
        else if (value.type == &UA_TYPES[UA_TYPES_BYTE])
        {
            uint8 byteValue = *(uint8*)value.data;
            UE_LOG(LogTemp, Log, TEXT("Value read from OPC UA server (Byte): %d"), byteValue);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Unexpected value type received"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to read value: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
    }

    UA_Variant_clear(&value);  // 메모리 해제
}