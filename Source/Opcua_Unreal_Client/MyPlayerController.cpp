// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "client.h"  // open62541 Ŭ���̾�Ʈ ���
#include "client_highlevel.h"
#include "Components/EditableTextBox.h" 
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

    // OPC UA ������ ����
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
        ReadNumberDataFromOpcUa();
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

    // ������ ���� (���� URL ���� �ʿ�)
    UA_StatusCode status = UA_Client_connect(MyClient, "opc.tcp://uademo.prosysopc.com:53530/OPCUA/SimulationServer");
    if (status != UA_STATUSCODE_GOOD)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to connect to OPC UA server: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
        UA_Client_delete(MyClient);
        MyClient = nullptr;
    }
}

void AMyPlayerController::ReadNumberDataFromOpcUa()
{
    if (MyClient == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Client is not initialized"));
        return;
    }

    UA_Variant value; // OPC UA���� �پ��� Ÿ���� ���� ������ �� �ִ� ����ü
    UA_Variant_init(&value); // ����ü �ʱ�ȭ
    UA_NodeId nodeId = UA_NODEID_STRING(5, const_cast<char*>("ByteArray"));  // namespace index�� 5�̰�, ��� ID�� "Number"�� ���

    UA_StatusCode status = UA_Client_readValueAttribute(MyClient, nodeId, &value); // Ư�� ����� ���� �а�, value�� ����
    if (status == UA_STATUSCODE_GOOD)
    {
        // ���� Ÿ�� Ȯ�� �� �α� ���
        UE_LOG(LogTemp, Log, TEXT("Value type received: %s"), *FString(UTF8_TO_TCHAR(value.type->typeName)));

        if (value.type == &UA_TYPES[UA_TYPES_BYTE])    //Byte Ÿ�� ó��.
        {
            uint8 byteValue = *(uint8*)value.data;
            UEditableTextBox* EditableTextBox = Cast<UEditableTextBox>(MyWidget->GetWidgetFromName(TEXT("EditableTextBox_1")));
            if (EditableTextBox)
            {
                // float ���� FString���� ��ȯ �� ����
                EditableTextBox->SetText(FText::FromString(FString::Printf(TEXT("%f"), byteValue))); // �ؽ�Ʈ ����
            }
        }
        else if (value.type == &UA_TYPES[UA_TYPES_INT32]) // Int32 Ÿ�� ó��
        {
            int32 intValue = *(int32*)value.data; // Int32 �� ��������
            UEditableTextBox* EditableTextBox = Cast<UEditableTextBox>(MyWidget->GetWidgetFromName(TEXT("EditableTextBox_1")));
            if (EditableTextBox)
            {
                // Int32 ���� FString���� ��ȯ �� ����
                EditableTextBox->SetText(FText::FromString(FString::Printf(TEXT("%d"), intValue))); // �ؽ�Ʈ ����
            }
        }
        else // ������
        {
            UE_LOG(LogTemp, Warning, TEXT("������������ �ڷ���"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("������ �б� ����: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
    }

    UA_Variant_clear(&value);  // �޸� ����
}