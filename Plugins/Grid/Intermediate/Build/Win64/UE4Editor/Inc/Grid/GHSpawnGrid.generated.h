// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AGHHexActor;
#ifdef GRID_GHSpawnGrid_generated_h
#error "GHSpawnGrid.generated.h already included, missing '#pragma once' in GHSpawnGrid.h"
#endif
#define GRID_GHSpawnGrid_generated_h

#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_SPARSE_DATA
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInit); \
	DECLARE_FUNCTION(execBeginOverlap); \
	DECLARE_FUNCTION(execEndOverlap); \
	DECLARE_FUNCTION(execNeedMove); \
	DECLARE_FUNCTION(execHexSpawn);


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInit); \
	DECLARE_FUNCTION(execBeginOverlap); \
	DECLARE_FUNCTION(execEndOverlap); \
	DECLARE_FUNCTION(execNeedMove); \
	DECLARE_FUNCTION(execHexSpawn);


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGHSpawnGrid(); \
	friend struct Z_Construct_UClass_AGHSpawnGrid_Statics; \
public: \
	DECLARE_CLASS(AGHSpawnGrid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHSpawnGrid)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAGHSpawnGrid(); \
	friend struct Z_Construct_UClass_AGHSpawnGrid_Statics; \
public: \
	DECLARE_CLASS(AGHSpawnGrid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHSpawnGrid)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGHSpawnGrid(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGHSpawnGrid) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHSpawnGrid); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHSpawnGrid); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHSpawnGrid(AGHSpawnGrid&&); \
	NO_API AGHSpawnGrid(const AGHSpawnGrid&); \
public:


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHSpawnGrid(AGHSpawnGrid&&); \
	NO_API AGHSpawnGrid(const AGHSpawnGrid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHSpawnGrid); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHSpawnGrid); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGHSpawnGrid)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SceneComponent() { return STRUCT_OFFSET(AGHSpawnGrid, SceneComponent); } \
	FORCEINLINE static uint32 __PPO__StatickMesh() { return STRUCT_OFFSET(AGHSpawnGrid, StatickMesh); } \
	FORCEINLINE static uint32 __PPO__HexArray() { return STRUCT_OFFSET(AGHSpawnGrid, HexArray); } \
	FORCEINLINE static uint32 __PPO__HexActorClass() { return STRUCT_OFFSET(AGHSpawnGrid, HexActorClass); } \
	FORCEINLINE static uint32 __PPO__Hex() { return STRUCT_OFFSET(AGHSpawnGrid, Hex); } \
	FORCEINLINE static uint32 __PPO__ArrayHexComponents() { return STRUCT_OFFSET(AGHSpawnGrid, ArrayHexComponents); } \
	FORCEINLINE static uint32 __PPO__HexComponent() { return STRUCT_OFFSET(AGHSpawnGrid, HexComponent); }


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_10_PROLOG
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_RPC_WRAPPERS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_INCLASS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_INCLASS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GRID_API UClass* StaticClass<class AGHSpawnGrid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GloomHaven_Plugins_Grid_Source_Grid_Public_GHSpawnGrid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
