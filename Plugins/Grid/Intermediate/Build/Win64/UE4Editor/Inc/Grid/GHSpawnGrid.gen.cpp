// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Grid/Public/GHSpawnGrid.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGHSpawnGrid() {}
// Cross Module References
	GRID_API UClass* Z_Construct_UClass_AGHSpawnGrid_NoRegister();
	GRID_API UClass* Z_Construct_UClass_AGHSpawnGrid();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Grid();
	GRID_API UClass* Z_Construct_UClass_AGHHexActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AGHSpawnGrid::execInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Init();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AGHSpawnGrid::execBeginOverlap)
	{
		P_GET_OBJECT(AGHHexActor,Z_Param_ActorStart);
		P_GET_OBJECT(AGHHexActor,Z_Param_ActorEnd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginOverlap(Z_Param_ActorStart,Z_Param_ActorEnd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AGHSpawnGrid::execEndOverlap)
	{
		P_GET_OBJECT(AGHHexActor,Z_Param_ActorEnd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndOverlap(Z_Param_ActorEnd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AGHSpawnGrid::execNeedMove)
	{
		P_GET_OBJECT(AGHHexActor,Z_Param_ActorEnd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NeedMove(Z_Param_ActorEnd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AGHSpawnGrid::execHexSpawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HexSpawn();
		P_NATIVE_END;
	}
	void AGHSpawnGrid::StaticRegisterNativesAGHSpawnGrid()
	{
		UClass* Class = AGHSpawnGrid::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginOverlap", &AGHSpawnGrid::execBeginOverlap },
			{ "EndOverlap", &AGHSpawnGrid::execEndOverlap },
			{ "HexSpawn", &AGHSpawnGrid::execHexSpawn },
			{ "Init", &AGHSpawnGrid::execInit },
			{ "NeedMove", &AGHSpawnGrid::execNeedMove },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics
	{
		struct GHSpawnGrid_eventBeginOverlap_Parms
		{
			AGHHexActor* ActorStart;
			AGHHexActor* ActorEnd;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorStart;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorEnd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::NewProp_ActorStart = { "ActorStart", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GHSpawnGrid_eventBeginOverlap_Parms, ActorStart), Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::NewProp_ActorEnd = { "ActorEnd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GHSpawnGrid_eventBeginOverlap_Parms, ActorEnd), Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::NewProp_ActorStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::NewProp_ActorEnd,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGHSpawnGrid, nullptr, "BeginOverlap", nullptr, nullptr, sizeof(GHSpawnGrid_eventBeginOverlap_Parms), Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics
	{
		struct GHSpawnGrid_eventEndOverlap_Parms
		{
			AGHHexActor* ActorEnd;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorEnd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::NewProp_ActorEnd = { "ActorEnd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GHSpawnGrid_eventEndOverlap_Parms, ActorEnd), Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::NewProp_ActorEnd,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGHSpawnGrid, nullptr, "EndOverlap", nullptr, nullptr, sizeof(GHSpawnGrid_eventEndOverlap_Parms), Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGHSpawnGrid_EndOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGHSpawnGrid_EndOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGHSpawnGrid, nullptr, "HexSpawn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGHSpawnGrid_HexSpawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGHSpawnGrid_HexSpawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGHSpawnGrid_Init_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGHSpawnGrid_Init_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGHSpawnGrid_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGHSpawnGrid, nullptr, "Init", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGHSpawnGrid_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGHSpawnGrid_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGHSpawnGrid_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics
	{
		struct GHSpawnGrid_eventNeedMove_Parms
		{
			AGHHexActor* ActorEnd;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorEnd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::NewProp_ActorEnd = { "ActorEnd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GHSpawnGrid_eventNeedMove_Parms, ActorEnd), Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::NewProp_ActorEnd,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGHSpawnGrid, nullptr, "NeedMove", nullptr, nullptr, sizeof(GHSpawnGrid_eventNeedMove_Parms), Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGHSpawnGrid_NeedMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGHSpawnGrid_NeedMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGHSpawnGrid_NoRegister()
	{
		return AGHSpawnGrid::StaticClass();
	}
	struct Z_Construct_UClass_AGHSpawnGrid_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HexArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HexArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_HexArray;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SizeX_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SizeX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SizeY_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SizeY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HexActorClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_HexActorClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hex_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Hex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HexMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_HexMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGHSpawnGrid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Grid,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGHSpawnGrid_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGHSpawnGrid_BeginOverlap, "BeginOverlap" }, // 1215854140
		{ &Z_Construct_UFunction_AGHSpawnGrid_EndOverlap, "EndOverlap" }, // 1363754182
		{ &Z_Construct_UFunction_AGHSpawnGrid_HexSpawn, "HexSpawn" }, // 3295161535
		{ &Z_Construct_UFunction_AGHSpawnGrid_Init, "Init" }, // 2103590513
		{ &Z_Construct_UFunction_AGHSpawnGrid_NeedMove, "NeedMove" }, // 129221069
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GHSpawnGrid.h" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "GHSpawnGrid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SceneComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SceneComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray_Inner = { "HexArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray_MetaData[] = {
		{ "Category", "GHSpawnGrid" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray = { "HexArray", nullptr, (EPropertyFlags)0x0020080000000004, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, HexArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeX_MetaData[] = {
		{ "Category", "SizeGrid" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeX = { "SizeX", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, SizeX), METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeY_MetaData[] = {
		{ "Category", "SizeGrid" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeY = { "SizeY", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, SizeY), METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexActorClass_MetaData[] = {
		{ "Category", "GHSpawnGrid" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexActorClass = { "HexActorClass", nullptr, (EPropertyFlags)0x0044000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, HexActorClass), Z_Construct_UClass_AGHHexActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexActorClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexActorClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_Hex_MetaData[] = {
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_Hex = { "Hex", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, Hex), Z_Construct_UClass_AGHHexActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_Hex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_Hex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexMesh_MetaData[] = {
		{ "Category", "GHSpawnGrid" },
		{ "ModuleRelativePath", "Public/GHSpawnGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexMesh = { "HexMesh", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGHSpawnGrid, HexMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGHSpawnGrid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SceneComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_SizeY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexActorClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_Hex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGHSpawnGrid_Statics::NewProp_HexMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGHSpawnGrid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGHSpawnGrid>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGHSpawnGrid_Statics::ClassParams = {
		&AGHSpawnGrid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AGHSpawnGrid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGHSpawnGrid_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGHSpawnGrid_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGHSpawnGrid()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGHSpawnGrid_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGHSpawnGrid, 834693223);
	template<> GRID_API UClass* StaticClass<AGHSpawnGrid>()
	{
		return AGHSpawnGrid::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGHSpawnGrid(Z_Construct_UClass_AGHSpawnGrid, &AGHSpawnGrid::StaticClass, TEXT("/Script/Grid"), TEXT("AGHSpawnGrid"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGHSpawnGrid);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
