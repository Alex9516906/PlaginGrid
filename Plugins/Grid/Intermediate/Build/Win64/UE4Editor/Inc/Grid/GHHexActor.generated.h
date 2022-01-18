// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AGHHexActor;
class UPrimitiveComponent;
struct FKey;
#ifdef GRID_GHHexActor_generated_h
#error "GHHexActor.generated.h already included, missing '#pragma once' in GHHexActor.h"
#endif
#define GRID_GHHexActor_generated_h

#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_16_DELEGATE \
static inline void FInitSpawn_DelegateWrapper(const FMulticastScriptDelegate& InitSpawn) \
{ \
	InitSpawn.ProcessMulticastDelegate<UObject>(NULL); \
}


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_15_DELEGATE \
struct _Script_Grid_eventOnEndMouseOverlap_Parms \
{ \
	AGHHexActor* ActorEnd; \
}; \
static inline void FOnEndMouseOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnEndMouseOverlap, AGHHexActor* ActorEnd) \
{ \
	_Script_Grid_eventOnEndMouseOverlap_Parms Parms; \
	Parms.ActorEnd=ActorEnd; \
	OnEndMouseOverlap.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_14_DELEGATE \
struct _Script_Grid_eventOnBeginMouseOverlap_Parms \
{ \
	AGHHexActor* ActorStart; \
	AGHHexActor* ActorEnd; \
}; \
static inline void FOnBeginMouseOverlap_DelegateWrapper(const FMulticastScriptDelegate& OnBeginMouseOverlap, AGHHexActor* ActorStart, AGHHexActor* ActorEnd) \
{ \
	_Script_Grid_eventOnBeginMouseOverlap_Parms Parms; \
	Parms.ActorStart=ActorStart; \
	Parms.ActorEnd=ActorEnd; \
	OnBeginMouseOverlap.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_13_DELEGATE \
struct _Script_Grid_eventOnClickToMove_Parms \
{ \
	AGHHexActor* ActorEnd; \
}; \
static inline void FOnClickToMove_DelegateWrapper(const FMulticastScriptDelegate& OnClickToMove, AGHHexActor* ActorEnd) \
{ \
	_Script_Grid_eventOnClickToMove_Parms Parms; \
	Parms.ActorEnd=ActorEnd; \
	OnClickToMove.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_SPARSE_DATA
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnClickMouse); \
	DECLARE_FUNCTION(execEndOverlapCursor); \
	DECLARE_FUNCTION(execBeginOverlapCursor); \
	DECLARE_FUNCTION(execFCost); \
	DECLARE_FUNCTION(execSetIsClear); \
	DECLARE_FUNCTION(execIsClear);


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnClickMouse); \
	DECLARE_FUNCTION(execEndOverlapCursor); \
	DECLARE_FUNCTION(execBeginOverlapCursor); \
	DECLARE_FUNCTION(execFCost); \
	DECLARE_FUNCTION(execSetIsClear); \
	DECLARE_FUNCTION(execIsClear);


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGHHexActor(); \
	friend struct Z_Construct_UClass_AGHHexActor_Statics; \
public: \
	DECLARE_CLASS(AGHHexActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHHexActor)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_INCLASS \
private: \
	static void StaticRegisterNativesAGHHexActor(); \
	friend struct Z_Construct_UClass_AGHHexActor_Statics; \
public: \
	DECLARE_CLASS(AGHHexActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Grid"), NO_API) \
	DECLARE_SERIALIZER(AGHHexActor)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGHHexActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGHHexActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHHexActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHHexActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHHexActor(AGHHexActor&&); \
	NO_API AGHHexActor(const AGHHexActor&); \
public:


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGHHexActor(AGHHexActor&&); \
	NO_API AGHHexActor(const AGHHexActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGHHexActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGHHexActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGHHexActor)


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshGrid() { return STRUCT_OFFSET(AGHHexActor, MeshGrid); } \
	FORCEINLINE static uint32 __PPO__OnChosenMaterial() { return STRUCT_OFFSET(AGHHexActor, OnChosenMaterial); } \
	FORCEINLINE static uint32 __PPO__StandardMaterial() { return STRUCT_OFFSET(AGHHexActor, StandardMaterial); } \
	FORCEINLINE static uint32 __PPO__PlayerOnHexMaterial() { return STRUCT_OFFSET(AGHHexActor, PlayerOnHexMaterial); } \
	FORCEINLINE static uint32 __PPO__MovableMaterial() { return STRUCT_OFFSET(AGHHexActor, MovableMaterial); }


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_26_PROLOG
#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_RPC_WRAPPERS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_INCLASS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_PRIVATE_PROPERTY_OFFSET \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_SPARSE_DATA \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_INCLASS_NO_PURE_DECLS \
	GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GRID_API UClass* StaticClass<class AGHHexActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GloomHaven_Plugins_Grid_Source_Grid_Public_GHHexActor_h


#define FOREACH_ENUM_EMATERIALTOHEX(op) \
	op(Way) \
	op(OverlapMouse) \
	op(Player) \
	op(Movable) \
	op(Clear) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
