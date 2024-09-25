#include "MyPlayerController.h"
#include "client.h"  // open62541 클라이언트 헤더
#include "client_highlevel.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyCustomStruct.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
    MyClient = nullptr;  // 클라이언트 초기화
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    ConnectToOpcUaServer();
    ReadMyLevelDataFromOpcUa();
    PrintMyStructArray();
}

void AMyPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 데이터 읽기 (5초마다)
    static float Timer = 0.0f;
    Timer += DeltaTime;
    if (Timer >= 5.0f)
    {
        Timer = 0.0f;  // 타이머 리셋
    }
}

void AMyPlayerController::ConnectToOpcUaServer()
{
    // OPC UA 클라이언트 생성
    MyClient = UA_Client_new();
    if (MyClient == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create UA_Client"));
        return;
    }

    UA_StatusCode status = UA_Client_connect(MyClient, "opc.tcp://uademo.prosysopc.com:53530/OPCUA/SimulationServer");
    if (status != UA_STATUSCODE_GOOD)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to connect to OPC UA server: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
        UA_Client_delete(MyClient);
        MyClient = nullptr;
    }
}

void AMyPlayerController::ReadMyLevelDataFromOpcUa()
{
    if (MyClient == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Client is not initialized"));
        return;
    }

    struct FNodeData
    {
        FString NodeId; // Node ID
        FString DisplayName; // Display Name
        FString DataType; // Data Type
    };

    FNodeData Nodes[] =
    {
        { TEXT("MyLevel"), TEXT("MyLevel"), TEXT("Double") },
        { TEXT("MySwitch"), TEXT("MySwitch"), TEXT("Boolean") },
        { TEXT("MyLevel.Alarm/0:EventId"), TEXT("EventId"), TEXT("ByteString") },
        { TEXT("MyLevel.Alarm/0:ReceiveTime"), TEXT("ReceiveTime"), TEXT("DateTime") },
        { TEXT("MyLevel.Alarm/0:Severity"), TEXT("Severity"), TEXT("UInt16") }
    };

    for (const FNodeData& Node : Nodes)
    {
        // NodeIdString을 UTF8 문자열로 변환
        FString NodeIdString = FString(Node.NodeId); // 노드 ID를 FString으로 생성
        UA_NodeId nodeId = UA_NODEID_STRING(6, TCHAR_TO_UTF8(*NodeIdString)); // TCHAR를 UTF8로 변환

        // DisplayName 가져오기
        UA_LocalizedText displayNameResult;
        UA_StatusCode status = UA_Client_readDisplayNameAttribute(MyClient, nodeId, &displayNameResult);
        if (status == UA_STATUSCODE_GOOD)
        {
            FString displayName = UTF8_TO_TCHAR(displayNameResult.text.data);
            UE_LOG(LogTemp, Log, TEXT("DisplayName: %s"), *displayName);

            // Locale 로그
            UE_LOG(LogTemp, Log, TEXT("DisplayName Locale: %s"), UTF8_TO_TCHAR(displayNameResult.locale.data));

            // Value 가져오기
            UA_Variant value;
            UA_Variant_init(&value); // value 초기화
            status = UA_Client_readValueAttribute(MyClient, nodeId, &value);
            FMyCustomStruct NodeInfo;
            NodeInfo.DisplayName = displayName;

            if (status == UA_STATUSCODE_GOOD)
            {
                // 자료형에 따른 값 읽기
                if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "Double") == 0 && value.type == &UA_TYPES[UA_TYPES_DOUBLE])
                {
                    NodeInfo.ValueDouble = *(double*)value.data; // Double 값 가져오기
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "Boolean") == 0 && value.type == &UA_TYPES[UA_TYPES_BOOLEAN])
                {
                    NodeInfo.ValueBool = *(bool*)value.data; // Boolean 값 가져오기
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "ByteString") == 0 && value.type == &UA_TYPES[UA_TYPES_BYTESTRING])
                {
                    NodeInfo.ValueByteString = TArray<uint8>((uint8*)value.data, ((UA_ByteString*)value.data)->length);
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "DateTime") == 0 && value.type == &UA_TYPES[UA_TYPES_DATETIME])
                {
                    NodeInfo.ValueDateTime = *(FDateTime*)value.data; // DateTime 값 가져오기
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "UInt16") == 0 && value.type == &UA_TYPES[UA_TYPES_UINT16])
                {
                    NodeInfo.ValueInt32 = *(uint16*)value.data; // UInt16 값 가져오기
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Unsupported data type for node %s"), *displayName);
                }
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("Failed to read value for node %s: %s"), *displayName, *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
            }

            // FMyNodeInfo 구조체 생성 후 배열에 추가
            MyStructArray.Add(NodeInfo);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to read display name for node %s: %s"), *Node.NodeId, *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
        }
    }
}

void AMyPlayerController::PrintMyStructArray()
{
    for (const FMyCustomStruct& Item : MyStructArray)
    {
        // 요소의 값을 출력 (예: Item의 특정 속성)
        FString OutputString;

        // 각 자료형에 따라 적절한 출력 형식 설정
        if (Item.ValueDouble != 0) // 더블 값이 있을 경우
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %f"), *Item.DisplayName, Item.ValueDouble);
        }
        else if (Item.ValueBool) // 불리언 값이 있을 경우
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %s"), *Item.DisplayName, Item.ValueBool ? TEXT("true") : TEXT("false"));
        }
        else if (Item.ValueInt32 != 0) // UInt16 값이 있을 경우
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %d"), *Item.DisplayName, Item.ValueInt32);
        }
        else if (Item.ValueDateTime != FDateTime::MinValue()) // DateTime 값이 있을 경우
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %s"), *Item.DisplayName, *Item.ValueDateTime.ToString());
        }
        else if (Item.ValueByteString.Num() > 0) // ByteString 값이 있을 경우
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: [ByteString data]"), *Item.DisplayName);
        }
        else
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: [Unsupported type]"), *Item.DisplayName);
        }

        // 로그에 출력
        UE_LOG(LogTemp, Warning, TEXT("%s"), *OutputString);

        // 화면에 출력 (Blueprint에서 Print String 사용)
        UKismetSystemLibrary::PrintString(this, OutputString, true, false, FLinearColor::Red, 2.0f);
    }
}

