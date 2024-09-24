// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "client.h"  // open62541 클라이언트 헤더
#include "client_highlevel.h"
#include "Components/EditableTextBox.h" 
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
    MyClient = nullptr;  // 클라이언트 초기화

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

    // OPC UA 서버에 연결
    ConnectToOpcUaServer();
}
void AMyPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 데이터 읽기 (1초마다)
    static float Timer = 0.0f;
    Timer += DeltaTime;
    if (Timer >= 1.0f)
    {
        ReadNumberDataFromOpcUa();
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

    // 서버에 연결 (서버 URL 변경 필요)
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

    UA_Variant value; // OPC UA에서 다양한 타입의 값을 저장할 수 있는 구조체
    UA_Variant_init(&value); // 구조체 초기화
    UA_NodeId nodeId = UA_NODEID_STRING(5, const_cast<char*>("ByteArray"));  // namespace index가 5이고, 노드 ID가 "Number"인 노드

    UA_StatusCode status = UA_Client_readValueAttribute(MyClient, nodeId, &value); // 특정 노드의 값을 읽고, value에 저장
    if (status == UA_STATUSCODE_GOOD)
    {
        // 실제 타입 확인 및 로그 출력
        UE_LOG(LogTemp, Log, TEXT("Value type received: %s"), *FString(UTF8_TO_TCHAR(value.type->typeName)));

        if (value.type == &UA_TYPES[UA_TYPES_BYTE])    //Byte 타입 처리.
        {
            uint8 byteValue = *(uint8*)value.data;
            UEditableTextBox* EditableTextBox = Cast<UEditableTextBox>(MyWidget->GetWidgetFromName(TEXT("EditableTextBox_1")));
            if (EditableTextBox)
            {
                // float 값을 FString으로 변환 후 설정
                EditableTextBox->SetText(FText::FromString(FString::Printf(TEXT("%f"), byteValue))); // 텍스트 설정
            }
        }
        else if (value.type == &UA_TYPES[UA_TYPES_INT32]) // Int32 타입 처리
        {
            int32 intValue = *(int32*)value.data; // Int32 값 가져오기
            UEditableTextBox* EditableTextBox = Cast<UEditableTextBox>(MyWidget->GetWidgetFromName(TEXT("EditableTextBox_1")));
            if (EditableTextBox)
            {
                // Int32 값을 FString으로 변환 후 설정
                EditableTextBox->SetText(FText::FromString(FString::Printf(TEXT("%d"), intValue))); // 텍스트 설정
            }
        }
        else // 나머지
        {
            UE_LOG(LogTemp, Warning, TEXT("예상하지못한 자료형"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("데이터 읽기 실패: %s"), *FString(UTF8_TO_TCHAR(UA_StatusCode_name(status))));
    }

    UA_Variant_clear(&value);  // 메모리 해제
}