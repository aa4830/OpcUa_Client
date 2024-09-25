#pragma once

#include "CoreMinimal.h"
#include "MyCustomStruct.generated.h"

USTRUCT(BlueprintType)
struct FMyCustomStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    double Value;

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    bool ValueBool;

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    TArray<uint8> ValueByteString;

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    FDateTime ValueDateTime;

    UPROPERTY(BlueprintReadWrite, Category = "Node Info")
    int32 ValueUInt16;  // uint16에서 int32로 변경
};