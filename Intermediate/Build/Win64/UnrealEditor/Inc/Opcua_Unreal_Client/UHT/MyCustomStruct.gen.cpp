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
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMyCustomStruct();
UPackage* Z_Construct_UPackage__Script_Opcua_Unreal_Client();
// End Cross Module References

// Begin ScriptStruct FMyCustomStruct
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyCustomStruct;
class UScriptStruct* FMyCustomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyCustomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyCustomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyCustomStruct, (UObject*)Z_Construct_UPackage__Script_Opcua_Unreal_Client(), TEXT("MyCustomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_MyCustomStruct.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UScriptStruct* StaticStruct<FMyCustomStruct>()
{
	return FMyCustomStruct::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMyCustomStruct_Statics
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueDouble_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueBool_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueByteString_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueDateTime_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueInt32_MetaData[] = {
		{ "Category", "Node Data" },
		{ "ModuleRelativePath", "MyCustomStruct.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ValueDouble;
	static void NewProp_ValueBool_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ValueBool;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ValueByteString_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ValueByteString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ValueDateTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ValueInt32;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyCustomStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCustomStruct, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueDouble = { "ValueDouble", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCustomStruct, ValueDouble), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueDouble_MetaData), NewProp_ValueDouble_MetaData) };
void Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueBool_SetBit(void* Obj)
{
	((FMyCustomStruct*)Obj)->ValueBool = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueBool = { "ValueBool", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMyCustomStruct), &Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueBool_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueBool_MetaData), NewProp_ValueBool_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueByteString_Inner = { "ValueByteString", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueByteString = { "ValueByteString", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCustomStruct, ValueByteString), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueByteString_MetaData), NewProp_ValueByteString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueDateTime = { "ValueDateTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCustomStruct, ValueDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueDateTime_MetaData), NewProp_ValueDateTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueInt32 = { "ValueInt32", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCustomStruct, ValueInt32), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueInt32_MetaData), NewProp_ValueInt32_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyCustomStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueDouble,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueBool,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueByteString_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueByteString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueDateTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewProp_ValueInt32,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCustomStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyCustomStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
	nullptr,
	&NewStructOps,
	"MyCustomStruct",
	Z_Construct_UScriptStruct_FMyCustomStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCustomStruct_Statics::PropPointers),
	sizeof(FMyCustomStruct),
	alignof(FMyCustomStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCustomStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyCustomStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMyCustomStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyCustomStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyCustomStruct.InnerSingleton, Z_Construct_UScriptStruct_FMyCustomStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MyCustomStruct.InnerSingleton;
}
// End ScriptStruct FMyCustomStruct

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMyCustomStruct::StaticStruct, Z_Construct_UScriptStruct_FMyCustomStruct_Statics::NewStructOps, TEXT("MyCustomStruct"), &Z_Registration_Info_UScriptStruct_MyCustomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyCustomStruct), 3196960900U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_1674805910(TEXT("/Script/Opcua_Unreal_Client"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyCustomStruct_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
