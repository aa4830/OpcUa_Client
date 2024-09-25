#include "MyPlayerController.h"
#include "client.h"  // open62541 Ŭ���̾�Ʈ ���
#include "client_highlevel.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyCustomStruct.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
    MyClient = nullptr;  // Ŭ���̾�Ʈ �ʱ�ȭ
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

    // ������ �б� (5�ʸ���)
    static float Timer = 0.0f;
    Timer += DeltaTime;
    if (Timer >= 5.0f)
    {
        Timer = 0.0f;  // Ÿ�̸� ����
    }
}

void AMyPlayerController::ConnectToOpcUaServer()
{
    // OPC UA Ŭ���̾�Ʈ ����
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
        // NodeIdString�� UTF8 ���ڿ��� ��ȯ
        FString NodeIdString = FString(Node.NodeId); // ��� ID�� FString���� ����
        UA_NodeId nodeId = UA_NODEID_STRING(6, TCHAR_TO_UTF8(*NodeIdString)); // TCHAR�� UTF8�� ��ȯ

        // DisplayName ��������
        UA_LocalizedText displayNameResult;
        UA_StatusCode status = UA_Client_readDisplayNameAttribute(MyClient, nodeId, &displayNameResult);
        if (status == UA_STATUSCODE_GOOD)
        {
            FString displayName = UTF8_TO_TCHAR(displayNameResult.text.data);
            UE_LOG(LogTemp, Log, TEXT("DisplayName: %s"), *displayName);

            // Locale �α�
            UE_LOG(LogTemp, Log, TEXT("DisplayName Locale: %s"), UTF8_TO_TCHAR(displayNameResult.locale.data));

            // Value ��������
            UA_Variant value;
            UA_Variant_init(&value); // value �ʱ�ȭ
            status = UA_Client_readValueAttribute(MyClient, nodeId, &value);
            FMyCustomStruct NodeInfo;
            NodeInfo.DisplayName = displayName;

            if (status == UA_STATUSCODE_GOOD)
            {
                // �ڷ����� ���� �� �б�
                if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "Double") == 0 && value.type == &UA_TYPES[UA_TYPES_DOUBLE])
                {
                    NodeInfo.ValueDouble = *(double*)value.data; // Double �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "Boolean") == 0 && value.type == &UA_TYPES[UA_TYPES_BOOLEAN])
                {
                    NodeInfo.ValueBool = *(bool*)value.data; // Boolean �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "ByteString") == 0 && value.type == &UA_TYPES[UA_TYPES_BYTESTRING])
                {
                    NodeInfo.ValueByteString = TArray<uint8>((uint8*)value.data, ((UA_ByteString*)value.data)->length);
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "DateTime") == 0 && value.type == &UA_TYPES[UA_TYPES_DATETIME])
                {
                    NodeInfo.ValueDateTime = *(FDateTime*)value.data; // DateTime �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "UInt16") == 0 && value.type == &UA_TYPES[UA_TYPES_UINT16])
                {
                    NodeInfo.ValueInt32 = *(uint16*)value.data; // UInt16 �� ��������
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

            // FMyNodeInfo ����ü ���� �� �迭�� �߰�
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
        // ����� ���� ��� (��: Item�� Ư�� �Ӽ�)
        FString OutputString;

        // �� �ڷ����� ���� ������ ��� ���� ����
        if (Item.ValueDouble != 0) // ���� ���� ���� ���
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %f"), *Item.DisplayName, Item.ValueDouble);
        }
        else if (Item.ValueBool) // �Ҹ��� ���� ���� ���
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %s"), *Item.DisplayName, Item.ValueBool ? TEXT("true") : TEXT("false"));
        }
        else if (Item.ValueInt32 != 0) // UInt16 ���� ���� ���
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %d"), *Item.DisplayName, Item.ValueInt32);
        }
        else if (Item.ValueDateTime != FDateTime::MinValue()) // DateTime ���� ���� ���
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: %s"), *Item.DisplayName, *Item.ValueDateTime.ToString());
        }
        else if (Item.ValueByteString.Num() > 0) // ByteString ���� ���� ���
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: [ByteString data]"), *Item.DisplayName);
        }
        else
        {
            OutputString = FString::Printf(TEXT("Display Name: %s, Value: [Unsupported type]"), *Item.DisplayName);
        }

        // �α׿� ���
        UE_LOG(LogTemp, Warning, TEXT("%s"), *OutputString);

        // ȭ�鿡 ��� (Blueprint���� Print String ���)
        UKismetSystemLibrary::PrintString(this, OutputString, true, false, FLinearColor::Red, 2.0f);
    }
}

