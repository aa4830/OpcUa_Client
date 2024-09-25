// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Opcua_Unreal_Client/MyPlayerController.h"
#include "Opcua_Unreal_Client/MyCustomStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
OPCUA_UNREAL_CLIENT_API UClass* Z_Construct_UClass_AMyPlayerController();
OPCUA_UNREAL_CLIENT_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();
OPCUA_UNREAL_CLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FMyCustomStruct();
UPackage* Z_Construct_UPackage__Script_Opcua_Unreal_Client();
// End Cross Module References

// Begin Class AMyPlayerController Function PrintMyStructArray
struct Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "My Functions" },
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "PrintMyStructArray", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execPrintMyStructArray)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PrintMyStructArray();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function PrintMyStructArray

// Begin Class AMyPlayerController
void AMyPlayerController::StaticRegisterNativesAMyPlayerController()
{
	UClass* Class = AMyPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PrintMyStructArray", &AMyPlayerController::execPrintMyStructArray },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyPlayerController);
UClass* Z_Construct_UClass_AMyPlayerController_NoRegister()
{
	return AMyPlayerController::StaticClass();
}
struct Z_Construct_UClass_AMyPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MyPlayerController.h" },
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MyStructArray_MetaData[] = {
		{ "Category", "My Custom Structs" },
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MyStructArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MyStructArray;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyPlayerController_PrintMyStructArray, "PrintMyStructArray" }, // 1316193893
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_MyStructArray_Inner = { "MyStructArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMyCustomStruct, METADATA_PARAMS(0, nullptr) }; // 3196960900
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_MyStructArray = { "MyStructArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayerController, MyStructArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MyStructArray_MetaData), NewProp_MyStructArray_MetaData) }; // 3196960900
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_MyStructArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_MyStructArray,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Opcua_Unreal_Client,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyPlayerController_Statics::ClassParams = {
	&AMyPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyPlayerController()
{
	if (!Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton, Z_Construct_UClass_AMyPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton;
}
template<> OPCUA_UNREAL_CLIENT_API UClass* StaticClass<AMyPlayerController>()
{
	return AMyPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPlayerController);
AMyPlayerController::~AMyPlayerController() {}
// End Class AMyPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyPlayerController, AMyPlayerController::StaticClass, TEXT("AMyPlayerController"), &Z_Registration_Info_UClass_AMyPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyPlayerController), 3255381908U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyPlayerController_h_3313463172(TEXT("/Script/Opcua_Unreal_Client"),
	Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Opcua_Unreal_Client_Source_Opcua_Unreal_Client_MyPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
