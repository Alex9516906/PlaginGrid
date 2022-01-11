// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GRID_GHCharacter_generated_h
#error "GHCharacter.generated.h already included, missing '#pragma once' in GHCharacter.h"
#endif
#define GRID_GHCharacter_generated_h

#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_SPARSE_DATA
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_RPC_WRAPPERS
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGHCharacter(); \
	friend struct Z_Construct_UClass_AGHCharacter_Statics; \
public: \
	DECLARE_CLASS(AGHCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHCharacter)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAGHCharacter(); \
	friend struct Z_Construct_UClass_AGHCharacter_Statics; \
public: \
	DECLARE_CLASS(AGHCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHCharacter)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGHCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGHCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHCharacter(AGHCharacter&&); \
	NO_API AGHCharacter(const AGHCharacter&); \
public:


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHCharacter(AGHCharacter&&); \
	NO_API AGHCharacter(const AGHCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGHCharacter)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MoveComponent() { return STRUCT_OFFSET(AGHCharacter, MoveComponent); } \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AGHCharacter, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AGHCharacter, Camera); }


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_14_PROLOG
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_RPC_WRAPPERS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_INCLASS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_INCLASS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GRID_API UClass* StaticClass<class AGHCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GloomHaven_Plugins_Grid_Source_Grid_Public_GHCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
