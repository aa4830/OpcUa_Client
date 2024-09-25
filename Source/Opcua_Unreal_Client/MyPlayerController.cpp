#include "MyPlayerController.h"
#include "client.h"  // open62541 Ŭ���̾�Ʈ ���
#include "client_highlevel.h"
#include "MyCustomStruct.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
    MyClient = nullptr;  // Ŭ���̾�Ʈ �ʱ�ȭ

    ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/Wg_Test"));
    if (WidgetClass.Succeeded())
    {
        MyWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass.Class);
        if (MyWidget)
        {
            MyWidget->AddToViewport();
        }
    }
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    ConnectToOpcUaServer();
}

void AMyPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ������ �б� (1�ʸ���)
    static float Timer = 0.0f;
    Timer += DeltaTime;
    if (Timer >= 1.0f)
    {
        ReadMyLevelDataFromOpcUa();
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

    TArray<FMyCustomStruct> NodeInfoArray; // ��� ������ ������ �迭

    struct FNodeData
    {
        FString NodeId; // Node ID
        FString DisplayName; // Display Name
        FString DataType; // Data Type
    };

    FNodeData Nodes[] =
    {
        { TEXT("ns=6;s=MyLevel"), TEXT("My Level"), TEXT("double") },
        { TEXT("ns=6;s=MySwitch"), TEXT("My Switch"), TEXT("boolean") },
        { TEXT("ns=6;s=Eventid"), TEXT("Eventid"), TEXT("bytestring") },
        { TEXT("ns=6;s=receivetime"), TEXT("receivetime"), TEXT("datetime") },
        { TEXT("ns=6;s=severity"), TEXT("severity"), TEXT("uint16") }
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

            // Value ��������
            UA_Variant value;
            UA_Variant_init(&value); // value �ʱ�ȭ
            status = UA_Client_readValueAttribute(MyClient, nodeId, &value);
            FMyCustomStruct NodeInfo;
            NodeInfo.DisplayName = displayName;

            if (status == UA_STATUSCODE_GOOD)
            {
                // �ڷ����� ���� �� �б�
                if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "double") == 0 && value.type == &UA_TYPES[UA_TYPES_DOUBLE])
                {
                    NodeInfo.Value = *(double*)value.data; // Double �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "boolean") == 0 && value.type == &UA_TYPES[UA_TYPES_BOOLEAN])
                {
                    NodeInfo.ValueBool = *(bool*)value.data; // Boolean �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "bytestring") == 0 && value.type == &UA_TYPES[UA_TYPES_BYTESTRING])
                {
                    NodeInfo.ValueByteString = TArray<uint8>((uint8*)value.data, ((UA_ByteString*)value.data)->length);
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "datetime") == 0 && value.type == &UA_TYPES[UA_TYPES_DATETIME])
                {
                    NodeInfo.ValueDateTime = *(FDateTime*)value.data; // DateTime �� ��������
                }
                else if (strcmp(TCHAR_TO_UTF8(*Node.DataType), "uint16") == 0 && value.type == &UA_TYPES[UA_TYPES_UINT16])
                {
                    NodeInfo.ValueUInt16 = *(uint16*)value.data; // UInt16 �� ��������
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
            NodeInfoArray.Add(NodeInfo);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to read display name for node %s: %s"), *Node.NodeId, *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
        }
    }
}
