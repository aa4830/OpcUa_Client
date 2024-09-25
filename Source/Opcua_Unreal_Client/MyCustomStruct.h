#pragma once

#include "CoreMinimal.h"
#include "MyCustomStruct.generated.h"

USTRUCT(BlueprintType)
struct FMyCustomStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    double ValueDouble;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    bool ValueBool;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    TArray<uint8> ValueByteString;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FDateTime ValueDateTime;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    int32 ValueInt32; // uint16 대신 int32 사용
};