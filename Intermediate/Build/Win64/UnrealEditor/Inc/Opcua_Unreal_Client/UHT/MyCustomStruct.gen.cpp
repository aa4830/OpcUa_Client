// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Opcua_Unreal_Client/MyCustomStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCustomStruct() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FEventIdStruct();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMyLevelStruct();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMySwitchStruct();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FReciveTimeStruct();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FSeverityStruct();
UPackage* Z_Construct_UPackage__Script_Opcua_Unreal_Client();
// End Cross Module References

// Begin ScriptStruct FMyLevelStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyLevelStruct;
class UScriptStruct* FMyLevelStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyLevelStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyLevelStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyLevelStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("MyLevelStruct"));
	}
	return Z_Registration_Info_UScriptStruct_MyLevelStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FMyLevelStruct>()
{
	return FMyLevelStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMyLevelStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataType_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueDouble_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DataType;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ValueDouble;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyLevelStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyLevelStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_DataType = { "DataType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyLevelStruct, DataType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataType_MetaData), NewProp_DataType_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_ValueDouble = { "ValueDouble", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyLevelStruct, ValueDouble), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueDouble_MetaData), NewProp_ValueDouble_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyLevelStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_DataType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewProp_ValueDouble,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyLevelStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyLevelStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"MyLevelStruct",
	Z_Construct_UScriptStruct_FMyLevelStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyLevelStruct_Statics::PropPointers),
	sizeof(FMyLevelStruct),
	alignof(FMyLevelStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyLevelStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyLevelStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMyLevelStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyLevelStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyLevelStruct.InnerSingleton, Z_Construct_UScriptStruct_FMyLevelStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MyLevelStruct.InnerSingleton;
}
// End ScriptStruct FMyLevelStruct

// Begin ScriptStruct FMySwitchStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MySwitchStruct;
class UScriptStruct* FMySwitchStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySwitchStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MySwitchStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMySwitchStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("MySwitchStruct"));
	}
	return Z_Registration_Info_UScriptStruct_MySwitchStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FMySwitchStruct>()
{
	return FMySwitchStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMySwitchStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataType_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueBool_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DataType;
	static void NewProp_ValueBool_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ValueBool;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMySwitchStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMySwitchStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_DataType = { "DataType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMySwitchStruct, DataType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataType_MetaData), NewProp_DataType_MetaData) };
void Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_ValueBool_SetBit(void* Obj)
{
	((FMySwitchStruct*)Obj)->ValueBool = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_ValueBool = { "ValueBool", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMySwitchStruct), &Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_ValueBool_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueBool_MetaData), NewProp_ValueBool_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMySwitchStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_DataType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewProp_ValueBool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySwitchStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMySwitchStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"MySwitchStruct",
	Z_Construct_UScriptStruct_FMySwitchStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySwitchStruct_Statics::PropPointers),
	sizeof(FMySwitchStruct),
	alignof(FMySwitchStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySwitchStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMySwitchStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMySwitchStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySwitchStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MySwitchStruct.InnerSingleton, Z_Construct_UScriptStruct_FMySwitchStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MySwitchStruct.InnerSingleton;
}
// End ScriptStruct FMySwitchStruct

// Begin ScriptStruct FEventIdStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_EventIdStruct;
class UScriptStruct* FEventIdStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EventIdStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_EventIdStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEventIdStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("EventIdStruct"));
	}
	return Z_Registration_Info_UScriptStruct_EventIdStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FEventIdStruct>()
{
	return FEventIdStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEventIdStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataType_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueByteString_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DataType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ValueByteString_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ValueByteString;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEventIdStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEventIdStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_DataType = { "DataType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEventIdStruct, DataType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataType_MetaData), NewProp_DataType_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_ValueByteString_Inner = { "ValueByteString", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_ValueByteString = { "ValueByteString", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEventIdStruct, ValueByteString), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueByteString_MetaData), NewProp_ValueByteString_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEventIdStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_DataType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_ValueByteString_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewProp_ValueByteString,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEventIdStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEventIdStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"EventIdStruct",
	Z_Construct_UScriptStruct_FEventIdStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEventIdStruct_Statics::PropPointers),
	sizeof(FEventIdStruct),
	alignof(FEventIdStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEventIdStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEventIdStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEventIdStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EventIdStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_EventIdStruct.InnerSingleton, Z_Construct_UScriptStruct_FEventIdStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_EventIdStruct.InnerSingleton;
}
// End ScriptStruct FEventIdStruct

// Begin ScriptStruct FReciveTimeStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ReciveTimeStruct;
class UScriptStruct* FReciveTimeStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ReciveTimeStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ReciveTimeStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FReciveTimeStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("ReciveTimeStruct"));
	}
	return Z_Registration_Info_UScriptStruct_ReciveTimeStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FReciveTimeStruct>()
{
	return FReciveTimeStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FReciveTimeStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataType_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueDateTime_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DataType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ValueDateTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FReciveTimeStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReciveTimeStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_DataType = { "DataType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReciveTimeStruct, DataType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataType_MetaData), NewProp_DataType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_ValueDateTime = { "ValueDateTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReciveTimeStruct, ValueDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueDateTime_MetaData), NewProp_ValueDateTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_DataType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewProp_ValueDateTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"ReciveTimeStruct",
	Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::PropPointers),
	sizeof(FReciveTimeStruct),
	alignof(FReciveTimeStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FReciveTimeStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ReciveTimeStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ReciveTimeStruct.InnerSingleton, Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ReciveTimeStruct.InnerSingleton;
}
// End ScriptStruct FReciveTimeStruct

// Begin ScriptStruct FSeverityStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SeverityStruct;
class UScriptStruct* FSeverityStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SeverityStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SeverityStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSeverityStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("SeverityStruct"));
	}
	return Z_Registration_Info_UScriptStruct_SeverityStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FSeverityStruct>()
{
	return FSeverityStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSeverityStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataType_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueInt32_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DataType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ValueInt32;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSeverityStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSeverityStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_DataType = { "DataType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSeverityStruct, DataType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataType_MetaData), NewProp_DataType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_ValueInt32 = { "ValueInt32", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSeverityStruct, ValueInt32), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueInt32_MetaData), NewProp_ValueInt32_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSeverityStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_DataType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewProp_ValueInt32,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSeverityStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSeverityStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"SeverityStruct",
	Z_Construct_UScriptStruct_FSeverityStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSeverityStruct_Statics::PropPointers),
	sizeof(FSeverityStruct),
	alignof(FSeverityStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSeverityStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSeverityStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSeverityStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SeverityStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SeverityStruct.InnerSingleton, Z_Construct_UScriptStruct_FSeverityStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SeverityStruct.InnerSingleton;
}
// End ScriptStruct FSeverityStruct

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMyLevelStruct::StaticStruct, Z_Construct_UScriptStruct_FMyLevelStruct_Statics::NewStructOps, TEXT("MyLevelStruct"), &Z_Registration_Info_UScriptStruct_MyLevelStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyLevelStruct), 2770169882U) },
		{ FMySwitchStruct::StaticStruct, Z_Construct_UScriptStruct_FMySwitchStruct_Statics::NewStructOps, TEXT("MySwitchStruct"), &Z_Registration_Info_UScriptStruct_MySwitchStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMySwitchStruct), 777077150U) },
		{ FEventIdStruct::StaticStruct, Z_Construct_UScriptStruct_FEventIdStruct_Statics::NewStructOps, TEXT("EventIdStruct"), &Z_Registration_Info_UScriptStruct_EventIdStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEventIdStruct), 2163169764U) },
		{ FReciveTimeStruct::StaticStruct, Z_Construct_UScriptStruct_FReciveTimeStruct_Statics::NewStructOps, TEXT("ReciveTimeStruct"), &Z_Registration_Info_UScriptStruct_ReciveTimeStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FReciveTimeStruct), 1170812267U) },
		{ FSeverityStruct::StaticStruct, Z_Construct_UScriptStruct_FSeverityStruct_Statics::NewStructOps, TEXT("SeverityStruct"), &Z_Registration_Info_UScriptStruct_SeverityStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSeverityStruct), 2399962205U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_3126528971(TEXT("/Script/Opcua_Unreal_Client"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
