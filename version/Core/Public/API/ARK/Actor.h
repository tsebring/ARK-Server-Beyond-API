#pragma once

#include "../Base.h"

struct FChatMessage
{
	FString SenderName;
	FString SenderSteamName;
	FString SenderTribeName;
	unsigned int SenderId;
	FString Message;
	FString Receiver;
	int SenderTeamIndex;
	long double ReceivedTime;
	TEnumAsByte<EChatSendMode::Type> SendMode;
	unsigned int RadioFrequency;
	TEnumAsByte<enum EChatType::Type> ChatType;
	UTexture2D* SenderIcon;
	FString UserId;

	FChatMessage()
		: SenderName(""),
		SenderSteamName(""),
		SenderTribeName(""),
		SenderId(0),
		Message(""),
		Receiver(""),
		SenderTeamIndex(0),
		ReceivedTime(-1),
		SendMode(EChatSendMode::GlobalChat),
		RadioFrequency(0),
		ChatType(EChatType::GlobalChat),
		SenderIcon(nullptr),
		UserId("")
	{
	}

	FChatMessage(FChatMessage* __that) { NativeCall<void, FChatMessage *>(this, "FChatMessage.FChatMessage", __that); }
	FChatMessage* operator=(FChatMessage* __that) { return NativeCall<FChatMessage *, FChatMessage *>(this, "FChatMessage.operator=", __that); }
};

struct FUniqueNetIdRepl
{
	TSharedPtr<FUniqueNetId> UniqueNetId;
};

struct FActorSpawnParameters
{
	FActorSpawnParameters()
		: Name()
		, Template(NULL)
		, Owner(NULL)
		, Instigator(NULL)
		, OverrideLevel(NULL)
		, bNoCollisionFail(0)
		, bRemoteOwned(false)
		, bNoFail(false)
		, bDeferConstruction(false)
		, bAllowDuringConstructionScript(false)
		, bDeferBeginPlay(0)
		, ExtraSpawnData(0)
		, ObjectFlags(EObjectFlags::RF_Transactional)
		, AttachToComponent(nullptr)
	{
	}

	FName Name;
	AActor *Template;
	AActor *Owner;
	APawn *Instigator;
	ULevel *OverrideLevel;
	unsigned __int32 bNoCollisionFail : 1;
	unsigned __int32 bRemoteOwned : 1;
	unsigned __int32 bNoFail : 1;
	unsigned __int32 bDeferConstruction : 1;
	unsigned __int32 bAllowDuringConstructionScript : 1;
	unsigned __int32 bDeferBeginPlay : 1;
	int ExtraSpawnData;
	EObjectFlags ObjectFlags;
	USceneComponent *AttachToComponent;
	FName AttachToBoneName;
};

struct FPlayerDeathReason
{
	int PlayerID;
	FString DeathReason;
	long double DiedAtTime;
};

struct __declspec(align(8)) FPrimalPlayerCharacterConfigStruct
{
	__int8 bIsFemale : 1;
	FLinearColor BodyColors[4];
	FLinearColor OverrideHeadHairColor;
	FLinearColor OverrideFacialHairColor;
	char FacialHairIndex;
	char HeadHairIndex;
	FString PlayerCharacterName;
	float RawBoneModifiers[22];
	int PlayerSpawnRegionIndex;
};

struct FPrimalCharacterStatusValueModifier
{
	EPrimalCharacterStatusValue::Type ValueType;
	EPrimalCharacterStatusValue::Type StopOnValueNearMax;
	float AmountToAdd;
	float BaseAmountToAdd;
	float SpeedToAdd;
	bool bContinueOnUnchangedValue;
	bool bSetValue;
	bool bSetAdditionalValue;
	bool bMakeUntameable;
	int StatusValueModifierDescriptionIndex;
};

struct FDinoBaseLevelWeightEntry
{
	float EntryWeight;
	float BaseLevelMinRange;
	float BaseLevelMaxRange;
};

struct FClassRemappingWeight
{
	TSubclassOf<UObject> FromClass;
	TArray<TSubclassOf<UObject>> ToClasses;
	TArray<float> Weights;
};

struct FClassNameReplacement
{
	FString FromClassName;
	FString ToClassName;
};

struct FNPCDifficultyLevelRange
{
	TArray<float> EnemyLevelsMin;
	TArray<float> EnemyLevelsMax;
	TArray<float> GameDifficulties;
};

struct FNPCSpawnEntry
{
	FString AnEntryName;
	TArray<TSubclassOf<APrimalDinoCharacter>> NPCsToSpawn;
	TArray<FString> NPCsToSpawnStrings;
	TArray<FClassRemappingWeight> NPCRandomSpawnClassWeights;
	TArray<FVector> NPCsSpawnOffsets;
	TArray<float> NPCsToSpawnPercentageChance;
	TArray<float> NPCMinLevelOffset;
	TArray<float> NPCMaxLevelOffset;
	TArray<float> NPCMinLevelMultiplier;
	TArray<float> NPCMaxLevelMultiplier;
	unsigned __int32 bAddLevelOffsetBeforeMultiplier : 1;
	TArray<unsigned char> NPCOverrideLevel;
	FVector ExtentCheck;
	FVector GroupSpawnOffset;
	float EntryWeight;
	float ManualSpawnPointSpreadRadius;
	float WaterOnlySpawnMinimumWaterHeight;
	float MaximumWaterHeight;
	TArray<FNPCDifficultyLevelRange> NPCDifficultyLevelRanges;
	float LevelDifficultyTestOverride;
	float SpawnMinDistanceFromStructuresMultiplier;
	float SpawnMinDistanceFromPlayersMultiplier;
	float SpawnMinDistanceFromTamedDinosMultiplier;
	float RandGroupSpawnOffsetZMin;
	float RandGroupSpawnOffsetZMax;
};

struct FNPCSpawnLimit
{
	TSubclassOf<APrimalDinoCharacter> NPCClass;
	FString NPCClassString;
	float MaxPercentageOfDesiredNumToAllow;
	int CurrentNumberOfNPCTouching;
};

struct __declspec(align(8)) UNPCSpawnEntriesContainer : UObject
{
	TArray<FNPCSpawnEntry> NPCSpawnEntries;
	TArray<FNPCSpawnLimit> NPCSpawnLimits;
	float MaxDesiredNumEnemiesMultiplier;
};

struct FConfigCacheIni
{
};

struct USceneComponent : UActorComponent
{
	FieldValue<FTransform> ComponentToWorldField() { return { this, "USceneComponent.ComponentToWorld" }; }
	FieldValue<TEnumAsByte<enum EComponentMobility::Type>> MobilityField() { return { this, "USceneComponent.Mobility" }; }
	FieldValue<FBoxSphereBounds> BoundsField() { return { this, "USceneComponent.Bounds" }; }
	FieldValue<USceneComponent *> AttachParentField() { return { this, "USceneComponent.AttachParent" }; }
	FieldValue<FName> AttachSocketNameField() { return { this, "USceneComponent.AttachSocketName" }; }
	FieldValue<TArray<USceneComponent *>> AttachChildrenField() { return { this, "USceneComponent.AttachChildren" }; }
	FieldValue<FVector> RelativeLocationField() { return { this, "USceneComponent.RelativeLocation" }; }
	FieldValue<FRotator> RelativeRotationField() { return { this, "USceneComponent.RelativeRotation" }; }
	FieldValue<TEnumAsByte<enum EDetailMode>> DetailModeField() { return { this, "USceneComponent.DetailMode" }; }
	FieldValue<int> AttachmentChangedIncrementerField() { return { this, "USceneComponent.AttachmentChangedIncrementer" }; }
	FieldValue<bool> NetUpdateTransformField() { return { this, "USceneComponent.NetUpdateTransform" }; }
	FieldValue<USceneComponent *> NetOldAttachParentField() { return { this, "USceneComponent.NetOldAttachParent" }; }
	FieldValue<FName> NetOldAttachSocketNameField() { return { this, "USceneComponent.NetOldAttachSocketName" }; }
	FieldValue<FVector> RelativeScale3DField() { return { this, "USceneComponent.RelativeScale3D" }; }
	FieldValue<FVector> ComponentVelocityField() { return { this, "USceneComponent.ComponentVelocity" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bRequiresCustomLocation() { return { this, "USceneComponent.bRequiresCustomLocation" }; }
	BitFieldValue<bool, unsigned __int32> bAbsoluteLocation() { return { this, "USceneComponent.bAbsoluteLocation" }; }
	BitFieldValue<bool, unsigned __int32> bAllowActorUpdateCallback() { return { this, "USceneComponent.bAllowActorUpdateCallback" }; }
	BitFieldValue<bool, unsigned __int32> bAbsoluteTranslation_DEPRECATED() { return { this, "USceneComponent.bAbsoluteTranslation_DEPRECATED" }; }
	BitFieldValue<bool, unsigned __int32> bAbsoluteRotation() { return { this, "USceneComponent.bAbsoluteRotation" }; }
	BitFieldValue<bool, unsigned __int32> bAbsoluteScale() { return { this, "USceneComponent.bAbsoluteScale" }; }
	BitFieldValue<bool, unsigned __int32> bVisible() { return { this, "USceneComponent.bVisible" }; }
	BitFieldValue<bool, unsigned __int32> bHiddenInGame() { return { this, "USceneComponent.bHiddenInGame" }; }
	BitFieldValue<bool, unsigned __int32> bAttachedSoundsForceHighPriority() { return { this, "USceneComponent.bAttachedSoundsForceHighPriority" }; }
	BitFieldValue<bool, unsigned __int32> bShouldUpdatePhysicsVolume() { return { this, "USceneComponent.bShouldUpdatePhysicsVolume" }; }
	BitFieldValue<bool, unsigned __int32> bUpdateChildOverlaps() { return { this, "USceneComponent.bUpdateChildOverlaps" }; }
	BitFieldValue<bool, unsigned __int32> bBoundsChangeTriggersStreamingDataRebuild() { return { this, "USceneComponent.bBoundsChangeTriggersStreamingDataRebuild" }; }
	BitFieldValue<bool, unsigned __int32> bUseAttachParentBound() { return { this, "USceneComponent.bUseAttachParentBound" }; }
	BitFieldValue<bool, unsigned __int32> bWorldToComponentUpdated() { return { this, "USceneComponent.bWorldToComponentUpdated" }; }
	BitFieldValue<bool, unsigned __int32> bClientSyncAlwaysUpdatePhysicsCollision() { return { this, "USceneComponent.bClientSyncAlwaysUpdatePhysicsCollision" }; }

	// Functions

	void OnChildAttached(USceneComponent * ChildComponent) { NativeCall<void, USceneComponent *>(this, "USceneComponent.OnChildAttached", ChildComponent); }
	FVector * GetCustomLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetCustomLocation", result); }
	UField * StaticClass() { return NativeCall<UField *>(this, "USceneComponent.StaticClass"); }
	FVector * GetForwardVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetForwardVector", result); }
	FTransform * CalcNewComponentToWorld(FTransform * result, FTransform * NewRelativeTransform, USceneComponent * Parent) { return NativeCall<FTransform *, FTransform *, FTransform *, USceneComponent *>(this, "USceneComponent.CalcNewComponentToWorld", result, NewRelativeTransform, Parent); }
	void UpdateComponentToWorldWithParent(USceneComponent * Parent, bool bSkipPhysicsMove, FQuat * RelativeRotationQuat) { NativeCall<void, USceneComponent *, bool, FQuat *>(this, "USceneComponent.UpdateComponentToWorldWithParent", Parent, bSkipPhysicsMove, RelativeRotationQuat); }
	void OnRegister() { NativeCall<void>(this, "USceneComponent.OnRegister"); }
	void UpdateComponentToWorld(bool bSkipPhysicsMove) { NativeCall<void, bool>(this, "USceneComponent.UpdateComponentToWorld", bSkipPhysicsMove); }
	void PropagateTransformUpdate(bool bTransformChanged, bool bSkipPhysicsMove) { NativeCall<void, bool, bool>(this, "USceneComponent.PropagateTransformUpdate", bTransformChanged, bSkipPhysicsMove); }
	void DestroyComponent() { NativeCall<void>(this, "USceneComponent.DestroyComponent"); }
	FBoxSphereBounds * CalcBounds(FBoxSphereBounds * result, FTransform * LocalToWorld) { return NativeCall<FBoxSphereBounds *, FBoxSphereBounds *, FTransform *>(this, "USceneComponent.CalcBounds", result, LocalToWorld); }
	void CalcBoundingCylinder(float * CylinderRadius, float * CylinderHalfHeight) { NativeCall<void, float *, float *>(this, "USceneComponent.CalcBoundingCylinder", CylinderRadius, CylinderHalfHeight); }
	void UpdateBounds() { NativeCall<void>(this, "USceneComponent.UpdateBounds"); }
	void SetRelativeLocationAndRotation(FVector NewLocation, FQuat * NewRotation, bool bSweep) { NativeCall<void, FVector, FQuat *, bool>(this, "USceneComponent.SetRelativeLocationAndRotation", NewLocation, NewRotation, bSweep); }
	void AddLocalOffset(FVector DeltaLocation, bool bSweep) { NativeCall<void, FVector, bool>(this, "USceneComponent.AddLocalOffset", DeltaLocation, bSweep); }
	void AddLocalRotation(FRotator DeltaRotation, bool bSweep) { NativeCall<void, FRotator, bool>(this, "USceneComponent.AddLocalRotation", DeltaRotation, bSweep); }
	void AddLocalTransform(FTransform * DeltaTransform, bool bSweep) { NativeCall<void, FTransform *, bool>(this, "USceneComponent.AddLocalTransform", DeltaTransform, bSweep); }
	void AddWorldTransform(FTransform * DeltaTransform, bool bSweep) { NativeCall<void, FTransform *, bool>(this, "USceneComponent.AddWorldTransform", DeltaTransform, bSweep); }
	void SetRelativeScale3D(FVector NewScale3D) { NativeCall<void, FVector>(this, "USceneComponent.SetRelativeScale3D", NewScale3D); }
	void ResetRelativeTransform() { NativeCall<void>(this, "USceneComponent.ResetRelativeTransform"); }
	void SetRelativeTransform(FTransform * NewTransform, bool bSweep) { NativeCall<void, FTransform *, bool>(this, "USceneComponent.SetRelativeTransform", NewTransform, bSweep); }
	FTransform * GetRelativeTransform(FTransform * result) { return NativeCall<FTransform *, FTransform *>(this, "USceneComponent.GetRelativeTransform", result); }
	void SetWorldLocation(FVector NewLocation, bool bSweep) { NativeCall<void, FVector, bool>(this, "USceneComponent.SetWorldLocation", NewLocation, bSweep); }
	void SetWorldRotation(FQuat * NewRotation, bool bSweep) { NativeCall<void, FQuat *, bool>(this, "USceneComponent.SetWorldRotation", NewRotation, bSweep); }
	void SetWorldScale3D(FVector NewScale) { NativeCall<void, FVector>(this, "USceneComponent.SetWorldScale3D", NewScale); }
	void SetWorldTransform(FTransform * NewTransform, bool bSweep) { NativeCall<void, FTransform *, bool>(this, "USceneComponent.SetWorldTransform", NewTransform, bSweep); }
	void SetWorldLocationAndRotation(FVector NewLocation, FQuat * NewRotation, bool bSweep) { NativeCall<void, FVector, FQuat *, bool>(this, "USceneComponent.SetWorldLocationAndRotation", NewLocation, NewRotation, bSweep); }
	void SetWorldLocationAndRotationNoPhysics(FVector * NewLocation, FRotator * NewRotation) { NativeCall<void, FVector *, FRotator *>(this, "USceneComponent.SetWorldLocationAndRotationNoPhysics", NewLocation, NewRotation); }
	FVector * GetRightVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetRightVector", result); }
	FVector * GetUpVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetUpVector", result); }
	void GetParentComponents(TArray<USceneComponent *> * Parents) { NativeCall<void, TArray<USceneComponent *> *>(this, "USceneComponent.GetParentComponents", Parents); }
	void GetChildrenComponents(bool bIncludeAllDescendants, TArray<USceneComponent *> * Children) { NativeCall<void, bool, TArray<USceneComponent *> *>(this, "USceneComponent.GetChildrenComponents", bIncludeAllDescendants, Children); }
	void AppendDescendants(TArray<USceneComponent *> * Children) { NativeCall<void, TArray<USceneComponent *> *>(this, "USceneComponent.AppendDescendants", Children); }
	void AttachTo(USceneComponent * Parent, FName InSocketName, EAttachLocation::Type AttachType, bool bWeldSimulatedBodies) { NativeCall<void, USceneComponent *, FName, EAttachLocation::Type, bool>(this, "USceneComponent.AttachTo", Parent, InSocketName, AttachType, bWeldSimulatedBodies); }
	void DetachFromParent(bool bMaintainWorldPosition) { NativeCall<void, bool>(this, "USceneComponent.DetachFromParent", bMaintainWorldPosition); }
	FVector * GetMeshScaleMultiplier(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetMeshScaleMultiplier", result); }
	AActor * GetAttachmentRootActor() { return NativeCall<AActor *>(this, "USceneComponent.GetAttachmentRootActor"); }
	void UpdateChildTransforms() { NativeCall<void>(this, "USceneComponent.UpdateChildTransforms"); }
	void PostInterpChange(UProperty * PropertyThatChanged) { NativeCall<void, UProperty *>(this, "USceneComponent.PostInterpChange", PropertyThatChanged); }
	FTransform * GetSocketTransform(FTransform * result, FName SocketName, ERelativeTransformSpace TransformSpace) { return NativeCall<FTransform *, FTransform *, FName, ERelativeTransformSpace>(this, "USceneComponent.GetSocketTransform", result, SocketName, TransformSpace); }
	FVector * GetSocketLocation(FVector * result, FName SocketName) { return NativeCall<FVector *, FVector *, FName>(this, "USceneComponent.GetSocketLocation", result, SocketName); }
	FRotator * GetSocketRotation(FRotator * result, FName SocketName) { return NativeCall<FRotator *, FRotator *, FName>(this, "USceneComponent.GetSocketRotation", result, SocketName); }
	FQuat * GetSocketQuaternion(FQuat * result, FName SocketName) { return NativeCall<FQuat *, FQuat *, FName>(this, "USceneComponent.GetSocketQuaternion", result, SocketName); }
	FVector * GetComponentVelocity(FVector * result) { return NativeCall<FVector *, FVector *>(this, "USceneComponent.GetComponentVelocity", result); }
	void GetSocketWorldLocationAndRotation(FName InSocketName, FVector * OutLocation, FRotator * OutRotation) { NativeCall<void, FName, FVector *, FRotator *>(this, "USceneComponent.GetSocketWorldLocationAndRotation", InSocketName, OutLocation, OutRotation); }
	FCollisionResponseContainer * GetCollisionResponseToChannels() { return NativeCall<FCollisionResponseContainer *>(this, "USceneComponent.GetCollisionResponseToChannels"); }
	void SetMobility(EComponentMobility::Type NewMobility) { NativeCall<void, EComponentMobility::Type>(this, "USceneComponent.SetMobility", NewMobility); }
	bool IsAnySimulatingPhysics() { return NativeCall<bool>(this, "USceneComponent.IsAnySimulatingPhysics"); }
	void UpdatePhysicsVolume(bool bTriggerNotifiers) { NativeCall<void, bool>(this, "USceneComponent.UpdatePhysicsVolume", bTriggerNotifiers); }
	void BeginDestroy() { NativeCall<void>(this, "USceneComponent.BeginDestroy"); }
	bool InternalSetWorldLocationAndRotation(FVector NewLocation, FQuat * RotationQuat, bool bNoPhysics) { return NativeCall<bool, FVector, FQuat *, bool>(this, "USceneComponent.InternalSetWorldLocationAndRotation", NewLocation, RotationQuat, bNoPhysics); }
	bool MoveComponentImpl(FVector * Delta, FQuat * NewRotation, bool bSweep, FHitResult * OutHit, EMoveComponentFlags MoveFlags, bool bUpdateOverlaps) { return NativeCall<bool, FVector *, FQuat *, bool, FHitResult *, EMoveComponentFlags, bool>(this, "USceneComponent.MoveComponentImpl", Delta, NewRotation, bSweep, OutHit, MoveFlags, bUpdateOverlaps); }
	bool IsVisibleInEditor() { return NativeCall<bool>(this, "USceneComponent.IsVisibleInEditor"); }
	bool ShouldRender() { return NativeCall<bool>(this, "USceneComponent.ShouldRender"); }
	bool CanEverRender() { return NativeCall<bool>(this, "USceneComponent.CanEverRender"); }
	bool IsVisible() { return NativeCall<bool>(this, "USceneComponent.IsVisible"); }
	void SetVisibility(bool bNewVisibility, bool bPropagateToChildren) { NativeCall<void, bool, bool>(this, "USceneComponent.SetVisibility", bNewVisibility, bPropagateToChildren); }
	void SetHiddenInGame(bool NewHiddenGame, bool bPropagateToChildren) { NativeCall<void, bool, bool>(this, "USceneComponent.SetHiddenInGame", NewHiddenGame, bPropagateToChildren); }
	void ApplyWorldOffset(FVector * InOffset, bool bWorldShift) { NativeCall<void, FVector *, bool>(this, "USceneComponent.ApplyWorldOffset", InOffset, bWorldShift); }
	FBoxSphereBounds * GetPlacementExtent(FBoxSphereBounds * result) { return NativeCall<FBoxSphereBounds *, FBoxSphereBounds *>(this, "USceneComponent.GetPlacementExtent", result); }
	void PreNetReceive() { NativeCall<void>(this, "USceneComponent.PreNetReceive"); }
	void PostNetReceive() { NativeCall<void>(this, "USceneComponent.PostNetReceive"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "USceneComponent.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void StopSound(USoundBase * SoundToStop, float FadeOutTime) { NativeCall<void, USoundBase *, float>(this, "USceneComponent.StopSound", SoundToStop, FadeOutTime); }
	static void StaticRegisterNativesUSceneComponent() { NativeCall<void>(nullptr, "USceneComponent.StaticRegisterNativesUSceneComponent"); }
};

struct UPrimitiveComponent : USceneComponent
{
	FieldValue<float> MinDrawDistanceField() { return { this, "UPrimitiveComponent.MinDrawDistance" }; }
	FieldValue<float> MassiveLODSizeOnScreenField() { return { this, "UPrimitiveComponent.MassiveLODSizeOnScreen" }; }
	FieldValue<float> LDMaxDrawDistanceField() { return { this, "UPrimitiveComponent.LDMaxDrawDistance" }; }
	FieldValue<float> CachedMaxDrawDistanceField() { return { this, "UPrimitiveComponent.CachedMaxDrawDistance" }; }
	FieldValue<TEnumAsByte<enum ESceneDepthPriorityGroup>> DepthPriorityGroupField() { return { this, "UPrimitiveComponent.DepthPriorityGroup" }; }
	FieldValue<TEnumAsByte<enum ESceneDepthPriorityGroup>> ViewOwnerDepthPriorityGroupField() { return { this, "UPrimitiveComponent.ViewOwnerDepthPriorityGroup" }; }
	FieldValue<int> CustomDepthStencilValueField() { return { this, "UPrimitiveComponent.CustomDepthStencilValue" }; }
	FieldValue<int> ObjectLayerField() { return { this, "UPrimitiveComponent.ObjectLayer" }; }
	FieldValue<TEnumAsByte<enum EIndirectLightingCacheQuality>> IndirectLightingCacheQualityField() { return { this, "UPrimitiveComponent.IndirectLightingCacheQuality" }; }
	FieldValue<bool> bHasCachedStaticLightingField() { return { this, "UPrimitiveComponent.bHasCachedStaticLighting" }; }
	FieldValue<bool> bStaticLightingBuildEnqueuedField() { return { this, "UPrimitiveComponent.bStaticLightingBuildEnqueued" }; }
	FieldValue<int> TranslucencySortPriorityField() { return { this, "UPrimitiveComponent.TranslucencySortPriority" }; }
	FieldValue<int> VisibilityIdField() { return { this, "UPrimitiveComponent.VisibilityId" }; }
	FieldValue<float> LastPhysxSleepTimeField() { return { this, "UPrimitiveComponent.LastPhysxSleepTime" }; }
	FieldValue<unsigned int> GameThread_OverlapIncrementorField() { return { this, "UPrimitiveComponent.GameThread_OverlapIncrementor" }; }
	FieldValue<unsigned int> GameThread_OverlapIndexMaskField() { return { this, "UPrimitiveComponent.GameThread_OverlapIndexMask" }; }
	FieldValue<int> InternalOctreeMaskField() { return { this, "UPrimitiveComponent.InternalOctreeMask" }; }
	FieldValue<float> LpvBiasMultiplierField() { return { this, "UPrimitiveComponent.LpvBiasMultiplier" }; }
	FieldValue<float> OverrideStepHeightField() { return { this, "UPrimitiveComponent.OverrideStepHeight" }; }
	FieldValue<FBodyInstance> BodyInstanceField() { return { this, "UPrimitiveComponent.BodyInstance" }; }
	FieldValue<float> LastCheckedAllCollideableDescendantsTimeField() { return { this, "UPrimitiveComponent.LastCheckedAllCollideableDescendantsTime" }; }
	FieldValue<float> BoundsScaleField() { return { this, "UPrimitiveComponent.BoundsScale" }; }
	FieldValue<long double> LastSubmitTimeField() { return { this, "UPrimitiveComponent.LastSubmitTime" }; }
	FieldValue<long double> LastRenderTimeField() { return { this, "UPrimitiveComponent.LastRenderTime" }; }
	FieldValue<long double> LastRenderTimeIgnoreShadowField() { return { this, "UPrimitiveComponent.LastRenderTimeIgnoreShadow" }; }
	FieldValue<TEnumAsByte<enum ECanBeCharacterBase>> CanCharacterStepUpOnField() { return { this, "UPrimitiveComponent.CanCharacterStepUpOn" }; }
	FieldValue<TArray<TWeakObjectPtr<AActor>>> MoveIgnoreActorsField() { return { this, "UPrimitiveComponent.MoveIgnoreActors" }; }
	FieldValue<unsigned int> ProxyMeshIDField() { return { this, "UPrimitiveComponent.ProxyMeshID" }; }
	FieldValue<bool> bIsProxyMeshParentField() { return { this, "UPrimitiveComponent.bIsProxyMeshParent" }; }
	FieldValue<bool> bHasActiveProxyMeshChildrenField() { return { this, "UPrimitiveComponent.bHasActiveProxyMeshChildren" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUseAbsoluteMaxDrawDisatance() { return { this, "UPrimitiveComponent.bUseAbsoluteMaxDrawDisatance" }; }
	BitFieldValue<bool, unsigned __int32> bIncludeBoundsRadiusInDrawDistances() { return { this, "UPrimitiveComponent.bIncludeBoundsRadiusInDrawDistances" }; }
	BitFieldValue<bool, unsigned __int32> bExcludeFromLevelBounds() { return { this, "UPrimitiveComponent.bExcludeFromLevelBounds" }; }
	BitFieldValue<bool, unsigned __int32> bPreventCharacterBasing() { return { this, "UPrimitiveComponent.bPreventCharacterBasing" }; }
	BitFieldValue<bool, unsigned __int32> bAllowBasedCharacters() { return { this, "UPrimitiveComponent.bAllowBasedCharacters" }; }
	BitFieldValue<bool, unsigned __int32> bNoEncroachCheck_DEPRECATED() { return { this, "UPrimitiveComponent.bNoEncroachCheck_DEPRECATED" }; }
	BitFieldValue<bool, unsigned __int32> bDisableAllRigidBody_DEPRECATED() { return { this, "UPrimitiveComponent.bDisableAllRigidBody_DEPRECATED" }; }
	BitFieldValue<bool, unsigned __int32> bForceDynamicPhysics() { return { this, "UPrimitiveComponent.bForceDynamicPhysics" }; }
	BitFieldValue<bool, unsigned __int32> bPreventDamage() { return { this, "UPrimitiveComponent.bPreventDamage" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysCreatePhysicsState() { return { this, "UPrimitiveComponent.bAlwaysCreatePhysicsState" }; }
	BitFieldValue<bool, unsigned __int32> bGenerateOverlapEvents() { return { this, "UPrimitiveComponent.bGenerateOverlapEvents" }; }
	BitFieldValue<bool, unsigned __int32> bForceOverlapEvents() { return { this, "UPrimitiveComponent.bForceOverlapEvents" }; }
	BitFieldValue<bool, unsigned __int32> bMultiBodyOverlap() { return { this, "UPrimitiveComponent.bMultiBodyOverlap" }; }
	BitFieldValue<bool, unsigned __int32> bCheckAsyncSceneOnMove() { return { this, "UPrimitiveComponent.bCheckAsyncSceneOnMove" }; }
	BitFieldValue<bool, unsigned __int32> bTraceComplexOnMove() { return { this, "UPrimitiveComponent.bTraceComplexOnMove" }; }
	BitFieldValue<bool, unsigned __int32> bReturnMaterialOnMove() { return { this, "UPrimitiveComponent.bReturnMaterialOnMove" }; }
	BitFieldValue<bool, unsigned __int32> bUseViewOwnerDepthPriorityGroup() { return { this, "UPrimitiveComponent.bUseViewOwnerDepthPriorityGroup" }; }
	BitFieldValue<bool, unsigned __int32> bAllowCullDistanceVolume() { return { this, "UPrimitiveComponent.bAllowCullDistanceVolume" }; }
	BitFieldValue<bool, unsigned __int32> bHasMotionBlurVelocityMeshes() { return { this, "UPrimitiveComponent.bHasMotionBlurVelocityMeshes" }; }
	BitFieldValue<bool, unsigned __int32> bRenderCustomDepth() { return { this, "UPrimitiveComponent.bRenderCustomDepth" }; }
	BitFieldValue<bool, unsigned __int32> bRenderInMainPass() { return { this, "UPrimitiveComponent.bRenderInMainPass" }; }
	BitFieldValue<bool, unsigned __int32> bIsInForeground() { return { this, "UPrimitiveComponent.bIsInForeground" }; }
	BitFieldValue<bool, unsigned __int32> HiddenGame_DEPRECATED() { return { this, "UPrimitiveComponent.HiddenGame_DEPRECATED" }; }
	BitFieldValue<bool, unsigned __int32> DrawInGame_DEPRECATED() { return { this, "UPrimitiveComponent.DrawInGame_DEPRECATED" }; }
	BitFieldValue<bool, unsigned __int32> bReceivesDecals() { return { this, "UPrimitiveComponent.bReceivesDecals" }; }
	BitFieldValue<bool, unsigned __int32> bOwnerNoSee() { return { this, "UPrimitiveComponent.bOwnerNoSee" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyOwnerSee() { return { this, "UPrimitiveComponent.bOnlyOwnerSee" }; }
	BitFieldValue<bool, unsigned __int32> bTreatAsBackgroundForOcclusion() { return { this, "UPrimitiveComponent.bTreatAsBackgroundForOcclusion" }; }
	BitFieldValue<bool, unsigned __int32> bUseAsOccluder() { return { this, "UPrimitiveComponent.bUseAsOccluder" }; }
	BitFieldValue<bool, unsigned __int32> bSelectable() { return { this, "UPrimitiveComponent.bSelectable" }; }
	BitFieldValue<bool, unsigned __int32> bForceMipStreaming() { return { this, "UPrimitiveComponent.bForceMipStreaming" }; }
	BitFieldValue<bool, unsigned __int32> bHasPerInstanceHitProxies() { return { this, "UPrimitiveComponent.bHasPerInstanceHitProxies" }; }
	BitFieldValue<bool, unsigned __int32> CastShadow() { return { this, "UPrimitiveComponent.CastShadow" }; }
	BitFieldValue<bool, unsigned __int32> bAffectDynamicIndirectLighting() { return { this, "UPrimitiveComponent.bAffectDynamicIndirectLighting" }; }
	BitFieldValue<bool, unsigned __int32> bAffectDistanceFieldLighting() { return { this, "UPrimitiveComponent.bAffectDistanceFieldLighting" }; }
	BitFieldValue<bool, unsigned __int32> bCastDynamicShadow() { return { this, "UPrimitiveComponent.bCastDynamicShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastStaticShadow() { return { this, "UPrimitiveComponent.bCastStaticShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastVolumetricTranslucentShadow() { return { this, "UPrimitiveComponent.bCastVolumetricTranslucentShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastFarShadow() { return { this, "UPrimitiveComponent.bCastFarShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastInsetShadow() { return { this, "UPrimitiveComponent.bCastInsetShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastHiddenShadow() { return { this, "UPrimitiveComponent.bCastHiddenShadow" }; }
	BitFieldValue<bool, unsigned __int32> bCastShadowAsTwoSided() { return { this, "UPrimitiveComponent.bCastShadowAsTwoSided" }; }
	BitFieldValue<bool, unsigned __int32> bLightAsIfStatic() { return { this, "UPrimitiveComponent.bLightAsIfStatic" }; }
	BitFieldValue<bool, unsigned __int32> bLightAttachmentsAsGroup() { return { this, "UPrimitiveComponent.bLightAttachmentsAsGroup" }; }
	BitFieldValue<bool, unsigned __int32> bUseInternalOctree() { return { this, "UPrimitiveComponent.bUseInternalOctree" }; }
	BitFieldValue<bool, unsigned __int32> bUseInternalOctreeOnClient() { return { this, "UPrimitiveComponent.bUseInternalOctreeOnClient" }; }
	BitFieldValue<bool, unsigned __int32> bRegisteredInternalOctree() { return { this, "UPrimitiveComponent.bRegisteredInternalOctree" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreRadialImpulse() { return { this, "UPrimitiveComponent.bIgnoreRadialImpulse" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreRadialForce() { return { this, "UPrimitiveComponent.bIgnoreRadialForce" }; }
	BitFieldValue<bool, unsigned __int32> AlwaysLoadOnClient() { return { this, "UPrimitiveComponent.AlwaysLoadOnClient" }; }
	BitFieldValue<bool, unsigned __int32> AlwaysLoadOnServer() { return { this, "UPrimitiveComponent.AlwaysLoadOnServer" }; }
	BitFieldValue<bool, unsigned __int32> bUseEditorCompositing() { return { this, "UPrimitiveComponent.bUseEditorCompositing" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoredByCharacterEncroachment() { return { this, "UPrimitiveComponent.bIgnoredByCharacterEncroachment" }; }
	BitFieldValue<bool, unsigned __int32> bMovableUseDynamicDrawDistance() { return { this, "UPrimitiveComponent.bMovableUseDynamicDrawDistance" }; }
	BitFieldValue<bool, unsigned __int32> bCanEverAffectNavigation() { return { this, "UPrimitiveComponent.bCanEverAffectNavigation" }; }
	BitFieldValue<bool, unsigned __int32> bNavigationRelevant() { return { this, "UPrimitiveComponent.bNavigationRelevant" }; }
	BitFieldValue<bool, unsigned __int32> bCachedAllCollideableDescendantsRelative() { return { this, "UPrimitiveComponent.bCachedAllCollideableDescendantsRelative" }; }

	// Functions

	UField * GetPrivateStaticClass() { return NativeCall<UField *>(this, "UPrimitiveComponent.GetPrivateStaticClass"); }
	void GetLightAndShadowMapMemoryUsage(int * OutNum, int * OutMax) { NativeCall<void, int *, int *>(this, "UPrimitiveComponent.GetLightAndShadowMapMemoryUsage", OutNum, OutMax); }
	bool CanBeBaseForCharacter(APawn * Pawn) { return NativeCall<bool, APawn *>(this, "UPrimitiveComponent.CanBeBaseForCharacter", Pawn); }
	bool AreSymmetricRotations(FQuat * A, FQuat * B, FVector * Scale3D) { return NativeCall<bool, FQuat *, FQuat *, FVector *>(this, "UPrimitiveComponent.AreSymmetricRotations", A, B, Scale3D); }
	char GetStaticDepthPriorityGroup() { return NativeCall<char>(this, "UPrimitiveComponent.GetStaticDepthPriorityGroup"); }
	bool HasValidSettingsForStaticLighting() { return NativeCall<bool>(this, "UPrimitiveComponent.HasValidSettingsForStaticLighting"); }
	void DestroyRenderState_Concurrent() { NativeCall<void>(this, "UPrimitiveComponent.DestroyRenderState_Concurrent"); }
	void FinishDestroy() { NativeCall<void>(this, "UPrimitiveComponent.FinishDestroy"); }
	void InvalidateLightingCacheDetailed(bool bInvalidateBuildEnqueuedLighting, bool bTranslationOnly) { NativeCall<void, bool, bool>(this, "UPrimitiveComponent.InvalidateLightingCacheDetailed", bInvalidateBuildEnqueuedLighting, bTranslationOnly); }
	bool IsEditorOnly() { return NativeCall<bool>(this, "UPrimitiveComponent.IsEditorOnly"); }
	void RegisterComponentTickFunctions(bool bRegister, bool bSaveAndRestoreComponentTickState) { NativeCall<void, bool, bool>(this, "UPrimitiveComponent.RegisterComponentTickFunctions", bRegister, bSaveAndRestoreComponentTickState); }
	void CreateRenderState_Concurrent() { NativeCall<void>(this, "UPrimitiveComponent.CreateRenderState_Concurrent"); }
	void SendRenderTransform_Concurrent() { NativeCall<void>(this, "UPrimitiveComponent.SendRenderTransform_Concurrent"); }
	void OnRegister() { NativeCall<void>(this, "UPrimitiveComponent.OnRegister"); }
	void OnUnregister() { NativeCall<void>(this, "UPrimitiveComponent.OnUnregister"); }
	void OnAttachmentChanged() { NativeCall<void>(this, "UPrimitiveComponent.OnAttachmentChanged"); }
	void CreatePhysicsState() { NativeCall<void>(this, "UPrimitiveComponent.CreatePhysicsState"); }
	void OnUpdateTransform(bool bSkipPhysicsMove) { NativeCall<void, bool>(this, "UPrimitiveComponent.OnUpdateTransform", bSkipPhysicsMove); }
	void PostLoad() { NativeCall<void>(this, "UPrimitiveComponent.PostLoad"); }
	void PostDuplicate(bool bDuplicateForPIE) { NativeCall<void, bool>(this, "UPrimitiveComponent.PostDuplicate", bDuplicateForPIE); }
	bool IsReadyForFinishDestroy() { return NativeCall<bool>(this, "UPrimitiveComponent.IsReadyForFinishDestroy"); }
	bool NeedsLoadForClient() { return NativeCall<bool>(this, "UPrimitiveComponent.NeedsLoadForClient"); }
	bool NeedsLoadForServer() { return NativeCall<bool>(this, "UPrimitiveComponent.NeedsLoadForServer"); }
	void SetOwnerNoSee(bool bNewOwnerNoSee) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetOwnerNoSee", bNewOwnerNoSee); }
	void SetOnlyOwnerSee(bool bNewOnlyOwnerSee) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetOnlyOwnerSee", bNewOnlyOwnerSee); }
	bool ShouldComponentAddToScene() { return NativeCall<bool>(this, "UPrimitiveComponent.ShouldComponentAddToScene"); }
	bool ShouldCreatePhysicsState() { return NativeCall<bool>(this, "UPrimitiveComponent.ShouldCreatePhysicsState"); }
	bool HasValidPhysicsState() { return NativeCall<bool>(this, "UPrimitiveComponent.HasValidPhysicsState"); }
	bool ShouldRenderSelected() { return NativeCall<bool>(this, "UPrimitiveComponent.ShouldRenderSelected"); }
	void SetCastShadow(bool NewCastShadow) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetCastShadow", NewCastShadow); }
	void SetCullDistance(float NewCullDistance) { NativeCall<void, float>(this, "UPrimitiveComponent.SetCullDistance", NewCullDistance); }
	void SetAbsoluteMaxDrawScale(bool bInValue) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetAbsoluteMaxDrawScale", bInValue); }
	bool IsWorldGeometry() { return NativeCall<bool>(this, "UPrimitiveComponent.IsWorldGeometry"); }
	ECollisionChannel GetCollisionObjectType() { return NativeCall<ECollisionChannel>(this, "UPrimitiveComponent.GetCollisionObjectType"); }
	void InitSweepCollisionParams(FCollisionQueryParams * OutParams, FCollisionResponseParams * OutResponseParam) { NativeCall<void, FCollisionQueryParams *, FCollisionResponseParams *>(this, "UPrimitiveComponent.InitSweepCollisionParams", OutParams, OutResponseParam); }
	bool MoveComponentImpl(FVector * Delta, FQuat * NewRotationQuat, bool bSweep, FHitResult * OutHit, EMoveComponentFlags MoveFlags, bool bUpdateOverlaps) { return NativeCall<bool, FVector *, FQuat *, bool, FHitResult *, EMoveComponentFlags, bool>(this, "UPrimitiveComponent.MoveComponentImpl", Delta, NewRotationQuat, bSweep, OutHit, MoveFlags, bUpdateOverlaps); }
	void DispatchBlockingHit(AActor * Owner, FHitResult * BlockingHit) { NativeCall<void, AActor *, FHitResult *>(this, "UPrimitiveComponent.DispatchBlockingHit", Owner, BlockingHit); }
	bool IsNavigationRelevant() { return NativeCall<bool>(this, "UPrimitiveComponent.IsNavigationRelevant"); }
	FBox * GetNavigationBounds(FBox * result) { return NativeCall<FBox *, FBox *>(this, "UPrimitiveComponent.GetNavigationBounds", result); }
	void SetCanEverAffectNavigation(bool bRelevant) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetCanEverAffectNavigation", bRelevant); }
	bool LineTraceComponent(FHitResult * OutHit, FVector Start, FVector End, FCollisionQueryParams * Params) { return NativeCall<bool, FHitResult *, FVector, FVector, FCollisionQueryParams *>(this, "UPrimitiveComponent.LineTraceComponent", OutHit, Start, End, Params); }
	bool ComponentOverlapComponentImpl(UPrimitiveComponent * PrimComp, FVector Pos, FQuat * Quat, FCollisionQueryParams * Params) { return NativeCall<bool, UPrimitiveComponent *, FVector, FQuat *, FCollisionQueryParams *>(this, "UPrimitiveComponent.ComponentOverlapComponentImpl", PrimComp, Pos, Quat, Params); }
	bool IsOverlappingActor(AActor * Other) { return NativeCall<bool, AActor *>(this, "UPrimitiveComponent.IsOverlappingActor", Other); }
	void GetOverlappingActors(TArray<AActor *> * OutOverlappingActors, UClass * ClassFilter) { NativeCall<void, TArray<AActor *> *, UClass *>(this, "UPrimitiveComponent.GetOverlappingActors", OutOverlappingActors, ClassFilter); }
	void GetOverlappingComponents(TArray<UPrimitiveComponent *> * OutOverlappingComponents) { NativeCall<void, TArray<UPrimitiveComponent *> *>(this, "UPrimitiveComponent.GetOverlappingComponents", OutOverlappingComponents); }
	bool AreAllCollideableDescendantsRelative(bool bAllowCachedValue) { return NativeCall<bool, bool>(this, "UPrimitiveComponent.AreAllCollideableDescendantsRelative", bAllowCachedValue); }
	void IgnoreActorWhenMoving(AActor * Actor, bool bShouldIgnore) { NativeCall<void, AActor *, bool>(this, "UPrimitiveComponent.IgnoreActorWhenMoving", Actor, bShouldIgnore); }
	void UpdatePhysicsVolume(bool bTriggerNotifiers) { NativeCall<void, bool>(this, "UPrimitiveComponent.UpdatePhysicsVolume", bTriggerNotifiers); }
	static void DispatchMouseOverEvents(UPrimitiveComponent * CurrentComponent, UPrimitiveComponent * NewComponent) { NativeCall<void, UPrimitiveComponent *, UPrimitiveComponent *>(nullptr, "UPrimitiveComponent.DispatchMouseOverEvents", CurrentComponent, NewComponent); }
	static void DispatchTouchOverEvents(ETouchIndex::Type FingerIndex, UPrimitiveComponent * CurrentComponent, UPrimitiveComponent * NewComponent) { NativeCall<void, ETouchIndex::Type, UPrimitiveComponent *, UPrimitiveComponent *>(nullptr, "UPrimitiveComponent.DispatchTouchOverEvents", FingerIndex, CurrentComponent, NewComponent); }
	void DispatchOnClicked() { NativeCall<void>(this, "UPrimitiveComponent.DispatchOnClicked"); }
	void DispatchOnReleased() { NativeCall<void>(this, "UPrimitiveComponent.DispatchOnReleased"); }
	void DispatchOnInputTouchBegin(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "UPrimitiveComponent.DispatchOnInputTouchBegin", FingerIndex); }
	void DispatchOnInputTouchEnd(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "UPrimitiveComponent.DispatchOnInputTouchEnd", FingerIndex); }
	void SetRenderCustomDepth(bool bValue) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetRenderCustomDepth", bValue); }
	void SetCustomDepthStencilValue(int Value) { NativeCall<void, int>(this, "UPrimitiveComponent.SetCustomDepthStencilValue", Value); }
	bool CanCharacterStepUp(APawn * Pawn) { return NativeCall<bool, APawn *>(this, "UPrimitiveComponent.CanCharacterStepUp", Pawn); }
	bool CanEditSimulatePhysics() { return NativeCall<bool>(this, "UPrimitiveComponent.CanEditSimulatePhysics"); }
	void SetSimulatePhysics(bool bSimulate) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetSimulatePhysics", bSimulate); }
	void AddImpulse(FVector Impulse, FName BoneName, bool bVelChange) { NativeCall<void, FVector, FName, bool>(this, "UPrimitiveComponent.AddImpulse", Impulse, BoneName, bVelChange); }
	void AddImpulseAtLocation(FVector Impulse, FVector Location, FName BoneName) { NativeCall<void, FVector, FVector, FName>(this, "UPrimitiveComponent.AddImpulseAtLocation", Impulse, Location, BoneName); }
	void AddRadialImpulse(FVector Origin, float Radius, float Strength, ERadialImpulseFalloff Falloff, bool bVelChange) { NativeCall<void, FVector, float, float, ERadialImpulseFalloff, bool>(this, "UPrimitiveComponent.AddRadialImpulse", Origin, Radius, Strength, Falloff, bVelChange); }
	void AddForce(FVector Force, FName BoneName) { NativeCall<void, FVector, FName>(this, "UPrimitiveComponent.AddForce", Force, BoneName); }
	void AddForceAtLocation(FVector Force, FVector Location, FName BoneName) { NativeCall<void, FVector, FVector, FName>(this, "UPrimitiveComponent.AddForceAtLocation", Force, Location, BoneName); }
	void AddRadialForce(FVector Origin, float Radius, float Strength, ERadialImpulseFalloff Falloff) { NativeCall<void, FVector, float, float, ERadialImpulseFalloff>(this, "UPrimitiveComponent.AddRadialForce", Origin, Radius, Strength, Falloff); }
	void SetAllPhysicsLinearVelocity(FVector NewVel, bool bAddToCurrent) { NativeCall<void, FVector, bool>(this, "UPrimitiveComponent.SetAllPhysicsLinearVelocity", NewVel, bAddToCurrent); }
	void SetAllPhysicsAngularVelocity(FVector * NewAngVel, bool bAddToCurrent) { NativeCall<void, FVector *, bool>(this, "UPrimitiveComponent.SetAllPhysicsAngularVelocity", NewAngVel, bAddToCurrent); }
	void SetAllPhysicsPosition(FVector NewPos) { NativeCall<void, FVector>(this, "UPrimitiveComponent.SetAllPhysicsPosition", NewPos); }
	void SetAllPhysicsRotation(FRotator NewRot) { NativeCall<void, FRotator>(this, "UPrimitiveComponent.SetAllPhysicsRotation", NewRot); }
	void WakeAllRigidBodies() { NativeCall<void>(this, "UPrimitiveComponent.WakeAllRigidBodies"); }
	void SetEnableGravity(bool bGravityEnabled) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetEnableGravity", bGravityEnabled); }
	bool IsGravityEnabled() { return NativeCall<bool>(this, "UPrimitiveComponent.IsGravityEnabled"); }
	void SetLinearDamping(float InDamping) { NativeCall<void, float>(this, "UPrimitiveComponent.SetLinearDamping", InDamping); }
	float GetLinearDamping() { return NativeCall<float>(this, "UPrimitiveComponent.GetLinearDamping"); }
	void SetAngularDamping(float InDamping) { NativeCall<void, float>(this, "UPrimitiveComponent.SetAngularDamping", InDamping); }
	float GetAngularDamping() { return NativeCall<float>(this, "UPrimitiveComponent.GetAngularDamping"); }
	float GetMass() { return NativeCall<float>(this, "UPrimitiveComponent.GetMass"); }
	float CalculateMass(FName __formal) { return NativeCall<float, FName>(this, "UPrimitiveComponent.CalculateMass", __formal); }
	void PutAllRigidBodiesToSleep() { NativeCall<void>(this, "UPrimitiveComponent.PutAllRigidBodiesToSleep"); }
	bool IsAnyRigidBodyAwake() { return NativeCall<bool>(this, "UPrimitiveComponent.IsAnyRigidBodyAwake"); }
	void SetNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision) { NativeCall<void, bool>(this, "UPrimitiveComponent.SetNotifyRigidBodyCollision", bNewNotifyRigidBodyCollision); }
	void SetPhysMaterialOverride(UPhysicalMaterial * NewPhysMaterial) { NativeCall<void, UPhysicalMaterial *>(this, "UPrimitiveComponent.SetPhysMaterialOverride", NewPhysMaterial); }
	void SyncComponentToRBPhysics() { NativeCall<void>(this, "UPrimitiveComponent.SyncComponentToRBPhysics"); }
	void GetWeldedBodies(TArray<FBodyInstance *> * OutWeldedBodies, TArray<FName> * OutLabels) { NativeCall<void, TArray<FBodyInstance *> *, TArray<FName> *>(this, "UPrimitiveComponent.GetWeldedBodies", OutWeldedBodies, OutLabels); }
	bool WeldToImplementation(USceneComponent * InParent, FName ParentSocketName, bool bWeldSimulatedChild) { return NativeCall<bool, USceneComponent *, FName, bool>(this, "UPrimitiveComponent.WeldToImplementation", InParent, ParentSocketName, bWeldSimulatedChild); }
	void WeldTo(USceneComponent * InParent, FName InSocketName) { NativeCall<void, USceneComponent *, FName>(this, "UPrimitiveComponent.WeldTo", InParent, InSocketName); }
	void UnWeldFromParent() { NativeCall<void>(this, "UPrimitiveComponent.UnWeldFromParent"); }
	FBodyInstance * GetBodyInstance(FName BoneName, bool bGetWelded) { return NativeCall<FBodyInstance *, FName, bool>(this, "UPrimitiveComponent.GetBodyInstance", BoneName, bGetWelded); }
	bool IsSimulatingPhysics(FName BoneName) { return NativeCall<bool, FName>(this, "UPrimitiveComponent.IsSimulatingPhysics", BoneName); }
	FVector * GetComponentVelocity(FVector * result) { return NativeCall<FVector *, FVector *>(this, "UPrimitiveComponent.GetComponentVelocity", result); }
	void SetCollisionObjectType(ECollisionChannel Channel) { NativeCall<void, ECollisionChannel>(this, "UPrimitiveComponent.SetCollisionObjectType", Channel); }
	void SetCollisionResponseToAllChannels(ECollisionResponse NewResponse) { NativeCall<void, ECollisionResponse>(this, "UPrimitiveComponent.SetCollisionResponseToAllChannels", NewResponse); }
	void SetCollisionEnabled(ECollisionEnabled::Type NewType) { NativeCall<void, ECollisionEnabled::Type>(this, "UPrimitiveComponent.SetCollisionEnabled", NewType); }
	void SetCollisionProfileName(FName InCollisionProfileName) { NativeCall<void, FName>(this, "UPrimitiveComponent.SetCollisionProfileName", InCollisionProfileName); }
	void OnActorEnableCollisionChanged() { NativeCall<void>(this, "UPrimitiveComponent.OnActorEnableCollisionChanged"); }
	void OnComponentCollisionSettingsChanged() { NativeCall<void>(this, "UPrimitiveComponent.OnComponentCollisionSettingsChanged"); }
	bool K2_LineTraceComponent(FVector TraceStart, FVector TraceEnd, bool bTraceComplex, bool bShowTrace, FVector * HitLocation, FVector * HitNormal, FName * BoneName) { return NativeCall<bool, FVector, FVector, bool, bool, FVector *, FVector *, FName *>(this, "UPrimitiveComponent.K2_LineTraceComponent", TraceStart, TraceEnd, bTraceComplex, bShowTrace, HitLocation, HitNormal, BoneName); }
	ECollisionEnabled::Type GetCollisionEnabled() { return NativeCall<ECollisionEnabled::Type>(this, "UPrimitiveComponent.GetCollisionEnabled"); }
	ECollisionResponse GetCollisionResponseToChannel(ECollisionChannel Channel) { return NativeCall<ECollisionResponse, ECollisionChannel>(this, "UPrimitiveComponent.GetCollisionResponseToChannel", Channel); }
	void UpdatePhysicsToRBChannels() { NativeCall<void>(this, "UPrimitiveComponent.UpdatePhysicsToRBChannels"); }
	void SetInternalOctreeMask(int InOctreeMask, bool bReregisterWithTree) { NativeCall<void, int, bool>(this, "UPrimitiveComponent.SetInternalOctreeMask", InOctreeMask, bReregisterWithTree); }
	static void StaticRegisterNativesUPrimitiveComponent() { NativeCall<void>(nullptr, "UPrimitiveComponent.StaticRegisterNativesUPrimitiveComponent"); }
};

struct UShapeComponent : UPrimitiveComponent
{
	FieldValue<UMaterialInterface *> ShapeMaterialField() { return { this, "UShapeComponent.ShapeMaterial" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bDrawOnlyIfSelected() { return { this, "UShapeComponent.bDrawOnlyIfSelected" }; }
	BitFieldValue<bool, unsigned __int32> bShouldCollideWhenPlacing() { return { this, "UShapeComponent.bShouldCollideWhenPlacing" }; }

	// Functions

	bool ShouldCollideWhenPlacing() { return NativeCall<bool>(this, "UShapeComponent.ShouldCollideWhenPlacing"); }
};

struct USphereComponent : UShapeComponent
{

	// Functions

	FBoxSphereBounds * CalcBounds(FBoxSphereBounds * result, FTransform * LocalToWorld) { return NativeCall<FBoxSphereBounds *, FBoxSphereBounds *, FTransform *>(this, "USphereComponent.CalcBounds", result, LocalToWorld); }
	void CalcBoundingCylinder(float * CylinderRadius, float * CylinderHalfHeight) { NativeCall<void, float *, float *>(this, "USphereComponent.CalcBoundingCylinder", CylinderRadius, CylinderHalfHeight); }
	void UpdateBodySetup() { NativeCall<void>(this, "USphereComponent.UpdateBodySetup"); }
	void SetSphereRadius(float InSphereRadius, bool bUpdateOverlaps) { NativeCall<void, float, bool>(this, "USphereComponent.SetSphereRadius", InSphereRadius, bUpdateOverlaps); }
	bool IsZeroExtent() { return NativeCall<bool>(this, "USphereComponent.IsZeroExtent"); }
	bool AreSymmetricRotations(FQuat * A, FQuat * B, FVector * Scale3D) { return NativeCall<bool, FQuat *, FQuat *, FVector *>(this, "USphereComponent.AreSymmetricRotations", A, B, Scale3D); }
	static void StaticRegisterNativesUSphereComponent() { NativeCall<void>(nullptr, "USphereComponent.StaticRegisterNativesUSphereComponent"); }
};

struct AActor : UObject
{
	FieldValue<float> CustomTimeDilationField() { return { this, "AActor.CustomTimeDilation" }; }
	FieldValue<float> ClientReplicationSendNowThresholdField() { return { this, "AActor.ClientReplicationSendNowThreshold" }; }
	FieldValue<TEnumAsByte<enum ENetRole>> RemoteRoleField() { return { this, "AActor.RemoteRole" }; }
	FieldValue<AActor *> OwnerField() { return { this, "AActor.Owner" }; }
	FieldValue<long double> LastReplicatedMovementField() { return { this, "AActor.LastReplicatedMovement" }; }
	FieldValue<TEnumAsByte<enum ENetRole>> RoleField() { return { this, "AActor.Role" }; }
	FieldValue<TEnumAsByte<enum ENetDormancy>> NetDormancyField() { return { this, "AActor.NetDormancy" }; }
	FieldValue<TArray<TWeakObjectPtr<UActorComponent>>> ReplicatedComponentsField() { return { this, "AActor.ReplicatedComponents" }; }
	FieldValue<TWeakObjectPtr<USoundBase>> LastPostProcessVolumeSoundField() { return { this, "AActor.LastPostProcessVolumeSound" }; }
	FieldValue<int> DefaultStasisComponentOctreeFlagsField() { return { this, "AActor.DefaultStasisComponentOctreeFlags" }; }
	FieldValue<UPrimitiveComponent *> StasisCheckComponentField() { return { this, "AActor.StasisCheckComponent" }; }
	FieldValue<TArray<AActor *>> NetworkSpatializationChildrenField() { return { this, "AActor.NetworkSpatializationChildren" }; }
	FieldValue<AActor *> NetworkSpatializationParentField() { return { this, "AActor.NetworkSpatializationParent" }; }
	FieldValue<float> NetworkAndStasisRangeMultiplierField() { return { this, "AActor.NetworkAndStasisRangeMultiplier" }; }
	FieldValue<long double> UnstasisLastInRangeTimeField() { return { this, "AActor.UnstasisLastInRangeTime" }; }
	FieldValue<long double> LastPreReplicationTimeField() { return { this, "AActor.LastPreReplicationTime" }; }
	FieldValue<long double> LastEnterStasisTimeField() { return { this, "AActor.LastEnterStasisTime" }; }
	FieldValue<long double> LastExitStasisTimeField() { return { this, "AActor.LastExitStasisTime" }; }
	FieldValue<FName> CustomTagField() { return { this, "AActor.CustomTag" }; }
	FieldValue<int> CustomDataField() { return { this, "AActor.CustomData" }; }
	FieldValue<float> ReplicationIntervalMultiplierField() { return { this, "AActor.ReplicationIntervalMultiplier" }; }
	FieldValue<int> ForceImmediateReplicationFrameField() { return { this, "AActor.ForceImmediateReplicationFrame" }; }
	FieldValue<char> StasisSetIndexField() { return { this, "AActor.StasisSetIndex" }; }
	FieldValue<char> RandomStartByteField() { return { this, "AActor.RandomStartByte" }; }
	FieldValue<unsigned __int64> LastFrameUnStasisField() { return { this, "AActor.LastFrameUnStasis" }; }
	FieldValue<volatile int> LastUnstasisFrameCounterField() { return { this, "AActor.LastUnstasisFrameCounter" }; }
	FieldValue<TArray<TWeakObjectPtr<UActorComponent>>> StasisUnRegisteredComponentsField() { return { this, "AActor.StasisUnRegisteredComponents" }; }
	FieldValue<float> NetCullDistanceSquaredField() { return { this, "AActor.NetCullDistanceSquared" }; }
	FieldValue<float> NetCullDistanceSquaredDormantField() { return { this, "AActor.NetCullDistanceSquaredDormant" }; }
	FieldValue<int> NetTagField() { return { this, "AActor.NetTag" }; }
	FieldValue<long double> NetUpdateTimeField() { return { this, "AActor.NetUpdateTime" }; }
	FieldValue<float> NetUpdateFrequencyField() { return { this, "AActor.NetUpdateFrequency" }; }
	FieldValue<float> NetPriorityField() { return { this, "AActor.NetPriority" }; }
	FieldValue<long double> LastNetUpdateTimeField() { return { this, "AActor.LastNetUpdateTime" }; }
	FieldValue<FName> NetDriverNameField() { return { this, "AActor.NetDriverName" }; }
	FieldValue<int> TargetingTeamField() { return { this, "AActor.TargetingTeam" }; }
	FieldValue<float> OverrideStasisComponentRadiusField() { return { this, "AActor.OverrideStasisComponentRadius" }; }
	FieldValue<APawn *> InstigatorField() { return { this, "AActor.Instigator" }; }
	FieldValue<long double> CreationTimeField() { return { this, "AActor.CreationTime" }; }
	FieldValue<long double> OriginalCreationTimeField() { return { this, "AActor.OriginalCreationTime" }; }
	FieldValue<TArray<AActor *>> ChildrenField() { return { this, "AActor.Children" }; }
	FieldValue<unsigned int> AnimUpdateRateShiftTagField() { return { this, "AActor.AnimUpdateRateShiftTag" }; }
	FieldValue<unsigned int> AnimUpdateRateFrameCountField() { return { this, "AActor.AnimUpdateRateFrameCount" }; }
	FieldValue<USceneComponent *> RootComponentField() { return { this, "AActor.RootComponent" }; }
	FieldValue<TArray<AMatineeActor *>> ControllingMatineeActorsField() { return { this, "AActor.ControllingMatineeActors" }; }
	FieldValue<float> InitialLifeSpanField() { return { this, "AActor.InitialLifeSpan" }; }
	FieldValue<TArray<FName>> LayersField() { return { this, "AActor.Layers" }; }
	FieldValue<TWeakObjectPtr<AActor>> ParentComponentActorField() { return { this, "AActor.ParentComponentActor" }; }
	FieldValue<long double> LastRenderTimeField() { return { this, "AActor.LastRenderTime" }; }
	FieldValue<long double> LastRenderTimeIgnoreShadowField() { return { this, "AActor.LastRenderTimeIgnoreShadow" }; }
	FieldValue<TArray<FName>> TagsField() { return { this, "AActor.Tags" }; }
	FieldValue<unsigned __int64> HiddenEditorViewsField() { return { this, "AActor.HiddenEditorViews" }; }
	FieldValue<FVector> DefaultActorLocationField() { return { this, "AActor.DefaultActorLocation" }; }
	FieldValue<FGuid> UniqueGuidIdField() { return { this, "AActor.UniqueGuidId" }; }
	FieldValue<float> ForceMaximumReplicationRateUntilTimeField() { return { this, "AActor.ForceMaximumReplicationRateUntilTime" }; }
	FieldValue<long double> LastActorForceReplicationTimeField() { return { this, "AActor.LastActorForceReplicationTime" }; }
	FieldValue<TArray<UActorComponent *>> OwnedComponentsField() { return { this, "AActor.OwnedComponents" }; }
	FieldValue<TArray<UActorComponent *>> SerializedComponentsField() { return { this, "AActor.SerializedComponents" }; }
	FieldValue<int> LastFrameCalculcatedNetworkRangeMultiplierField() { return { this, "AActor.LastFrameCalculcatedNetworkRangeMultiplier" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bHidden() { return { this, "AActor.bHidden" }; }
	BitFieldValue<bool, unsigned __int32> bNetTemporary() { return { this, "AActor.bNetTemporary" }; }
	BitFieldValue<bool, unsigned __int32> bIsMapActor() { return { this, "AActor.bIsMapActor" }; }
	BitFieldValue<bool, unsigned __int32> bHasHighVolumeRPCs() { return { this, "AActor.bHasHighVolumeRPCs" }; }
	BitFieldValue<bool, unsigned __int32> bNetStartup() { return { this, "AActor.bNetStartup" }; }
	BitFieldValue<bool, unsigned __int32> bPreventCharacterBasing() { return { this, "AActor.bPreventCharacterBasing" }; }
	BitFieldValue<bool, unsigned __int32> bPreventCharacterBasingAllowSteppingUp() { return { this, "AActor.bPreventCharacterBasingAllowSteppingUp" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyRelevantToOwner() { return { this, "AActor.bOnlyRelevantToOwner" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysRelevant() { return { this, "AActor.bAlwaysRelevant" }; }
	BitFieldValue<bool, unsigned __int32> bForceHiddenReplication() { return { this, "AActor.bForceHiddenReplication" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPChangedActorTeam() { return { this, "AActor.bUseBPChangedActorTeam" }; }
	BitFieldValue<bool, unsigned __int32> bHasExecutedActorConstruction() { return { this, "AActor.bHasExecutedActorConstruction" }; }
	BitFieldValue<bool, unsigned __int32> bEverSetTimer() { return { this, "AActor.bEverSetTimer" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoredByCharacterEncroachment() { return { this, "AActor.bIgnoredByCharacterEncroachment" }; }
	BitFieldValue<bool, unsigned __int32> bClimbable() { return { this, "AActor.bClimbable" }; }
	BitFieldValue<bool, unsigned __int32> bAttachmentReplicationUseNetworkParent() { return { this, "AActor.bAttachmentReplicationUseNetworkParent" }; }
	BitFieldValue<bool, unsigned __int32> bUnstreamComponentsUseEndOverlap() { return { this, "AActor.bUnstreamComponentsUseEndOverlap" }; }
	BitFieldValue<bool, unsigned __int32> bNetCritical() { return { this, "AActor.bNetCritical" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateInstigator() { return { this, "AActor.bReplicateInstigator" }; }
	BitFieldValue<bool, unsigned __int32> bSuppressDestroyedEvent() { return { this, "AActor.bSuppressDestroyedEvent" }; }
	BitFieldValue<bool, unsigned __int32> bUseOnlyPointForLevelBounds() { return { this, "AActor.bUseOnlyPointForLevelBounds" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateMovement() { return { this, "AActor.bReplicateMovement" }; }
	BitFieldValue<bool, unsigned __int32> bTearOff() { return { this, "AActor.bTearOff" }; }
	BitFieldValue<bool, unsigned __int32> bExchangedRoles() { return { this, "AActor.bExchangedRoles" }; }
	BitFieldValue<bool, unsigned __int32> bStasised() { return { this, "AActor.bStasised" }; }
	BitFieldValue<bool, unsigned __int32> bPendingUnstasis() { return { this, "AActor.bPendingUnstasis" }; }
	BitFieldValue<bool, unsigned __int32> bPendingNetUpdate() { return { this, "AActor.bPendingNetUpdate" }; }
	BitFieldValue<bool, unsigned __int32> bNetLoadOnClient() { return { this, "AActor.bNetLoadOnClient" }; }
	BitFieldValue<bool, unsigned __int32> bNetUseOwnerRelevancy() { return { this, "AActor.bNetUseOwnerRelevancy" }; }
	BitFieldValue<bool, unsigned __int32> bNetUseClientRelevancy() { return { this, "AActor.bNetUseClientRelevancy" }; }
	BitFieldValue<bool, unsigned __int32> bDoNotCook() { return { this, "AActor.bDoNotCook" }; }
	BitFieldValue<bool, unsigned __int32> bHibernateChange() { return { this, "AActor.bHibernateChange" }; }
	BitFieldValue<bool, unsigned __int32> bBlockInput() { return { this, "AActor.bBlockInput" }; }
	BitFieldValue<bool, unsigned __int32> bAutoStasis() { return { this, "AActor.bAutoStasis" }; }
	BitFieldValue<bool, unsigned __int32> bBlueprintMultiUseEntries() { return { this, "AActor.bBlueprintMultiUseEntries" }; }
	BitFieldValue<bool, unsigned __int32> bEnableMultiUse() { return { this, "AActor.bEnableMultiUse" }; }
	BitFieldValue<bool, unsigned __int32> bPreventSaving() { return { this, "AActor.bPreventSaving" }; }
	BitFieldValue<bool, unsigned __int32> bMultiUseCenterHUD() { return { this, "AActor.bMultiUseCenterHUD" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyInitialReplication() { return { this, "AActor.bOnlyInitialReplication" }; }
	BitFieldValue<bool, unsigned __int32> bUseAttachmentReplication() { return { this, "AActor.bUseAttachmentReplication" }; }
	BitFieldValue<bool, unsigned __int32> bUseNetworkSpatialization() { return { this, "AActor.bUseNetworkSpatialization" }; }
	BitFieldValue<bool, unsigned __int32> bNetworkSpatializationForceRelevancyCheck() { return { this, "AActor.bNetworkSpatializationForceRelevancyCheck" }; }
	BitFieldValue<bool, unsigned __int32> bReplicates() { return { this, "AActor.bReplicates" }; }
	BitFieldValue<bool, unsigned __int32> bRunningUserConstructionScript() { return { this, "AActor.bRunningUserConstructionScript" }; }
	BitFieldValue<bool, unsigned __int32> bHasFinishedSpawning() { return { this, "AActor.bHasFinishedSpawning" }; }
	BitFieldValue<bool, unsigned __int32> bDeferredBeginPlay() { return { this, "AActor.bDeferredBeginPlay" }; }
	BitFieldValue<bool, unsigned __int32> bHasReplicatedProperties() { return { this, "AActor.bHasReplicatedProperties" }; }
	BitFieldValue<bool, unsigned __int32> bActorEnableCollision() { return { this, "AActor.bActorEnableCollision" }; }
	BitFieldValue<bool, unsigned __int32> bAutoDestroyWhenFinished() { return { this, "AActor.bAutoDestroyWhenFinished" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeDamaged() { return { this, "AActor.bCanBeDamaged" }; }
	BitFieldValue<bool, unsigned __int32> bPendingKillPending() { return { this, "AActor.bPendingKillPending" }; }
	BitFieldValue<bool, unsigned __int32> bCollideWhenPlacing() { return { this, "AActor.bCollideWhenPlacing" }; }
	BitFieldValue<bool, unsigned __int32> bPreventOnDedicatedServer() { return { this, "AActor.bPreventOnDedicatedServer" }; }
	BitFieldValue<bool, unsigned __int32> bNetMulticasting() { return { this, "AActor.bNetMulticasting" }; }
	BitFieldValue<bool, unsigned __int32> bNetConnectionDidInitialSort() { return { this, "AActor.bNetConnectionDidInitialSort" }; }
	BitFieldValue<bool, unsigned __int32> bDormantNetMulticastForceFullReplication() { return { this, "AActor.bDormantNetMulticastForceFullReplication" }; }
	BitFieldValue<bool, unsigned __int32> bDoOverrideHiddenShadow() { return { this, "AActor.bDoOverrideHiddenShadow" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideHiddenShadowValue() { return { this, "AActor.bOverrideHiddenShadowValue" }; }
	BitFieldValue<bool, unsigned __int32> bAllowReceiveTickEventOnDedicatedServer() { return { this, "AActor.bAllowReceiveTickEventOnDedicatedServer" }; }
	BitFieldValue<bool, unsigned __int32> bLoadedFromSaveGame() { return { this, "AActor.bLoadedFromSaveGame" }; }
	BitFieldValue<bool, unsigned __int32> bPreventLevelBoundsRelevant() { return { this, "AActor.bPreventLevelBoundsRelevant" }; }
	BitFieldValue<bool, unsigned __int32> bForceReplicateDormantChildrenWithoutSpatialRelevancy() { return { this, "AActor.bForceReplicateDormantChildrenWithoutSpatialRelevancy" }; }
	BitFieldValue<bool, unsigned __int32> bFindCameraComponentWhenViewTarget() { return { this, "AActor.bFindCameraComponentWhenViewTarget" }; }
	BitFieldValue<bool, unsigned __int32> bBPPreInitializeComponents() { return { this, "AActor.bBPPreInitializeComponents" }; }
	BitFieldValue<bool, unsigned __int32> bBPPostInitializeComponents() { return { this, "AActor.bBPPostInitializeComponents" }; }
	BitFieldValue<bool, unsigned __int32> bForceNetworkSpatialization() { return { this, "AActor.bForceNetworkSpatialization" }; }
	BitFieldValue<bool, unsigned __int32> bStasisComponentRadiusForceDistanceCheck() { return { this, "AActor.bStasisComponentRadiusForceDistanceCheck" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInventoryItemUsed() { return { this, "AActor.bUseBPInventoryItemUsed" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInventoryItemDropped() { return { this, "AActor.bUseBPInventoryItemDropped" }; }
	BitFieldValue<bool, unsigned __int32> bBPInventoryItemUsedHandlesDurability() { return { this, "AActor.bBPInventoryItemUsedHandlesDurability" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPForceAllowsInventoryUse() { return { this, "AActor.bUseBPForceAllowsInventoryUse" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysCreatePhysicsState() { return { this, "AActor.bAlwaysCreatePhysicsState" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateVelocityHighQuality() { return { this, "AActor.bReplicateVelocityHighQuality" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyReplicateOnNetForcedUpdate() { return { this, "AActor.bOnlyReplicateOnNetForcedUpdate" }; }
	BitFieldValue<bool, unsigned __int32> bActorInitialized() { return { this, "AActor.bActorInitialized" }; }
	BitFieldValue<bool, unsigned __int32> bActorSeamlessTraveled() { return { this, "AActor.bActorSeamlessTraveled" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoresOriginShifting() { return { this, "AActor.bIgnoresOriginShifting" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateHidden() { return { this, "AActor.bReplicateHidden" }; }
	BitFieldValue<bool, unsigned __int32> bPreventActorStasis() { return { this, "AActor.bPreventActorStasis" }; }

	// Functions

	FVector * GetTargetPathfindingLocation(FVector * result, AActor * RequestedBy) { return NativeCall<FVector *, FVector *, AActor *>(this, "AActor.GetTargetPathfindingLocation", result, RequestedBy); }
	FVector * GetTargetingLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AActor.GetTargetingLocation", result); }
	bool IsLevelBoundsRelevant() { return NativeCall<bool>(this, "AActor.IsLevelBoundsRelevant"); }
	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "AActor.GetPrivateStaticClass"); }
	void OutsideWorldBounds() { NativeCall<void>(this, "AActor.OutsideWorldBounds"); }
	bool IsPendingKillPending() { return NativeCall<bool>(this, "AActor.IsPendingKillPending"); }
	bool AllowSaving() { return NativeCall<bool>(this, "AActor.AllowSaving"); }
	FString * GetHumanReadableName(FString * result) { return NativeCall<FString *, FString *>(this, "AActor.GetHumanReadableName", result); }
	bool CheckDefaultSubobjectsInternal() { return NativeCall<bool>(this, "AActor.CheckDefaultSubobjectsInternal"); }
	bool CheckActorComponents() { return NativeCall<bool>(this, "AActor.CheckActorComponents"); }
	void ResetOwnedComponents() { NativeCall<void>(this, "AActor.ResetOwnedComponents"); }
	void PostInitProperties() { NativeCall<void>(this, "AActor.PostInitProperties"); }
	UWorld * GetWorld() { return NativeCall<UWorld *>(this, "AActor.GetWorld"); }
	bool IsInGameplayWorld() { return NativeCall<bool>(this, "AActor.IsInGameplayWorld"); }
	void ClearCrossLevelReferences() { NativeCall<void>(this, "AActor.ClearCrossLevelReferences"); }
	bool TeleportTo(FVector * DestLocation, FRotator * DestRotation, bool bIsATest, bool bNoCheck) { return NativeCall<bool, FVector *, FRotator *, bool, bool>(this, "AActor.TeleportTo", DestLocation, DestRotation, bIsATest, bNoCheck); }
	bool SimpleTeleportTo(FVector * DestLocation, FRotator * DestRotation) { return NativeCall<bool, FVector *, FRotator *>(this, "AActor.SimpleTeleportTo", DestLocation, DestRotation); }
	void AddTickPrerequisiteActor(AActor * PrerequisiteActor) { NativeCall<void, AActor *>(this, "AActor.AddTickPrerequisiteActor", PrerequisiteActor); }
	void AddTickPrerequisiteComponent(UActorComponent * PrerequisiteComponent) { NativeCall<void, UActorComponent *>(this, "AActor.AddTickPrerequisiteComponent", PrerequisiteComponent); }
	void RemoveTickPrerequisiteActor(AActor * PrerequisiteActor) { NativeCall<void, AActor *>(this, "AActor.RemoveTickPrerequisiteActor", PrerequisiteActor); }
	void RemoveTickPrerequisiteComponent(UActorComponent * PrerequisiteComponent) { NativeCall<void, UActorComponent *>(this, "AActor.RemoveTickPrerequisiteComponent", PrerequisiteComponent); }
	void BeginDestroy() { NativeCall<void>(this, "AActor.BeginDestroy"); }
	bool IsReadyForFinishDestroy() { return NativeCall<bool>(this, "AActor.IsReadyForFinishDestroy"); }
	void PostLoad() { NativeCall<void>(this, "AActor.PostLoad"); }
	void PostLoadSubobjects(FObjectInstancingGraph * OuterInstanceGraph) { NativeCall<void, FObjectInstancingGraph *>(this, "AActor.PostLoadSubobjects", OuterInstanceGraph); }
	void ProcessEvent(UFunction * Function, void * Parameters) { NativeCall<void, UFunction *, void *>(this, "AActor.ProcessEvent", Function, Parameters); }
	void RegisterActorTickFunctions(bool bRegister, bool bSaveAndRestoreTickState) { NativeCall<void, bool, bool>(this, "AActor.RegisterActorTickFunctions", bRegister, bSaveAndRestoreTickState); }
	void RegisterAllActorTickFunctions(bool bRegister, bool bDoComponents, bool bSaveAndRestoreTickState) { NativeCall<void, bool, bool, bool>(this, "AActor.RegisterAllActorTickFunctions", bRegister, bDoComponents, bSaveAndRestoreTickState); }
	void SetActorTickEnabled(bool bEnabled) { NativeCall<void, bool>(this, "AActor.SetActorTickEnabled", bEnabled); }
	bool Rename(const wchar_t * InName, UObject * NewOuter, unsigned int Flags) { return NativeCall<bool, const wchar_t *, UObject *, unsigned int>(this, "AActor.Rename", InName, NewOuter, Flags); }
	UNetConnection * GetNetConnection() { return NativeCall<UNetConnection *>(this, "AActor.GetNetConnection"); }
	UPlayer * GetNetOwningPlayer() { return NativeCall<UPlayer *>(this, "AActor.GetNetOwningPlayer"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "AActor.Tick", DeltaSeconds); }
	void GetComponentsBoundingCylinder(float * OutCollisionRadius, float * OutCollisionHalfHeight, bool bNonColliding) { NativeCall<void, float *, float *, bool>(this, "AActor.GetComponentsBoundingCylinder", OutCollisionRadius, OutCollisionHalfHeight, bNonColliding); }
	void GetSimpleCollisionCylinder(float * CollisionRadius, float * CollisionHalfHeight) { NativeCall<void, float *, float *>(this, "AActor.GetSimpleCollisionCylinder", CollisionRadius, CollisionHalfHeight); }
	bool IsRootComponentCollisionRegistered() { return NativeCall<bool>(this, "AActor.IsRootComponentCollisionRegistered"); }
	bool IsAttachedTo(AActor * Other) { return NativeCall<bool, AActor *>(this, "AActor.IsAttachedTo", Other); }
	bool IsBasedOnActor(AActor * Other) { return NativeCall<bool, AActor *>(this, "AActor.IsBasedOnActor", Other); }
	bool Modify(bool bAlwaysMarkDirty) { return NativeCall<bool, bool>(this, "AActor.Modify", bAlwaysMarkDirty); }
	FBox * GetComponentsBoundingBox(FBox * result, bool bNonColliding) { return NativeCall<FBox *, FBox *, bool>(this, "AActor.GetComponentsBoundingBox", result, bNonColliding); }
	FBox * GetComponentsBoundingBoxForLevelBounds(FBox * result) { return NativeCall<FBox *, FBox *>(this, "AActor.GetComponentsBoundingBoxForLevelBounds", result); }
	bool CheckStillInWorld() { return NativeCall<bool>(this, "AActor.CheckStillInWorld"); }
	void GetOverlappingActors(TArray<AActor *> * OverlappingActors, UClass * ClassFilter) { NativeCall<void, TArray<AActor *> *, UClass *>(this, "AActor.GetOverlappingActors", OverlappingActors, ClassFilter); }
	void GetOverlappingComponents(TArray<UPrimitiveComponent *> * OutOverlappingComponents) { NativeCall<void, TArray<UPrimitiveComponent *> *>(this, "AActor.GetOverlappingComponents", OutOverlappingComponents); }
	long double GetLastRenderTime(bool ignoreShadow) { return NativeCall<long double, bool>(this, "AActor.GetLastRenderTime", ignoreShadow); }
	void SetOwner(AActor * NewOwner) { NativeCall<void, AActor *>(this, "AActor.SetOwner", NewOwner); }
	bool HasNetOwner() { return NativeCall<bool>(this, "AActor.HasNetOwner"); }
	void AttachRootComponentTo(USceneComponent * InParent, FName InSocketName, EAttachLocation::Type AttachLocationType, bool bWeldSimulatedBodies) { NativeCall<void, USceneComponent *, FName, EAttachLocation::Type, bool>(this, "AActor.AttachRootComponentTo", InParent, InSocketName, AttachLocationType, bWeldSimulatedBodies); }
	void OnRep_AttachmentReplication() { NativeCall<void>(this, "AActor.OnRep_AttachmentReplication"); }
	void AttachRootComponentToActor(AActor * InParentActor, FName InSocketName, EAttachLocation::Type AttachLocationType, bool bWeldSimulatedBodies) { NativeCall<void, AActor *, FName, EAttachLocation::Type, bool>(this, "AActor.AttachRootComponentToActor", InParentActor, InSocketName, AttachLocationType, bWeldSimulatedBodies); }
	void DetachRootComponentFromParent(bool bMaintainWorldPosition) { NativeCall<void, bool>(this, "AActor.DetachRootComponentFromParent", bMaintainWorldPosition); }
	AActor * GetAttachParentActor() { return NativeCall<AActor *>(this, "AActor.GetAttachParentActor"); }
	FName * GetAttachParentSocketName(FName * result) { return NativeCall<FName *, FName *>(this, "AActor.GetAttachParentSocketName", result); }
	void GetAttachedActors(TArray<AActor *> * OutActors) { NativeCall<void, TArray<AActor *> *>(this, "AActor.GetAttachedActors", OutActors); }
	bool ActorHasTag(FName Tag) { return NativeCall<bool, FName>(this, "AActor.ActorHasTag", Tag); }
	bool IsMatineeControlled() { return NativeCall<bool>(this, "AActor.IsMatineeControlled"); }
	bool IsRelevancyOwnerFor(AActor * ReplicatedActor, AActor * ActorOwner, AActor * ConnectionActor) { return NativeCall<bool, AActor *, AActor *, AActor *>(this, "AActor.IsRelevancyOwnerFor", ReplicatedActor, ActorOwner, ConnectionActor); }
	void PrestreamTextures(float Seconds, bool bEnableStreaming, int CinematicTextureGroups) { NativeCall<void, float, bool, int>(this, "AActor.PrestreamTextures", Seconds, bEnableStreaming, CinematicTextureGroups); }
	void EndPlay(EEndPlayReason::Type EndPlayReason) { NativeCall<void, EEndPlayReason::Type>(this, "AActor.EndPlay", EndPlayReason); }
	FTransform * GetTransform(FTransform * result) { return NativeCall<FTransform *, FTransform *>(this, "AActor.GetTransform", result); }
	void ClearNetworkSpatializationParent() { NativeCall<void>(this, "AActor.ClearNetworkSpatializationParent"); }
	void SetNetworkSpatializationParent(AActor * NewParent) { NativeCall<void, AActor *>(this, "AActor.SetNetworkSpatializationParent", NewParent); }
	void Destroyed() { NativeCall<void>(this, "AActor.Destroyed"); }
	void FellOutOfWorld(UDamageType * dmgType) { NativeCall<void, UDamageType *>(this, "AActor.FellOutOfWorld", dmgType); }
	void MakeNoise(float Loudness, APawn * NoiseInstigator, FVector NoiseLocation) { NativeCall<void, float, APawn *, FVector>(this, "AActor.MakeNoise", Loudness, NoiseInstigator, NoiseLocation); }
	static void MakeNoiseImpl(AActor * NoiseMaker, float Loudness, APawn * NoiseInstigator, FVector * NoiseLocation) { NativeCall<void, AActor *, float, APawn *, FVector *>(nullptr, "AActor.MakeNoiseImpl", NoiseMaker, Loudness, NoiseInstigator, NoiseLocation); }
	float TakeDamage(float DamageAmount, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<float, float, FDamageEvent *, AController *, AActor *>(this, "AActor.TakeDamage", DamageAmount, DamageEvent, EventInstigator, DamageCauser); }
	float InternalTakeRadialDamage(float Damage, FRadialDamageEvent * RadialDamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<float, float, FRadialDamageEvent *, AController *, AActor *>(this, "AActor.InternalTakeRadialDamage", Damage, RadialDamageEvent, EventInstigator, DamageCauser); }
	void DispatchBlockingHit(UPrimitiveComponent * MyComp, UPrimitiveComponent * OtherComp, bool bSelfMoved, FHitResult * Hit) { NativeCall<void, UPrimitiveComponent *, UPrimitiveComponent *, bool, FHitResult *>(this, "AActor.DispatchBlockingHit", MyComp, OtherComp, bSelfMoved, Hit); }
	void BecomeViewTarget(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "AActor.BecomeViewTarget", PC); }
	void EndViewTarget(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "AActor.EndViewTarget", PC); }
	void CalcCamera(float DeltaTime, FMinimalViewInfo * OutResult) { NativeCall<void, float, FMinimalViewInfo *>(this, "AActor.CalcCamera", DeltaTime, OutResult); }
	void ForceNetRelevant() { NativeCall<void>(this, "AActor.ForceNetRelevant"); }
	void InventoryItemUsed(UObject * InventoryItemObject) { NativeCall<void, UObject *>(this, "AActor.InventoryItemUsed", InventoryItemObject); }
	void InventoryItemDropped(UObject * InventoryItemObject) { NativeCall<void, UObject *>(this, "AActor.InventoryItemDropped", InventoryItemObject); }
	bool ForceAllowsInventoryUse(UObject * InventoryItemObject) { return NativeCall<bool, UObject *>(this, "AActor.ForceAllowsInventoryUse", InventoryItemObject); }
	ECollisionResponse GetComponentsCollisionResponseToChannel(ECollisionChannel Channel) { return NativeCall<ECollisionResponse, ECollisionChannel>(this, "AActor.GetComponentsCollisionResponseToChannel", Channel); }
	void RemoveOwnedComponent(UActorComponent * Component) { NativeCall<void, UActorComponent *>(this, "AActor.RemoveOwnedComponent", Component); }
	UActorComponent * GetComponentByClass(TSubclassOf<UActorComponent> ComponentClass) { return NativeCall<UActorComponent *, TSubclassOf<UActorComponent>>(this, "AActor.GetComponentByClass", ComponentClass); }
	UPrimitiveComponent * GetVisibleComponentByClass(TSubclassOf<UPrimitiveComponent> ComponentClass) { return NativeCall<UPrimitiveComponent *, TSubclassOf<UPrimitiveComponent>>(this, "AActor.GetVisibleComponentByClass", ComponentClass); }
	UActorComponent * GetComponentByCustomTag(FName TheTag) { return NativeCall<UActorComponent *, FName>(this, "AActor.GetComponentByCustomTag", TheTag); }
	TArray<UActorComponent *> * GetComponentsByClass(TArray<UActorComponent *> * result, TSubclassOf<UActorComponent> ComponentClass) { return NativeCall<TArray<UActorComponent *> *, TArray<UActorComponent *> *, TSubclassOf<UActorComponent>>(this, "AActor.GetComponentsByClass", result, ComponentClass); }
	TArray<UActorComponent *> * GetComponentsByCustomTag(TArray<UActorComponent *> * result, FName TheTag) { return NativeCall<TArray<UActorComponent *> *, TArray<UActorComponent *> *, FName>(this, "AActor.GetComponentsByCustomTag", result, TheTag); }
	void DisableComponentsSimulatePhysics() { NativeCall<void>(this, "AActor.DisableComponentsSimulatePhysics"); }
	void PostSpawnInitialize(FVector * SpawnLocation, FRotator * SpawnRotation, AActor * InOwner, APawn * InInstigator, bool bRemoteOwned, bool bNoFail, bool bDeferConstruction, bool bDeferBeginPlay) { NativeCall<void, FVector *, FRotator *, AActor *, APawn *, bool, bool, bool, bool>(this, "AActor.PostSpawnInitialize", SpawnLocation, SpawnRotation, InOwner, InInstigator, bRemoteOwned, bNoFail, bDeferConstruction, bDeferBeginPlay); }
	void FinishSpawning(FTransform * Transform, bool bIsDefaultTransform) { NativeCall<void, FTransform *, bool>(this, "AActor.FinishSpawning", Transform, bIsDefaultTransform); }
	void DoExecuteActorConstruction(FTransform * Transform, bool bIsDefaultTransform) { NativeCall<void, FTransform *, bool>(this, "AActor.DoExecuteActorConstruction", Transform, bIsDefaultTransform); }
	void PreSave() { NativeCall<void>(this, "AActor.PreSave"); }
	void PostActorConstruction() { NativeCall<void>(this, "AActor.PostActorConstruction"); }
	void SetReplicates(bool bInReplicates) { NativeCall<void, bool>(this, "AActor.SetReplicates", bInReplicates); }
	void CopyRemoteRoleFrom(AActor * CopyFromActor) { NativeCall<void, AActor *>(this, "AActor.CopyRemoteRoleFrom", CopyFromActor); }
	void PostNetInit() { NativeCall<void>(this, "AActor.PostNetInit"); }
	void BeginPlay() { NativeCall<void>(this, "AActor.BeginPlay"); }
	void MatineeUpdated() { NativeCall<void>(this, "AActor.MatineeUpdated"); }
	void ForceReplicateNowWithChannel() { NativeCall<void>(this, "AActor.ForceReplicateNowWithChannel"); }
	void EnableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "AActor.EnableInput", PlayerController); }
	void DisableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "AActor.DisableInput", PlayerController); }
	float GetInputAxisValue(FName InputAxisName) { return NativeCall<float, FName>(this, "AActor.GetInputAxisValue", InputAxisName); }
	float GetInputAxisKeyValue(FKey InputAxisKey) { return NativeCall<float, FKey>(this, "AActor.GetInputAxisKeyValue", InputAxisKey); }
	FVector * GetInputVectorAxisValue(FVector * result, FKey InputAxisKey) { return NativeCall<FVector *, FVector *, FKey>(this, "AActor.GetInputVectorAxisValue", result, InputAxisKey); }
	bool SetActorLocation(FVector * NewLocation, bool bSweep) { return NativeCall<bool, FVector *, bool>(this, "AActor.SetActorLocation", NewLocation, bSweep); }
	bool SetActorRotation(FRotator NewRotation) { return NativeCall<bool, FRotator>(this, "AActor.SetActorRotation", NewRotation); }
	bool SetActorLocationAndRotation(FVector * NewLocation, FRotator NewRotation, bool bSweep) { return NativeCall<bool, FVector *, FRotator, bool>(this, "AActor.SetActorLocationAndRotation", NewLocation, NewRotation, bSweep); }
	void SetActorScale3D(FVector * NewScale3D) { NativeCall<void, FVector *>(this, "AActor.SetActorScale3D", NewScale3D); }
	void SetActorRelativeScale3D(FVector NewRelativeScale) { NativeCall<void, FVector>(this, "AActor.SetActorRelativeScale3D", NewRelativeScale); }
	void SetActorHiddenInGame(bool bNewHidden) { NativeCall<void, bool>(this, "AActor.SetActorHiddenInGame", bNewHidden); }
	void SetActorEnableCollision(bool bNewActorEnableCollision) { NativeCall<void, bool>(this, "AActor.SetActorEnableCollision", bNewActorEnableCollision); }
	bool Destroy(bool bNetForce, bool bShouldModifyLevel) { return NativeCall<bool, bool, bool>(this, "AActor.Destroy", bNetForce, bShouldModifyLevel); }
	bool SetRootComponent(USceneComponent * NewRootComponent) { return NativeCall<bool, USceneComponent *>(this, "AActor.SetRootComponent", NewRootComponent); }
	FVector * GetActorForwardVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AActor.GetActorForwardVector", result); }
	FVector * GetActorUpVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AActor.GetActorUpVector", result); }
	FVector * GetActorRightVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AActor.GetActorRightVector", result); }
	void GetActorBounds(bool bOnlyCollidingComponents, FVector * Origin, FVector * BoxExtent) { NativeCall<void, bool, FVector *, FVector *>(this, "AActor.GetActorBounds", bOnlyCollidingComponents, Origin, BoxExtent); }
	AWorldSettings * GetWorldSettings() { return NativeCall<AWorldSettings *>(this, "AActor.GetWorldSettings"); }
	void PlaySoundOnActor(USoundCue * InSoundCue, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, USoundCue *, float, float>(this, "AActor.PlaySoundOnActor", InSoundCue, VolumeMultiplier, PitchMultiplier); }
	void PlaySoundAtLocation(USoundCue * InSoundCue, FVector SoundLocation, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, USoundCue *, FVector, float, float>(this, "AActor.PlaySoundAtLocation", InSoundCue, SoundLocation, VolumeMultiplier, PitchMultiplier); }
	void UnregisterAllComponents(bool bDetachFromOtherParent) { NativeCall<void, bool>(this, "AActor.UnregisterAllComponents", bDetachFromOtherParent); }
	void RegisterAllComponents() { NativeCall<void>(this, "AActor.RegisterAllComponents"); }
	void MarkComponentsAsPendingKill() { NativeCall<void>(this, "AActor.MarkComponentsAsPendingKill"); }
	void ReregisterAllComponents() { NativeCall<void>(this, "AActor.ReregisterAllComponents"); }
	void MarkComponentsRenderStateDirty() { NativeCall<void>(this, "AActor.MarkComponentsRenderStateDirty"); }
	void InitializeComponents() { NativeCall<void>(this, "AActor.InitializeComponents"); }
	void UninitializeComponents(EEndPlayReason::Type EndPlayReason) { NativeCall<void, EEndPlayReason::Type>(this, "AActor.UninitializeComponents", EndPlayReason); }
	void InvalidateLightingCacheDetailed(bool bTranslationOnly) { NativeCall<void, bool>(this, "AActor.InvalidateLightingCacheDetailed", bTranslationOnly); }
	bool ActorLineTraceSingle(FHitResult * OutHit, FVector * Start, FVector * End, ECollisionChannel TraceChannel, FCollisionQueryParams * Params) { return NativeCall<bool, FHitResult *, FVector *, FVector *, ECollisionChannel, FCollisionQueryParams *>(this, "AActor.ActorLineTraceSingle", OutHit, Start, End, TraceChannel, Params); }
	void SetLifeSpan(float InLifespan) { NativeCall<void, float>(this, "AActor.SetLifeSpan", InLifespan); }
	float GetLifeSpan() { return NativeCall<float>(this, "AActor.GetLifeSpan"); }
	void PostInitializeComponents() { NativeCall<void>(this, "AActor.PostInitializeComponents"); }
	void Stasis() { NativeCall<void>(this, "AActor.Stasis"); }
	void Unstasis() { NativeCall<void>(this, "AActor.Unstasis"); }
	void PreInitializeComponents() { NativeCall<void>(this, "AActor.PreInitializeComponents"); }
	float GetDistanceTo(AActor * OtherActor) { return NativeCall<float, AActor *>(this, "AActor.GetDistanceTo", OtherActor); }
	float GetHorizontalDistanceTo(AActor * OtherActor) { return NativeCall<float, AActor *>(this, "AActor.GetHorizontalDistanceTo", OtherActor); }
	float GetVerticalDistanceTo(AActor * OtherActor) { return NativeCall<float, AActor *>(this, "AActor.GetVerticalDistanceTo", OtherActor); }
	float GetDotProductTo(AActor * OtherActor) { return NativeCall<float, AActor *>(this, "AActor.GetDotProductTo", OtherActor); }
	float GetHorizontalDotProductTo(AActor * OtherActor) { return NativeCall<float, AActor *>(this, "AActor.GetHorizontalDotProductTo", OtherActor); }
	APlayerController * GetOwnerController() { return NativeCall<APlayerController *>(this, "AActor.GetOwnerController"); }
	bool AlwaysReplicatePropertyConditional(UProperty * forProperty) { return NativeCall<bool, UProperty *>(this, "AActor.AlwaysReplicatePropertyConditional", forProperty); }
	bool TryMultiUse(APlayerController * ForPC, int UseIndex) { return NativeCall<bool, APlayerController *, int>(this, "AActor.TryMultiUse", ForPC, UseIndex); }
	void ChangeActorTeam(int NewTeam) { NativeCall<void, int>(this, "AActor.ChangeActorTeam", NewTeam); }
	bool GetIsMapActor() { return NativeCall<bool>(this, "AActor.GetIsMapActor"); }
	void SendExecCommand(FName CommandName, FNetExecParams * ExecParams, bool bIsReliable) { NativeCall<void, FName, FNetExecParams *, bool>(this, "AActor.SendExecCommand", CommandName, ExecParams, bIsReliable); }
	void ServerSendSimpleExecCommandToEveryone(FName CommandName, bool bIsReliable, bool bForceSendToLocalPlayer, bool bIgnoreRelevancy) { NativeCall<void, FName, bool, bool, bool>(this, "AActor.ServerSendSimpleExecCommandToEveryone", CommandName, bIsReliable, bForceSendToLocalPlayer, bIgnoreRelevancy); }
	bool IsOwnedOrControlledBy(AActor * TestOwner) { return NativeCall<bool, AActor *>(this, "AActor.IsOwnedOrControlledBy", TestOwner); }
	bool PreventCharacterBasing(AActor * OtherActor, UPrimitiveComponent * BasedOnComponent) { return NativeCall<bool, AActor *, UPrimitiveComponent *>(this, "AActor.PreventCharacterBasing", OtherActor, BasedOnComponent); }
	bool BPIsA(TSubclassOf<AActor> anActorClass) { return NativeCall<bool, TSubclassOf<AActor>>(this, "AActor.BPIsA", anActorClass); }
	void MulticastProperty(FName PropertyName) { NativeCall<void, FName>(this, "AActor.MulticastProperty", PropertyName); }
	void PropertyServerToClients_Implementation(AActor * ActorToRep, FName PropertyName, TArray<unsigned char> * ReplicationData) { NativeCall<void, AActor *, FName, TArray<unsigned char> *>(this, "AActor.PropertyServerToClients_Implementation", ActorToRep, PropertyName, ReplicationData); }
	float GetNetStasisAndRangeMultiplier() { return NativeCall<float>(this, "AActor.GetNetStasisAndRangeMultiplier"); }
	void StopActorSound(USoundBase * SoundAsset, float FadeOutTime) { NativeCall<void, USoundBase *, float>(this, "AActor.StopActorSound", SoundAsset, FadeOutTime); }
	void GetAllSceneComponents(TArray<USceneComponent *> * OutComponents) { NativeCall<void, TArray<USceneComponent *> *>(this, "AActor.GetAllSceneComponents", OutComponents); }
	void ActorPlaySound_Implementation(USoundBase * SoundAsset, bool bAttach, FName BoneName, FVector LocOffset) { NativeCall<void, USoundBase *, bool, FName, FVector>(this, "AActor.ActorPlaySound_Implementation", SoundAsset, bAttach, BoneName, LocOffset); }
	void NetAttachRootComponentTo_Implementation(USceneComponent * InParent, FName InSocketName, FVector RelativeLocation, FRotator RelativeRotation) { NativeCall<void, USceneComponent *, FName, FVector, FRotator>(this, "AActor.NetAttachRootComponentTo_Implementation", InParent, InSocketName, RelativeLocation, RelativeRotation); }
	void NetDetachRootComponentFromAny_Implementation() { NativeCall<void>(this, "AActor.NetDetachRootComponentFromAny_Implementation"); }
	void ResetPropertiesForConstruction() { NativeCall<void>(this, "AActor.ResetPropertiesForConstruction"); }
	void DestroyConstructedComponents() { NativeCall<void>(this, "AActor.DestroyConstructedComponents"); }
	void RerunConstructionScripts() { NativeCall<void>(this, "AActor.RerunConstructionScripts"); }
	UActorComponent * CreateComponentFromTemplate(UActorComponent * Template, FString * InName) { return NativeCall<UActorComponent *, UActorComponent *, FString *>(this, "AActor.CreateComponentFromTemplate", Template, InName); }
	UActorComponent * AddComponent(FName TemplateName, bool bManualAttachment, FTransform * RelativeTransform, UObject * ComponentTemplateContext) { return NativeCall<UActorComponent *, FName, bool, FTransform *, UObject *>(this, "AActor.AddComponent", TemplateName, bManualAttachment, RelativeTransform, ComponentTemplateContext); }
	void PreNetReceive() { NativeCall<void>(this, "AActor.PreNetReceive"); }
	void PostNetReceive() { NativeCall<void>(this, "AActor.PostNetReceive"); }
	void OnRep_ReplicatedMovement() { NativeCall<void>(this, "AActor.OnRep_ReplicatedMovement"); }
	void PostNetReceiveLocationAndRotation() { NativeCall<void>(this, "AActor.PostNetReceiveLocationAndRotation"); }
	void PostNetReceivePhysicState() { NativeCall<void>(this, "AActor.PostNetReceivePhysicState"); }
	bool IsNetRelevantFor(APlayerController * RealViewer, AActor * Viewer, FVector * SrcLocation) { return NativeCall<bool, APlayerController *, AActor *, FVector *>(this, "AActor.IsNetRelevantFor", RealViewer, Viewer, SrcLocation); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AActor.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void GetSubobjectsWithStableNamesForNetworking(TArray<UObject *> * ObjList) { NativeCall<void, TArray<UObject *> *>(this, "AActor.GetSubobjectsWithStableNamesForNetworking", ObjList); }
	void OnSubobjectCreatedFromReplication(UObject * NewSubobject) { NativeCall<void, UObject *>(this, "AActor.OnSubobjectCreatedFromReplication", NewSubobject); }
	void OnSubobjectDestroyFromReplication(UObject * NewSubobject) { NativeCall<void, UObject *>(this, "AActor.OnSubobjectDestroyFromReplication", NewSubobject); }
	bool IsNameStableForNetworking() { return NativeCall<bool>(this, "AActor.IsNameStableForNetworking"); }
	void GetComponents(TArray<UActorComponent *> * OutComponents) { NativeCall<void, TArray<UActorComponent *> *>(this, "AActor.GetComponents", OutComponents); }
	void GatherCurrentMovement() { NativeCall<void>(this, "AActor.GatherCurrentMovement"); }
	void ForceReplicateNow(bool bForceCreateChannel, bool bForceCreateChannelIfRelevant) { NativeCall<void, bool, bool>(this, "AActor.ForceReplicateNow", bForceCreateChannel, bForceCreateChannelIfRelevant); }
	void ForceNetUpdate(bool bDormantDontReplicateProperties) { NativeCall<void, bool>(this, "AActor.ForceNetUpdate", bDormantDontReplicateProperties); }
	static void StaticRegisterNativesAActor() { NativeCall<void>(nullptr, "AActor.StaticRegisterNativesAActor"); }
	bool AllowIgnoreCharacterEncroachment(UPrimitiveComponent * HitComponent, AActor * EncroachingCharacter) { return NativeCall<bool, UPrimitiveComponent *, AActor *>(this, "AActor.AllowIgnoreCharacterEncroachment", HitComponent, EncroachingCharacter); }
	bool AllowManualMultiUseActivation(APlayerController * ForPC) { return NativeCall<bool, APlayerController *>(this, "AActor.AllowManualMultiUseActivation", ForPC); }
	void BPAttachedRootComponent() { NativeCall<void>(this, "AActor.BPAttachedRootComponent"); }
	bool BPForceAllowsInventoryUse(UObject * InventoryItemObject) { return NativeCall<bool, UObject *>(this, "AActor.BPForceAllowsInventoryUse", InventoryItemObject); }
	void BPInventoryItemDropped(UObject * InventoryItemObject) { NativeCall<void, UObject *>(this, "AActor.BPInventoryItemDropped", InventoryItemObject); }
	void BPInventoryItemUsed(UObject * InventoryItemObject) { NativeCall<void, UObject *>(this, "AActor.BPInventoryItemUsed", InventoryItemObject); }
	void DrawBasicFloatingHUD(AHUD * ForHUD) { NativeCall<void, AHUD *>(this, "AActor.DrawBasicFloatingHUD", ForHUD); }
	void K2_OnBecomeViewTarget(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "AActor.K2_OnBecomeViewTarget", PC); }
	void K2_OnEndViewTarget(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "AActor.K2_OnEndViewTarget", PC); }
	void ModifyHudMultiUseLoc(FVector2D * theVec, APlayerController * PC, int index) { NativeCall<void, FVector2D *, APlayerController *, int>(this, "AActor.ModifyHudMultiUseLoc", theVec, PC, index); }
	void PropertyServerToClients(AActor * ActorToRep, FName PropertyName, TArray<unsigned char> * ReplicationData) { NativeCall<void, AActor *, FName, TArray<unsigned char> *>(this, "AActor.PropertyServerToClients", ActorToRep, PropertyName, ReplicationData); }
	void ReceiveActorBeginCursorOver() { NativeCall<void>(this, "AActor.ReceiveActorBeginCursorOver"); }
	void ReceiveActorBeginOverlap(AActor * OtherActor) { NativeCall<void, AActor *>(this, "AActor.ReceiveActorBeginOverlap", OtherActor); }
	void ReceiveActorEndCursorOver() { NativeCall<void>(this, "AActor.ReceiveActorEndCursorOver"); }
	void ReceiveActorEndOverlap(AActor * OtherActor) { NativeCall<void, AActor *>(this, "AActor.ReceiveActorEndOverlap", OtherActor); }
	void ReceiveActorOnClicked() { NativeCall<void>(this, "AActor.ReceiveActorOnClicked"); }
	void ReceiveActorOnInputTouchBegin(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "AActor.ReceiveActorOnInputTouchBegin", FingerIndex); }
	void ReceiveActorOnInputTouchEnd(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "AActor.ReceiveActorOnInputTouchEnd", FingerIndex); }
	void ReceiveActorOnInputTouchEnter(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "AActor.ReceiveActorOnInputTouchEnter", FingerIndex); }
	void ReceiveActorOnInputTouchLeave(ETouchIndex::Type FingerIndex) { NativeCall<void, ETouchIndex::Type>(this, "AActor.ReceiveActorOnInputTouchLeave", FingerIndex); }
	void ReceiveActorOnReleased() { NativeCall<void>(this, "AActor.ReceiveActorOnReleased"); }
	void ReceiveAnyDamage(float Damage, UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser) { NativeCall<void, float, UDamageType *, AController *, AActor *>(this, "AActor.ReceiveAnyDamage", Damage, DamageType, InstigatedBy, DamageCauser); }
	void ReceiveBeginPlay() { NativeCall<void>(this, "AActor.ReceiveBeginPlay"); }
	void ReceiveDestroyed() { NativeCall<void>(this, "AActor.ReceiveDestroyed"); }
	void ReceiveEndPlay(EEndPlayReason::Type EndPlayReason) { NativeCall<void, EEndPlayReason::Type>(this, "AActor.ReceiveEndPlay", EndPlayReason); }
	void ReceiveHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, FHitResult * Hit) { NativeCall<void, UPrimitiveComponent *, AActor *, UPrimitiveComponent *, bool, FVector, FVector, FVector, FHitResult *>(this, "AActor.ReceiveHit", MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit); }
	void ReceiveInput(FString * InputName, float Value, FVector VectorValue, bool bStarted, bool bEnded) { NativeCall<void, FString *, float, FVector, bool, bool>(this, "AActor.ReceiveInput", InputName, Value, VectorValue, bStarted, bEnded); }
	void ReceivePointDamage(float Damage, UDamageType * DamageType, FVector HitLocation, FVector HitNormal, UPrimitiveComponent * HitComponent, FName BoneName, FVector ShotFromDirection, AController * InstigatedBy, AActor * DamageCauser) { NativeCall<void, float, UDamageType *, FVector, FVector, UPrimitiveComponent *, FName, FVector, AController *, AActor *>(this, "AActor.ReceivePointDamage", Damage, DamageType, HitLocation, HitNormal, HitComponent, BoneName, ShotFromDirection, InstigatedBy, DamageCauser); }
	void ReceiveRadialDamage(float DamageReceived, UDamageType * DamageType, FVector Origin, FHitResult * HitInfo, AController * InstigatedBy, AActor * DamageCauser) { NativeCall<void, float, UDamageType *, FVector, FHitResult *, AController *, AActor *>(this, "AActor.ReceiveRadialDamage", DamageReceived, DamageType, Origin, HitInfo, InstigatedBy, DamageCauser); }
	void ReceiveTick(float DeltaSeconds) { NativeCall<void, float>(this, "AActor.ReceiveTick", DeltaSeconds); }
	void RecieveMatineeUpdated() { NativeCall<void>(this, "AActor.RecieveMatineeUpdated"); }
	void UserConstructionScript() { NativeCall<void>(this, "AActor.UserConstructionScript"); }
};

struct APawn : AActor
{
	FieldValue<float> BaseEyeHeightField() { return { this, "APawn.BaseEyeHeight" }; }
	FieldValue<TSubclassOf<AController>> AIControllerClassField() { return { this, "APawn.AIControllerClass" }; }
	FieldValue<APlayerState *> PlayerStateField() { return { this, "APawn.PlayerState" }; }
	FieldValue<char> RemoteViewPitchField() { return { this, "APawn.RemoteViewPitch" }; }
	FieldValue<AController *> LastHitByField() { return { this, "APawn.LastHitBy" }; }
	FieldValue<AController *> ControllerField() { return { this, "APawn.Controller" }; }
	FieldValue<float> AllowedYawErrorField() { return { this, "APawn.AllowedYawError" }; }
	FieldValue<bool> bClearOnConsumeField() { return { this, "APawn.bClearOnConsume" }; }
	FieldValue<FVector> ControlInputVectorField() { return { this, "APawn.ControlInputVector" }; }
	FieldValue<FVector> LastControlInputVectorField() { return { this, "APawn.LastControlInputVector" }; }
	FieldValue<TWeakObjectPtr<AController>> SpawnedForControllerField() { return { this, "APawn.SpawnedForController" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUseControllerRotationPitch() { return { this, "APawn.bUseControllerRotationPitch" }; }
	BitFieldValue<bool, unsigned __int32> bUseControllerRotationYaw() { return { this, "APawn.bUseControllerRotationYaw" }; }
	BitFieldValue<bool, unsigned __int32> bUseControllerRotationRoll() { return { this, "APawn.bUseControllerRotationRoll" }; }
	BitFieldValue<bool, unsigned __int32> bCanAffectNavigationGeneration() { return { this, "APawn.bCanAffectNavigationGeneration" }; }
	BitFieldValue<bool, unsigned __int32> bPreventMovementStoppingOnPossess() { return { this, "APawn.bPreventMovementStoppingOnPossess" }; }
	BitFieldValue<bool, unsigned __int32> bInputEnabled() { return { this, "APawn.bInputEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bProcessingOutsideWorldBounds() { return { this, "APawn.bProcessingOutsideWorldBounds" }; }

	// Functions

	FVector * GetNavAgentLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APawn.GetNavAgentLocation", result); }
	void PreInitializeComponents() { NativeCall<void>(this, "APawn.PreInitializeComponents"); }
	void PostInitializeComponents() { NativeCall<void>(this, "APawn.PostInitializeComponents"); }
	void PostLoad() { NativeCall<void>(this, "APawn.PostLoad"); }
	void PostRegisterAllComponents() { NativeCall<void>(this, "APawn.PostRegisterAllComponents"); }
	void UpdateNavAgent() { NativeCall<void>(this, "APawn.UpdateNavAgent"); }
	bool CanBeBaseForCharacter(APawn * APawn2) { return NativeCall<bool, APawn *>(this, "APawn.CanBeBaseForCharacter", APawn2); }
	FVector * GetVelocity(FVector * result, bool bIsForRagdoll) { return NativeCall<FVector *, FVector *, bool>(this, "APawn.GetVelocity", result, bIsForRagdoll); }
	bool IsLocallyControlled() { return NativeCall<bool>(this, "APawn.IsLocallyControlled"); }
	bool ReachedDesiredRotation() { return NativeCall<bool>(this, "APawn.ReachedDesiredRotation"); }
	float GetDefaultHalfHeight() { return NativeCall<float>(this, "APawn.GetDefaultHalfHeight"); }
	bool ShouldTickIfViewportsOnly() { return NativeCall<bool>(this, "APawn.ShouldTickIfViewportsOnly"); }
	FVector * GetPawnViewLocation(FVector * result, bool bAllTransforms) { return NativeCall<FVector *, FVector *, bool>(this, "APawn.GetPawnViewLocation", result, bAllTransforms); }
	FRotator * GetViewRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "APawn.GetViewRotation", result); }
	void SpawnDefaultController() { NativeCall<void>(this, "APawn.SpawnDefaultController"); }
	void TurnOff() { NativeCall<void>(this, "APawn.TurnOff"); }
	void BecomeViewTarget(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "APawn.BecomeViewTarget", PC); }
	void PawnClientRestart() { NativeCall<void>(this, "APawn.PawnClientRestart"); }
	void Destroyed() { NativeCall<void>(this, "APawn.Destroyed"); }
	bool ShouldTakeDamage(float Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<bool, float, FDamageEvent *, AController *, AActor *>(this, "APawn.ShouldTakeDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	float TakeDamage(float Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<float, float, FDamageEvent *, AController *, AActor *>(this, "APawn.TakeDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	FRotator * GetControlRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "APawn.GetControlRotation", result); }
	void OnRep_Controller() { NativeCall<void>(this, "APawn.OnRep_Controller"); }
	void PossessedBy(AController * NewController) { NativeCall<void, AController *>(this, "APawn.PossessedBy", NewController); }
	void UnPossessed() { NativeCall<void>(this, "APawn.UnPossessed"); }
	UNetConnection * GetNetConnection() { return NativeCall<UNetConnection *>(this, "APawn.GetNetConnection"); }
	UPlayer * GetNetOwningPlayer() { return NativeCall<UPlayer *>(this, "APawn.GetNetOwningPlayer"); }
	void DestroyPlayerInputComponent() { NativeCall<void>(this, "APawn.DestroyPlayerInputComponent"); }
	bool IsMoveInputIgnored() { return NativeCall<bool>(this, "APawn.IsMoveInputIgnored"); }
	void AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce) { NativeCall<void, FVector, float, bool>(this, "APawn.AddMovementInput", WorldDirection, ScaleValue, bForce); }
	FVector * ConsumeMovementInputVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APawn.ConsumeMovementInputVector", result); }
	void Internal_AddMovementInput(FVector WorldAccel, bool bForce) { NativeCall<void, FVector, bool>(this, "APawn.Internal_AddMovementInput", WorldAccel, bForce); }
	void PostInputProcessed() { NativeCall<void>(this, "APawn.PostInputProcessed"); }
	FVector * Internal_ConsumeMovementInputVector(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APawn.Internal_ConsumeMovementInputVector", result); }
	void AddControllerPitchInput(float Val) { NativeCall<void, float>(this, "APawn.AddControllerPitchInput", Val); }
	void AddControllerYawInput(float Val) { NativeCall<void, float>(this, "APawn.AddControllerYawInput", Val); }
	void AddControllerRollInput(float Val) { NativeCall<void, float>(this, "APawn.AddControllerRollInput", Val); }
	void Restart() { NativeCall<void>(this, "APawn.Restart"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "APawn.Tick", DeltaSeconds); }
	void RecalculateBaseEyeHeight() { NativeCall<void>(this, "APawn.RecalculateBaseEyeHeight"); }
	void Reset() { NativeCall<void>(this, "APawn.Reset"); }
	FString * GetHumanReadableName(FString * result) { return NativeCall<FString *, FString *>(this, "APawn.GetHumanReadableName", result); }
	void GetActorEyesViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "APawn.GetActorEyesViewPoint", out_Location, out_Rotation); }
	FRotator * GetBaseAimRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "APawn.GetBaseAimRotation", result); }
	bool InFreeCam() { return NativeCall<bool>(this, "APawn.InFreeCam"); }
	void OutsideWorldBounds() { NativeCall<void>(this, "APawn.OutsideWorldBounds"); }
	void ClientSetRotation(FRotator NewRotation) { NativeCall<void, FRotator>(this, "APawn.ClientSetRotation", NewRotation); }
	void FaceRotation(FRotator NewControlRotation, float DeltaTime, bool bFromController) { NativeCall<void, FRotator, float, bool>(this, "APawn.FaceRotation", NewControlRotation, DeltaTime, bFromController); }
	void DetachFromControllerPendingDestroy() { NativeCall<void>(this, "APawn.DetachFromControllerPendingDestroy"); }
	AController * GetDamageInstigator(AController * InstigatedBy, UDamageType * DamageType) { return NativeCall<AController *, AController *, UDamageType *>(this, "APawn.GetDamageInstigator", InstigatedBy, DamageType); }
	void EnableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "APawn.EnableInput", PlayerController); }
	void DisableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "APawn.DisableInput", PlayerController); }
	bool IsWalking() { return NativeCall<bool>(this, "APawn.IsWalking"); }
	bool IsFalling() { return NativeCall<bool>(this, "APawn.IsFalling"); }
	bool IsCrouched() { return NativeCall<bool>(this, "APawn.IsCrouched"); }
	void PostNetReceiveVelocity(FVector * NewVelocity) { NativeCall<void, FVector *>(this, "APawn.PostNetReceiveVelocity", NewVelocity); }
	void PostNetReceiveLocationAndRotation() { NativeCall<void>(this, "APawn.PostNetReceiveLocationAndRotation"); }
	bool IsBasedOnActor(AActor * Other) { return NativeCall<bool, AActor *>(this, "APawn.IsBasedOnActor", Other); }
	bool IsNetRelevantFor(APlayerController * RealViewer, AActor * Viewer, FVector * SrcLocation) { return NativeCall<bool, APlayerController *, AActor *, FVector *>(this, "APawn.IsNetRelevantFor", RealViewer, Viewer, SrcLocation); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APawn.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void PawnMakeNoise(float Loudness, FVector NoiseLocation, bool bUseNoiseMakerLocation, AActor * NoiseMaker) { NativeCall<void, float, FVector, bool, AActor *>(this, "APawn.PawnMakeNoise", Loudness, NoiseLocation, bUseNoiseMakerLocation, NoiseMaker); }
	APlayerController * GetOwnerController() { return NativeCall<APlayerController *>(this, "APawn.GetOwnerController"); }
	AController * GetCharacterController() { return NativeCall<AController *>(this, "APawn.GetCharacterController"); }
	bool IsLocallyControlledByPlayer() { return NativeCall<bool>(this, "APawn.IsLocallyControlledByPlayer"); }
	static void StaticRegisterNativesAPawn() { NativeCall<void>(nullptr, "APawn.StaticRegisterNativesAPawn"); }
};

struct UCheatManager
{
	FieldValue<float> DebugTraceDistanceField() { return { this, "UCheatManager.DebugTraceDistance" }; }
	FieldValue<float> DebugCapsuleHalfHeightField() { return { this, "UCheatManager.DebugCapsuleHalfHeight" }; }
	FieldValue<float> DebugCapsuleRadiusField() { return { this, "UCheatManager.DebugCapsuleRadius" }; }
	FieldValue<float> DebugTraceDrawNormalLengthField() { return { this, "UCheatManager.DebugTraceDrawNormalLength" }; }
	FieldValue<TEnumAsByte<enum ECollisionChannel>> DebugTraceChannelField() { return { this, "UCheatManager.DebugTraceChannel" }; }
	FieldValue<int> CurrentTraceIndexField() { return { this, "UCheatManager.CurrentTraceIndex" }; }
	FieldValue<int> CurrentTracePawnIndexField() { return { this, "UCheatManager.CurrentTracePawnIndex" }; }
	FieldValue<float> DumpAILogsIntervalField() { return { this, "UCheatManager.DumpAILogsInterval" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bDebugCapsuleSweep() { return { this, "UCheatManager.bDebugCapsuleSweep" }; }
	BitFieldValue<bool, unsigned __int32> bDebugCapsuleSweepPawn() { return { this, "UCheatManager.bDebugCapsuleSweepPawn" }; }
	BitFieldValue<bool, unsigned __int32> bDebugCapsuleTraceComplex() { return { this, "UCheatManager.bDebugCapsuleTraceComplex" }; }
	BitFieldValue<bool, unsigned __int32> bToggleAILogging() { return { this, "UCheatManager.bToggleAILogging" }; }

	// Functions

	void FreezeFrame(float delay) { NativeCall<void, float>(this, "UCheatManager.FreezeFrame", delay); }
	void Teleport() { NativeCall<void>(this, "UCheatManager.Teleport"); }
	void ChangeSize(float F) { NativeCall<void, float>(this, "UCheatManager.ChangeSize", F); }
	void Fly() { NativeCall<void>(this, "UCheatManager.Fly"); }
	void Walk() { NativeCall<void>(this, "UCheatManager.Walk"); }
	void Ghost() { NativeCall<void>(this, "UCheatManager.Ghost"); }
	void God() { NativeCall<void>(this, "UCheatManager.God"); }
	void Slomo(float T) { NativeCall<void, float>(this, "UCheatManager.Slomo", T); }
	void DamageTarget(float DamageAmount) { NativeCall<void, float>(this, "UCheatManager.DamageTarget", DamageAmount); }
	void DestroyTarget() { NativeCall<void>(this, "UCheatManager.DestroyTarget"); }
	void DestroyAll(TSubclassOf<AActor> aClass) { NativeCall<void, TSubclassOf<AActor>>(this, "UCheatManager.DestroyAll", aClass); }
	void DestroyPawns(TSubclassOf<APawn> aClass) { NativeCall<void, TSubclassOf<APawn>>(this, "UCheatManager.DestroyPawns", aClass); }
	void Summon(FString * ClassName) { NativeCall<void, FString *>(this, "UCheatManager.Summon", ClassName); }
	void PlayersOnly() { NativeCall<void>(this, "UCheatManager.PlayersOnly"); }
	void ViewSelf() { NativeCall<void>(this, "UCheatManager.ViewSelf"); }
	void ViewPlayer(FString * S) { NativeCall<void, FString *>(this, "UCheatManager.ViewPlayer", S); }
	void ViewActor(FName ActorName) { NativeCall<void, FName>(this, "UCheatManager.ViewActor", ActorName); }
	void ViewClass(TSubclassOf<AActor> DesiredClass) { NativeCall<void, TSubclassOf<AActor>>(this, "UCheatManager.ViewClass", DesiredClass); }
	void SetLevelStreamingStatus(FName PackageName, bool bShouldBeLoaded, bool bShouldBeVisible) { NativeCall<void, FName, bool, bool>(this, "UCheatManager.SetLevelStreamingStatus", PackageName, bShouldBeLoaded, bShouldBeVisible); }
	void StreamLevelIn(FName PackageName) { NativeCall<void, FName>(this, "UCheatManager.StreamLevelIn", PackageName); }
	void OnlyLoadLevel(FName PackageName) { NativeCall<void, FName>(this, "UCheatManager.OnlyLoadLevel", PackageName); }
	void StreamLevelOut(FName PackageName) { NativeCall<void, FName>(this, "UCheatManager.StreamLevelOut", PackageName); }
	void ToggleDebugCamera() { NativeCall<void>(this, "UCheatManager.ToggleDebugCamera"); }
	void EnableDebugCamera() { NativeCall<void>(this, "UCheatManager.EnableDebugCamera"); }
	void DisableDebugCamera() { NativeCall<void>(this, "UCheatManager.DisableDebugCamera"); }
	void DebugCapsuleSweep() { NativeCall<void>(this, "UCheatManager.DebugCapsuleSweep"); }
	void DebugCapsuleSweepSize(float HalfHeight, float Radius) { NativeCall<void, float, float>(this, "UCheatManager.DebugCapsuleSweepSize", HalfHeight, Radius); }
	void DebugCapsuleSweepChannel(ECollisionChannel Channel) { NativeCall<void, ECollisionChannel>(this, "UCheatManager.DebugCapsuleSweepChannel", Channel); }
	void DebugCapsuleSweepComplex(bool bTraceComplex) { NativeCall<void, bool>(this, "UCheatManager.DebugCapsuleSweepComplex", bTraceComplex); }
	void DebugCapsuleSweepCapture() { NativeCall<void>(this, "UCheatManager.DebugCapsuleSweepCapture"); }
	void DebugCapsuleSweepPawn() { NativeCall<void>(this, "UCheatManager.DebugCapsuleSweepPawn"); }
	void DebugCapsuleSweepClear() { NativeCall<void>(this, "UCheatManager.DebugCapsuleSweepClear"); }
	void TestCollisionDistance() { NativeCall<void>(this, "UCheatManager.TestCollisionDistance"); }
	void WidgetReflector() { NativeCall<void>(this, "UCheatManager.WidgetReflector"); }
	void RebuildNavigation() { NativeCall<void>(this, "UCheatManager.RebuildNavigation"); }
	void DumpOnlineSessionState() { NativeCall<void>(this, "UCheatManager.DumpOnlineSessionState"); }
	void DumpVoiceMutingState() { NativeCall<void>(this, "UCheatManager.DumpVoiceMutingState"); }
	UWorld * GetWorld() { return NativeCall<UWorld *>(this, "UCheatManager.GetWorld"); }
	void BugItGo(float X, float Y, float Z, float Pitch, float Yaw, float Roll) { NativeCall<void, float, float, float, float, float, float>(this, "UCheatManager.BugItGo", X, Y, Z, Pitch, Yaw, Roll); }
	void BugItGoString(FString * TheLocation, FString * TheRotation) { NativeCall<void, FString *, FString *>(this, "UCheatManager.BugItGoString", TheLocation, TheRotation); }
	void BugItWorker(FVector TheLocation, FRotator TheRotation) { NativeCall<void, FVector, FRotator>(this, "UCheatManager.BugItWorker", TheLocation, TheRotation); }
	void BugIt(FString * ScreenShotDescription) { NativeCall<void, FString *>(this, "UCheatManager.BugIt", ScreenShotDescription); }
	void BugItStringCreator(FVector ViewLocation, FRotator ViewRotation, FString * GoString, FString * LocString) { NativeCall<void, FVector, FRotator, FString *, FString *>(this, "UCheatManager.BugItStringCreator", ViewLocation, ViewRotation, GoString, LocString); }
	void FlushLog() { NativeCall<void>(this, "UCheatManager.FlushLog"); }
	void LogLoc() { NativeCall<void>(this, "UCheatManager.LogLoc"); }
	void SetWorldOrigin() { NativeCall<void>(this, "UCheatManager.SetWorldOrigin"); }
	void ServerToggleAILogging() { NativeCall<void>(this, "UCheatManager.ServerToggleAILogging"); }
};

struct UShooterCheatManager : UCheatManager
{
	FieldValue<bool> bIsRCONCheatManagerField() { return { this, "UShooterCheatManager.bIsRCONCheatManager" }; }
	FieldValue<AShooterPlayerController *> MyPCField() { return { this, "UShooterCheatManager.MyPC" }; }

	// Functions

	void TakeAllStructure() { NativeCall<void>(this, "UShooterCheatManager.TakeAllStructure"); }
	void TakeAllDino() { NativeCall<void>(this, "UShooterCheatManager.TakeAllDino"); }
	void GMBuff() { NativeCall<void>(this, "UShooterCheatManager.GMBuff"); }
	void GMSummon(FString * ClassName, int Level) { NativeCall<void, FString *, int>(this, "UShooterCheatManager.GMSummon", ClassName, Level); }
	void AllowPlayerToJoinNoCheck(FString * SteamId) { NativeCall<void, FString *>(this, "UShooterCheatManager.AllowPlayerToJoinNoCheck", SteamId); }
	void RenameTribe(FString * TribeName, FString * NewName) { NativeCall<void, FString *, FString *>(this, "UShooterCheatManager.RenameTribe", TribeName, NewName); }
	void RenamePlayer(FString * PlayerName, FString * NewName) { NativeCall<void, FString *, FString *>(this, "UShooterCheatManager.RenamePlayer", PlayerName, NewName); }
	void DestroyActors(FString * ClassName) { NativeCall<void, FString *>(this, "UShooterCheatManager.DestroyActors", ClassName); }
	void StartSaveBackup() { NativeCall<void>(this, "UShooterCheatManager.StartSaveBackup"); }
	void DoExit() { NativeCall<void>(this, "UShooterCheatManager.DoExit"); }
	void OpenMap(FString * MapName) { NativeCall<void, FString *>(this, "UShooterCheatManager.OpenMap", MapName); }
	void DoRestartLevel() { NativeCall<void>(this, "UShooterCheatManager.DoRestartLevel"); }
	void SetGlobalPause(bool bIsPaused) { NativeCall<void, bool>(this, "UShooterCheatManager.SetGlobalPause", bIsPaused); }
	void DisallowPlayerToJoinNoCheck(FString * SteamId) { NativeCall<void, FString *>(this, "UShooterCheatManager.DisallowPlayerToJoinNoCheck", SteamId); }
	bool SetCreativeModeOnPawn(AShooterCharacter * Pawn, bool bCreativeMode) { return NativeCall<bool, AShooterCharacter *, bool>(this, "UShooterCheatManager.SetCreativeModeOnPawn", Pawn, bCreativeMode); }
	void GiveCreativeMode() { NativeCall<void>(this, "UShooterCheatManager.GiveCreativeMode"); }
	void GiveCreativeModeToTarget() { NativeCall<void>(this, "UShooterCheatManager.GiveCreativeModeToTarget"); }
	void GiveCreativeModeToPlayer(__int64 PlayerID) { NativeCall<void, __int64>(this, "UShooterCheatManager.GiveCreativeModeToPlayer", PlayerID); }
	void GiveExpToPlayer(__int64 PlayerID, float HowMuch, bool fromTribeShare, bool bPreventSharingWithTribe) { NativeCall<void, __int64, float, bool, bool>(this, "UShooterCheatManager.GiveExpToPlayer", PlayerID, HowMuch, fromTribeShare, bPreventSharingWithTribe); }
	void DestroyMyTarget() { NativeCall<void>(this, "UShooterCheatManager.DestroyMyTarget"); }
	void SetMyTargetSleeping(bool bIsSleeping) { NativeCall<void, bool>(this, "UShooterCheatManager.SetMyTargetSleeping", bIsSleeping); }
	void SetTargetDinoColor(int ColorRegion, int ColorID) { NativeCall<void, int, int>(this, "UShooterCheatManager.SetTargetDinoColor", ColorRegion, ColorID); }
	void Kill() { NativeCall<void>(this, "UShooterCheatManager.Kill"); }
	void KillPlayer(__int64 PlayerID) { NativeCall<void, __int64>(this, "UShooterCheatManager.KillPlayer", PlayerID); }
	void TeleportPlayerIDToMe(__int64 PlayerID) { NativeCall<void, __int64>(this, "UShooterCheatManager.TeleportPlayerIDToMe", PlayerID); }
	void TeleportPlayerNameToMe(FString * PlayerName) { NativeCall<void, FString *>(this, "UShooterCheatManager.TeleportPlayerNameToMe", PlayerName); }
	void TeleportToPlayer(__int64 PlayerID) { NativeCall<void, __int64>(this, "UShooterCheatManager.TeleportToPlayer", PlayerID); }
	void DestroyTribePlayers() { NativeCall<void>(this, "UShooterCheatManager.DestroyTribePlayers"); }
	void DestroyTribeDinos() { NativeCall<void>(this, "UShooterCheatManager.DestroyTribeDinos"); }
	void DestroyAllTames() { NativeCall<void>(this, "UShooterCheatManager.DestroyAllTames"); }
	void DestroyTribeStructures() { NativeCall<void>(this, "UShooterCheatManager.DestroyTribeStructures"); }
	void ForcePlayerToJoinTargetTribe(__int64 PlayerID) { NativeCall<void, __int64>(this, "UShooterCheatManager.ForcePlayerToJoinTargetTribe", PlayerID); }
	void ForcePlayerToJoinTribe(__int64 PlayerID, FString TribeName) { NativeCall<void, __int64, FString>(this, "UShooterCheatManager.ForcePlayerToJoinTribe", PlayerID, TribeName); }
	void SpawnActorTamed(FString * blueprintPath, float spawnDistance, float spawnYOffset, float ZOffset) { NativeCall<void, FString *, float, float, float>(this, "UShooterCheatManager.SpawnActorTamed", blueprintPath, spawnDistance, spawnYOffset, ZOffset); }
	AActor * DoSummon(FString * ClassName) { return NativeCall<AActor *, FString *>(this, "UShooterCheatManager.DoSummon", ClassName); }
	void Summon(FString * ClassName) { NativeCall<void, FString *>(this, "UShooterCheatManager.Summon", ClassName); }
	void SummonTamed(FString * ClassName) { NativeCall<void, FString *>(this, "UShooterCheatManager.SummonTamed", ClassName); }
	void SDF(FName * DinoBlueprintPath, bool bIsTamed) { NativeCall<void, FName *, bool>(this, "UShooterCheatManager.SDF", DinoBlueprintPath, bIsTamed); }
	void EnableCheats(FString pass) { NativeCall<void, FString>(this, "UShooterCheatManager.EnableCheats", pass); }
	void BanPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "UShooterCheatManager.BanPlayer", PlayerSteamName); }
	void UnbanPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "UShooterCheatManager.UnbanPlayer", PlayerSteamName); }
	void KickPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "UShooterCheatManager.KickPlayer", PlayerSteamName); }
	void Suicide() { NativeCall<void>(this, "UShooterCheatManager.Suicide"); }
	void ForceTame() { NativeCall<void>(this, "UShooterCheatManager.ForceTame"); }
	void SetImprintQuality(float ImprintQuality) { NativeCall<void, float>(this, "UShooterCheatManager.SetImprintQuality", ImprintQuality); }
	void DoTame() { NativeCall<void>(this, "UShooterCheatManager.DoTame"); }
	void GiveToMe() { NativeCall<void>(this, "UShooterCheatManager.GiveToMe"); }
	void GiveAllStructure() { NativeCall<void>(this, "UShooterCheatManager.GiveAllStructure"); }
	void SetTargetPlayerBodyVal(int BodyValIndex, float BodyVal) { NativeCall<void, int, float>(this, "UShooterCheatManager.SetTargetPlayerBodyVal", BodyValIndex, BodyVal); }
	void SetTargetPlayerColorVal(int ColorValIndex, float ColorVal) { NativeCall<void, int, float>(this, "UShooterCheatManager.SetTargetPlayerColorVal", ColorValIndex, ColorVal); }
	void SetBabyAge(float AgeValue) { NativeCall<void, float>(this, "UShooterCheatManager.SetBabyAge", AgeValue); }
	void ListPlayers() { NativeCall<void>(this, "UShooterCheatManager.ListPlayers"); }
	void EnemyInVisible(bool Invisible) { NativeCall<void, bool>(this, "UShooterCheatManager.EnemyInVisible", Invisible); }
	void AddItemToAllClustersInventory(FString UserId, int MasterIndexNum) { NativeCall<void, FString, int>(this, "UShooterCheatManager.AddItemToAllClustersInventory", UserId, MasterIndexNum); }
	void GiveItemToPlayer(int playerID, FString * blueprintPath, int quantityOverride, float qualityOverride, bool bForceBlueprint) { NativeCall<void, int, FString *, int, float, bool>(this, "UShooterCheatManager.GiveItemToPlayer", playerID, blueprintPath, quantityOverride, qualityOverride, bForceBlueprint); }
	void GiveItemNumToPlayer(int playerID, int masterIndexNum, int quantityOverride, float qualityOverride, bool bForceBlueprint) { NativeCall<void, int, int, int, float, bool>(this, "UShooterCheatManager.GiveItemNumToPlayer", playerID, masterIndexNum, quantityOverride, qualityOverride, bForceBlueprint); }
	void ClearPlayerInventory(int playerID, bool bClearInventory, bool bClearSlotItems, bool bClearEquippedItems) { NativeCall<void, int, bool, bool, bool>(this, "UShooterCheatManager.ClearPlayerInventory", playerID, bClearInventory, bClearSlotItems, bClearEquippedItems); }
	void DestroyAllEnemies() { NativeCall<void>(this, "UShooterCheatManager.DestroyAllEnemies"); }
	void DestroyWildDinos() { NativeCall<void>(this, "UShooterCheatManager.DestroyWildDinos"); }
	void DestroyStructures() { NativeCall<void>(this, "UShooterCheatManager.DestroyStructures"); }
	void PrintActorLocation(FString * ActorName) { NativeCall<void, FString *>(this, "UShooterCheatManager.PrintActorLocation", ActorName); }
	void TeleportToActorLocation(FString * ActorName) { NativeCall<void, FString *>(this, "UShooterCheatManager.TeleportToActorLocation", ActorName); }
	void TP(FString LocationName) { NativeCall<void, FString>(this, "UShooterCheatManager.TP", LocationName); }
	void ServerChat(FString * MessageText) { NativeCall<void, FString *>(this, "UShooterCheatManager.ServerChat", MessageText); }
	AShooterPlayerController * FindPlayerControllerFromPlayerID(__int64 PlayerID) { return NativeCall<AShooterPlayerController *, __int64>(this, "UShooterCheatManager.FindPlayerControllerFromPlayerID", PlayerID); }
	void GameCommand(FString * TheCommand) { NativeCall<void, FString *>(this, "UShooterCheatManager.GameCommand", TheCommand); }
	void ScriptCommand(FString * commandString) { NativeCall<void, FString *>(this, "UShooterCheatManager.ScriptCommand", commandString); }
	void RemoveTribeAdmin() { NativeCall<void>(this, "UShooterCheatManager.RemoveTribeAdmin"); }
	void MakeTribeFounder() { NativeCall<void>(this, "UShooterCheatManager.MakeTribeFounder"); }
	void VisualizeClass(FString * ClassIn, int MaxTotal) { NativeCall<void, FString *, int>(this, "UShooterCheatManager.VisualizeClass", ClassIn, MaxTotal); }
	void UnlockEngram(FString * ItemClassName) { NativeCall<void, FString *>(this, "UShooterCheatManager.UnlockEngram", ItemClassName); }
	void SetHeadHairPercent(float thePercent) { NativeCall<void, float>(this, "UShooterCheatManager.SetHeadHairPercent", thePercent); }
	void SetFacialHairPercent(float thePercent) { NativeCall<void, float>(this, "UShooterCheatManager.SetFacialHairPercent", thePercent); }
	void SetHeadHairstyle(int hairStyleIndex) { NativeCall<void, int>(this, "UShooterCheatManager.SetHeadHairstyle", hairStyleIndex); }
	void SetFacialHairstyle(int hairStyleIndex) { NativeCall<void, int>(this, "UShooterCheatManager.SetFacialHairstyle", hairStyleIndex); }
	void PrintMessageOut(FString * Msg) { NativeCall<void, FString *>(this, "UShooterCheatManager.PrintMessageOut", Msg); }
	void GetTribeIdPlayerList(int TribeID) { NativeCall<void, int>(this, "UShooterCheatManager.GetTribeIdPlayerList", TribeID); }
	void GetSteamIDForPlayerID(int PlayerID) { NativeCall<void, int>(this, "UShooterCheatManager.GetSteamIDForPlayerID", PlayerID); }
	void GetPlayerIDForSteamID(int SteamID) { NativeCall<void, int>(this, "UShooterCheatManager.GetPlayerIDForSteamID", SteamID); }
	void psc(FString * command) { NativeCall<void, FString *>(this, "UShooterCheatManager.psc", command); }
	UField * GetPrivateStaticClass() { return NativeCall<UField *>(this, "UShooterCheatManager.GetPrivateStaticClass"); }
};

struct UPlayer
{
	FieldValue<APlayerController *> PlayerControllerField() { return { this, "UPlayer.PlayerController" }; }
	FieldValue<int> CurrentNetSpeedField() { return { this, "UPlayer.CurrentNetSpeed" }; }
	FieldValue<int> ConfiguredInternetSpeedField() { return { this, "UPlayer.ConfiguredInternetSpeed" }; }
	FieldValue<int> ConfiguredLanSpeedField() { return { this, "UPlayer.ConfiguredLanSpeed" }; }
	FieldValue<unsigned __int64> TransferringPlayerDataIdField() { return { this, "UPlayer.TransferringPlayerDataId" }; }

	// Functions

	void SwitchController(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "UPlayer.SwitchController", PC); }
};

struct APlayerState : AActor
{
	FieldValue<float> ScoreField() { return { this, "APlayerState.Score" }; }
	FieldValue<char> PingField() { return { this, "APlayerState.Ping" }; }
	FieldValue<FString> PlayerNameField() { return { this, "APlayerState.PlayerName" }; }
	FieldValue<FString> OldNameField() { return { this, "APlayerState.OldName" }; }
	FieldValue<int> PlayerIdField() { return { this, "APlayerState.PlayerId" }; }
	FieldValue<int> StartTimeField() { return { this, "APlayerState.StartTime" }; }
	FieldValue<float> ExactPingField() { return { this, "APlayerState.ExactPing" }; }
	FieldValue<FString> SavedNetworkAddressField() { return { this, "APlayerState.SavedNetworkAddress" }; }
	FieldValue<FUniqueNetIdRepl> UniqueIdField() { return { this, "APlayerState.UniqueId" }; }
	FieldValue<FName> SessionNameField() { return { this, "APlayerState.SessionName" }; }
	FieldValue<char> CurPingBucketField() { return { this, "APlayerState.CurPingBucket" }; }
	FieldValue<float> CurPingBucketTimestampField() { return { this, "APlayerState.CurPingBucketTimestamp" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsSpectator() { return { this, "APlayerState.bIsSpectator" }; }
	BitFieldValue<bool, unsigned __int32> bOnlySpectator() { return { this, "APlayerState.bOnlySpectator" }; }
	BitFieldValue<bool, unsigned __int32> bIsABot() { return { this, "APlayerState.bIsABot" }; }
	BitFieldValue<bool, unsigned __int32> bHasBeenWelcomed() { return { this, "APlayerState.bHasBeenWelcomed" }; }
	BitFieldValue<bool, unsigned __int32> bIsInactive() { return { this, "APlayerState.bIsInactive" }; }
	BitFieldValue<bool, unsigned __int32> bFromPreviousLevel() { return { this, "APlayerState.bFromPreviousLevel" }; }

	// Functions

	void UpdatePing(float InPing) { NativeCall<void, float>(this, "APlayerState.UpdatePing", InPing); }
	void RecalculateAvgPing() { NativeCall<void>(this, "APlayerState.RecalculateAvgPing"); }
	void OverrideWith(APlayerState * PlayerState) { NativeCall<void, APlayerState *>(this, "APlayerState.OverrideWith", PlayerState); }
	void CopyProperties(APlayerState * PlayerState) { NativeCall<void, APlayerState *>(this, "APlayerState.CopyProperties", PlayerState); }
	void PostInitializeComponents() { NativeCall<void>(this, "APlayerState.PostInitializeComponents"); }
	void ClientInitialize(AController * C) { NativeCall<void, AController *>(this, "APlayerState.ClientInitialize", C); }
	void OnRep_PlayerName() { NativeCall<void>(this, "APlayerState.OnRep_PlayerName"); }
	void OnRep_bIsInactive() { NativeCall<void>(this, "APlayerState.OnRep_bIsInactive"); }
	bool ShouldBroadCastWelcomeMessage(bool bExiting) { return NativeCall<bool, bool>(this, "APlayerState.ShouldBroadCastWelcomeMessage", bExiting); }
	void Destroyed() { NativeCall<void>(this, "APlayerState.Destroyed"); }
	FString * GetHumanReadableName(FString * result) { return NativeCall<FString *, FString *>(this, "APlayerState.GetHumanReadableName", result); }
	void SetPlayerName(FString * S) { NativeCall<void, FString *>(this, "APlayerState.SetPlayerName", S); }
	void OnRep_UniqueId() { NativeCall<void>(this, "APlayerState.OnRep_UniqueId"); }
	void SetUniqueId(TSharedPtr<FUniqueNetId, 0> * InUniqueId) { NativeCall<void, TSharedPtr<FUniqueNetId, 0> *>(this, "APlayerState.SetUniqueId", InUniqueId); }
	void RegisterPlayerWithSession(bool bWasFromInvite) { NativeCall<void, bool>(this, "APlayerState.RegisterPlayerWithSession", bWasFromInvite); }
	void UnregisterPlayerWithSession() { NativeCall<void>(this, "APlayerState.UnregisterPlayerWithSession"); }
	APlayerState * Duplicate() { return NativeCall<APlayerState *>(this, "APlayerState.Duplicate"); }
	void SeamlessTravelTo(APlayerState * NewPlayerState) { NativeCall<void, APlayerState *>(this, "APlayerState.SeamlessTravelTo", NewPlayerState); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APlayerState.GetLifetimeReplicatedProps", OutLifetimeProps); }
	static void StaticRegisterNativesAPlayerState() { NativeCall<void>(nullptr, "APlayerState.StaticRegisterNativesAPlayerState"); }
};

struct AShooterPlayerState : APlayerState
{
	FieldValue<UPrimalPlayerData *> MyPlayerDataField() { return { this, "AShooterPlayerState.MyPlayerData" }; }
	FieldPointer<FPrimalPlayerDataStruct *> MyPlayerDataStructField() { return { this, "AShooterPlayerState.MyPlayerDataStruct" }; }
	FieldArray<TSubclassOf<UPrimalItem>, 10> DefaultItemSlotClassesField() { return { this, "AShooterPlayerState.DefaultItemSlotClasses" }; }
	FieldArray<char, 10> DefaultItemSlotEngramsField() { return { this, "AShooterPlayerState.DefaultItemSlotEngrams" }; }
	FieldPointer<FTribeData *> MyTribeDataField() { return { this, "AShooterPlayerState.MyTribeData" }; }
	FieldPointer<FTribeData *> LastTribeInviteDataField() { return { this, "AShooterPlayerState.LastTribeInviteData" }; }
	FieldValue<int> TotalEngramPointsField() { return { this, "AShooterPlayerState.TotalEngramPoints" }; }
	FieldValue<int> FreeEngramPointsField() { return { this, "AShooterPlayerState.FreeEngramPoints" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> EngramItemBlueprintsField() { return { this, "AShooterPlayerState.EngramItemBlueprints" }; }
	FieldValue<TSet<TSubclassOf<UPrimalItem>, DefaultKeyFuncs<TSubclassOf<UPrimalItem>, 0>, FDefaultSetAllocator>> ServerEngramItemBlueprintsSetField() { return { this, "AShooterPlayerState.ServerEngramItemBlueprintsSet" }; }
	FieldValue<long double> NextAllowedRespawnTimeField() { return { this, "AShooterPlayerState.NextAllowedRespawnTime" }; }
	FieldValue<float> AllowedRespawnIntervalField() { return { this, "AShooterPlayerState.AllowedRespawnInterval" }; }
	FieldValue<long double> LastTimeDiedToEnemyTeamField() { return { this, "AShooterPlayerState.LastTimeDiedToEnemyTeam" }; }
	FieldValue<int> CurrentlySelectedDinoOrderGroupField() { return { this, "AShooterPlayerState.CurrentlySelectedDinoOrderGroup" }; }
	FieldArray<FDinoOrderGroup, 10> DinoOrderGroupsField() { return { this, "AShooterPlayerState.DinoOrderGroups" }; }
	FieldValue<long double> LastTribeRequestTimeField() { return { this, "AShooterPlayerState.LastTribeRequestTime" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bQuitter() { return { this, "AShooterPlayerState.bQuitter" }; }

	// Functions

	void Reset() { NativeCall<void>(this, "AShooterPlayerState.Reset"); }
	void UnregisterPlayerWithSession() { NativeCall<void>(this, "AShooterPlayerState.UnregisterPlayerWithSession"); }
	void ClientInitialize(AController * InController) { NativeCall<void, AController *>(this, "AShooterPlayerState.ClientInitialize", InController); }
	void CopyProperties(APlayerState * PlayerState) { NativeCall<void, APlayerState *>(this, "AShooterPlayerState.CopyProperties", PlayerState); }
	void ServerGetAllPlayerNamesAndLocations_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetAllPlayerNamesAndLocations_Implementation"); }
	void ServerGetAlivePlayerConnectedData_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetAlivePlayerConnectedData_Implementation"); }
	void ServerGetPlayerConnectedData_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetPlayerConnectedData_Implementation"); }
	void ServerGetServerOptions_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetServerOptions_Implementation"); }
	void ServerGetPlayerBannedData_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetPlayerBannedData_Implementation"); }
	void ServerGetPlayerWhiteListedData_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerGetPlayerWhiteListedData_Implementation"); }
	void ClientGetServerOptions_Implementation(FServerOptions info) { NativeCall<void, FServerOptions>(this, "AShooterPlayerState.ClientGetServerOptions_Implementation", info); }
	void BroadcastDeath_Implementation(AShooterPlayerState * KillerPlayerState, UDamageType * KillerDamageType, AShooterPlayerState * KilledPlayerState) { NativeCall<void, AShooterPlayerState *, UDamageType *, AShooterPlayerState *>(this, "AShooterPlayerState.BroadcastDeath_Implementation", KillerPlayerState, KillerDamageType, KilledPlayerState); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AShooterPlayerState.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void Destroyed() { NativeCall<void>(this, "AShooterPlayerState.Destroyed"); }
	void BeginPlay() { NativeCall<void>(this, "AShooterPlayerState.BeginPlay"); }
	void PromoteToTribeAdmin(APlayerController * PromoterPC) { NativeCall<void, APlayerController *>(this, "AShooterPlayerState.PromoteToTribeAdmin", PromoterPC); }
	bool AddToTribe(FTribeData * MyNewTribe, bool bMergeTribe, bool bForce, bool bIsFromInvite, APlayerController * InviterPC) { return NativeCall<bool, FTribeData *, bool, bool, bool, APlayerController *>(this, "AShooterPlayerState.AddToTribe", MyNewTribe, bMergeTribe, bForce, bIsFromInvite, InviterPC); }
	void ClearTribe(bool bDontRemoveFromTribe, bool bForce, APlayerController * ForPC) { NativeCall<void, bool, bool, APlayerController *>(this, "AShooterPlayerState.ClearTribe", bDontRemoveFromTribe, bForce, ForPC); }
	void TransferTribalObjects(FTribeData * TribeData, bool bTransferToTribe, bool bDontIncludePlayers) { NativeCall<void, FTribeData *, bool, bool>(this, "AShooterPlayerState.TransferTribalObjects", TribeData, bTransferToTribe, bDontIncludePlayers); }
	bool IsTribeOwner(unsigned int CheckPlayerDataID) { return NativeCall<bool, unsigned int>(this, "AShooterPlayerState.IsTribeOwner", CheckPlayerDataID); }
	bool IsTribeAdmin() { return NativeCall<bool>(this, "AShooterPlayerState.IsTribeAdmin"); }
	void ServerRequestDinoOrderGroups_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerRequestDinoOrderGroups_Implementation"); }
	void ClientRefreshDinoOrderGroup_Implementation(int groupIndex, FDinoOrderGroup groupData, int UseCurrentlySelectedGroup) { NativeCall<void, int, FDinoOrderGroup, int>(this, "AShooterPlayerState.ClientRefreshDinoOrderGroup_Implementation", groupIndex, groupData, UseCurrentlySelectedGroup); }
	bool AllowDinoOrderByGroup(APrimalDinoCharacter * orderDino) { return NativeCall<bool, APrimalDinoCharacter *>(this, "AShooterPlayerState.AllowDinoOrderByGroup", orderDino); }
	void ServerDinoOrderGroup_AddOrRemoveDinoClass_Implementation(int groupIndex, TSubclassOf<APrimalDinoCharacter> DinoClass, bool bAdd) { NativeCall<void, int, TSubclassOf<APrimalDinoCharacter>, bool>(this, "AShooterPlayerState.ServerDinoOrderGroup_AddOrRemoveDinoClass_Implementation", groupIndex, DinoClass, bAdd); }
	void ServerSetDinoGroupName_Implementation(int groupIndex, FString * GroupName) { NativeCall<void, int, FString *>(this, "AShooterPlayerState.ServerSetDinoGroupName_Implementation", groupIndex, GroupName); }
	FString * GetDinoOrderGroupName(FString * result, int groupIndex) { return NativeCall<FString *, FString *, int>(this, "AShooterPlayerState.GetDinoOrderGroupName", result, groupIndex); }
	bool IsDinoInOrderGroup(int groupIndex, APrimalDinoCharacter * dinoChar) { return NativeCall<bool, int, APrimalDinoCharacter *>(this, "AShooterPlayerState.IsDinoInOrderGroup", groupIndex, dinoChar); }
	bool IsDinoClassInOrderGroup(int groupIndex, TSubclassOf<APrimalDinoCharacter> dinoClass) { return NativeCall<bool, int, TSubclassOf<APrimalDinoCharacter>>(this, "AShooterPlayerState.IsDinoClassInOrderGroup", groupIndex, dinoClass); }
	void ServerDinoOrderGroup_AddOrRemoveDinoCharacter_Implementation(int groupIndex, APrimalDinoCharacter * DinoCharacter, bool bAdd) { NativeCall<void, int, APrimalDinoCharacter *, bool>(this, "AShooterPlayerState.ServerDinoOrderGroup_AddOrRemoveDinoCharacter_Implementation", groupIndex, DinoCharacter, bAdd); }
	void ServerDinoOrderGroup_Clear_Implementation(int groupIndex, bool bClearClasses, bool bClearChars) { NativeCall<void, int, bool, bool>(this, "AShooterPlayerState.ServerDinoOrderGroup_Clear_Implementation", groupIndex, bClearClasses, bClearChars); }
	void ServerDinoOrderGroup_RemoveEntryByIndex_Implementation(int groupIndex, bool bIsClass, int entryIndex) { NativeCall<void, int, bool, int>(this, "AShooterPlayerState.ServerDinoOrderGroup_RemoveEntryByIndex_Implementation", groupIndex, bIsClass, entryIndex); }
	void ServerSetSelectedDinoOrderGroup_Implementation(int newGroup) { NativeCall<void, int>(this, "AShooterPlayerState.ServerSetSelectedDinoOrderGroup_Implementation", newGroup); }
	void ServerRequestRenameTribe_Implementation(FString * TribeName) { NativeCall<void, FString *>(this, "AShooterPlayerState.ServerRequestRenameTribe_Implementation", TribeName); }
	void ServerRequestSetTribeGovernment_Implementation(FTribeGovernment TribeGovernment) { NativeCall<void, FTribeGovernment>(this, "AShooterPlayerState.ServerRequestSetTribeGovernment_Implementation", TribeGovernment); }
	void ServerRequestCreateNewTribe_Implementation(FString * TribeName, FTribeGovernment TribeGovernment) { NativeCall<void, FString *, FTribeGovernment>(this, "AShooterPlayerState.ServerRequestCreateNewTribe_Implementation", TribeName, TribeGovernment); }
	void ServerRequestLeaveTribe_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ServerRequestLeaveTribe_Implementation"); }
	void ServerRequestRemovePlayerIndexFromMyTribe_Implementation(int PlayerIndexInTribe) { NativeCall<void, int>(this, "AShooterPlayerState.ServerRequestRemovePlayerIndexFromMyTribe_Implementation", PlayerIndexInTribe); }
	void ServerRequestPromotePlayerInMyTribe_Implementation(int PlayerIndexInTribe) { NativeCall<void, int>(this, "AShooterPlayerState.ServerRequestPromotePlayerInMyTribe_Implementation", PlayerIndexInTribe); }
	void ServerRequestDemotePlayerInMyTribe_Implementation(int PlayerIndexInTribe) { NativeCall<void, int>(this, "AShooterPlayerState.ServerRequestDemotePlayerInMyTribe_Implementation", PlayerIndexInTribe); }
	void InvitedRankGroupPlayerIntoTribe(AShooterPlayerState * OtherPlayer) { NativeCall<void, AShooterPlayerState *>(this, "AShooterPlayerState.InvitedRankGroupPlayerIntoTribe", OtherPlayer); }
	void ServerRequestSetTribeMemberGroupRank_Implementation(int PlayerIndexInTribe, int RankGroupIndex) { NativeCall<void, int, int>(this, "AShooterPlayerState.ServerRequestSetTribeMemberGroupRank_Implementation", PlayerIndexInTribe, RankGroupIndex); }
	void ServerTribeRequestAddRankGroup_Implementation(FString * GroupName) { NativeCall<void, FString *>(this, "AShooterPlayerState.ServerTribeRequestAddRankGroup_Implementation", GroupName); }
	void ServerTribeRequestRemoveRankGroup_Implementation(int RankGroupIndex) { NativeCall<void, int>(this, "AShooterPlayerState.ServerTribeRequestRemoveRankGroup_Implementation", RankGroupIndex); }
	void ServerTribeRequestApplyRankGroupSettings_Implementation(int RankGroupIndex, FTribeRankGroup newGroupSettings) { NativeCall<void, int, FTribeRankGroup>(this, "AShooterPlayerState.ServerTribeRequestApplyRankGroupSettings_Implementation", RankGroupIndex, newGroupSettings); }
	void ServerRequestTransferOwnershipInMyTribe_Implementation(int PlayerIndexInTribe) { NativeCall<void, int>(this, "AShooterPlayerState.ServerRequestTransferOwnershipInMyTribe_Implementation", PlayerIndexInTribe); }
	FString * GetPlayerName(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerState.GetPlayerName", result); }
	void ServerRequestMySpawnPoints_Implementation(int IgnoreBedID, TSubclassOf<APrimalStructure> FilterClass) { NativeCall<void, int, TSubclassOf<APrimalStructure>>(this, "AShooterPlayerState.ServerRequestMySpawnPoints_Implementation", IgnoreBedID, FilterClass); }
	void RequestCreateNewPlayerWithArkData(UPrimalPlayerData * PlayerArkData) { NativeCall<void, UPrimalPlayerData *>(this, "AShooterPlayerState.RequestCreateNewPlayerWithArkData", PlayerArkData); }
	void ServerRequestApplyEngramPoints_Implementation(TSubclassOf<UPrimalItem> forItemEntry) { NativeCall<void, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerState.ServerRequestApplyEngramPoints_Implementation", forItemEntry); }
	void ServerUnlockEngram(TSubclassOf<UPrimalItem> forItemEntry, bool bNotifyPlayerHUD, bool bForceUnlock) { NativeCall<void, TSubclassOf<UPrimalItem>, bool, bool>(this, "AShooterPlayerState.ServerUnlockEngram", forItemEntry, bNotifyPlayerHUD, bForceUnlock); }
	bool IsAlliedWith(int OtherTeam) { return NativeCall<bool, int>(this, "AShooterPlayerState.IsAlliedWith", OtherTeam); }
	void AddEngramBlueprintToPlayerInventory(UPrimalInventoryComponent * invComp, TSubclassOf<UPrimalItem> engramItemBlueprint) { NativeCall<void, UPrimalInventoryComponent *, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerState.AddEngramBlueprintToPlayerInventory", invComp, engramItemBlueprint); }
	UObject * GetObjectW() { return NativeCall<UObject *>(this, "AShooterPlayerState.GetObjectW"); }
	bool HasEngram(TSubclassOf<UPrimalItem> ItemClass) { return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerState.HasEngram", ItemClass); }
	void NotifyPlayerJoinedTribe_Implementation(FString * ThePlayerName, FString * TribeName) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerState.NotifyPlayerJoinedTribe_Implementation", ThePlayerName, TribeName); }
	void NotifyPlayerLeftTribe_Implementation(FString * ThePlayerName, FString * TribeName) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerState.NotifyPlayerLeftTribe_Implementation", ThePlayerName, TribeName); }
	void NotifyPlayerJoined_Implementation(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyPlayerJoined_Implementation", ThePlayerName); }
	void NotifyTribememberJoined_Implementation(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyTribememberJoined_Implementation", ThePlayerName); }
	void NotifyPlayerLeft_Implementation(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyPlayerLeft_Implementation", ThePlayerName); }
	void NotifyTribememberLeft_Implementation(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyTribememberLeft_Implementation", ThePlayerName); }
	void ServerSetDefaultItemSlotClass_Implementation(int slotNum, TSubclassOf<UPrimalItem> ItemClass, bool bIsEngram) { NativeCall<void, int, TSubclassOf<UPrimalItem>, bool>(this, "AShooterPlayerState.ServerSetDefaultItemSlotClass_Implementation", slotNum, ItemClass, bIsEngram); }
	void ClientNotifyLevelUpAvailable_Implementation() { NativeCall<void>(this, "AShooterPlayerState.ClientNotifyLevelUpAvailable_Implementation"); }
	int GetCharacterLevel() { return NativeCall<int>(this, "AShooterPlayerState.GetCharacterLevel"); }
	void SetTribeTamingDinoSettings(APrimalDinoCharacter * aDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterPlayerState.SetTribeTamingDinoSettings", aDinoChar); }
	void SendTribeInviteData_Implementation(FTribeData TribeInviteData) { NativeCall<void, FTribeData>(this, "AShooterPlayerState.SendTribeInviteData_Implementation", TribeInviteData); }
	void DoRespec(UPrimalPlayerData * ForPlayerData, AShooterCharacter * ForCharacter, bool bSetRespecedAtCharacterLevel) { NativeCall<void, UPrimalPlayerData *, AShooterCharacter *, bool>(this, "AShooterPlayerState.DoRespec", ForPlayerData, ForCharacter, bSetRespecedAtCharacterLevel); }
	FString * GetUniqueIdString(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerState.GetUniqueIdString", result); }
	void ServerDeclareTribeWar_Implementation(int EnemyTeamID, int StartDayNum, int EndDayNumber, float WarStartTime, float WarEndTime) { NativeCall<void, int, int, int, float, float>(this, "AShooterPlayerState.ServerDeclareTribeWar_Implementation", EnemyTeamID, StartDayNum, EndDayNumber, WarStartTime, WarEndTime); }
	void ServerAcceptTribeWar_Implementation(int EnemyTeamID) { NativeCall<void, int>(this, "AShooterPlayerState.ServerAcceptTribeWar_Implementation", EnemyTeamID); }
	void ServerRejectTribeWar_Implementation(int EnemyTeamID) { NativeCall<void, int>(this, "AShooterPlayerState.ServerRejectTribeWar_Implementation", EnemyTeamID); }
	FTribeWar * GetTribeWar(FTribeWar * result, int EnemyTeam) { return NativeCall<FTribeWar *, FTribeWar *, int>(this, "AShooterPlayerState.GetTribeWar", result, EnemyTeam); }
	void ServerRequestRemoveAllianceMember_Implementation(unsigned int AllianceID, unsigned int MemberID) { NativeCall<void, unsigned int, unsigned int>(this, "AShooterPlayerState.ServerRequestRemoveAllianceMember_Implementation", AllianceID, MemberID); }
	void ServerRequestPromoteAllianceMember_Implementation(unsigned int AllianceID, unsigned int MemberID) { NativeCall<void, unsigned int, unsigned int>(this, "AShooterPlayerState.ServerRequestPromoteAllianceMember_Implementation", AllianceID, MemberID); }
	void ServerTribeRequestNewAlliance_Implementation(FString * AllianceName) { NativeCall<void, FString *>(this, "AShooterPlayerState.ServerTribeRequestNewAlliance_Implementation", AllianceName); }
	void ServerRequestLeaveAlliance_Implementation(unsigned int AllianceID) { NativeCall<void, unsigned int>(this, "AShooterPlayerState.ServerRequestLeaveAlliance_Implementation", AllianceID); }
	void AcceptJoinAlliance(unsigned int AllianceID, unsigned int NewMemberID, FString NewMemberName) { NativeCall<void, unsigned int, unsigned int, FString>(this, "AShooterPlayerState.AcceptJoinAlliance", AllianceID, NewMemberID, NewMemberName); }
	bool AllowTribeGroupPermission(ETribeGroupPermission::Type TribeGroupPermission, UObject * OnObject) { return NativeCall<bool, ETribeGroupPermission::Type, UObject *>(this, "AShooterPlayerState.AllowTribeGroupPermission", TribeGroupPermission, OnObject); }
	void ServerRequestSpawnPointsForDownloadedCharacters_Implementation(unsigned __int64 PlayerDataID, int IgnoreBedID) { NativeCall<void, unsigned __int64, int>(this, "AShooterPlayerState.ServerRequestSpawnPointsForDownloadedCharacters_Implementation", PlayerDataID, IgnoreBedID); }
	void OnRep_UpdatedEngrams() { NativeCall<void>(this, "AShooterPlayerState.OnRep_UpdatedEngrams"); }
	static void StaticRegisterNativesAShooterPlayerState() { NativeCall<void>(nullptr, "AShooterPlayerState.StaticRegisterNativesAShooterPlayerState"); }
	UField * GetPrivateStaticClass() { return NativeCall<UField *>(this, "AShooterPlayerState.GetPrivateStaticClass"); }
	void ClientGetServerOptions(FServerOptions info) { NativeCall<void, FServerOptions>(this, "AShooterPlayerState.ClientGetServerOptions", info); }
	void ClientRefreshDinoOrderGroup(int groupIndex, FDinoOrderGroup groupData, int UseCurrentlySelectedGroup) { NativeCall<void, int, FDinoOrderGroup, int>(this, "AShooterPlayerState.ClientRefreshDinoOrderGroup", groupIndex, groupData, UseCurrentlySelectedGroup); }
	void NotifyPlayerJoined(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyPlayerJoined", ThePlayerName); }
	void NotifyPlayerJoinedTribe(FString * ThePlayerName, FString * TribeName) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerState.NotifyPlayerJoinedTribe", ThePlayerName, TribeName); }
	void NotifyPlayerLeft(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyPlayerLeft", ThePlayerName); }
	void NotifyPlayerLeftTribe(FString * ThePlayerName, FString * TribeName) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerState.NotifyPlayerLeftTribe", ThePlayerName, TribeName); }
	void NotifyTribememberJoined(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyTribememberJoined", ThePlayerName); }
	void NotifyTribememberLeft(FString * ThePlayerName) { NativeCall<void, FString *>(this, "AShooterPlayerState.NotifyTribememberLeft", ThePlayerName); }
	void SendTribeInviteData(FTribeData TribeInviteData) { NativeCall<void, FTribeData>(this, "AShooterPlayerState.SendTribeInviteData", TribeInviteData); }
	void ServerAcceptTribeWar(int EnemyTeamID) { NativeCall<void, int>(this, "AShooterPlayerState.ServerAcceptTribeWar", EnemyTeamID); }
	void ServerDinoOrderGroup_AddOrRemoveDinoCharacter(int groupIndex, APrimalDinoCharacter * DinoCharacter, bool bAdd) { NativeCall<void, int, APrimalDinoCharacter *, bool>(this, "AShooterPlayerState.ServerDinoOrderGroup_AddOrRemoveDinoCharacter", groupIndex, DinoCharacter, bAdd); }
	void ServerGetAllPlayerNamesAndLocations() { NativeCall<void>(this, "AShooterPlayerState.ServerGetAllPlayerNamesAndLocations"); }
	void ServerRequestApplyEngramPoints(TSubclassOf<UPrimalItem> forItemEntry) { NativeCall<void, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerState.ServerRequestApplyEngramPoints", forItemEntry); }
	void ServerRequestCreateNewTribe(FString * TribeName, FTribeGovernment TribeGovernment) { NativeCall<void, FString *, FTribeGovernment>(this, "AShooterPlayerState.ServerRequestCreateNewTribe", TribeName, TribeGovernment); }
	void ServerRequestLeaveTribe() { NativeCall<void>(this, "AShooterPlayerState.ServerRequestLeaveTribe"); }
	void ServerRequestRenameTribe(FString * ServerRequestRenameTribe) { NativeCall<void, FString *>(this, "AShooterPlayerState.ServerRequestRenameTribe", ServerRequestRenameTribe); }
	void ServerRequestSetTribeMemberGroupRank(int PlayerIndexInTribe, int RankGroupIndex) { NativeCall<void, int, int>(this, "AShooterPlayerState.ServerRequestSetTribeMemberGroupRank", PlayerIndexInTribe, RankGroupIndex); }
	void ServerRequestSpawnPointsForDownloadedCharacters(unsigned __int64 PlayerDataID, int IgnoreBedID) { NativeCall<void, unsigned __int64, int>(this, "AShooterPlayerState.ServerRequestSpawnPointsForDownloadedCharacters", PlayerDataID, IgnoreBedID); }
	void ServerSetDefaultItemSlotClass(int slotNum, TSubclassOf<UPrimalItem> ItemClass, bool bIsEngram) { NativeCall<void, int, TSubclassOf<UPrimalItem>, bool>(this, "AShooterPlayerState.ServerSetDefaultItemSlotClass", slotNum, ItemClass, bIsEngram); }
	void ServerSetDinoGroupName(int groupIndex, FString * GroupName) { NativeCall<void, int, FString *>(this, "AShooterPlayerState.ServerSetDinoGroupName", groupIndex, GroupName); }
	void ServerTribeRequestApplyRankGroupSettings(int RankGroupIndex, FTribeRankGroup newGroupSettings) { NativeCall<void, int, FTribeRankGroup>(this, "AShooterPlayerState.ServerTribeRequestApplyRankGroupSettings", RankGroupIndex, newGroupSettings); }
};

struct AController : AActor
{
	FieldValue<TWeakObjectPtr<APawn>> OldPawnField() { return { this, "AController.OldPawn" }; }
	FieldValue<ACharacter *> CharacterField() { return { this, "AController.Character" }; }
	FieldValue<APlayerState *> PlayerStateField() { return { this, "AController.PlayerState" }; }
	FieldValue<APawn *> PawnField() { return { this, "AController.Pawn" }; }
	FieldValue<FRotator> ControlRotationField() { return { this, "AController.ControlRotation" }; }
	FieldValue<TWeakObjectPtr<AActor>> StartSpotField() { return { this, "AController.StartSpot" }; }
	FieldValue<FName> StateNameField() { return { this, "AController.StateName" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bAttachToPawn() { return { this, "AController.bAttachToPawn" }; }

	// Functions

	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "AController.GetPrivateStaticClass"); }
	bool IsLocalController() { return NativeCall<bool>(this, "AController.IsLocalController"); }
	void FailedToSpawnPawn() { NativeCall<void>(this, "AController.FailedToSpawnPawn"); }
	void SetInitialLocationAndRotation(FVector * NewLocation, FRotator * NewRotation) { NativeCall<void, FVector *, FRotator *>(this, "AController.SetInitialLocationAndRotation", NewLocation, NewRotation); }
	FRotator * GetControlRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "AController.GetControlRotation", result); }
	void SetControlRotation(FRotator * NewRotation) { NativeCall<void, FRotator *>(this, "AController.SetControlRotation", NewRotation); }
	void AttachToPawn(APawn * InPawn) { NativeCall<void, APawn *>(this, "AController.AttachToPawn", InPawn); }
	void DetachFromPawn() { NativeCall<void>(this, "AController.DetachFromPawn"); }
	AActor * GetViewTarget() { return NativeCall<AActor *>(this, "AController.GetViewTarget"); }
	void GetPlayerViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "AController.GetPlayerViewPoint", out_Location, out_Rotation); }
	bool LineOfSightTo(AActor * Other, FVector ViewPoint, bool bAlternateChecks) { return NativeCall<bool, AActor *, FVector, bool>(this, "AController.LineOfSightTo", Other, ViewPoint, bAlternateChecks); }
	void PostInitializeComponents() { NativeCall<void>(this, "AController.PostInitializeComponents"); }
	void Possess(APawn * InPawn) { NativeCall<void, APawn *>(this, "AController.Possess", InPawn); }
	void PawnPendingDestroy(APawn * inPawn) { NativeCall<void, APawn *>(this, "AController.PawnPendingDestroy", inPawn); }
	void Reset() { NativeCall<void>(this, "AController.Reset"); }
	void ClientSetLocation_Implementation(FVector NewLocation, FRotator NewRotation) { NativeCall<void, FVector, FRotator>(this, "AController.ClientSetLocation_Implementation", NewLocation, NewRotation); }
	void ClientSetRotation_Implementation(FRotator NewRotation, bool bResetCamera) { NativeCall<void, FRotator, bool>(this, "AController.ClientSetRotation_Implementation", NewRotation, bResetCamera); }
	void RemovePawnTickDependency(APawn * InOldPawn) { NativeCall<void, APawn *>(this, "AController.RemovePawnTickDependency", InOldPawn); }
	void AddPawnTickDependency(APawn * NewPawn) { NativeCall<void, APawn *>(this, "AController.AddPawnTickDependency", NewPawn); }
	void SetPawn(APawn * InPawn) { NativeCall<void, APawn *>(this, "AController.SetPawn", InPawn); }
	void OnRep_Pawn() { NativeCall<void>(this, "AController.OnRep_Pawn"); }
	void OnRep_PlayerState() { NativeCall<void>(this, "AController.OnRep_PlayerState"); }
	void Destroyed() { NativeCall<void>(this, "AController.Destroyed"); }
	void CleanupPlayerState() { NativeCall<void>(this, "AController.CleanupPlayerState"); }
	void InstigatedAnyDamage(float Damage, UDamageType * DamageType, AActor * DamagedActor, AActor * DamageCauser) { NativeCall<void, float, UDamageType *, AActor *, AActor *>(this, "AController.InstigatedAnyDamage", Damage, DamageType, DamagedActor, DamageCauser); }
	void InitPlayerState() { NativeCall<void>(this, "AController.InitPlayerState"); }
	FRotator * GetDesiredRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "AController.GetDesiredRotation", result); }
	void GetActorEyesViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "AController.GetActorEyesViewPoint", out_Location, out_Rotation); }
	FString * GetHumanReadableName(FString * result) { return NativeCall<FString *, FString *>(this, "AController.GetHumanReadableName", result); }
	void ChangeState(FName NewState) { NativeCall<void, FName>(this, "AController.ChangeState", NewState); }
	FVector * GetNavAgentLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AController.GetNavAgentLocation", result); }
	void GetMoveGoalReachTest(AActor * MovingActor, FVector * MoveOffset, FVector * GoalOffset, float * GoalRadius, float * GoalHalfHeight) { NativeCall<void, AActor *, FVector *, FVector *, float *, float *>(this, "AController.GetMoveGoalReachTest", MovingActor, MoveOffset, GoalOffset, GoalRadius, GoalHalfHeight); }
	void UpdateNavigationComponents() { NativeCall<void>(this, "AController.UpdateNavigationComponents"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AController.GetLifetimeReplicatedProps", OutLifetimeProps); }
	static void StaticRegisterNativesAController() { NativeCall<void>(nullptr, "AController.StaticRegisterNativesAController"); }
	void ReceiveInstigatedAnyDamage(float Damage, UDamageType * DamageType, AActor * DamagedActor, AActor * DamageCauser) { NativeCall<void, float, UDamageType *, AActor *, AActor *>(this, "AController.ReceiveInstigatedAnyDamage", Damage, DamageType, DamagedActor, DamageCauser); }
};

struct APlayerController : AController
{
	FieldValue<UPlayer *> PlayerField() { return { this, "APlayerController.Player" }; }
	FieldValue<APawn *> AcknowledgedPawnField() { return { this, "APlayerController.AcknowledgedPawn" }; }
	FieldValue<float> LocalPlayerCachedLODDistanceFactorField() { return { this, "APlayerController.LocalPlayerCachedLODDistanceFactor" }; }
	FieldValue<AHUD *> MyHUDField() { return { this, "APlayerController.MyHUD" }; }
	FieldValue<APlayerCameraManager *> PlayerCameraManagerField() { return { this, "APlayerController.PlayerCameraManager" }; }
	FieldValue<TSubclassOf<APlayerCameraManager>> PlayerCameraManagerClassField() { return { this, "APlayerController.PlayerCameraManagerClass" }; }
	FieldValue<bool> bAutoManageActiveCameraTargetField() { return { this, "APlayerController.bAutoManageActiveCameraTarget" }; }
	FieldValue<FRotator> TargetViewRotationField() { return { this, "APlayerController.TargetViewRotation" }; }
	FieldValue<FRotator> BlendedTargetViewRotationField() { return { this, "APlayerController.BlendedTargetViewRotation" }; }
	FieldValue<TArray<AActor *>> HiddenActorsField() { return { this, "APlayerController.HiddenActors" }; }
	FieldValue<float> LastSpectatorStateSynchTimeField() { return { this, "APlayerController.LastSpectatorStateSynchTime" }; }
	FieldValue<int> ClientCapField() { return { this, "APlayerController.ClientCap" }; }
	FieldValue<long double> ServerLastReceivedSpectatorLocTimeField() { return { this, "APlayerController.ServerLastReceivedSpectatorLocTime" }; }
	FieldValue<UCheatManager *> CheatManagerField() { return { this, "APlayerController.CheatManager" }; }
	FieldValue<TSubclassOf<UCheatManager>> CheatClassField() { return { this, "APlayerController.CheatClass" }; }
	FieldValue<TArray<FName>> PendingMapChangeLevelNamesField() { return { this, "APlayerController.PendingMapChangeLevelNames" }; }
	FieldValue<char> NetPlayerIndexField() { return { this, "APlayerController.NetPlayerIndex" }; }
	FieldValue<UNetConnection *> PendingSwapConnectionField() { return { this, "APlayerController.PendingSwapConnection" }; }
	FieldValue<UNetConnection *> NetConnectionField() { return { this, "APlayerController.NetConnection" }; }
	FieldValue<FRotator> RotationInputField() { return { this, "APlayerController.RotationInput" }; }
	FieldValue<float> InputYawScaleField() { return { this, "APlayerController.InputYawScale" }; }
	FieldValue<float> InputPitchScaleField() { return { this, "APlayerController.InputPitchScale" }; }
	FieldValue<float> InputRollScaleField() { return { this, "APlayerController.InputRollScale" }; }
	FieldValue<TEnumAsByte<enum EMouseCursor::Type>> DefaultMouseCursorField() { return { this, "APlayerController.DefaultMouseCursor" }; }
	FieldValue<TEnumAsByte<enum EMouseCursor::Type>> CurrentMouseCursorField() { return { this, "APlayerController.CurrentMouseCursor" }; }
	FieldValue<TEnumAsByte<enum ECollisionChannel>> DefaultClickTraceChannelField() { return { this, "APlayerController.DefaultClickTraceChannel" }; }
	FieldValue<TEnumAsByte<enum ECollisionChannel>> CurrentClickTraceChannelField() { return { this, "APlayerController.CurrentClickTraceChannel" }; }
	FieldValue<bool> bLockedInputUIField() { return { this, "APlayerController.bLockedInputUI" }; }
	FieldValue<TSubobjectPtr<USceneComponent>> TransformComponentField() { return { this, "APlayerController.TransformComponent" }; }
	FieldValue<TWeakObjectPtr<UPrimitiveComponent>> CurrentClickablePrimitiveField() { return { this, "APlayerController.CurrentClickablePrimitive" }; }
	FieldArray<TWeakObjectPtr<UPrimitiveComponent>, 11> CurrentTouchablePrimitivesField() { return { this, "APlayerController.CurrentTouchablePrimitives" }; }
	FieldValue<char> IgnoreMoveInputField() { return { this, "APlayerController.IgnoreMoveInput" }; }
	FieldValue<char> IgnoreLookInputField() { return { this, "APlayerController.IgnoreLookInput" }; }
	FieldValue<TWeakObjectPtr<USceneComponent>> AudioListenerComponentField() { return { this, "APlayerController.AudioListenerComponent" }; }
	FieldValue<FVector> AudioListenerLocationOverrideField() { return { this, "APlayerController.AudioListenerLocationOverride" }; }
	FieldValue<FRotator> AudioListenerRotationOverrideField() { return { this, "APlayerController.AudioListenerRotationOverride" }; }
	FieldValue<FVector> SpawnLocationField() { return { this, "APlayerController.SpawnLocation" }; }
	FieldValue<float> LastRetryPlayerTimeField() { return { this, "APlayerController.LastRetryPlayerTime" }; }
	FieldValue<unsigned __int16> SeamlessTravelCountField() { return { this, "APlayerController.SeamlessTravelCount" }; }
	FieldValue<unsigned __int16> LastCompletedSeamlessTravelCountField() { return { this, "APlayerController.LastCompletedSeamlessTravelCount" }; }
	FieldValue<FVector> LastReplicatedFocalLocField() { return { this, "APlayerController.LastReplicatedFocalLoc" }; }
	FieldValue<bool> bIsDelayedNetCleanupField() { return { this, "APlayerController.bIsDelayedNetCleanup" }; }
	FieldValue<float> LastTeleportDistanceField() { return { this, "APlayerController.LastTeleportDistance" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bShortConnectTimeOut() { return { this, "APlayerController.bShortConnectTimeOut" }; }
	BitFieldValue<bool, unsigned __int32> bShowExtendedInfoKey() { return { this, "APlayerController.bShowExtendedInfoKey" }; }
	BitFieldValue<bool, unsigned __int32> bIsAnselActive() { return { this, "APlayerController.bIsAnselActive" }; }
	BitFieldValue<bool, unsigned __int32> bCinematicMode() { return { this, "APlayerController.bCinematicMode" }; }
	BitFieldValue<bool, unsigned __int32> bIsUsingStreamingVolumes() { return { this, "APlayerController.bIsUsingStreamingVolumes" }; }
	BitFieldValue<bool, unsigned __int32> bPlayerIsWaiting() { return { this, "APlayerController.bPlayerIsWaiting" }; }
	BitFieldValue<bool, unsigned __int32> bCheatPlayer() { return { this, "APlayerController.bCheatPlayer" }; }
	BitFieldValue<bool, unsigned __int32> bIsAdmin() { return { this, "APlayerController.bIsAdmin" }; }
	BitFieldValue<bool, unsigned __int32> bShowMouseCursor() { return { this, "APlayerController.bShowMouseCursor" }; }
	BitFieldValue<bool, unsigned __int32> bEnableClickEvents() { return { this, "APlayerController.bEnableClickEvents" }; }
	BitFieldValue<bool, unsigned __int32> bEnableTouchEvents() { return { this, "APlayerController.bEnableTouchEvents" }; }
	BitFieldValue<bool, unsigned __int32> bEnableMouseOverEvents() { return { this, "APlayerController.bEnableMouseOverEvents" }; }
	BitFieldValue<bool, unsigned __int32> bEnableTouchOverEvents() { return { this, "APlayerController.bEnableTouchOverEvents" }; }
	BitFieldValue<bool, unsigned __int32> bForceFeedbackEnabled() { return { this, "APlayerController.bForceFeedbackEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bCinemaDisableInputMove() { return { this, "APlayerController.bCinemaDisableInputMove" }; }
	BitFieldValue<bool, unsigned __int32> bCinemaDisableInputLook() { return { this, "APlayerController.bCinemaDisableInputLook" }; }
	BitFieldValue<bool, unsigned __int32> bAcknowledgedClientReceivedActor() { return { this, "APlayerController.bAcknowledgedClientReceivedActor" }; }
	BitFieldValue<bool, unsigned __int32> bInputEnabled() { return { this, "APlayerController.bInputEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bShouldPerformFullTickWhenPaused() { return { this, "APlayerController.bShouldPerformFullTickWhenPaused" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideAudioListener() { return { this, "APlayerController.bOverrideAudioListener" }; }

	// Functions

	AActor * GetAimedUseActor(UActorComponent ** UseComponent, int * hitBodyIndex) { return NativeCall<AActor *, UActorComponent **, int *>(this, "APlayerController.GetAimedUseActor", UseComponent, hitBodyIndex); }
	AActor * BaseGetPlayerCharacter() { return NativeCall<AActor *>(this, "APlayerController.BaseGetPlayerCharacter"); }
	static UClass * StaticClass() { return NativeCall<UClass *>(nullptr, "APlayerController.StaticClass"); }
	UPlayer * GetNetOwningPlayer() { return NativeCall<UPlayer *>(this, "APlayerController.GetNetOwningPlayer"); }
	UNetConnection * GetNetConnection() { return NativeCall<UNetConnection *>(this, "APlayerController.GetNetConnection"); }
	bool IsLocalController() { return NativeCall<bool>(this, "APlayerController.IsLocalController"); }
	bool ServerPause_Validate() { return NativeCall<bool>(this, "APlayerController.ServerPause_Validate"); }
	void FailedToSpawnPawn() { NativeCall<void>(this, "APlayerController.FailedToSpawnPawn"); }
	void ClientFlushLevelStreaming_Implementation() { NativeCall<void>(this, "APlayerController.ClientFlushLevelStreaming_Implementation"); }
	void ServerUpdateLevelVisibility_Implementation(FName PackageName, bool bIsVisible) { NativeCall<void, FName, bool>(this, "APlayerController.ServerUpdateLevelVisibility_Implementation", PackageName, bIsVisible); }
	bool ServerUpdateLevelVisibility_Validate(FName PackageName, bool bIsVisible) { return NativeCall<bool, FName, bool>(this, "APlayerController.ServerUpdateLevelVisibility_Validate", PackageName, bIsVisible); }
	FString * ConsoleCommand(FString * result, FString * Cmd, bool bWriteToLog) { return NativeCall<FString *, FString *, FString *, bool>(this, "APlayerController.ConsoleCommand", result, Cmd, bWriteToLog); }
	void CleanUpAudioComponents() { NativeCall<void>(this, "APlayerController.CleanUpAudioComponents"); }
	AActor * GetViewTarget() { return NativeCall<AActor *>(this, "APlayerController.GetViewTarget"); }
	void AutoManageActiveCameraTarget(AActor * SuggestedTarget) { NativeCall<void, AActor *>(this, "APlayerController.AutoManageActiveCameraTarget", SuggestedTarget); }
	void ServerNotifyLoadedWorld_Implementation(FName WorldPackageName) { NativeCall<void, FName>(this, "APlayerController.ServerNotifyLoadedWorld_Implementation", WorldPackageName); }
	bool HasClientLoadedCurrentWorld() { return NativeCall<bool>(this, "APlayerController.HasClientLoadedCurrentWorld"); }
	void ForceSingleNetUpdateFor(AActor * Target) { NativeCall<void, AActor *>(this, "APlayerController.ForceSingleNetUpdateFor", Target); }
	void SmoothTargetViewRotation(APawn * TargetPawn, float DeltaSeconds) { NativeCall<void, APawn *, float>(this, "APlayerController.SmoothTargetViewRotation", TargetPawn, DeltaSeconds); }
	void InitInputSystem() { NativeCall<void>(this, "APlayerController.InitInputSystem"); }
	void SafeRetryClientRestart() { NativeCall<void>(this, "APlayerController.SafeRetryClientRestart"); }
	void ClientRetryClientRestart_Implementation(APawn * NewPawn) { NativeCall<void, APawn *>(this, "APlayerController.ClientRetryClientRestart_Implementation", NewPawn); }
	void ClientRestart_Implementation(APawn * NewPawn) { NativeCall<void, APawn *>(this, "APlayerController.ClientRestart_Implementation", NewPawn); }
	void Possess(APawn * PawnToPossess) { NativeCall<void, APawn *>(this, "APlayerController.Possess", PawnToPossess); }
	void AcknowledgePossession(APawn * P) { NativeCall<void, APawn *>(this, "APlayerController.AcknowledgePossession", P); }
	void ReceivedPlayer() { NativeCall<void>(this, "APlayerController.ReceivedPlayer"); }
	FVector * GetFocalLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APlayerController.GetFocalLocation", result); }
	void PostLoad() { NativeCall<void>(this, "APlayerController.PostLoad"); }
	void GetActorEyesViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "APlayerController.GetActorEyesViewPoint", out_Location, out_Rotation); }
	void CalcCamera(float DeltaTime, FMinimalViewInfo * OutResult) { NativeCall<void, float, FMinimalViewInfo *>(this, "APlayerController.CalcCamera", DeltaTime, OutResult); }
	void GetPlayerViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "APlayerController.GetPlayerViewPoint", out_Location, out_Rotation); }
	void UpdateRotation(float DeltaTime) { NativeCall<void, float>(this, "APlayerController.UpdateRotation", DeltaTime); }
	void PostInitializeComponents() { NativeCall<void>(this, "APlayerController.PostInitializeComponents"); }
	void AddCheats(bool bForce) { NativeCall<void, bool>(this, "APlayerController.AddCheats", bForce); }
	void EnableCheats(FString pass) { NativeCall<void, FString>(this, "APlayerController.EnableCheats", pass); }
	void SpawnDefaultHUD() { NativeCall<void>(this, "APlayerController.SpawnDefaultHUD"); }
	void CreateTouchInterface() { NativeCall<void>(this, "APlayerController.CreateTouchInterface"); }
	void CleanupGameViewport() { NativeCall<void>(this, "APlayerController.CleanupGameViewport"); }
	void GetViewportSize(int * SizeX, int * SizeY) { NativeCall<void, int *, int *>(this, "APlayerController.GetViewportSize", SizeX, SizeY); }
	void Reset() { NativeCall<void>(this, "APlayerController.Reset"); }
	void ClientReset_Implementation() { NativeCall<void>(this, "APlayerController.ClientReset_Implementation"); }
	void ClientGotoState_Implementation(FName NewState) { NativeCall<void, FName>(this, "APlayerController.ClientGotoState_Implementation", NewState); }
	bool IsFrozen() { return NativeCall<bool>(this, "APlayerController.IsFrozen"); }
	void ServerAcknowledgePossession_Implementation(APawn * P) { NativeCall<void, APawn *>(this, "APlayerController.ServerAcknowledgePossession_Implementation", P); }
	bool ServerAcknowledgePossession_Validate(APawn * P) { return NativeCall<bool, APawn *>(this, "APlayerController.ServerAcknowledgePossession_Validate", P); }
	void UnPossess() { NativeCall<void>(this, "APlayerController.UnPossess"); }
	void ClientSetHUD_Implementation(TSubclassOf<AHUD> NewHUDClass) { NativeCall<void, TSubclassOf<AHUD>>(this, "APlayerController.ClientSetHUD_Implementation", NewHUDClass); }
	void CleanupPlayerState() { NativeCall<void>(this, "APlayerController.CleanupPlayerState"); }
	void OnNetCleanup(UNetConnection * Connection) { NativeCall<void, UNetConnection *>(this, "APlayerController.OnNetCleanup", Connection); }
	void DelayedNetCleanup() { NativeCall<void>(this, "APlayerController.DelayedNetCleanup"); }
	void ClientPlaySound_Implementation(USoundBase * Sound, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, USoundBase *, float, float>(this, "APlayerController.ClientPlaySound_Implementation", Sound, VolumeMultiplier, PitchMultiplier); }
	void ClientPlaySoundAtLocation_Implementation(USoundBase * Sound, FVector Location, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, USoundBase *, FVector, float, float>(this, "APlayerController.ClientPlaySoundAtLocation_Implementation", Sound, Location, VolumeMultiplier, PitchMultiplier); }
	void ClientMessage_Implementation(FString * S, FName Type, float MsgLifeTime) { NativeCall<void, FString *, FName, float>(this, "APlayerController.ClientMessage_Implementation", S, Type, MsgLifeTime); }
	void ClientTeamMessage_Implementation(APlayerState * SenderPlayerState, FString * S, FName Type, float MsgLifeTime) { NativeCall<void, APlayerState *, FString *, FName, float>(this, "APlayerController.ClientTeamMessage_Implementation", SenderPlayerState, S, Type, MsgLifeTime); }
	void ServerToggleAILogging_Implementation() { NativeCall<void>(this, "APlayerController.ServerToggleAILogging_Implementation"); }
	void PawnLeavingGame() { NativeCall<void>(this, "APlayerController.PawnLeavingGame"); }
	void EndPlay(EEndPlayReason::Type EndPlayReason) { NativeCall<void, EEndPlayReason::Type>(this, "APlayerController.EndPlay", EndPlayReason); }
	void Destroyed() { NativeCall<void>(this, "APlayerController.Destroyed"); }
	void FOV(float F) { NativeCall<void, float>(this, "APlayerController.FOV", F); }
	void Camera(FName NewMode) { NativeCall<void, FName>(this, "APlayerController.Camera", NewMode); }
	void ServerCamera_Implementation(FName NewMode) { NativeCall<void, FName>(this, "APlayerController.ServerCamera_Implementation", NewMode); }
	bool ServerCamera_Validate(FName NewMode) { return NativeCall<bool, FName>(this, "APlayerController.ServerCamera_Validate", NewMode); }
	void SetCameraMode(FName NewCamMode) { NativeCall<void, FName>(this, "APlayerController.SetCameraMode", NewCamMode); }
	void ResetCameraMode() { NativeCall<void>(this, "APlayerController.ResetCameraMode"); }
	void ClientSetCameraFade_Implementation(bool bEnableFading, FColor FadeColor, FVector2D FadeAlpha, float FadeTime, bool bFadeAudio) { NativeCall<void, bool, FColor, FVector2D, float, bool>(this, "APlayerController.ClientSetCameraFade_Implementation", bEnableFading, FadeColor, FadeAlpha, FadeTime, bFadeAudio); }
	void SendClientAdjustment() { NativeCall<void>(this, "APlayerController.SendClientAdjustment"); }
	void ClientCapBandwidth_Implementation(int Cap) { NativeCall<void, int>(this, "APlayerController.ClientCapBandwidth_Implementation", Cap); }
	void SetSpawnLocation(FVector * NewLocation) { NativeCall<void, FVector *>(this, "APlayerController.SetSpawnLocation", NewLocation); }
	void SetInitialLocationAndRotation(FVector * NewLocation, FRotator * NewRotation) { NativeCall<void, FVector *, FRotator *>(this, "APlayerController.SetInitialLocationAndRotation", NewLocation, NewRotation); }
	void ServerUpdateCamera_Implementation(FVector_NetQuantize CamLoc, int CamPitchAndYaw) { NativeCall<void, FVector_NetQuantize, int>(this, "APlayerController.ServerUpdateCamera_Implementation", CamLoc, CamPitchAndYaw); }
	void RestartLevel() { NativeCall<void>(this, "APlayerController.RestartLevel"); }
	void LocalTravel(FString * FURL) { NativeCall<void, FString *>(this, "APlayerController.LocalTravel", FURL); }
	void ClientReturnToMainMenu_Implementation(FString * ReturnReason) { NativeCall<void, FString *>(this, "APlayerController.ClientReturnToMainMenu_Implementation", ReturnReason); }
	void Pause() { NativeCall<void>(this, "APlayerController.Pause"); }
	void ServerPause_Implementation() { NativeCall<void>(this, "APlayerController.ServerPause_Implementation"); }
	void SetName(FString * S) { NativeCall<void, FString *>(this, "APlayerController.SetName", S); }
	void ServerChangeName_Implementation(FString * S) { NativeCall<void, FString *>(this, "APlayerController.ServerChangeName_Implementation", S); }
	bool ServerChangeName_Validate(FString * S) { return NativeCall<bool, FString *>(this, "APlayerController.ServerChangeName_Validate", S); }
	void SwitchLevel(FString * FURL) { NativeCall<void, FString *>(this, "APlayerController.SwitchLevel", FURL); }
	void NotifyLoadedWorld(FName WorldPackageName, bool bFinalDest) { NativeCall<void, FName, bool>(this, "APlayerController.NotifyLoadedWorld", WorldPackageName, bFinalDest); }
	void GameHasEnded(AActor * EndGameFocus, bool bIsWinner) { NativeCall<void, AActor *, bool>(this, "APlayerController.GameHasEnded", EndGameFocus, bIsWinner); }
	void ClientGameEnded_Implementation(AActor * EndGameFocus, bool bIsWinner) { NativeCall<void, AActor *, bool>(this, "APlayerController.ClientGameEnded_Implementation", EndGameFocus, bIsWinner); }
	bool GetHitResultUnderCursor(ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, ECollisionChannel, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderCursor", TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultUnderCursorByChannel(ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, ETraceTypeQuery, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderCursorByChannel", TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultUnderCursorForObjects(TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderCursorForObjects", ObjectTypes, bTraceComplex, HitResult); }
	bool GetHitResultUnderFinger(ETouchIndex::Type FingerIndex, ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, ETouchIndex::Type, ECollisionChannel, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderFinger", FingerIndex, TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultUnderFingerByChannel(ETouchIndex::Type FingerIndex, ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, ETouchIndex::Type, ETraceTypeQuery, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderFingerByChannel", FingerIndex, TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultUnderFingerForObjects(ETouchIndex::Type FingerIndex, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, ETouchIndex::Type, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, FHitResult *>(this, "APlayerController.GetHitResultUnderFingerForObjects", FingerIndex, ObjectTypes, bTraceComplex, HitResult); }
	bool DeprojectMousePositionToWorld(FVector * WorldLocation, FVector * WorldDirection) { return NativeCall<bool, FVector *, FVector *>(this, "APlayerController.DeprojectMousePositionToWorld", WorldLocation, WorldDirection); }
	bool DeprojectScreenPositionToWorld(float ScreenX, float ScreenY, FVector * WorldLocation, FVector * WorldDirection) { return NativeCall<bool, float, float, FVector *, FVector *>(this, "APlayerController.DeprojectScreenPositionToWorld", ScreenX, ScreenY, WorldLocation, WorldDirection); }
	bool ProjectWorldLocationToScreen(FVector WorldLocation, FVector2D * ScreenLocation) { return NativeCall<bool, FVector, FVector2D *>(this, "APlayerController.ProjectWorldLocationToScreen", WorldLocation, ScreenLocation); }
	bool GetHitResultAtScreenPosition(FVector2D ScreenPosition, ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, FVector2D, ECollisionChannel, bool, FHitResult *>(this, "APlayerController.GetHitResultAtScreenPosition", ScreenPosition, TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultAtScreenPosition(FVector2D ScreenPosition, ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, FVector2D, ETraceTypeQuery, bool, FHitResult *>(this, "APlayerController.GetHitResultAtScreenPosition", ScreenPosition, TraceChannel, bTraceComplex, HitResult); }
	bool GetHitResultAtScreenPosition(FVector2D ScreenPosition, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, FHitResult * HitResult) { return NativeCall<bool, FVector2D, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, FHitResult *>(this, "APlayerController.GetHitResultAtScreenPosition", ScreenPosition, ObjectTypes, bTraceComplex, HitResult); }
	void PlayerTick(float DeltaTime) { NativeCall<void, float>(this, "APlayerController.PlayerTick", DeltaTime); }
	void FlushPressedKeys() { NativeCall<void>(this, "APlayerController.FlushPressedKeys"); }
	bool InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad) { return NativeCall<bool, FKey, EInputEvent, float, bool>(this, "APlayerController.InputKey", Key, EventType, AmountDepressed, bGamepad); }
	bool InputAxis(FKey Key, float Delta, float DeltaTime, int NumSamples, bool bGamepad) { return NativeCall<bool, FKey, float, float, int, bool>(this, "APlayerController.InputAxis", Key, Delta, DeltaTime, NumSamples, bGamepad); }
	bool InputTouch(unsigned int Handle, ETouchType::Type Type, FVector2D * TouchLocation, FDateTime DeviceTimestamp, unsigned int TouchpadIndex) { return NativeCall<bool, unsigned int, ETouchType::Type, FVector2D *, FDateTime, unsigned int>(this, "APlayerController.InputTouch", Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex); }
	bool InputMotion(FVector * Tilt, FVector * RotationRate, FVector * Gravity, FVector * Acceleration) { return NativeCall<bool, FVector *, FVector *, FVector *, FVector *>(this, "APlayerController.InputMotion", Tilt, RotationRate, Gravity, Acceleration); }
	bool ShouldShowMouseCursor() { return NativeCall<bool>(this, "APlayerController.ShouldShowMouseCursor"); }
	EMouseCursor::Type GetMouseCursor() { return NativeCall<EMouseCursor::Type>(this, "APlayerController.GetMouseCursor"); }
	void SetupInputComponent() { NativeCall<void>(this, "APlayerController.SetupInputComponent"); }
	void ProcessPlayerInput(const float DeltaTime, const bool bGamePaused) { NativeCall<void, const float, const bool>(this, "APlayerController.ProcessPlayerInput", DeltaTime, bGamePaused); }
	void PostProcessInput(const float DeltaTime, const bool bGamePaused) { NativeCall<void, const float, const bool>(this, "APlayerController.PostProcessInput", DeltaTime, bGamePaused); }
	void ResetIgnoreInputFlags() { NativeCall<void>(this, "APlayerController.ResetIgnoreInputFlags"); }
	void SetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning) { NativeCall<void, bool, bool, bool>(this, "APlayerController.SetCinematicMode", bInCinematicMode, bAffectsMovement, bAffectsTurning); }
	void SetIgnoreMoveInput(bool bNewMoveInput) { NativeCall<void, bool>(this, "APlayerController.SetIgnoreMoveInput", bNewMoveInput); }
	bool IsMoveInputIgnored() { return NativeCall<bool>(this, "APlayerController.IsMoveInputIgnored"); }
	void SetIgnoreLookInput(bool bNewLookInput) { NativeCall<void, bool>(this, "APlayerController.SetIgnoreLookInput", bNewLookInput); }
	bool IsLookInputIgnored() { return NativeCall<bool>(this, "APlayerController.IsLookInputIgnored"); }
	void ServerVerifyViewTarget_Implementation() { NativeCall<void>(this, "APlayerController.ServerVerifyViewTarget_Implementation"); }
	void SpawnPlayerCameraManager() { NativeCall<void>(this, "APlayerController.SpawnPlayerCameraManager"); }
	void GetAudioListenerPosition(FVector * OutLocation, FVector * OutFrontDir, FVector * OutRightDir) { NativeCall<void, FVector *, FVector *, FVector *>(this, "APlayerController.GetAudioListenerPosition", OutLocation, OutFrontDir, OutRightDir); }
	void ServerCheckClientPossession_Implementation() { NativeCall<void>(this, "APlayerController.ServerCheckClientPossession_Implementation"); }
	void SafeServerCheckClientPossession() { NativeCall<void>(this, "APlayerController.SafeServerCheckClientPossession"); }
	void SafeServerUpdateSpectatorState() { NativeCall<void>(this, "APlayerController.SafeServerUpdateSpectatorState"); }
	void ServerSetSpectatorLocation_Implementation(FVector NewLoc) { NativeCall<void, FVector>(this, "APlayerController.ServerSetSpectatorLocation_Implementation", NewLoc); }
	void ServerViewNextPlayer_Implementation() { NativeCall<void>(this, "APlayerController.ServerViewNextPlayer_Implementation"); }
	void ServerViewPrevPlayer_Implementation() { NativeCall<void>(this, "APlayerController.ServerViewPrevPlayer_Implementation"); }
	APlayerState * GetNextViewablePlayer(int dir) { return NativeCall<APlayerState *, int>(this, "APlayerController.GetNextViewablePlayer", dir); }
	void ViewAPlayer(int dir) { NativeCall<void, int>(this, "APlayerController.ViewAPlayer", dir); }
	void StartFire(char FireModeNum) { NativeCall<void, char>(this, "APlayerController.StartFire", FireModeNum); }
	bool NotifyServerReceivedClientData(APawn * InPawn, float TimeStamp) { return NativeCall<bool, APawn *, float>(this, "APlayerController.NotifyServerReceivedClientData", InPawn, TimeStamp); }
	void ServerRestartPlayer_Implementation() { NativeCall<void>(this, "APlayerController.ServerRestartPlayer_Implementation"); }
	bool CanRestartPlayer() { return NativeCall<bool>(this, "APlayerController.CanRestartPlayer"); }
	void ClientIgnoreMoveInput_Implementation(bool bIgnore) { NativeCall<void, bool>(this, "APlayerController.ClientIgnoreMoveInput_Implementation", bIgnore); }
	void ClientIgnoreLookInput_Implementation(bool bIgnore) { NativeCall<void, bool>(this, "APlayerController.ClientIgnoreLookInput_Implementation", bIgnore); }
	void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning) { NativeCall<void, bool, bool, bool, bool, bool>(this, "APlayerController.SetCinematicMode", bInCinematicMode, bHidePlayer, bAffectsHUD, bAffectsMovement, bAffectsTurning); }
	void ClientSetCinematicMode_Implementation(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD) { NativeCall<void, bool, bool, bool, bool>(this, "APlayerController.ClientSetCinematicMode_Implementation", bInCinematicMode, bAffectsMovement, bAffectsTurning, bAffectsHUD); }
	void ClientForceGarbageCollection_Implementation() { NativeCall<void>(this, "APlayerController.ClientForceGarbageCollection_Implementation"); }
	void ClientPrepareMapChange_Implementation(FName LevelName, bool bFirst, bool bLast) { NativeCall<void, FName, bool, bool>(this, "APlayerController.ClientPrepareMapChange_Implementation", LevelName, bFirst, bLast); }
	void DelayedPrepareMapChange() { NativeCall<void>(this, "APlayerController.DelayedPrepareMapChange"); }
	void ClientCommitMapChange_Implementation() { NativeCall<void>(this, "APlayerController.ClientCommitMapChange_Implementation"); }
	void ClientCancelPendingMapChange_Implementation() { NativeCall<void>(this, "APlayerController.ClientCancelPendingMapChange_Implementation"); }
	void ClientSetBlockOnAsyncLoading_Implementation() { NativeCall<void>(this, "APlayerController.ClientSetBlockOnAsyncLoading_Implementation"); }
	void GetSeamlessTravelActorList(bool bToEntry, TArray<AActor *> * ActorList) { NativeCall<void, bool, TArray<AActor *> *>(this, "APlayerController.GetSeamlessTravelActorList", bToEntry, ActorList); }
	void SeamlessTravelFrom(APlayerController * OldPC) { NativeCall<void, APlayerController *>(this, "APlayerController.SeamlessTravelFrom", OldPC); }
	void ClientEnableNetworkVoice_Implementation(bool bEnable) { NativeCall<void, bool>(this, "APlayerController.ClientEnableNetworkVoice_Implementation", bEnable); }
	void StartTalking() { NativeCall<void>(this, "APlayerController.StartTalking"); }
	void ToggleSpeaking(bool bSpeaking) { NativeCall<void, bool>(this, "APlayerController.ToggleSpeaking", bSpeaking); }
	void ClientVoiceHandshakeComplete_Implementation() { NativeCall<void>(this, "APlayerController.ClientVoiceHandshakeComplete_Implementation"); }
	void ServerMutePlayer_Implementation(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ServerMutePlayer_Implementation", PlayerId); }
	bool ServerUnmutePlayer_Validate(FUniqueNetIdRepl PlayerId) { return NativeCall<bool, FUniqueNetIdRepl>(this, "APlayerController.ServerUnmutePlayer_Validate", PlayerId); }
	void ServerUnmutePlayer_Implementation(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ServerUnmutePlayer_Implementation", PlayerId); }
	void ClientMutePlayer_Implementation(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ClientMutePlayer_Implementation", PlayerId); }
	void ClientUnmutePlayer_Implementation(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ClientUnmutePlayer_Implementation", PlayerId); }
	bool IsPlayerMuted(FUniqueNetId * PlayerId) { return NativeCall<bool, FUniqueNetId *>(this, "APlayerController.IsPlayerMuted", PlayerId); }
	bool ShouldReplicateVoicePacketFrom(FUniqueNetId * Sender, char * PlaybackFlags) { return NativeCall<bool, FUniqueNetId *, char *>(this, "APlayerController.ShouldReplicateVoicePacketFrom", Sender, PlaybackFlags); }
	void NotifyDirectorControl(bool bNowControlling, AMatineeActor * CurrentMatinee) { NativeCall<void, bool, AMatineeActor *>(this, "APlayerController.NotifyDirectorControl", bNowControlling, CurrentMatinee); }
	void ClientWasKicked_Implementation(FText * KickReason) { NativeCall<void, FText *>(this, "APlayerController.ClientWasKicked_Implementation", KickReason); }
	bool IsSplitscreenPlayer(int * OutSplitscreenPlayerIndex) { return NativeCall<bool, int *>(this, "APlayerController.IsSplitscreenPlayer", OutSplitscreenPlayerIndex); }
	int GetSplitscreenPlayerCount() { return NativeCall<int>(this, "APlayerController.GetSplitscreenPlayerCount"); }
	void ClientSetForceMipLevelsToBeResident_Implementation(UMaterialInterface * Material, float ForceDuration, int CinematicTextureGroups) { NativeCall<void, UMaterialInterface *, float, int>(this, "APlayerController.ClientSetForceMipLevelsToBeResident_Implementation", Material, ForceDuration, CinematicTextureGroups); }
	void ClientPrestreamTextures_Implementation(AActor * ForcedActor, float ForceDuration, bool bEnableStreaming, int CinematicTextureGroups) { NativeCall<void, AActor *, float, bool, int>(this, "APlayerController.ClientPrestreamTextures_Implementation", ForcedActor, ForceDuration, bEnableStreaming, CinematicTextureGroups); }
	void ProcessForceFeedback(const float DeltaTime, const bool bGamePaused) { NativeCall<void, const float, const bool>(this, "APlayerController.ProcessForceFeedback", DeltaTime, bGamePaused); }
	void ClientClearCameraLensEffects_Implementation() { NativeCall<void>(this, "APlayerController.ClientClearCameraLensEffects_Implementation"); }
	void ReceivedSpectatorClass(TSubclassOf<AGameMode> SpectatorClass) { NativeCall<void, TSubclassOf<AGameMode>>(this, "APlayerController.ReceivedSpectatorClass", SpectatorClass); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APlayerController.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void SetPawn(APawn * InPawn) { NativeCall<void, APawn *>(this, "APlayerController.SetPawn", InPawn); }
	void SetPlayer(UPlayer * InPlayer) { NativeCall<void, UPlayer *>(this, "APlayerController.SetPlayer", InPlayer); }
	void TickPlayerInput(const float DeltaSeconds, const bool bGamePaused) { NativeCall<void, const float, const bool>(this, "APlayerController.TickPlayerInput", DeltaSeconds, bGamePaused); }
	bool IsNetRelevantFor(APlayerController * RealViewer, AActor * Viewer, FVector * SrcLocation) { return NativeCall<bool, APlayerController *, AActor *, FVector *>(this, "APlayerController.IsNetRelevantFor", RealViewer, Viewer, SrcLocation); }
	bool DefaultCanUnpause() { return NativeCall<bool>(this, "APlayerController.DefaultCanUnpause"); }
	void StartSpectatingOnly() { NativeCall<void>(this, "APlayerController.StartSpectatingOnly"); }
	void EndPlayingState() { NativeCall<void>(this, "APlayerController.EndPlayingState"); }
	void BeginSpectatingState() { NativeCall<void>(this, "APlayerController.BeginSpectatingState"); }
	void DestroySpectatorPawn() { NativeCall<void>(this, "APlayerController.DestroySpectatorPawn"); }
	void UpdateStateInputComponents() { NativeCall<void>(this, "APlayerController.UpdateStateInputComponents"); }
	void ChangeState(FName NewState) { NativeCall<void, FName>(this, "APlayerController.ChangeState", NewState); }
	void EndSpectatingState() { NativeCall<void>(this, "APlayerController.EndSpectatingState"); }
	void BeginInactiveState() { NativeCall<void>(this, "APlayerController.BeginInactiveState"); }
	void AddPitchInput(float Val) { NativeCall<void, float>(this, "APlayerController.AddPitchInput", Val); }
	void AddYawInput(float Val) { NativeCall<void, float>(this, "APlayerController.AddYawInput", Val); }
	void AddRollInput(float Val) { NativeCall<void, float>(this, "APlayerController.AddRollInput", Val); }
	bool IsInputKeyDown(FKey Key) { return NativeCall<bool, FKey>(this, "APlayerController.IsInputKeyDown", Key); }
	bool WasInputKeyJustPressed(FKey Key) { return NativeCall<bool, FKey>(this, "APlayerController.WasInputKeyJustPressed", Key); }
	bool WasInputKeyJustReleased(FKey Key) { return NativeCall<bool, FKey>(this, "APlayerController.WasInputKeyJustReleased", Key); }
	float GetInputAnalogKeyState(FKey Key) { return NativeCall<float, FKey>(this, "APlayerController.GetInputAnalogKeyState", Key); }
	FVector * GetInputVectorKeyState(FVector * result, FKey Key) { return NativeCall<FVector *, FVector *, FKey>(this, "APlayerController.GetInputVectorKeyState", result, Key); }
	void GetInputMotionState(FVector * Tilt, FVector * RotationRate, FVector * Gravity, FVector * Acceleration) { NativeCall<void, FVector *, FVector *, FVector *, FVector *>(this, "APlayerController.GetInputMotionState", Tilt, RotationRate, Gravity, Acceleration); }
	float GetInputKeyTimeDown(FKey Key) { return NativeCall<float, FKey>(this, "APlayerController.GetInputKeyTimeDown", Key); }
	bool GetMousePosition(float * LocationX, float * LocationY) { return NativeCall<bool, float *, float *>(this, "APlayerController.GetMousePosition", LocationX, LocationY); }
	void GetInputMouseDelta(float * DeltaX, float * DeltaY) { NativeCall<void, float *, float *>(this, "APlayerController.GetInputMouseDelta", DeltaX, DeltaY); }
	void EnableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "APlayerController.EnableInput", PlayerController); }
	void DisableInput(APlayerController * PlayerController) { NativeCall<void, APlayerController *>(this, "APlayerController.DisableInput", PlayerController); }
	void SetVirtualJoystickVisibility(bool bVisible) { NativeCall<void, bool>(this, "APlayerController.SetVirtualJoystickVisibility", bVisible); }
	void UpdateCameraManager(float DeltaSeconds) { NativeCall<void, float>(this, "APlayerController.UpdateCameraManager", DeltaSeconds); }
	void ClientRepObjRef_Implementation(UObject * Object) { NativeCall<void, UObject *>(this, "APlayerController.ClientRepObjRef_Implementation", Object); }
	void NetSpawnActorAtLocation_Implementation(TSubclassOf<AActor> AnActorClass, FVector_NetQuantize AtLocation, FRotator_NetQuantize AtRotation, USceneComponent * attachToComponent, int dataIndex, FName attachSocketName) { NativeCall<void, TSubclassOf<AActor>, FVector_NetQuantize, FRotator_NetQuantize, USceneComponent *, int, FName>(this, "APlayerController.NetSpawnActorAtLocation_Implementation", AnActorClass, AtLocation, AtRotation, attachToComponent, dataIndex, attachSocketName); }
	void ServerReceivedPlayerControllerAck_Implementation() { NativeCall<void>(this, "APlayerController.ServerReceivedPlayerControllerAck_Implementation"); }
	void ClientProcessNetExecCommandUnreliable_Implementation(AActor * ForActor, FName CommandName, FNetExecParams ExecParams) { NativeCall<void, AActor *, FName, FNetExecParams>(this, "APlayerController.ClientProcessNetExecCommandUnreliable_Implementation", ForActor, CommandName, ExecParams); }
	void ClientProcessSimpleNetExecCommandBP_Implementation(AActor * ForActor, FName CommandName) { NativeCall<void, AActor *, FName>(this, "APlayerController.ClientProcessSimpleNetExecCommandBP_Implementation", ForActor, CommandName); }
	void ClientProcessSimpleNetExecCommandUnreliableBP_Implementation(AActor * ForActor, FName CommandName) { NativeCall<void, AActor *, FName>(this, "APlayerController.ClientProcessSimpleNetExecCommandUnreliableBP_Implementation", ForActor, CommandName); }
	static void StaticRegisterNativesAPlayerController() { NativeCall<void>(nullptr, "APlayerController.StaticRegisterNativesAPlayerController"); }
	void ClientClearCameraLensEffects() { NativeCall<void>(this, "APlayerController.ClientClearCameraLensEffects"); }
	void ClientCommitMapChange() { NativeCall<void>(this, "APlayerController.ClientCommitMapChange"); }
	void ClientEnableNetworkVoice(bool bEnable) { NativeCall<void, bool>(this, "APlayerController.ClientEnableNetworkVoice", bEnable); }
	void ClientMessage(FString * S, FName Type, float MsgLifeTime) { NativeCall<void, FString *, FName, float>(this, "APlayerController.ClientMessage", S, Type, MsgLifeTime); }
	void ClientMutePlayer(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ClientMutePlayer", PlayerId); }
	void ClientRepObjRef(UObject * Object) { NativeCall<void, UObject *>(this, "APlayerController.ClientRepObjRef", Object); }
	void ClientReturnToMainMenu(FString * ReturnReason) { NativeCall<void, FString *>(this, "APlayerController.ClientReturnToMainMenu", ReturnReason); }
	void ClientSetHUD(TSubclassOf<AHUD> NewHUDClass) { NativeCall<void, TSubclassOf<AHUD>>(this, "APlayerController.ClientSetHUD", NewHUDClass); }
	void ClientTeamMessage(APlayerState * SenderPlayerState, FString * S, FName Type, float MsgLifeTime) { NativeCall<void, APlayerState *, FString *, FName, float>(this, "APlayerController.ClientTeamMessage", SenderPlayerState, S, Type, MsgLifeTime); }
	void ClientUnmutePlayer(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ClientUnmutePlayer", PlayerId); }
	void ClientVoiceHandshakeComplete() { NativeCall<void>(this, "APlayerController.ClientVoiceHandshakeComplete"); }
	void ClientWasKicked(FText * KickReason) { NativeCall<void, FText *>(this, "APlayerController.ClientWasKicked", KickReason); }
	void ServerChangeName(FString * S) { NativeCall<void, FString *>(this, "APlayerController.ServerChangeName", S); }
	void ServerMutePlayer(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ServerMutePlayer", PlayerId); }
	void ServerRestartPlayer() { NativeCall<void>(this, "APlayerController.ServerRestartPlayer"); }
	void ServerUnmutePlayer(FUniqueNetIdRepl PlayerId) { NativeCall<void, FUniqueNetIdRepl>(this, "APlayerController.ServerUnmutePlayer", PlayerId); }
	void ServerVerifyViewTarget() { NativeCall<void>(this, "APlayerController.ServerVerifyViewTarget"); }
};

struct AShooterPlayerController : APlayerController
{
	FieldArray<char, 10> HeldItemSlotField() { return { this, "AShooterPlayerController.HeldItemSlot" }; }
	FieldArray<char, 10> UsedItemSlotField() { return { this, "AShooterPlayerController.UsedItemSlot" }; }
	FieldArray<long double, 10> LastRepeatUseConsumableTimeField() { return { this, "AShooterPlayerController.LastRepeatUseConsumableTime" }; }
	FieldArray<long double, 10> HeldItemSlotTimeField() { return { this, "AShooterPlayerController.HeldItemSlotTime" }; }
	FieldArray<long double, 10> LastUsedItemSlotTimesField() { return { this, "AShooterPlayerController.LastUsedItemSlotTimes" }; }
	FieldValue<FVector> CurrentPlayerCharacterLocationField() { return { this, "AShooterPlayerController.CurrentPlayerCharacterLocation" }; }
	FieldValue<int> ModifedButtonCountField() { return { this, "AShooterPlayerController.ModifedButtonCount" }; }
	FieldValue<APrimalStructurePlacer *> StructurePlacerField() { return { this, "AShooterPlayerController.StructurePlacer" }; }
	FieldValue<FVector> LastDeathLocationField() { return { this, "AShooterPlayerController.LastDeathLocation" }; }
	FieldValue<long double> LastDeathTimeField() { return { this, "AShooterPlayerController.LastDeathTime" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> LastDeathPrimalCharacterField() { return { this, "AShooterPlayerController.LastDeathPrimalCharacter" }; }
	FieldValue<bool> bWasDeadField() { return { this, "AShooterPlayerController.bWasDead" }; }
	FieldValue<long double> LastDeadCharacterDestructionTimeField() { return { this, "AShooterPlayerController.LastDeadCharacterDestructionTime" }; }
	FieldValue<bool> bShowGameModeHUDField() { return { this, "AShooterPlayerController.bShowGameModeHUD" }; }
	FieldValue<FVector2D> CurrentRadialDirection1Field() { return { this, "AShooterPlayerController.CurrentRadialDirection1" }; }
	FieldValue<FVector2D> CurrentRadialDirection2Field() { return { this, "AShooterPlayerController.CurrentRadialDirection2" }; }
	FieldValue<USoundCue *> SelectSlotSoundField() { return { this, "AShooterPlayerController.SelectSlotSound" }; }
	FieldValue<UPrimalLocalProfile *> PrimalLocalProfileField() { return { this, "AShooterPlayerController.PrimalLocalProfile" }; }
	FieldValue<bool> bPlayerSpeakingField() { return { this, "AShooterPlayerController.bPlayerSpeaking" }; }
	FieldValue<int> CurrentGameModeMaxNumOfRespawnsField() { return { this, "AShooterPlayerController.CurrentGameModeMaxNumOfRespawns" }; }
	FieldValue<FVector> LastRawInputDirField() { return { this, "AShooterPlayerController.LastRawInputDir" }; }
	FieldValue<unsigned __int64> TargetOrbitedPlayerIdField() { return { this, "AShooterPlayerController.TargetOrbitedPlayerId" }; }
	FieldValue<char> TargetOrbitedTrialCountField() { return { this, "AShooterPlayerController.TargetOrbitedTrialCount" }; }
	FieldValue<TWeakObjectPtr<AShooterCharacter>> LastControlledPlayerCharacterField() { return { this, "AShooterPlayerController.LastControlledPlayerCharacter" }; }
	FieldValue<TSubclassOf<APrimalStructurePlacer>> StructurePlacerClassField() { return { this, "AShooterPlayerController.StructurePlacerClass" }; }
	FieldValue<float> MaxUseDistanceField() { return { this, "AShooterPlayerController.MaxUseDistance" }; }
	FieldValue<float> MaxUseCheckRadiusField() { return { this, "AShooterPlayerController.MaxUseCheckRadius" }; }
	FieldValue<TArray<bool>> SavedSurvivorProfileSettingsField() { return { this, "AShooterPlayerController.SavedSurvivorProfileSettings" }; }
	FieldValue<bool> bCachedOnlyShowOnlineTribeMembersField() { return { this, "AShooterPlayerController.bCachedOnlyShowOnlineTribeMembers" }; }
	FieldValue<TArray<TWeakObjectPtr<UPrimalInventoryComponent>>> RemoteViewingInventoriesField() { return { this, "AShooterPlayerController.RemoteViewingInventories" }; }
	FieldValue<TWeakObjectPtr<AActor>> LastHeldUseActorField() { return { this, "AShooterPlayerController.LastHeldUseActor" }; }
	FieldValue<TWeakObjectPtr<UActorComponent>> LastHeldUseHitComponentField() { return { this, "AShooterPlayerController.LastHeldUseHitComponent" }; }
	FieldValue<int> LastHeldUseHitBodyIndexField() { return { this, "AShooterPlayerController.LastHeldUseHitBodyIndex" }; }
	FieldValue<bool> bUsePressedFromGamepadField() { return { this, "AShooterPlayerController.bUsePressedFromGamepad" }; }
	FieldValue<TWeakObjectPtr<APrimalStructure>> SpawnAtBedField() { return { this, "AShooterPlayerController.SpawnAtBed" }; }
	FieldValue<APawn *> TempLastLostPawnField() { return { this, "AShooterPlayerController.TempLastLostPawn" }; }
	FieldValue<bool> bLockedInputDontRecenterMouseField() { return { this, "AShooterPlayerController.bLockedInputDontRecenterMouse" }; }
	FieldValue<long double> LastRespawnTimeField() { return { this, "AShooterPlayerController.LastRespawnTime" }; }
	FieldValue<bool> bIsFirstSpawnField() { return { this, "AShooterPlayerController.bIsFirstSpawn" }; }
	FieldValue<bool> bIsRespawningField() { return { this, "AShooterPlayerController.bIsRespawning" }; }
	FieldValue<bool> bIsVRPlayerField() { return { this, "AShooterPlayerController.bIsVRPlayer" }; }
	FieldValue<TSubclassOf<AHUD>> AwaitingHUDClassField() { return { this, "AShooterPlayerController.AwaitingHUDClass" }; }
	FieldValue<FItemNetID> LastEquipedItemNetIDField() { return { this, "AShooterPlayerController.LastEquipedItemNetID" }; }
	FieldValue<FItemNetID> LastUnequippedItemNetIDField() { return { this, "AShooterPlayerController.LastUnequippedItemNetID" }; }
	FieldValue<__int64> LinkedPlayerIDField() { return { this, "AShooterPlayerController.LinkedPlayerID" }; }
	FieldValue<bool> bDrawLocationField() { return { this, "AShooterPlayerController.bDrawLocation" }; }
	FieldValue<int> PlayerControllerNumField() { return { this, "AShooterPlayerController.PlayerControllerNum" }; }
	FieldValue<FVector> LastTurnSpeedField() { return { this, "AShooterPlayerController.LastTurnSpeed" }; }
	FieldValue<long double> LastMultiUseInteractionTimeField() { return { this, "AShooterPlayerController.LastMultiUseInteractionTime" }; }
	FieldValue<float> LastTimeSentCarriedRotationField() { return { this, "AShooterPlayerController.LastTimeSentCarriedRotation" }; }
	FieldValue<FItemNetID> LastSteamItemIDToRemoveField() { return { this, "AShooterPlayerController.LastSteamItemIDToRemove" }; }
	FieldValue<FItemNetID> LastSteamItemIDToAddField() { return { this, "AShooterPlayerController.LastSteamItemIDToAdd" }; }
	FieldValue<bool> bConsumeItemSucceededField() { return { this, "AShooterPlayerController.bConsumeItemSucceeded" }; }
	FieldValue<bool> bRefreshedInvetoryForRemoveField() { return { this, "AShooterPlayerController.bRefreshedInvetoryForRemove" }; }
	FieldValue<bool> bServerRefreshedSteamInventoryField() { return { this, "AShooterPlayerController.bServerRefreshedSteamInventory" }; }
	FieldValue<bool> bServerRefreshStatusField() { return { this, "AShooterPlayerController.bServerRefreshStatus" }; }
	FieldValue<bool> bCloseSteamStatusSceneField() { return { this, "AShooterPlayerController.bCloseSteamStatusScene" }; }
	FieldValue<long double> LastSteamInventoryRefreshTimeField() { return { this, "AShooterPlayerController.LastSteamInventoryRefreshTime" }; }
	FieldValue<long double> LastRequesteDinoAncestorsTimeField() { return { this, "AShooterPlayerController.LastRequesteDinoAncestorsTime" }; }
	FieldValue<long double> LastDiedMessageTimeField() { return { this, "AShooterPlayerController.LastDiedMessageTime" }; }
	FieldValue<long double> LastNotifiedTorpidityIncreaseTimeField() { return { this, "AShooterPlayerController.LastNotifiedTorpidityIncreaseTime" }; }
	FieldValue<long double> LastInvDropRequestTimeField() { return { this, "AShooterPlayerController.LastInvDropRequestTime" }; }
	FieldValue<long double> LastHadPawnTimeField() { return { this, "AShooterPlayerController.LastHadPawnTime" }; }
	FieldValue<long double> LastChatMessageTimeField() { return { this, "AShooterPlayerController.LastChatMessageTime" }; }
	FieldValue<FItemNetInfo> ARKTributeItemNetInfoField() { return { this, "AShooterPlayerController.ARKTributeItemNetInfo" }; }
	FieldValue<bool> bServerIsPaintingField() { return { this, "AShooterPlayerController.bServerIsPainting" }; }
	FieldValue<bool> bServerPaintingSuccessField() { return { this, "AShooterPlayerController.bServerPaintingSuccess" }; }
	FieldValue<long double> LastListenServerNotifyOutOfRangeTimeField() { return { this, "AShooterPlayerController.LastListenServerNotifyOutOfRangeTime" }; }
	FieldValue<int> SpectatorCycleIndexField() { return { this, "AShooterPlayerController.SpectatorCycleIndex" }; }
	FieldValue<bool> bPossessedAnyPawnField() { return { this, "AShooterPlayerController.bPossessedAnyPawn" }; }
	FieldValue<bool> bIsFastTravellingField() { return { this, "AShooterPlayerController.bIsFastTravelling" }; }
	FieldValue<bool> bSuppressAdminIconField() { return { this, "AShooterPlayerController.bSuppressAdminIcon" }; }
	FieldValue<long double> WaitingForSpawnUITimeField() { return { this, "AShooterPlayerController.WaitingForSpawnUITime" }; }
	FieldValue<float> ChatSpamWeightField() { return { this, "AShooterPlayerController.ChatSpamWeight" }; }
	FieldValue<bool> bChatSpammedField() { return { this, "AShooterPlayerController.bChatSpammed" }; }
	FieldValue<long double> EnteredSpectatingStateTimeField() { return { this, "AShooterPlayerController.EnteredSpectatingStateTime" }; }
	FieldValue<bool> bPreventPaintingStreamingField() { return { this, "AShooterPlayerController.bPreventPaintingStreaming" }; }
	FieldValue<long double> LastUsePressTimeField() { return { this, "AShooterPlayerController.LastUsePressTime" }; }
	FieldValue<TArray<int>> PlayerAppIDsField() { return { this, "AShooterPlayerController.PlayerAppIDs" }; }
	FieldValue<TArray<int>> NotifiedTribeWarIDsField() { return { this, "AShooterPlayerController.NotifiedTribeWarIDs" }; }
	FieldValue<TArray<FString>> NotifiedTribeWarNamesField() { return { this, "AShooterPlayerController.NotifiedTribeWarNames" }; }
	FieldValue<int> ServerTribeLogLastLogIndexField() { return { this, "AShooterPlayerController.ServerTribeLogLastLogIndex" }; }
	FieldValue<int> ServerTribeLogLastTribeIDField() { return { this, "AShooterPlayerController.ServerTribeLogLastTribeID" }; }
	FieldValue<FVector> LastViewLocationField() { return { this, "AShooterPlayerController.LastViewLocation" }; }
	FieldValue<bool> bHasGottenInitialSpawnLocationField() { return { this, "AShooterPlayerController.bHasGottenInitialSpawnLocation" }; }
	FieldValue<bool> bClientReceivedTribeLogField() { return { this, "AShooterPlayerController.bClientReceivedTribeLog" }; }
	FieldValue<TArray<FString>> CurrentTribeLogField() { return { this, "AShooterPlayerController.CurrentTribeLog" }; }
	FieldValue<long double> LastTribeLogRequestTimeField() { return { this, "AShooterPlayerController.LastTribeLogRequestTime" }; }
	FieldValue<bool> bHasSurvivedOneDayField() { return { this, "AShooterPlayerController.bHasSurvivedOneDay" }; }
	FieldValue<bool> bHasReachedHighestPeakField() { return { this, "AShooterPlayerController.bHasReachedHighestPeak" }; }
	FieldValue<bool> bHasReachedLowestDepthField() { return { this, "AShooterPlayerController.bHasReachedLowestDepth" }; }
	FieldValue<TSet<FString, DefaultKeyFuncs<FString, 0>, FDefaultSetAllocator>> ServerCachedAchievementIDsField() { return { this, "AShooterPlayerController.ServerCachedAchievementIDs" }; }
	FieldValue<bool> bZoomingOutField() { return { this, "AShooterPlayerController.bZoomingOut" }; }
	FieldValue<bool> bZoomingInField() { return { this, "AShooterPlayerController.bZoomingIn" }; }
	FieldValue<long double> LastRPCStayAliveTimeField() { return { this, "AShooterPlayerController.LastRPCStayAliveTime" }; }
	FieldValue<int> PlayerBadgeGroupField() { return { this, "AShooterPlayerController.PlayerBadgeGroup" }; }
	FieldValue<long double> LastMultiUseTraceTimeField() { return { this, "AShooterPlayerController.LastMultiUseTraceTime" }; }
	FieldValue<FVector> LastLargeMoveLocationField() { return { this, "AShooterPlayerController.LastLargeMoveLocation" }; }
	FieldValue<long double> LastLargeMoveTimeField() { return { this, "AShooterPlayerController.LastLargeMoveTime" }; }
	FieldValue<long double> LastNotOnUnriddenDinoTimeField() { return { this, "AShooterPlayerController.LastNotOnUnriddenDinoTime" }; }
	FieldValue<long double> LastHitMarkerCharacterTimeField() { return { this, "AShooterPlayerController.LastHitMarkerCharacterTime" }; }
	FieldValue<bool> bLastHitMarkerCharacterAllyField() { return { this, "AShooterPlayerController.bLastHitMarkerCharacterAlly" }; }
	FieldValue<long double> LastHitMarkerStructureTimeField() { return { this, "AShooterPlayerController.LastHitMarkerStructureTime" }; }
	FieldValue<bool> bLastHitMarkerStructureAllyField() { return { this, "AShooterPlayerController.bLastHitMarkerStructureAlly" }; }
	FieldValue<float> DoFSettingCurrentTimerField() { return { this, "AShooterPlayerController.DoFSettingCurrentTimer" }; }
	FieldValue<float> DoFSettingTargetTimerField() { return { this, "AShooterPlayerController.DoFSettingTargetTimer" }; }
	FieldValue<int> LastSpawnPointIDField() { return { this, "AShooterPlayerController.LastSpawnPointID" }; }
	FieldValue<int> LastSpawnRegionIndexField() { return { this, "AShooterPlayerController.LastSpawnRegionIndex" }; }
	FieldValue<unsigned __int64> LastTransferredPlayerIDField() { return { this, "AShooterPlayerController.LastTransferredPlayerID" }; }
	FieldValue<bool> bReceivedSubscribedAppsField() { return { this, "AShooterPlayerController.bReceivedSubscribedApps" }; }
	FieldValue<bool> bIsTransferringCharacterField() { return { this, "AShooterPlayerController.bIsTransferringCharacter" }; }
	FieldValue<long double> PossessedFirstPawnTimeField() { return { this, "AShooterPlayerController.PossessedFirstPawnTime" }; }
	FieldValue<int> SnapPointCycleField() { return { this, "AShooterPlayerController.SnapPointCycle" }; }
	FieldValue<FVector> LastSnapPointCyclePositionField() { return { this, "AShooterPlayerController.LastSnapPointCyclePosition" }; }
	FieldValue<int> ViewingWheelCategoryField() { return { this, "AShooterPlayerController.ViewingWheelCategory" }; }
	FieldValue<long double> ForceDrawCurrentGroupsUntilTimeField() { return { this, "AShooterPlayerController.ForceDrawCurrentGroupsUntilTime" }; }
	FieldValue<long double> LastRequestedPlaceStructureTimeField() { return { this, "AShooterPlayerController.LastRequestedPlaceStructureTime" }; }
	FieldValue<int> PersonalDinoTameCountField() { return { this, "AShooterPlayerController.PersonalDinoTameCount" }; }
	FieldValue<bool> bNextShowCharacterCreationUIDownloadField() { return { this, "AShooterPlayerController.bNextShowCharacterCreationUIDownload" }; }
	FieldValue<bool> bForceHideGameplayUIField() { return { this, "AShooterPlayerController.bForceHideGameplayUI" }; }
	FieldValue<long double> LastGamepadOpenRemoteInventoryTimeField() { return { this, "AShooterPlayerController.LastGamepadOpenRemoteInventoryTime" }; }
	FieldValue<bool> bIsGamepadActiveField() { return { this, "AShooterPlayerController.bIsGamepadActive" }; }
	FieldValue<bool> bClientIsDPCField() { return { this, "AShooterPlayerController.bClientIsDPC" }; }
	FieldValue<long double> LastClientRequestTribeOnlineListTimeField() { return { this, "AShooterPlayerController.LastClientRequestTribeOnlineListTime" }; }
	FieldValue<long double> LastClientModifiedARKInventoryTimeField() { return { this, "AShooterPlayerController.LastClientModifiedARKInventoryTime" }; }
	FieldValue<TArray<unsigned __int64>> ClientCachedTribeOnlineListField() { return { this, "AShooterPlayerController.ClientCachedTribeOnlineList" }; }
	FieldValue<bool> bPreventDefaultCharacterItemsField() { return { this, "AShooterPlayerController.bPreventDefaultCharacterItems" }; }
	FieldValue<float> SFXVolumeMultiplierField() { return { this, "AShooterPlayerController.SFXVolumeMultiplier" }; }
	FieldValue<long double> LastTeleportedTimeField() { return { this, "AShooterPlayerController.LastTeleportedTime" }; }
	FieldValue<unsigned __int64> LastConvertedPlayerIDField() { return { this, "AShooterPlayerController.LastConvertedPlayerID" }; }
	FieldValue<FString> LastConvertedPlayerIDStringField() { return { this, "AShooterPlayerController.LastConvertedPlayerIDString" }; }
	FieldValue<long double> LastShowExtendedInfoTimeField() { return { this, "AShooterPlayerController.LastShowExtendedInfoTime" }; }
	FieldValue<bool> bHasDisplayedSplitScreenMessageField() { return { this, "AShooterPlayerController.bHasDisplayedSplitScreenMessage" }; }
	FieldValue<UPrimalItem *> LastTransferredToRemoteInventoryItemField() { return { this, "AShooterPlayerController.LastTransferredToRemoteInventoryItem" }; }
	FieldValue<TSet<TWeakObjectPtr<UPrimalInventoryComponent>, DefaultKeyFuncs<TWeakObjectPtr<UPrimalInventoryComponent>, 0>, FDefaultSetAllocator>> PendingResponseEquippedItemsQueueField() { return { this, "AShooterPlayerController.PendingResponseEquippedItemsQueue" }; }
	FieldValue<TSet<TWeakObjectPtr<UPrimalInventoryComponent>, DefaultKeyFuncs<TWeakObjectPtr<UPrimalInventoryComponent>, 0>, FDefaultSetAllocator>> PendingRequestEquippedItemsQueueField() { return { this, "AShooterPlayerController.PendingRequestEquippedItemsQueue" }; }
	FieldValue<bool> bIsViewingTributeInventoryField() { return { this, "AShooterPlayerController.bIsViewingTributeInventory" }; }
	FieldValue<bool> bDrawBlackBackgroundField() { return { this, "AShooterPlayerController.bDrawBlackBackground" }; }
	FieldValue<bool> bFailedToDownloadedTransferredCharacterField() { return { this, "AShooterPlayerController.bFailedToDownloadedTransferredCharacter" }; }
	FieldValue<TSubclassOf<APrimalBuff>> CreativeModeBuffField() { return { this, "AShooterPlayerController.CreativeModeBuff" }; }
	FieldValue<float> PrimalStatsCacheFlushIntervalField() { return { this, "AShooterPlayerController.PrimalStatsCacheFlushInterval" }; }
	FieldValue<bool> bIsPrimalStatsTimerActiveField() { return { this, "AShooterPlayerController.bIsPrimalStatsTimerActive" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bInfiniteAmmo() { return { this, "AShooterPlayerController.bInfiniteAmmo" }; }
	BitFieldValue<bool, unsigned __int32> bGodMode() { return { this, "AShooterPlayerController.bGodMode" }; }
	BitFieldValue<bool, unsigned __int32> bHideGun() { return { this, "AShooterPlayerController.bHideGun" }; }
	BitFieldValue<bool, unsigned __int32> bEnemyInvisible() { return { this, "AShooterPlayerController.bEnemyInvisible" }; }
	BitFieldValue<bool, unsigned __int32> bIsAdminPauseUIEnabled() { return { this, "AShooterPlayerController.bIsAdminPauseUIEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bUsePressed() { return { this, "AShooterPlayerController.bUsePressed" }; }
	BitFieldValue<bool, unsigned __int32> bForceCraftButtonHeld() { return { this, "AShooterPlayerController.bForceCraftButtonHeld" }; }
	BitFieldValue<bool, unsigned __int32> bGamepadHotbarModifierPressed() { return { this, "AShooterPlayerController.bGamepadHotbarModifierPressed" }; }
	BitFieldValue<bool, unsigned __int32> bBattlEyePlayerHasGottenInGameFully() { return { this, "AShooterPlayerController.bBattlEyePlayerHasGottenInGameFully" }; }
	BitFieldValue<bool, unsigned __int32> bAdminShowAllPlayers() { return { this, "AShooterPlayerController.bAdminShowAllPlayers" }; }

	// Functions

	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "AShooterPlayerController.GetPrivateStaticClass"); }
	void EnableCheats(FString Pass) { NativeCall<void, FString>(this, "AShooterPlayerController.EnableCheats", Pass); }
	void CheckCheatsPassword_Implementation(FString * Pass) { NativeCall<void, FString *>(this, "AShooterPlayerController.CheckCheatsPassword_Implementation", Pass); }
	void CheckRequestSpectator_Implementation(FString * InSpectatorPass) { NativeCall<void, FString *>(this, "AShooterPlayerController.CheckRequestSpectator_Implementation", InSpectatorPass); }
	void ServerStopSpectating_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerStopSpectating_Implementation"); }
	TArray<FString> * GetCheatsCommands(TArray<FString> * result) { return NativeCall<TArray<FString> *, TArray<FString> *>(this, "AShooterPlayerController.GetCheatsCommands", result); }
	void SetupInputComponent() { NativeCall<void>(this, "AShooterPlayerController.SetupInputComponent"); }
	void OnLevelView() { NativeCall<void>(this, "AShooterPlayerController.OnLevelView"); }
	void LevelView() { NativeCall<void>(this, "AShooterPlayerController.LevelView"); }
	void SpectatorDetachOrbitCamera() { NativeCall<void>(this, "AShooterPlayerController.SpectatorDetachOrbitCamera"); }
	void SpectatorPreviousPlayer() { NativeCall<void>(this, "AShooterPlayerController.SpectatorPreviousPlayer"); }
	void SpectatorNextPlayer() { NativeCall<void>(this, "AShooterPlayerController.SpectatorNextPlayer"); }
	void DelayedTeamSpectatorSetup() { NativeCall<void>(this, "AShooterPlayerController.DelayedTeamSpectatorSetup"); }
	void ServerCycleSpectator_Implementation(bool bNext) { NativeCall<void, bool>(this, "AShooterPlayerController.ServerCycleSpectator_Implementation", bNext); }
	void ServerSpectateToPlayerByID_Implementation(unsigned __int64 PlayerID) { NativeCall<void, unsigned __int64>(this, "AShooterPlayerController.ServerSpectateToPlayerByID_Implementation", PlayerID); }
	void ClientTeleportSpectator_Implementation(FVector Location, unsigned __int64 PlayerID) { NativeCall<void, FVector, unsigned __int64>(this, "AShooterPlayerController.ClientTeleportSpectator_Implementation", Location, PlayerID); }
	void ForceCraftPressed() { NativeCall<void>(this, "AShooterPlayerController.ForceCraftPressed"); }
	void ForceCraftReleased() { NativeCall<void>(this, "AShooterPlayerController.ForceCraftReleased"); }
	void StopTalkingWrapper() { NativeCall<void>(this, "AShooterPlayerController.StopTalkingWrapper"); }
	void ToggleHUDHidden() { NativeCall<void>(this, "AShooterPlayerController.ToggleHUDHidden"); }
	void OnUseItemSlotForStructure(int ItemSlotNumber) { NativeCall<void, int>(this, "AShooterPlayerController.OnUseItemSlotForStructure", ItemSlotNumber); }
	void OnUsePress(bool bFromGamepad) { NativeCall<void, bool>(this, "AShooterPlayerController.OnUsePress", bFromGamepad); }
	bool GetAllAimedHarvestActors(float MaxDistance, TArray<AActor *> * OutHarvestActors, TArray<UActorComponent *> * OutHarvestComponents, TArray<int> * OutHitBodyIndices) { return NativeCall<bool, float, TArray<AActor *> *, TArray<UActorComponent *> *, TArray<int> *>(this, "AShooterPlayerController.GetAllAimedHarvestActors", MaxDistance, OutHarvestActors, OutHarvestComponents, OutHitBodyIndices); }
	AActor * GetAimedUseActor(UActorComponent ** UseComponent, int * hitBodyIndex) { return NativeCall<AActor *, UActorComponent **, int *>(this, "AShooterPlayerController.GetAimedUseActor", UseComponent, hitBodyIndex); }
	void OnUseRelease(bool bFromGamepad) { NativeCall<void, bool>(this, "AShooterPlayerController.OnUseRelease", bFromGamepad); }
	void ActivateMultiUseSelection(bool bIsFromUseRelease) { NativeCall<void, bool>(this, "AShooterPlayerController.ActivateMultiUseSelection", bIsFromUseRelease); }
	void CancelMultiUseSelection() { NativeCall<void>(this, "AShooterPlayerController.CancelMultiUseSelection"); }
	void OnKeyboardUsePress() { NativeCall<void>(this, "AShooterPlayerController.OnKeyboardUsePress"); }
	void OnKeyboardUseRelease() { NativeCall<void>(this, "AShooterPlayerController.OnKeyboardUseRelease"); }
	void OnGamepadUsePress() { NativeCall<void>(this, "AShooterPlayerController.OnGamepadUsePress"); }
	void OnGamepadUseRelease() { NativeCall<void>(this, "AShooterPlayerController.OnGamepadUseRelease"); }
	void OnRepeatUseHeldTimer() { NativeCall<void>(this, "AShooterPlayerController.OnRepeatUseHeldTimer"); }
	void OnUseHeldTimer() { NativeCall<void>(this, "AShooterPlayerController.OnUseHeldTimer"); }
	void SetMultiUseWheelCategory(int Category) { NativeCall<void, int>(this, "AShooterPlayerController.SetMultiUseWheelCategory", Category); }
	void StartInventoryRadialSelector() { NativeCall<void>(this, "AShooterPlayerController.StartInventoryRadialSelector"); }
	void EndInventoryRadialSelector() { NativeCall<void>(this, "AShooterPlayerController.EndInventoryRadialSelector"); }
	void StartPlayerActionRadialSelector() { NativeCall<void>(this, "AShooterPlayerController.StartPlayerActionRadialSelector"); }
	void EndPlayerActionRadialSelector() { NativeCall<void>(this, "AShooterPlayerController.EndPlayerActionRadialSelector"); }
	void OnEmoteKey2Press() { NativeCall<void>(this, "AShooterPlayerController.OnEmoteKey2Press"); }
	void OnEmoteKey1Release() { NativeCall<void>(this, "AShooterPlayerController.OnEmoteKey1Release"); }
	void SaveSpectatorPos(int Index) { NativeCall<void, int>(this, "AShooterPlayerController.SaveSpectatorPos", Index); }
	void LoadSpectatorPos(int Index) { NativeCall<void, int>(this, "AShooterPlayerController.LoadSpectatorPos", Index); }
	void OnEmoteKey2Release() { NativeCall<void>(this, "AShooterPlayerController.OnEmoteKey2Release"); }
	void StartEmoteSelection() { NativeCall<void>(this, "AShooterPlayerController.StartEmoteSelection"); }
	void OnWhistlePress() { NativeCall<void>(this, "AShooterPlayerController.OnWhistlePress"); }
	void StartWhistleSelection() { NativeCall<void>(this, "AShooterPlayerController.StartWhistleSelection"); }
	void EndWhistleSelection() { NativeCall<void>(this, "AShooterPlayerController.EndWhistleSelection"); }
	void EndEmoteSelection() { NativeCall<void>(this, "AShooterPlayerController.EndEmoteSelection"); }
	void TriggerPlayerAction(int ActionIndex) { NativeCall<void, int>(this, "AShooterPlayerController.TriggerPlayerAction", ActionIndex); }
	void ShowMyInventory() { NativeCall<void>(this, "AShooterPlayerController.ShowMyInventory"); }
	void ShowMyCraftables() { NativeCall<void>(this, "AShooterPlayerController.ShowMyCraftables"); }
	void ShowTribeManager() { NativeCall<void>(this, "AShooterPlayerController.ShowTribeManager"); }
	void ShowGlobalChat() { NativeCall<void>(this, "AShooterPlayerController.ShowGlobalChat"); }
	void ShowTribeChat() { NativeCall<void>(this, "AShooterPlayerController.ShowTribeChat"); }
	void ShowAllianceChat() { NativeCall<void>(this, "AShooterPlayerController.ShowAllianceChat"); }
	void ShowLocalChat() { NativeCall<void>(this, "AShooterPlayerController.ShowLocalChat"); }
	void ShowTutorial(int TutorialIndex, bool bForceDisplay) { NativeCall<void, int, bool>(this, "AShooterPlayerController.ShowTutorial", TutorialIndex, bForceDisplay); }
	void ClearTutorials() { NativeCall<void>(this, "AShooterPlayerController.ClearTutorials"); }
	void ToggleAutoChat() { NativeCall<void>(this, "AShooterPlayerController.ToggleAutoChat"); }
	void ScrollChatDown() { NativeCall<void>(this, "AShooterPlayerController.ScrollChatDown"); }
	void ScrollChatUp() { NativeCall<void>(this, "AShooterPlayerController.ScrollChatUp"); }
	void ToggleMap() { NativeCall<void>(this, "AShooterPlayerController.ToggleMap"); }
	void OpenMapMarkers() { NativeCall<void>(this, "AShooterPlayerController.OpenMapMarkers"); }
	void ShowAllPlayersListToFollow() { NativeCall<void>(this, "AShooterPlayerController.ShowAllPlayersListToFollow"); }
	void ToggleShowAllPlayersWhenSpectatingLocal() { NativeCall<void>(this, "AShooterPlayerController.ToggleShowAllPlayersWhenSpectatingLocal"); }
	void ToggleDinoNameTags() { NativeCall<void>(this, "AShooterPlayerController.ToggleDinoNameTags"); }
	void ToggleShowAllPlayersWhenSpectating() { NativeCall<void>(this, "AShooterPlayerController.ToggleShowAllPlayersWhenSpectating"); }
	void ToggleWeaponAccessory() { NativeCall<void>(this, "AShooterPlayerController.ToggleWeaponAccessory"); }
	void BeginPlay() { NativeCall<void>(this, "AShooterPlayerController.BeginPlay"); }
	void SaveProfile() { NativeCall<void>(this, "AShooterPlayerController.SaveProfile"); }
	void ClientNotifyPaintFinished_Implementation(bool bSuccess) { NativeCall<void, bool>(this, "AShooterPlayerController.ClientNotifyPaintFinished_Implementation", bSuccess); }
	bool IsValidUnStasisCaster() { return NativeCall<bool>(this, "AShooterPlayerController.IsValidUnStasisCaster"); }
	void ServerSetSpectatorLocation_Implementation(FVector NewLoc) { NativeCall<void, FVector>(this, "AShooterPlayerController.ServerSetSpectatorLocation_Implementation", NewLoc); }
	static void TickStasisForCharacter(UWorld * theWorld, AShooterCharacter * Character, FVector ActorLocation) { NativeCall<void, UWorld *, AShooterCharacter *, FVector>(nullptr, "AShooterPlayerController.TickStasisForCharacter", theWorld, Character, ActorLocation); }
	void SetPlayer(UPlayer * InPlayer) { NativeCall<void, UPlayer *>(this, "AShooterPlayerController.SetPlayer", InPlayer); }
	void UnFreeze() { NativeCall<void>(this, "AShooterPlayerController.UnFreeze"); }
	void ServerCheckUnfreeze_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerCheckUnfreeze_Implementation"); }
	void DoServerCheckUnfreeze_Implementation() { NativeCall<void>(this, "AShooterPlayerController.DoServerCheckUnfreeze_Implementation"); }
	void FailedToSpawnPawn() { NativeCall<void>(this, "AShooterPlayerController.FailedToSpawnPawn"); }
	void EnableSpectator() { NativeCall<void>(this, "AShooterPlayerController.EnableSpectator"); }
	void DisableSpectator() { NativeCall<void>(this, "AShooterPlayerController.DisableSpectator"); }
	void OnDisableSpectator_Implementation() { NativeCall<void>(this, "AShooterPlayerController.OnDisableSpectator_Implementation"); }
	void ServerSaveWorld_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerSaveWorld_Implementation"); }
	void ServerLoadWorld_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerLoadWorld_Implementation"); }
	void CheckforOrbiting() { NativeCall<void>(this, "AShooterPlayerController.CheckforOrbiting"); }
	bool CheckforOrbitingInstantaneously() { return NativeCall<bool>(this, "AShooterPlayerController.CheckforOrbitingInstantaneously"); }
	void OnToggleInGameMenu() { NativeCall<void>(this, "AShooterPlayerController.OnToggleInGameMenu"); }
	void OnToggleDoFMenu() { NativeCall<void>(this, "AShooterPlayerController.OnToggleDoFMenu"); }
	void MoveForward(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.MoveForward", Val); }
	void MoveRight(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.MoveRight", Val); }
	void TurnAtRate(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.TurnAtRate", Val); }
	void LookUpAtRate(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.LookUpAtRate", Val); }
	void SpectatorTurn(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.SpectatorTurn", Val); }
	void TurnInput(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.TurnInput", Val); }
	void LookInput(float Val) { NativeCall<void, float>(this, "AShooterPlayerController.LookInput", Val); }
	void OnStartFire() { NativeCall<void>(this, "AShooterPlayerController.OnStartFire"); }
	void OnStopFire() { NativeCall<void>(this, "AShooterPlayerController.OnStopFire"); }
	void OnStartGamepadRightFire() { NativeCall<void>(this, "AShooterPlayerController.OnStartGamepadRightFire"); }
	void OnStopGamepadRightFire() { NativeCall<void>(this, "AShooterPlayerController.OnStopGamepadRightFire"); }
	void ShowBattleGameModeHUD() { NativeCall<void>(this, "AShooterPlayerController.ShowBattleGameModeHUD"); }
	void OnStartTargeting() { NativeCall<void>(this, "AShooterPlayerController.OnStartTargeting"); }
	void OnStopTargeting() { NativeCall<void>(this, "AShooterPlayerController.OnStopTargeting"); }
	void OnStartGamepadLeftFire() { NativeCall<void>(this, "AShooterPlayerController.OnStartGamepadLeftFire"); }
	void OnStopGamepadLeftFire() { NativeCall<void>(this, "AShooterPlayerController.OnStopGamepadLeftFire"); }
	void ServerRequestPlaceStructure_Implementation(int StructureIndex, FVector BuildLocation, FRotator BuildRotation, FRotator PlayerViewRotation, APawn * AttachToPawn, APrimalDinoCharacter * DinoCharacter, FName BoneName, FItemNetID PlaceUsingItemID, bool bSnapped, bool bIsCheat, bool bIsFlipped, int SnapPointCycle) { NativeCall<void, int, FVector, FRotator, FRotator, APawn *, APrimalDinoCharacter *, FName, FItemNetID, bool, bool, bool, int>(this, "AShooterPlayerController.ServerRequestPlaceStructure_Implementation", StructureIndex, BuildLocation, BuildRotation, PlayerViewRotation, AttachToPawn, DinoCharacter, BoneName, PlaceUsingItemID, bSnapped, bIsCheat, bIsFlipped, SnapPointCycle); }
	void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning) { NativeCall<void, bool, bool, bool, bool, bool>(this, "AShooterPlayerController.SetCinematicMode", bInCinematicMode, bHidePlayer, bAffectsHUD, bAffectsMovement, bAffectsTurning); }
	void PawnLeavingGame() { NativeCall<void>(this, "AShooterPlayerController.PawnLeavingGame"); }
	void InitInputSystem() { NativeCall<void>(this, "AShooterPlayerController.InitInputSystem"); }
	void FlushPressedKeys() { NativeCall<void>(this, "AShooterPlayerController.FlushPressedKeys"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AShooterPlayerController.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void EnemyInVisible(bool Invisible) { NativeCall<void, bool>(this, "AShooterPlayerController.EnemyInVisible", Invisible); }
	void ServerSuicide_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerSuicide_Implementation"); }
	void ServerRemovePassenger_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerRemovePassenger_Implementation"); }
	void ClientTeamMessage_Implementation(APlayerState * SenderPlayerState, FString * S, FName Type, float MsgLifeTime) { NativeCall<void, APlayerState *, FString *, FName, float>(this, "AShooterPlayerController.ClientTeamMessage_Implementation", SenderPlayerState, S, Type, MsgLifeTime); }
	void DrawHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "AShooterPlayerController.DrawHUD", HUD); }
	void SetControlRotation(FRotator * NewRotation) { NativeCall<void, FRotator *>(this, "AShooterPlayerController.SetControlRotation", NewRotation); }
	void AcknowledgePossession(APawn * P) { NativeCall<void, APawn *>(this, "AShooterPlayerController.AcknowledgePossession", P); }
	void LeaveMeAlone() { NativeCall<void>(this, "AShooterPlayerController.LeaveMeAlone"); }
	void InfiniteStats() { NativeCall<void>(this, "AShooterPlayerController.InfiniteStats"); }
	void Destroyed() { NativeCall<void>(this, "AShooterPlayerController.Destroyed"); }
	void PostInitializeComponents() { NativeCall<void>(this, "AShooterPlayerController.PostInitializeComponents"); }
	void ServerGetMessageOfTheDay_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerGetMessageOfTheDay_Implementation"); }
	void ClientGetMessageOfTheDay_Implementation(FString * Message) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientGetMessageOfTheDay_Implementation", Message); }
	void ServerReadMessageOFTheDay_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerReadMessageOFTheDay_Implementation"); }
	void ClientStartReceivingActorItems_Implementation(UPrimalInventoryComponent * forInventory, bool bEquippedItems) { NativeCall<void, UPrimalInventoryComponent *, bool>(this, "AShooterPlayerController.ClientStartReceivingActorItems_Implementation", forInventory, bEquippedItems); }
	void ClientFinishedReceivingActorItems_Implementation(UPrimalInventoryComponent * forInventory, bool bEquippedItems) { NativeCall<void, UPrimalInventoryComponent *, bool>(this, "AShooterPlayerController.ClientFinishedReceivingActorItems_Implementation", forInventory, bEquippedItems); }
	void ClientAddActorItem_Implementation(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bEquipItem, bool ShowHUDNotification) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool, bool>(this, "AShooterPlayerController.ClientAddActorItem_Implementation", forInventory, itemInfo, bEquipItem, ShowHUDNotification); }
	void ClientAddActorItemToFolder_Implementation(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bEquipItem, bool ShowHUDNotification, FString * ToFolder) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool, bool, FString *>(this, "AShooterPlayerController.ClientAddActorItemToFolder_Implementation", forInventory, itemInfo, bEquipItem, ShowHUDNotification, ToFolder); }
	void ClientAddItemToArk_Implementation(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bFromLoad) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool>(this, "AShooterPlayerController.ClientAddItemToArk_Implementation", forInventory, itemInfo, bFromLoad); }
	void ClientAddFolderToInventoryComponent_Implementation(UPrimalInventoryComponent * forInventory, FString * NewCustomFolderName, int InventoryCompType) { NativeCall<void, UPrimalInventoryComponent *, FString *, int>(this, "AShooterPlayerController.ClientAddFolderToInventoryComponent_Implementation", forInventory, NewCustomFolderName, InventoryCompType); }
	void ClientLoadArkItems_Implementation(UPrimalInventoryComponent * forInventory, TArray<FItemNetInfo> * itemInfos) { NativeCall<void, UPrimalInventoryComponent *, TArray<FItemNetInfo> *>(this, "AShooterPlayerController.ClientLoadArkItems_Implementation", forInventory, itemInfos); }
	void ClientFinishedLoadArkItems_Implementation(UPrimalInventoryComponent * forInventory) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ClientFinishedLoadArkItems_Implementation", forInventory); }
	void ClientInsertActorItem_Implementation(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, FItemNetID InsertAfterItemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, FItemNetID>(this, "AShooterPlayerController.ClientInsertActorItem_Implementation", forInventory, itemInfo, InsertAfterItemID); }
	void ClientRemoveActorItem_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID, bool showHUDMessage) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, bool>(this, "AShooterPlayerController.ClientRemoveActorItem_Implementation", forInventory, itemID, showHUDMessage); }
	void ClientSwapActorItems_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID1, FItemNetID itemID2) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, FItemNetID>(this, "AShooterPlayerController.ClientSwapActorItems_Implementation", forInventory, itemID1, itemID2); }
	void ClientUpdateInventoryCraftQueue_Implementation(UPrimalInventoryComponent * forInventory, TArray<FItemCraftQueueEntry> * CraftQueueEntries) { NativeCall<void, UPrimalInventoryComponent *, TArray<FItemCraftQueueEntry> *>(this, "AShooterPlayerController.ClientUpdateInventoryCraftQueue_Implementation", forInventory, CraftQueueEntries); }
	void ServerRequestActorItems_Implementation(UPrimalInventoryComponent * forInventory, bool bInventoryItems, bool bIsFirstSpawn) { NativeCall<void, UPrimalInventoryComponent *, bool, bool>(this, "AShooterPlayerController.ServerRequestActorItems_Implementation", forInventory, bInventoryItems, bIsFirstSpawn); }
	void ServerRemovePawnItem_Implementation(FItemNetID itemID, bool bSecondryAction) { NativeCall<void, FItemNetID, bool>(this, "AShooterPlayerController.ServerRemovePawnItem_Implementation", itemID, bSecondryAction); }
	void ServerEquipPawnItem_Implementation(FItemNetID itemID) { NativeCall<void, FItemNetID>(this, "AShooterPlayerController.ServerEquipPawnItem_Implementation", itemID); }
	void ServerDeleteCustomFolder_Implementation(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType) { NativeCall<void, UPrimalInventoryComponent *, FString *, int>(this, "AShooterPlayerController.ServerDeleteCustomFolder_Implementation", forInventory, CFolderName, InventoryCompType); }
	void ServerAddItemToCustomFolder_Implementation(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType, FItemNetID ItemId) { NativeCall<void, UPrimalInventoryComponent *, FString *, int, FItemNetID>(this, "AShooterPlayerController.ServerAddItemToCustomFolder_Implementation", forInventory, CFolderName, InventoryCompType, ItemId); }
	void ServerDeleteItemFromCustomFolder_Implementation(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType, FItemNetID ItemId) { NativeCall<void, UPrimalInventoryComponent *, FString *, int, FItemNetID>(this, "AShooterPlayerController.ServerDeleteItemFromCustomFolder_Implementation", forInventory, CFolderName, InventoryCompType, ItemId); }
	void ServerCraftItem_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerCraftItem_Implementation", inventoryComp, itemID); }
	void ServerRepairItem_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRepairItem_Implementation", inventoryComp, itemID); }
	void ServerRequestInventorySwapItems_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, FItemNetID itemID2) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, FItemNetID>(this, "AShooterPlayerController.ServerRequestInventorySwapItems_Implementation", inventoryComp, itemID1, itemID2); }
	void ServerRequestInventoryUseItemWithItem_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, FItemNetID itemID2, int AdditionalData) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, FItemNetID, int>(this, "AShooterPlayerController.ServerRequestInventoryUseItemWithItem_Implementation", inventoryComp, itemID1, itemID2, AdditionalData); }
	void ServerRequestInventoryUseItemWithActor_Implementation(AActor * anActor, UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, int AdditionalData) { NativeCall<void, AActor *, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ServerRequestInventoryUseItemWithActor_Implementation", anActor, inventoryComp, itemID1, AdditionalData); }
	void ServerRequestInventoryUseItem_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestInventoryUseItem_Implementation", inventoryComp, itemID); }
	void ServerActorViewRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerActorViewRemoteInventory_Implementation", inventoryComp); }
	void ServerActorCloseRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerActorCloseRemoteInventory_Implementation", inventoryComp); }
	void ServerDropFromRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerDropFromRemoteInventory_Implementation", inventoryComp, itemID); }
	void ServerInventoryClearCraftQueue_Implementation(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerInventoryClearCraftQueue_Implementation", inventoryComp); }
	void ServerRequestRemoveItemSkin_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestRemoveItemSkin_Implementation", inventoryComp, itemID); }
	void ServerRequestRemoveItemSkinOnly_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestRemoveItemSkinOnly_Implementation", inventoryComp, itemID); }
	void ServerRequestRemoveWeaponAccessoryOnly_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestRemoveWeaponAccessoryOnly_Implementation", inventoryComp, itemID); }
	void ServerRequestRemoveWeaponClipAmmo_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestRemoveWeaponClipAmmo_Implementation", inventoryComp, itemID); }
	void ServerEquipToRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerEquipToRemoteInventory_Implementation", inventoryComp, itemID); }
	void ServerTransferFromRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, int requestedQuantity, int ToSlotIndex, bool bEquipItem) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int, int, bool>(this, "AShooterPlayerController.ServerTransferFromRemoteInventory_Implementation", inventoryComp, itemID, requestedQuantity, ToSlotIndex, bEquipItem); }
	void ServerTransferAllFromRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FString * CurrentCustomFolderFilter, FString * CurrentNameFilter, FString * CurrentDestinationFolder, bool bNoFolderView) { NativeCall<void, UPrimalInventoryComponent *, FString *, FString *, FString *, bool>(this, "AShooterPlayerController.ServerTransferAllFromRemoteInventory_Implementation", inventoryComp, CurrentCustomFolderFilter, CurrentNameFilter, CurrentDestinationFolder, bNoFolderView); }
	void ServerTransferAllToRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FString * CurrentCustomFolderFilter, FString * CurrentNameFilter, FString * CurrentDestinationFolder, bool bNoFolderView) { NativeCall<void, UPrimalInventoryComponent *, FString *, FString *, FString *, bool>(this, "AShooterPlayerController.ServerTransferAllToRemoteInventory_Implementation", inventoryComp, CurrentCustomFolderFilter, CurrentNameFilter, CurrentDestinationFolder, bNoFolderView); }
	void ServerTransferToRemoteInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, bool bAlsoTryToEqup, int requestedQuantity) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, bool, int>(this, "AShooterPlayerController.ServerTransferToRemoteInventory_Implementation", inventoryComp, itemID, bAlsoTryToEqup, requestedQuantity); }
	void ClientFailedToAddItemFromArkInventory_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientFailedToAddItemFromArkInventory_Implementation"); }
	void ServerAddItemFromArkInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, int requestedQuantity) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ServerAddItemFromArkInventory_Implementation", inventoryComp, itemID, requestedQuantity); }
	void OnRefreshSteamInventoryFinished(bool bSuccess, unsigned __int64 SteamID) { NativeCall<void, bool, unsigned __int64>(this, "AShooterPlayerController.OnRefreshSteamInventoryFinished", bSuccess, SteamID); }
	void ServerTakeItemFromArkInventoryAfterRefresh() { NativeCall<void>(this, "AShooterPlayerController.ServerTakeItemFromArkInventoryAfterRefresh"); }
	void ClientRemoveItemFromArk_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID RemovedItemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ClientRemoveItemFromArk_Implementation", forInventory, RemovedItemID); }
	void UploadCharaterDataToArk(UPrimalInventoryComponent * InvComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.UploadCharaterDataToArk", InvComp); }
	void ServerRequestCreateNewPlayerWithArkData(TArray<unsigned char> * PlayerArkDataBytes, unsigned __int64 TribeID) { NativeCall<void, TArray<unsigned char> *, unsigned __int64>(this, "AShooterPlayerController.ServerRequestCreateNewPlayerWithArkData", PlayerArkDataBytes, TribeID); }
	void ServerUploadCurrentCharacterAndItems_Implementation(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerUploadCurrentCharacterAndItems_Implementation", inventoryComp); }
	void ClientOnCurrentCharacterAndItemsUploaded_Implementation(unsigned __int64 TransferringPlayerDataId) { NativeCall<void, unsigned __int64>(this, "AShooterPlayerController.ClientOnCurrentCharacterAndItemsUploaded_Implementation", TransferringPlayerDataId); }
	void OnCurrentCharacterAndItemsUploaded(bool Success) { NativeCall<void, bool>(this, "AShooterPlayerController.OnCurrentCharacterAndItemsUploaded", Success); }
	void ServerUploadCharaterDataToArk_Implementation(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerUploadCharaterDataToArk_Implementation", inventoryComp); }
	void UploadCharacterPlayerDataToArk(TArray<unsigned char> * PlayerDataBytes, FString PlayerName, TArray<FString> PlayerStats, unsigned __int64 PlayerDataId, bool WithItems, unsigned int ItemCount) { NativeCall<void, TArray<unsigned char> *, FString, TArray<FString>, unsigned __int64, bool, unsigned int>(this, "AShooterPlayerController.UploadCharacterPlayerDataToArk", PlayerDataBytes, PlayerName, PlayerStats, PlayerDataId, WithItems, ItemCount); }
	void RemoveInvetoryItem(unsigned int ItemID) { NativeCall<void, unsigned int>(this, "AShooterPlayerController.RemoveInvetoryItem", ItemID); }
	bool IsHudVisible() { return NativeCall<bool>(this, "AShooterPlayerController.IsHudVisible"); }
	AShooterCharacter * GetPlayerCharacter() { return NativeCall<AShooterCharacter *>(this, "AShooterPlayerController.GetPlayerCharacter"); }
	void SetPawn(APawn * InPawn) { NativeCall<void, APawn *>(this, "AShooterPlayerController.SetPawn", InPawn); }
	void ServerRepeatMultiUse_Implementation(UObject * ForObject, int useIndex) { NativeCall<void, UObject *, int>(this, "AShooterPlayerController.ServerRepeatMultiUse_Implementation", ForObject, useIndex); }
	void ServerMultiUse_Implementation(UObject * ForObject, int useIndex) { NativeCall<void, UObject *, int>(this, "AShooterPlayerController.ServerMultiUse_Implementation", ForObject, useIndex); }
	void ClientDoMultiUse_Implementation(UObject * ForObject, int useIndex) { NativeCall<void, UObject *, int>(this, "AShooterPlayerController.ClientDoMultiUse_Implementation", ForObject, useIndex); }
	void ClientUpdateItemQuantity_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID, int ItemQuantity) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ClientUpdateItemQuantity_Implementation", forInventory, itemID, ItemQuantity); }
	void ClientUpdateItemDurability_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID, float ItemDurability) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, float>(this, "AShooterPlayerController.ClientUpdateItemDurability_Implementation", forInventory, itemID, ItemDurability); }
	void ClientUpdateItemWeaponClipAmmo_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID, int Ammo) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ClientUpdateItemWeaponClipAmmo_Implementation", forInventory, itemID, Ammo); }
	void ClientUsedActorItem_Implementation(UPrimalInventoryComponent * forInventory, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ClientUsedActorItem_Implementation", forInventory, itemID); }
	void UnPossess() { NativeCall<void>(this, "AShooterPlayerController.UnPossess"); }
	void Possess(APawn * inPawn) { NativeCall<void, APawn *>(this, "AShooterPlayerController.Possess", inPawn); }
	void UpdateRotation(float DeltaTime) { NativeCall<void, float>(this, "AShooterPlayerController.UpdateRotation", DeltaTime); }
	bool CanDoPlayerCharacterInput(bool bIgnoreCurrentWeapon, bool bWeaponForcesMountedWeaponry) { return NativeCall<bool, bool, bool>(this, "AShooterPlayerController.CanDoPlayerCharacterInput", bIgnoreCurrentWeapon, bWeaponForcesMountedWeaponry); }
	AActor * GetPlayerControllerViewerOverride() { return NativeCall<AActor *>(this, "AShooterPlayerController.GetPlayerControllerViewerOverride"); }
	void ForceTame(bool bCheatTame) { NativeCall<void, bool>(this, "AShooterPlayerController.ForceTame", bCheatTame); }
	void SetImprintQuality(float ImprintingQuality) { NativeCall<void, float>(this, "AShooterPlayerController.SetImprintQuality", ImprintingQuality); }
	void GiveToMe() { NativeCall<void>(this, "AShooterPlayerController.GiveToMe"); }
	void GiveActorToMe(AActor * anAct, bool bNotifyNetwork) { NativeCall<void, AActor *, bool>(this, "AShooterPlayerController.GiveActorToMe", anAct, bNotifyNetwork); }
	void ServerRequestLevelUp_Implementation(UPrimalCharacterStatusComponent * forStatusComp, EPrimalCharacterStatusValue::Type ValueType) { NativeCall<void, UPrimalCharacterStatusComponent *, EPrimalCharacterStatusValue::Type>(this, "AShooterPlayerController.ServerRequestLevelUp_Implementation", forStatusComp, ValueType); }
	void AddExperience(float HowMuch, bool fromTribeShare, bool bPreventSharingWithTribe) { NativeCall<void, float, bool, bool>(this, "AShooterPlayerController.AddExperience", HowMuch, fromTribeShare, bPreventSharingWithTribe); }
	void ServerRequestSetPin_Implementation(UObject * forTarget, int PinValue, bool bIsSetting, int TheCustomIndex) { NativeCall<void, UObject *, int, bool, int>(this, "AShooterPlayerController.ServerRequestSetPin_Implementation", forTarget, PinValue, bIsSetting, TheCustomIndex); }
	void ClientNotifyTribeXP_Implementation(float HowMuch) { NativeCall<void, float>(this, "AShooterPlayerController.ClientNotifyTribeXP_Implementation", HowMuch); }
	void ClientHUDNotificationTypeParams_Implementation(int MessageType, int MessageParam1, int MessageParam2, UObject * ObjectParam1) { NativeCall<void, int, int, int, UObject *>(this, "AShooterPlayerController.ClientHUDNotificationTypeParams_Implementation", MessageType, MessageParam1, MessageParam2, ObjectParam1); }
	void ServerRequestRespawnAtPoint_Implementation(int spawnPointID, int spawnRegionIndex) { NativeCall<void, int, int>(this, "AShooterPlayerController.ServerRequestRespawnAtPoint_Implementation", spawnPointID, spawnRegionIndex); }
	void ServerRequestFastTravelToPoint_Implementation(int fromSpawnPointID, int spawnPointID) { NativeCall<void, int, int>(this, "AShooterPlayerController.ServerRequestFastTravelToPoint_Implementation", fromSpawnPointID, spawnPointID); }
	void ServerUploadDino_Implementation(APrimalDinoCharacter * DownloadedDino) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterPlayerController.ServerUploadDino_Implementation", DownloadedDino); }
	void ServerRequestRemoteDropAllItems_Implementation(UPrimalInventoryComponent * inventoryComp, FString * CurrentCustomFolderFilter, FString * CurrentNameFilter) { NativeCall<void, UPrimalInventoryComponent *, FString *, FString *>(this, "AShooterPlayerController.ServerRequestRemoteDropAllItems_Implementation", inventoryComp, CurrentCustomFolderFilter, CurrentNameFilter); }
	void ServerRequestDropAllItems_Implementation(FString * CurrentCustomFolderFilter, FString * CurrentNameFilter) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerRequestDropAllItems_Implementation", CurrentCustomFolderFilter, CurrentNameFilter); }
	void ClientShowSpawnUI_Implementation(float Delay) { NativeCall<void, float>(this, "AShooterPlayerController.ClientShowSpawnUI_Implementation", Delay); }
	void ClientShowCharacterCreationUI_Implementation(bool bShowDownloadCharacter) { NativeCall<void, bool>(this, "AShooterPlayerController.ClientShowCharacterCreationUI_Implementation", bShowDownloadCharacter); }
	AActor * SpawnActor(FString * blueprintPath, float spawnDistance, float spawnYOffset, float ZOffset, bool bDoDeferBeginPlay) { return NativeCall<AActor *, FString *, float, float, float, bool>(this, "AShooterPlayerController.SpawnActor", blueprintPath, spawnDistance, spawnYOffset, ZOffset, bDoDeferBeginPlay); }
	bool GiveItem(FString * blueprintPath, int quantityOverride, float qualityOverride, bool bForceBlueprint) { return NativeCall<bool, FString *, int, float, bool>(this, "AShooterPlayerController.GiveItem", blueprintPath, quantityOverride, qualityOverride, bForceBlueprint); }
	bool GiveFast(FName * blueprintPath, int quantityOverride, float qualityOverride, bool bForceBlueprint) { return NativeCall<bool, FName *, int, float, bool>(this, "AShooterPlayerController.GiveFast", blueprintPath, quantityOverride, qualityOverride, bForceBlueprint); }
	bool GiveSlotItem(FString * blueprintPath, int slotNum, int quantityOverride) { return NativeCall<bool, FString *, int, int>(this, "AShooterPlayerController.GiveSlotItem", blueprintPath, slotNum, quantityOverride); }
	bool GiveSlotItemNum(int masterIndexNum, int slotNum, int quantityOverride) { return NativeCall<bool, int, int, int>(this, "AShooterPlayerController.GiveSlotItemNum", masterIndexNum, slotNum, quantityOverride); }
	bool GiveItemNum(int masterIndexNum, int quantityOverride, float qualityOverride, bool bForceBlueprint) { return NativeCall<bool, int, int, float, bool>(this, "AShooterPlayerController.GiveItemNum", masterIndexNum, quantityOverride, qualityOverride, bForceBlueprint); }
	FString * GetUniqueNetIdAsString(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerController.GetUniqueNetIdAsString", result); }
	void ClientOnAddedItemsToAllClustersInventory_Implementation(bool Success, FString * UserId, TArray<int> * MasterIndexNum) { NativeCall<void, bool, FString *, TArray<int> *>(this, "AShooterPlayerController.ClientOnAddedItemsToAllClustersInventory_Implementation", Success, UserId, MasterIndexNum); }
	void OnAddedItemsToAllClustersInventory(bool Success, FString * UserId, TArray<int> * MasterIndexNum) { NativeCall<void, bool, FString *, TArray<int> *>(this, "AShooterPlayerController.OnAddedItemsToAllClustersInventory", Success, UserId, MasterIndexNum); }
	bool AddItemToAllClustersInventory(FString UserId, int MasterIndexNum) { return NativeCall<bool, FString, int>(this, "AShooterPlayerController.AddItemToAllClustersInventory", UserId, MasterIndexNum); }
	void BeginInactiveState() { NativeCall<void>(this, "AShooterPlayerController.BeginInactiveState"); }
	void PawnPendingDestroy(APawn * inPawn) { NativeCall<void, APawn *>(this, "AShooterPlayerController.PawnPendingDestroy", inPawn); }
	void BeginSpectatingState() { NativeCall<void>(this, "AShooterPlayerController.BeginSpectatingState"); }
	void SetGraphicsQuality(int val) { NativeCall<void, int>(this, "AShooterPlayerController.SetGraphicsQuality", val); }
	void ResetSpawnTime() { NativeCall<void>(this, "AShooterPlayerController.ResetSpawnTime"); }
	void GetPlayerViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "AShooterPlayerController.GetPlayerViewPoint", out_Location, out_Rotation); }
	void GetPlayerViewPoint(FVector * out_Location, FRotator * out_Rotation, bool ForAiming) { NativeCall<void, FVector *, FRotator *, bool>(this, "AShooterPlayerController.GetPlayerViewPoint", out_Location, out_Rotation, ForAiming); }
	void GetPlayerViewPointNoModifiers(FVector * out_Location, FRotator * out_Rotation, bool ForAiming, bool bNoTPVAim) { NativeCall<void, FVector *, FRotator *, bool, bool>(this, "AShooterPlayerController.GetPlayerViewPointNoModifiers", out_Location, out_Rotation, ForAiming, bNoTPVAim); }
	void ClientNotifyEditText_Implementation(TSubclassOf<UObject> ForObjectClass, unsigned int ExtraID1, unsigned int ExtraID2, UObject * ForObject) { NativeCall<void, TSubclassOf<UObject>, unsigned int, unsigned int, UObject *>(this, "AShooterPlayerController.ClientNotifyEditText_Implementation", ForObjectClass, ExtraID1, ExtraID2, ForObject); }
	void ServerNotifyEditText_Implementation(FString * TextToUse, bool checkedBox, TSubclassOf<UObject> ForObjectClass, unsigned int ExtraID1, unsigned int ExtraID2, UObject * ForObject) { NativeCall<void, FString *, bool, TSubclassOf<UObject>, unsigned int, unsigned int, UObject *>(this, "AShooterPlayerController.ServerNotifyEditText_Implementation", TextToUse, checkedBox, ForObjectClass, ExtraID1, ExtraID2, ForObject); }
	void ServerSendChatMessage_Implementation(FString * ChatMessage, EChatSendMode::Type SendMode) { NativeCall<void, FString *, EChatSendMode::Type>(this, "AShooterPlayerController.ServerSendChatMessage_Implementation", ChatMessage, SendMode); }
	void ClientChatMessage_Implementation(FChatMessage Chat) { NativeCall<void, FChatMessage>(this, "AShooterPlayerController.ClientChatMessage_Implementation", Chat); }
	void ClientServerChatMessage_Implementation(FString * MessageText, FLinearColor MessageColor, bool bIsBold) { NativeCall<void, FString *, FLinearColor, bool>(this, "AShooterPlayerController.ClientServerChatMessage_Implementation", MessageText, MessageColor, bIsBold); }
	void ClientServerChatDirectMessage_Implementation(FString * MessageText, FLinearColor MessageColor, bool bIsBold) { NativeCall<void, FString *, FLinearColor, bool>(this, "AShooterPlayerController.ClientServerChatDirectMessage_Implementation", MessageText, MessageColor, bIsBold); }
	void ClientServerNotification_Implementation(FString * MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D * MessageIcon, USoundBase * SoundToPlay) { NativeCall<void, FString *, FLinearColor, float, float, UTexture2D *, USoundBase *>(this, "AShooterPlayerController.ClientServerNotification_Implementation", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay); }
	void ClientServerNotificationSingle_Implementation(FString * MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D * MessageIcon, USoundBase * SoundToPlay, int MessageTypeID) { NativeCall<void, FString *, FLinearColor, float, float, UTexture2D *, USoundBase *, int>(this, "AShooterPlayerController.ClientServerNotificationSingle_Implementation", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay, MessageTypeID); }
	void ClientServerSOTFNotificationCustom_Implementation(FString * MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D * MessageIcon, USoundBase * SoundToPlay) { NativeCall<void, FString *, FLinearColor, float, float, UTexture2D *, USoundBase *>(this, "AShooterPlayerController.ClientServerSOTFNotificationCustom_Implementation", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay); }
	void ServerGetOriginalHairColor_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerGetOriginalHairColor_Implementation"); }
	void ClientReceiveOriginalHairColor_Implementation(FLinearColor HairColor) { NativeCall<void, FLinearColor>(this, "AShooterPlayerController.ClientReceiveOriginalHairColor_Implementation", HairColor); }
	FString * WritePNTScreenshot(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerController.WritePNTScreenshot", result); }
	void TestNotification() { NativeCall<void>(this, "AShooterPlayerController.TestNotification"); }
	void ClientReset_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientReset_Implementation"); }
	void Reset() { NativeCall<void>(this, "AShooterPlayerController.Reset"); }
	void TestAlarmNotification(FString Title, FString Message) { NativeCall<void, FString, FString>(this, "AShooterPlayerController.TestAlarmNotification", Title, Message); }
	void SendAlarmNotification(FString SteamID, FString Title, FString Message) { NativeCall<void, FString, FString, FString>(this, "AShooterPlayerController.SendAlarmNotification", SteamID, Title, Message); }
	bool SendUseItemSlotToStructure() { return NativeCall<bool>(this, "AShooterPlayerController.SendUseItemSlotToStructure"); }
	void SpectatorUseItem(int Index) { NativeCall<void, int>(this, "AShooterPlayerController.SpectatorUseItem", Index); }
	void ExportDinoData(APrimalDinoCharacter * DinoToExport) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterPlayerController.ExportDinoData", DinoToExport); }
	void ApplyDepthOfFieldSetting(int Index, float CurrentTimer) { NativeCall<void, int, float>(this, "AShooterPlayerController.ApplyDepthOfFieldSetting", Index, CurrentTimer); }
	void ServerReleaseSeatingStructure_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerReleaseSeatingStructure_Implementation"); }
	void AdminCheat(FString * Msg) { NativeCall<void, FString *>(this, "AShooterPlayerController.AdminCheat", Msg); }
	void OnExtendedInfoPress() { NativeCall<void>(this, "AShooterPlayerController.OnExtendedInfoPress"); }
	void OnExtendedInfoRelease() { NativeCall<void>(this, "AShooterPlayerController.OnExtendedInfoRelease"); }
	void ClientNotifyPlayerDeath_Implementation(APawn * InstigatingPawn) { NativeCall<void, APawn *>(this, "AShooterPlayerController.ClientNotifyPlayerDeath_Implementation", InstigatingPawn); }
	void ClientNotifyPlayerDeathReason_Implementation(FString * ReasonString) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientNotifyPlayerDeathReason_Implementation", ReasonString); }
	void ServerShowMessageOfTheDay_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerShowMessageOfTheDay_Implementation"); }
	void ServerSetMessageOfTheDay_Implementation(FString * Message) { NativeCall<void, FString *>(this, "AShooterPlayerController.ServerSetMessageOfTheDay_Implementation", Message); }
	void ClientNotifyMessageOfTheDay_Implementation(FString * Message, float TimeToDisplay) { NativeCall<void, FString *, float>(this, "AShooterPlayerController.ClientNotifyMessageOfTheDay_Implementation", Message, TimeToDisplay); }
	void ClientNotifyRemotePlayerDeath_Implementation(FString * PlayerName, FString * AttackerName) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ClientNotifyRemotePlayerDeath_Implementation", PlayerName, AttackerName); }
	void ClientNotifyPlayerKill_Implementation(AActor * PlayerPawn, APawn * VictimPawn) { NativeCall<void, AActor *, APawn *>(this, "AShooterPlayerController.ClientNotifyPlayerKill_Implementation", PlayerPawn, VictimPawn); }
	void ClientNotifyDinoKill_Implementation(APrimalDinoCharacter * InstigatingPawn, APawn * VictimPawn) { NativeCall<void, APrimalDinoCharacter *, APawn *>(this, "AShooterPlayerController.ClientNotifyDinoKill_Implementation", InstigatingPawn, VictimPawn); }
	void ClientNotifyDinoDeath_Implementation(FString * DinoName, FString * AttackerName, bool bIsVehicle) { NativeCall<void, FString *, FString *, bool>(this, "AShooterPlayerController.ClientNotifyDinoDeath_Implementation", DinoName, AttackerName, bIsVehicle); }
	void ClientNotifyRespawned_Implementation(APawn * NewPawn, bool IsFirstSpawn) { NativeCall<void, APawn *, bool>(this, "AShooterPlayerController.ClientNotifyRespawned_Implementation", NewPawn, IsFirstSpawn); }
	void ClientNotifyReconnected_Implementation(APawn * NewPawn) { NativeCall<void, APawn *>(this, "AShooterPlayerController.ClientNotifyReconnected_Implementation", NewPawn); }
	void ClientResetRespawningFlag_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientResetRespawningFlag_Implementation"); }
	void CheckForPlayerInventory() { NativeCall<void>(this, "AShooterPlayerController.CheckForPlayerInventory"); }
	void ReportSpawnManagers() { NativeCall<void>(this, "AShooterPlayerController.ReportSpawnManagers"); }
	void HibernationReport(FString * ClassName) { NativeCall<void, FString *>(this, "AShooterPlayerController.HibernationReport", ClassName); }
	void HiWarp(FString * ClassName, int Index) { NativeCall<void, FString *, int>(this, "AShooterPlayerController.HiWarp", ClassName, Index); }
	void ReportLeastSpawnManagers() { NativeCall<void>(this, "AShooterPlayerController.ReportLeastSpawnManagers"); }
	void FlushLevelStreaming() { NativeCall<void>(this, "AShooterPlayerController.FlushLevelStreaming"); }
	void DoFlushLevelStreaming() { NativeCall<void>(this, "AShooterPlayerController.DoFlushLevelStreaming"); }
	void FinalFlushLevelStreaming() { NativeCall<void>(this, "AShooterPlayerController.FinalFlushLevelStreaming"); }
	void ClientNotifyCantHarvest_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyCantHarvest_Implementation"); }
	void ClientNotifyHitHarvest_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyHitHarvest_Implementation"); }
	void ClientNotifyCantHitHarvest_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyCantHitHarvest_Implementation"); }
	void ServerSetVRPlayer_Implementation(bool bSetVRPlayer) { NativeCall<void, bool>(this, "AShooterPlayerController.ServerSetVRPlayer_Implementation", bSetVRPlayer); }
	void ClientNotifyTamedDino_Implementation(TSubclassOf<APrimalDinoCharacter> DinoClass) { NativeCall<void, TSubclassOf<APrimalDinoCharacter>>(this, "AShooterPlayerController.ClientNotifyTamedDino_Implementation", DinoClass); }
	void ClientNotifySummonedDino_Implementation(TSubclassOf<APrimalDinoCharacter> DinoClass) { NativeCall<void, TSubclassOf<APrimalDinoCharacter>>(this, "AShooterPlayerController.ClientNotifySummonedDino_Implementation", DinoClass); }
	void ClientNotifyDefeatedDino_Implementation(TSubclassOf<APrimalDinoCharacter> DinoClass) { NativeCall<void, TSubclassOf<APrimalDinoCharacter>>(this, "AShooterPlayerController.ClientNotifyDefeatedDino_Implementation", DinoClass); }
	void SetPlayerPos(float X, float Y, float Z) { NativeCall<void, float, float, float>(this, "AShooterPlayerController.SetPlayerPos", X, Y, Z); }
	void SPI(float X, float Y, float Z, float Yaw, float Pitch) { NativeCall<void, float, float, float, float, float>(this, "AShooterPlayerController.SPI", X, Y, Z, Yaw, Pitch); }
	void ClientSetSpectatorLocation_Implementation(FVector NewLocation) { NativeCall<void, FVector>(this, "AShooterPlayerController.ClientSetSpectatorLocation_Implementation", NewLocation); }
	void ClientSetControlRotation_Implementation(FRotator NewRotation) { NativeCall<void, FRotator>(this, "AShooterPlayerController.ClientSetControlRotation_Implementation", NewRotation); }
	bool ShouldReplicateVoicePacketFrom(FUniqueNetId * Sender, char * PlaybackFlags) { return NativeCall<bool, FUniqueNetId *, char *>(this, "AShooterPlayerController.ShouldReplicateVoicePacketFrom", Sender, PlaybackFlags); }
	bool HasRadio(bool allowVoice) { return NativeCall<bool, bool>(this, "AShooterPlayerController.HasRadio", allowVoice); }
	TArray<unsigned int> * GetRadioFrequencies(TArray<unsigned int> * result) { return NativeCall<TArray<unsigned int> *, TArray<unsigned int> *>(this, "AShooterPlayerController.GetRadioFrequencies", result); }
	bool HasSameRadioFrequency(AShooterPlayerController * OtherPC, unsigned int * SharedFrequency) { return NativeCall<bool, AShooterPlayerController *, unsigned int *>(this, "AShooterPlayerController.HasSameRadioFrequency", OtherPC, SharedFrequency); }
	bool CanCommunicateVoiceWithRadio(AShooterPlayerController * otherPC) { return NativeCall<bool, AShooterPlayerController *>(this, "AShooterPlayerController.CanCommunicateVoiceWithRadio", otherPC); }
	void ToggleSpeaking(bool bSpeaking) { NativeCall<void, bool>(this, "AShooterPlayerController.ToggleSpeaking", bSpeaking); }
	void ForceUnstasisAtLocation(FVector AtLocation) { NativeCall<void, FVector>(this, "AShooterPlayerController.ForceUnstasisAtLocation", AtLocation); }
	void SpawnActorSpread(FString * blueprintPath, float spawnDistance, float spawnYOffset, float ZOffset, int NumberActors, float SpreadAmount) { NativeCall<void, FString *, float, float, float, int, float>(this, "AShooterPlayerController.SpawnActorSpread", blueprintPath, spawnDistance, spawnYOffset, ZOffset, NumberActors, SpreadAmount); }
	void SpawnActorSpreadTamed(FString * blueprintPath, float spawnDistance, float spawnYOffset, float ZOffset, int NumberActors, float SpreadAmount) { NativeCall<void, FString *, float, float, float, int, float>(this, "AShooterPlayerController.SpawnActorSpreadTamed", blueprintPath, spawnDistance, spawnYOffset, ZOffset, NumberActors, SpreadAmount); }
	void GiveResources() { NativeCall<void>(this, "AShooterPlayerController.GiveResources"); }
	void GiveEngrams(bool ForceAllEngrams) { NativeCall<void, bool>(this, "AShooterPlayerController.GiveEngrams", ForceAllEngrams); }
	void ForceTribes(FString * PlayerName1, FString * PlayerName2, FString * NewTribeName) { NativeCall<void, FString *, FString *, FString *>(this, "AShooterPlayerController.ForceTribes", PlayerName1, PlayerName2, NewTribeName); }
	void ClientPlayLocalSound_Implementation(USoundBase * aSound, bool bAttach) { NativeCall<void, USoundBase *, bool>(this, "AShooterPlayerController.ClientPlayLocalSound_Implementation", aSound, bAttach); }
	void ClientStopLocalSound_Implementation(USoundBase * aSound) { NativeCall<void, USoundBase *>(this, "AShooterPlayerController.ClientStopLocalSound_Implementation", aSound); }
	void ServerAddItemToArkInventory_Implementation(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, int requestedQuantity) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ServerAddItemToArkInventory_Implementation", inventoryComp, itemID, requestedQuantity); }
	void OnArkTributeAllClustersInventoryItemsLoaded(TArray<FItemNetInfo> * Items, bool bAllowForcedItemDownload) { NativeCall<void, TArray<FItemNetInfo> *, bool>(this, "AShooterPlayerController.OnArkTributeAllClustersInventoryItemsLoaded", Items, bAllowForcedItemDownload); }
	void OnArkTributeSaved(bool Success) { NativeCall<void, bool>(this, "AShooterPlayerController.OnArkTributeSaved", Success); }
	void ClientSetArkTributeLimits_Implementation(bool LimitItems, bool LimitDinos, bool LimitCharacters, int MaxItems, int MaxDinos, int MaxCharacters) { NativeCall<void, bool, bool, bool, int, int, int>(this, "AShooterPlayerController.ClientSetArkTributeLimits_Implementation", LimitItems, LimitDinos, LimitCharacters, MaxItems, MaxDinos, MaxCharacters); }
	void ServerLoadArkInventoryItems_Implementation(TArray<FItemNetInfo> * ArkInventoryItemsInfo) { NativeCall<void, TArray<FItemNetInfo> *>(this, "AShooterPlayerController.ServerLoadArkInventoryItems_Implementation", ArkInventoryItemsInfo); }
	void GetTamedDinosNearBy(TArray<TWeakObjectPtr<APrimalDinoCharacter>> * Dinos, float RangeRadius) { NativeCall<void, TArray<TWeakObjectPtr<APrimalDinoCharacter>> *, float>(this, "AShooterPlayerController.GetTamedDinosNearBy", Dinos, RangeRadius); }
	bool IsTamedDinoNearBy(APrimalDinoCharacter * Dino, float RangeRadius) { return NativeCall<bool, APrimalDinoCharacter *, float>(this, "AShooterPlayerController.IsTamedDinoNearBy", Dino, RangeRadius); }
	void ServerSendArkDataPayloadBegin_Implementation(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, FString * DataClass, FString * TagName, FString * Name, TArray<FString> * DataStats, unsigned int ID1, unsigned int ID2) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, FString *, FString *, FString *, TArray<FString> *, unsigned int, unsigned int>(this, "AShooterPlayerController.ServerSendArkDataPayloadBegin_Implementation", ID, ArkDataType, DataClass, TagName, Name, DataStats, ID1, ID2); }
	void ServerSendArkDataPayload_Implementation(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, TArray<unsigned char> * DataBytes) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, TArray<unsigned char> *>(this, "AShooterPlayerController.ServerSendArkDataPayload_Implementation", ID, ArkDataType, DataBytes); }
	void ServerSendArkDataPayloadEnd_Implementation(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type>(this, "AShooterPlayerController.ServerSendArkDataPayloadEnd_Implementation", ID, ArkDataType); }
	void ClientSendArkDataPayloadBegin_Implementation(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, FString * DataClass, FString * TagName, FString * Name, TArray<FString> * DataStats, unsigned int ID1, unsigned int ID2) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, FString *, FString *, FString *, TArray<FString> *, unsigned int, unsigned int>(this, "AShooterPlayerController.ClientSendArkDataPayloadBegin_Implementation", ID, ArkDataType, DataClass, TagName, Name, DataStats, ID1, ID2); }
	void ClientSendArkDataPayloadEnd_Implementation(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, unsigned __int64 PlayerDataID) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, unsigned __int64>(this, "AShooterPlayerController.ClientSendArkDataPayloadEnd_Implementation", ID, ArkDataType, PlayerDataID); }
	void ServerCharacterUploadWithItems_CharaterPayload_Implementation(unsigned __int64 PlayerDataId, TArray<unsigned char> * PlayerDataChunk) { NativeCall<void, unsigned __int64, TArray<unsigned char> *>(this, "AShooterPlayerController.ServerCharacterUploadWithItems_CharaterPayload_Implementation", PlayerDataId, PlayerDataChunk); }
	void ServerCharacterUploadWithItems_UploadItem_Implementation(unsigned __int64 PlayerDataId, FItemNetInfo InvItem) { NativeCall<void, unsigned __int64, FItemNetInfo>(this, "AShooterPlayerController.ServerCharacterUploadWithItems_UploadItem_Implementation", PlayerDataId, InvItem); }
	void ServerCharacterUploadWithItems_FinishAndCreateCharacter_Implementation(unsigned __int64 PlayerDataId) { NativeCall<void, unsigned __int64>(this, "AShooterPlayerController.ServerCharacterUploadWithItems_FinishAndCreateCharacter_Implementation", PlayerDataId); }
	void RequestCreateNewPlayerWithArkData(TArray<unsigned char> PlayerArkDataBytes, unsigned __int64 TribeID) { NativeCall<void, TArray<unsigned char>, unsigned __int64>(this, "AShooterPlayerController.RequestCreateNewPlayerWithArkData", PlayerArkDataBytes, TribeID); }
	void LoadLocalPlayerArkData() { NativeCall<void>(this, "AShooterPlayerController.LoadLocalPlayerArkData"); }
	int GetSubscribedAppIds() { return NativeCall<int>(this, "AShooterPlayerController.GetSubscribedAppIds"); }
	void ServerLoadUploadedDinos_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerLoadUploadedDinos_Implementation"); }
	void ClientDownloadDinoRequestFinished_Implementation(bool Success) { NativeCall<void, bool>(this, "AShooterPlayerController.ClientDownloadDinoRequestFinished_Implementation", Success); }
	void AttemptTransferRedownload() { NativeCall<void>(this, "AShooterPlayerController.AttemptTransferRedownload"); }
	void ServerLoadUploadedCharacters_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerLoadUploadedCharacters_Implementation"); }
	void ClientOnStartDownloadTransferredPlayerCharacter_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientOnStartDownloadTransferredPlayerCharacter_Implementation"); }
	void ClientOnEndDownloadTransferredPlayerCharacter_Implementation(bool Success, int FailureResponseCode, FString * FailureResponseMessage) { NativeCall<void, bool, int, FString *>(this, "AShooterPlayerController.ClientOnEndDownloadTransferredPlayerCharacter_Implementation", Success, FailureResponseCode, FailureResponseMessage); }
	void DownloadTransferredPlayerCharacter() { NativeCall<void>(this, "AShooterPlayerController.DownloadTransferredPlayerCharacter"); }
	void ClientDownloadPlayerCharacterRequestFinished_Implementation(bool Success) { NativeCall<void, bool>(this, "AShooterPlayerController.ClientDownloadPlayerCharacterRequestFinished_Implementation", Success); }
	void ServerSetSubscribedApp_Implementation(int AppID, bool bPreventDefaultItems) { NativeCall<void, int, bool>(this, "AShooterPlayerController.ServerSetSubscribedApp_Implementation", AppID, bPreventDefaultItems); }
	void ServerAddItemToSteamInventory(int ItemSteamDefID, int Quantity) { NativeCall<void, int, int>(this, "AShooterPlayerController.ServerAddItemToSteamInventory", ItemSteamDefID, Quantity); }
	void ClientRemoveItemFromSteamInventory_Implementation(TArray<unsigned __int64> * ItemSteamUserID, int Quantity) { NativeCall<void, TArray<unsigned __int64> *, int>(this, "AShooterPlayerController.ClientRemoveItemFromSteamInventory_Implementation", ItemSteamUserID, Quantity); }
	void ServerRemoveSteamItemSucceeded_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerRemoveSteamItemSucceeded_Implementation"); }
	void OnConsumeItemFinished(bool bSuccess, unsigned __int64 SteamID) { NativeCall<void, bool, unsigned __int64>(this, "AShooterPlayerController.OnConsumeItemFinished", bSuccess, SteamID); }
	void OnAddItemFinished(bool bSuccess, TArray<unsigned __int64> SteamItemUserIds, unsigned __int64 SteamID) { NativeCall<void, bool, TArray<unsigned __int64>, unsigned __int64>(this, "AShooterPlayerController.OnAddItemFinished", bSuccess, SteamItemUserIds, SteamID); }
	void ServerRefreshSteamInventoryForRemove() { NativeCall<void>(this, "AShooterPlayerController.ServerRefreshSteamInventoryForRemove"); }
	void ServerRefreshSteamInventoryToCheckConsume() { NativeCall<void>(this, "AShooterPlayerController.ServerRefreshSteamInventoryToCheckConsume"); }
	void ServerRefreshSteamInventory_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerRefreshSteamInventory_Implementation"); }
	void OnServerRefreshSteamInventoryFinished(bool bSuccess, unsigned __int64 SteamID) { NativeCall<void, bool, unsigned __int64>(this, "AShooterPlayerController.OnServerRefreshSteamInventoryFinished", bSuccess, SteamID); }
	void OnRefreshSteamInventoryToCheckConsumeFinished(bool bSuccess, unsigned __int64 SteamID) { NativeCall<void, bool, unsigned __int64>(this, "AShooterPlayerController.OnRefreshSteamInventoryToCheckConsumeFinished", bSuccess, SteamID); }
	void ClientRefreshSteamInventoryFinished_Implementation(bool bSuccess) { NativeCall<void, bool>(this, "AShooterPlayerController.ClientRefreshSteamInventoryFinished_Implementation", bSuccess); }
	void RefreshSteamInventory() { NativeCall<void>(this, "AShooterPlayerController.RefreshSteamInventory"); }
	void ServerRemoveSteamItem_Implementation(unsigned int ItemdDefId) { NativeCall<void, unsigned int>(this, "AShooterPlayerController.ServerRemoveSteamItem_Implementation", ItemdDefId); }
	void ReceivedPlayerState() { NativeCall<void>(this, "AShooterPlayerController.ReceivedPlayerState"); }
	void CloseSteamStatusScene() { NativeCall<void>(this, "AShooterPlayerController.CloseSteamStatusScene"); }
	void ServerAllowPlayerToJoinNoCheck_Implementation(FString * PlayerId) { NativeCall<void, FString *>(this, "AShooterPlayerController.ServerAllowPlayerToJoinNoCheck_Implementation", PlayerId); }
	void ServerDisallowPlayerToJoinNoCheck_Implementation(FString * PlayerId) { NativeCall<void, FString *>(this, "AShooterPlayerController.ServerDisallowPlayerToJoinNoCheck_Implementation", PlayerId); }
	void ServerSendDirectMessage_Implementation(FString * PlayerSteamID, FString * MessageText) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerSendDirectMessage_Implementation", PlayerSteamID, MessageText); }
	void ServerListPlayers_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerListPlayers_Implementation"); }
	void KickPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "AShooterPlayerController.KickPlayer", PlayerSteamName); }
	void ServerKickPlayer_Implementation(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerKickPlayer_Implementation", PlayerSteamName, PlayerSteamID); }
	void BanPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "AShooterPlayerController.BanPlayer", PlayerSteamName); }
	void ServerBanPlayer_Implementation(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerBanPlayer_Implementation", PlayerSteamName, PlayerSteamID); }
	void UnbanPlayer(FString PlayerSteamName) { NativeCall<void, FString>(this, "AShooterPlayerController.UnbanPlayer", PlayerSteamName); }
	void ServerUnbanPlayer_Implementation(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerUnbanPlayer_Implementation", PlayerSteamName, PlayerSteamID); }
	void SetKickedNotification(FString KickReason) { NativeCall<void, FString>(this, "AShooterPlayerController.SetKickedNotification", KickReason); }
	void ClientUnlockAchievement_Implementation(FString * AchievementID) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientUnlockAchievement_Implementation", AchievementID); }
	void ClientNotifyLevelUp_Implementation(APrimalCharacter * ForChar, int NewLevel) { NativeCall<void, APrimalCharacter *, int>(this, "AShooterPlayerController.ClientNotifyLevelUp_Implementation", ForChar, NewLevel); }
	void ClientNotifyAdmin_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyAdmin_Implementation"); }
	void ClientNotifyTorpidityIncrease_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyTorpidityIncrease_Implementation"); }
	void InitCharacterPainting_Implementation(APrimalCharacter * Char) { NativeCall<void, APrimalCharacter *>(this, "AShooterPlayerController.InitCharacterPainting_Implementation", Char); }
	void ClientNotifyListenServerOutOfRange_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyListenServerOutOfRange_Implementation"); }
	void StopLoadingMusic() { NativeCall<void>(this, "AShooterPlayerController.StopLoadingMusic"); }
	void FadeOutLoadingMusic() { NativeCall<void>(this, "AShooterPlayerController.FadeOutLoadingMusic"); }
	void ChangeState(FName NewState) { NativeCall<void, FName>(this, "AShooterPlayerController.ChangeState", NewState); }
	bool IsSpectator() { return NativeCall<bool>(this, "AShooterPlayerController.IsSpectator"); }
	void ClientFailedRemoveSaddle_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientFailedRemoveSaddle_Implementation"); }
	void PrintColors() { NativeCall<void>(this, "AShooterPlayerController.PrintColors"); }
	FString * ConsoleCommand(FString * result, FString * Command, bool bWriteToLog) { return NativeCall<FString *, FString *, FString *, bool>(this, "AShooterPlayerController.ConsoleCommand", result, Command, bWriteToLog); }
	void GiveColors(int quantity) { NativeCall<void, int>(this, "AShooterPlayerController.GiveColors", quantity); }
	void ClientShowPaintingUI_Implementation(UObject * ObjectToPaint) { NativeCall<void, UObject *>(this, "AShooterPlayerController.ClientShowPaintingUI_Implementation", ObjectToPaint); }
	void HideRiders(bool bDoHide) { NativeCall<void, bool>(this, "AShooterPlayerController.HideRiders", bDoHide); }
	void SetAdminIcon(bool bAdminIcon) { NativeCall<void, bool>(this, "AShooterPlayerController.SetAdminIcon", bAdminIcon); }
	void SpawnPlayerCameraManager() { NativeCall<void>(this, "AShooterPlayerController.SpawnPlayerCameraManager"); }
	void ServerSetSupressAdminIcon_Implementation(bool bSuppress) { NativeCall<void, bool>(this, "AShooterPlayerController.ServerSetSupressAdminIcon_Implementation", bSuppress); }
	void NotifyTribeWarStatus_Implementation(FString * EnemyTribeString, int StatusType) { NativeCall<void, FString *, int>(this, "AShooterPlayerController.NotifyTribeWarStatus_Implementation", EnemyTribeString, StatusType); }
	void StartArkGamepadLeftShoulder() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadLeftShoulder"); }
	void StartArkGamepadRightShoulder() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadRightShoulder"); }
	void EndArkGamepadRightShoulder() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadRightShoulder"); }
	void ServerRequestTribeLog_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerRequestTribeLog_Implementation"); }
	void ClientStartReceivingTribeLog_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientStartReceivingTribeLog_Implementation"); }
	void ClientReceiveTribeLog_Implementation(FString * LogString) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientReceiveTribeLog_Implementation", LogString); }
	void ClientEndReceivingTribeLog_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientEndReceivingTribeLog_Implementation"); }
	void EndArkGamepadLeftShoulder() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadLeftShoulder"); }
	void RPCStayAlive_Implementation() { NativeCall<void>(this, "AShooterPlayerController.RPCStayAlive_Implementation"); }
	void StartArkGamepadBackButton() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadBackButton"); }
	void EndArkGamepadBackButton() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadBackButton"); }
	void StartArkGamepadFaceButtonLeft() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadFaceButtonLeft"); }
	void EndArkGamepadFaceButtonLeft() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadFaceButtonLeft"); }
	void StartArkGamepadFaceButtonRight() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadFaceButtonRight"); }
	void EndArkGamepadFaceButtonRight() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadFaceButtonRight"); }
	void StartArkGamepadFaceButtonTop() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadFaceButtonTop"); }
	void EndArkGamepadFaceButtonTop() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadFaceButtonTop"); }
	void StartArkGamepadFaceButtonBottom() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadFaceButtonBottom"); }
	void EndArkGamepadFaceButtonBottom() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadFaceButtonBottom"); }
	void StartArkGamepadDpadLeft() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadDpadLeft"); }
	void EndArkGamepadDpadLeft() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadDpadLeft"); }
	void StartArkGamepadDpadUp() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadDpadUp"); }
	void EndAArkGamepadDpadUp() { NativeCall<void>(this, "AShooterPlayerController.EndAArkGamepadDpadUp"); }
	void StartArkGamepadDpadRight() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadDpadRight"); }
	void EndArkGamepadDpadRight() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadDpadRight"); }
	void StartArkGamepadDpadDown() { NativeCall<void>(this, "AShooterPlayerController.StartArkGamepadDpadDown"); }
	void EndArkGamepadDpadDown() { NativeCall<void>(this, "AShooterPlayerController.EndArkGamepadDpadDown"); }
	void ServerAddAchievementID_Implementation(FString * AchievementID, bool bIsOnSpawn) { NativeCall<void, FString *, bool>(this, "AShooterPlayerController.ServerAddAchievementID_Implementation", AchievementID, bIsOnSpawn); }
	FString * GetPlayerCharacterName(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerController.GetPlayerCharacterName", result); }
	void ClientCollectedAchievementItem_Implementation(TSubclassOf<UPrimalItem> ItemClass) { NativeCall<void, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerController.ClientCollectedAchievementItem_Implementation", ItemClass); }
	bool UseTribeGroupRanks() { return NativeCall<bool>(this, "AShooterPlayerController.UseTribeGroupRanks"); }
	bool IsTribeAdmin() { return NativeCall<bool>(this, "AShooterPlayerController.IsTribeAdmin"); }
	void ClientAddFloatingDamageText_Implementation(FVector_NetQuantize AtLocation, int DamageAmount, int FromTeamID) { NativeCall<void, FVector_NetQuantize, int, int>(this, "AShooterPlayerController.ClientAddFloatingDamageText_Implementation", AtLocation, DamageAmount, FromTeamID); }
	void ClientAddFloatingText_Implementation(FVector_NetQuantize AtLocation, FString * FloatingTextString, FColor FloatingTextColor, float ScaleX, float ScaleY, float TextLifeSpan, FVector TextVelocity, float MinScale, float FadeInTime, float FadeOutTime) { NativeCall<void, FVector_NetQuantize, FString *, FColor, float, float, float, FVector, float, float, float>(this, "AShooterPlayerController.ClientAddFloatingText_Implementation", AtLocation, FloatingTextString, FloatingTextColor, ScaleX, ScaleY, TextLifeSpan, TextVelocity, MinScale, FadeInTime, FadeOutTime); }
	UPrimalItem * GetInventoryUISelectedItemLocal() { return NativeCall<UPrimalItem *>(this, "AShooterPlayerController.GetInventoryUISelectedItemLocal"); }
	UPrimalItem * GetInventoryUISelectedItemRemote() { return NativeCall<UPrimalItem *>(this, "AShooterPlayerController.GetInventoryUISelectedItemRemote"); }
	void PlayHitMarkerCharacter_Implementation() { NativeCall<void>(this, "AShooterPlayerController.PlayHitMarkerCharacter_Implementation"); }
	void PlayHitMarkerStructure_Implementation() { NativeCall<void>(this, "AShooterPlayerController.PlayHitMarkerStructure_Implementation"); }
	void PlayHitMarkerCharacterAlly_Implementation() { NativeCall<void>(this, "AShooterPlayerController.PlayHitMarkerCharacterAlly_Implementation"); }
	void PlayHitMarkerStructureAlly_Implementation() { NativeCall<void>(this, "AShooterPlayerController.PlayHitMarkerStructureAlly_Implementation"); }
	void ClientShowTransferredPlayerConfirmationDialog_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientShowTransferredPlayerConfirmationDialog_Implementation"); }
	void ShowTransferCharacterConfirmationDialog() { NativeCall<void>(this, "AShooterPlayerController.ShowTransferCharacterConfirmationDialog"); }
	void OnTransferCharacterConfirmationDialogClosed(bool bAccept) { NativeCall<void, bool>(this, "AShooterPlayerController.OnTransferCharacterConfirmationDialogClosed", bAccept); }
	void ServerTransferredPlayerConfirmationResult_Implementation(bool bAccpet) { NativeCall<void, bool>(this, "AShooterPlayerController.ServerTransferredPlayerConfirmationResult_Implementation", bAccpet); }
	void ClientSetHUDAndInitUIScenes_Implementation(TSubclassOf<AHUD> NewHUDClass) { NativeCall<void, TSubclassOf<AHUD>>(this, "AShooterPlayerController.ClientSetHUDAndInitUIScenes_Implementation", NewHUDClass); }
	void ClientShowSpawnUIForTransferringPlayer_Implementation(TSubclassOf<AHUD> NewHUDClass, unsigned __int64 TransferingPlayerID, bool bUseTimer) { NativeCall<void, TSubclassOf<AHUD>, unsigned __int64, bool>(this, "AShooterPlayerController.ClientShowSpawnUIForTransferringPlayer_Implementation", NewHUDClass, TransferingPlayerID, bUseTimer); }
	void ServerDownloadTransferredPlayer_Implementation(int spawnPointID, int spawnPointRegionIndex) { NativeCall<void, int, int>(this, "AShooterPlayerController.ServerDownloadTransferredPlayer_Implementation", spawnPointID, spawnPointRegionIndex); }
	void GetAudioListenerPosition(FVector * OutLocation, FVector * OutFrontDir, FVector * OutRightDir) { NativeCall<void, FVector *, FVector *, FVector *>(this, "AShooterPlayerController.GetAudioListenerPosition", OutLocation, OutFrontDir, OutRightDir); }
	void ServerStartWeaponFire_Implementation(AShooterWeapon * weapon) { NativeCall<void, AShooterWeapon *>(this, "AShooterPlayerController.ServerStartWeaponFire_Implementation", weapon); }
	void ServerStopWeaponFire_Implementation(AShooterWeapon * weapon) { NativeCall<void, AShooterWeapon *>(this, "AShooterPlayerController.ServerStopWeaponFire_Implementation", weapon); }
	void ServerStartWeaponAltFire_Implementation(AShooterWeapon * weapon) { NativeCall<void, AShooterWeapon *>(this, "AShooterPlayerController.ServerStartWeaponAltFire_Implementation", weapon); }
	void ServerStopWeaponAltFire_Implementation(AShooterWeapon * weapon) { NativeCall<void, AShooterWeapon *>(this, "AShooterPlayerController.ServerStopWeaponAltFire_Implementation", weapon); }
	void ClientStartSurfaceCameraForPassenger_Implementation(float yaw, float pitch, float roll, bool bInvertTurnInput) { NativeCall<void, float, float, float, bool>(this, "AShooterPlayerController.ClientStartSurfaceCameraForPassenger_Implementation", yaw, pitch, roll, bInvertTurnInput); }
	void ServerUnlockPerMapExplorerNote_Implementation(int ExplorerNoteIndex) { NativeCall<void, int>(this, "AShooterPlayerController.ServerUnlockPerMapExplorerNote_Implementation", ExplorerNoteIndex); }
	void UnlockExplorerNote(int ExplorerNoteIndex) { NativeCall<void, int>(this, "AShooterPlayerController.UnlockExplorerNote", ExplorerNoteIndex); }
	void ClientUnlockExplorerNote_Implementation(int ExplorerNoteIndex) { NativeCall<void, int>(this, "AShooterPlayerController.ClientUnlockExplorerNote_Implementation", ExplorerNoteIndex); }
	APawn * GetResponsibleDamager(AActor * DamageCauser) { return NativeCall<APawn *, AActor *>(this, "AShooterPlayerController.GetResponsibleDamager", DamageCauser); }
	void UnlockEmote(FName EmoteName) { NativeCall<void, FName>(this, "AShooterPlayerController.UnlockEmote", EmoteName); }
	void LockEmote(FName EmoteName) { NativeCall<void, FName>(this, "AShooterPlayerController.LockEmote", EmoteName); }
	bool IsEmoteUnlocked(FName EmoteName) { return NativeCall<bool, FName>(this, "AShooterPlayerController.IsEmoteUnlocked", EmoteName); }
	int GetCurrentMultiUseWheelCategory() { return NativeCall<int>(this, "AShooterPlayerController.GetCurrentMultiUseWheelCategory"); }
	void ClientReceiveDinoAncestors_Implementation(APrimalDinoCharacter * ForDino, TArray<FDinoAncestorsEntry> * DinoAncestors, TArray<FDinoAncestorsEntry> * DinoAncestorsMale, int RandomMutationsFemale, int RandomMutationsMale) { NativeCall<void, APrimalDinoCharacter *, TArray<FDinoAncestorsEntry> *, TArray<FDinoAncestorsEntry> *, int, int>(this, "AShooterPlayerController.ClientReceiveDinoAncestors_Implementation", ForDino, DinoAncestors, DinoAncestorsMale, RandomMutationsFemale, RandomMutationsMale); }
	void ServerRequestDinoAncestors_Implementation(APrimalDinoCharacter * ForDino) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterPlayerController.ServerRequestDinoAncestors_Implementation", ForDino); }
	void OnPressGroupAddOrRemoveTame() { NativeCall<void>(this, "AShooterPlayerController.OnPressGroupAddOrRemoveTame"); }
	AActor * BaseGetPlayerCharacter() { return NativeCall<AActor *>(this, "AShooterPlayerController.BaseGetPlayerCharacter"); }
	void ClientNotifyUnlockedEngram_Implementation(TSubclassOf<UPrimalItem> ItemClass, bool bTekGram) { NativeCall<void, TSubclassOf<UPrimalItem>, bool>(this, "AShooterPlayerController.ClientNotifyUnlockedEngram_Implementation", ItemClass, bTekGram); }
	void ClientTeleportSucceeded_Implementation(FVector TeleportLoc, FRotator TeleportRot, bool bSimpleTeleport) { NativeCall<void, FVector, FRotator, bool>(this, "AShooterPlayerController.ClientTeleportSucceeded_Implementation", TeleportLoc, TeleportRot, bSimpleTeleport); }
	bool IsAtPersonalTameLimit(bool bIsForStructure) { return NativeCall<bool, bool>(this, "AShooterPlayerController.IsAtPersonalTameLimit", bIsForStructure); }
	FString * GetPersonalTameLimitString(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterPlayerController.GetPersonalTameLimitString", result); }
	void ClientSetPersonalDinoTameCount_Implementation(int NewPersonalDinoTameCount) { NativeCall<void, int>(this, "AShooterPlayerController.ClientSetPersonalDinoTameCount_Implementation", NewPersonalDinoTameCount); }
	void UpdatePostProcessVolumes() { NativeCall<void>(this, "AShooterPlayerController.UpdatePostProcessVolumes"); }
	bool IsSavingData() { return NativeCall<bool>(this, "AShooterPlayerController.IsSavingData"); }
	FString * PlayerCommand_Implementation(FString * result, FString * TheCommand) { return NativeCall<FString *, FString *, FString *>(this, "AShooterPlayerController.PlayerCommand_Implementation", result, TheCommand); }
	void TryToForceUploadCharacter_Implementation() { NativeCall<void>(this, "AShooterPlayerController.TryToForceUploadCharacter_Implementation"); }
	void ServerDPC_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerDPC_Implementation"); }
	void QuitToMainMenu() { NativeCall<void>(this, "AShooterPlayerController.QuitToMainMenu"); }
	bool IsViewingInventoryUI() { return NativeCall<bool>(this, "AShooterPlayerController.IsViewingInventoryUI"); }
	bool IsFirstLocalPlayerOrLivingLocalPlayer() { return NativeCall<bool>(this, "AShooterPlayerController.IsFirstLocalPlayerOrLivingLocalPlayer"); }
	void ServerRequestMyTribeOnlineList_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerRequestMyTribeOnlineList_Implementation"); }
	void ClientReceiveMyTribeOnlineList_Implementation(TArray<unsigned int> * OnlinePlayerIDs) { NativeCall<void, TArray<unsigned int> *>(this, "AShooterPlayerController.ClientReceiveMyTribeOnlineList_Implementation", OnlinePlayerIDs); }
	void ClientNotifyUnlockHairStyleOrEmote_Implementation(FName HairstyleOrEmoteName) { NativeCall<void, FName>(this, "AShooterPlayerController.ClientNotifyUnlockHairStyleOrEmote_Implementation", HairstyleOrEmoteName); }
	void UpdateRequestEquippedItemsQueue() { NativeCall<void>(this, "AShooterPlayerController.UpdateRequestEquippedItemsQueue"); }
	void SetGamma1() { NativeCall<void>(this, "AShooterPlayerController.SetGamma1"); }
	void SetGamma2() { NativeCall<void>(this, "AShooterPlayerController.SetGamma2"); }
	void ServerDropAllNotReadyForUploadItems_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ServerDropAllNotReadyForUploadItems_Implementation"); }
	void ClientOnDropAllNotReadyForUploadItemsFinished_Implementation() { NativeCall<void>(this, "AShooterPlayerController.ClientOnDropAllNotReadyForUploadItemsFinished_Implementation"); }
	void QueueRequestEquippedItems(UPrimalInventoryComponent * invComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.QueueRequestEquippedItems", invComp); }
	void IncrementPrimalStats(EPrimalStatsValueTypes::Type statsValueType) { NativeCall<void, EPrimalStatsValueTypes::Type>(this, "AShooterPlayerController.IncrementPrimalStats", statsValueType); }
	void FlushPrimalStats() { NativeCall<void>(this, "AShooterPlayerController.FlushPrimalStats"); }
	static void StaticRegisterNativesAShooterPlayerController() { NativeCall<void>(nullptr, "AShooterPlayerController.StaticRegisterNativesAShooterPlayerController"); }
	void CheckCheatsPassword(FString * pass) { NativeCall<void, FString *>(this, "AShooterPlayerController.CheckCheatsPassword", pass); }
	void CheckRequestSpectator(FString * InSpectatorPass) { NativeCall<void, FString *>(this, "AShooterPlayerController.CheckRequestSpectator", InSpectatorPass); }
	void ClientAddActorItem(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bEquipItem, bool ShowHUDNotification) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool, bool>(this, "AShooterPlayerController.ClientAddActorItem", forInventory, itemInfo, bEquipItem, ShowHUDNotification); }
	void ClientAddActorItemToFolder(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bEquipItem, bool ShowHUDNotification, FString * ToFolder) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool, bool, FString *>(this, "AShooterPlayerController.ClientAddActorItemToFolder", forInventory, itemInfo, bEquipItem, ShowHUDNotification, ToFolder); }
	void ClientAddItemToArk(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, bool bFromLoad) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, bool>(this, "AShooterPlayerController.ClientAddItemToArk", forInventory, itemInfo, bFromLoad); }
	void ClientChatMessage(FChatMessage Chat) { NativeCall<void, FChatMessage>(this, "AShooterPlayerController.ClientChatMessage", Chat); }
	void ClientCollectedAchievementItem(TSubclassOf<UPrimalItem> ItemClass) { NativeCall<void, TSubclassOf<UPrimalItem>>(this, "AShooterPlayerController.ClientCollectedAchievementItem", ItemClass); }
	void ClientDoMultiUse(UObject * ForObject, int useIndex) { NativeCall<void, UObject *, int>(this, "AShooterPlayerController.ClientDoMultiUse", ForObject, useIndex); }
	void ClientFailedRemoveSaddle() { NativeCall<void>(this, "AShooterPlayerController.ClientFailedRemoveSaddle"); }
	void ClientFailedToAddItemFromArkInventory() { NativeCall<void>(this, "AShooterPlayerController.ClientFailedToAddItemFromArkInventory"); }
	void ClientFinishedReceivingActorItems(UPrimalInventoryComponent * forInventory, bool bEquippedItems) { NativeCall<void, UPrimalInventoryComponent *, bool>(this, "AShooterPlayerController.ClientFinishedReceivingActorItems", forInventory, bEquippedItems); }
	void ClientHUDNotificationTypeParams(int MessageType, int MessageType1, int MessageParam2, UObject * ObjectParam1) { NativeCall<void, int, int, int, UObject *>(this, "AShooterPlayerController.ClientHUDNotificationTypeParams", MessageType, MessageType1, MessageParam2, ObjectParam1); }
	void ClientInsertActorItem(UPrimalInventoryComponent * forInventory, FItemNetInfo itemInfo, FItemNetID InsertAfterItemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetInfo, FItemNetID>(this, "AShooterPlayerController.ClientInsertActorItem", forInventory, itemInfo, InsertAfterItemID); }
	void ClientNotifyAdmin() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyAdmin"); }
	void ClientNotifyDinoDeath(FString * DinoName, FString * AttackerName, bool bIsVehicle) { NativeCall<void, FString *, FString *, bool>(this, "AShooterPlayerController.ClientNotifyDinoDeath", DinoName, AttackerName, bIsVehicle); }
	void ClientNotifyDinoKill(APrimalDinoCharacter * InstigatingPawn, APawn * VictimPawn) { NativeCall<void, APrimalDinoCharacter *, APawn *>(this, "AShooterPlayerController.ClientNotifyDinoKill", InstigatingPawn, VictimPawn); }
	void ClientNotifyEditText(TSubclassOf<UObject> ForObjectClass, unsigned int ExtraID1, unsigned int ExtraID2, UObject * ForObject) { NativeCall<void, TSubclassOf<UObject>, unsigned int, unsigned int, UObject *>(this, "AShooterPlayerController.ClientNotifyEditText", ForObjectClass, ExtraID1, ExtraID2, ForObject); }
	void ClientNotifyListenServerOutOfRange() { NativeCall<void>(this, "AShooterPlayerController.ClientNotifyListenServerOutOfRange"); }
	void ClientNotifyMessageOfTheDay(FString * Message, float timeToDisplay) { NativeCall<void, FString *, float>(this, "AShooterPlayerController.ClientNotifyMessageOfTheDay", Message, timeToDisplay); }
	void ClientNotifyPlayerDeathReason(FString * ReasonString) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientNotifyPlayerDeathReason", ReasonString); }
	void ClientNotifyPlayerKill(AActor * PlayerPawn, APawn * VictimPawn) { NativeCall<void, AActor *, APawn *>(this, "AShooterPlayerController.ClientNotifyPlayerKill", PlayerPawn, VictimPawn); }
	void ClientNotifyTamedDino(TSubclassOf<APrimalDinoCharacter> DinoClass) { NativeCall<void, TSubclassOf<APrimalDinoCharacter>>(this, "AShooterPlayerController.ClientNotifyTamedDino", DinoClass); }
	void ClientNotifyUnlockedEngram(TSubclassOf<UPrimalItem> ItemClass, bool bTekGram) { NativeCall<void, TSubclassOf<UPrimalItem>, bool>(this, "AShooterPlayerController.ClientNotifyUnlockedEngram", ItemClass, bTekGram); }
	void ClientOnAddedItemsToAllClustersInventory(bool Success, FString * UserId, TArray<int> * MasterIndexNum) { NativeCall<void, bool, FString *, TArray<int> *>(this, "AShooterPlayerController.ClientOnAddedItemsToAllClustersInventory", Success, UserId, MasterIndexNum); }
	void ClientOnEndDownloadTransferredPlayerCharacter(bool Success, int FailureResponseCode, FString * FailureResponseMessage) { NativeCall<void, bool, int, FString *>(this, "AShooterPlayerController.ClientOnEndDownloadTransferredPlayerCharacter", Success, FailureResponseCode, FailureResponseMessage); }
	void ClientPlayLocalSound(USoundBase * aSound, bool bAttach) { NativeCall<void, USoundBase *, bool>(this, "AShooterPlayerController.ClientPlayLocalSound", aSound, bAttach); }
	void ClientReceiveDinoAncestors(APrimalDinoCharacter * ForDino, TArray<FDinoAncestorsEntry> * DinoAncestors, TArray<FDinoAncestorsEntry> * DinoAncestorsMale, int RandomMutationsFemale, int RandomMutationsMale) { NativeCall<void, APrimalDinoCharacter *, TArray<FDinoAncestorsEntry> *, TArray<FDinoAncestorsEntry> *, int, int>(this, "AShooterPlayerController.ClientReceiveDinoAncestors", ForDino, DinoAncestors, DinoAncestorsMale, RandomMutationsFemale, RandomMutationsMale); }
	void ClientReceiveTribeLog(FString * LogString) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientReceiveTribeLog", LogString); }
	void ClientRemoveItemFromSteamInventory(TArray<unsigned __int64> * ItemSteamUserID, int Quantity) { NativeCall<void, TArray<unsigned __int64> *, int>(this, "AShooterPlayerController.ClientRemoveItemFromSteamInventory", ItemSteamUserID, Quantity); }
	void ClientSendArkDataPayloadBegin(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, FString * DataClass, FString * TagName, FString * Name, TArray<FString> * DataStats, unsigned int ID1, unsigned int ID2) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, FString *, FString *, FString *, TArray<FString> *, unsigned int, unsigned int>(this, "AShooterPlayerController.ClientSendArkDataPayloadBegin", ID, ArkDataType, DataClass, TagName, Name, DataStats, ID1, ID2); }
	void ClientServerChatDirectMessage(FString * MessageText, FLinearColor MessageColor, bool bIsBold) { NativeCall<void, FString *, FLinearColor, bool>(this, "AShooterPlayerController.ClientServerChatDirectMessage", MessageText, MessageColor, bIsBold); }
	void ClientServerNotification(FString * MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D * MessageIcon, USoundBase * SoundToPlay) { NativeCall<void, FString *, FLinearColor, float, float, UTexture2D *, USoundBase *>(this, "AShooterPlayerController.ClientServerNotification", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay); }
	void ClientServerSOTFNotificationCustom(FString * MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D * MessageIcon, USoundBase * SoundToPlay) { NativeCall<void, FString *, FLinearColor, float, float, UTexture2D *, USoundBase *>(this, "AShooterPlayerController.ClientServerSOTFNotificationCustom", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay); }
	void ClientSetArkTributeLimits(bool LimitItems, bool LimitDinos, bool LimitCharacters, int MaxItems, int MaxDinos, int MaxCharacters) { NativeCall<void, bool, bool, bool, int, int, int>(this, "AShooterPlayerController.ClientSetArkTributeLimits", LimitItems, LimitDinos, LimitCharacters, MaxItems, MaxDinos, MaxCharacters); }
	void ClientSetHUDAndInitUIScenes(TSubclassOf<AHUD> NewHUDClass) { NativeCall<void, TSubclassOf<AHUD>>(this, "AShooterPlayerController.ClientSetHUDAndInitUIScenes", NewHUDClass); }
	void ClientShowPaintingUI(UObject * ObjectToPaint) { NativeCall<void, UObject *>(this, "AShooterPlayerController.ClientShowPaintingUI", ObjectToPaint); }
	void ClientUnlockAchievement(FString * AchievementID) { NativeCall<void, FString *>(this, "AShooterPlayerController.ClientUnlockAchievement", AchievementID); }
	void ClientUpdateInventoryCraftQueue(UPrimalInventoryComponent * forInventory, TArray<FItemCraftQueueEntry> * CraftQueueEntries) { NativeCall<void, UPrimalInventoryComponent *, TArray<FItemCraftQueueEntry> *>(this, "AShooterPlayerController.ClientUpdateInventoryCraftQueue", forInventory, CraftQueueEntries); }
	void NotifyTribeWarStatus(FString * EnemyTribeString, int StatusType) { NativeCall<void, FString *, int>(this, "AShooterPlayerController.NotifyTribeWarStatus", EnemyTribeString, StatusType); }
	FString * PlayerCommand(FString * result, FString * TheCommand) { return NativeCall<FString *, FString *, FString *>(this, "AShooterPlayerController.PlayerCommand", result, TheCommand); }
	void ServerAddAchievementID(FString * AchievementID, bool bIsOnSpawn) { NativeCall<void, FString *, bool>(this, "AShooterPlayerController.ServerAddAchievementID", AchievementID, bIsOnSpawn); }
	void ServerAddItemToCustomFolder(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType, FItemNetID ItemId) { NativeCall<void, UPrimalInventoryComponent *, FString *, int, FItemNetID>(this, "AShooterPlayerController.ServerAddItemToCustomFolder", forInventory, CFolderName, InventoryCompType, ItemId); }
	void ServerAllowPlayerToJoinNoCheck(FString * PlayerId) { NativeCall<void, FString *>(this, "AShooterPlayerController.ServerAllowPlayerToJoinNoCheck", PlayerId); }
	void ServerBanPlayer(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerBanPlayer", PlayerSteamName, PlayerSteamID); }
	void ServerCharacterUploadWithItems_UploadItem(unsigned __int64 PlayerDataId, FItemNetInfo InvItem) { NativeCall<void, unsigned __int64, FItemNetInfo>(this, "AShooterPlayerController.ServerCharacterUploadWithItems_UploadItem", PlayerDataId, InvItem); }
	void ServerCraftItem(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerCraftItem", inventoryComp, itemID); }
	void ServerDeleteCustomFolder(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType) { NativeCall<void, UPrimalInventoryComponent *, FString *, int>(this, "AShooterPlayerController.ServerDeleteCustomFolder", forInventory, CFolderName, InventoryCompType); }
	void ServerDeleteItemFromCustomFolder(UPrimalInventoryComponent * forInventory, FString * CFolderName, int InventoryCompType, FItemNetID ItemId) { NativeCall<void, UPrimalInventoryComponent *, FString *, int, FItemNetID>(this, "AShooterPlayerController.ServerDeleteItemFromCustomFolder", forInventory, CFolderName, InventoryCompType, ItemId); }
	void ServerDisallowPlayerToJoinNoCheck(FString * PlayerId) { NativeCall<void, FString *>(this, "AShooterPlayerController.ServerDisallowPlayerToJoinNoCheck", PlayerId); }
	void ServerDPC() { NativeCall<void>(this, "AShooterPlayerController.ServerDPC"); }
	void ServerDropFromRemoteInventory(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerDropFromRemoteInventory", inventoryComp, itemID); }
	void ServerEquipPawnItem(FItemNetID itemID) { NativeCall<void, FItemNetID>(this, "AShooterPlayerController.ServerEquipPawnItem", itemID); }
	void ServerEquipToRemoteInventory(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerEquipToRemoteInventory", inventoryComp, itemID); }
	void ServerKickPlayer(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerKickPlayer", PlayerSteamName, PlayerSteamID); }
	void ServerMultiUse(UObject * ForObject, int useIndex) { NativeCall<void, UObject *, int>(this, "AShooterPlayerController.ServerMultiUse", ForObject, useIndex); }
	void ServerRemovePassenger() { NativeCall<void>(this, "AShooterPlayerController.ServerRemovePassenger"); }
	void ServerRemovePawnItem(FItemNetID itemID, bool bSecondryAction) { NativeCall<void, FItemNetID, bool>(this, "AShooterPlayerController.ServerRemovePawnItem", itemID, bSecondryAction); }
	void ServerRepairItem(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRepairItem", inventoryComp, itemID); }
	void ServerRequestInventorySwapItems(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, FItemNetID itemID2) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, FItemNetID>(this, "AShooterPlayerController.ServerRequestInventorySwapItems", inventoryComp, itemID1, itemID2); }
	void ServerRequestInventoryUseItem(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestInventoryUseItem", inventoryComp, itemID); }
	void ServerRequestInventoryUseItemWithActor(AActor * anActor, UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, int AdditionalData) { NativeCall<void, AActor *, UPrimalInventoryComponent *, FItemNetID, int>(this, "AShooterPlayerController.ServerRequestInventoryUseItemWithActor", anActor, inventoryComp, itemID1, AdditionalData); }
	void ServerRequestInventoryUseItemWithItem(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID1, FItemNetID itemID2, int AdditionalData) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, FItemNetID, int>(this, "AShooterPlayerController.ServerRequestInventoryUseItemWithItem", inventoryComp, itemID1, itemID2, AdditionalData); }
	void ServerRequestRemoveWeaponClipAmmo(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID>(this, "AShooterPlayerController.ServerRequestRemoveWeaponClipAmmo", inventoryComp, itemID); }
	void ServerRequestSetPin(UObject * forTarget, int PinValue, bool bIsSetting, int TheCustomIndex) { NativeCall<void, UObject *, int, bool, int>(this, "AShooterPlayerController.ServerRequestSetPin", forTarget, PinValue, bIsSetting, TheCustomIndex); }
	void ServerSendArkDataPayloadBegin(FGuid ID, EPrimalARKTributeDataType::Type ArkDataType, FString * DataClass, FString * TagName, FString * Name, TArray<FString> * DataStats, unsigned int ID1, unsigned int ID2) { NativeCall<void, FGuid, EPrimalARKTributeDataType::Type, FString *, FString *, FString *, TArray<FString> *, unsigned int, unsigned int>(this, "AShooterPlayerController.ServerSendArkDataPayloadBegin", ID, ArkDataType, DataClass, TagName, Name, DataStats, ID1, ID2); }
	void ServerSendChatMessage(FString * ChatMessage, EChatSendMode::Type SendMode) { NativeCall<void, FString *, EChatSendMode::Type>(this, "AShooterPlayerController.ServerSendChatMessage", ChatMessage, SendMode); }
	void ServerSendDirectMessage(FString * PlayerSteamID, FString * Message) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerSendDirectMessage", PlayerSteamID, Message); }
	void ServerTransferAllFromRemoteInventory(UPrimalInventoryComponent * inventoryComp, FString * CurrentCustomFolderFilter, FString * CurrentNameFilter, FString * CurrentDestinationFolder, bool bNoFolderView) { NativeCall<void, UPrimalInventoryComponent *, FString *, FString *, FString *, bool>(this, "AShooterPlayerController.ServerTransferAllFromRemoteInventory", inventoryComp, CurrentCustomFolderFilter, CurrentNameFilter, CurrentDestinationFolder, bNoFolderView); }
	void ServerTransferAllToRemoteInventory(UPrimalInventoryComponent * inventoryComp, FString * CurrentCustomFolderFilter, FString * CurrentNameFilter, FString * CurrentDestinationFolder, bool bNoFolderView) { NativeCall<void, UPrimalInventoryComponent *, FString *, FString *, FString *, bool>(this, "AShooterPlayerController.ServerTransferAllToRemoteInventory", inventoryComp, CurrentCustomFolderFilter, CurrentNameFilter, CurrentDestinationFolder, bNoFolderView); }
	void ServerTransferFromRemoteInventory(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, int requestedQuantity, int ToSlotIndex, bool bEquipItem) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, int, int, bool>(this, "AShooterPlayerController.ServerTransferFromRemoteInventory", inventoryComp, itemID, requestedQuantity, ToSlotIndex, bEquipItem); }
	void ServerTransferToRemoteInventory(UPrimalInventoryComponent * inventoryComp, FItemNetID itemID, bool bAlsoTryToEqup, int requestedQuantity) { NativeCall<void, UPrimalInventoryComponent *, FItemNetID, bool, int>(this, "AShooterPlayerController.ServerTransferToRemoteInventory", inventoryComp, itemID, bAlsoTryToEqup, requestedQuantity); }
	void ServerUnbanPlayer(FString * PlayerSteamName, FString * PlayerSteamID) { NativeCall<void, FString *, FString *>(this, "AShooterPlayerController.ServerUnbanPlayer", PlayerSteamName, PlayerSteamID); }
	void ServerUploadCurrentCharacterAndItems(UPrimalInventoryComponent * inventoryComp) { NativeCall<void, UPrimalInventoryComponent *>(this, "AShooterPlayerController.ServerUploadCurrentCharacterAndItems", inventoryComp); }
};

struct ACharacter : APawn
{
	FieldValue<TSubobjectPtr<UCharacterMovementComponent>> CharacterMovementField() { return { this, "ACharacter.CharacterMovement" }; }
	FieldValue<FVector> BaseTranslationOffsetField() { return { this, "ACharacter.BaseTranslationOffset" }; }
	FieldValue<char> ReplicatedMovementModeField() { return { this, "ACharacter.ReplicatedMovementMode" }; }
	FieldValue<float> LeftDynamicActorBaseTimeField() { return { this, "ACharacter.LeftDynamicActorBaseTime" }; }
	FieldValue<float> CrouchedEyeHeightField() { return { this, "ACharacter.CrouchedEyeHeight" }; }
	FieldValue<float> ProneEyeHeightField() { return { this, "ACharacter.ProneEyeHeight" }; }
	FieldValue<TArray<USoundBase *>> CharacterOverrideSoundFromField() { return { this, "ACharacter.CharacterOverrideSoundFrom" }; }
	FieldValue<TArray<USoundBase *>> CharacterOverrideSoundToField() { return { this, "ACharacter.CharacterOverrideSoundTo" }; }
	FieldValue<bool> bInBaseReplicationField() { return { this, "ACharacter.bInBaseReplication" }; }
	FieldValue<float> JumpKeyHoldTimeField() { return { this, "ACharacter.JumpKeyHoldTime" }; }
	FieldValue<float> JumpMaxHoldTimeField() { return { this, "ACharacter.JumpMaxHoldTime" }; }
	FieldValue<int> LastTeleportedFrameField() { return { this, "ACharacter.LastTeleportedFrame" }; }
	FieldValue<long double> ForceUnfreezeSkeletalDynamicsUntilTimeField() { return { this, "ACharacter.ForceUnfreezeSkeletalDynamicsUntilTime" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsCrouched() { return { this, "ACharacter.bIsCrouched" }; }
	BitFieldValue<bool, unsigned __int32> bIsProne() { return { this, "ACharacter.bIsProne" }; }
	BitFieldValue<bool, unsigned __int32> bCanEverProne() { return { this, "ACharacter.bCanEverProne" }; }
	BitFieldValue<bool, unsigned __int32> bCanEverCrouch() { return { this, "ACharacter.bCanEverCrouch" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateDesiredRotation() { return { this, "ACharacter.bReplicateDesiredRotation" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideCharacterSound() { return { this, "ACharacter.bUseBPOverrideCharacterSound" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideCharacterParticle() { return { this, "ACharacter.bUseBPOverrideCharacterParticle" }; }
	BitFieldValue<bool, unsigned __int32> bPressedJump() { return { this, "ACharacter.bPressedJump" }; }
	BitFieldValue<bool, unsigned __int32> bClientUpdating() { return { this, "ACharacter.bClientUpdating" }; }
	BitFieldValue<bool, unsigned __int32> bIsPlayingTurningAnim() { return { this, "ACharacter.bIsPlayingTurningAnim" }; }
	BitFieldValue<bool, unsigned __int32> bClientWasFalling() { return { this, "ACharacter.bClientWasFalling" }; }
	BitFieldValue<bool, unsigned __int32> bClientResimulateRootMotion() { return { this, "ACharacter.bClientResimulateRootMotion" }; }
	BitFieldValue<bool, unsigned __int32> bSimGravityDisabled() { return { this, "ACharacter.bSimGravityDisabled" }; }
	BitFieldValue<bool, unsigned __int32> bIsBigPusher() { return { this, "ACharacter.bIsBigPusher" }; }
	BitFieldValue<bool, unsigned __int32> bCanBePushed() { return { this, "ACharacter.bCanBePushed" }; }
	BitFieldValue<bool, unsigned __int32> bCanPushOthers() { return { this, "ACharacter.bCanPushOthers" }; }
	BitFieldValue<bool, unsigned __int32> bSetDefaultMovementMode() { return { this, "ACharacter.bSetDefaultMovementMode" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideNewFallVelocity() { return { this, "ACharacter.bOverrideNewFallVelocity" }; }

	// Functions

	void SetLastMovementDesiredRotation(FRotator * InRotation) { NativeCall<void, FRotator *>(this, "ACharacter.SetLastMovementDesiredRotation", InRotation); }
	bool NotifyLanded(FHitResult * Hit) { return NativeCall<bool, FHitResult *>(this, "ACharacter.NotifyLanded", Hit); }
	bool IsJumping() { return NativeCall<bool>(this, "ACharacter.IsJumping"); }
	UPrimitiveComponent * GetMovementBase() { return NativeCall<UPrimitiveComponent *>(this, "ACharacter.GetMovementBase"); }
	void PostInitializeComponents() { NativeCall<void>(this, "ACharacter.PostInitializeComponents"); }
	void GetSimpleCollisionCylinder(float * CollisionRadius, float * CollisionHalfHeight) { NativeCall<void, float *, float *>(this, "ACharacter.GetSimpleCollisionCylinder", CollisionRadius, CollisionHalfHeight); }
	void ApplyWorldOffset(FVector * InOffset, bool bWorldShift) { NativeCall<void, FVector *, bool>(this, "ACharacter.ApplyWorldOffset", InOffset, bWorldShift); }
	float GetDefaultHalfHeight() { return NativeCall<float>(this, "ACharacter.GetDefaultHalfHeight"); }
	UActorComponent * FindComponentByClass(TSubclassOf<UActorComponent> ComponentClass) { return NativeCall<UActorComponent *, TSubclassOf<UActorComponent>>(this, "ACharacter.FindComponentByClass", ComponentClass); }
	void Landed(FHitResult * Hit) { NativeCall<void, FHitResult *>(this, "ACharacter.Landed", Hit); }
	bool CanJump() { return NativeCall<bool>(this, "ACharacter.CanJump"); }
	bool CanJumpInternal_Implementation() { return NativeCall<bool>(this, "ACharacter.CanJumpInternal_Implementation"); }
	bool DoJump(bool bReplayingMoves) { return NativeCall<bool, bool>(this, "ACharacter.DoJump", bReplayingMoves); }
	void RecalculateBaseEyeHeight() { NativeCall<void>(this, "ACharacter.RecalculateBaseEyeHeight"); }
	void OnRep_IsCrouched() { NativeCall<void>(this, "ACharacter.OnRep_IsCrouched"); }
	void OnRep_IsProne() { NativeCall<void>(this, "ACharacter.OnRep_IsProne"); }
	bool CanCrouch() { return NativeCall<bool>(this, "ACharacter.CanCrouch"); }
	void Crouch(bool bClientSimulation) { NativeCall<void, bool>(this, "ACharacter.Crouch", bClientSimulation); }
	void UnCrouch(bool bClientSimulation) { NativeCall<void, bool>(this, "ACharacter.UnCrouch", bClientSimulation); }
	bool CanProne() { return NativeCall<bool>(this, "ACharacter.CanProne"); }
	void Prone(bool bClientSimulation) { NativeCall<void, bool>(this, "ACharacter.Prone", bClientSimulation); }
	void UnProne(bool bClientSimulation) { NativeCall<void, bool>(this, "ACharacter.UnProne", bClientSimulation); }
	void OnEndCrouch(float HeightAdjust, float ScaledHeightAdjust) { NativeCall<void, float, float>(this, "ACharacter.OnEndCrouch", HeightAdjust, ScaledHeightAdjust); }
	void OnStartCrouch(float HeightAdjust, float ScaledHeightAdjust) { NativeCall<void, float, float>(this, "ACharacter.OnStartCrouch", HeightAdjust, ScaledHeightAdjust); }
	void ApplyDamageMomentum(float DamageTaken, FDamageEvent * DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "ACharacter.ApplyDamageMomentum", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	void TeleportSucceeded(bool bIsATest, bool bSimpleTeleport) { NativeCall<void, bool, bool>(this, "ACharacter.TeleportSucceeded", bIsATest, bSimpleTeleport); }
	void NetTeleportSucceeded_Implementation(FVector ToLoc, FRotator ToRot) { NativeCall<void, FVector, FRotator>(this, "ACharacter.NetTeleportSucceeded_Implementation", ToLoc, ToRot); }
	void ClearCrossLevelReferences() { NativeCall<void>(this, "ACharacter.ClearCrossLevelReferences"); }
	void SetBase(UPrimitiveComponent * NewBaseComponent, FName BoneName, bool bNotifyPawn) { NativeCall<void, UPrimitiveComponent *, FName, bool>(this, "ACharacter.SetBase", NewBaseComponent, BoneName, bNotifyPawn); }
	bool IsBasedOnDynamicActor() { return NativeCall<bool>(this, "ACharacter.IsBasedOnDynamicActor"); }
	void TurnOff() { NativeCall<void>(this, "ACharacter.TurnOff"); }
	void Restart() { NativeCall<void>(this, "ACharacter.Restart"); }
	void PawnClientRestart() { NativeCall<void>(this, "ACharacter.PawnClientRestart"); }
	void PossessedBy(AController * NewController) { NativeCall<void, AController *>(this, "ACharacter.PossessedBy", NewController); }
	void UnPossessed() { NativeCall<void>(this, "ACharacter.UnPossessed"); }
	void TornOff() { NativeCall<void>(this, "ACharacter.TornOff"); }
	void BaseChange() { NativeCall<void>(this, "ACharacter.BaseChange"); }
	void LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride) { NativeCall<void, FVector, bool, bool>(this, "ACharacter.LaunchCharacter", LaunchVelocity, bXYOverride, bZOverride); }
	void OnMovementModeChanged(EMovementMode PrevMovementMode, char PrevCustomMode) { NativeCall<void, EMovementMode, char>(this, "ACharacter.OnMovementModeChanged", PrevMovementMode, PrevCustomMode); }
	bool ShouldNotifyLanded(FHitResult * Hit) { return NativeCall<bool, FHitResult *>(this, "ACharacter.ShouldNotifyLanded", Hit); }
	void Jump() { NativeCall<void>(this, "ACharacter.Jump"); }
	void StopJumping() { NativeCall<void>(this, "ACharacter.StopJumping"); }
	void CheckJumpInput(float DeltaTime) { NativeCall<void, float>(this, "ACharacter.CheckJumpInput", DeltaTime); }
	void ClearJumpInput() { NativeCall<void>(this, "ACharacter.ClearJumpInput"); }
	float GetJumpMaxHoldTime() { return NativeCall<float>(this, "ACharacter.GetJumpMaxHoldTime"); }
	void PreNetReceive() { NativeCall<void>(this, "ACharacter.PreNetReceive"); }
	void PostNetReceive() { NativeCall<void>(this, "ACharacter.PostNetReceive"); }
	void OnRep_ReplicatedBasedMovement() { NativeCall<void>(this, "ACharacter.OnRep_ReplicatedBasedMovement"); }
	void OnRep_ReplicatedMovement() { NativeCall<void>(this, "ACharacter.OnRep_ReplicatedMovement"); }
	void OnRep_RootMotion() { NativeCall<void>(this, "ACharacter.OnRep_RootMotion"); }
	void SimulatedRootMotionPositionFixup(float DeltaSeconds) { NativeCall<void, float>(this, "ACharacter.SimulatedRootMotionPositionFixup", DeltaSeconds); }
	void UpdateSimulatedPosition(FVector * NewLocation, FRotator * NewRotation) { NativeCall<void, FVector *, FRotator *>(this, "ACharacter.UpdateSimulatedPosition", NewLocation, NewRotation); }
	void PostNetReceiveLocationAndRotation() { NativeCall<void>(this, "ACharacter.PostNetReceiveLocationAndRotation"); }
	bool TeleportTo(FVector * DestLocation, FRotator * DestRotation, bool bIsATest, bool bNoCheck) { return NativeCall<bool, FVector *, FRotator *, bool, bool>(this, "ACharacter.TeleportTo", DestLocation, DestRotation, bIsATest, bNoCheck); }
	bool SimpleTeleportTo(FVector * DestLocation, FRotator * DestRotation) { return NativeCall<bool, FVector *, FRotator *>(this, "ACharacter.SimpleTeleportTo", DestLocation, DestRotation); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "ACharacter.GetLifetimeReplicatedProps", OutLifetimeProps); }
	bool IsPlayingRootMotion() { return NativeCall<bool>(this, "ACharacter.IsPlayingRootMotion"); }
	USoundBase * BPOverrideCharacterSound_Implementation(USoundBase * SoundIn) { return NativeCall<USoundBase *, USoundBase *>(this, "ACharacter.BPOverrideCharacterSound_Implementation", SoundIn); }
	float PlayAnimMontage(UAnimMontage * AnimMontage, float InPlayRate, FName StartSectionName, bool bForceTickPoseAndServerUpdateMesh, bool bForceTickPoseOnServer) { return NativeCall<float, UAnimMontage *, float, FName, bool, bool>(this, "ACharacter.PlayAnimMontage", AnimMontage, InPlayRate, StartSectionName, bForceTickPoseAndServerUpdateMesh, bForceTickPoseOnServer); }
	void StopAnimMontage(UAnimMontage * AnimMontage) { NativeCall<void, UAnimMontage *>(this, "ACharacter.StopAnimMontage", AnimMontage); }
	UAnimMontage * GetCurrentMontage() { return NativeCall<UAnimMontage *>(this, "ACharacter.GetCurrentMontage"); }
	void ClientCheatWalk_Implementation() { NativeCall<void>(this, "ACharacter.ClientCheatWalk_Implementation"); }
	void ClientCheatFly_Implementation() { NativeCall<void>(this, "ACharacter.ClientCheatFly_Implementation"); }
	void ClientCheatGhost_Implementation() { NativeCall<void>(this, "ACharacter.ClientCheatGhost_Implementation"); }
	bool ShouldReplicateRotPitch() { return NativeCall<bool>(this, "ACharacter.ShouldReplicateRotPitch"); }
	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "ACharacter.GetPrivateStaticClass"); }
	void K2_OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) { NativeCall<void, float, float>(this, "ACharacter.K2_OnEndCrouch", HalfHeightAdjust, ScaledHalfHeightAdjust); }
	void K2_OnMovementModeChanged(EMovementMode PrevMovementMode, EMovementMode NewMovementMode, char PrevCustomMode, char NewCustomMode) { NativeCall<void, EMovementMode, EMovementMode, char, char>(this, "ACharacter.K2_OnMovementModeChanged", PrevMovementMode, NewMovementMode, PrevCustomMode, NewCustomMode); }
	void K2_OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) { NativeCall<void, float, float>(this, "ACharacter.K2_OnStartCrouch", HalfHeightAdjust, ScaledHalfHeightAdjust); }
	void K2_UpdateCustomMovement(float DeltaTime) { NativeCall<void, float>(this, "ACharacter.K2_UpdateCustomMovement", DeltaTime); }
	void OnJumped() { NativeCall<void>(this, "ACharacter.OnJumped"); }
	void OnLanded(FHitResult * Hit) { NativeCall<void, FHitResult *>(this, "ACharacter.OnLanded", Hit); }
	void OnLaunched(FVector LaunchVelocity, bool bXYOverride, bool bZOverride) { NativeCall<void, FVector, bool, bool>(this, "ACharacter.OnLaunched", LaunchVelocity, bXYOverride, bZOverride); }
	void OnWalkingOffLedge() { NativeCall<void>(this, "ACharacter.OnWalkingOffLedge"); }
};

struct APrimalCharacter : ACharacter
{
	FieldValue<FVector> OldLocationField() { return { this, "APrimalCharacter.OldLocation" }; }
	FieldValue<FRotator> OldRotationField() { return { this, "APrimalCharacter.OldRotation" }; }
	FieldValue<float> EffectorInterpSpeedField() { return { this, "APrimalCharacter.EffectorInterpSpeed" }; }
	FieldValue<float> HalfLegLengthField() { return { this, "APrimalCharacter.HalfLegLength" }; }
	FieldValue<float> TwoLeggedVirtualPointDistFactorField() { return { this, "APrimalCharacter.TwoLeggedVirtualPointDistFactor" }; }
	FieldValue<float> FullIKDistanceField() { return { this, "APrimalCharacter.FullIKDistance" }; }
	FieldValue<float> SimpleIkRateField() { return { this, "APrimalCharacter.SimpleIkRate" }; }
	FieldValue<FVector> GroundCheckExtentField() { return { this, "APrimalCharacter.GroundCheckExtent" }; }
	FieldValue<long double> LastForceAimedCharactersTimeField() { return { this, "APrimalCharacter.LastForceAimedCharactersTime" }; }
	FieldValue<UAnimMontage *> JumpAnimField() { return { this, "APrimalCharacter.JumpAnim" }; }
	FieldValue<UAnimMontage *> LandedAnimField() { return { this, "APrimalCharacter.LandedAnim" }; }
	FieldValue<UAnimMontage *> HurtAnimField() { return { this, "APrimalCharacter.HurtAnim" }; }
	FieldValue<UAnimMontage *> PinnedAnimField() { return { this, "APrimalCharacter.PinnedAnim" }; }
	FieldValue<USoundCue *> HurtSoundField() { return { this, "APrimalCharacter.HurtSound" }; }
	FieldValue<FName> RootBodyBoneNameField() { return { this, "APrimalCharacter.RootBodyBoneName" }; }
	FieldValue<TArray<APrimalBuff *>> BuffsField() { return { this, "APrimalCharacter.Buffs" }; }
	FieldValue<FString> TribeNameField() { return { this, "APrimalCharacter.TribeName" }; }
	FieldValue<float> WaterSubmergedDepthThresholdField() { return { this, "APrimalCharacter.WaterSubmergedDepthThreshold" }; }
	FieldValue<float> ProneWaterSubmergedDepthThresholdField() { return { this, "APrimalCharacter.ProneWaterSubmergedDepthThreshold" }; }
	FieldValue<TEnumAsByte<enum EMovementMode>> SubmergedWaterMovementModeField() { return { this, "APrimalCharacter.SubmergedWaterMovementMode" }; }
	FieldValue<TEnumAsByte<enum EMovementMode>> UnSubmergedWaterMovementModeField() { return { this, "APrimalCharacter.UnSubmergedWaterMovementMode" }; }
	FieldValue<TSubclassOf<UPrimalItem>> PoopItemClassField() { return { this, "APrimalCharacter.PoopItemClass" }; }
	FieldValue<FName> DragBoneNameField() { return { this, "APrimalCharacter.DragBoneName" }; }
	FieldValue<FName> DragSocketNameField() { return { this, "APrimalCharacter.DragSocketName" }; }
	FieldValue<float> MaxDragDistanceField() { return { this, "APrimalCharacter.MaxDragDistance" }; }
	FieldValue<float> MaxDragDistanceTimeoutField() { return { this, "APrimalCharacter.MaxDragDistanceTimeout" }; }
	FieldValue<TArray<FName>> BonesToIngoreWhileDraggedField() { return { this, "APrimalCharacter.BonesToIngoreWhileDragged" }; }
	FieldValue<float> PreviewCameraMaxZoomMultiplierField() { return { this, "APrimalCharacter.PreviewCameraMaxZoomMultiplier" }; }
	FieldValue<float> PreviewCameraDefaultZoomMultiplierField() { return { this, "APrimalCharacter.PreviewCameraDefaultZoomMultiplier" }; }
	FieldValue<float> PreviewCameraDistanceScaleFactorField() { return { this, "APrimalCharacter.PreviewCameraDistanceScaleFactor" }; }
	FieldValue<USoundBase *> StartDraggedSoundField() { return { this, "APrimalCharacter.StartDraggedSound" }; }
	FieldValue<USoundBase *> EndDraggedSoundField() { return { this, "APrimalCharacter.EndDraggedSound" }; }
	FieldValue<APrimalCharacter *> DraggedCharacterField() { return { this, "APrimalCharacter.DraggedCharacter" }; }
	FieldValue<APrimalCharacter *> DraggingCharacterField() { return { this, "APrimalCharacter.DraggingCharacter" }; }
	FieldValue<FTransform> LocalDraggedCharacterTransformField() { return { this, "APrimalCharacter.LocalDraggedCharacterTransform" }; }
	FieldValue<long double> StartDraggingTimeField() { return { this, "APrimalCharacter.StartDraggingTime" }; }
	FieldValue<long double> LastDragUpdateTimeField() { return { this, "APrimalCharacter.LastDragUpdateTime" }; }
	FieldValue<AActor *> ImmobilizationActorField() { return { this, "APrimalCharacter.ImmobilizationActor" }; }
	FieldValue<int> CurrentFrameAnimPreventInputField() { return { this, "APrimalCharacter.CurrentFrameAnimPreventInput" }; }
	FieldValue<float> BPTimerServerMinField() { return { this, "APrimalCharacter.BPTimerServerMin" }; }
	FieldValue<float> BPTimerServerMaxField() { return { this, "APrimalCharacter.BPTimerServerMax" }; }
	FieldValue<float> BPTimerNonDedicatedMinField() { return { this, "APrimalCharacter.BPTimerNonDedicatedMin" }; }
	FieldValue<float> BPTimerNonDedicatedMaxField() { return { this, "APrimalCharacter.BPTimerNonDedicatedMax" }; }
	FieldValue<long double> NextBPTimerServerField() { return { this, "APrimalCharacter.NextBPTimerServer" }; }
	FieldValue<long double> NextBPTimerNonDedicatedField() { return { this, "APrimalCharacter.NextBPTimerNonDedicated" }; }
	FieldValue<TArray<TSubclassOf<APrimalStructure>>> ImmobilizationTrapsToIgnoreField() { return { this, "APrimalCharacter.ImmobilizationTrapsToIgnore" }; }
	FieldValue<TWeakObjectPtr<APrimalDinoCharacter>> CarryingDinoField() { return { this, "APrimalCharacter.CarryingDino" }; }
	FieldValue<FName> DediOverrideCapsuleCollisionProfileNameField() { return { this, "APrimalCharacter.DediOverrideCapsuleCollisionProfileName" }; }
	FieldValue<FName> DediOverrideMeshCollisionProfileNameField() { return { this, "APrimalCharacter.DediOverrideMeshCollisionProfileName" }; }
	FieldValue<FName> SnaredFromSocketField() { return { this, "APrimalCharacter.SnaredFromSocket" }; }
	FieldValue<TSubclassOf<APrimalStructureItemContainer>> DeathDestructionDepositInventoryClassField() { return { this, "APrimalCharacter.DeathDestructionDepositInventoryClass" }; }
	FieldValue<float> DamageNotifyTeamAggroMultiplierField() { return { this, "APrimalCharacter.DamageNotifyTeamAggroMultiplier" }; }
	FieldValue<float> DamageNotifyTeamAggroRangeField() { return { this, "APrimalCharacter.DamageNotifyTeamAggroRange" }; }
	FieldValue<float> DamageNotifyTeamAggroRangeFalloffField() { return { this, "APrimalCharacter.DamageNotifyTeamAggroRangeFalloff" }; }
	FieldValue<float> ReplicatedCurrentHealthField() { return { this, "APrimalCharacter.ReplicatedCurrentHealth" }; }
	FieldValue<float> ReplicatedMaxHealthField() { return { this, "APrimalCharacter.ReplicatedMaxHealth" }; }
	FieldValue<float> ReplicatedCurrentTorporField() { return { this, "APrimalCharacter.ReplicatedCurrentTorpor" }; }
	FieldValue<float> ReplicatedMaxTorporField() { return { this, "APrimalCharacter.ReplicatedMaxTorpor" }; }
	FieldValue<FVector> DragOffsetField() { return { this, "APrimalCharacter.DragOffset" }; }
	FieldValue<AShooterCharacter *> LastGrapHookPullingOwnerField() { return { this, "APrimalCharacter.LastGrapHookPullingOwner" }; }
	FieldValue<long double> LastIkUpdateTimeField() { return { this, "APrimalCharacter.LastIkUpdateTime" }; }
	FieldValue<long double> LastUpdatedAimOffsetsTimeField() { return { this, "APrimalCharacter.LastUpdatedAimOffsetsTime" }; }
	FieldValue<FVector> MeshPreRagdollRelativeLocationField() { return { this, "APrimalCharacter.MeshPreRagdollRelativeLocation" }; }
	FieldValue<FRotator> MeshPreRagdollRelativeRotationField() { return { this, "APrimalCharacter.MeshPreRagdollRelativeRotation" }; }
	FieldValue<int> DraggingBodyIndexField() { return { this, "APrimalCharacter.DraggingBodyIndex" }; }
	FieldValue<int> DraggedBoneIndexField() { return { this, "APrimalCharacter.DraggedBoneIndex" }; }
	FieldValue<int> customBitFlagsField() { return { this, "APrimalCharacter.customBitFlags" }; }
	FieldValue<float> RunningSpeedModifierField() { return { this, "APrimalCharacter.RunningSpeedModifier" }; }
	FieldValue<float> LowHealthPercentageField() { return { this, "APrimalCharacter.LowHealthPercentage" }; }
	FieldValue<float> BaseTurnRateField() { return { this, "APrimalCharacter.BaseTurnRate" }; }
	FieldValue<float> BaseLookUpRateField() { return { this, "APrimalCharacter.BaseLookUpRate" }; }
	FieldValue<UAnimMontage *> DeathAnimField() { return { this, "APrimalCharacter.DeathAnim" }; }
	FieldValue<USoundCue *> DeathSoundField() { return { this, "APrimalCharacter.DeathSound" }; }
	FieldValue<USoundCue *> RunLoopSoundField() { return { this, "APrimalCharacter.RunLoopSound" }; }
	FieldValue<USoundCue *> RunStopSoundField() { return { this, "APrimalCharacter.RunStopSound" }; }
	FieldValue<TArray<USoundCue *>> FootStepSoundsPhysMatField() { return { this, "APrimalCharacter.FootStepSoundsPhysMat" }; }
	FieldValue<TArray<USoundCue *>> LandedSoundsPhysMatField() { return { this, "APrimalCharacter.LandedSoundsPhysMat" }; }
	FieldValue<FName> MeshRootSocketNameField() { return { this, "APrimalCharacter.MeshRootSocketName" }; }
	FieldValue<TWeakObjectPtr<UAudioComponent>> LastVoiceAudioComponentField() { return { this, "APrimalCharacter.LastVoiceAudioComponent" }; }
	FieldValue<float> MaxFallSpeedField() { return { this, "APrimalCharacter.MaxFallSpeed" }; }
	FieldValue<float> FallDamageMultiplierField() { return { this, "APrimalCharacter.FallDamageMultiplier" }; }
	FieldValue<UAudioComponent *> RunLoopACField() { return { this, "APrimalCharacter.RunLoopAC" }; }
	FieldValue<float> CurrentCarriedYawField() { return { this, "APrimalCharacter.CurrentCarriedYaw" }; }
	FieldValue<APrimalStructureExplosiveTransGPS *> CurrentTransponderField() { return { this, "APrimalCharacter.CurrentTransponder" }; }
	FieldValue<float> TargetCarriedYawField() { return { this, "APrimalCharacter.TargetCarriedYaw" }; }
	FieldValue<float> ServerTargetCarriedYawField() { return { this, "APrimalCharacter.ServerTargetCarriedYaw" }; }
	FieldValue<USoundBase *> NetDynamicMusicSoundField() { return { this, "APrimalCharacter.NetDynamicMusicSound" }; }
	FieldValue<TWeakObjectPtr<APrimalDinoCharacter>> MountedDinoField() { return { this, "APrimalCharacter.MountedDino" }; }
	FieldValue<float> MountedDinoTimeField() { return { this, "APrimalCharacter.MountedDinoTime" }; }
	FieldValue<TWeakObjectPtr<APrimalDinoCharacter>> PreviousMountedDinoField() { return { this, "APrimalCharacter.PreviousMountedDino" }; }
	FieldValue<FVector> LastForceFallCheckBaseLocationField() { return { this, "APrimalCharacter.LastForceFallCheckBaseLocation" }; }
	FieldValue<FVector> LastHitWallSweepCheckLocationField() { return { this, "APrimalCharacter.LastHitWallSweepCheckLocation" }; }
	FieldValue<long double> LastTimeBasedMovementHadCurrentActorField() { return { this, "APrimalCharacter.LastTimeBasedMovementHadCurrentActor" }; }
	FieldValue<TWeakObjectPtr<AActor>> LastBasedMovementActorRefField() { return { this, "APrimalCharacter.LastBasedMovementActorRef" }; }
	FieldValue<float> GrabWeightThresholdField() { return { this, "APrimalCharacter.GrabWeightThreshold" }; }
	FieldValue<float> DragWeightField() { return { this, "APrimalCharacter.DragWeight" }; }
	FieldValue<FString> DescriptiveNameField() { return { this, "APrimalCharacter.DescriptiveName" }; }
	FieldValue<TArray<FVector_NetQuantize>> ReplicatedRagdollPositionsField() { return { this, "APrimalCharacter.ReplicatedRagdollPositions" }; }
	FieldValue<TArray<FRotator_NetQuantize>> ReplicatedRagdollRotationsField() { return { this, "APrimalCharacter.ReplicatedRagdollRotations" }; }
	FieldValue<TArray<FVector_NetQuantize>> LastReplicatedRagdollPositionsField() { return { this, "APrimalCharacter.LastReplicatedRagdollPositions" }; }
	FieldValue<TArray<FRotator_NetQuantize>> LastReplicatedRagdollRotationsField() { return { this, "APrimalCharacter.LastReplicatedRagdollRotations" }; }
	FieldValue<FRotator> ReplicatedRootRotationField() { return { this, "APrimalCharacter.ReplicatedRootRotation" }; }
	FieldValue<TArray<int>> ReplicatedBonesIndiciesField() { return { this, "APrimalCharacter.ReplicatedBonesIndicies" }; }
	FieldValue<float> KillXPBaseField() { return { this, "APrimalCharacter.KillXPBase" }; }
	FieldValue<TArray<FName>> ReplicatedBonesField() { return { this, "APrimalCharacter.ReplicatedBones" }; }
	FieldValue<float> RagdollReplicationIntervalField() { return { this, "APrimalCharacter.RagdollReplicationInterval" }; }
	FieldValue<float> ClientRotationInterpSpeedField() { return { this, "APrimalCharacter.ClientRotationInterpSpeed" }; }
	FieldValue<float> ClientLocationInterpSpeedField() { return { this, "APrimalCharacter.ClientLocationInterpSpeed" }; }
	FieldValue<float> MaxDragMovementSpeedField() { return { this, "APrimalCharacter.MaxDragMovementSpeed" }; }
	FieldValue<FRotator> CurrentAimRotField() { return { this, "APrimalCharacter.CurrentAimRot" }; }
	FieldValue<FVector> CurrentRootLocField() { return { this, "APrimalCharacter.CurrentRootLoc" }; }
	FieldValue<int> LastYawSpeedWorldFrameCounterField() { return { this, "APrimalCharacter.LastYawSpeedWorldFrameCounter" }; }
	FieldValue<FName> MeshPreRagdollCollisionProfileNameField() { return { this, "APrimalCharacter.MeshPreRagdollCollisionProfileName" }; }
	FieldValue<FName> CapsulePreRagdollCollisionProfileNameField() { return { this, "APrimalCharacter.CapsulePreRagdollCollisionProfileName" }; }
	FieldValue<UPrimalCharacterStatusComponent *> MyCharacterStatusComponentField() { return { this, "APrimalCharacter.MyCharacterStatusComponent" }; }
	FieldValue<UPrimalInventoryComponent *> MyInventoryComponentField() { return { this, "APrimalCharacter.MyInventoryComponent" }; }
	FieldValue<long double> LastRunningTimeField() { return { this, "APrimalCharacter.LastRunningTime" }; }
	FieldValue<FVector> TPVCameraOffsetField() { return { this, "APrimalCharacter.TPVCameraOffset" }; }
	FieldValue<FVector> TPVCameraOffsetMultiplierField() { return { this, "APrimalCharacter.TPVCameraOffsetMultiplier" }; }
	FieldValue<FVector> TPVCameraOrgOffsetField() { return { this, "APrimalCharacter.TPVCameraOrgOffset" }; }
	FieldValue<float> LandedSoundMaxRangeField() { return { this, "APrimalCharacter.LandedSoundMaxRange" }; }
	FieldValue<float> FallingDamageHealthScaleBaseField() { return { this, "APrimalCharacter.FallingDamageHealthScaleBase" }; }
	FieldValue<float> FootstepsMaxRangeField() { return { this, "APrimalCharacter.FootstepsMaxRange" }; }
	FieldValue<float> MinTimeBetweenFootstepsField() { return { this, "APrimalCharacter.MinTimeBetweenFootsteps" }; }
	FieldValue<long double> LastPlayedFootstepTimeField() { return { this, "APrimalCharacter.LastPlayedFootstepTime" }; }
	FieldValue<float> MinTimeBetweenFootstepsRunningField() { return { this, "APrimalCharacter.MinTimeBetweenFootstepsRunning" }; }
	FieldValue<TArray<UAnimMontage *>> AnimationsPreventInputField() { return { this, "APrimalCharacter.AnimationsPreventInput" }; }
	FieldValue<long double> LastNetDidLandField() { return { this, "APrimalCharacter.LastNetDidLand" }; }
	FieldValue<TWeakObjectPtr<AController>> LastDamageEventInstigatorField() { return { this, "APrimalCharacter.LastDamageEventInstigator" }; }
	FieldValue<int> CachedNumberOfClientRagdollCorrectionAttemptsField() { return { this, "APrimalCharacter.CachedNumberOfClientRagdollCorrectionAttempts" }; }
	FieldValue<int> NumberOfClientRagdollCorrectionAttemptsField() { return { this, "APrimalCharacter.NumberOfClientRagdollCorrectionAttempts" }; }
	FieldValue<float> ServerForceSleepRagdollIntervalField() { return { this, "APrimalCharacter.ServerForceSleepRagdollInterval" }; }
	FieldValue<float> ClientForceSleepRagdollIntervalField() { return { this, "APrimalCharacter.ClientForceSleepRagdollInterval" }; }
	FieldValue<float> NonRelevantServerForceSleepRagdollIntervalField() { return { this, "APrimalCharacter.NonRelevantServerForceSleepRagdollInterval" }; }
	FieldValue<TEnumAsByte<enum EShooterPhysMaterialType::Type>> TargetableDamageFXDefaultPhysMaterialField() { return { this, "APrimalCharacter.TargetableDamageFXDefaultPhysMaterial" }; }
	FieldValue<UAnimMontage *> PoopAnimationField() { return { this, "APrimalCharacter.PoopAnimation" }; }
	FieldValue<long double> CorpseDestructionTimeField() { return { this, "APrimalCharacter.CorpseDestructionTime" }; }
	FieldValue<float> CorpseLifespanField() { return { this, "APrimalCharacter.CorpseLifespan" }; }
	FieldValue<float> TPVStructurePlacingHeightMultiplierField() { return { this, "APrimalCharacter.TPVStructurePlacingHeightMultiplier" }; }
	FieldValue<float> CorpseFadeAwayTimeField() { return { this, "APrimalCharacter.CorpseFadeAwayTime" }; }
	FieldValue<float> RagdollDeathImpulseScalerField() { return { this, "APrimalCharacter.RagdollDeathImpulseScaler" }; }
	FieldValue<USoundCue *> PoopSoundField() { return { this, "APrimalCharacter.PoopSound" }; }
	FieldValue<float> BaseTargetingDesirabilityField() { return { this, "APrimalCharacter.BaseTargetingDesirability" }; }
	FieldValue<float> DeadBaseTargetingDesirabilityField() { return { this, "APrimalCharacter.DeadBaseTargetingDesirability" }; }
	FieldValue<FRotator> OrbitCamRotField() { return { this, "APrimalCharacter.OrbitCamRot" }; }
	FieldValue<float> OrbitCamZoomField() { return { this, "APrimalCharacter.OrbitCamZoom" }; }
	FieldValue<FVector> LastSubmergedCheckLocField() { return { this, "APrimalCharacter.LastSubmergedCheckLoc" }; }
	FieldValue<long double> LastTimeNotInFallingField() { return { this, "APrimalCharacter.LastTimeNotInFalling" }; }
	FieldValue<float> MaxCursorHUDDistanceField() { return { this, "APrimalCharacter.MaxCursorHUDDistance" }; }
	FieldValue<float> AddForwardVelocityOnJumpField() { return { this, "APrimalCharacter.AddForwardVelocityOnJump" }; }
	FieldValue<FVector> DeathActorTargetingOffsetField() { return { this, "APrimalCharacter.DeathActorTargetingOffset" }; }
	FieldValue<FName> SocketOverrideTargetingLocationField() { return { this, "APrimalCharacter.SocketOverrideTargetingLocation" }; }
	FieldValue<FDamageEvent *> CurrentDamageEventField() { return { this, "APrimalCharacter.CurrentDamageEvent" }; }
	FieldValue<FVector> LastApproximatePhysVolumeLocationField() { return { this, "APrimalCharacter.LastApproximatePhysVolumeLocation" }; }
	FieldValue<long double> LastTimeSubmergedField() { return { this, "APrimalCharacter.LastTimeSubmerged" }; }
	FieldValue<EPhysicalSurface> LastFootPhysicalSurfaceTypeField() { return { this, "APrimalCharacter.LastFootPhysicalSurfaceType" }; }
	FieldValue<long double> LastFootPhysicalSurfaceCheckTimeField() { return { this, "APrimalCharacter.LastFootPhysicalSurfaceCheckTime" }; }
	FieldValue<float> FootPhysicalSurfaceCheckIntervalField() { return { this, "APrimalCharacter.FootPhysicalSurfaceCheckInterval" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> LastHurtByNearbyPlayerField() { return { this, "APrimalCharacter.LastHurtByNearbyPlayer" }; }
	FieldValue<float> LastHurtByNearbyPlayerTimeField() { return { this, "APrimalCharacter.LastHurtByNearbyPlayerTime" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> LastAttackedNearbyPlayerField() { return { this, "APrimalCharacter.LastAttackedNearbyPlayer" }; }
	FieldValue<float> LastAttackedNearbyPlayerTimeField() { return { this, "APrimalCharacter.LastAttackedNearbyPlayerTime" }; }
	FieldValue<long double> LastStartFallingRagdollTimeField() { return { this, "APrimalCharacter.LastStartFallingRagdollTime" }; }
	FieldValue<FVector> RagdollLastFrameLinearVelocityField() { return { this, "APrimalCharacter.RagdollLastFrameLinearVelocity" }; }
	FieldValue<float> RagdollImpactDamageVelocityScaleField() { return { this, "APrimalCharacter.RagdollImpactDamageVelocityScale" }; }
	FieldValue<float> RagdollImpactDamageMinDecelerationSpeedField() { return { this, "APrimalCharacter.RagdollImpactDamageMinDecelerationSpeed" }; }
	FieldValue<float> StartFallingImpactRagdollTimeIntervalField() { return { this, "APrimalCharacter.StartFallingImpactRagdollTimeInterval" }; }
	FieldValue<long double> LastUnstasisTimeField() { return { this, "APrimalCharacter.LastUnstasisTime" }; }
	FieldValue<FVector> PreviousRagdollLocationField() { return { this, "APrimalCharacter.PreviousRagdollLocation" }; }
	FieldValue<int> RagdollPenetrationFailuresField() { return { this, "APrimalCharacter.RagdollPenetrationFailures" }; }
	FieldValue<long double> NextBlinkTimeField() { return { this, "APrimalCharacter.NextBlinkTime" }; }
	FieldValue<long double> BlinkTimerField() { return { this, "APrimalCharacter.BlinkTimer" }; }
	FieldValue<long double> LastInSwimmingSoundTimeField() { return { this, "APrimalCharacter.LastInSwimmingSoundTime" }; }
	FieldValue<USoundCue *> EnteredSwimmingSoundField() { return { this, "APrimalCharacter.EnteredSwimmingSound" }; }
	FieldValue<USoundCue *> EnteredSleepingSoundField() { return { this, "APrimalCharacter.EnteredSleepingSound" }; }
	FieldValue<USoundCue *> LeftSleepingSoundField() { return { this, "APrimalCharacter.LeftSleepingSound" }; }
	FieldValue<long double> LastRelevantToPlayerTimeField() { return { this, "APrimalCharacter.LastRelevantToPlayerTime" }; }
	FieldValue<long double> MeshStopForceUpdatingAtTimeField() { return { this, "APrimalCharacter.MeshStopForceUpdatingAtTime" }; }
	FieldValue<long double> LastWalkingTimeField() { return { this, "APrimalCharacter.LastWalkingTime" }; }
	FieldValue<long double> LastSpecialDamageTimeField() { return { this, "APrimalCharacter.LastSpecialDamageTime" }; }
	FieldValue<float> CorpseDraggedDecayRateField() { return { this, "APrimalCharacter.CorpseDraggedDecayRate" }; }
	FieldValue<float> PoopAltItemChanceField() { return { this, "APrimalCharacter.PoopAltItemChance" }; }
	FieldValue<TSubclassOf<UPrimalItem>> PoopAltItemClassField() { return { this, "APrimalCharacter.PoopAltItemClass" }; }
	FieldValue<TArray<TSubclassOf<APrimalBuff>>> DefaultBuffsField() { return { this, "APrimalCharacter.DefaultBuffs" }; }
	FieldValue<UTexture2D *> PoopIconField() { return { this, "APrimalCharacter.PoopIcon" }; }
	FieldValue<float> RunningMaxDesiredRotDeltaField() { return { this, "APrimalCharacter.RunningMaxDesiredRotDelta" }; }
	FieldValue<long double> CorpseDestructionTimerField() { return { this, "APrimalCharacter.CorpseDestructionTimer" }; }
	FieldValue<float> OriginalCorpseLifespanField() { return { this, "APrimalCharacter.OriginalCorpseLifespan" }; }
	FieldValue<float> CorpseHarvestFadeTimeField() { return { this, "APrimalCharacter.CorpseHarvestFadeTime" }; }
	FieldValue<FVector> CurrentLocalRootLocField() { return { this, "APrimalCharacter.CurrentLocalRootLoc" }; }
	FieldValue<float> RootYawField() { return { this, "APrimalCharacter.RootYaw" }; }
	FieldValue<long double> LastTimeInSwimmingField() { return { this, "APrimalCharacter.LastTimeInSwimming" }; }
	FieldValue<long double> LastListenRangePushTimeField() { return { this, "APrimalCharacter.LastListenRangePushTime" }; }
	FieldValue<float> LastDamageAmountMaterialValueField() { return { this, "APrimalCharacter.LastDamageAmountMaterialValue" }; }
	FieldValue<float> BuffedDamageMultField() { return { this, "APrimalCharacter.BuffedDamageMult" }; }
	FieldValue<float> BuffedResistanceMultField() { return { this, "APrimalCharacter.BuffedResistanceMult" }; }
	FieldValue<float> ExtraMaxSpeedModifierField() { return { this, "APrimalCharacter.ExtraMaxSpeedModifier" }; }
	FieldValue<float> TamedDinoCallOutRangeField() { return { this, "APrimalCharacter.TamedDinoCallOutRange" }; }
	FieldValue<long double> LastBumpedDamageTimeField() { return { this, "APrimalCharacter.LastBumpedDamageTime" }; }
	FieldValue<FVector> TargetPathfindingLocationOffsetField() { return { this, "APrimalCharacter.TargetPathfindingLocationOffset" }; }
	FieldValue<long double> LastTookDamageTimeField() { return { this, "APrimalCharacter.LastTookDamageTime" }; }
	FieldValue<float> ExtraReceiveDamageMultiplierField() { return { this, "APrimalCharacter.ExtraReceiveDamageMultiplier" }; }
	FieldValue<float> ExtraMeleeDamageMultiplierField() { return { this, "APrimalCharacter.ExtraMeleeDamageMultiplier" }; }
	FieldValue<float> LastFallingZField() { return { this, "APrimalCharacter.LastFallingZ" }; }
	FieldValue<int> NumFallZFailsField() { return { this, "APrimalCharacter.NumFallZFails" }; }
	FieldValue<TArray<TWeakObjectPtr<APrimalCharacter>>> CharactersGrappledToMeField() { return { this, "APrimalCharacter.CharactersGrappledToMe" }; }
	FieldValue<float> DamageTheMeleeDamageCauserPercentField() { return { this, "APrimalCharacter.DamageTheMeleeDamageCauserPercent" }; }
	FieldValue<float> DurabilityDegrateTheMeleeDamageCauserPercentField() { return { this, "APrimalCharacter.DurabilityDegrateTheMeleeDamageCauserPercent" }; }
	FieldValue<TSubclassOf<UDamageType>> DamageTheMeleeDamageCauserDamageTypeField() { return { this, "APrimalCharacter.DamageTheMeleeDamageCauserDamageType" }; }
	FieldValue<char> TribeGroupInventoryRankField() { return { this, "APrimalCharacter.TribeGroupInventoryRank" }; }
	FieldValue<float> CharacterDamageImpulseMultiplierField() { return { this, "APrimalCharacter.CharacterDamageImpulseMultiplier" }; }
	FieldValue<long double> ForceCheckPushThroughWallsTimeField() { return { this, "APrimalCharacter.ForceCheckPushThroughWallsTime" }; }
	FieldValue<long double> LastStoppedEatAnimationTimeField() { return { this, "APrimalCharacter.LastStoppedEatAnimationTime" }; }
	FieldValue<float> ClientRotationInterpSpeedMultiplierGroundField() { return { this, "APrimalCharacter.ClientRotationInterpSpeedMultiplierGround" }; }
	FieldValue<float> GlideGravityScaleMultiplierField() { return { this, "APrimalCharacter.GlideGravityScaleMultiplier" }; }
	FieldValue<float> GlideMaxCarriedWeightField() { return { this, "APrimalCharacter.GlideMaxCarriedWeight" }; }
	FieldValue<UAnimMontage *> lastPlayedMountAnimField() { return { this, "APrimalCharacter.lastPlayedMountAnim" }; }
	FieldValue<float> ScaleDeathHarvestHealthyByMaxHealthBaseField() { return { this, "APrimalCharacter.ScaleDeathHarvestHealthyByMaxHealthBase" }; }
	FieldValue<long double> LastForceMeshRefreshBonesTimeField() { return { this, "APrimalCharacter.LastForceMeshRefreshBonesTime" }; }
	FieldValue<long double> LastStartedBeingCarriedTimeField() { return { this, "APrimalCharacter.LastStartedBeingCarriedTime" }; }
	FieldValue<float> RunMinVelocityRotDotField() { return { this, "APrimalCharacter.RunMinVelocityRotDot" }; }
	FieldValue<long double> LastHitDamageTimeField() { return { this, "APrimalCharacter.LastHitDamageTime" }; }
	FieldValue<TArray<TSubclassOf<APrimalBuff>>> PreventBuffClassesField() { return { this, "APrimalCharacter.PreventBuffClasses" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUseBlueprintJumpInputEvents() { return { this, "APrimalCharacter.bUseBlueprintJumpInputEvents" }; }
	BitFieldValue<bool, unsigned __int32> bIsSleeping() { return { this, "APrimalCharacter.bIsSleeping" }; }
	BitFieldValue<bool, unsigned __int32> bWantsToRun() { return { this, "APrimalCharacter.bWantsToRun" }; }
	BitFieldValue<bool, unsigned __int32> bActiveRunToggle() { return { this, "APrimalCharacter.bActiveRunToggle" }; }
	BitFieldValue<bool, unsigned __int32> bIsBeingDragged() { return { this, "APrimalCharacter.bIsBeingDragged" }; }
	BitFieldValue<bool, unsigned __int32> bDisableSpawnDefaultController() { return { this, "APrimalCharacter.bDisableSpawnDefaultController" }; }
	BitFieldValue<bool, unsigned __int32> bIsDragging() { return { this, "APrimalCharacter.bIsDragging" }; }
	BitFieldValue<bool, unsigned __int32> bIsDraggingWithGrapHook() { return { this, "APrimalCharacter.bIsDraggingWithGrapHook" }; }
	BitFieldValue<bool, unsigned __int32> bDeathKeepCapsuleCollision() { return { this, "APrimalCharacter.bDeathKeepCapsuleCollision" }; }
	BitFieldValue<bool, unsigned __int32> bRemoteRunning() { return { this, "APrimalCharacter.bRemoteRunning" }; }
	BitFieldValue<bool, unsigned __int32> bCanRun() { return { this, "APrimalCharacter.bCanRun" }; }
	BitFieldValue<bool, unsigned __int32> bUseHealthDamageMaterialOverlay() { return { this, "APrimalCharacter.bUseHealthDamageMaterialOverlay" }; }
	BitFieldValue<bool, unsigned __int32> bIsBlinking() { return { this, "APrimalCharacter.bIsBlinking" }; }
	BitFieldValue<bool, unsigned __int32> bSleepedWaterRagdoll() { return { this, "APrimalCharacter.bSleepedWaterRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeTorpid() { return { this, "APrimalCharacter.bCanBeTorpid" }; }
	BitFieldValue<bool, unsigned __int32> bDebugIK() { return { this, "APrimalCharacter.bDebugIK" }; }
	BitFieldValue<bool, unsigned __int32> bForceAlwaysUpdateMesh() { return { this, "APrimalCharacter.bForceAlwaysUpdateMesh" }; }
	BitFieldValue<bool, unsigned __int32> bRagdollIgnoresPawnCapsules() { return { this, "APrimalCharacter.bRagdollIgnoresPawnCapsules" }; }
	BitFieldValue<bool, unsigned __int32> bUsePoopAnimationNotify() { return { this, "APrimalCharacter.bUsePoopAnimationNotify" }; }
	BitFieldValue<bool, unsigned __int32> bIsBigDino() { return { this, "APrimalCharacter.bIsBigDino" }; }
	BitFieldValue<bool, unsigned __int32> bDeathUseRagdoll() { return { this, "APrimalCharacter.bDeathUseRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeCarried() { return { this, "APrimalCharacter.bCanBeCarried" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanNotifyTeamAggroAI() { return { this, "APrimalCharacter.bUseBPCanNotifyTeamAggroAI" }; }
	BitFieldValue<bool, unsigned __int32> bDamageNotifyTeamAggroAI() { return { this, "APrimalCharacter.bDamageNotifyTeamAggroAI" }; }
	BitFieldValue<bool, unsigned __int32> bRecentlyUpdateIk() { return { this, "APrimalCharacter.bRecentlyUpdateIk" }; }
	BitFieldValue<bool, unsigned __int32> bIKEnabled() { return { this, "APrimalCharacter.bIKEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bIsCarried() { return { this, "APrimalCharacter.bIsCarried" }; }
	BitFieldValue<bool, unsigned __int32> bIsCarriedAsPassenger() { return { this, "APrimalCharacter.bIsCarriedAsPassenger" }; }
	BitFieldValue<bool, unsigned __int32> bForceIKOnDedicatedServer() { return { this, "APrimalCharacter.bForceIKOnDedicatedServer" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreAllImmobilizationTraps() { return { this, "APrimalCharacter.bIgnoreAllImmobilizationTraps" }; }
	BitFieldValue<bool, unsigned __int32> bForceTriggerIgnoredTraps() { return { this, "APrimalCharacter.bForceTriggerIgnoredTraps" }; }
	BitFieldValue<bool, unsigned __int32> bIsImmobilized() { return { this, "APrimalCharacter.bIsImmobilized" }; }
	BitFieldValue<bool, unsigned __int32> bCanIgnoreWater() { return { this, "APrimalCharacter.bCanIgnoreWater" }; }
	BitFieldValue<bool, unsigned __int32> bIsDead() { return { this, "APrimalCharacter.bIsDead" }; }
	BitFieldValue<bool, unsigned __int32> ReplicateAllBones() { return { this, "APrimalCharacter.ReplicateAllBones" }; }
	BitFieldValue<bool, unsigned __int32> AutoStopReplicationWhenSleeping() { return { this, "APrimalCharacter.AutoStopReplicationWhenSleeping" }; }
	BitFieldValue<bool, unsigned __int32> bCanDrag() { return { this, "APrimalCharacter.bCanDrag" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeDragged() { return { this, "APrimalCharacter.bCanBeDragged" }; }
	BitFieldValue<bool, unsigned __int32> bUsesRunningAnimation() { return { this, "APrimalCharacter.bUsesRunningAnimation" }; }
	BitFieldValue<bool, unsigned __int32> bForceNetDidLand() { return { this, "APrimalCharacter.bForceNetDidLand" }; }
	BitFieldValue<bool, unsigned __int32> bPreventSimpleIK() { return { this, "APrimalCharacter.bPreventSimpleIK" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyAllowRunningWhileFlying() { return { this, "APrimalCharacter.bOnlyAllowRunningWhileFlying" }; }
	BitFieldValue<bool, unsigned __int32> bOrbitCamera() { return { this, "APrimalCharacter.bOrbitCamera" }; }
	BitFieldValue<bool, unsigned __int32> bClientSetCurrentAimRot() { return { this, "APrimalCharacter.bClientSetCurrentAimRot" }; }
	BitFieldValue<bool, unsigned __int32> bDisablePawnTick() { return { this, "APrimalCharacter.bDisablePawnTick" }; }
	BitFieldValue<bool, unsigned __int32> bSetDeath() { return { this, "APrimalCharacter.bSetDeath" }; }
	BitFieldValue<bool, unsigned __int32> bTicksOnClient() { return { this, "APrimalCharacter.bTicksOnClient" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingRunSound() { return { this, "APrimalCharacter.bPlayingRunSound" }; }
	BitFieldValue<bool, unsigned __int32> bIsRespawn() { return { this, "APrimalCharacter.bIsRespawn" }; }
	BitFieldValue<bool, unsigned __int32> bCreatedDynamicMaterials() { return { this, "APrimalCharacter.bCreatedDynamicMaterials" }; }
	BitFieldValue<bool, unsigned __int32> bCurrentFrameAnimPreventInput() { return { this, "APrimalCharacter.bCurrentFrameAnimPreventInput" }; }
	BitFieldValue<bool, unsigned __int32> bDraggedFromExtremitiesOnly() { return { this, "APrimalCharacter.bDraggedFromExtremitiesOnly" }; }
	BitFieldValue<bool, unsigned __int32> bEnableIK() { return { this, "APrimalCharacter.bEnableIK" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyPlayPoopAnimWhileWalking() { return { this, "APrimalCharacter.bOnlyPlayPoopAnimWhileWalking" }; }
	BitFieldValue<bool, unsigned __int32> bUseBlueprintAnimNotifyCustomEvent() { return { this, "APrimalCharacter.bUseBlueprintAnimNotifyCustomEvent" }; }
	BitFieldValue<bool, unsigned __int32> bNoDamageImpulse() { return { this, "APrimalCharacter.bNoDamageImpulse" }; }
	BitFieldValue<bool, unsigned __int32> bPreventImmobilization() { return { this, "APrimalCharacter.bPreventImmobilization" }; }
	BitFieldValue<bool, unsigned __int32> bAllowAirJump() { return { this, "APrimalCharacter.bAllowAirJump" }; }
	BitFieldValue<bool, unsigned __int32> bSleepingUseRagdoll() { return { this, "APrimalCharacter.bSleepingUseRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bDediForceUnregisterSKMesh() { return { this, "APrimalCharacter.bDediForceUnregisterSKMesh" }; }
	BitFieldValue<bool, unsigned __int32> bReadyToPoop() { return { this, "APrimalCharacter.bReadyToPoop" }; }
	BitFieldValue<bool, unsigned __int32> bHasDynamicBase() { return { this, "APrimalCharacter.bHasDynamicBase" }; }
	BitFieldValue<bool, unsigned __int32> bIsBeingDraggedByDino() { return { this, "APrimalCharacter.bIsBeingDraggedByDino" }; }
	BitFieldValue<bool, unsigned __int32> bIsDraggingDinoStopped() { return { this, "APrimalCharacter.bIsDraggingDinoStopped" }; }
	BitFieldValue<bool, unsigned __int32> bMissingDynamicBase() { return { this, "APrimalCharacter.bMissingDynamicBase" }; }
	BitFieldValue<bool, unsigned __int32> bClientRagdollUpdateTimerEnabled() { return { this, "APrimalCharacter.bClientRagdollUpdateTimerEnabled" }; }
	BitFieldValue<bool, unsigned __int32> bDieIfLeftWater() { return { this, "APrimalCharacter.bDieIfLeftWater" }; }
	BitFieldValue<bool, unsigned __int32> bIsAmphibious() { return { this, "APrimalCharacter.bIsAmphibious" }; }
	BitFieldValue<bool, unsigned __int32> bUseAmphibiousTargeting() { return { this, "APrimalCharacter.bUseAmphibiousTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bIsWaterDino() { return { this, "APrimalCharacter.bIsWaterDino" }; }
	BitFieldValue<bool, unsigned __int32> bIsFlyerDino() { return { this, "APrimalCharacter.bIsFlyerDino" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreTargetingCarnivores() { return { this, "APrimalCharacter.bIgnoreTargetingCarnivores" }; }
	BitFieldValue<bool, unsigned __int32> bAimGettingCharacterMeshRotation() { return { this, "APrimalCharacter.bAimGettingCharacterMeshRotation" }; }
	BitFieldValue<bool, unsigned __int32> bIsRunningCheckIgnoreVelocity() { return { this, "APrimalCharacter.bIsRunningCheckIgnoreVelocity" }; }
	BitFieldValue<bool, unsigned __int32> bIsPlayingLowHealthAnim() { return { this, "APrimalCharacter.bIsPlayingLowHealthAnim" }; }
	BitFieldValue<bool, unsigned __int32> bAllowCharacterPainting() { return { this, "APrimalCharacter.bAllowCharacterPainting" }; }
	BitFieldValue<bool, unsigned __int32> bTickStatusComponent() { return { this, "APrimalCharacter.bTickStatusComponent" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateDamageMomentum() { return { this, "APrimalCharacter.bReplicateDamageMomentum" }; }
	BitFieldValue<bool, unsigned __int32> bDontActuallyEmitPoop() { return { this, "APrimalCharacter.bDontActuallyEmitPoop" }; }
	BitFieldValue<bool, unsigned __int32> bBPHUDOverideBuffProgressBar() { return { this, "APrimalCharacter.bBPHUDOverideBuffProgressBar" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRunningWhileSwimming() { return { this, "APrimalCharacter.bAllowRunningWhileSwimming" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyBumpedByPawn() { return { this, "APrimalCharacter.bUseBPNotifyBumpedByPawn" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyBumpedPawn() { return { this, "APrimalCharacter.bUseBPNotifyBumpedPawn" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAdjustDamage() { return { this, "APrimalCharacter.bUseBPAdjustDamage" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPTimerServer() { return { this, "APrimalCharacter.bUseBPTimerServer" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPTimerNonDedicated() { return { this, "APrimalCharacter.bUseBPTimerNonDedicated" }; }
	BitFieldValue<bool, unsigned __int32> bTriggerBPStasis() { return { this, "APrimalCharacter.bTriggerBPStasis" }; }
	BitFieldValue<bool, unsigned __int32> bIsMounted() { return { this, "APrimalCharacter.bIsMounted" }; }
	BitFieldValue<bool, unsigned __int32> bPreventTargetingByTurrets() { return { this, "APrimalCharacter.bPreventTargetingByTurrets" }; }
	BitFieldValue<bool, unsigned __int32> bDelayFootstepsUnderMinInterval() { return { this, "APrimalCharacter.bDelayFootstepsUnderMinInterval" }; }
	BitFieldValue<bool, unsigned __int32> bSleepingDisableIK() { return { this, "APrimalCharacter.bSleepingDisableIK" }; }
	BitFieldValue<bool, unsigned __int32> bRagdollRetainAnimations() { return { this, "APrimalCharacter.bRagdollRetainAnimations" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAddedAttachments() { return { this, "APrimalCharacter.bUseBPAddedAttachments" }; }
	BitFieldValue<bool, unsigned __int32> bCanPlayLandingAnim() { return { this, "APrimalCharacter.bCanPlayLandingAnim" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyHasRunningAnimationWhenWalking() { return { this, "APrimalCharacter.bOnlyHasRunningAnimationWhenWalking" }; }
	BitFieldValue<bool, unsigned __int32> bIsReflectingDamage() { return { this, "APrimalCharacter.bIsReflectingDamage" }; }
	BitFieldValue<bool, unsigned __int32> bPreventTargetingAndMovement() { return { this, "APrimalCharacter.bPreventTargetingAndMovement" }; }
	BitFieldValue<bool, unsigned __int32> bPreventMovement() { return { this, "APrimalCharacter.bPreventMovement" }; }
	BitFieldValue<bool, unsigned __int32> bIsWhistleTargetingDown() { return { this, "APrimalCharacter.bIsWhistleTargetingDown" }; }
	BitFieldValue<bool, unsigned __int32> bBPPreventInputType() { return { this, "APrimalCharacter.bBPPreventInputType" }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventAllInput() { return { this, "APrimalCharacter.bForcePreventAllInput" }; }
	BitFieldValue<bool, unsigned __int32> bPreventAllBuffs() { return { this, "APrimalCharacter.bPreventAllBuffs" }; }
	BitFieldValue<bool, unsigned __int32> LastIsInsideVaccumSealedCube() { return { this, "APrimalCharacter.LastIsInsideVaccumSealedCube" }; }
	BitFieldValue<bool, unsigned __int32> bPreventJump() { return { this, "APrimalCharacter.bPreventJump" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventStasis() { return { this, "APrimalCharacter.bUseBPPreventStasis" }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnStasis() { return { this, "APrimalCharacter.bDestroyOnStasis" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPostLoadedFromSaveGame() { return { this, "APrimalCharacter.bUseBPPostLoadedFromSaveGame" }; }
	BitFieldValue<bool, unsigned __int32> bUseHeavyCombatMusic() { return { this, "APrimalCharacter.bUseHeavyCombatMusic" }; }
	BitFieldValue<bool, unsigned __int32> bMarkForDestruction() { return { this, "APrimalCharacter.bMarkForDestruction" }; }
	BitFieldValue<bool, unsigned __int32> bBPModifyAllowedViewHitDir() { return { this, "APrimalCharacter.bBPModifyAllowedViewHitDir" }; }
	BitFieldValue<bool, unsigned __int32> bBPLimitPlayerRotation() { return { this, "APrimalCharacter.bBPLimitPlayerRotation" }; }
	BitFieldValue<bool, unsigned __int32> bBPManagedFPVViewLocation() { return { this, "APrimalCharacter.bBPManagedFPVViewLocation" }; }
	BitFieldValue<bool, unsigned __int32> bBPCameraRotationFinal() { return { this, "APrimalCharacter.bBPCameraRotationFinal" }; }
	BitFieldValue<bool, unsigned __int32> bServerBPNotifyInventoryItemChangesUseQuantity() { return { this, "APrimalCharacter.bServerBPNotifyInventoryItemChangesUseQuantity" }; }
	BitFieldValue<bool, unsigned __int32> bServerBPNotifyInventoryItemChanges() { return { this, "APrimalCharacter.bServerBPNotifyInventoryItemChanges" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRun() { return { this, "APrimalCharacter.bAllowRun" }; }
	BitFieldValue<bool, unsigned __int32> bIsAtMaxInventoryItems() { return { this, "APrimalCharacter.bIsAtMaxInventoryItems" }; }
	BitFieldValue<bool, unsigned __int32> bIsReplicatedRagdoll() { return { this, "APrimalCharacter.bIsReplicatedRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bWasAllBodiesSleeping() { return { this, "APrimalCharacter.bWasAllBodiesSleeping" }; }
	BitFieldValue<bool, unsigned __int32> bInRagdoll() { return { this, "APrimalCharacter.bInRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bIsNPC() { return { this, "APrimalCharacter.bIsNPC" }; }
	BitFieldValue<bool, unsigned __int32> LastCheckedSubmergedFull() { return { this, "APrimalCharacter.LastCheckedSubmergedFull" }; }
	BitFieldValue<bool, unsigned __int32> bAllowFullSubmergedCheck() { return { this, "APrimalCharacter.bAllowFullSubmergedCheck" }; }
	BitFieldValue<bool, unsigned __int32> bRagdollWasInWaterVolume() { return { this, "APrimalCharacter.bRagdollWasInWaterVolume" }; }
	BitFieldValue<bool, unsigned __int32> bIsBuffed() { return { this, "APrimalCharacter.bIsBuffed" }; }
	BitFieldValue<bool, unsigned __int32> bIsDraggingWithOffset() { return { this, "APrimalCharacter.bIsDraggingWithOffset" }; }
	BitFieldValue<bool, unsigned __int32> bIsDraggedWithOffset() { return { this, "APrimalCharacter.bIsDraggedWithOffset" }; }
	BitFieldValue<bool, unsigned __int32> bPreventRunningWhileWalking() { return { this, "APrimalCharacter.bPreventRunningWhileWalking" }; }
	BitFieldValue<bool, unsigned __int32> bCanLandOnWater() { return { this, "APrimalCharacter.bCanLandOnWater" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAdjustMoveForward() { return { this, "APrimalCharacter.bUseBPAdjustMoveForward" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetGravity() { return { this, "APrimalCharacter.bUseBPGetGravity" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDamageWhenMounted() { return { this, "APrimalCharacter.bAllowDamageWhenMounted" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnAttachmentReplication() { return { this, "APrimalCharacter.bUseBPOnAttachmentReplication" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnMovementModeChangedNotify() { return { this, "APrimalCharacter.bUseBPOnMovementModeChangedNotify" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnAnimPlayedNotify() { return { this, "APrimalCharacter.bUseBPOnAnimPlayedNotify" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideCharacterNewFallVelocity() { return { this, "APrimalCharacter.bUseBPOverrideCharacterNewFallVelocity" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_OnSetRunningEvent() { return { this, "APrimalCharacter.bUseBP_OnSetRunningEvent" }; }
	BitFieldValue<bool, unsigned __int32> bForceTurretFastTargeting() { return { this, "APrimalCharacter.bForceTurretFastTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bFlyingOrWaterDinoPreventBackwardsRun() { return { this, "APrimalCharacter.bFlyingOrWaterDinoPreventBackwardsRun" }; }
	BitFieldValue<bool, unsigned __int32> bSleepingDisableRagdoll() { return { this, "APrimalCharacter.bSleepingDisableRagdoll" }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnStasisWhenDead() { return { this, "APrimalCharacter.bDestroyOnStasisWhenDead" }; }
	BitFieldValue<bool, unsigned __int32> bPreventLiveBlinking() { return { this, "APrimalCharacter.bPreventLiveBlinking" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreSeatingDetachment() { return { this, "APrimalCharacter.bIgnoreSeatingDetachment" }; }
	BitFieldValue<bool, unsigned __int32> bForceAlwaysUpdateMeshAndCollision() { return { this, "APrimalCharacter.bForceAlwaysUpdateMeshAndCollision" }; }
	BitFieldValue<bool, unsigned __int32> bPreventHurtAnim() { return { this, "APrimalCharacter.bPreventHurtAnim" }; }

	// Functions

	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "APrimalCharacter.GetPrivateStaticClass"); }
	float BPGetAddForwardVelocityOnJump_Implementation() { return NativeCall<float>(this, "APrimalCharacter.BPGetAddForwardVelocityOnJump_Implementation"); }
	bool CanJumpInternal_Implementation() { return NativeCall<bool>(this, "APrimalCharacter.CanJumpInternal_Implementation"); }
	void PreInitializeComponents() { NativeCall<void>(this, "APrimalCharacter.PreInitializeComponents"); }
	void ValidatePaintingComponentOctree() { NativeCall<void>(this, "APrimalCharacter.ValidatePaintingComponentOctree"); }
	void PostInitializeComponents() { NativeCall<void>(this, "APrimalCharacter.PostInitializeComponents"); }
	void Destroyed() { NativeCall<void>(this, "APrimalCharacter.Destroyed"); }
	void BeginPlay() { NativeCall<void>(this, "APrimalCharacter.BeginPlay"); }
	void FellOutOfWorld(UDamageType * dmgType) { NativeCall<void, UDamageType *>(this, "APrimalCharacter.FellOutOfWorld", dmgType); }
	void Suicide() { NativeCall<void>(this, "APrimalCharacter.Suicide"); }
	bool IsDead() { return NativeCall<bool>(this, "APrimalCharacter.IsDead"); }
	void InventoryItemUsed(UObject * InventoryItemObject) { NativeCall<void, UObject *>(this, "APrimalCharacter.InventoryItemUsed", InventoryItemObject); }
	void AdjustDamage(float * Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { NativeCall<void, float *, FDamageEvent *, AController *, AActor *>(this, "APrimalCharacter.AdjustDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool CanBeTargetedBy(ITargetableInterface * Attacker) { return NativeCall<bool, ITargetableInterface *>(this, "APrimalCharacter.CanBeTargetedBy", Attacker); }
	bool IsValidForCombatMusic() { return NativeCall<bool>(this, "APrimalCharacter.IsValidForCombatMusic"); }
	float TakeDamage(float Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<float, float, FDamageEvent *, AController *, AActor *>(this, "APrimalCharacter.TakeDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool CanDie(float KillingDamage, FDamageEvent * DamageEvent, AController * Killer, AActor * DamageCauser) { return NativeCall<bool, float, FDamageEvent *, AController *, AActor *>(this, "APrimalCharacter.CanDie", KillingDamage, DamageEvent, Killer, DamageCauser); }
	bool Die(float KillingDamage, FDamageEvent * DamageEvent, AController * Killer, AActor * DamageCauser) { return NativeCall<bool, float, FDamageEvent *, AController *, AActor *>(this, "APrimalCharacter.Die", KillingDamage, DamageEvent, Killer, DamageCauser); }
	void PlayDyingPoint_Implementation(float KillingDamage, FPointDamageEvent DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FPointDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayDyingPoint_Implementation", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayDyingRadial_Implementation(float KillingDamage, FRadialDamageEvent DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FRadialDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayDyingRadial_Implementation", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void SetDeath(bool bForceRagdoll) { NativeCall<void, bool>(this, "APrimalCharacter.SetDeath", bForceRagdoll); }
	bool CanIgnoreImmobilizationTrap(TSubclassOf<APrimalStructure> TrapClass, bool * bForceTrigger) { return NativeCall<bool, TSubclassOf<APrimalStructure>, bool *>(this, "APrimalCharacter.CanIgnoreImmobilizationTrap", TrapClass, bForceTrigger); }
	void Immobilize(bool bImmobilize, AActor * UsingActor, bool bImmobilizeFalling) { NativeCall<void, bool, AActor *, bool>(this, "APrimalCharacter.Immobilize", bImmobilize, UsingActor, bImmobilizeFalling); }
	float GetCorpseLifespan() { return NativeCall<float>(this, "APrimalCharacter.GetCorpseLifespan"); }
	void PlayDying(float KillingDamage, FDamageEvent * DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "APrimalCharacter.PlayDying", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayHitEffectGeneric_Implementation(float DamageTaken, FPointDamageEvent DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FPointDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayHitEffectGeneric_Implementation", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	void PlayHitEffectRadial_Implementation(float DamageTaken, FRadialDamageEvent DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FRadialDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayHitEffectRadial_Implementation", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	bool AllowHurtAnimation() { return NativeCall<bool>(this, "APrimalCharacter.AllowHurtAnimation"); }
	UPrimitiveComponent * GetPrimaryHitComponent() { return NativeCall<UPrimitiveComponent *>(this, "APrimalCharacter.GetPrimaryHitComponent"); }
	void PlayHitEffect(float DamageTaken, FDamageEvent * DamageEvent, APawn * PawnInstigator, AActor * DamageCauser, bool bIsLocalPath) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *, bool>(this, "APrimalCharacter.PlayHitEffect", DamageTaken, DamageEvent, PawnInstigator, DamageCauser, bIsLocalPath); }
	void DoSetRagdollPhysics() { NativeCall<void>(this, "APrimalCharacter.DoSetRagdollPhysics"); }
	void SetRagdollPhysics(bool bUseRagdollLocationOffset, bool bForceRecreateBones, bool bForLoading) { NativeCall<void, bool, bool, bool>(this, "APrimalCharacter.SetRagdollPhysics", bUseRagdollLocationOffset, bForceRecreateBones, bForLoading); }
	void CheckOnDinoPlatformSaddle() { NativeCall<void>(this, "APrimalCharacter.CheckOnDinoPlatformSaddle"); }
	void ForceSleepRagdollEx() { NativeCall<void>(this, "APrimalCharacter.ForceSleepRagdollEx"); }
	void ForceSleepRagdoll() { NativeCall<void>(this, "APrimalCharacter.ForceSleepRagdoll"); }
	void ClearRagdollPhysics() { NativeCall<void>(this, "APrimalCharacter.ClearRagdollPhysics"); }
	void DoFindGoodSpot(FVector RagdollLoc, bool bClearCollisionSweep) { NativeCall<void, FVector, bool>(this, "APrimalCharacter.DoFindGoodSpot", RagdollLoc, bClearCollisionSweep); }
	void SetSleeping(bool bSleeping, bool bUseRagdollLocationOffset) { NativeCall<void, bool, bool>(this, "APrimalCharacter.SetSleeping", bSleeping, bUseRagdollLocationOffset); }
	void ExecSetSleeping(bool bEnable) { NativeCall<void, bool>(this, "APrimalCharacter.ExecSetSleeping", bEnable); }
	void ChangeActorTeam(int NewTeam) { NativeCall<void, int>(this, "APrimalCharacter.ChangeActorTeam", NewTeam); }
	void UpdateTribeName(FString NewTribeName) { NativeCall<void, FString>(this, "APrimalCharacter.UpdateTribeName", NewTribeName); }
	void NetUpdateTribeName_Implementation(FString * NewTribeName) { NativeCall<void, FString *>(this, "APrimalCharacter.NetUpdateTribeName_Implementation", NewTribeName); }
	float GetMaxCursorHUDDistance(AShooterPlayerController * PC) { return NativeCall<float, AShooterPlayerController *>(this, "APrimalCharacter.GetMaxCursorHUDDistance", PC); }
	void DrawHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "APrimalCharacter.DrawHUD", HUD); }
	bool IsSubmerged(bool bDontCheckSwimming, bool bUseFullThreshold, bool bForceCheck, bool bFromVolumeChange) { return NativeCall<bool, bool, bool, bool, bool>(this, "APrimalCharacter.IsSubmerged", bDontCheckSwimming, bUseFullThreshold, bForceCheck, bFromVolumeChange); }
	float GetWaterSubmergedDepthThreshold() { return NativeCall<float>(this, "APrimalCharacter.GetWaterSubmergedDepthThreshold"); }
	float PlayAnimMontage(UAnimMontage * AnimMontage, float InPlayRate, FName StartSectionName, bool bForceTickPoseAndServerUpdateMesh, bool bForceTickPoseOnServer) { return NativeCall<float, UAnimMontage *, float, FName, bool, bool>(this, "APrimalCharacter.PlayAnimMontage", AnimMontage, InPlayRate, StartSectionName, bForceTickPoseAndServerUpdateMesh, bForceTickPoseOnServer); }
	void StopAnimMontage(UAnimMontage * AnimMontage) { NativeCall<void, UAnimMontage *>(this, "APrimalCharacter.StopAnimMontage", AnimMontage); }
	bool IsMontagePlaying(UAnimMontage * AnimMontage, float TimeFromEndToConsiderFinished) { return NativeCall<bool, UAnimMontage *, float>(this, "APrimalCharacter.IsMontagePlaying", AnimMontage, TimeFromEndToConsiderFinished); }
	void StopAllAnimMontages(float BlendOutTime) { NativeCall<void, float>(this, "APrimalCharacter.StopAllAnimMontages", BlendOutTime); }
	void TryGiveDefaultWeapon() { NativeCall<void>(this, "APrimalCharacter.TryGiveDefaultWeapon"); }
	void TryPoop() { NativeCall<void>(this, "APrimalCharacter.TryPoop"); }
	void OrbitCamToggle() { NativeCall<void>(this, "APrimalCharacter.OrbitCamToggle"); }
	void OrbitCamOn() { NativeCall<void>(this, "APrimalCharacter.OrbitCamOn"); }
	void OrbitCamOff() { NativeCall<void>(this, "APrimalCharacter.OrbitCamOff"); }
	void ServerRequestDrag_Implementation() { NativeCall<void>(this, "APrimalCharacter.ServerRequestDrag_Implementation"); }
	void ServerDinoOrder_Implementation(APrimalDinoCharacter * aDino, EDinoTamedOrder::Type OrderType, AActor * enemyTarget) { NativeCall<void, APrimalDinoCharacter *, EDinoTamedOrder::Type, AActor *>(this, "APrimalCharacter.ServerDinoOrder_Implementation", aDino, OrderType, enemyTarget); }
	void MoveForward(float Val) { NativeCall<void, float>(this, "APrimalCharacter.MoveForward", Val); }
	void MoveRight(float Val) { NativeCall<void, float>(this, "APrimalCharacter.MoveRight", Val); }
	void MoveUp(float Val) { NativeCall<void, float>(this, "APrimalCharacter.MoveUp", Val); }
	void TurnInput(float Val) { NativeCall<void, float>(this, "APrimalCharacter.TurnInput", Val); }
	void LookInput(float Val) { NativeCall<void, float>(this, "APrimalCharacter.LookInput", Val); }
	void TurnAtRate(float Val) { NativeCall<void, float>(this, "APrimalCharacter.TurnAtRate", Val); }
	void LookUpAtRate(float Val) { NativeCall<void, float>(this, "APrimalCharacter.LookUpAtRate", Val); }
	bool IsGameInputAllowed() { return NativeCall<bool>(this, "APrimalCharacter.IsGameInputAllowed"); }
	bool IsInputAllowed() { return NativeCall<bool>(this, "APrimalCharacter.IsInputAllowed"); }
	void OnStartRunning() { NativeCall<void>(this, "APrimalCharacter.OnStartRunning"); }
	void OnStopRunning() { NativeCall<void>(this, "APrimalCharacter.OnStopRunning"); }
	void OnRunToggle() { NativeCall<void>(this, "APrimalCharacter.OnRunToggle"); }
	bool IsRunning() { return NativeCall<bool>(this, "APrimalCharacter.IsRunning"); }
	bool IsMoving() { return NativeCall<bool>(this, "APrimalCharacter.IsMoving"); }
	void UpdateStatusComponent(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalCharacter.UpdateStatusComponent", DeltaSeconds); }
	void SetBoundsScale(float NewScale) { NativeCall<void, float>(this, "APrimalCharacter.SetBoundsScale", NewScale); }
	void UpdateStencilValues() { NativeCall<void>(this, "APrimalCharacter.UpdateStencilValues"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalCharacter.Tick", DeltaSeconds); }
	void SetCharacterMeshesMaterialScalarParamValue(FName ParamName, float Value) { NativeCall<void, FName, float>(this, "APrimalCharacter.SetCharacterMeshesMaterialScalarParamValue", ParamName, Value); }
	void UpdateSwimmingState() { NativeCall<void>(this, "APrimalCharacter.UpdateSwimmingState"); }
	FVector * GetRootBodyBoneLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalCharacter.GetRootBodyBoneLocation", result); }
	void ZoomIn() { NativeCall<void>(this, "APrimalCharacter.ZoomIn"); }
	void ZoomOut() { NativeCall<void>(this, "APrimalCharacter.ZoomOut"); }
	void OnStartJump() { NativeCall<void>(this, "APrimalCharacter.OnStartJump"); }
	void PlayJumpAnim() { NativeCall<void>(this, "APrimalCharacter.PlayJumpAnim"); }
	void PlayLandedAnim() { NativeCall<void>(this, "APrimalCharacter.PlayLandedAnim"); }
	void OnJumped_Implementation() { NativeCall<void>(this, "APrimalCharacter.OnJumped_Implementation"); }
	void NetOnJumped_Implementation() { NativeCall<void>(this, "APrimalCharacter.NetOnJumped_Implementation"); }
	void OnStopJump() { NativeCall<void>(this, "APrimalCharacter.OnStopJump"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APrimalCharacter.GetLifetimeReplicatedProps", OutLifetimeProps); }
	float GetRunningSpeedModifier(bool bIsForDefaultSpeed) { return NativeCall<float, bool>(this, "APrimalCharacter.GetRunningSpeedModifier", bIsForDefaultSpeed); }
	float GetMaxHealth() { return NativeCall<float>(this, "APrimalCharacter.GetMaxHealth"); }
	bool AllowFirstPerson() { return NativeCall<bool>(this, "APrimalCharacter.AllowFirstPerson"); }
	AActor * GetAimedActor(ECollisionChannel CollisionChannel, UActorComponent ** HitComponent, float MaxDistanceOverride, float CheckRadius, int * hitBodyIndex, FHitResult * outHitResult, bool bForceUseCameraLocation, bool bForceUpdateAimedActors) { return NativeCall<AActor *, ECollisionChannel, UActorComponent **, float, float, int *, FHitResult *, bool, bool>(this, "APrimalCharacter.GetAimedActor", CollisionChannel, HitComponent, MaxDistanceOverride, CheckRadius, hitBodyIndex, outHitResult, bForceUseCameraLocation, bForceUpdateAimedActors); }
	void OnPrimalCharacterSleeped() { NativeCall<void>(this, "APrimalCharacter.OnPrimalCharacterSleeped"); }
	void OnPrimalCharacterUnsleeped() { NativeCall<void>(this, "APrimalCharacter.OnPrimalCharacterUnsleeped"); }
	float PlayAnimEx(UAnimMontage * AnimMontage, float InPlayRate, FName StartSectionName, bool bReplicate, bool bReplicateToOwner, bool bForceTickPoseAndServerUpdateMesh, bool bForceTickPoseOnServer) { return NativeCall<float, UAnimMontage *, float, FName, bool, bool, bool, bool>(this, "APrimalCharacter.PlayAnimEx", AnimMontage, InPlayRate, StartSectionName, bReplicate, bReplicateToOwner, bForceTickPoseAndServerUpdateMesh, bForceTickPoseOnServer); }
	void StopAnimEx(UAnimMontage * AnimMontage, bool bReplicate, bool bReplicateToOwner, float BlendOutTime) { NativeCall<void, UAnimMontage *, bool, bool, float>(this, "APrimalCharacter.StopAnimEx", AnimMontage, bReplicate, bReplicateToOwner, BlendOutTime); }
	void ClientPlayAnimation_Implementation(UAnimMontage * AnimMontage, float PlayRate, FName StartSectionName, bool bPlayOnOwner, bool bForceTickPoseAndServerUpdateMesh) { NativeCall<void, UAnimMontage *, float, FName, bool, bool>(this, "APrimalCharacter.ClientPlayAnimation_Implementation", AnimMontage, PlayRate, StartSectionName, bPlayOnOwner, bForceTickPoseAndServerUpdateMesh); }
	void ClientStopAnimation_Implementation(UAnimMontage * AnimMontage, bool bStopOnOwner, float BlendOutTime) { NativeCall<void, UAnimMontage *, bool, float>(this, "APrimalCharacter.ClientStopAnimation_Implementation", AnimMontage, bStopOnOwner, BlendOutTime); }
	void SetRunning(bool bNewRunning) { NativeCall<void, bool>(this, "APrimalCharacter.SetRunning", bNewRunning); }
	void ServerSetRunning_Implementation(bool bNewRunning) { NativeCall<void, bool>(this, "APrimalCharacter.ServerSetRunning_Implementation", bNewRunning); }
	void UpdateRunSounds(bool bNewRunning) { NativeCall<void, bool>(this, "APrimalCharacter.UpdateRunSounds", bNewRunning); }
	void ControllerLeavingGame(AShooterPlayerController * theController) { NativeCall<void, AShooterPlayerController *>(this, "APrimalCharacter.ControllerLeavingGame", theController); }
	float GetLowHealthPercentage() { return NativeCall<float>(this, "APrimalCharacter.GetLowHealthPercentage"); }
	bool IsAlive() { return NativeCall<bool>(this, "APrimalCharacter.IsAlive"); }
	FString * GetDescriptiveName(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalCharacter.GetDescriptiveName", result); }
	FString * GetShortName(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalCharacter.GetShortName", result); }
	float GetHealthPercentage() { return NativeCall<float>(this, "APrimalCharacter.GetHealthPercentage"); }
	float GetHealth() { return NativeCall<float>(this, "APrimalCharacter.GetHealth"); }
	FVector * GetInterpolatedLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalCharacter.GetInterpolatedLocation", result); }
	FRotator * GetInterpolatedRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "APrimalCharacter.GetInterpolatedRotation", result); }
	float GetClientRotationInterpSpeed(FVector * RootLoc) { return NativeCall<float, FVector *>(this, "APrimalCharacter.GetClientRotationInterpSpeed", RootLoc); }
	FRotator * GetAimOffsets(FRotator * result, float DeltaTime, FRotator * RootRotOffset, float * RootYawSpeed, float MaxYawAimClamp, FVector * RootLocOffset) { return NativeCall<FRotator *, FRotator *, float, FRotator *, float *, float, FVector *>(this, "APrimalCharacter.GetAimOffsets", result, DeltaTime, RootRotOffset, RootYawSpeed, MaxYawAimClamp, RootLocOffset); }
	void ForceRefreshBones() { NativeCall<void>(this, "APrimalCharacter.ForceRefreshBones"); }
	void StartForceSkelUpdate(float ForTime, bool bForceUpdateMesh, bool bServerOnly) { NativeCall<void, float, bool, bool>(this, "APrimalCharacter.StartForceSkelUpdate", ForTime, bForceUpdateMesh, bServerOnly); }
	void EndForceSkelUpdate() { NativeCall<void>(this, "APrimalCharacter.EndForceSkelUpdate"); }
	bool IsConscious() { return NativeCall<bool>(this, "APrimalCharacter.IsConscious"); }
	void Stasis() { NativeCall<void>(this, "APrimalCharacter.Stasis"); }
	void Unstasis() { NativeCall<void>(this, "APrimalCharacter.Unstasis"); }
	UPrimalCharacterStatusComponent * GetCharacterStatusComponent() { return NativeCall<UPrimalCharacterStatusComponent *>(this, "APrimalCharacter.GetCharacterStatusComponent"); }
	void DrawLocalPlayerHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "APrimalCharacter.DrawLocalPlayerHUD", HUD); }
	bool IsInStatusState(EPrimalCharacterStatusState::Type StatusStateType) { return NativeCall<bool, EPrimalCharacterStatusState::Type>(this, "APrimalCharacter.IsInStatusState", StatusStateType); }
	bool IsValidForStatusUpdate() { return NativeCall<bool>(this, "APrimalCharacter.IsValidForStatusUpdate"); }
	float GetMaxSpeedModifier() { return NativeCall<float>(this, "APrimalCharacter.GetMaxSpeedModifier"); }
	float GetJumpZModifier() { return NativeCall<float>(this, "APrimalCharacter.GetJumpZModifier"); }
	bool CanBeBaseForCharacter(APawn * Pawn) { return NativeCall<bool, APawn *>(this, "APrimalCharacter.CanBeBaseForCharacter", Pawn); }
	float GetDefaultMovementSpeed() { return NativeCall<float>(this, "APrimalCharacter.GetDefaultMovementSpeed"); }
	void TakeFallingDamage(FHitResult * Hit) { NativeCall<void, FHitResult *>(this, "APrimalCharacter.TakeFallingDamage", Hit); }
	void OnLanded(FHitResult * Hit) { NativeCall<void, FHitResult *>(this, "APrimalCharacter.OnLanded", Hit); }
	void NetDidLand_Implementation() { NativeCall<void>(this, "APrimalCharacter.NetDidLand_Implementation"); }
	void DidLand() { NativeCall<void>(this, "APrimalCharacter.DidLand"); }
	void FadeOutLoadingMusic() { NativeCall<void>(this, "APrimalCharacter.FadeOutLoadingMusic"); }
	void LocalPossessedBy(APlayerController * ByController) { NativeCall<void, APlayerController *>(this, "APrimalCharacter.LocalPossessedBy", ByController); }
	void LocalUnpossessed_Implementation() { NativeCall<void>(this, "APrimalCharacter.LocalUnpossessed_Implementation"); }
	void PlayFootstep() { NativeCall<void>(this, "APrimalCharacter.PlayFootstep"); }
	EPhysicalSurface GetFootPhysicalSurfaceType(bool bForce) { return NativeCall<EPhysicalSurface, bool>(this, "APrimalCharacter.GetFootPhysicalSurfaceType", bForce); }
	bool ModifyInputAcceleration(FVector * InputAcceleration) { return NativeCall<bool, FVector *>(this, "APrimalCharacter.ModifyInputAcceleration", InputAcceleration); }
	bool ShouldAttackStopMoveCollapsing() { return NativeCall<bool>(this, "APrimalCharacter.ShouldAttackStopMoveCollapsing"); }
	bool AnimationPreventsInput() { return NativeCall<bool>(this, "APrimalCharacter.AnimationPreventsInput"); }
	float SetHealth(float newHealth) { return NativeCall<float, float>(this, "APrimalCharacter.SetHealth", newHealth); }
	bool IsOfTribe(int ID) { return NativeCall<bool, int>(this, "APrimalCharacter.IsOfTribe", ID); }
	void SetRagdollReplication(bool Enabled) { NativeCall<void, bool>(this, "APrimalCharacter.SetRagdollReplication", Enabled); }
	void ReplicateRagdoll() { NativeCall<void>(this, "APrimalCharacter.ReplicateRagdoll"); }
	void InitRagdollRepConstraints() { NativeCall<void>(this, "APrimalCharacter.InitRagdollRepConstraints"); }
	void TermRagdollRepConstraints() { NativeCall<void>(this, "APrimalCharacter.TermRagdollRepConstraints"); }
	void ClientRagdollUpdate_Implementation(TArray<FVector_NetQuantize> * BoneLocations, FRotator_NetQuantize TargetRootRotation) { NativeCall<void, TArray<FVector_NetQuantize> *, FRotator_NetQuantize>(this, "APrimalCharacter.ClientRagdollUpdate_Implementation", BoneLocations, TargetRootRotation); }
	void SleepBodies() { NativeCall<void>(this, "APrimalCharacter.SleepBodies"); }
	void UpdateRagdollReplicationOnClient() { NativeCall<void>(this, "APrimalCharacter.UpdateRagdollReplicationOnClient"); }
	void ClientEndRagdollUpdate_Implementation() { NativeCall<void>(this, "APrimalCharacter.ClientEndRagdollUpdate_Implementation"); }
	void OnRep_RagdollPositions() { NativeCall<void>(this, "APrimalCharacter.OnRep_RagdollPositions"); }
	void InitRagdollReplication() { NativeCall<void>(this, "APrimalCharacter.InitRagdollReplication"); }
	bool CanDragCharacter(APrimalCharacter * Character) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalCharacter.CanDragCharacter", Character); }
	bool CanBeDragged() { return NativeCall<bool>(this, "APrimalCharacter.CanBeDragged"); }
	bool IsInvincible() { return NativeCall<bool>(this, "APrimalCharacter.IsInvincible"); }
	int GetNearestBoneIndexForDrag(APrimalCharacter * Character, FVector HitLocation) { return NativeCall<int, APrimalCharacter *, FVector>(this, "APrimalCharacter.GetNearestBoneIndexForDrag", Character, HitLocation); }
	void TryDragCharacter() { NativeCall<void>(this, "APrimalCharacter.TryDragCharacter"); }
	void UpdateDragging() { NativeCall<void>(this, "APrimalCharacter.UpdateDragging"); }
	void OnBeginDrag_Implementation(APrimalCharacter * Dragged, int BoneIndex, bool bWithGrapHook) { NativeCall<void, APrimalCharacter *, int, bool>(this, "APrimalCharacter.OnBeginDrag_Implementation", Dragged, BoneIndex, bWithGrapHook); }
	void OnEndDrag_Implementation() { NativeCall<void>(this, "APrimalCharacter.OnEndDrag_Implementation"); }
	void OnBeginDragged(APrimalCharacter * Dragger) { NativeCall<void, APrimalCharacter *>(this, "APrimalCharacter.OnBeginDragged", Dragger); }
	void OnEndDragged(APrimalCharacter * Dragger) { NativeCall<void, APrimalCharacter *>(this, "APrimalCharacter.OnEndDragged", Dragger); }
	bool CanBeCarried(APrimalCharacter * ByCarrier) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalCharacter.CanBeCarried", ByCarrier); }
	float GetKillXP() { return NativeCall<float>(this, "APrimalCharacter.GetKillXP"); }
	void UpdateIK() { NativeCall<void>(this, "APrimalCharacter.UpdateIK"); }
	void SetEnableIK(bool bEnable, bool bForceOnDedicated) { NativeCall<void, bool, bool>(this, "APrimalCharacter.SetEnableIK", bEnable, bForceOnDedicated); }
	bool TryMultiUse(APlayerController * ForPC, int UseIndex) { return NativeCall<bool, APlayerController *, int>(this, "APrimalCharacter.TryMultiUse", ForPC, UseIndex); }
	void ClientMultiUse(APlayerController * ForPC, int UseIndex) { NativeCall<void, APlayerController *, int>(this, "APrimalCharacter.ClientMultiUse", ForPC, UseIndex); }
	void ForceTickPoseDelta() { NativeCall<void>(this, "APrimalCharacter.ForceTickPoseDelta"); }
	void CheckJumpOutOfWater() { NativeCall<void>(this, "APrimalCharacter.CheckJumpOutOfWater"); }
	bool IsTargetableDead() { return NativeCall<bool>(this, "APrimalCharacter.IsTargetableDead"); }
	EShooterPhysMaterialType::Type GetTargetableDamageFXDefaultPhysMaterial() { return NativeCall<EShooterPhysMaterialType::Type>(this, "APrimalCharacter.GetTargetableDamageFXDefaultPhysMaterial"); }
	void Poop(bool bForcePoop) { NativeCall<void, bool>(this, "APrimalCharacter.Poop", bForcePoop); }
	void EmitPoop() { NativeCall<void>(this, "APrimalCharacter.EmitPoop"); }
	bool IsValidForStatusRecovery() { return NativeCall<bool>(this, "APrimalCharacter.IsValidForStatusRecovery"); }
	bool GetGroundLocation(FVector * theGroundLoc, FVector * OffsetUp, FVector * OffsetDown) { return NativeCall<bool, FVector *, FVector *, FVector *>(this, "APrimalCharacter.GetGroundLocation", theGroundLoc, OffsetUp, OffsetDown); }
	void DeathHarvestingFadeOut_Implementation() { NativeCall<void>(this, "APrimalCharacter.DeathHarvestingFadeOut_Implementation"); }
	void ServerUploadCharacter(AShooterPlayerController * UploadedBy) { NativeCall<void, AShooterPlayerController *>(this, "APrimalCharacter.ServerUploadCharacter", UploadedBy); }
	FRotator * GetBaseAimRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "APrimalCharacter.GetBaseAimRotation", result); }
	void ApplyDamageMomentum(float DamageTaken, FDamageEvent * DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "APrimalCharacter.ApplyDamageMomentum", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	void NetAddCharacterMovementImpulse_Implementation(FVector Impulse, bool bVelChange, float ImpulseExponent, bool bSetNewMovementMode, EMovementMode NewMovementMode, bool bOverrideMaxImpulseZ) { NativeCall<void, FVector, bool, float, bool, EMovementMode, bool>(this, "APrimalCharacter.NetAddCharacterMovementImpulse_Implementation", Impulse, bVelChange, ImpulseExponent, bSetNewMovementMode, NewMovementMode, bOverrideMaxImpulseZ); }
	void NetSetCharacterMovementVelocity_Implementation(bool bSetNewVelocity, FVector NewVelocity, bool bSetNewMovementMode, EMovementMode NewMovementMode) { NativeCall<void, bool, FVector, bool, EMovementMode>(this, "APrimalCharacter.NetSetCharacterMovementVelocity_Implementation", bSetNewVelocity, NewVelocity, bSetNewMovementMode, NewMovementMode); }
	bool AllowSaving() { return NativeCall<bool>(this, "APrimalCharacter.AllowSaving"); }
	bool IsWatered() { return NativeCall<bool>(this, "APrimalCharacter.IsWatered"); }
	void LoadedFromSaveGame() { NativeCall<void>(this, "APrimalCharacter.LoadedFromSaveGame"); }
	FVector * GetTargetingLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalCharacter.GetTargetingLocation", result); }
	void CheckJumpInput(float DeltaTime) { NativeCall<void, float>(this, "APrimalCharacter.CheckJumpInput", DeltaTime); }
	void ServerTryPoop_Implementation() { NativeCall<void>(this, "APrimalCharacter.ServerTryPoop_Implementation"); }
	void ClientFailedPoop_Implementation() { NativeCall<void>(this, "APrimalCharacter.ClientFailedPoop_Implementation"); }
	void ClientDidPoop_Implementation() { NativeCall<void>(this, "APrimalCharacter.ClientDidPoop_Implementation"); }
	void TryAccessInventoryWrapper() { NativeCall<void>(this, "APrimalCharacter.TryAccessInventoryWrapper"); }
	bool TryAccessInventory() { return NativeCall<bool>(this, "APrimalCharacter.TryAccessInventory"); }
	bool IsRagdolled() { return NativeCall<bool>(this, "APrimalCharacter.IsRagdolled"); }
	static void ForceUpdateAimedCharacters(UWorld * World, FVector * StartLoc, FVector * EndLoc, AActor * IgnoreActor, bool bForceUpdateIgnoreActor, float TraceRadius) { NativeCall<void, UWorld *, FVector *, FVector *, AActor *, bool, float>(nullptr, "APrimalCharacter.ForceUpdateAimedCharacters", World, StartLoc, EndLoc, IgnoreActor, bForceUpdateIgnoreActor, TraceRadius); }
	void NetForceUpdateAimedCharacters_Implementation(FVector StartLoc, FVector EndLoc, AActor * IgnoreActor, bool bForceUpdateIgnoreActor, float TraceRadius) { NativeCall<void, FVector, FVector, AActor *, bool, float>(this, "APrimalCharacter.NetForceUpdateAimedCharacters_Implementation", StartLoc, EndLoc, IgnoreActor, bForceUpdateIgnoreActor, TraceRadius); }
	bool HasBuff(TSubclassOf<APrimalBuff> BuffClass, bool useExactMatch) { return NativeCall<bool, TSubclassOf<APrimalBuff>, bool>(this, "APrimalCharacter.HasBuff", BuffClass, useExactMatch); }
	APrimalBuff * GetBuff(TSubclassOf<APrimalBuff> BuffClass) { return NativeCall<APrimalBuff *, TSubclassOf<APrimalBuff>>(this, "APrimalCharacter.GetBuff", BuffClass); }
	APrimalBuff * GetBuffForPostEffect(UMaterialInterface * anEffect) { return NativeCall<APrimalBuff *, UMaterialInterface *>(this, "APrimalCharacter.GetBuffForPostEffect", anEffect); }
	void RemoveAllJumpDeactivatedBuffs(APrimalBuff * IgnoredBuff) { NativeCall<void, APrimalBuff *>(this, "APrimalCharacter.RemoveAllJumpDeactivatedBuffs", IgnoredBuff); }
	void AttachGPSTransponder(APrimalStructureExplosiveTransGPS * Transponder) { NativeCall<void, APrimalStructureExplosiveTransGPS *>(this, "APrimalCharacter.AttachGPSTransponder", Transponder); }
	void UpdateNetDynamicMusic() { NativeCall<void>(this, "APrimalCharacter.UpdateNetDynamicMusic"); }
	void NetPlaySoundOnCharacter_Implementation(USoundBase * SoundToPlay, bool bPlayOnOwner) { NativeCall<void, USoundBase *, bool>(this, "APrimalCharacter.NetPlaySoundOnCharacter_Implementation", SoundToPlay, bPlayOnOwner); }
	bool IsMeshGameplayRelevant() { return NativeCall<bool>(this, "APrimalCharacter.IsMeshGameplayRelevant"); }
	float GetCorpseDecayRate() { return NativeCall<float>(this, "APrimalCharacter.GetCorpseDecayRate"); }
	void TagFriendlyStructures() { NativeCall<void>(this, "APrimalCharacter.TagFriendlyStructures"); }
	void OnAttachedToCharacter() { NativeCall<void>(this, "APrimalCharacter.OnAttachedToCharacter"); }
	void OnDetachedFromCharacter(APrimalCharacter * aCharacter, int OverrideDirection) { NativeCall<void, APrimalCharacter *, int>(this, "APrimalCharacter.OnDetachedFromCharacter", aCharacter, OverrideDirection); }
	void ClearMountedDino(bool fromMountedDino) { NativeCall<void, bool>(this, "APrimalCharacter.ClearMountedDino", fromMountedDino); }
	bool DinoMountOnMe(APrimalDinoCharacter * dinoCharacter) { return NativeCall<bool, APrimalDinoCharacter *>(this, "APrimalCharacter.DinoMountOnMe", dinoCharacter); }
	bool CanMountOnMe(APrimalDinoCharacter * dinoCharacter) { return NativeCall<bool, APrimalDinoCharacter *>(this, "APrimalCharacter.CanMountOnMe", dinoCharacter); }
	void OnRep_MountedDino() { NativeCall<void>(this, "APrimalCharacter.OnRep_MountedDino"); }
	float GetDragWeight(APrimalCharacter * ForDragger) { return NativeCall<float, APrimalCharacter *>(this, "APrimalCharacter.GetDragWeight", ForDragger); }
	void SetBase(UPrimitiveComponent * NewBaseComponent, FName BoneName, bool bNotifyPawn) { NativeCall<void, UPrimitiveComponent *, FName, bool>(this, "APrimalCharacter.SetBase", NewBaseComponent, BoneName, bNotifyPawn); }
	void UnPossessed() { NativeCall<void>(this, "APrimalCharacter.UnPossessed"); }
	void TryCallAttackTarget() { NativeCall<void>(this, "APrimalCharacter.TryCallAttackTarget"); }
	void TryCallMoveTo() { NativeCall<void>(this, "APrimalCharacter.TryCallMoveTo"); }
	UTexture2D * GetOverrideDefaultCharacterParamTexture(FName theParamName, UTexture2D * CurrentTexture) { return NativeCall<UTexture2D *, FName, UTexture2D *>(this, "APrimalCharacter.GetOverrideDefaultCharacterParamTexture", theParamName, CurrentTexture); }
	bool CanBePainted() { return NativeCall<bool>(this, "APrimalCharacter.CanBePainted"); }
	UPaintingTexture * GetPaintingTexture() { return NativeCall<UPaintingTexture *>(this, "APrimalCharacter.GetPaintingTexture"); }
	bool AllowColoringBy(APlayerController * ForPC, UObject * anItem) { return NativeCall<bool, APlayerController *, UObject *>(this, "APrimalCharacter.AllowColoringBy", ForPC, anItem); }
	void NetStopAllAnimMontage_Implementation() { NativeCall<void>(this, "APrimalCharacter.NetStopAllAnimMontage_Implementation"); }
	void DeactivateBuffs(TSubclassOf<APrimalBuff> ForBuffClass, UPrimalItem * ForInstigatorItem, bool perfectClassMatch) { NativeCall<void, TSubclassOf<APrimalBuff>, UPrimalItem *, bool>(this, "APrimalCharacter.DeactivateBuffs", ForBuffClass, ForInstigatorItem, perfectClassMatch); }
	bool ExcludePostProcessBlendableMaterial(UMaterialInterface * BlendableMaterialInterface) { return NativeCall<bool, UMaterialInterface *>(this, "APrimalCharacter.ExcludePostProcessBlendableMaterial", BlendableMaterialInterface); }
	FVector * GetVelocity(FVector * result, bool bIsForRagdoll) { return NativeCall<FVector *, FVector *, bool>(this, "APrimalCharacter.GetVelocity", result, bIsForRagdoll); }
	void TryCallStayOne() { NativeCall<void>(this, "APrimalCharacter.TryCallStayOne"); }
	void TryCallFollowOne() { NativeCall<void>(this, "APrimalCharacter.TryCallFollowOne"); }
	void TryCallFollowDistanceCycleOne() { NativeCall<void>(this, "APrimalCharacter.TryCallFollowDistanceCycleOne"); }
	void OnRep_AttachmentReplication() { NativeCall<void>(this, "APrimalCharacter.OnRep_AttachmentReplication"); }
	bool SimulatedPreventBasedPhysics() { return NativeCall<bool>(this, "APrimalCharacter.SimulatedPreventBasedPhysics"); }
	APrimalDinoCharacter * GetBasedOnDino() { return NativeCall<APrimalDinoCharacter *>(this, "APrimalCharacter.GetBasedOnDino"); }
	FVector * GetTargetPathfindingLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalCharacter.GetTargetPathfindingLocation", result); }
	void ClientHandleNetDestroy() { NativeCall<void>(this, "APrimalCharacter.ClientHandleNetDestroy"); }
	bool UseClearOnConsumeInput() { return NativeCall<bool>(this, "APrimalCharacter.UseClearOnConsumeInput"); }
	float GetDamageTorpidityIncreaseMultiplierScale() { return NativeCall<float>(this, "APrimalCharacter.GetDamageTorpidityIncreaseMultiplierScale"); }
	float GetIndirectTorpidityIncreaseMultiplierScale() { return NativeCall<float>(this, "APrimalCharacter.GetIndirectTorpidityIncreaseMultiplierScale"); }
	void NotifyBumpedByPawn(APrimalCharacter * ByPawn) { NativeCall<void, APrimalCharacter *>(this, "APrimalCharacter.NotifyBumpedByPawn", ByPawn); }
	void NotifyBumpedPawn(APawn * BumpedPawn) { NativeCall<void, APawn *>(this, "APrimalCharacter.NotifyBumpedPawn", BumpedPawn); }
	void PossessedBy(AController * NewController) { NativeCall<void, AController *>(this, "APrimalCharacter.PossessedBy", NewController); }
	void BPNetAddCharacterMovementImpulse(FVector Impulse, bool bVelChange, float ImpulseExponent, bool bSetNewMovementMode, EMovementMode NewMovementMode, bool bOverrideMaxImpulseZ, bool bApplyToBigPawns) { NativeCall<void, FVector, bool, float, bool, EMovementMode, bool, bool>(this, "APrimalCharacter.BPNetAddCharacterMovementImpulse", Impulse, bVelChange, ImpulseExponent, bSetNewMovementMode, NewMovementMode, bOverrideMaxImpulseZ, bApplyToBigPawns); }
	void BPNetSetCharacterMovementVelocity(bool bSetNewVelocity, FVector NewVelocity, bool bSetNewMovementMode, EMovementMode NewMovementMode) { NativeCall<void, bool, FVector, bool, EMovementMode>(this, "APrimalCharacter.BPNetSetCharacterMovementVelocity", bSetNewVelocity, NewVelocity, bSetNewMovementMode, NewMovementMode); }
	float GetGravityZScale() { return NativeCall<float>(this, "APrimalCharacter.GetGravityZScale"); }
	void OnMovementModeChanged(EMovementMode PrevMovementMode, char PreviousCustomMode) { NativeCall<void, EMovementMode, char>(this, "APrimalCharacter.OnMovementModeChanged", PrevMovementMode, PreviousCustomMode); }
	void EnableBPTimerServer(bool bEnable) { NativeCall<void, bool>(this, "APrimalCharacter.EnableBPTimerServer", bEnable); }
	void EnableBPTimerNonDedicated(bool bEnable) { NativeCall<void, bool>(this, "APrimalCharacter.EnableBPTimerNonDedicated", bEnable); }
	void CheckRagdollPenetration() { NativeCall<void>(this, "APrimalCharacter.CheckRagdollPenetration"); }
	APrimalStructureExplosive * GetAttachedExplosive() { return NativeCall<APrimalStructureExplosive *>(this, "APrimalCharacter.GetAttachedExplosive"); }
	bool IsInVacuumSealedSpace() { return NativeCall<bool>(this, "APrimalCharacter.IsInVacuumSealedSpace"); }
	void DownCallOne() { NativeCall<void>(this, "APrimalCharacter.DownCallOne"); }
	float BPModifyFOV_Implementation(float FOVIn) { return NativeCall<float, float>(this, "APrimalCharacter.BPModifyFOV_Implementation", FOVIn); }
	FVector * OverrideNewFallVelocity(FVector * result, FVector * InitialVelocity, FVector * Gravity, float DeltaTime) { return NativeCall<FVector *, FVector *, FVector *, FVector *, float>(this, "APrimalCharacter.OverrideNewFallVelocity", result, InitialVelocity, Gravity, DeltaTime); }
	void SetDynamicMusic(USoundBase * newMusic) { NativeCall<void, USoundBase *>(this, "APrimalCharacter.SetDynamicMusic", newMusic); }
	bool PreventsTargeting_Implementation(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalCharacter.PreventsTargeting_Implementation", ByActor); }
	bool PreventInputType(EPrimalCharacterInputType::Type inputType) { return NativeCall<bool, EPrimalCharacterInputType::Type>(this, "APrimalCharacter.PreventInputType", inputType); }
	bool IsAlliedWithOtherTeam(int OtherTeamID) { return NativeCall<bool, int>(this, "APrimalCharacter.IsAlliedWithOtherTeam", OtherTeamID); }
	void ResetCollisionSweepLocation(FVector * newLocation) { NativeCall<void, FVector *>(this, "APrimalCharacter.ResetCollisionSweepLocation", newLocation); }
	void DidTeleport_Implementation(FVector newLoc, FRotator newRot) { NativeCall<void, FVector, FRotator>(this, "APrimalCharacter.DidTeleport_Implementation", newLoc, newRot); }
	void FinalLoadedFromSaveGame() { NativeCall<void>(this, "APrimalCharacter.FinalLoadedFromSaveGame"); }
	void DoExecuteActorConstruction(FTransform * Transform, bool bIsDefaultTransform) { NativeCall<void, FTransform *, bool>(this, "APrimalCharacter.DoExecuteActorConstruction", Transform, bIsDefaultTransform); }
	void UpdateSimulatedPosition(FVector * NewLocation, FRotator * NewRotation) { NativeCall<void, FVector *, FRotator *>(this, "APrimalCharacter.UpdateSimulatedPosition", NewLocation, NewRotation); }
	void NotifyItemQuantityUpdated(UPrimalItem * anItem, int amount) { NativeCall<void, UPrimalItem *, int>(this, "APrimalCharacter.NotifyItemQuantityUpdated", anItem, amount); }
	void NotifyItemAdded(UPrimalItem * anItem, bool bEquipItem) { NativeCall<void, UPrimalItem *, bool>(this, "APrimalCharacter.NotifyItemAdded", anItem, bEquipItem); }
	void NotifyItemRemoved(UPrimalItem * anItem) { NativeCall<void, UPrimalItem *>(this, "APrimalCharacter.NotifyItemRemoved", anItem); }
	void TeleportSucceeded(bool bIsATest, bool bSimpleTeleport) { NativeCall<void, bool, bool>(this, "APrimalCharacter.TeleportSucceeded", bIsATest, bSimpleTeleport); }
	bool IsAttachedToSomething() { return NativeCall<bool>(this, "APrimalCharacter.IsAttachedToSomething"); }
	bool UseFastTurretTargeting() { return NativeCall<bool>(this, "APrimalCharacter.UseFastTurretTargeting"); }
	bool IsProneOrSitting(bool bIgnoreLockedToSeat) { return NativeCall<bool, bool>(this, "APrimalCharacter.IsProneOrSitting", bIgnoreLockedToSeat); }
	bool CharacterIsCarriedAsPassenger() { return NativeCall<bool>(this, "APrimalCharacter.CharacterIsCarriedAsPassenger"); }
	void DoCharacterDetachment(bool bIncludeRiding, bool bIncludeCarrying, APrimalBuff * BuffToIgnore) { NativeCall<void, bool, bool, APrimalBuff *>(this, "APrimalCharacter.DoCharacterDetachment", bIncludeRiding, bIncludeCarrying, BuffToIgnore); }
	bool IsCharacterHardAttached(bool bIgnoreRiding, bool bIgnoreCarried) { return NativeCall<bool, bool, bool>(this, "APrimalCharacter.IsCharacterHardAttached", bIgnoreRiding, bIgnoreCarried); }
	void InitializedAnimScriptInstance() { NativeCall<void>(this, "APrimalCharacter.InitializedAnimScriptInstance"); }
	bool ForceAddUnderwaterCharacterStatusValues() { return NativeCall<bool>(this, "APrimalCharacter.ForceAddUnderwaterCharacterStatusValues"); }
	bool IsPrimalCharFriendly(APrimalCharacter * primalChar) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalCharacter.IsPrimalCharFriendly", primalChar); }
	bool TeleportTo(FVector * DestLocation, FRotator * DestRotation, bool bIsATest, bool bNoCheck) { return NativeCall<bool, FVector *, FRotator *, bool, bool>(this, "APrimalCharacter.TeleportTo", DestLocation, DestRotation, bIsATest, bNoCheck); }
	UObject * GetUObjectInterfaceTargetableInterface() { return NativeCall<UObject *>(this, "APrimalCharacter.GetUObjectInterfaceTargetableInterface"); }
	float GetBaseDragWeight() { return NativeCall<float>(this, "APrimalCharacter.GetBaseDragWeight"); }
	static void StaticRegisterNativesAPrimalCharacter() { NativeCall<void>(nullptr, "APrimalCharacter.StaticRegisterNativesAPrimalCharacter"); }
	float BPAdjustDamage(float IncomingDamage, FDamageEvent TheDamageEvent, AController * EventInstigator, AActor * DamageCauser, bool bIsPointDamage, FHitResult PointHitInfo) { return NativeCall<float, float, FDamageEvent, AController *, AActor *, bool, FHitResult>(this, "APrimalCharacter.BPAdjustDamage", IncomingDamage, TheDamageEvent, EventInstigator, DamageCauser, bIsPointDamage, PointHitInfo); }
	FRotator * BPCameraBaseOrientation(FRotator * result, APrimalCharacter * viewingCharacter) { return NativeCall<FRotator *, FRotator *, APrimalCharacter *>(this, "APrimalCharacter.BPCameraBaseOrientation", result, viewingCharacter); }
	FRotator * BPCameraRotationFinal(FRotator * result, APrimalCharacter * viewingCharacter, FRotator * InCurrentFinalRot) { return NativeCall<FRotator *, FRotator *, APrimalCharacter *, FRotator *>(this, "APrimalCharacter.BPCameraRotationFinal", result, viewingCharacter, InCurrentFinalRot); }
	bool BPCanNotifyTeamAggroAI(APrimalDinoCharacter * Dino) { return NativeCall<bool, APrimalDinoCharacter *>(this, "APrimalCharacter.BPCanNotifyTeamAggroAI", Dino); }
	FVector * BPGetFPVViewLocation(FVector * result, APrimalCharacter * viewingCharacter) { return NativeCall<FVector *, FVector *, APrimalCharacter *>(this, "APrimalCharacter.BPGetFPVViewLocation", result, viewingCharacter); }
	float BPModifyViewHitDir(APrimalCharacter * viewingCharacter, float InViewHitDir) { return NativeCall<float, APrimalCharacter *, float>(this, "APrimalCharacter.BPModifyViewHitDir", viewingCharacter, InViewHitDir); }
	void BPNotifyLevelUp(int ExtraCharacterLevel) { NativeCall<void, int>(this, "APrimalCharacter.BPNotifyLevelUp", ExtraCharacterLevel); }
	FVector * BPOverrideCharacterNewFallVelocity(FVector * result, FVector * InitialVelocity, FVector * Gravity, float DeltaTime) { return NativeCall<FVector *, FVector *, FVector *, FVector *, float>(this, "APrimalCharacter.BPOverrideCharacterNewFallVelocity", result, InitialVelocity, Gravity, DeltaTime); }
	bool BPOverrideFPVViewLocation(APrimalCharacter * viewingCharacter) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalCharacter.BPOverrideFPVViewLocation", viewingCharacter); }
	void LocalUnpossessed() { NativeCall<void>(this, "APrimalCharacter.LocalUnpossessed"); }
	void NetPlaySoundOnCharacter(USoundBase * SoundToPlay, bool bPlayOnOwner) { NativeCall<void, USoundBase *, bool>(this, "APrimalCharacter.NetPlaySoundOnCharacter", SoundToPlay, bPlayOnOwner); }
	void NetUpdateTribeName(FString * NewTribeName) { NativeCall<void, FString *>(this, "APrimalCharacter.NetUpdateTribeName", NewTribeName); }
	void OnBeginDrag(APrimalCharacter * Dragged, int BoneIndex, bool bWithGrapHook) { NativeCall<void, APrimalCharacter *, int, bool>(this, "APrimalCharacter.OnBeginDrag", Dragged, BoneIndex, bWithGrapHook); }
	void OnEndDrag() { NativeCall<void>(this, "APrimalCharacter.OnEndDrag"); }
	void PlayDyingGeneric(float KillingDamage, FDamageEvent DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayDyingGeneric", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayDyingPoint(float KillingDamage, FPointDamageEvent DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FPointDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayDyingPoint", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayDyingRadial(float KillingDamage, FRadialDamageEvent DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FRadialDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayDyingRadial", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void PlayHitEffectPoint(float DamageTaken, FPointDamageEvent DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FPointDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayHitEffectPoint", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	void PlayHitEffectRadial(float DamageTaken, FRadialDamageEvent DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FRadialDamageEvent, APawn *, AActor *>(this, "APrimalCharacter.PlayHitEffectRadial", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	bool PreventsTargeting(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalCharacter.PreventsTargeting", ByActor); }
	void ServerCallAggressive() { NativeCall<void>(this, "APrimalCharacter.ServerCallAggressive"); }
	void ServerCallFollow() { NativeCall<void>(this, "APrimalCharacter.ServerCallFollow"); }
	void ServerCallNeutral() { NativeCall<void>(this, "APrimalCharacter.ServerCallNeutral"); }
	void ServerCallPassive() { NativeCall<void>(this, "APrimalCharacter.ServerCallPassive"); }
	void ServerCallSetAggressive() { NativeCall<void>(this, "APrimalCharacter.ServerCallSetAggressive"); }
	void ServerCallStay() { NativeCall<void>(this, "APrimalCharacter.ServerCallStay"); }
	void ServerDinoOrder(APrimalDinoCharacter * aDino, EDinoTamedOrder::Type OrderType, AActor * target) { NativeCall<void, APrimalDinoCharacter *, EDinoTamedOrder::Type, AActor *>(this, "APrimalCharacter.ServerDinoOrder", aDino, OrderType, target); }
	void ServerGiveDefaultWeapon() { NativeCall<void>(this, "APrimalCharacter.ServerGiveDefaultWeapon"); }
	void ServerRequestDrag() { NativeCall<void>(this, "APrimalCharacter.ServerRequestDrag"); }
	void ServerTryPoop() { NativeCall<void>(this, "APrimalCharacter.ServerTryPoop"); }
};

struct AShooterCharacter : APrimalCharacter
{
	FieldValue<UAnimMontage *> SpawnIntroAnim1PField() { return { this, "AShooterCharacter.SpawnIntroAnim1P" }; }
	FieldValue<UAnimMontage *> RespawnIntroAnim1PField() { return { this, "AShooterCharacter.RespawnIntroAnim1P" }; }
	FieldValue<UAnimMontage *> ProneInAnimField() { return { this, "AShooterCharacter.ProneInAnim" }; }
	FieldValue<UAnimMontage *> ProneOutAnimField() { return { this, "AShooterCharacter.ProneOutAnim" }; }
	FieldValue<UAnimMontage *> StartRidingAnimField() { return { this, "AShooterCharacter.StartRidingAnim" }; }
	FieldValue<UAnimMontage *> StopRidingAnimField() { return { this, "AShooterCharacter.StopRidingAnim" }; }
	FieldValue<UAnimMontage *> TalkingAnimField() { return { this, "AShooterCharacter.TalkingAnim" }; }
	FieldValue<UAnimMontage *> VoiceTalkingAnimField() { return { this, "AShooterCharacter.VoiceTalkingAnim" }; }
	FieldValue<TArray<UAnimMontage *>> EmoteAnimsField() { return { this, "AShooterCharacter.EmoteAnims" }; }
	FieldValue<UAnimMontage *> FireBallistaAnimationField() { return { this, "AShooterCharacter.FireBallistaAnimation" }; }
	FieldValue<UAnimMontage *> ReloadBallistaAnimationField() { return { this, "AShooterCharacter.ReloadBallistaAnimation" }; }
	FieldValue<UAnimMontage *> DraggingCharacterAnimField() { return { this, "AShooterCharacter.DraggingCharacterAnim" }; }
	FieldValue<bool> bWasProneField() { return { this, "AShooterCharacter.bWasProne" }; }
	FieldValue<bool> bIsPreviewCharacterField() { return { this, "AShooterCharacter.bIsPreviewCharacter" }; }
	FieldValue<bool> bIsVoiceTalkingField() { return { this, "AShooterCharacter.bIsVoiceTalking" }; }
	FieldValue<long double> LastStartedTalkingTimeField() { return { this, "AShooterCharacter.LastStartedTalkingTime" }; }
	FieldValue<long double> DontTargetUntilTimeField() { return { this, "AShooterCharacter.DontTargetUntilTime" }; }
	FieldValue<float> OriginalCollisionHeightField() { return { this, "AShooterCharacter.OriginalCollisionHeight" }; }
	FieldValue<float> WalkBobMagnitudeField() { return { this, "AShooterCharacter.WalkBobMagnitude" }; }
	FieldValue<float> WalkBobInterpSpeedField() { return { this, "AShooterCharacter.WalkBobInterpSpeed" }; }
	FieldValue<float> TargetingTimeField() { return { this, "AShooterCharacter.TargetingTime" }; }
	FieldValue<float> BobMaxMovementSpeedField() { return { this, "AShooterCharacter.BobMaxMovementSpeed" }; }
	FieldValue<float> WeaponBobMaxMovementSpeedField() { return { this, "AShooterCharacter.WeaponBobMaxMovementSpeed" }; }
	FieldValue<TSubclassOf<AShooterWeapon>> DefaultWeaponField() { return { this, "AShooterCharacter.DefaultWeapon" }; }
	FieldValue<TSubclassOf<AShooterWeapon>> MapWeaponField() { return { this, "AShooterCharacter.MapWeapon" }; }
	FieldValue<TSubclassOf<AShooterWeapon>> GPSWeaponField() { return { this, "AShooterCharacter.GPSWeapon" }; }
	FieldValue<TSubclassOf<AShooterWeapon>> CompassWeaponField() { return { this, "AShooterCharacter.CompassWeapon" }; }
	FieldValue<FString> PlayerNameField() { return { this, "AShooterCharacter.PlayerName" }; }
	FieldValue<TWeakObjectPtr<APrimalDinoCharacter>> RidingDinoField() { return { this, "AShooterCharacter.RidingDino" }; }
	FieldValue<TArray<FName>> LowerBodyPartRootBonesField() { return { this, "AShooterCharacter.LowerBodyPartRootBones" }; }
	FieldValue<UAnimMontage *> DropItemAnimationField() { return { this, "AShooterCharacter.DropItemAnimation" }; }
	FieldValue<UAnimMontage *> ThrowItemAnimationField() { return { this, "AShooterCharacter.ThrowItemAnimation" }; }
	FieldValue<UAnimMontage *> PickupItemAnimationField() { return { this, "AShooterCharacter.PickupItemAnimation" }; }
	FieldValue<UAnimMontage *> ActivateInventoryAnimationField() { return { this, "AShooterCharacter.ActivateInventoryAnimation" }; }
	FieldValue<FRotator> LastDinoAimRotationOffsetField() { return { this, "AShooterCharacter.LastDinoAimRotationOffset" }; }
	FieldValue<FRotator> LastAimRotOffsetField() { return { this, "AShooterCharacter.LastAimRotOffset" }; }
	FieldValue<UAudioComponent *> LastGrapHookACField() { return { this, "AShooterCharacter.LastGrapHookAC" }; }
	FieldValue<int> _GrapHookCableObjectCountField() { return { this, "AShooterCharacter._GrapHookCableObjectCount" }; }
	FieldValue<FVector> GrapHookDefaultOffsetField() { return { this, "AShooterCharacter.GrapHookDefaultOffset" }; }
	FieldValue<float> GrapHookCableWidthField() { return { this, "AShooterCharacter.GrapHookCableWidth" }; }
	FieldValue<UMaterialInterface *> GrapHookMaterialField() { return { this, "AShooterCharacter.GrapHookMaterial" }; }
	FieldValue<float> LadderLateralJumpVelocityField() { return { this, "AShooterCharacter.LadderLateralJumpVelocity" }; }
	FieldValue<float> GrapHookPulledRopeDistanceField() { return { this, "AShooterCharacter.GrapHookPulledRopeDistance" }; }
	FieldValue<float> GrapHookSyncTimeField() { return { this, "AShooterCharacter.GrapHookSyncTime" }; }
	FieldValue<bool> bReleasingGrapHookField() { return { this, "AShooterCharacter.bReleasingGrapHook" }; }
	FieldValue<FString> PlatformProfileNameField() { return { this, "AShooterCharacter.PlatformProfileName" }; }
	FieldValue<FUniqueNetIdRepl> PlatformProfileIDField() { return { this, "AShooterCharacter.PlatformProfileID" }; }
	FieldValue<UAudioComponent *> CharacterStatusStateSoundComponentField() { return { this, "AShooterCharacter.CharacterStatusStateSoundComponent" }; }
	FieldValue<long double> LastUncrouchTimeField() { return { this, "AShooterCharacter.LastUncrouchTime" }; }
	FieldValue<long double> LastUnproneTimeField() { return { this, "AShooterCharacter.LastUnproneTime" }; }
	FieldValue<float> CurrentWeaponBobSpeedField() { return { this, "AShooterCharacter.CurrentWeaponBobSpeed" }; }
	FieldValue<float> WalkBobOldSpeedField() { return { this, "AShooterCharacter.WalkBobOldSpeed" }; }
	FieldValue<float> AppliedBobField() { return { this, "AShooterCharacter.AppliedBob" }; }
	FieldValue<float> BobTimeField() { return { this, "AShooterCharacter.BobTime" }; }
	FieldValue<long double> LastPressReloadTimeField() { return { this, "AShooterCharacter.LastPressReloadTime" }; }
	FieldValue<FName> WeaponAttachPointField() { return { this, "AShooterCharacter.WeaponAttachPoint" }; }
	FieldValue<float> TargetingSpeedModifierField() { return { this, "AShooterCharacter.TargetingSpeedModifier" }; }
	FieldValue<USoundCue *> LowHealthSoundField() { return { this, "AShooterCharacter.LowHealthSound" }; }
	FieldValue<UAnimMontage *> CallFollowAnimField() { return { this, "AShooterCharacter.CallFollowAnim" }; }
	FieldValue<UAnimMontage *> CallStayAnimField() { return { this, "AShooterCharacter.CallStayAnim" }; }
	FieldValue<UAnimMontage *> CallFollowAnimSingleField() { return { this, "AShooterCharacter.CallFollowAnimSingle" }; }
	FieldValue<UAnimMontage *> CallStayAnimSingleField() { return { this, "AShooterCharacter.CallStayAnimSingle" }; }
	FieldValue<UAnimMontage *> CallMoveToAnimField() { return { this, "AShooterCharacter.CallMoveToAnim" }; }
	FieldValue<UAnimMontage *> CallAttackAnimField() { return { this, "AShooterCharacter.CallAttackAnim" }; }
	FieldValue<UAudioComponent *> LowHealthWarningPlayerField() { return { this, "AShooterCharacter.LowHealthWarningPlayer" }; }
	FieldValue<FItemNetID> NextWeaponItemIDField() { return { this, "AShooterCharacter.NextWeaponItemID" }; }
	FieldValue<float> WeaponBobTimeField() { return { this, "AShooterCharacter.WeaponBobTime" }; }
	FieldValue<float> CurrentAimBlendingField() { return { this, "AShooterCharacter.CurrentAimBlending" }; }
	FieldValue<long double> InterpLastCrouchProneStateChangeTimeField() { return { this, "AShooterCharacter.InterpLastCrouchProneStateChangeTime" }; }
	FieldValue<long double> PressCrouchProneToggleTimeField() { return { this, "AShooterCharacter.PressCrouchProneToggleTime" }; }
	FieldValue<float> CraftingMovementSpeedModifierField() { return { this, "AShooterCharacter.CraftingMovementSpeedModifier" }; }
	FieldValue<FVector> WeaponBobMagnitudesField() { return { this, "AShooterCharacter.WeaponBobMagnitudes" }; }
	FieldValue<FVector> WeaponBobPeriodsField() { return { this, "AShooterCharacter.WeaponBobPeriods" }; }
	FieldValue<FVector> WeaponBobOffsetsField() { return { this, "AShooterCharacter.WeaponBobOffsets" }; }
	FieldValue<FVector> WeaponBobMagnitudes_TargetingField() { return { this, "AShooterCharacter.WeaponBobMagnitudes_Targeting" }; }
	FieldValue<FVector> WeaponBobPeriods_TargetingField() { return { this, "AShooterCharacter.WeaponBobPeriods_Targeting" }; }
	FieldValue<FVector> WeaponBobOffsets_TargetingField() { return { this, "AShooterCharacter.WeaponBobOffsets_Targeting" }; }
	FieldValue<float> WeaponBobMinimumSpeedField() { return { this, "AShooterCharacter.WeaponBobMinimumSpeed" }; }
	FieldValue<float> WeaponBobSpeedBaseField() { return { this, "AShooterCharacter.WeaponBobSpeedBase" }; }
	FieldValue<float> WeaponBobSpeedBaseFallingField() { return { this, "AShooterCharacter.WeaponBobSpeedBaseFalling" }; }
	FieldValue<float> WeaponBobTargetingBlendField() { return { this, "AShooterCharacter.WeaponBobTargetingBlend" }; }
	FieldValue<TArray<FItemAttachmentInfo>> DefaultAttachmentInfosField() { return { this, "AShooterCharacter.DefaultAttachmentInfos" }; }
	FieldValue<USoundCue *> StartCrouchSoundField() { return { this, "AShooterCharacter.StartCrouchSound" }; }
	FieldValue<USoundCue *> EndCrouchSoundField() { return { this, "AShooterCharacter.EndCrouchSound" }; }
	FieldValue<USoundCue *> StartProneSoundField() { return { this, "AShooterCharacter.StartProneSound" }; }
	FieldValue<USoundCue *> EndProneSoundField() { return { this, "AShooterCharacter.EndProneSound" }; }
	FieldValue<TSubclassOf<AShooterWeapon>> NextInventoryWeaponField() { return { this, "AShooterCharacter.NextInventoryWeapon" }; }
	FieldValue<FItemNetID> PreMapWeaponItemNetIDField() { return { this, "AShooterCharacter.PreMapWeaponItemNetID" }; }
	FieldValue<float> ServerSeatedViewRotationYawField() { return { this, "AShooterCharacter.ServerSeatedViewRotationYaw" }; }
	FieldValue<float> ServerSeatedViewRotationPitchField() { return { this, "AShooterCharacter.ServerSeatedViewRotationPitch" }; }
	FieldValue<AShooterWeapon *> CurrentWeaponField() { return { this, "AShooterCharacter.CurrentWeapon" }; }
	FieldValue<unsigned __int64> LinkedPlayerDataIDField() { return { this, "AShooterCharacter.LinkedPlayerDataID" }; }
	FieldValue<long double> LastTimeInFallingField() { return { this, "AShooterCharacter.LastTimeInFalling" }; }
	FieldValue<long double> StartedRidingTimeField() { return { this, "AShooterCharacter.StartedRidingTime" }; }
	FieldValue<long double> TimeSinceLastControllerField() { return { this, "AShooterCharacter.TimeSinceLastController" }; }
	FieldValue<TWeakObjectPtr<AController>> LastControllerField() { return { this, "AShooterCharacter.LastController" }; }
	FieldValue<UAnimMontage *> DrinkingAnimationField() { return { this, "AShooterCharacter.DrinkingAnimation" }; }
	FieldValue<long double> LastRequestedTribeTimeField() { return { this, "AShooterCharacter.LastRequestedTribeTime" }; }
	FieldValue<unsigned __int64> LastRequestedTribeIDField() { return { this, "AShooterCharacter.LastRequestedTribeID" }; }
	FieldValue<FString> LastRequestedTribeNameField() { return { this, "AShooterCharacter.LastRequestedTribeName" }; }
	FieldValue<TWeakObjectPtr<AShooterCharacter>> LastRequestedTribePlayerCharacterField() { return { this, "AShooterCharacter.LastRequestedTribePlayerCharacter" }; }
	FieldValue<float> IndoorsHyperthermiaInsulationField() { return { this, "AShooterCharacter.IndoorsHyperthermiaInsulation" }; }
	FieldValue<float> IndoorsHypothermiaInsulationField() { return { this, "AShooterCharacter.IndoorsHypothermiaInsulation" }; }
	FieldValue<float> IndoorCheckIntervalField() { return { this, "AShooterCharacter.IndoorCheckInterval" }; }
	FieldValue<long double> LastIndoorCheckTimeField() { return { this, "AShooterCharacter.LastIndoorCheckTime" }; }
	FieldValue<FItemNetID> PreRidingWeaponItemNetIDField() { return { this, "AShooterCharacter.PreRidingWeaponItemNetID" }; }
	FieldValue<FItemNetID> PreInventoryWeaponItemNetIDField() { return { this, "AShooterCharacter.PreInventoryWeaponItemNetID" }; }
	FieldValue<UAnimSequence *> ViewingInventoryAnimationField() { return { this, "AShooterCharacter.ViewingInventoryAnimation" }; }
	FieldValue<UAnimSequence *> DefaultDinoRidingAnimationField() { return { this, "AShooterCharacter.DefaultDinoRidingAnimation" }; }
	FieldValue<UAnimSequence *> DefaultDinoRidingMoveAnimationField() { return { this, "AShooterCharacter.DefaultDinoRidingMoveAnimation" }; }
	FieldValue<UAnimSequence *> DefaultSeatingAnimationField() { return { this, "AShooterCharacter.DefaultSeatingAnimation" }; }
	FieldValue<UAnimSequence *> DefaultShieldAnimationField() { return { this, "AShooterCharacter.DefaultShieldAnimation" }; }
	FieldValue<UAnimMontage *> ShieldCoverAnimationField() { return { this, "AShooterCharacter.ShieldCoverAnimation" }; }
	FieldValue<UAnimMontage *> ShieldCoverAnimationForCrouchField() { return { this, "AShooterCharacter.ShieldCoverAnimationForCrouch" }; }
	FieldValue<float> EnemyPlayerMaxCursorHUDDistanceProneField() { return { this, "AShooterCharacter.EnemyPlayerMaxCursorHUDDistanceProne" }; }
	FieldValue<float> EnemyPlayerMaxCursorHUDDistanceCrouchedField() { return { this, "AShooterCharacter.EnemyPlayerMaxCursorHUDDistanceCrouched" }; }
	FieldValue<float> EnemyPlayerMaxCursorHUDDistanceStandingField() { return { this, "AShooterCharacter.EnemyPlayerMaxCursorHUDDistanceStanding" }; }
	FieldValue<FSaddlePassengerSeatDefinition> CurrentPassengerSeatDefinitionField() { return { this, "AShooterCharacter.CurrentPassengerSeatDefinition" }; }
	FieldValue<TArray<UAnimMontage *>> AnimsOverrideFromField() { return { this, "AShooterCharacter.AnimsOverrideFrom" }; }
	FieldValue<TArray<UAnimMontage *>> AnimOverrideToField() { return { this, "AShooterCharacter.AnimOverrideTo" }; }
	FieldValue<TArray<UAnimSequence *>> AnimSequencesOverrideFromField() { return { this, "AShooterCharacter.AnimSequencesOverrideFrom" }; }
	FieldValue<TArray<UAnimSequence *>> AnimSequenceOverrideToField() { return { this, "AShooterCharacter.AnimSequenceOverrideTo" }; }
	FieldValue<float> PreviousRootYawSpeedField() { return { this, "AShooterCharacter.PreviousRootYawSpeed" }; }
	FieldArray<FLinearColor, 4> BodyColorsField() { return { this, "AShooterCharacter.BodyColors" }; }
	FieldValue<char> FacialHairIndexField() { return { this, "AShooterCharacter.FacialHairIndex" }; }
	FieldValue<char> HeadHairIndexField() { return { this, "AShooterCharacter.HeadHairIndex" }; }
	FieldArray<float, 22> RawBoneModifiersField() { return { this, "AShooterCharacter.RawBoneModifiers" }; }
	FieldValue<float> LoggedOutTargetingDesirabilityField() { return { this, "AShooterCharacter.LoggedOutTargetingDesirability" }; }
	FieldValue<bool> bIsRainWateredField() { return { this, "AShooterCharacter.bIsRainWatered" }; }
	FieldValue<long double> LastAttackTimeField() { return { this, "AShooterCharacter.LastAttackTime" }; }
	FieldValue<bool> bCacheRidingDinoWeaponField() { return { this, "AShooterCharacter.bCacheRidingDinoWeapon" }; }
	FieldValue<bool> bWasLocallyControlledField() { return { this, "AShooterCharacter.bWasLocallyControlled" }; }
	FieldValue<unsigned int> UniqueNetIdTypeHashField() { return { this, "AShooterCharacter.UniqueNetIdTypeHash" }; }
	FieldValue<long double> LastUseHarvestTimeField() { return { this, "AShooterCharacter.LastUseHarvestTime" }; }
	FieldValue<long double> StopRidingTimeField() { return { this, "AShooterCharacter.StopRidingTime" }; }
	FieldValue<UAnimMontage *> SpawnAnimField() { return { this, "AShooterCharacter.SpawnAnim" }; }
	FieldValue<UAnimMontage *> FirstSpawnAnimField() { return { this, "AShooterCharacter.FirstSpawnAnim" }; }
	FieldValue<long double> LocalLastViewingInventoryTimeField() { return { this, "AShooterCharacter.LocalLastViewingInventoryTime" }; }
	FieldValue<FVector> LastStasisCastPositionField() { return { this, "AShooterCharacter.LastStasisCastPosition" }; }
	FieldValue<bool> bWasHostPlayerField() { return { this, "AShooterCharacter.bWasHostPlayer" }; }
	FieldValue<long double> LastTimeHadControllerField() { return { this, "AShooterCharacter.LastTimeHadController" }; }
	FieldValue<long double> LastTaggedTimeField() { return { this, "AShooterCharacter.LastTaggedTime" }; }
	FieldValue<long double> LastTaggedTimeExtraField() { return { this, "AShooterCharacter.LastTaggedTimeExtra" }; }
	FieldValue<long double> LastTaggedTimeThirdField() { return { this, "AShooterCharacter.LastTaggedTimeThird" }; }
	FieldValue<float> ExtraFloatVarField() { return { this, "AShooterCharacter.ExtraFloatVar" }; }
	FieldValue<FVector> ExtraVectorVarField() { return { this, "AShooterCharacter.ExtraVectorVar" }; }
	FieldValue<FVector> ExtraExtraVectorVarField() { return { this, "AShooterCharacter.ExtraExtraVectorVar" }; }
	FieldValue<FName> ExtraNameVarField() { return { this, "AShooterCharacter.ExtraNameVar" }; }
	FieldValue<bool> bIsOnSeatingStructureField() { return { this, "AShooterCharacter.bIsOnSeatingStructure" }; }
	FieldValue<bool> bIsControllingBallistaField() { return { this, "AShooterCharacter.bIsControllingBallista" }; }
	FieldValue<bool> bUseBallistaAimOffsetField() { return { this, "AShooterCharacter.bUseBallistaAimOffset" }; }
	FieldValue<float> CurrentControlledBallistaYawField() { return { this, "AShooterCharacter.CurrentControlledBallistaYaw" }; }
	FieldValue<bool> bIsServerAdminField() { return { this, "AShooterCharacter.bIsServerAdmin" }; }
	FieldValue<TWeakObjectPtr<APrimalStructureSeating>> SeatingStructureField() { return { this, "AShooterCharacter.SeatingStructure" }; }
	FieldValue<int> SeatingStructureSeatNumberField() { return { this, "AShooterCharacter.SeatingStructureSeatNumber" }; }
	FieldValue<long double> NextPlayerUndergroundCheckField() { return { this, "AShooterCharacter.NextPlayerUndergroundCheck" }; }
	FieldValue<int> PlayerNumUnderGroundFailField() { return { this, "AShooterCharacter.PlayerNumUnderGroundFail" }; }
	FieldValue<float> LastSweepCapsuleHeightField() { return { this, "AShooterCharacter.LastSweepCapsuleHeight" }; }
	FieldValue<float> LastSweepCapsuleRadiusField() { return { this, "AShooterCharacter.LastSweepCapsuleRadius" }; }
	FieldValue<USoundBase *> ThrowCharacterSoundField() { return { this, "AShooterCharacter.ThrowCharacterSound" }; }
	FieldValue<float> ClientSeatedViewRotationPitchField() { return { this, "AShooterCharacter.ClientSeatedViewRotationPitch" }; }
	FieldValue<float> ClientSeatedViewRotationYawField() { return { this, "AShooterCharacter.ClientSeatedViewRotationYaw" }; }
	FieldValue<long double> LastReleaseSeatingStructureTimeField() { return { this, "AShooterCharacter.LastReleaseSeatingStructureTime" }; }
	FieldValue<char> PlayerBadgeGroupField() { return { this, "AShooterCharacter.PlayerBadgeGroup" }; }
	FieldValue<bool> bShouldInvertTurnInputField() { return { this, "AShooterCharacter.bShouldInvertTurnInput" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> LastGrappledToCharacterField() { return { this, "AShooterCharacter.LastGrappledToCharacter" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> CurrentGrappledToCharacterField() { return { this, "AShooterCharacter.CurrentGrappledToCharacter" }; }
	FieldValue<int> AllianceInviteRequestingTeamField() { return { this, "AShooterCharacter.AllianceInviteRequestingTeam" }; }
	FieldValue<unsigned int> AllianceInviteIDField() { return { this, "AShooterCharacter.AllianceInviteID" }; }
	FieldValue<FString> AllianceInviteNameField() { return { this, "AShooterCharacter.AllianceInviteName" }; }
	FieldValue<long double> AllianceInviteTimeField() { return { this, "AShooterCharacter.AllianceInviteTime" }; }
	FieldValue<UAnimMontage *> MountedCarryingDinoAnimationField() { return { this, "AShooterCharacter.MountedCarryingDinoAnimation" }; }
	FieldValue<UAnimMontage *> CuddleAnimationField() { return { this, "AShooterCharacter.CuddleAnimation" }; }
	FieldValue<long double> LastUpdatedAimActorsTimeField() { return { this, "AShooterCharacter.LastUpdatedAimActorsTime" }; }
	FieldValue<FVector> UpdateHyperThermalInsulationPositionField() { return { this, "AShooterCharacter.UpdateHyperThermalInsulationPosition" }; }
	FieldValue<FVector> UpdateHypoThermalInsulationPositionField() { return { this, "AShooterCharacter.UpdateHypoThermalInsulationPosition" }; }
	FieldValue<long double> NextUpdateHyperThermalInsulationTimeField() { return { this, "AShooterCharacter.NextUpdateHyperThermalInsulationTime" }; }
	FieldValue<long double> NextUpdateHypoThermalInsulationTimeField() { return { this, "AShooterCharacter.NextUpdateHypoThermalInsulationTime" }; }
	FieldValue<float> LastAdditionalHypoThermalInsulationField() { return { this, "AShooterCharacter.LastAdditionalHypoThermalInsulation" }; }
	FieldValue<float> LastAdditionalHyperThermalInsulationField() { return { this, "AShooterCharacter.LastAdditionalHyperThermalInsulation" }; }
	FieldValue<float> WaterLossRateMultiplierField() { return { this, "AShooterCharacter.WaterLossRateMultiplier" }; }
	FieldValue<UAnimSequence *> CharacterAdditiveStandingAnimField() { return { this, "AShooterCharacter.CharacterAdditiveStandingAnim" }; }
	FieldValue<long double> LastTryAccessInventoryFailTimeField() { return { this, "AShooterCharacter.LastTryAccessInventoryFailTime" }; }
	FieldValue<long double> LastEmotePlayTimeField() { return { this, "AShooterCharacter.LastEmotePlayTime" }; }
	FieldValue<float> IntervalForFullHeadHairGrowthField() { return { this, "AShooterCharacter.IntervalForFullHeadHairGrowth" }; }
	FieldValue<float> IntervalForFullFacialHairGrowthField() { return { this, "AShooterCharacter.IntervalForFullFacialHairGrowth" }; }
	FieldValue<float> PercentOfFullFacialHairGrowthField() { return { this, "AShooterCharacter.PercentOfFullFacialHairGrowth" }; }
	FieldValue<float> PercentOfFullHeadHairGrowthField() { return { this, "AShooterCharacter.PercentOfFullHeadHairGrowth" }; }
	FieldValue<FLinearColor> OriginalHairColorField() { return { this, "AShooterCharacter.OriginalHairColor" }; }
	FieldValue<long double> LastEmoteTryPlayTimeField() { return { this, "AShooterCharacter.LastEmoteTryPlayTime" }; }
	FieldValue<int> IgnoreCollisionSweepUntilFrameNumberField() { return { this, "AShooterCharacter.IgnoreCollisionSweepUntilFrameNumber" }; }
	FieldValue<float> ReplicatedWeightField() { return { this, "AShooterCharacter.ReplicatedWeight" }; }
	FieldValue<long double> LocalDiedAtTimeField() { return { this, "AShooterCharacter.LocalDiedAtTime" }; }
	FieldValue<long double> LastNotStuckTimeField() { return { this, "AShooterCharacter.LastNotStuckTime" }; }
	FieldValue<USoundBase *> ProneMoveSoundField() { return { this, "AShooterCharacter.ProneMoveSound" }; }
	FieldValue<long double> UploadEarliestValidTimeField() { return { this, "AShooterCharacter.UploadEarliestValidTime" }; }
	FieldValue<long double> LastCollisionStuckTimeField() { return { this, "AShooterCharacter.LastCollisionStuckTime" }; }
	FieldValue<int> SimulatedLastFrameProcessedForceUpdateAimedActorsField() { return { this, "AShooterCharacter.SimulatedLastFrameProcessedForceUpdateAimedActors" }; }
	FieldValue<FVector> OriginalLastHitWallSweepCheckLocationField() { return { this, "AShooterCharacter.OriginalLastHitWallSweepCheckLocation" }; }
	FieldValue<int> LastCapsuleAttachmentChangedIncrementField() { return { this, "AShooterCharacter.LastCapsuleAttachmentChangedIncrement" }; }
	FieldValue<int> LastMeshAttachmentChangedIncrementField() { return { this, "AShooterCharacter.LastMeshAttachmentChangedIncrement" }; }
	FieldValue<int> LastCameraAttachmentChangedIncrementField() { return { this, "AShooterCharacter.LastCameraAttachmentChangedIncrement" }; }
	FieldValue<bool> bPreventWeaponMovementAnimsField() { return { this, "AShooterCharacter.bPreventWeaponMovementAnims" }; }
	FieldValue<TEnumAsByte<enum EPrimalStatsValueTypes::Type>> BestInstantShotResultField() { return { this, "AShooterCharacter.BestInstantShotResult" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bIsTargeting() { return { this, "AShooterCharacter.bIsTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bIsCrafting() { return { this, "AShooterCharacter.bIsCrafting" }; }
	BitFieldValue<bool, unsigned __int32> bIsRiding() { return { this, "AShooterCharacter.bIsRiding" }; }
	BitFieldValue<bool, unsigned __int32> bIsIndoors() { return { this, "AShooterCharacter.bIsIndoors" }; }
	BitFieldValue<bool, unsigned __int32> bIsClimbing() { return { this, "AShooterCharacter.bIsClimbing" }; }
	BitFieldValue<bool, unsigned __int32> bIsViewingInventory() { return { this, "AShooterCharacter.bIsViewingInventory" }; }
	BitFieldValue<bool, unsigned __int32> bUseAlternateFallBlendspace() { return { this, "AShooterCharacter.bUseAlternateFallBlendspace" }; }
	BitFieldValue<bool, unsigned __int32> bIsFemale() { return { this, "AShooterCharacter.bIsFemale" }; }
	BitFieldValue<bool, unsigned __int32> bPlaySpawnAnim() { return { this, "AShooterCharacter.bPlaySpawnAnim" }; }
	BitFieldValue<bool, unsigned __int32> bPlayFirstSpawnAnim() { return { this, "AShooterCharacter.bPlayFirstSpawnAnim" }; }
	BitFieldValue<bool, unsigned __int32> bNoPhysics() { return { this, "AShooterCharacter.bNoPhysics" }; }
	BitFieldValue<bool, unsigned __int32> bPossessionDontUnsleep() { return { this, "AShooterCharacter.bPossessionDontUnsleep" }; }
	BitFieldValue<bool, unsigned __int32> bLastViewingInventory() { return { this, "AShooterCharacter.bLastViewingInventory" }; }
	BitFieldValue<bool, unsigned __int32> bPlayedSpawnIntro() { return { this, "AShooterCharacter.bPlayedSpawnIntro" }; }
	BitFieldValue<bool, unsigned __int32> bWasSubmerged() { return { this, "AShooterCharacter.bWasSubmerged" }; }
	BitFieldValue<bool, unsigned __int32> bCheckPushedThroughWallsWasSeatingStructure() { return { this, "AShooterCharacter.bCheckPushedThroughWallsWasSeatingStructure" }; }
	BitFieldValue<bool, unsigned __int32> bGaveInitialItems() { return { this, "AShooterCharacter.bGaveInitialItems" }; }
	BitFieldValue<bool, unsigned __int32> bHadGrapHookAttachActor() { return { this, "AShooterCharacter.bHadGrapHookAttachActor" }; }
	BitFieldValue<bool, unsigned __int32> bAddedToActivePlayerList() { return { this, "AShooterCharacter.bAddedToActivePlayerList" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingShieldCoverAnimation() { return { this, "AShooterCharacter.bPlayingShieldCoverAnimation" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingShieldCoverAnimationForCrouch() { return { this, "AShooterCharacter.bPlayingShieldCoverAnimationForCrouch" }; }
	BitFieldValue<bool, unsigned __int32> bTriggerBPUnstasis() { return { this, "AShooterCharacter.bTriggerBPUnstasis" }; }
	BitFieldValue<bool, unsigned __int32> bWasFirstPerson() { return { this, "AShooterCharacter.bWasFirstPerson" }; }
	BitFieldValue<bool, unsigned __int32> bWasOverrideHiddenShadowValue() { return { this, "AShooterCharacter.bWasOverrideHiddenShadowValue" }; }
	BitFieldValue<bool, unsigned __int32> bLastLocInterpProne() { return { this, "AShooterCharacter.bLastLocInterpProne" }; }
	BitFieldValue<bool, unsigned __int32> bLastLocInterpCrouched() { return { this, "AShooterCharacter.bLastLocInterpCrouched" }; }
	BitFieldValue<bool, unsigned __int32> bHatHidden() { return { this, "AShooterCharacter.bHatHidden" }; }
	BitFieldValue<bool, unsigned __int32> bBeganPlay() { return { this, "AShooterCharacter.bBeganPlay" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDPC() { return { this, "AShooterCharacter.bAllowDPC" }; }
	BitFieldValue<bool, unsigned __int32> bHadWeaponWhenStartedClimbingLadder() { return { this, "AShooterCharacter.bHadWeaponWhenStartedClimbingLadder" }; }
	BitFieldValue<bool, unsigned __int32> bIsConnected() { return { this, "AShooterCharacter.bIsConnected" }; }
	BitFieldValue<bool, unsigned __int32> bRefreshDefaultAttachmentsHadEquippedItems() { return { this, "AShooterCharacter.bRefreshDefaultAttachmentsHadEquippedItems" }; }
	BitFieldValue<bool, unsigned __int32> bLockedToSeatingStructure() { return { this, "AShooterCharacter.bLockedToSeatingStructure" }; }

	// Functions

	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "AShooterCharacter.GetPrivateStaticClass"); }
	bool BuffsPreventFirstPerson() { return NativeCall<bool>(this, "AShooterCharacter.BuffsPreventFirstPerson"); }
	void PostInitializeComponents() { NativeCall<void>(this, "AShooterCharacter.PostInitializeComponents"); }
	void AuthPostSpawnInit() { NativeCall<void>(this, "AShooterCharacter.AuthPostSpawnInit"); }
	void Destroyed() { NativeCall<void>(this, "AShooterCharacter.Destroyed"); }
	void OnRep_RawBoneModifiers() { NativeCall<void>(this, "AShooterCharacter.OnRep_RawBoneModifiers"); }
	void UpdateTransponders() { NativeCall<void>(this, "AShooterCharacter.UpdateTransponders"); }
	void BeginPlay() { NativeCall<void>(this, "AShooterCharacter.BeginPlay"); }
	void DrawTranspondersInfo(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "AShooterCharacter.DrawTranspondersInfo", HUD); }
	void PlaySpawnAnim() { NativeCall<void>(this, "AShooterCharacter.PlaySpawnAnim"); }
	void ClearSpawnAnim() { NativeCall<void>(this, "AShooterCharacter.ClearSpawnAnim"); }
	void PlayJumpAnim() { NativeCall<void>(this, "AShooterCharacter.PlayJumpAnim"); }
	void PlayLandedAnim() { NativeCall<void>(this, "AShooterCharacter.PlayLandedAnim"); }
	void DedicatedServerBoneFixup() { NativeCall<void>(this, "AShooterCharacter.DedicatedServerBoneFixup"); }
	void ControllerLeavingGame(AShooterPlayerController * theController) { NativeCall<void, AShooterPlayerController *>(this, "AShooterCharacter.ControllerLeavingGame", theController); }
	void ModifyFirstPersonCameraLocation(FVector * Loc, float DeltaTime) { NativeCall<void, FVector *, float>(this, "AShooterCharacter.ModifyFirstPersonCameraLocation", Loc, DeltaTime); }
	void PossessedBy(AController * InController) { NativeCall<void, AController *>(this, "AShooterCharacter.PossessedBy", InController); }
	void LocalPossessedBy(APlayerController * ByController) { NativeCall<void, APlayerController *>(this, "AShooterCharacter.LocalPossessedBy", ByController); }
	void ServerDetachGrapHookCable_Implementation(bool bDoUpwardsJump, float UpwardsJumpYaw) { NativeCall<void, bool, float>(this, "AShooterCharacter.ServerDetachGrapHookCable_Implementation", bDoUpwardsJump, UpwardsJumpYaw); }
	void ServerReleaseGrapHookCable_Implementation(bool bReleasing) { NativeCall<void, bool>(this, "AShooterCharacter.ServerReleaseGrapHookCable_Implementation", bReleasing); }
	void DetachGrapHookCable_Implementation() { NativeCall<void>(this, "AShooterCharacter.DetachGrapHookCable_Implementation"); }
	void SyncGrapHookDistance_Implementation(float Distance) { NativeCall<void, float>(this, "AShooterCharacter.SyncGrapHookDistance_Implementation", Distance); }
	void UpdateGrapHook(float DeltaSeconds) { NativeCall<void, float>(this, "AShooterCharacter.UpdateGrapHook", DeltaSeconds); }
	void SetCarriedPitchYaw_Implementation(float NewCarriedPitch, float NewCarriedYaw) { NativeCall<void, float, float>(this, "AShooterCharacter.SetCarriedPitchYaw_Implementation", NewCarriedPitch, NewCarriedYaw); }
	FRotator * GetAimOffsets(FRotator * result, float DeltaTime, FRotator * RootRotOffset, float * RootYawSpeed, float MaxYawAimClamp, FVector * RootLocOffset) { return NativeCall<FRotator *, FRotator *, float, FRotator *, float *, float, FVector *>(this, "AShooterCharacter.GetAimOffsets", result, DeltaTime, RootRotOffset, RootYawSpeed, MaxYawAimClamp, RootLocOffset); }
	void UpdatePawnMeshes(bool bForceThirdPerson, bool bForceFlush) { NativeCall<void, bool, bool>(this, "AShooterCharacter.UpdatePawnMeshes", bForceThirdPerson, bForceFlush); }
	void OnCameraUpdate(FVector * CameraLocation, FRotator * CameraRotation) { NativeCall<void, FVector *, FRotator *>(this, "AShooterCharacter.OnCameraUpdate", CameraLocation, CameraRotation); }
	void GiveDefaultWeapon(bool bForceGiveDefaultWeapon) { NativeCall<void, bool>(this, "AShooterCharacter.GiveDefaultWeapon", bForceGiveDefaultWeapon); }
	void GiveMapWeapon() { NativeCall<void>(this, "AShooterCharacter.GiveMapWeapon"); }
	void SwitchMap() { NativeCall<void>(this, "AShooterCharacter.SwitchMap"); }
	void DelayGiveDefaultWeapon(float DelayTime) { NativeCall<void, float>(this, "AShooterCharacter.DelayGiveDefaultWeapon", DelayTime); }
	void ServerSwitchMap_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerSwitchMap_Implementation"); }
	void ServerGiveDefaultWeapon_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerGiveDefaultWeapon_Implementation"); }
	void GivePrimalItemWeapon(UPrimalItem * aPrimalItem) { NativeCall<void, UPrimalItem *>(this, "AShooterCharacter.GivePrimalItemWeapon", aPrimalItem); }
	void StartWeaponSwitch(UPrimalItem * aPrimalItem, bool bDontClearLastWeapon) { NativeCall<void, UPrimalItem *, bool>(this, "AShooterCharacter.StartWeaponSwitch", aPrimalItem, bDontClearLastWeapon); }
	void FinishWeaponSwitch() { NativeCall<void>(this, "AShooterCharacter.FinishWeaponSwitch"); }
	float GetMaxCursorHUDDistance(AShooterPlayerController * PC) { return NativeCall<float, AShooterPlayerController *>(this, "AShooterCharacter.GetMaxCursorHUDDistance", PC); }
	void DrawFloatingHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "AShooterCharacter.DrawFloatingHUD", HUD); }
	void DrawFloatingChatMessage(AShooterHUD * HUD, FString Message, long double receivedChatTime) { NativeCall<void, AShooterHUD *, FString, long double>(this, "AShooterCharacter.DrawFloatingChatMessage", HUD, Message, receivedChatTime); }
	void SetCurrentWeapon(AShooterWeapon * NewWeapon, AShooterWeapon * LastWeapon) { NativeCall<void, AShooterWeapon *, AShooterWeapon *>(this, "AShooterCharacter.SetCurrentWeapon", NewWeapon, LastWeapon); }
	void ForceSleep() { NativeCall<void>(this, "AShooterCharacter.ForceSleep"); }
	bool CanFire() { return NativeCall<bool>(this, "AShooterCharacter.CanFire"); }
	void SetTargeting(bool bNewTargeting) { NativeCall<void, bool>(this, "AShooterCharacter.SetTargeting", bNewTargeting); }
	void ServerSetTargeting_Implementation(bool bNewTargeting) { NativeCall<void, bool>(this, "AShooterCharacter.ServerSetTargeting_Implementation", bNewTargeting); }
	void ClientUpdateTranspondersInfo_Implementation(TArray<FTransponderInfo> * TranspondersInfo, bool bNewData) { NativeCall<void, TArray<FTransponderInfo> *, bool>(this, "AShooterCharacter.ClientUpdateTranspondersInfo_Implementation", TranspondersInfo, bNewData); }
	void ZoomIn() { NativeCall<void>(this, "AShooterCharacter.ZoomIn"); }
	void ZoomOut() { NativeCall<void>(this, "AShooterCharacter.ZoomOut"); }
	bool CanProne() { return NativeCall<bool>(this, "AShooterCharacter.CanProne"); }
	bool CanCrouch() { return NativeCall<bool>(this, "AShooterCharacter.CanCrouch"); }
	void OnPressCrouch() { NativeCall<void>(this, "AShooterCharacter.OnPressCrouch"); }
	void OnPressProne() { NativeCall<void>(this, "AShooterCharacter.OnPressProne"); }
	void OnPressCrouchProneToggle() { NativeCall<void>(this, "AShooterCharacter.OnPressCrouchProneToggle"); }
	void OnReleaseCrouchProneToggle() { NativeCall<void>(this, "AShooterCharacter.OnReleaseCrouchProneToggle"); }
	void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) { NativeCall<void, float, float>(this, "AShooterCharacter.OnEndCrouch", HalfHeightAdjust, ScaledHalfHeightAdjust); }
	void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) { NativeCall<void, float, float>(this, "AShooterCharacter.OnStartCrouch", HalfHeightAdjust, ScaledHalfHeightAdjust); }
	void OnStartFire(bool bFromGamepadRight) { NativeCall<void, bool>(this, "AShooterCharacter.OnStartFire", bFromGamepadRight); }
	void OnStopFire(bool bFromGamepadRight) { NativeCall<void, bool>(this, "AShooterCharacter.OnStopFire", bFromGamepadRight); }
	void OnStartAltFire() { NativeCall<void>(this, "AShooterCharacter.OnStartAltFire"); }
	void OnStopAltFire() { NativeCall<void>(this, "AShooterCharacter.OnStopAltFire"); }
	void OnStartTargeting(bool bFromGamepadLeft) { NativeCall<void, bool>(this, "AShooterCharacter.OnStartTargeting", bFromGamepadLeft); }
	void OnStopTargeting(bool bFromGamepadLeft) { NativeCall<void, bool>(this, "AShooterCharacter.OnStopTargeting", bFromGamepadLeft); }
	void OnPressReload() { NativeCall<void>(this, "AShooterCharacter.OnPressReload"); }
	void OnReload() { NativeCall<void>(this, "AShooterCharacter.OnReload"); }
	bool IsRunning() { return NativeCall<bool>(this, "AShooterCharacter.IsRunning"); }
	void SetSleeping(bool bSleeping, bool bUseRagdollLocationOffset) { NativeCall<void, bool, bool>(this, "AShooterCharacter.SetSleeping", bSleeping, bUseRagdollLocationOffset); }
	bool IsValidUnStasisCaster() { return NativeCall<bool>(this, "AShooterCharacter.IsValidUnStasisCaster"); }
	void CheckAndHandleBasedPlayersBeingPushedThroughWalls() { NativeCall<void>(this, "AShooterCharacter.CheckAndHandleBasedPlayersBeingPushedThroughWalls"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "AShooterCharacter.Tick", DeltaSeconds); }
	void UpdateCarriedLocationAndRotation(float DeltaSeconds) { NativeCall<void, float>(this, "AShooterCharacter.UpdateCarriedLocationAndRotation", DeltaSeconds); }
	float GetCarryingSocketYaw(bool RefreshBones) { return NativeCall<float, bool>(this, "AShooterCharacter.GetCarryingSocketYaw", RefreshBones); }
	bool CanBeCarried(APrimalCharacter * ByCarrier) { return NativeCall<bool, APrimalCharacter *>(this, "AShooterCharacter.CanBeCarried", ByCarrier); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AShooterCharacter.GetLifetimeReplicatedProps", OutLifetimeProps); }
	bool IsTargeting() { return NativeCall<bool>(this, "AShooterCharacter.IsTargeting"); }
	bool IsFirstPerson() { return NativeCall<bool>(this, "AShooterCharacter.IsFirstPerson"); }
	void SetActorHiddenInGame(bool bNewHidden) { NativeCall<void, bool>(this, "AShooterCharacter.SetActorHiddenInGame", bNewHidden); }
	bool AllowFirstPerson() { return NativeCall<bool>(this, "AShooterCharacter.AllowFirstPerson"); }
	void SetCameraMode(bool bFirstperson, bool bIgnoreSettingFirstPersonRiding) { NativeCall<void, bool, bool>(this, "AShooterCharacter.SetCameraMode", bFirstperson, bIgnoreSettingFirstPersonRiding); }
	void PlaySpawnIntro() { NativeCall<void>(this, "AShooterCharacter.PlaySpawnIntro"); }
	void FinishSpawnIntro() { NativeCall<void>(this, "AShooterCharacter.FinishSpawnIntro"); }
	bool ValidToRestoreForPC(AShooterPlayerController * aPC) { return NativeCall<bool, AShooterPlayerController *>(this, "AShooterCharacter.ValidToRestoreForPC", aPC); }
	static AShooterCharacter * FindForPlayerController(AShooterPlayerController * aPC) { return NativeCall<AShooterCharacter *, AShooterPlayerController *>(nullptr, "AShooterCharacter.FindForPlayerController", aPC); }
	FString * GetDescriptiveName(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterCharacter.GetDescriptiveName", result); }
	FString * GetShortName(FString * result) { return NativeCall<FString *, FString *>(this, "AShooterCharacter.GetShortName", result); }
	UPrimalPlayerData * GetPlayerData() { return NativeCall<UPrimalPlayerData *>(this, "AShooterCharacter.GetPlayerData"); }
	void PlayDying(float KillingDamage, FDamageEvent * DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "AShooterCharacter.PlayDying", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	bool IsUsingShield() { return NativeCall<bool>(this, "AShooterCharacter.IsUsingShield"); }
	bool IsBlockingWithShield() { return NativeCall<bool>(this, "AShooterCharacter.IsBlockingWithShield"); }
	bool AllowBlockingWithShield() { return NativeCall<bool>(this, "AShooterCharacter.AllowBlockingWithShield"); }
	bool GetBlockingShieldOffsets(FVector * OutBlockingShieldFPVTranslation, FRotator * OutBlockingShieldFPVRotation) { return NativeCall<bool, FVector *, FRotator *>(this, "AShooterCharacter.GetBlockingShieldOffsets", OutBlockingShieldFPVTranslation, OutBlockingShieldFPVRotation); }
	void NetSimulatedForceUpdateAimedActors_Implementation(float OverrideMaxDistance) { NativeCall<void, float>(this, "AShooterCharacter.NetSimulatedForceUpdateAimedActors_Implementation", OverrideMaxDistance); }
	void ServerForceUpdatedAimedActors(float OverrideMaxDistance, bool bReplicateToSimulatedClients) { NativeCall<void, float, bool>(this, "AShooterCharacter.ServerForceUpdatedAimedActors", OverrideMaxDistance, bReplicateToSimulatedClients); }
	void ServerSetBallistaNewRotation_Implementation(float Pitch, float Yaw) { NativeCall<void, float, float>(this, "AShooterCharacter.ServerSetBallistaNewRotation_Implementation", Pitch, Yaw); }
	void ServerNotifyBallistaShot_Implementation(FHitResult Impact, FVector_NetQuantizeNormal ShootDir) { NativeCall<void, FHitResult, FVector_NetQuantizeNormal>(this, "AShooterCharacter.ServerNotifyBallistaShot_Implementation", Impact, ShootDir); }
	float GetMaxSpeedModifier() { return NativeCall<float>(this, "AShooterCharacter.GetMaxSpeedModifier"); }
	void SetRidingDino(APrimalDinoCharacter * aDino) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterCharacter.SetRidingDino", aDino); }
	void ClearRidingDino(bool bFromDino, int OverrideUnboardDirection) { NativeCall<void, bool, int>(this, "AShooterCharacter.ClearRidingDino", bFromDino, OverrideUnboardDirection); }
	void SetCarryingDino(APrimalDinoCharacter * aDino) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterCharacter.SetCarryingDino", aDino); }
	void ClearCarryingDino(bool bFromDino, bool bCancelAnyCarryBuffs) { NativeCall<void, bool, bool>(this, "AShooterCharacter.ClearCarryingDino", bFromDino, bCancelAnyCarryBuffs); }
	void SetRidingDinoAsPassenger(APrimalDinoCharacter * aDino, FSaddlePassengerSeatDefinition * SeatDefinition) { NativeCall<void, APrimalDinoCharacter *, FSaddlePassengerSeatDefinition *>(this, "AShooterCharacter.SetRidingDinoAsPassenger", aDino, SeatDefinition); }
	void ClearRidingDinoAsPassenger(bool bFromDino) { NativeCall<void, bool>(this, "AShooterCharacter.ClearRidingDinoAsPassenger", bFromDino); }
	void ServerLaunchMountedDino_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerLaunchMountedDino_Implementation"); }
	void ClientPlayHarvestAnim_Implementation() { NativeCall<void>(this, "AShooterCharacter.ClientPlayHarvestAnim_Implementation"); }
	void LaunchMountedDino() { NativeCall<void>(this, "AShooterCharacter.LaunchMountedDino"); }
	void OnPrimalCharacterSleeped() { NativeCall<void>(this, "AShooterCharacter.OnPrimalCharacterSleeped"); }
	bool Die(float KillingDamage, FDamageEvent * DamageEvent, AController * Killer, AActor * DamageCauser) { return NativeCall<bool, float, FDamageEvent *, AController *, AActor *>(this, "AShooterCharacter.Die", KillingDamage, DamageEvent, Killer, DamageCauser); }
	void ApplyDamageMomentum(float DamageTaken, FDamageEvent * DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "AShooterCharacter.ApplyDamageMomentum", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	bool CanJumpInternal_Implementation() { return NativeCall<bool>(this, "AShooterCharacter.CanJumpInternal_Implementation"); }
	bool CanProneInternal() { return NativeCall<bool>(this, "AShooterCharacter.CanProneInternal"); }
	bool IsCrafting() { return NativeCall<bool>(this, "AShooterCharacter.IsCrafting"); }
	void RemoveAttachments() { NativeCall<void>(this, "AShooterCharacter.RemoveAttachments"); }
	void NotifyEquippedItems() { NativeCall<void>(this, "AShooterCharacter.NotifyEquippedItems"); }
	void RefreshDefaultAttachments(AActor * UseOtherActor) { NativeCall<void, AActor *>(this, "AShooterCharacter.RefreshDefaultAttachments", UseOtherActor); }
	void ClientMultiUse(APlayerController * ForPC, int UseIndex) { NativeCall<void, APlayerController *, int>(this, "AShooterCharacter.ClientMultiUse", ForPC, UseIndex); }
	bool TryMultiUse(APlayerController * ForPC, int UseIndex) { return NativeCall<bool, APlayerController *, int>(this, "AShooterCharacter.TryMultiUse", ForPC, UseIndex); }
	void RefreshTribeName() { NativeCall<void>(this, "AShooterCharacter.RefreshTribeName"); }
	void ChangeActorTeam(int NewTeam) { NativeCall<void, int>(this, "AShooterCharacter.ChangeActorTeam", NewTeam); }
	void ClientClearTribeRequest_Implementation() { NativeCall<void>(this, "AShooterCharacter.ClientClearTribeRequest_Implementation"); }
	void ClientNotifyTribeRequest_Implementation(FString * RequestTribeName, AShooterCharacter * PlayerCharacter) { NativeCall<void, FString *, AShooterCharacter *>(this, "AShooterCharacter.ClientNotifyTribeRequest_Implementation", RequestTribeName, PlayerCharacter); }
	void PlayDrinkingAnimation() { NativeCall<void>(this, "AShooterCharacter.PlayDrinkingAnimation"); }
	float GetCharacterAdditionalHypothermiaInsulationValue() { return NativeCall<float>(this, "AShooterCharacter.GetCharacterAdditionalHypothermiaInsulationValue"); }
	bool CalcIsIndoors() { return NativeCall<bool>(this, "AShooterCharacter.CalcIsIndoors"); }
	static bool IsIndoorsAtLoc(UWorld * theWorld, FVector * actorLoc) { return NativeCall<bool, UWorld *, FVector *>(nullptr, "AShooterCharacter.IsIndoorsAtLoc", theWorld, actorLoc); }
	float GetInsulationFromItem(FHitResult * HitOut, EPrimalItemStat::Type TypeInsulation) { return NativeCall<float, FHitResult *, EPrimalItemStat::Type>(this, "AShooterCharacter.GetInsulationFromItem", HitOut, TypeInsulation); }
	float GetCharacterAdditionalInsulationValueFromStructure(UWorld * theWorld, FVector * actorLoc, EPrimalItemStat::Type TypeInsulation) { return NativeCall<float, UWorld *, FVector *, EPrimalItemStat::Type>(this, "AShooterCharacter.GetCharacterAdditionalInsulationValueFromStructure", theWorld, actorLoc, TypeInsulation); }
	float GetCharacterAdditionalHyperthermiaInsulationValue() { return NativeCall<float>(this, "AShooterCharacter.GetCharacterAdditionalHyperthermiaInsulationValue"); }
	void PreInitializeComponents() { NativeCall<void>(this, "AShooterCharacter.PreInitializeComponents"); }
	void OnMovementModeChanged(EMovementMode PrevMovementMode, char PreviousCustomMode) { NativeCall<void, EMovementMode, char>(this, "AShooterCharacter.OnMovementModeChanged", PrevMovementMode, PreviousCustomMode); }
	void PreApplyAccumulatedForces(float DeltaSeconds, FVector * PendingImpulseToApply, FVector * PendingForceToApply) { NativeCall<void, float, FVector *, FVector *>(this, "AShooterCharacter.PreApplyAccumulatedForces", DeltaSeconds, PendingImpulseToApply, PendingForceToApply); }
	void OnBeginDrag_Implementation(APrimalCharacter * Dragged, int BoneIndex, bool bWithGrapHook) { NativeCall<void, APrimalCharacter *, int, bool>(this, "AShooterCharacter.OnBeginDrag_Implementation", Dragged, BoneIndex, bWithGrapHook); }
	void OnEndDrag_Implementation() { NativeCall<void>(this, "AShooterCharacter.OnEndDrag_Implementation"); }
	bool IsSubmerged(bool bDontCheckSwimming, bool bUseHalfThreshold, bool bForceCheck, bool bFromVolumeChange) { return NativeCall<bool, bool, bool, bool, bool>(this, "AShooterCharacter.IsSubmerged", bDontCheckSwimming, bUseHalfThreshold, bForceCheck, bFromVolumeChange); }
	void UpdateSwimmingState() { NativeCall<void>(this, "AShooterCharacter.UpdateSwimmingState"); }
	void SetCharacterMeshesMaterialScalarParamValue(FName ParamName, float Value) { NativeCall<void, FName, float>(this, "AShooterCharacter.SetCharacterMeshesMaterialScalarParamValue", ParamName, Value); }
	float GetRidingDinoAnimSpeedRatio() { return NativeCall<float>(this, "AShooterCharacter.GetRidingDinoAnimSpeedRatio"); }
	UAnimSequence * GetDinoRidingAnimation() { return NativeCall<UAnimSequence *>(this, "AShooterCharacter.GetDinoRidingAnimation"); }
	UAnimSequence * GetDinoRidingMoveAnimation() { return NativeCall<UAnimSequence *>(this, "AShooterCharacter.GetDinoRidingMoveAnimation"); }
	UAnimSequence * GetSeatingAnimation() { return NativeCall<UAnimSequence *>(this, "AShooterCharacter.GetSeatingAnimation"); }
	float GetBaseTargetingDesire(ITargetableInterface * Attacker) { return NativeCall<float, ITargetableInterface *>(this, "AShooterCharacter.GetBaseTargetingDesire", Attacker); }
	void ApplyBodyColors() { NativeCall<void>(this, "AShooterCharacter.ApplyBodyColors"); }
	void ApplyBoneModifiers() { NativeCall<void>(this, "AShooterCharacter.ApplyBoneModifiers"); }
	float GetTargetingDesirability(ITargetableInterface * Attacker) { return NativeCall<float, ITargetableInterface *>(this, "AShooterCharacter.GetTargetingDesirability", Attacker); }
	UAnimMontage * GetOverridenMontage(UAnimMontage * AnimMontage) { return NativeCall<UAnimMontage *, UAnimMontage *>(this, "AShooterCharacter.GetOverridenMontage", AnimMontage); }
	UAnimSequence * GetOverridenAnimSequence(UAnimSequence * AnimSeq) { return NativeCall<UAnimSequence *, UAnimSequence *>(this, "AShooterCharacter.GetOverridenAnimSequence", AnimSeq); }
	bool IsWatered() { return NativeCall<bool>(this, "AShooterCharacter.IsWatered"); }
	void AdjustDamage(float * Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { NativeCall<void, float *, FDamageEvent *, AController *, AActor *>(this, "AShooterCharacter.AdjustDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool IsBlockedByShield(FHitResult * HitInfo, FVector * ShotDirection, bool bBlockAllPointDamage) { return NativeCall<bool, FHitResult *, FVector *, bool>(this, "AShooterCharacter.IsBlockedByShield", HitInfo, ShotDirection, bBlockAllPointDamage); }
	void ClientNotifyLevelUp_Implementation() { NativeCall<void>(this, "AShooterCharacter.ClientNotifyLevelUp_Implementation"); }
	void StartedFiringWeapon(bool bPrimaryFire) { NativeCall<void, bool>(this, "AShooterCharacter.StartedFiringWeapon", bPrimaryFire); }
	void OrbitCamOn() { NativeCall<void>(this, "AShooterCharacter.OrbitCamOn"); }
	void OrbitCamToggle() { NativeCall<void>(this, "AShooterCharacter.OrbitCamToggle"); }
	void SetRagdollPhysics(bool bUseRagdollLocationOffset, bool bForceRecreateBones, bool bForLoading) { NativeCall<void, bool, bool, bool>(this, "AShooterCharacter.SetRagdollPhysics", bUseRagdollLocationOffset, bForceRecreateBones, bForLoading); }
	bool IsPlayingUpperBodyCallAnimation_Implementation() { return NativeCall<bool>(this, "AShooterCharacter.IsPlayingUpperBodyCallAnimation_Implementation"); }
	void ServerCallFollow_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallFollow_Implementation"); }
	void ServerCallFollowOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterCharacter.ServerCallFollowOne_Implementation", ForDinoChar); }
	void ServerCallStay_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallStay_Implementation"); }
	void ServerCallStayOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterCharacter.ServerCallStayOne_Implementation", ForDinoChar); }
	void ServerCallFollowDistanceCycleOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "AShooterCharacter.ServerCallFollowDistanceCycleOne_Implementation", ForDinoChar); }
	void ServerCallAggressive_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallAggressive_Implementation"); }
	void ServerCallNeutral_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallNeutral_Implementation"); }
	void ServerCallPassive_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallPassive_Implementation"); }
	void ServerCallSetAggressive_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCallSetAggressive_Implementation"); }
	void ServerCallAttackTarget_Implementation(AActor * TheTarget) { NativeCall<void, AActor *>(this, "AShooterCharacter.ServerCallAttackTarget_Implementation", TheTarget); }
	void ClientOrderedMoveTo_Implementation(FVector MoveToLoc) { NativeCall<void, FVector>(this, "AShooterCharacter.ClientOrderedMoveTo_Implementation", MoveToLoc); }
	void ClientOrderedAttackTarget_Implementation(AActor * attackTarget) { NativeCall<void, AActor *>(this, "AShooterCharacter.ClientOrderedAttackTarget_Implementation", attackTarget); }
	void ServerCallMoveTo_Implementation(FVector MoveToLoc) { NativeCall<void, FVector>(this, "AShooterCharacter.ServerCallMoveTo_Implementation", MoveToLoc); }
	bool TryAccessInventory() { return NativeCall<bool>(this, "AShooterCharacter.TryAccessInventory"); }
	void PlayEmoteAnimation_Implementation(char EmoteIndex) { NativeCall<void, char>(this, "AShooterCharacter.PlayEmoteAnimation_Implementation", EmoteIndex); }
	void OnVoiceTalkingStateChanged(bool talking) { NativeCall<void, bool>(this, "AShooterCharacter.OnVoiceTalkingStateChanged", talking); }
	void OnFailedJumped() { NativeCall<void>(this, "AShooterCharacter.OnFailedJumped"); }
	float GetRecoilMultiplier() { return NativeCall<float>(this, "AShooterCharacter.GetRecoilMultiplier"); }
	void StasisingCharacter() { NativeCall<void>(this, "AShooterCharacter.StasisingCharacter"); }
	UAnimSequence * GetAlternateStandingAnim(float * OutBlendInTime, float * OutBlendOutTime) { return NativeCall<UAnimSequence *, float *, float *>(this, "AShooterCharacter.GetAlternateStandingAnim", OutBlendInTime, OutBlendOutTime); }
	bool UseAdditiveStandingAnim() { return NativeCall<bool>(this, "AShooterCharacter.UseAdditiveStandingAnim"); }
	bool GetAdditiveStandingAnimNonAdditive() { return NativeCall<bool>(this, "AShooterCharacter.GetAdditiveStandingAnimNonAdditive"); }
	UAnimSequence * GetAdditiveStandingAnim(float * OutBlendInTime, float * OutBlendOutTime) { return NativeCall<UAnimSequence *, float *, float *>(this, "AShooterCharacter.GetAdditiveStandingAnim", OutBlendInTime, OutBlendOutTime); }
	void ClosedInventoryUI() { NativeCall<void>(this, "AShooterCharacter.ClosedInventoryUI"); }
	void ServerSetViewingInventory_Implementation(bool bIsViewing) { NativeCall<void, bool>(this, "AShooterCharacter.ServerSetViewingInventory_Implementation", bIsViewing); }
	void ServerCheckDrinkingWater_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerCheckDrinkingWater_Implementation"); }
	void GameStateHandleEvent_Implementation(FName NameParam, FVector VecParam) { NativeCall<void, FName, FVector>(this, "AShooterCharacter.GameStateHandleEvent_Implementation", NameParam, VecParam); }
	APrimalDinoCharacter * GetRidingDino() { return NativeCall<APrimalDinoCharacter *>(this, "AShooterCharacter.GetRidingDino"); }
	void AttachToLadder_Implementation(USceneComponent * Parent) { NativeCall<void, USceneComponent *>(this, "AShooterCharacter.AttachToLadder_Implementation", Parent); }
	void DetachFromLadder_Implementation() { NativeCall<void>(this, "AShooterCharacter.DetachFromLadder_Implementation"); }
	bool IsValidForStatusRecovery() { return NativeCall<bool>(this, "AShooterCharacter.IsValidForStatusRecovery"); }
	bool IsOnSeatingStructure() { return NativeCall<bool>(this, "AShooterCharacter.IsOnSeatingStructure"); }
	bool IsControllingBallistaTurret() { return NativeCall<bool>(this, "AShooterCharacter.IsControllingBallistaTurret"); }
	void OnAttachedToSeatingStructure() { NativeCall<void>(this, "AShooterCharacter.OnAttachedToSeatingStructure"); }
	void OnDetachedFromSeatingStructure(APrimalStructureSeating * InSeatingStructure) { NativeCall<void, APrimalStructureSeating *>(this, "AShooterCharacter.OnDetachedFromSeatingStructure", InSeatingStructure); }
	void TakeSeatingStructure(APrimalStructureSeating * InSeatingStructure, int SeatNumber, bool bLockedToSeat) { NativeCall<void, APrimalStructureSeating *, int, bool>(this, "AShooterCharacter.TakeSeatingStructure", InSeatingStructure, SeatNumber, bLockedToSeat); }
	void ReleaseSeatingStructure(APrimalStructureSeating * InSeatingStructure) { NativeCall<void, APrimalStructureSeating *>(this, "AShooterCharacter.ReleaseSeatingStructure", InSeatingStructure); }
	bool ShouldReplicateRotPitch() { return NativeCall<bool>(this, "AShooterCharacter.ShouldReplicateRotPitch"); }
	bool IsUsingClimbingPick() { return NativeCall<bool>(this, "AShooterCharacter.IsUsingClimbingPick"); }
	void ServerPlayFireBallistaAnimation_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerPlayFireBallistaAnimation_Implementation"); }
	void ServerStopFireBallista_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerStopFireBallista_Implementation"); }
	void ServerToClientsPlayFireBallistaAnimation_Implementation() { NativeCall<void>(this, "AShooterCharacter.ServerToClientsPlayFireBallistaAnimation_Implementation"); }
	void ServerFireBallistaProjectile_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir) { NativeCall<void, FVector, FVector_NetQuantizeNormal>(this, "AShooterCharacter.ServerFireBallistaProjectile_Implementation", Origin, ShootDir); }
	void ServerSeatingStructureAction_Implementation(char ActionNumber) { NativeCall<void, char>(this, "AShooterCharacter.ServerSeatingStructureAction_Implementation", ActionNumber); }
	void WasPushed(ACharacter * ByOtherCharacter) { NativeCall<void, ACharacter *>(this, "AShooterCharacter.WasPushed", ByOtherCharacter); }
	void NotifyBumpedPawn(APawn * BumpedPawn) { NativeCall<void, APawn *>(this, "AShooterCharacter.NotifyBumpedPawn", BumpedPawn); }
	void ClientNetEndClimbingLadder_Implementation() { NativeCall<void>(this, "AShooterCharacter.ClientNetEndClimbingLadder_Implementation"); }
	void ServerNetEndClimbingLadder_Implementation(bool bIsClimbOver, FVector ClimbOverLoc, float RightDir) { NativeCall<void, bool, FVector, float>(this, "AShooterCharacter.ServerNetEndClimbingLadder_Implementation", bIsClimbOver, ClimbOverLoc, RightDir); }
	void RenamePlayer_Implementation(FString * NewName) { NativeCall<void, FString *>(this, "AShooterCharacter.RenamePlayer_Implementation", NewName); }
	bool AllowDinoTargetingRange(FVector * AtLoc, float TargetingRange) { return NativeCall<bool, FVector *, float>(this, "AShooterCharacter.AllowDinoTargetingRange", AtLoc, TargetingRange); }
	FVector * GetPawnViewLocation(FVector * result, bool bAllTransforms) { return NativeCall<FVector *, FVector *, bool>(this, "AShooterCharacter.GetPawnViewLocation", result, bAllTransforms); }
	FRotator * GetPassengerAttachedRotation(FRotator * result) { return NativeCall<FRotator *, FRotator *>(this, "AShooterCharacter.GetPassengerAttachedRotation", result); }
	void ClientInviteToAlliance_Implementation(int RequestingTeam, unsigned int AllianceID, FString * AllianceName, FString * InviteeName) { NativeCall<void, int, unsigned int, FString *, FString *>(this, "AShooterCharacter.ClientInviteToAlliance_Implementation", RequestingTeam, AllianceID, AllianceName, InviteeName); }
	void InviteToAlliance(int RequestingTeam, unsigned int AllianceID, FString AllianceName, FString InviteeName) { NativeCall<void, int, unsigned int, FString, FString>(this, "AShooterCharacter.InviteToAlliance", RequestingTeam, AllianceID, AllianceName, InviteeName); }
	bool CanDragCharacter(APrimalCharacter * Character) { return NativeCall<bool, APrimalCharacter *>(this, "AShooterCharacter.CanDragCharacter", Character); }
	void GiveDefaultWeaponTimer() { NativeCall<void>(this, "AShooterCharacter.GiveDefaultWeaponTimer"); }
	bool IsCarryingSomething(bool bNotForRunning) { return NativeCall<bool, bool>(this, "AShooterCharacter.IsCarryingSomething", bNotForRunning); }
	void ForceGiveDefaultWeapon() { NativeCall<void>(this, "AShooterCharacter.ForceGiveDefaultWeapon"); }
	APrimalDinoCharacter * GetBasedOnDino() { return NativeCall<APrimalDinoCharacter *>(this, "AShooterCharacter.GetBasedOnDino"); }
	void HideWeapon() { NativeCall<void>(this, "AShooterCharacter.HideWeapon"); }
	void ShowWeapon() { NativeCall<void>(this, "AShooterCharacter.ShowWeapon"); }
	void ServerStartSurfaceCameraForPassenger_Implementation(float yaw, float roll, float pitch, bool bShouldInvertInput) { NativeCall<void, float, float, float, bool>(this, "AShooterCharacter.ServerStartSurfaceCameraForPassenger_Implementation", yaw, roll, pitch, bShouldInvertInput); }
	float ModifyAirControl(float AirControlIn) { return NativeCall<float, float>(this, "AShooterCharacter.ModifyAirControl", AirControlIn); }
	FVector * GetLastSweepLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AShooterCharacter.GetLastSweepLocation", result); }
	void NetSetHeadHairPercent_Implementation(float thePercent, int newHeadHairIndex) { NativeCall<void, float, int>(this, "AShooterCharacter.NetSetHeadHairPercent_Implementation", thePercent, newHeadHairIndex); }
	void NetSetFacialHairPercent_Implementation(float thePercent, int newFacialHairIndex) { NativeCall<void, float, int>(this, "AShooterCharacter.NetSetFacialHairPercent_Implementation", thePercent, newFacialHairIndex); }
	void UpdateHair() { NativeCall<void>(this, "AShooterCharacter.UpdateHair"); }
	void NetSetOverrideHeadHairColor_Implementation(FLinearColor HairColor) { NativeCall<void, FLinearColor>(this, "AShooterCharacter.NetSetOverrideHeadHairColor_Implementation", HairColor); }
	void NetSetOverrideFacialHairColor_Implementation(FLinearColor HairColor) { NativeCall<void, FLinearColor>(this, "AShooterCharacter.NetSetOverrideFacialHairColor_Implementation", HairColor); }
	void Unstasis() { NativeCall<void>(this, "AShooterCharacter.Unstasis"); }
	void RegisterActorTickFunctions(bool bRegister, bool bSaveAndRestoreTickState) { NativeCall<void, bool, bool>(this, "AShooterCharacter.RegisterActorTickFunctions", bRegister, bSaveAndRestoreTickState); }
	void OnRep_HatHidden() { NativeCall<void>(this, "AShooterCharacter.OnRep_HatHidden"); }
	float GetHeadHairMorphTargetValue() { return NativeCall<float>(this, "AShooterCharacter.GetHeadHairMorphTargetValue"); }
	float GetFacialHairMorphTargetValue() { return NativeCall<float>(this, "AShooterCharacter.GetFacialHairMorphTargetValue"); }
	void TempDampenInputAcceleration() { NativeCall<void>(this, "AShooterCharacter.TempDampenInputAcceleration"); }
	APrimalStructureExplosive * GetAttachedExplosive() { return NativeCall<APrimalStructureExplosive *>(this, "AShooterCharacter.GetAttachedExplosive"); }
	AShooterPlayerController * GetSpawnedForController() { return NativeCall<AShooterPlayerController *>(this, "AShooterCharacter.GetSpawnedForController"); }
	void Poop(bool bForcePoop) { NativeCall<void, bool>(this, "AShooterCharacter.Poop", bForcePoop); }
	AActor * StructurePlacementUseAlternateOriginActor() { return NativeCall<AActor *>(this, "AShooterCharacter.StructurePlacementUseAlternateOriginActor"); }
	USceneComponent * GetActorSoundAttachmentComponentOverride(USceneComponent * ForComponent) { return NativeCall<USceneComponent *, USceneComponent *>(this, "AShooterCharacter.GetActorSoundAttachmentComponentOverride", ForComponent); }
	bool IsNearTopOfLadder() { return NativeCall<bool>(this, "AShooterCharacter.IsNearTopOfLadder"); }
	bool AllowGrappling_Implementation() { return NativeCall<bool>(this, "AShooterCharacter.AllowGrappling_Implementation"); }
	void TryCutEnemyGrapplingCable() { NativeCall<void>(this, "AShooterCharacter.TryCutEnemyGrapplingCable"); }
	void FinalLoadedFromSaveGame() { NativeCall<void>(this, "AShooterCharacter.FinalLoadedFromSaveGame"); }
	AActor * GetSecondaryMountedActor() { return NativeCall<AActor *>(this, "AShooterCharacter.GetSecondaryMountedActor"); }
	void FaceRotation(FRotator NewControlRotation, float DeltaTime, bool bFromController) { NativeCall<void, FRotator, float, bool>(this, "AShooterCharacter.FaceRotation", NewControlRotation, DeltaTime, bFromController); }
	bool IsGameInputAllowed() { return NativeCall<bool>(this, "AShooterCharacter.IsGameInputAllowed"); }
	bool IsReadyToUpload(UWorld * theWorld) { return NativeCall<bool, UWorld *>(this, "AShooterCharacter.IsReadyToUpload", theWorld); }
	void ServerClearSwitchingWeapon_Implementation(bool bOnlyIfDefaultWeapon, bool bClientRequestNextWeaponID) { NativeCall<void, bool, bool>(this, "AShooterCharacter.ServerClearSwitchingWeapon_Implementation", bOnlyIfDefaultWeapon, bClientRequestNextWeaponID); }
	void ClientReceiveNextWeaponID_Implementation(FItemNetID theItemID) { NativeCall<void, FItemNetID>(this, "AShooterCharacter.ClientReceiveNextWeaponID_Implementation", theItemID); }
	void DoCharacterDetachment(bool bIncludeRiding, bool bIncludeCarrying, APrimalBuff * BuffToIgnore) { NativeCall<void, bool, bool, APrimalBuff *>(this, "AShooterCharacter.DoCharacterDetachment", bIncludeRiding, bIncludeCarrying, BuffToIgnore); }
	bool IsCharacterHardAttached(bool bIgnoreRiding, bool bIgnoreCarried) { return NativeCall<bool, bool, bool>(this, "AShooterCharacter.IsCharacterHardAttached", bIgnoreRiding, bIgnoreCarried); }
	bool IsGrapplingHardAttached() { return NativeCall<bool>(this, "AShooterCharacter.IsGrapplingHardAttached"); }
	bool TeleportTo(FVector * DestLocation, FRotator * DestRotation, bool bIsATest, bool bNoCheck) { return NativeCall<bool, FVector *, FRotator *, bool, bool>(this, "AShooterCharacter.TeleportTo", DestLocation, DestRotation, bIsATest, bNoCheck); }
	unsigned int GetUniqueNetIdTypeHash() { return NativeCall<unsigned int>(this, "AShooterCharacter.GetUniqueNetIdTypeHash"); }
	bool IsSitting(bool bIgnoreLockedToSeat) { return NativeCall<bool, bool>(this, "AShooterCharacter.IsSitting", bIgnoreLockedToSeat); }
	bool IsProneOrSitting(bool bIgnoreLockedToSeat) { return NativeCall<bool, bool>(this, "AShooterCharacter.IsProneOrSitting", bIgnoreLockedToSeat); }
	UPrimalItem * GetShieldItem() { return NativeCall<UPrimalItem *>(this, "AShooterCharacter.GetShieldItem"); }
	static void StaticRegisterNativesAShooterCharacter() { NativeCall<void>(nullptr, "AShooterCharacter.StaticRegisterNativesAShooterCharacter"); }
	void ClientInviteToAlliance(int RequestingTeam, unsigned int AllianceID, FString * AllianceName, FString * InviteeName) { NativeCall<void, int, unsigned int, FString *, FString *>(this, "AShooterCharacter.ClientInviteToAlliance", RequestingTeam, AllianceID, AllianceName, InviteeName); }
	void ClientNetEndClimbingLadder() { NativeCall<void>(this, "AShooterCharacter.ClientNetEndClimbingLadder"); }
	void ClientNotifyTribeRequest(FString * RequestTribeName, AShooterCharacter * PlayerCharacter) { NativeCall<void, FString *, AShooterCharacter *>(this, "AShooterCharacter.ClientNotifyTribeRequest", RequestTribeName, PlayerCharacter); }
	void DetachFromLadder() { NativeCall<void>(this, "AShooterCharacter.DetachFromLadder"); }
	void DetachGrapHookCable() { NativeCall<void>(this, "AShooterCharacter.DetachGrapHookCable"); }
	void GameStateHandleEvent(FName NameParam, FVector VecParam) { NativeCall<void, FName, FVector>(this, "AShooterCharacter.GameStateHandleEvent", NameParam, VecParam); }
	bool IsPlayingUpperBodyCallAnimation() { return NativeCall<bool>(this, "AShooterCharacter.IsPlayingUpperBodyCallAnimation"); }
	void RenamePlayer(FString * NewName) { NativeCall<void, FString *>(this, "AShooterCharacter.RenamePlayer", NewName); }
	void ServerDetachGrapHookCable(bool bDoUpwardsJump, float UpwardsJumpYaw) { NativeCall<void, bool, float>(this, "AShooterCharacter.ServerDetachGrapHookCable", bDoUpwardsJump, UpwardsJumpYaw); }
	void ServerLaunchMountedDino() { NativeCall<void>(this, "AShooterCharacter.ServerLaunchMountedDino"); }
	void ServerNotifyBallistaShot(FHitResult Impact, FVector_NetQuantizeNormal ShootDir) { NativeCall<void, FHitResult, FVector_NetQuantizeNormal>(this, "AShooterCharacter.ServerNotifyBallistaShot", Impact, ShootDir); }
	void ServerPlayFireBallistaAnimation() { NativeCall<void>(this, "AShooterCharacter.ServerPlayFireBallistaAnimation"); }
	void ServerSeatingStructureAction(char ActionNumber) { NativeCall<void, char>(this, "AShooterCharacter.ServerSeatingStructureAction", ActionNumber); }
	void ServerSetBallistaNewRotation(float Pitch, float Yaw) { NativeCall<void, float, float>(this, "AShooterCharacter.ServerSetBallistaNewRotation", Pitch, Yaw); }
	void ServerStartSurfaceCameraForPassenger(float yaw, float pitch, float roll, bool bShouldInvertInput) { NativeCall<void, float, float, float, bool>(this, "AShooterCharacter.ServerStartSurfaceCameraForPassenger", yaw, pitch, roll, bShouldInvertInput); }
	void ServerStopFireBallista() { NativeCall<void>(this, "AShooterCharacter.ServerStopFireBallista"); }
};

struct FPrimalPersistentCharacterStatsStruct
{
	FieldValue<unsigned __int16> CharacterStatusComponent_ExtraCharacterLevelField() { return { this, "FPrimalPersistentCharacterStatsStruct.CharacterStatusComponent_ExtraCharacterLevel" }; }
	FieldValue<float> CharacterStatusComponent_ExperiencePointsField() { return { this, "FPrimalPersistentCharacterStatsStruct.CharacterStatusComponent_ExperiencePoints" }; }
	FieldValue<int> PlayerState_TotalEngramPointsField() { return { this, "FPrimalPersistentCharacterStatsStruct.PlayerState_TotalEngramPoints" }; }
	FieldValue<int> CharacterStatusComponent_HighestExtraCharacterLevelField() { return { this, "FPrimalPersistentCharacterStatsStruct.CharacterStatusComponent_HighestExtraCharacterLevel" }; }
	FieldValue<int> CharacterStatusComponent_LastRespecAtExtraCharacterLevelField() { return { this, "FPrimalPersistentCharacterStatsStruct.CharacterStatusComponent_LastRespecAtExtraCharacterLevel" }; }
	FieldValue<TArray<unsigned int>> PerMapExplorerNoteUnlocksField() { return { this, "FPrimalPersistentCharacterStatsStruct.PerMapExplorerNoteUnlocks" }; }
	FieldValue<TArray<FName>> EmoteUnlocksField() { return { this, "FPrimalPersistentCharacterStatsStruct.EmoteUnlocks" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> PlayerState_EngramBlueprintsField() { return { this, "FPrimalPersistentCharacterStatsStruct.PlayerState_EngramBlueprints" }; }
	FieldArray<char, 12> CharacterStatusComponent_NumberOfLevelUpPointsAppliedField() { return { this, "FPrimalPersistentCharacterStatsStruct.CharacterStatusComponent_NumberOfLevelUpPointsApplied" }; }
	FieldArray<TSubclassOf<UPrimalItem>, 10> PlayerState_DefaultItemSlotClassesField() { return { this, "FPrimalPersistentCharacterStatsStruct.PlayerState_DefaultItemSlotClasses" }; }
	FieldArray<char, 10> PlayerState_DefaultItemSlotEngramsField() { return { this, "FPrimalPersistentCharacterStatsStruct.PlayerState_DefaultItemSlotEngrams" }; }
	FieldArray<FDinoOrderGroup, 10> DinoOrderGroupsField() { return { this, "FPrimalPersistentCharacterStatsStruct.DinoOrderGroups" }; }
	FieldValue<int> CurrentlySelectedDinoOrderGroupField() { return { this, "FPrimalPersistentCharacterStatsStruct.CurrentlySelectedDinoOrderGroup" }; }
	FieldValue<float> PercentageOfHeadHairGrowthField() { return { this, "FPrimalPersistentCharacterStatsStruct.PercentageOfHeadHairGrowth" }; }
	FieldValue<float> PercentageOfFacialHairGrowthField() { return { this, "FPrimalPersistentCharacterStatsStruct.PercentageOfFacialHairGrowth" }; }
	FieldValue<char> FacialHairIndexField() { return { this, "FPrimalPersistentCharacterStatsStruct.FacialHairIndex" }; }
	FieldValue<char> HeadHairIndexField() { return { this, "FPrimalPersistentCharacterStatsStruct.HeadHairIndex" }; }

	// Functions

	FPrimalPersistentCharacterStatsStruct * operator=(FPrimalPersistentCharacterStatsStruct * __that) { return NativeCall<FPrimalPersistentCharacterStatsStruct *, FPrimalPersistentCharacterStatsStruct *>(this, "FPrimalPersistentCharacterStatsStruct.operator=", __that); }
	bool IsPerMapExplorerNoteUnlocked(int ExplorerNoteIndex) { return NativeCall<bool, int>(this, "FPrimalPersistentCharacterStatsStruct.IsPerMapExplorerNoteUnlocked", ExplorerNoteIndex); }
	void ApplyToPrimalCharacter(APrimalCharacter * aChar, AShooterPlayerController * forPC, bool bIgnoreStats) { NativeCall<void, APrimalCharacter *, AShooterPlayerController *, bool>(this, "FPrimalPersistentCharacterStatsStruct.ApplyToPrimalCharacter", aChar, forPC, bIgnoreStats); }
	void GiveEngramsToPlayerState(APrimalCharacter * aChar, AShooterPlayerController * forPC) { NativeCall<void, APrimalCharacter *, AShooterPlayerController *>(this, "FPrimalPersistentCharacterStatsStruct.GiveEngramsToPlayerState", aChar, forPC); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FPrimalPersistentCharacterStatsStruct.StaticStruct"); }
};

struct FPrimalPlayerDataStruct
{
	FieldValue<unsigned __int64> PlayerDataIDField() { return { this, "FPrimalPlayerDataStruct.PlayerDataID" }; }
	FieldValue<FUniqueNetIdRepl> UniqueIDField() { return { this, "FPrimalPlayerDataStruct.UniqueID" }; }
	FieldValue<FString> SavedNetworkAddressField() { return { this, "FPrimalPlayerDataStruct.SavedNetworkAddress" }; }
	FieldValue<FString> PlayerNameField() { return { this, "FPrimalPlayerDataStruct.PlayerName" }; }
	FieldValue<unsigned int> LocalPlayerIndexField() { return { this, "FPrimalPlayerDataStruct.LocalPlayerIndex" }; }
	FieldValue<FPrimalPlayerCharacterConfigStruct> MyPlayerCharacterConfigField() { return { this, "FPrimalPlayerDataStruct.MyPlayerCharacterConfig" }; }
	FieldValue<int> LastPinCodeUsedField() { return { this, "FPrimalPlayerDataStruct.LastPinCodeUsed" }; }
	FieldPointer<FPrimalPersistentCharacterStatsStruct *> MyPersistentCharacterStatsField() { return { this, "FPrimalPlayerDataStruct.MyPersistentCharacterStats" }; }
	FieldValue<int> NumPersonalDinosField() { return { this, "FPrimalPlayerDataStruct.NumPersonalDinos" }; }
	FieldValue<int> TribeIDField() { return { this, "FPrimalPlayerDataStruct.TribeID" }; }
	FieldValue<TArray<int>> AppIDSetField() { return { this, "FPrimalPlayerDataStruct.AppIDSet" }; }
	FieldValue<int> PlayerDataVersionField() { return { this, "FPrimalPlayerDataStruct.PlayerDataVersion" }; }
	FieldValue<long double> NextAllowedRespawnTimeField() { return { this, "FPrimalPlayerDataStruct.NextAllowedRespawnTime" }; }
	FieldValue<long double> LastTimeDiedToEnemyTeamField() { return { this, "FPrimalPlayerDataStruct.LastTimeDiedToEnemyTeam" }; }
	FieldValue<float> AllowedRespawnIntervalField() { return { this, "FPrimalPlayerDataStruct.AllowedRespawnInterval" }; }
	FieldValue<float> NumOfDeathsField() { return { this, "FPrimalPlayerDataStruct.NumOfDeaths" }; }
	FieldValue<int> SpawnDayNumberField() { return { this, "FPrimalPlayerDataStruct.SpawnDayNumber" }; }
	FieldValue<float> SpawnDayTimeField() { return { this, "FPrimalPlayerDataStruct.SpawnDayTime" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bFirstSpawned() { return { this, "FPrimalPlayerDataStruct.bFirstSpawned" }; }
	BitFieldValue<bool, unsigned __int32> bUseSpectator() { return { this, "FPrimalPlayerDataStruct.bUseSpectator" }; }

	// Functions

	FPrimalPlayerDataStruct * operator=(FPrimalPlayerDataStruct * __that) { return NativeCall<FPrimalPlayerDataStruct *, FPrimalPlayerDataStruct *>(this, "FPrimalPlayerDataStruct.operator=", __that); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FPrimalPlayerDataStruct.StaticStruct"); }
};

struct UPrimalPlayerData
{
	FieldPointer<FPrimalPlayerDataStruct *> MyDataField() { return { this, "UPrimalPlayerData.MyData" }; }
	FieldValue<TArray<UPrimalBuffPersistentData *>> MyPersistentBuffDatasField() { return { this, "UPrimalPlayerData.MyPersistentBuffDatas" }; }
	FieldValue<bool> bIsLocalPlayerField() { return { this, "UPrimalPlayerData.bIsLocalPlayer" }; }
	FieldValue<float> LastXPWritePercentField() { return { this, "UPrimalPlayerData.LastXPWritePercent" }; }

	// Functions

	bool MatchesPlayer(AShooterPlayerState * aPlayerState, bool bCheckForExistingPlayer) { return NativeCall<bool, AShooterPlayerState *, bool>(this, "UPrimalPlayerData.MatchesPlayer", aPlayerState, bCheckForExistingPlayer); }
	void InitForPlayer(AShooterPlayerState * aPlayerState, bool bDontSaveData) { NativeCall<void, AShooterPlayerState *, bool>(this, "UPrimalPlayerData.InitForPlayer", aPlayerState, bDontSaveData); }
	AShooterPlayerState * GetPlayerState(AShooterPlayerState * ignorePlayerState, bool bOnlyCheckExistingPlayers) { return NativeCall<AShooterPlayerState *, AShooterPlayerState *, bool>(this, "UPrimalPlayerData.GetPlayerState", ignorePlayerState, bOnlyCheckExistingPlayers); }
	static UPrimalPlayerData * GetDataForID(unsigned __int64 PlayerDataID) { return NativeCall<UPrimalPlayerData *, unsigned __int64>(nullptr, "UPrimalPlayerData.GetDataForID", PlayerDataID); }
	void ApplyToPlayerState(AShooterPlayerState * aPlayerState) { NativeCall<void, AShooterPlayerState *>(this, "UPrimalPlayerData.ApplyToPlayerState", aPlayerState); }
	void GiveInitialItems(int AppID, AShooterPlayerController * ForPC) { NativeCall<void, int, AShooterPlayerController *>(this, "UPrimalPlayerData.GiveInitialItems", AppID, ForPC); }
	FString * GetUniqueIdString(FString * result) { return NativeCall<FString *, FString *>(this, "UPrimalPlayerData.GetUniqueIdString", result); }
	void SavePlayerData(UWorld * ForWorld) { NativeCall<void, UWorld *>(this, "UPrimalPlayerData.SavePlayerData", ForWorld); }
	void ApplyToPlayerCharacter(AShooterPlayerState * ForPlayerState, AShooterCharacter * NewPawn) { NativeCall<void, AShooterPlayerState *, AShooterCharacter *>(this, "UPrimalPlayerData.ApplyToPlayerCharacter", ForPlayerState, NewPawn); }
	void RefreshPersistentBuffs(AShooterCharacter * theChar) { NativeCall<void, AShooterCharacter *>(this, "UPrimalPlayerData.RefreshPersistentBuffs", theChar); }
	void CreatedNewPlayerData() { NativeCall<void>(this, "UPrimalPlayerData.CreatedNewPlayerData"); }
	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "UPrimalPlayerData.GetPrivateStaticClass"); }
};

struct UPrimalCharacterStatusComponent
{
	FieldArray<float, 12> MaxStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.MaxStatusValues" }; }
	FieldArray<float, 12> BaseLevelMaxStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.BaseLevelMaxStatusValues" }; }
	FieldArray<char, 12> NumberOfLevelUpPointsAppliedField() { return { this, "UPrimalCharacterStatusComponent.NumberOfLevelUpPointsApplied" }; }
	FieldArray<char, 12> NumberOfLevelUpPointsAppliedTamedField() { return { this, "UPrimalCharacterStatusComponent.NumberOfLevelUpPointsAppliedTamed" }; }
	FieldValue<float> TamedIneffectivenessModifierField() { return { this, "UPrimalCharacterStatusComponent.TamedIneffectivenessModifier" }; }
	FieldValue<float> MovingStaminaRecoveryRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.MovingStaminaRecoveryRateMultiplier" }; }
	FieldArray<float, 12> RecoveryRateStatusValueField() { return { this, "UPrimalCharacterStatusComponent.RecoveryRateStatusValue" }; }
	FieldArray<float, 12> TimeToRecoverAfterDepletionStatusValueField() { return { this, "UPrimalCharacterStatusComponent.TimeToRecoverAfterDepletionStatusValue" }; }
	FieldArray<float, 12> TimeToRecoverAfterDecreaseStatusValueField() { return { this, "UPrimalCharacterStatusComponent.TimeToRecoverAfterDecreaseStatusValue" }; }
	FieldArray<float, 12> AmountMaxGainedPerLevelUpValueField() { return { this, "UPrimalCharacterStatusComponent.AmountMaxGainedPerLevelUpValue" }; }
	FieldArray<float, 12> AmountMaxGainedPerLevelUpValueTamedField() { return { this, "UPrimalCharacterStatusComponent.AmountMaxGainedPerLevelUpValueTamed" }; }
	FieldArray<char, 12> MaxGainedPerLevelUpValueIsPercentField() { return { this, "UPrimalCharacterStatusComponent.MaxGainedPerLevelUpValueIsPercent" }; }
	FieldArray<char, 12> RecoveryRateIsPercentField() { return { this, "UPrimalCharacterStatusComponent.RecoveryRateIsPercent" }; }
	FieldArray<float, 12> TamingMaxStatMultipliersField() { return { this, "UPrimalCharacterStatusComponent.TamingMaxStatMultipliers" }; }
	FieldArray<float, 12> TamingMaxStatAdditionsField() { return { this, "UPrimalCharacterStatusComponent.TamingMaxStatAdditions" }; }
	FieldArray<float, 12> MaxLevelUpMultiplierField() { return { this, "UPrimalCharacterStatusComponent.MaxLevelUpMultiplier" }; }
	FieldValue<float> TamedLandDinoSwimSpeedLevelUpEffectivenessField() { return { this, "UPrimalCharacterStatusComponent.TamedLandDinoSwimSpeedLevelUpEffectiveness" }; }
	FieldValue<float> TamingIneffectivenessMultiplierField() { return { this, "UPrimalCharacterStatusComponent.TamingIneffectivenessMultiplier" }; }
	FieldValue<float> DinoRiderWeightMultiplierField() { return { this, "UPrimalCharacterStatusComponent.DinoRiderWeightMultiplier" }; }
	FieldArray<char, 12> CanLevelUpValueField() { return { this, "UPrimalCharacterStatusComponent.CanLevelUpValue" }; }
	FieldArray<char, 12> DontUseValueField() { return { this, "UPrimalCharacterStatusComponent.DontUseValue" }; }
	FieldValue<float> ExperienceAutomaticConsciousIncreaseSpeedField() { return { this, "UPrimalCharacterStatusComponent.ExperienceAutomaticConsciousIncreaseSpeed" }; }
	FieldValue<float> CheatMaxWeightField() { return { this, "UPrimalCharacterStatusComponent.CheatMaxWeight" }; }
	FieldValue<int> CharacterStatusComponentPriorityField() { return { this, "UPrimalCharacterStatusComponent.CharacterStatusComponentPriority" }; }
	FieldValue<float> SuffocationHealthPercentDecreaseSpeedField() { return { this, "UPrimalCharacterStatusComponent.SuffocationHealthPercentDecreaseSpeed" }; }
	FieldValue<float> UnsubmergedOxygenIncreaseSpeedField() { return { this, "UPrimalCharacterStatusComponent.UnsubmergedOxygenIncreaseSpeed" }; }
	FieldValue<float> SubmergedOxygenDecreaseSpeedField() { return { this, "UPrimalCharacterStatusComponent.SubmergedOxygenDecreaseSpeed" }; }
	FieldValue<float> RunningStaminaConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.RunningStaminaConsumptionRate" }; }
	FieldValue<float> WalkingStaminaConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.WalkingStaminaConsumptionRate" }; }
	FieldValue<float> SwimmingOrFlyingStaminaConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.SwimmingOrFlyingStaminaConsumptionRate" }; }
	FieldValue<float> JumpStaminaConsumptionField() { return { this, "UPrimalCharacterStatusComponent.JumpStaminaConsumption" }; }
	FieldValue<float> WindedSpeedModifierField() { return { this, "UPrimalCharacterStatusComponent.WindedSpeedModifier" }; }
	FieldValue<float> WindedSpeedModifierSwimmingOrFlyingField() { return { this, "UPrimalCharacterStatusComponent.WindedSpeedModifierSwimmingOrFlying" }; }
	FieldValue<float> InjuredSpeedModifierField() { return { this, "UPrimalCharacterStatusComponent.InjuredSpeedModifier" }; }
	FieldValue<float> HypothermicHealthDecreaseRateBaseField() { return { this, "UPrimalCharacterStatusComponent.HypothermicHealthDecreaseRateBase" }; }
	FieldValue<float> HypothermicHealthDecreaseRatePerDegreeField() { return { this, "UPrimalCharacterStatusComponent.HypothermicHealthDecreaseRatePerDegree" }; }
	FieldValue<float> HyperthermicHealthDecreaseRateBaseField() { return { this, "UPrimalCharacterStatusComponent.HyperthermicHealthDecreaseRateBase" }; }
	FieldValue<float> HyperthermicHealthDecreaseRatePerDegreeField() { return { this, "UPrimalCharacterStatusComponent.HyperthermicHealthDecreaseRatePerDegree" }; }
	FieldValue<float> XPEarnedPerStaminaConsumedField() { return { this, "UPrimalCharacterStatusComponent.XPEarnedPerStaminaConsumed" }; }
	FieldValue<float> KillXPMultiplierPerCharacterLevelField() { return { this, "UPrimalCharacterStatusComponent.KillXPMultiplierPerCharacterLevel" }; }
	FieldValue<float> ShareXPWithTribeRangeField() { return { this, "UPrimalCharacterStatusComponent.ShareXPWithTribeRange" }; }
	FieldValue<int> BaseCharacterLevelField() { return { this, "UPrimalCharacterStatusComponent.BaseCharacterLevel" }; }
	FieldValue<unsigned __int16> ExtraCharacterLevelField() { return { this, "UPrimalCharacterStatusComponent.ExtraCharacterLevel" }; }
	FieldValue<float> ExperiencePointsField() { return { this, "UPrimalCharacterStatusComponent.ExperiencePoints" }; }
	FieldValue<float> ReplicatedExperiencePointsField() { return { this, "UPrimalCharacterStatusComponent.ReplicatedExperiencePoints" }; }
	FieldValue<TEnumAsByte<enum ELevelExperienceRampType::Type>> LevelExperienceRampTypeField() { return { this, "UPrimalCharacterStatusComponent.LevelExperienceRampType" }; }
	FieldValue<float> MaxExperiencePointsField() { return { this, "UPrimalCharacterStatusComponent.MaxExperiencePoints" }; }
	FieldValue<float> BaseFoodConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.BaseFoodConsumptionRate" }; }
	FieldValue<float> BaseWaterConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.BaseWaterConsumptionRate" }; }
	FieldValue<float> FortitudeTorpidityDecreaseMultiplierField() { return { this, "UPrimalCharacterStatusComponent.FortitudeTorpidityDecreaseMultiplier" }; }
	FieldValue<float> FortitudeTorpidityIncreaseResistanceField() { return { this, "UPrimalCharacterStatusComponent.FortitudeTorpidityIncreaseResistance" }; }
	FieldValue<float> SubmergedWaterIncreaseRateField() { return { this, "UPrimalCharacterStatusComponent.SubmergedWaterIncreaseRate" }; }
	FieldValue<float> CrouchedWaterFoodConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.CrouchedWaterFoodConsumptionMultiplier" }; }
	FieldValue<float> ProneWaterFoodConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ProneWaterFoodConsumptionMultiplier" }; }
	FieldValue<float> StaminaRecoveryDecreaseFoodMultiplierField() { return { this, "UPrimalCharacterStatusComponent.StaminaRecoveryDecreaseFoodMultiplier" }; }
	FieldValue<float> StaminaRecoveryDecreaseWaterMultiplierField() { return { this, "UPrimalCharacterStatusComponent.StaminaRecoveryDecreaseWaterMultiplier" }; }
	FieldValue<float> HealthRecoveryDecreaseFoodMultiplierField() { return { this, "UPrimalCharacterStatusComponent.HealthRecoveryDecreaseFoodMultiplier" }; }
	FieldValue<float> BabyDinoConsumingFoodRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.BabyDinoConsumingFoodRateMultiplier" }; }
	FieldValue<float> DinoTamedAdultConsumingFoodRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.DinoTamedAdultConsumingFoodRateMultiplier" }; }
	FieldValue<float> BabyGestationConsumingFoodRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.BabyGestationConsumingFoodRateMultiplier" }; }
	FieldValue<float> BabyDinoStarvationHealthDecreaseRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.BabyDinoStarvationHealthDecreaseRateMultiplier" }; }
	FieldValue<float> BabyMaxHealthPercentField() { return { this, "UPrimalCharacterStatusComponent.BabyMaxHealthPercent" }; }
	FieldValue<float> CrouchedStaminaConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.CrouchedStaminaConsumptionMultiplier" }; }
	FieldValue<float> ProneStaminaConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ProneStaminaConsumptionMultiplier" }; }
	FieldValue<float> StarvationHealthConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.StarvationHealthConsumptionRate" }; }
	FieldValue<float> DehyrdationHealthConsumptionRateField() { return { this, "UPrimalCharacterStatusComponent.DehyrdationHealthConsumptionRate" }; }
	FieldValue<float> StaminaConsumptionDecreaseWaterMultiplierField() { return { this, "UPrimalCharacterStatusComponent.StaminaConsumptionDecreaseWaterMultiplier" }; }
	FieldValue<float> StaminaConsumptionDecreaseFoodMultiplierField() { return { this, "UPrimalCharacterStatusComponent.StaminaConsumptionDecreaseFoodMultiplier" }; }
	FieldValue<float> HypothermiaDecreaseFoodMultiplierBaseField() { return { this, "UPrimalCharacterStatusComponent.HypothermiaDecreaseFoodMultiplierBase" }; }
	FieldValue<float> HypothermiaDecreaseFoodMultiplierPerDegreeField() { return { this, "UPrimalCharacterStatusComponent.HypothermiaDecreaseFoodMultiplierPerDegree" }; }
	FieldValue<float> HyperthermiaDecreaseWaterMultiplierBaseField() { return { this, "UPrimalCharacterStatusComponent.HyperthermiaDecreaseWaterMultiplierBase" }; }
	FieldValue<float> HyperthermiaDecreaseWaterMultiplierPerDegreeField() { return { this, "UPrimalCharacterStatusComponent.HyperthermiaDecreaseWaterMultiplierPerDegree" }; }
	FieldValue<float> HyperthermiaTemperatureThresholdField() { return { this, "UPrimalCharacterStatusComponent.HyperthermiaTemperatureThreshold" }; }
	FieldValue<float> HypothermiaTemperatureThresholdField() { return { this, "UPrimalCharacterStatusComponent.HypothermiaTemperatureThreshold" }; }
	FieldValue<float> TorporExitPercentThresholdField() { return { this, "UPrimalCharacterStatusComponent.TorporExitPercentThreshold" }; }
	FieldValue<float> KnockedOutTorpidityRecoveryRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.KnockedOutTorpidityRecoveryRateMultiplier" }; }
	FieldValue<float> DehydrationTorpidityMultiplierField() { return { this, "UPrimalCharacterStatusComponent.DehydrationTorpidityMultiplier" }; }
	FieldValue<float> StarvationTorpidityMultuplierField() { return { this, "UPrimalCharacterStatusComponent.StarvationTorpidityMultuplier" }; }
	FieldValue<float> StarvationTorpidityIncreaseRateField() { return { this, "UPrimalCharacterStatusComponent.StarvationTorpidityIncreaseRate" }; }
	FieldValue<float> DehyrdationTorpidityIncreaseRateField() { return { this, "UPrimalCharacterStatusComponent.DehyrdationTorpidityIncreaseRate" }; }
	FieldValue<float> InjuredTorpidityIncreaseMultiplierField() { return { this, "UPrimalCharacterStatusComponent.InjuredTorpidityIncreaseMultiplier" }; }
	FieldValue<float> WeightSpeedDecreasePowerField() { return { this, "UPrimalCharacterStatusComponent.WeightSpeedDecreasePower" }; }
	FieldValue<float> WeightJumpDecreasePowerField() { return { this, "UPrimalCharacterStatusComponent.WeightJumpDecreasePower" }; }
	FieldValue<float> PoopItemMinFoodConsumptionIntervalField() { return { this, "UPrimalCharacterStatusComponent.PoopItemMinFoodConsumptionInterval" }; }
	FieldValue<float> PoopItemMaxFoodConsumptionIntervalField() { return { this, "UPrimalCharacterStatusComponent.PoopItemMaxFoodConsumptionInterval" }; }
	FieldValue<float> TheMaxTorporIncreasePerBaseLevelField() { return { this, "UPrimalCharacterStatusComponent.TheMaxTorporIncreasePerBaseLevel" }; }
	FieldValue<float> CurrentStatusValuesReplicationIntervalField() { return { this, "UPrimalCharacterStatusComponent.CurrentStatusValuesReplicationInterval" }; }
	FieldValue<float> InsulationHyperthermiaOffsetExponentField() { return { this, "UPrimalCharacterStatusComponent.InsulationHyperthermiaOffsetExponent" }; }
	FieldValue<float> InsulationHyperthermiaOffsetScalerField() { return { this, "UPrimalCharacterStatusComponent.InsulationHyperthermiaOffsetScaler" }; }
	FieldValue<float> InsulationHypothermiaOffsetExponentField() { return { this, "UPrimalCharacterStatusComponent.InsulationHypothermiaOffsetExponent" }; }
	FieldValue<float> InsulationHypothermiaOffsetScalerField() { return { this, "UPrimalCharacterStatusComponent.InsulationHypothermiaOffsetScaler" }; }
	FieldValue<float> HypoCharacterInsulationValueField() { return { this, "UPrimalCharacterStatusComponent.HypoCharacterInsulationValue" }; }
	FieldValue<float> HyperCharacterInsulationValueField() { return { this, "UPrimalCharacterStatusComponent.HyperCharacterInsulationValue" }; }
	FieldValue<float> PoopItemFoodConsumptionCacheField() { return { this, "UPrimalCharacterStatusComponent.PoopItemFoodConsumptionCache" }; }
	FieldValue<float> LastHypothermalCharacterInsulationValueField() { return { this, "UPrimalCharacterStatusComponent.LastHypothermalCharacterInsulationValue" }; }
	FieldValue<float> LastHyperthermalCharacterInsulationValueField() { return { this, "UPrimalCharacterStatusComponent.LastHyperthermalCharacterInsulationValue" }; }
	FieldValue<TEnumAsByte<enum EPrimalCharacterStatusValue::Type>> MaxStatusValueToAutoUpdateField() { return { this, "UPrimalCharacterStatusComponent.MaxStatusValueToAutoUpdate" }; }
	FieldValue<float> GenericXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.GenericXPMultiplier" }; }
	FieldValue<float> CraftEarnXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.CraftEarnXPMultiplier" }; }
	FieldValue<float> KillEarnXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.KillEarnXPMultiplier" }; }
	FieldValue<float> GenericEarnXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.GenericEarnXPMultiplier" }; }
	FieldValue<float> SpecialEarnXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.SpecialEarnXPMultiplier" }; }
	FieldValue<float> HarvestEarnXPMultiplierField() { return { this, "UPrimalCharacterStatusComponent.HarvestEarnXPMultiplier" }; }
	FieldValue<float> DefaultHyperthermicInsulationField() { return { this, "UPrimalCharacterStatusComponent.DefaultHyperthermicInsulation" }; }
	FieldValue<float> DefaultHypothermicInsulationField() { return { this, "UPrimalCharacterStatusComponent.DefaultHypothermicInsulation" }; }
	FieldValue<float> MaxTamingEffectivenessBaseLevelMultiplierField() { return { this, "UPrimalCharacterStatusComponent.MaxTamingEffectivenessBaseLevelMultiplier" }; }
	FieldValue<TArray<FPrimalCharacterStatusValueModifier>> StatusValueModifiersField() { return { this, "UPrimalCharacterStatusComponent.StatusValueModifiers" }; }
	FieldValue<TArray<unsigned char>> StatusValueModifierDescriptionIndicesField() { return { this, "UPrimalCharacterStatusComponent.StatusValueModifierDescriptionIndices" }; }
	FieldArray<float, 12> CurrentStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.CurrentStatusValues" }; }
	FieldArray<float, 12> AdditionalStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.AdditionalStatusValues" }; }
	FieldArray<float, 12> ReplicatedCurrentStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.ReplicatedCurrentStatusValues" }; }
	FieldArray<float, 12> ReplicatedGlobalMaxStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.ReplicatedGlobalMaxStatusValues" }; }
	FieldArray<float, 12> ReplicatedBaseLevelMaxStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.ReplicatedBaseLevelMaxStatusValues" }; }
	FieldArray<float, 12> ReplicatedGlobalCurrentStatusValuesField() { return { this, "UPrimalCharacterStatusComponent.ReplicatedGlobalCurrentStatusValues" }; }
	FieldArray<char, 12> CurrentStatusStatesField() { return { this, "UPrimalCharacterStatusComponent.CurrentStatusStates" }; }
	FieldArray<long double, 12> LastDecreasedStatusValuesTimesField() { return { this, "UPrimalCharacterStatusComponent.LastDecreasedStatusValuesTimes" }; }
	FieldArray<long double, 12> LastIncreasedStatusValuesTimesField() { return { this, "UPrimalCharacterStatusComponent.LastIncreasedStatusValuesTimes" }; }
	FieldArray<long double, 12> LastMaxedStatusValuesTimesField() { return { this, "UPrimalCharacterStatusComponent.LastMaxedStatusValuesTimes" }; }
	FieldArray<long double, 12> LastDepletedStatusValuesTimesField() { return { this, "UPrimalCharacterStatusComponent.LastDepletedStatusValuesTimes" }; }
	FieldValue<float> StaminaRecoveryExtraResourceDecreaseMultiplierField() { return { this, "UPrimalCharacterStatusComponent.StaminaRecoveryExtraResourceDecreaseMultiplier" }; }
	FieldValue<float> DehydrationStaminaRecoveryRateField() { return { this, "UPrimalCharacterStatusComponent.DehydrationStaminaRecoveryRate" }; }
	FieldValue<float> WaterConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.WaterConsumptionMultiplier" }; }
	FieldValue<float> FoodConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.FoodConsumptionMultiplier" }; }
	FieldValue<TArray<USoundBase *>> EnteredStatusStateSoundsField() { return { this, "UPrimalCharacterStatusComponent.EnteredStatusStateSounds" }; }
	FieldValue<TArray<USoundBase *>> ExitStatusStateSoundsField() { return { this, "UPrimalCharacterStatusComponent.ExitStatusStateSounds" }; }
	FieldValue<float> ExtraOxygenSpeedStatMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraOxygenSpeedStatMultiplier" }; }
	FieldValue<float> ExtraTamedHealthMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraTamedHealthMultiplier" }; }
	FieldValue<float> WakingTameFoodConsumptionRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.WakingTameFoodConsumptionRateMultiplier" }; }
	FieldValue<float> SwimmingStaminaRecoveryRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.SwimmingStaminaRecoveryRateMultiplier" }; }
	FieldValue<float> ExtraWaterConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraWaterConsumptionMultiplier" }; }
	FieldValue<float> ExtraFoodConsumptionMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraFoodConsumptionMultiplier" }; }
	FieldValue<float> DefaultMaxOxygenField() { return { this, "UPrimalCharacterStatusComponent.DefaultMaxOxygen" }; }
	FieldValue<long double> LastReplicatedCurrentStatusValuesTimeField() { return { this, "UPrimalCharacterStatusComponent.LastReplicatedCurrentStatusValuesTime" }; }
	FieldValue<float> OriginalMaxTorporField() { return { this, "UPrimalCharacterStatusComponent.OriginalMaxTorpor" }; }
	FieldValue<float> MountedDinoDinoWeightMultiplierField() { return { this, "UPrimalCharacterStatusComponent.MountedDinoDinoWeightMultiplier" }; }
	FieldValue<float> ExtraWildDinoDamageMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraWildDinoDamageMultiplier" }; }
	FieldValue<float> ExtraTamedDinoDamageMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraTamedDinoDamageMultiplier" }; }
	FieldValue<float> WeightMultiplierForCarriedPassengersField() { return { this, "UPrimalCharacterStatusComponent.WeightMultiplierForCarriedPassengers" }; }
	FieldValue<float> WeightMultiplierForPlatformPassengersInventoryField() { return { this, "UPrimalCharacterStatusComponent.WeightMultiplierForPlatformPassengersInventory" }; }
	FieldArray<float, 12> DinoMaxStatAddMultiplierImprintingField() { return { this, "UPrimalCharacterStatusComponent.DinoMaxStatAddMultiplierImprinting" }; }
	FieldValue<float> DinoImprintingQualityField() { return { this, "UPrimalCharacterStatusComponent.DinoImprintingQuality" }; }
	FieldValue<float> TamedBaseHealthMultiplierField() { return { this, "UPrimalCharacterStatusComponent.TamedBaseHealthMultiplier" }; }
	FieldValue<float> ExtraBabyDinoConsumingFoodRateMultiplierField() { return { this, "UPrimalCharacterStatusComponent.ExtraBabyDinoConsumingFoodRateMultiplier" }; }
	FieldValue<TArray<FString>> StatusValueNameOverridesField() { return { this, "UPrimalCharacterStatusComponent.StatusValueNameOverrides" }; }
	FieldValue<TSubclassOf<UDamageType>> RegainOxygenDamageTypeField() { return { this, "UPrimalCharacterStatusComponent.RegainOxygenDamageType" }; }
	FieldValue<bool> bInWeightLockField() { return { this, "UPrimalCharacterStatusComponent.bInWeightLock" }; }
	FieldValue<long double> LastReplicatedXPTimeField() { return { this, "UPrimalCharacterStatusComponent.LastReplicatedXPTime" }; }
	FieldValue<bool> bHasUnlockedMaxPlayerLevelAchievementThisSessionField() { return { this, "UPrimalCharacterStatusComponent.bHasUnlockedMaxPlayerLevelAchievementThisSession" }; }
	FieldValue<bool> bHasUnlockedMaxDinoLevelAchievementThisSessionField() { return { this, "UPrimalCharacterStatusComponent.bHasUnlockedMaxDinoLevelAchievementThisSession" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bCanSuffocate() { return { this, "UPrimalCharacterStatusComponent.bCanSuffocate" }; }
	BitFieldValue<bool, unsigned __int32> bCanSuffocateIfTamed() { return { this, "UPrimalCharacterStatusComponent.bCanSuffocateIfTamed" }; }
	BitFieldValue<bool, unsigned __int32> bCanGetHungry() { return { this, "UPrimalCharacterStatusComponent.bCanGetHungry" }; }
	BitFieldValue<bool, unsigned __int32> bUseStamina() { return { this, "UPrimalCharacterStatusComponent.bUseStamina" }; }
	BitFieldValue<bool, unsigned __int32> bWalkingConsumesStamina() { return { this, "UPrimalCharacterStatusComponent.bWalkingConsumesStamina" }; }
	BitFieldValue<bool, unsigned __int32> bRunningConsumesStamina() { return { this, "UPrimalCharacterStatusComponent.bRunningConsumesStamina" }; }
	BitFieldValue<bool, unsigned __int32> bConsumeFoodAutomatically() { return { this, "UPrimalCharacterStatusComponent.bConsumeFoodAutomatically" }; }
	BitFieldValue<bool, unsigned __int32> bAddExperienceAutomatically() { return { this, "UPrimalCharacterStatusComponent.bAddExperienceAutomatically" }; }
	BitFieldValue<bool, unsigned __int32> bConsumeWaterAutomatically() { return { this, "UPrimalCharacterStatusComponent.bConsumeWaterAutomatically" }; }
	BitFieldValue<bool, unsigned __int32> bAutomaticallyUpdateTemperature() { return { this, "UPrimalCharacterStatusComponent.bAutomaticallyUpdateTemperature" }; }
	BitFieldValue<bool, unsigned __int32> bReplicateGlobalStatusValues() { return { this, "UPrimalCharacterStatusComponent.bReplicateGlobalStatusValues" }; }
	BitFieldValue<bool, unsigned __int32> bAllowLevelUps() { return { this, "UPrimalCharacterStatusComponent.bAllowLevelUps" }; }
	BitFieldValue<bool, unsigned __int32> bInfiniteStats() { return { this, "UPrimalCharacterStatusComponent.bInfiniteStats" }; }
	BitFieldValue<bool, unsigned __int32> bAllowSharingXPWithTribe() { return { this, "UPrimalCharacterStatusComponent.bAllowSharingXPWithTribe" }; }
	BitFieldValue<bool, unsigned __int32> bUseStatusSpeedModifiers() { return { this, "UPrimalCharacterStatusComponent.bUseStatusSpeedModifiers" }; }
	BitFieldValue<bool, unsigned __int32> bStatusSpeedModifierOnlyFullOrNone() { return { this, "UPrimalCharacterStatusComponent.bStatusSpeedModifierOnlyFullOrNone" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreStatusSpeedModifierIfSwimming() { return { this, "UPrimalCharacterStatusComponent.bIgnoreStatusSpeedModifierIfSwimming" }; }
	BitFieldValue<bool, unsigned __int32> bPreventJump() { return { this, "UPrimalCharacterStatusComponent.bPreventJump" }; }
	BitFieldValue<bool, unsigned __int32> bInitializedBaseLevelMaxStatusValues() { return { this, "UPrimalCharacterStatusComponent.bInitializedBaseLevelMaxStatusValues" }; }
	BitFieldValue<bool, unsigned __int32> bInitializedMe() { return { this, "UPrimalCharacterStatusComponent.bInitializedMe" }; }
	BitFieldValue<bool, unsigned __int32> bServerFirstInitialized() { return { this, "UPrimalCharacterStatusComponent.bServerFirstInitialized" }; }
	BitFieldValue<bool, unsigned __int32> bRunningUseDefaultSpeed() { return { this, "UPrimalCharacterStatusComponent.bRunningUseDefaultSpeed" }; }
	BitFieldValue<bool, unsigned __int32> bNeverAllowXP() { return { this, "UPrimalCharacterStatusComponent.bNeverAllowXP" }; }
	BitFieldValue<bool, unsigned __int32> bPreventTamedStatReplication() { return { this, "UPrimalCharacterStatusComponent.bPreventTamedStatReplication" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAdjustStatusValueModification() { return { this, "UPrimalCharacterStatusComponent.bUseBPAdjustStatusValueModification" }; }
	BitFieldValue<bool, unsigned __int32> bForceDefaultSpeed() { return { this, "UPrimalCharacterStatusComponent.bForceDefaultSpeed" }; }
	BitFieldValue<bool, unsigned __int32> bForceRefreshWeight() { return { this, "UPrimalCharacterStatusComponent.bForceRefreshWeight" }; }
	BitFieldValue<bool, unsigned __int32> bForceGainOxygen() { return { this, "UPrimalCharacterStatusComponent.bForceGainOxygen" }; }
	BitFieldValue<bool, unsigned __int32> bFreezeStatusValues() { return { this, "UPrimalCharacterStatusComponent.bFreezeStatusValues" }; }
	BitFieldValue<bool, unsigned __int32> bTicked() { return { this, "UPrimalCharacterStatusComponent.bTicked" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyMaxLevel() { return { this, "UPrimalCharacterStatusComponent.bUseBPModifyMaxLevel" }; }
	BitFieldValue<bool, unsigned __int32> bNoStaminaRecoveryWhenStarving() { return { this, "UPrimalCharacterStatusComponent.bNoStaminaRecoveryWhenStarving" }; }
	BitFieldValue<bool, unsigned __int32> bApplyingStatusValueModifiers() { return { this, "UPrimalCharacterStatusComponent.bApplyingStatusValueModifiers" }; }
	BitFieldValue<bool, unsigned __int32> bDontScaleMeleeDamage() { return { this, "UPrimalCharacterStatusComponent.bDontScaleMeleeDamage" }; }
	BitFieldValue<bool, unsigned __int32> bInfiniteWeight() { return { this, "UPrimalCharacterStatusComponent.bInfiniteWeight" }; }

	// Functions

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "UPrimalCharacterStatusComponent.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void InitializeComponent() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.InitializeComponent"); }
	float GetTotalStatusModifierDescriptionIndex(int StatusValueModifierDescriptionIndex) { return NativeCall<float, int>(this, "UPrimalCharacterStatusComponent.GetTotalStatusModifierDescriptionIndex", StatusValueModifierDescriptionIndex); }
	void AddStatusValueModifier(EPrimalCharacterStatusValue::Type ValueType, float Amount, float Speed, bool bContinueOnUnchangedValue, bool bSetValue, int StatusValueModifierDescriptionIndex, bool bResetExistingModifierDescriptionIndex, float LimitExistingModifierDescriptionToMaxAmount, bool bSetAdditionalValue, EPrimalCharacterStatusValue::Type StopAtValueNearMax, bool bMakeUntameable, TSubclassOf<UDamageType> ScaleValueByCharacterDamageType) { NativeCall<void, EPrimalCharacterStatusValue::Type, float, float, bool, bool, int, bool, float, bool, EPrimalCharacterStatusValue::Type, bool, TSubclassOf<UDamageType>>(this, "UPrimalCharacterStatusComponent.AddStatusValueModifier", ValueType, Amount, Speed, bContinueOnUnchangedValue, bSetValue, StatusValueModifierDescriptionIndex, bResetExistingModifierDescriptionIndex, LimitExistingModifierDescriptionToMaxAmount, bSetAdditionalValue, StopAtValueNearMax, bMakeUntameable, ScaleValueByCharacterDamageType); }
	void ApplyStatusValueModifiers(float DeltaTime) { NativeCall<void, float>(this, "UPrimalCharacterStatusComponent.ApplyStatusValueModifiers", DeltaTime); }
	void TickStatus(float DeltaTime, bool bForceStatusUpdate) { NativeCall<void, float, bool>(this, "UPrimalCharacterStatusComponent.TickStatus", DeltaTime, bForceStatusUpdate); }
	void UpdateStatusValue(EPrimalCharacterStatusValue::Type valueType, float DeltaTime, bool bManualUpdate) { NativeCall<void, EPrimalCharacterStatusValue::Type, float, bool>(this, "UPrimalCharacterStatusComponent.UpdateStatusValue", valueType, DeltaTime, bManualUpdate); }
	void UpdateWeightStat(bool bForceSetValue) { NativeCall<void, bool>(this, "UPrimalCharacterStatusComponent.UpdateWeightStat", bForceSetValue); }
	void AdjustStatusValueModification(EPrimalCharacterStatusValue::Type valueType, float * Amount, TSubclassOf<UDamageType> DamageTypeClass, bool bManualModification) { NativeCall<void, EPrimalCharacterStatusValue::Type, float *, TSubclassOf<UDamageType>, bool>(this, "UPrimalCharacterStatusComponent.AdjustStatusValueModification", valueType, Amount, DamageTypeClass, bManualModification); }
	void GetDinoFoodConsumptionRateMultiplier(float * Amount) { NativeCall<void, float *>(this, "UPrimalCharacterStatusComponent.GetDinoFoodConsumptionRateMultiplier", Amount); }
	float ModifyCurrentStatusValue(EPrimalCharacterStatusValue::Type valueType, float Amount, bool bPercentOfMax, bool bPercentOfCurrent, bool bManualModification, bool bSetValue, TSubclassOf<UDamageType> DamageTypeClass, bool bDamageDontKill, bool bForceSetValue) { return NativeCall<float, EPrimalCharacterStatusValue::Type, float, bool, bool, bool, bool, TSubclassOf<UDamageType>, bool, bool>(this, "UPrimalCharacterStatusComponent.ModifyCurrentStatusValue", valueType, Amount, bPercentOfMax, bPercentOfCurrent, bManualModification, bSetValue, DamageTypeClass, bDamageDontKill, bForceSetValue); }
	void ChangedStatusState(EPrimalCharacterStatusState::Type valueType, bool bEnteredState) { NativeCall<void, EPrimalCharacterStatusState::Type, bool>(this, "UPrimalCharacterStatusComponent.ChangedStatusState", valueType, bEnteredState); }
	void CharacterUpdatedInventory(bool bEquippedOrUneqippedItem) { NativeCall<void, bool>(this, "UPrimalCharacterStatusComponent.CharacterUpdatedInventory", bEquippedOrUneqippedItem); }
	void RefreshInsulation() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.RefreshInsulation"); }
	void RescaleMaxStat(EPrimalCharacterStatusValue::Type LevelUpValueType, float TargetValue, bool bIsPercentOfTrueValue) { NativeCall<void, EPrimalCharacterStatusValue::Type, float, bool>(this, "UPrimalCharacterStatusComponent.RescaleMaxStat", LevelUpValueType, TargetValue, bIsPercentOfTrueValue); }
	void RefreshTemperature() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.RefreshTemperature"); }
	void UpdatedCurrentStatusValue(EPrimalCharacterStatusValue::Type valueType, float Amount, bool bManualModification, TSubclassOf<UDamageType> DamageTypeClass, bool bDamageDontKill, bool bDontAdjustOtherStats) { NativeCall<void, EPrimalCharacterStatusValue::Type, float, bool, TSubclassOf<UDamageType>, bool, bool>(this, "UPrimalCharacterStatusComponent.UpdatedCurrentStatusValue", valueType, Amount, bManualModification, DamageTypeClass, bDamageDontKill, bDontAdjustOtherStats); }
	float GetStatusValueRecoveryRate(EPrimalCharacterStatusValue::Type valueType) { return NativeCall<float, EPrimalCharacterStatusValue::Type>(this, "UPrimalCharacterStatusComponent.GetStatusValueRecoveryRate", valueType); }
	void DrawLocalPlayerHUD(AShooterHUD * HUD, float ScaleMult, bool bFromBottomRight) { NativeCall<void, AShooterHUD *, float, bool>(this, "UPrimalCharacterStatusComponent.DrawLocalPlayerHUD", HUD, ScaleMult, bFromBottomRight); }
	void DrawLocalPlayerHUDDescriptions(AShooterHUD * HUD, long double TheTimeSeconds, float ScaleMult, bool bDrawBottomRight) { NativeCall<void, AShooterHUD *, long double, float, bool>(this, "UPrimalCharacterStatusComponent.DrawLocalPlayerHUDDescriptions", HUD, TheTimeSeconds, ScaleMult, bDrawBottomRight); }
	bool IsInStatusState(EPrimalCharacterStatusState::Type StateType) { return NativeCall<bool, EPrimalCharacterStatusState::Type>(this, "UPrimalCharacterStatusComponent.IsInStatusState", StateType); }
	void OnJumped() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.OnJumped"); }
	float GetMeleeDamageModifier() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetMeleeDamageModifier"); }
	float GetMovementSpeedModifier() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetMovementSpeedModifier"); }
	float GetJumpZModifier() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetJumpZModifier"); }
	void ServerSyncReplicatedValues() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.ServerSyncReplicatedValues"); }
	bool CanLevelUp(EPrimalCharacterStatusValue::Type LevelUpValueType) { return NativeCall<bool, EPrimalCharacterStatusValue::Type>(this, "UPrimalCharacterStatusComponent.CanLevelUp", LevelUpValueType); }
	void ServerApplyLevelUp(EPrimalCharacterStatusValue::Type LevelUpValueType, AShooterPlayerController * ByPC) { NativeCall<void, EPrimalCharacterStatusValue::Type, AShooterPlayerController *>(this, "UPrimalCharacterStatusComponent.ServerApplyLevelUp", LevelUpValueType, ByPC); }
	void SetBaseLevel(int Level, bool bDontCurrentSetToMax) { NativeCall<void, int, bool>(this, "UPrimalCharacterStatusComponent.SetBaseLevel", Level, bDontCurrentSetToMax); }
	void SetTameable(bool bTameable) { NativeCall<void, bool>(this, "UPrimalCharacterStatusComponent.SetTameable", bTameable); }
	void SetTamed(float TameIneffectivenessModifier) { NativeCall<void, float>(this, "UPrimalCharacterStatusComponent.SetTamed", TameIneffectivenessModifier); }
	void ApplyTamingStatModifiers(float TameIneffectivenessModifier) { NativeCall<void, float>(this, "UPrimalCharacterStatusComponent.ApplyTamingStatModifiers", TameIneffectivenessModifier); }
	FString * GetStatusValueString(FString * result, EPrimalCharacterStatusValue::Type ValueType, bool bValueOnly) { return NativeCall<FString *, FString *, EPrimalCharacterStatusValue::Type, bool>(this, "UPrimalCharacterStatusComponent.GetStatusValueString", result, ValueType, bValueOnly); }
	FString * GetStatusNameString(FString * result, EPrimalCharacterStatusValue::Type ValueType) { return NativeCall<FString *, FString *, EPrimalCharacterStatusValue::Type>(this, "UPrimalCharacterStatusComponent.GetStatusNameString", result, ValueType); }
	FString * GetStatusMaxValueString(FString * result, EPrimalCharacterStatusValue::Type ValueType, bool bValueOnly) { return NativeCall<FString *, FString *, EPrimalCharacterStatusValue::Type, bool>(this, "UPrimalCharacterStatusComponent.GetStatusMaxValueString", result, ValueType, bValueOnly); }
	void AddExperience(float HowMuch, bool bShareWithTribe, EXPType::Type XPType) { NativeCall<void, float, bool, EXPType::Type>(this, "UPrimalCharacterStatusComponent.AddExperience", HowMuch, bShareWithTribe, XPType); }
	int GetNumLevelUpsAvailable() { return NativeCall<int>(this, "UPrimalCharacterStatusComponent.GetNumLevelUpsAvailable"); }
	float GetExperienceRequiredForNextLevelUp() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetExperienceRequiredForNextLevelUp"); }
	float GetExperienceRequiredForPreviousLevelUp() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetExperienceRequiredForPreviousLevelUp"); }
	bool IsAtMaxLevel() { return NativeCall<bool>(this, "UPrimalCharacterStatusComponent.IsAtMaxLevel"); }
	bool HasExperienceForLevelUp() { return NativeCall<bool>(this, "UPrimalCharacterStatusComponent.HasExperienceForLevelUp"); }
	float GetExperiencePercent() { return NativeCall<float>(this, "UPrimalCharacterStatusComponent.GetExperiencePercent"); }
	void NetSyncMaxStatusValues_Implementation(TArray<float> * NetMaxStatusValues, TArray<float> * NetBaseMaxStatusValues) { NativeCall<void, TArray<float> *, TArray<float> *>(this, "UPrimalCharacterStatusComponent.NetSyncMaxStatusValues_Implementation", NetMaxStatusValues, NetBaseMaxStatusValues); }
	void ClientSyncMaxStatusValues_Implementation(TArray<float> * NetMaxStatusValues, TArray<float> * NetBaseMaxStatusValues) { NativeCall<void, TArray<float> *, TArray<float> *>(this, "UPrimalCharacterStatusComponent.ClientSyncMaxStatusValues_Implementation", NetMaxStatusValues, NetBaseMaxStatusValues); }
	void SetMaxStatusValue(EPrimalCharacterStatusValue::Type StatType, float newValue) { NativeCall<void, EPrimalCharacterStatusValue::Type, float>(this, "UPrimalCharacterStatusComponent.SetMaxStatusValue", StatType, newValue); }
	void RescaleAllStats() { NativeCall<void>(this, "UPrimalCharacterStatusComponent.RescaleAllStats"); }
	float BPModifyMaxExperiencePoints(float InMaxExperiencePoints) { return NativeCall<float, float>(this, "UPrimalCharacterStatusComponent.BPModifyMaxExperiencePoints", InMaxExperiencePoints); }
	int BPModifyMaxLevel(int InMaxLevel) { return NativeCall<int, int>(this, "UPrimalCharacterStatusComponent.BPModifyMaxLevel", InMaxLevel); }
};

struct APrimalDinoCharacter : APrimalCharacter
{
	FieldValue<TWeakObjectPtr<AActor>> ForcedMasterTargetField() { return { this, "APrimalDinoCharacter.ForcedMasterTarget" }; }
	FieldValue<FName> MountCharacterSocketNameField() { return { this, "APrimalDinoCharacter.MountCharacterSocketName" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> MountCharacterField() { return { this, "APrimalDinoCharacter.MountCharacter" }; }
	FieldValue<ECollisionChannel> MeshOriginalCollisionChannelField() { return { this, "APrimalDinoCharacter.MeshOriginalCollisionChannel" }; }
	FieldValue<float> ColorizationIntensityField() { return { this, "APrimalDinoCharacter.ColorizationIntensity" }; }
	FieldValue<FVector> RidingAttackExtraVelocityField() { return { this, "APrimalDinoCharacter.RidingAttackExtraVelocity" }; }
	FieldValue<UAnimMontage *> StartChargeAnimationField() { return { this, "APrimalDinoCharacter.StartChargeAnimation" }; }
	FieldValue<TArray<UAnimMontage *>> AttackAnimationsField() { return { this, "APrimalDinoCharacter.AttackAnimations" }; }
	FieldValue<TArray<float>> AttackAnimationWeightsField() { return { this, "APrimalDinoCharacter.AttackAnimationWeights" }; }
	FieldValue<TArray<float>> AttackAnimationsTimeFromEndToConsiderFinishedField() { return { this, "APrimalDinoCharacter.AttackAnimationsTimeFromEndToConsiderFinished" }; }
	FieldValue<TArray<UMaterialInterface *>> FemaleMaterialOverridesField() { return { this, "APrimalDinoCharacter.FemaleMaterialOverrides" }; }
	FieldValue<float> PaintConsumptionMultiplierField() { return { this, "APrimalDinoCharacter.PaintConsumptionMultiplier" }; }
	FieldValue<float> ChargingBlockedStopTimeThresholdField() { return { this, "APrimalDinoCharacter.ChargingBlockedStopTimeThreshold" }; }
	FieldValue<TArray<FName>> MeleeSwingSocketsField() { return { this, "APrimalDinoCharacter.MeleeSwingSockets" }; }
	FieldValue<int> MeleeDamageAmountField() { return { this, "APrimalDinoCharacter.MeleeDamageAmount" }; }
	FieldValue<float> MeleeDamageImpulseField() { return { this, "APrimalDinoCharacter.MeleeDamageImpulse" }; }
	FieldValue<float> MeleeSwingRadiusField() { return { this, "APrimalDinoCharacter.MeleeSwingRadius" }; }
	FieldValue<char> CurrentAttackIndexField() { return { this, "APrimalDinoCharacter.CurrentAttackIndex" }; }
	FieldValue<char> LastAttackIndexField() { return { this, "APrimalDinoCharacter.LastAttackIndex" }; }
	FieldValue<TSubclassOf<UDamageType>> MeleeDamageTypeField() { return { this, "APrimalDinoCharacter.MeleeDamageType" }; }
	FieldValue<TSubclassOf<UDamageType>> StepActorDamageTypeOverrideField() { return { this, "APrimalDinoCharacter.StepActorDamageTypeOverride" }; }
	FieldValue<float> AttackOffsetField() { return { this, "APrimalDinoCharacter.AttackOffset" }; }
	FieldValue<float> FleeHealthPercentageField() { return { this, "APrimalDinoCharacter.FleeHealthPercentage" }; }
	FieldValue<float> BreakFleeHealthPercentageField() { return { this, "APrimalDinoCharacter.BreakFleeHealthPercentage" }; }
	FieldValue<FString> TamerStringField() { return { this, "APrimalDinoCharacter.TamerString" }; }
	FieldValue<FString> TamedNameField() { return { this, "APrimalDinoCharacter.TamedName" }; }
	FieldValue<FVector2D> OverlayTooltipPaddingField() { return { this, "APrimalDinoCharacter.OverlayTooltipPadding" }; }
	FieldValue<FVector2D> OverlayTooltipScaleField() { return { this, "APrimalDinoCharacter.OverlayTooltipScale" }; }
	FieldValue<FVector> RiderFPVCameraOffsetField() { return { this, "APrimalDinoCharacter.RiderFPVCameraOffset" }; }
	FieldValue<FVector> LandingLocationField() { return { this, "APrimalDinoCharacter.LandingLocation" }; }
	FieldValue<long double> StartLandingTimeField() { return { this, "APrimalDinoCharacter.StartLandingTime" }; }
	FieldValue<long double> LastAxisStartPressTimeField() { return { this, "APrimalDinoCharacter.LastAxisStartPressTime" }; }
	FieldValue<long double> LastMoveForwardTimeField() { return { this, "APrimalDinoCharacter.LastMoveForwardTime" }; }
	FieldValue<float> LandingTraceMaxDistanceField() { return { this, "APrimalDinoCharacter.LandingTraceMaxDistance" }; }
	FieldValue<float> FlyingWanderFixedDistanceAmountField() { return { this, "APrimalDinoCharacter.FlyingWanderFixedDistanceAmount" }; }
	FieldValue<float> FlyingWanderRandomDistanceAmountField() { return { this, "APrimalDinoCharacter.FlyingWanderRandomDistanceAmount" }; }
	FieldValue<float> AcceptableLandingRadiusField() { return { this, "APrimalDinoCharacter.AcceptableLandingRadius" }; }
	FieldValue<float> MaxLandingTimeField() { return { this, "APrimalDinoCharacter.MaxLandingTime" }; }
	FieldArray<float, 2> GenderSpeedMultipliersField() { return { this, "APrimalDinoCharacter.GenderSpeedMultipliers" }; }
	FieldValue<float> ChargeSpeedMultiplierField() { return { this, "APrimalDinoCharacter.ChargeSpeedMultiplier" }; }
	FieldValue<UAnimMontage *> ChargingAnimField() { return { this, "APrimalDinoCharacter.ChargingAnim" }; }
	FieldValue<float> ChargingStaminaPerSecondDrainField() { return { this, "APrimalDinoCharacter.ChargingStaminaPerSecondDrain" }; }
	FieldValue<float> ChargingStopDotTresholdField() { return { this, "APrimalDinoCharacter.ChargingStopDotTreshold" }; }
	FieldValue<FVector> LastChargeLocationField() { return { this, "APrimalDinoCharacter.LastChargeLocation" }; }
	FieldValue<long double> LastStartChargingTimeField() { return { this, "APrimalDinoCharacter.LastStartChargingTime" }; }
	FieldValue<TWeakObjectPtr<AShooterCharacter>> RiderField() { return { this, "APrimalDinoCharacter.Rider" }; }
	FieldValue<TWeakObjectPtr<AShooterCharacter>> PreviousRiderField() { return { this, "APrimalDinoCharacter.PreviousRider" }; }
	FieldValue<TSubclassOf<UPrimalItem>> SaddleItemClassField() { return { this, "APrimalDinoCharacter.SaddleItemClass" }; }
	FieldValue<TArray<FSaddlePassengerSeatDefinition>> NoSaddlePassengerSeatsField() { return { this, "APrimalDinoCharacter.NoSaddlePassengerSeats" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> CarriedCharacterField() { return { this, "APrimalDinoCharacter.CarriedCharacter" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> PreviousCarriedCharacterField() { return { this, "APrimalDinoCharacter.PreviousCarriedCharacter" }; }
	FieldValue<UAnimMontage *> DinoWithPassengerAnimField() { return { this, "APrimalDinoCharacter.DinoWithPassengerAnim" }; }
	FieldValue<UAnimMontage *> DinoWithDinoPassengerAnimField() { return { this, "APrimalDinoCharacter.DinoWithDinoPassengerAnim" }; }
	FieldValue<TArray<TWeakObjectPtr<APrimalCharacter>>> PassengerPerSeatField() { return { this, "APrimalDinoCharacter.PassengerPerSeat" }; }
	FieldValue<TArray<APrimalCharacter *>> SavedPassengerPerSeatField() { return { this, "APrimalDinoCharacter.SavedPassengerPerSeat" }; }
	FieldValue<TArray<TWeakObjectPtr<APrimalCharacter>>> PrevPassengerPerSeatField() { return { this, "APrimalDinoCharacter.PrevPassengerPerSeat" }; }
	FieldValue<long double> LastClientCameraRotationServerUpdateField() { return { this, "APrimalDinoCharacter.LastClientCameraRotationServerUpdate" }; }
	FieldValue<int> LastPlayedAttackAnimationField() { return { this, "APrimalDinoCharacter.LastPlayedAttackAnimation" }; }
	FieldValue<char> AttackIndexOfPlayedAnimationField() { return { this, "APrimalDinoCharacter.AttackIndexOfPlayedAnimation" }; }
	FieldValue<TArray<FDinoBaseLevelWeightEntry>> DinoBaseLevelWeightEntriesField() { return { this, "APrimalDinoCharacter.DinoBaseLevelWeightEntries" }; }
	FieldValue<float> OriginalCapsuleHalfHeightField() { return { this, "APrimalDinoCharacter.OriginalCapsuleHalfHeight" }; }
	FieldValue<TArray<FVector>> LastSocketPositionsField() { return { this, "APrimalDinoCharacter.LastSocketPositions" }; }
	FieldValue<TSet<AActor *, DefaultKeyFuncs<AActor *, 0>, FDefaultSetAllocator>> MeleeSwingHurtListField() { return { this, "APrimalDinoCharacter.MeleeSwingHurtList" }; }
	FieldValue<long double> EndAttackTargetTimeField() { return { this, "APrimalDinoCharacter.EndAttackTargetTime" }; }
	FieldValue<FVector> RidingFirstPersonViewLocationOffsetField() { return { this, "APrimalDinoCharacter.RidingFirstPersonViewLocationOffset" }; }
	FieldValue<float> BabyChanceOfTwinsField() { return { this, "APrimalDinoCharacter.BabyChanceOfTwins" }; }
	FieldValue<float> BabyGestationSpeedField() { return { this, "APrimalDinoCharacter.BabyGestationSpeed" }; }
	FieldValue<float> ExtraBabyGestationSpeedMultiplierField() { return { this, "APrimalDinoCharacter.ExtraBabyGestationSpeedMultiplier" }; }
	FieldValue<float> AutoFadeOutAfterTameTimeField() { return { this, "APrimalDinoCharacter.AutoFadeOutAfterTameTime" }; }
	FieldValue<long double> LastEggBoostedTimeField() { return { this, "APrimalDinoCharacter.LastEggBoostedTime" }; }
	FieldValue<float> WildPercentageChanceOfBabyField() { return { this, "APrimalDinoCharacter.WildPercentageChanceOfBaby" }; }
	FieldValue<float> WildBabyAgeWeightField() { return { this, "APrimalDinoCharacter.WildBabyAgeWeight" }; }
	FieldValue<float> BabyGestationProgressField() { return { this, "APrimalDinoCharacter.BabyGestationProgress" }; }
	FieldValue<float> LastBabyAgeField() { return { this, "APrimalDinoCharacter.LastBabyAge" }; }
	FieldValue<float> LastBabyGestationProgressField() { return { this, "APrimalDinoCharacter.LastBabyGestationProgress" }; }
	FieldValue<float> BabyChanceOfTripletsField() { return { this, "APrimalDinoCharacter.BabyChanceOfTriplets" }; }
	FieldValue<float> BabyAgeField() { return { this, "APrimalDinoCharacter.BabyAge" }; }
	FieldValue<float> MaxPercentOfCapsulHeightAllowedForIKField() { return { this, "APrimalDinoCharacter.MaxPercentOfCapsulHeightAllowedForIK" }; }
	FieldValue<float> SlopeBiasForMaxCapsulePercentField() { return { this, "APrimalDinoCharacter.SlopeBiasForMaxCapsulePercent" }; }
	FieldValue<float> FlyingForceRotationRateModifierField() { return { this, "APrimalDinoCharacter.FlyingForceRotationRateModifier" }; }
	FieldValue<TArray<FName>> HideBoneNamesField() { return { this, "APrimalDinoCharacter.HideBoneNames" }; }
	FieldValue<FString> HideBonesStringField() { return { this, "APrimalDinoCharacter.HideBonesString" }; }
	FieldValue<FVector> WaterSurfaceExtraJumpVectorField() { return { this, "APrimalDinoCharacter.WaterSurfaceExtraJumpVector" }; }
	FieldValue<FVector> FlyerTakeOffAdditionalVelocityField() { return { this, "APrimalDinoCharacter.FlyerTakeOffAdditionalVelocity" }; }
	FieldValue<float> OpenDoorDelayField() { return { this, "APrimalDinoCharacter.OpenDoorDelay" }; }
	FieldValue<float> TamedWanderHarvestIntervalField() { return { this, "APrimalDinoCharacter.TamedWanderHarvestInterval" }; }
	FieldValue<float> TamedWanderHarvestSearchRangeField() { return { this, "APrimalDinoCharacter.TamedWanderHarvestSearchRange" }; }
	FieldValue<float> TamedWanderHarvestCollectRadiusField() { return { this, "APrimalDinoCharacter.TamedWanderHarvestCollectRadius" }; }
	FieldValue<FVector> TamedWanderHarvestCollectOffsetField() { return { this, "APrimalDinoCharacter.TamedWanderHarvestCollectOffset" }; }
	FieldValue<float> RootLocSwimOffsetField() { return { this, "APrimalDinoCharacter.RootLocSwimOffset" }; }
	FieldValue<float> PlayAnimBelowHealthPercentField() { return { this, "APrimalDinoCharacter.PlayAnimBelowHealthPercent" }; }
	FieldValue<float> LeavePlayAnimBelowHealthPercentField() { return { this, "APrimalDinoCharacter.LeavePlayAnimBelowHealthPercent" }; }
	FieldValue<float> PlatformSaddleMaxStructureBuildDistance2DField() { return { this, "APrimalDinoCharacter.PlatformSaddleMaxStructureBuildDistance2D" }; }
	FieldValue<UAnimMontage *> PlayAnimBelowHealthField() { return { this, "APrimalDinoCharacter.PlayAnimBelowHealth" }; }
	FieldValue<USoundBase *> LowHealthExitSoundField() { return { this, "APrimalDinoCharacter.LowHealthExitSound" }; }
	FieldValue<USoundBase *> LowHealthEnterSoundField() { return { this, "APrimalDinoCharacter.LowHealthEnterSound" }; }
	FieldValue<float> SwimOffsetInterpSpeedField() { return { this, "APrimalDinoCharacter.SwimOffsetInterpSpeed" }; }
	FieldValue<float> CurrentRootLocSwimOffsetField() { return { this, "APrimalDinoCharacter.CurrentRootLocSwimOffset" }; }
	FieldValue<float> AIRangeMultiplierField() { return { this, "APrimalDinoCharacter.AIRangeMultiplier" }; }
	FieldArray<char, 6> PreventColorizationRegionsField() { return { this, "APrimalDinoCharacter.PreventColorizationRegions" }; }
	FieldArray<char, 6> ColorSetIndicesField() { return { this, "APrimalDinoCharacter.ColorSetIndices" }; }
	FieldArray<float, 6> ColorSetIntensityMultipliersField() { return { this, "APrimalDinoCharacter.ColorSetIntensityMultipliers" }; }
	FieldValue<float> MeleeAttackStaminaCostField() { return { this, "APrimalDinoCharacter.MeleeAttackStaminaCost" }; }
	FieldValue<UAnimMontage *> WakingTameAnimationField() { return { this, "APrimalDinoCharacter.WakingTameAnimation" }; }
	FieldValue<TWeakObjectPtr<AActor>> TargetField() { return { this, "APrimalDinoCharacter.Target" }; }
	FieldValue<TWeakObjectPtr<AActor>> TamedFollowTargetField() { return { this, "APrimalDinoCharacter.TamedFollowTarget" }; }
	FieldValue<float> PercentChanceFemaleField() { return { this, "APrimalDinoCharacter.PercentChanceFemale" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> DeathGiveItemClassesField() { return { this, "APrimalDinoCharacter.DeathGiveItemClasses" }; }
	FieldValue<TArray<float>> DeathGiveItemChanceToBeBlueprintField() { return { this, "APrimalDinoCharacter.DeathGiveItemChanceToBeBlueprint" }; }
	FieldValue<float> DeathGiveItemQualityMinField() { return { this, "APrimalDinoCharacter.DeathGiveItemQualityMin" }; }
	FieldValue<float> DeathGiveItemQualityMaxField() { return { this, "APrimalDinoCharacter.DeathGiveItemQualityMax" }; }
	FieldValue<float> DeathGiveItemRangeField() { return { this, "APrimalDinoCharacter.DeathGiveItemRange" }; }
	FieldValue<FString> DeathGiveAchievementField() { return { this, "APrimalDinoCharacter.DeathGiveAchievement" }; }
	FieldValue<USoundBase *> OverrideAreaMusicField() { return { this, "APrimalDinoCharacter.OverrideAreaMusic" }; }
	FieldValue<FVector> UnboardLocationOffsetField() { return { this, "APrimalDinoCharacter.UnboardLocationOffset" }; }
	FieldValue<float> LastTimeWhileHeadingToGoalField() { return { this, "APrimalDinoCharacter.LastTimeWhileHeadingToGoal" }; }
	FieldValue<float> RidingNetUpdateFequencyField() { return { this, "APrimalDinoCharacter.RidingNetUpdateFequency" }; }
	FieldValue<float> RiderMaxSpeedModifierField() { return { this, "APrimalDinoCharacter.RiderMaxSpeedModifier" }; }
	FieldValue<float> RiderExtraMaxSpeedModifierField() { return { this, "APrimalDinoCharacter.RiderExtraMaxSpeedModifier" }; }
	FieldValue<float> RiderMaxRunSpeedModifierField() { return { this, "APrimalDinoCharacter.RiderMaxRunSpeedModifier" }; }
	FieldValue<float> RiderRotationRateModifierField() { return { this, "APrimalDinoCharacter.RiderRotationRateModifier" }; }
	FieldValue<float> SwimmingRotationRateModifierField() { return { this, "APrimalDinoCharacter.SwimmingRotationRateModifier" }; }
	FieldValue<float> chargingRotationRateModifierField() { return { this, "APrimalDinoCharacter.chargingRotationRateModifier" }; }
	FieldValue<UAnimMontage *> EnterFlightAnimField() { return { this, "APrimalDinoCharacter.EnterFlightAnim" }; }
	FieldValue<UAnimMontage *> ExitFlightAnimField() { return { this, "APrimalDinoCharacter.ExitFlightAnim" }; }
	FieldValue<UAnimMontage *> SleepConsumeFoodAnimField() { return { this, "APrimalDinoCharacter.SleepConsumeFoodAnim" }; }
	FieldValue<UAnimMontage *> WakingConsumeFoodAnimField() { return { this, "APrimalDinoCharacter.WakingConsumeFoodAnim" }; }
	FieldValue<UAnimMontage *> FallAsleepAnimField() { return { this, "APrimalDinoCharacter.FallAsleepAnim" }; }
	FieldValue<UAnimMontage *> TamedUnsleepAnimField() { return { this, "APrimalDinoCharacter.TamedUnsleepAnim" }; }
	FieldValue<UAnimMontage *> WildUnsleepAnimField() { return { this, "APrimalDinoCharacter.WildUnsleepAnim" }; }
	FieldValue<UAnimMontage *> OpenDoorAnimField() { return { this, "APrimalDinoCharacter.OpenDoorAnim" }; }
	FieldValue<float> ControlFacePitchInterpSpeedField() { return { this, "APrimalDinoCharacter.ControlFacePitchInterpSpeed" }; }
	FieldValue<float> TamedWalkableFloorZField() { return { this, "APrimalDinoCharacter.TamedWalkableFloorZ" }; }
	FieldValue<float> CurrentMovementAnimRateField() { return { this, "APrimalDinoCharacter.CurrentMovementAnimRate" }; }
	FieldValue<int> MinPlayerLevelForWakingTameField() { return { this, "APrimalDinoCharacter.MinPlayerLevelForWakingTame" }; }
	FieldValue<float> ForceNextAttackIndexField() { return { this, "APrimalDinoCharacter.ForceNextAttackIndex" }; }
	FieldValue<TSubclassOf<UPrimalInventoryComponent>> TamedInventoryComponentTemplateField() { return { this, "APrimalDinoCharacter.TamedInventoryComponentTemplate" }; }
	FieldValue<float> DeathInventoryChanceToUseField() { return { this, "APrimalDinoCharacter.DeathInventoryChanceToUse" }; }
	FieldValue<float> WakingTameFeedIntervalField() { return { this, "APrimalDinoCharacter.WakingTameFeedInterval" }; }
	FieldValue<long double> LastWakingTameFedTimeField() { return { this, "APrimalDinoCharacter.LastWakingTameFedTime" }; }
	FieldValue<float> DeathInventoryQualityPerLevelMultiplierField() { return { this, "APrimalDinoCharacter.DeathInventoryQualityPerLevelMultiplier" }; }
	FieldValue<float> RequiredTameAffinityField() { return { this, "APrimalDinoCharacter.RequiredTameAffinity" }; }
	FieldValue<float> RequiredTameAffinityPerBaseLevelField() { return { this, "APrimalDinoCharacter.RequiredTameAffinityPerBaseLevel" }; }
	FieldValue<char> TamedAITargetingRangeField() { return { this, "APrimalDinoCharacter.TamedAITargetingRange" }; }
	FieldValue<FName> PassengerBoneNameOverrideField() { return { this, "APrimalDinoCharacter.PassengerBoneNameOverride" }; }
	FieldValue<float> CurrentTameAffinityField() { return { this, "APrimalDinoCharacter.CurrentTameAffinity" }; }
	FieldValue<float> TameIneffectivenessModifierField() { return { this, "APrimalDinoCharacter.TameIneffectivenessModifier" }; }
	FieldValue<float> TameIneffectivenessByAffinityField() { return { this, "APrimalDinoCharacter.TameIneffectivenessByAffinity" }; }
	FieldValue<int> LastFrameUseLowQualityAnimationTickField() { return { this, "APrimalDinoCharacter.LastFrameUseLowQualityAnimationTick" }; }
	FieldValue<int> MaxSaddleStructuresHeightField() { return { this, "APrimalDinoCharacter.MaxSaddleStructuresHeight" }; }
	FieldValue<int> SaddlePivotOffsetField() { return { this, "APrimalDinoCharacter.SaddlePivotOffset" }; }
	FieldValue<int> MaxSaddleStructuresNumField() { return { this, "APrimalDinoCharacter.MaxSaddleStructuresNum" }; }
	FieldValue<float> TamingFoodConsumeIntervalField() { return { this, "APrimalDinoCharacter.TamingFoodConsumeInterval" }; }
	FieldValue<float> DediForceAttackAnimTimeField() { return { this, "APrimalDinoCharacter.DediForceAttackAnimTime" }; }
	FieldValue<float> DediForceStartAttackAfterAnimTimeField() { return { this, "APrimalDinoCharacter.DediForceStartAttackAfterAnimTime" }; }
	FieldValue<float> WakingTameFoodIncreaseMultiplierField() { return { this, "APrimalDinoCharacter.WakingTameFoodIncreaseMultiplier" }; }
	FieldValue<int> TamingTeamIDField() { return { this, "APrimalDinoCharacter.TamingTeamID" }; }
	FieldValue<int> OwningPlayerIDField() { return { this, "APrimalDinoCharacter.OwningPlayerID" }; }
	FieldValue<FString> OwningPlayerNameField() { return { this, "APrimalDinoCharacter.OwningPlayerName" }; }
	FieldValue<long double> TamingLastFoodConsumptionTimeField() { return { this, "APrimalDinoCharacter.TamingLastFoodConsumptionTime" }; }
	FieldValue<unsigned int> DinoID1Field() { return { this, "APrimalDinoCharacter.DinoID1" }; }
	FieldValue<unsigned int> DinoID2Field() { return { this, "APrimalDinoCharacter.DinoID2" }; }
	FieldValue<FRotator> PreviousAimRotField() { return { this, "APrimalDinoCharacter.PreviousAimRot" }; }
	FieldValue<int> TamedAggressionLevelField() { return { this, "APrimalDinoCharacter.TamedAggressionLevel" }; }
	FieldValue<float> TamingIneffectivenessModifierIncreaseByDamagePercentField() { return { this, "APrimalDinoCharacter.TamingIneffectivenessModifierIncreaseByDamagePercent" }; }
	FieldValue<int> NPCSpawnerExtraLevelOffsetField() { return { this, "APrimalDinoCharacter.NPCSpawnerExtraLevelOffset" }; }
	FieldValue<float> NPCSpawnerLevelMultiplierField() { return { this, "APrimalDinoCharacter.NPCSpawnerLevelMultiplier" }; }
	FieldValue<TWeakObjectPtr<APrimalStructureItemContainer_SupplyCrate>> LinkedSupplyCrateField() { return { this, "APrimalDinoCharacter.LinkedSupplyCrate" }; }
	FieldValue<float> UntamedPoopTimeMinIntervalField() { return { this, "APrimalDinoCharacter.UntamedPoopTimeMinInterval" }; }
	FieldValue<float> UntamedPoopTimeMaxIntervalField() { return { this, "APrimalDinoCharacter.UntamedPoopTimeMaxInterval" }; }
	FieldValue<float> MeleeHarvestDamageMultiplierField() { return { this, "APrimalDinoCharacter.MeleeHarvestDamageMultiplier" }; }
	FieldValue<float> AllowRidingMaxDistanceField() { return { this, "APrimalDinoCharacter.AllowRidingMaxDistance" }; }
	FieldValue<float> UntamedPoopTimeCacheField() { return { this, "APrimalDinoCharacter.UntamedPoopTimeCache" }; }
	FieldValue<TSubclassOf<UPrimalItem>> BaseEggClassField() { return { this, "APrimalDinoCharacter.BaseEggClass" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> EggItemsToSpawnField() { return { this, "APrimalDinoCharacter.EggItemsToSpawn" }; }
	FieldValue<TArray<float>> EggWeightsToSpawnField() { return { this, "APrimalDinoCharacter.EggWeightsToSpawn" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> FertilizedEggItemsToSpawnField() { return { this, "APrimalDinoCharacter.FertilizedEggItemsToSpawn" }; }
	FieldValue<TArray<float>> FertilizedEggWeightsToSpawnField() { return { this, "APrimalDinoCharacter.FertilizedEggWeightsToSpawn" }; }
	FieldValue<float> EggChanceToSpawnUnstasisField() { return { this, "APrimalDinoCharacter.EggChanceToSpawnUnstasis" }; }
	FieldValue<float> EggIntervalBetweenUnstasisChancesField() { return { this, "APrimalDinoCharacter.EggIntervalBetweenUnstasisChances" }; }
	FieldValue<float> EggRangeMaximumNumberFromSameDinoTypeField() { return { this, "APrimalDinoCharacter.EggRangeMaximumNumberFromSameDinoType" }; }
	FieldValue<int> EggMaximumNumberFromSameDinoTypeField() { return { this, "APrimalDinoCharacter.EggMaximumNumberFromSameDinoType" }; }
	FieldValue<float> EggRangeMaximumNumberField() { return { this, "APrimalDinoCharacter.EggRangeMaximumNumber" }; }
	FieldValue<int> EggMaximumNumberField() { return { this, "APrimalDinoCharacter.EggMaximumNumber" }; }
	FieldValue<float> UntamedWalkingSpeedModifierField() { return { this, "APrimalDinoCharacter.UntamedWalkingSpeedModifier" }; }
	FieldValue<float> TamedWalkingSpeedModifierField() { return { this, "APrimalDinoCharacter.TamedWalkingSpeedModifier" }; }
	FieldValue<float> UntamedRunningSpeedModifierField() { return { this, "APrimalDinoCharacter.UntamedRunningSpeedModifier" }; }
	FieldValue<float> TamedRunningSpeedModifierField() { return { this, "APrimalDinoCharacter.TamedRunningSpeedModifier" }; }
	FieldValue<UAnimSequence *> RiderAnimOverrideField() { return { this, "APrimalDinoCharacter.RiderAnimOverride" }; }
	FieldValue<UAnimSequence *> TurningRightRiderAnimOverrideField() { return { this, "APrimalDinoCharacter.TurningRightRiderAnimOverride" }; }
	FieldValue<UAnimSequence *> TurningLeftRiderAnimOverrideField() { return { this, "APrimalDinoCharacter.TurningLeftRiderAnimOverride" }; }
	FieldValue<UAnimSequence *> LatchedRiderAnimOverrideField() { return { this, "APrimalDinoCharacter.LatchedRiderAnimOverride" }; }
	FieldValue<UAnimSequence *> RiderMoveAnimOverrideField() { return { this, "APrimalDinoCharacter.RiderMoveAnimOverride" }; }
	FieldValue<float> RidingAnimSpeedFactorField() { return { this, "APrimalDinoCharacter.RidingAnimSpeedFactor" }; }
	FieldValue<UAnimMontage *> StartRidingAnimOverrideField() { return { this, "APrimalDinoCharacter.StartRidingAnimOverride" }; }
	FieldValue<UAnimMontage *> StopRidingAnimOverrideField() { return { this, "APrimalDinoCharacter.StopRidingAnimOverride" }; }
	FieldValue<FName> TargetingTeamNameOverrideField() { return { this, "APrimalDinoCharacter.TargetingTeamNameOverride" }; }
	FieldValue<float> ExtraTamedSpeedMultiplierField() { return { this, "APrimalDinoCharacter.ExtraTamedSpeedMultiplier" }; }
	FieldValue<float> ExtraUnTamedSpeedMultiplierField() { return { this, "APrimalDinoCharacter.ExtraUnTamedSpeedMultiplier" }; }
	FieldValue<long double> LastEggSpawnChanceTimeField() { return { this, "APrimalDinoCharacter.LastEggSpawnChanceTime" }; }
	FieldValue<FName> OriginalNPCVolumeNameField() { return { this, "APrimalDinoCharacter.OriginalNPCVolumeName" }; }
	FieldValue<float> OutsideOriginalNPCVolumeStasisDestroyIntervalField() { return { this, "APrimalDinoCharacter.OutsideOriginalNPCVolumeStasisDestroyInterval" }; }
	FieldValue<float> StasisedDestroyIntervalField() { return { this, "APrimalDinoCharacter.StasisedDestroyInterval" }; }
	FieldValue<float> TamedAllowNamingTimeField() { return { this, "APrimalDinoCharacter.TamedAllowNamingTime" }; }
	FieldValue<float> MovementSpeedScalingRotationRatePowerField() { return { this, "APrimalDinoCharacter.MovementSpeedScalingRotationRatePower" }; }
	FieldValue<float> AttackNoStaminaTorpidityMultiplierField() { return { this, "APrimalDinoCharacter.AttackNoStaminaTorpidityMultiplier" }; }
	FieldValue<float> DecayDestructionPeriodField() { return { this, "APrimalDinoCharacter.DecayDestructionPeriod" }; }
	FieldValue<long double> TamedAtTimeField() { return { this, "APrimalDinoCharacter.TamedAtTime" }; }
	FieldValue<long double> LastInAllyRangeTimeField() { return { this, "APrimalDinoCharacter.LastInAllyRangeTime" }; }
	FieldValue<TArray<APrimalStructure *>> LatchedOnStructuresField() { return { this, "APrimalDinoCharacter.LatchedOnStructures" }; }
	FieldValue<int> OriginalTargetingTeamField() { return { this, "APrimalDinoCharacter.OriginalTargetingTeam" }; }
	FieldValue<float> PreviousRootYawSpeedField() { return { this, "APrimalDinoCharacter.PreviousRootYawSpeed" }; }
	FieldValue<long double> LastTimeFallingField() { return { this, "APrimalDinoCharacter.LastTimeFalling" }; }
	FieldValue<float> TamedCorpseLifespanField() { return { this, "APrimalDinoCharacter.TamedCorpseLifespan" }; }
	FieldValue<float> MateBoostDamageReceiveMultiplierField() { return { this, "APrimalDinoCharacter.MateBoostDamageReceiveMultiplier" }; }
	FieldValue<float> MateBoostDamageGiveMultiplierField() { return { this, "APrimalDinoCharacter.MateBoostDamageGiveMultiplier" }; }
	FieldValue<float> MateBoostRangeField() { return { this, "APrimalDinoCharacter.MateBoostRange" }; }
	FieldValue<FName> DinoNameTagField() { return { this, "APrimalDinoCharacter.DinoNameTag" }; }
	FieldValue<AShooterPlayerController *> AttackMyTargetForPlayerControllerField() { return { this, "APrimalDinoCharacter.AttackMyTargetForPlayerController" }; }
	FieldValue<float> RidingAttackExtraVelocityDelayField() { return { this, "APrimalDinoCharacter.RidingAttackExtraVelocityDelay" }; }
	FieldValue<float> StepDamageRadialDamageIntervalField() { return { this, "APrimalDinoCharacter.StepDamageRadialDamageInterval" }; }
	FieldValue<float> StepDamageRadialDamageExtraRadiusField() { return { this, "APrimalDinoCharacter.StepDamageRadialDamageExtraRadius" }; }
	FieldValue<float> StepDamageRadialDamageAmountGeneralField() { return { this, "APrimalDinoCharacter.StepDamageRadialDamageAmountGeneral" }; }
	FieldValue<float> StepDamageRadialDamageAmountHarvestableField() { return { this, "APrimalDinoCharacter.StepDamageRadialDamageAmountHarvestable" }; }
	FieldValue<long double> LastRadialStepDamageTimeField() { return { this, "APrimalDinoCharacter.LastRadialStepDamageTime" }; }
	FieldValue<TSubclassOf<UDamageType>> StepHarvestableDamageTypeField() { return { this, "APrimalDinoCharacter.StepHarvestableDamageType" }; }
	FieldValue<float> StepDamageFootDamageIntervalField() { return { this, "APrimalDinoCharacter.StepDamageFootDamageInterval" }; }
	FieldValue<float> StepDamageFootDamageRadiusField() { return { this, "APrimalDinoCharacter.StepDamageFootDamageRadius" }; }
	FieldValue<float> StepDamageFootDamageAmountField() { return { this, "APrimalDinoCharacter.StepDamageFootDamageAmount" }; }
	FieldValue<TArray<FName>> StepDamageFootDamageSocketsField() { return { this, "APrimalDinoCharacter.StepDamageFootDamageSockets" }; }
	FieldValue<float> DurationBeforeMovingStuckPawnField() { return { this, "APrimalDinoCharacter.DurationBeforeMovingStuckPawn" }; }
	FieldValue<FVector> LastCheckedLocationField() { return { this, "APrimalDinoCharacter.LastCheckedLocation" }; }
	FieldValue<long double> LastValidNotStuckTimeField() { return { this, "APrimalDinoCharacter.LastValidNotStuckTime" }; }
	FieldValue<UAnimMontage *> StartledAnimationRightDefaultField() { return { this, "APrimalDinoCharacter.StartledAnimationRightDefault" }; }
	FieldValue<UAnimMontage *> StartledAnimationLeftField() { return { this, "APrimalDinoCharacter.StartledAnimationLeft" }; }
	FieldValue<TArray<UAnimMontage *>> StartledAnimationsField() { return { this, "APrimalDinoCharacter.StartledAnimations" }; }
	FieldValue<UAnimMontage *> FlyingStartledAnimationField() { return { this, "APrimalDinoCharacter.FlyingStartledAnimation" }; }
	FieldValue<float> RandomPlayStartledAnimIntervalMinField() { return { this, "APrimalDinoCharacter.RandomPlayStartledAnimIntervalMin" }; }
	FieldValue<float> RandomPlayStartledAnimIntervalMaxField() { return { this, "APrimalDinoCharacter.RandomPlayStartledAnimIntervalMax" }; }
	FieldValue<float> StartledAnimationCooldownField() { return { this, "APrimalDinoCharacter.StartledAnimationCooldown" }; }
	FieldValue<float> DefaultActivateAttackRangeOffsetField() { return { this, "APrimalDinoCharacter.DefaultActivateAttackRangeOffset" }; }
	FieldValue<float> CorpseTargetingMultiplierField() { return { this, "APrimalDinoCharacter.CorpseTargetingMultiplier" }; }
	FieldValue<long double> LastFootStepDamageTimeField() { return { this, "APrimalDinoCharacter.LastFootStepDamageTime" }; }
	FieldValue<long double> LastStartledTimeField() { return { this, "APrimalDinoCharacter.LastStartledTime" }; }
	FieldValue<float> CorpseLifespanNonRelevantField() { return { this, "APrimalDinoCharacter.CorpseLifespanNonRelevant" }; }
	FieldValue<float> MinStaminaForRiderField() { return { this, "APrimalDinoCharacter.MinStaminaForRider" }; }
	FieldValue<float> LoseStaminaWithRiderRateField() { return { this, "APrimalDinoCharacter.LoseStaminaWithRiderRate" }; }
	FieldValue<float> FollowingRunDistanceField() { return { this, "APrimalDinoCharacter.FollowingRunDistance" }; }
	FieldValue<float> MaxDinoKillerTransferWeightPercentField() { return { this, "APrimalDinoCharacter.MaxDinoKillerTransferWeightPercent" }; }
	FieldValue<float> NPCZoneVolumeCountWeightField() { return { this, "APrimalDinoCharacter.NPCZoneVolumeCountWeight" }; }
	FieldValue<float> NPCLerpToMaxRandomBaseLevelField() { return { this, "APrimalDinoCharacter.NPCLerpToMaxRandomBaseLevel" }; }
	FieldValue<FVector> FloatingHUDTextWorldOffsetField() { return { this, "APrimalDinoCharacter.FloatingHUDTextWorldOffset" }; }
	FieldValue<long double> LastAttackedTargetTimeField() { return { this, "APrimalDinoCharacter.LastAttackedTargetTime" }; }
	FieldValue<long double> LastForcedLandingCheckTimeField() { return { this, "APrimalDinoCharacter.LastForcedLandingCheckTime" }; }
	FieldValue<long double> LastAllyTargetLookTimeField() { return { this, "APrimalDinoCharacter.LastAllyTargetLookTime" }; }
	FieldValue<long double> LastAttackedTimeField() { return { this, "APrimalDinoCharacter.LastAttackedTime" }; }
	FieldValue<long double> LastPlayerDinoOverlapRelevantTimeField() { return { this, "APrimalDinoCharacter.LastPlayerDinoOverlapRelevantTime" }; }
	FieldValue<FRotator> DinoAimRotationOffsetField() { return { this, "APrimalDinoCharacter.DinoAimRotationOffset" }; }
	FieldValue<long double> LastDinoAllyLookInterpTimeField() { return { this, "APrimalDinoCharacter.LastDinoAllyLookInterpTime" }; }
	FieldValue<FVector> LastRiderOverlappedPositionField() { return { this, "APrimalDinoCharacter.LastRiderOverlappedPosition" }; }
	FieldValue<TWeakObjectPtr<APrimalCharacter>> AutoDragByPawnField() { return { this, "APrimalDinoCharacter.AutoDragByPawn" }; }
	FieldValue<long double> NextRidingFlyerUndergroundCheckField() { return { this, "APrimalDinoCharacter.NextRidingFlyerUndergroundCheck" }; }
	FieldValue<long double> LastSetRiderTimeField() { return { this, "APrimalDinoCharacter.LastSetRiderTime" }; }
	FieldValue<TSubclassOf<UPrimalItem>> RepairRequirementsItemField() { return { this, "APrimalDinoCharacter.RepairRequirementsItem" }; }
	FieldValue<float> RepairAmountRemainingField() { return { this, "APrimalDinoCharacter.RepairAmountRemaining" }; }
	FieldValue<float> RepairCheckIntervalField() { return { this, "APrimalDinoCharacter.RepairCheckInterval" }; }
	FieldValue<float> RepairPercentPerIntervalField() { return { this, "APrimalDinoCharacter.RepairPercentPerInterval" }; }
	FieldValue<FVector> RiderCheckTraceOffsetField() { return { this, "APrimalDinoCharacter.RiderCheckTraceOffset" }; }
	FieldValue<FVector> RiderEjectionImpulseField() { return { this, "APrimalDinoCharacter.RiderEjectionImpulse" }; }
	FieldValue<float> WakingTameAffinityDecreaseFoodPercentageField() { return { this, "APrimalDinoCharacter.WakingTameAffinityDecreaseFoodPercentage" }; }
	FieldValue<float> WakingTameAllowFeedingFoodPercentageField() { return { this, "APrimalDinoCharacter.WakingTameAllowFeedingFoodPercentage" }; }
	FieldValue<float> WakingTameFoodAffinityMultiplierField() { return { this, "APrimalDinoCharacter.WakingTameFoodAffinityMultiplier" }; }
	FieldValue<float> CheckForWildAmbientHarvestingIntervalMinField() { return { this, "APrimalDinoCharacter.CheckForWildAmbientHarvestingIntervalMin" }; }
	FieldValue<float> CheckForWildAmbientHarvestingIntervalMaxField() { return { this, "APrimalDinoCharacter.CheckForWildAmbientHarvestingIntervalMax" }; }
	FieldValue<float> WildAmbientHarvestingTimerField() { return { this, "APrimalDinoCharacter.WildAmbientHarvestingTimer" }; }
	FieldValue<UAnimMontage *> WildAmbientHarvestingAnimationField() { return { this, "APrimalDinoCharacter.WildAmbientHarvestingAnimation" }; }
	FieldValue<TArray<UAnimMontage *>> WildAmbientHarvestingAnimationsField() { return { this, "APrimalDinoCharacter.WildAmbientHarvestingAnimations" }; }
	FieldValue<float> WildAmbientHarvestingRadiusField() { return { this, "APrimalDinoCharacter.WildAmbientHarvestingRadius" }; }
	FieldValue<int> FlyerNumUnderGroundFailField() { return { this, "APrimalDinoCharacter.FlyerNumUnderGroundFail" }; }
	FieldValue<int> AbsoluteBaseLevelField() { return { this, "APrimalDinoCharacter.AbsoluteBaseLevel" }; }
	FieldValue<TSubclassOf<UDamageType>> TamedHarvestDamageTypeField() { return { this, "APrimalDinoCharacter.TamedHarvestDamageType" }; }
	FieldValue<TArray<APrimalCharacter *>> DraggedRagdollsField() { return { this, "APrimalDinoCharacter.DraggedRagdolls" }; }
	FieldValue<FVector> LastOverrodeRandomWanderLocationField() { return { this, "APrimalDinoCharacter.LastOverrodeRandomWanderLocation" }; }
	FieldValue<float> ChargeBumpDamageField() { return { this, "APrimalDinoCharacter.ChargeBumpDamage" }; }
	FieldValue<TSubclassOf<UDamageType>> ChargeBumpDamageTypeField() { return { this, "APrimalDinoCharacter.ChargeBumpDamageType" }; }
	FieldValue<float> ChargeBumpImpulseField() { return { this, "APrimalDinoCharacter.ChargeBumpImpulse" }; }
	FieldValue<float> MinChargeIntervalField() { return { this, "APrimalDinoCharacter.MinChargeInterval" }; }
	FieldValue<float> PlayerMountedLaunchFowardSpeedField() { return { this, "APrimalDinoCharacter.PlayerMountedLaunchFowardSpeed" }; }
	FieldValue<float> PlayerMountedLaunchUpSpeedField() { return { this, "APrimalDinoCharacter.PlayerMountedLaunchUpSpeed" }; }
	FieldValue<float> AttackOnLaunchMaximumTargetDistanceField() { return { this, "APrimalDinoCharacter.AttackOnLaunchMaximumTargetDistance" }; }
	FieldValue<float> KeepFlightRemainingTimeField() { return { this, "APrimalDinoCharacter.KeepFlightRemainingTime" }; }
	FieldValue<UAnimMontage *> MountCharacterAnimationField() { return { this, "APrimalDinoCharacter.MountCharacterAnimation" }; }
	FieldValue<UAnimMontage *> UnmountCharacterAnimationField() { return { this, "APrimalDinoCharacter.UnmountCharacterAnimation" }; }
	FieldValue<UAnimMontage *> EndChargingAnimationField() { return { this, "APrimalDinoCharacter.EndChargingAnimation" }; }
	FieldValue<float> FlyingRunSpeedModifierField() { return { this, "APrimalDinoCharacter.FlyingRunSpeedModifier" }; }
	FieldValue<float> ChargingAnimDelayField() { return { this, "APrimalDinoCharacter.ChargingAnimDelay" }; }
	FieldValue<FName> RiderSocketNameField() { return { this, "APrimalDinoCharacter.RiderSocketName" }; }
	FieldValue<float> ChargingActivationRequiresStaminaField() { return { this, "APrimalDinoCharacter.ChargingActivationRequiresStamina" }; }
	FieldValue<float> ChargingActivationConsumesStaminaField() { return { this, "APrimalDinoCharacter.ChargingActivationConsumesStamina" }; }
	FieldValue<float> FlyerHardBreakingOverrideField() { return { this, "APrimalDinoCharacter.FlyerHardBreakingOverride" }; }
	FieldValue<float> BabyScaleField() { return { this, "APrimalDinoCharacter.BabyScale" }; }
	FieldValue<float> BabySpeedMultiplierField() { return { this, "APrimalDinoCharacter.BabySpeedMultiplier" }; }
	FieldValue<float> BabyPitchMultiplierField() { return { this, "APrimalDinoCharacter.BabyPitchMultiplier" }; }
	FieldValue<float> BabyVolumeMultiplierField() { return { this, "APrimalDinoCharacter.BabyVolumeMultiplier" }; }
	FieldValue<TWeakObjectPtr<AActor>> WanderAroundActorField() { return { this, "APrimalDinoCharacter.WanderAroundActor" }; }
	FieldValue<float> WanderAroundActorMaxDistanceField() { return { this, "APrimalDinoCharacter.WanderAroundActorMaxDistance" }; }
	FieldValue<long double> ChargingStartBlockedTimeField() { return { this, "APrimalDinoCharacter.ChargingStartBlockedTime" }; }
	FieldValue<long double> LastChargeEndTimeField() { return { this, "APrimalDinoCharacter.LastChargeEndTime" }; }
	FieldValue<TArray<APrimalStructure *>> SaddledStructuresField() { return { this, "APrimalDinoCharacter.SaddledStructures" }; }
	FieldValue<long double> LastTamedFlyerNearbyAllyCheckTimeField() { return { this, "APrimalDinoCharacter.LastTamedFlyerNearbyAllyCheckTime" }; }
	FieldValue<long double> LastUpdatedBabyAgeAtTimeField() { return { this, "APrimalDinoCharacter.LastUpdatedBabyAgeAtTime" }; }
	FieldValue<long double> LastUpdatedGestationAtTimeField() { return { this, "APrimalDinoCharacter.LastUpdatedGestationAtTime" }; }
	FieldValue<long double> LastUpdatedMatingAtTimeField() { return { this, "APrimalDinoCharacter.LastUpdatedMatingAtTime" }; }
	FieldValue<float> BabyAgeSpeedField() { return { this, "APrimalDinoCharacter.BabyAgeSpeed" }; }
	FieldValue<float> ExtraBabyAgeSpeedMultiplierField() { return { this, "APrimalDinoCharacter.ExtraBabyAgeSpeedMultiplier" }; }
	FieldValue<float> FemaleMatingRangeAdditionField() { return { this, "APrimalDinoCharacter.FemaleMatingRangeAddition" }; }
	FieldValue<float> FemaleMatingTimeField() { return { this, "APrimalDinoCharacter.FemaleMatingTime" }; }
	FieldValue<long double> NextAllowedMatingTimeField() { return { this, "APrimalDinoCharacter.NextAllowedMatingTime" }; }
	FieldValue<float> MatingProgressField() { return { this, "APrimalDinoCharacter.MatingProgress" }; }
	FieldValue<long double> LastMatingNotificationTimeField() { return { this, "APrimalDinoCharacter.LastMatingNotificationTime" }; }
	FieldValue<APrimalDinoCharacter *> MatingWithDinoField() { return { this, "APrimalDinoCharacter.MatingWithDino" }; }
	FieldValue<UAnimMontage *> MatingAnimationMaleField() { return { this, "APrimalDinoCharacter.MatingAnimationMale" }; }
	FieldArray<char, 12> GestationEggNumberOfLevelUpPointsAppliedField() { return { this, "APrimalDinoCharacter.GestationEggNumberOfLevelUpPointsApplied" }; }
	FieldValue<float> GestationEggTamedIneffectivenessModifierField() { return { this, "APrimalDinoCharacter.GestationEggTamedIneffectivenessModifier" }; }
	FieldArray<char, 6> GestationEggColorSetIndicesField() { return { this, "APrimalDinoCharacter.GestationEggColorSetIndices" }; }
	FieldValue<float> NewFemaleMinTimeBetweenMatingField() { return { this, "APrimalDinoCharacter.NewFemaleMinTimeBetweenMating" }; }
	FieldValue<float> NewFemaleMaxTimeBetweenMatingField() { return { this, "APrimalDinoCharacter.NewFemaleMaxTimeBetweenMating" }; }
	FieldValue<TArray<TSubclassOf<APrimalBuff>>> DefaultTamedBuffsField() { return { this, "APrimalDinoCharacter.DefaultTamedBuffs" }; }
	FieldValue<FVector> InterpolatedVelocityField() { return { this, "APrimalDinoCharacter.InterpolatedVelocity" }; }
	FieldValue<FVector> OldInterpolatedLocationField() { return { this, "APrimalDinoCharacter.OldInterpolatedLocation" }; }
	FieldValue<float> HyperThermiaInsulationField() { return { this, "APrimalDinoCharacter.HyperThermiaInsulation" }; }
	FieldValue<float> HypoThermiaInsulationField() { return { this, "APrimalDinoCharacter.HypoThermiaInsulation" }; }
	FieldValue<float> InsulationRangeField() { return { this, "APrimalDinoCharacter.InsulationRange" }; }
	FieldValue<float> GangOverlapRangeField() { return { this, "APrimalDinoCharacter.GangOverlapRange" }; }
	FieldValue<float> GangDamageResistanceField() { return { this, "APrimalDinoCharacter.GangDamageResistance" }; }
	FieldValue<float> GangDamageField() { return { this, "APrimalDinoCharacter.GangDamage" }; }
	FieldValue<int> MaxGangCountField() { return { this, "APrimalDinoCharacter.MaxGangCount" }; }
	FieldValue<int> GangCountField() { return { this, "APrimalDinoCharacter.GangCount" }; }
	FieldValue<long double> LastGangCheckTimeField() { return { this, "APrimalDinoCharacter.LastGangCheckTime" }; }
	FieldValue<FVector> LastGangCheckPositionField() { return { this, "APrimalDinoCharacter.LastGangCheckPosition" }; }
	FieldValue<int> PreviousTargetingTeamField() { return { this, "APrimalDinoCharacter.PreviousTargetingTeam" }; }
	FieldValue<int> LastRiderExitFrameCounterField() { return { this, "APrimalDinoCharacter.LastRiderExitFrameCounter" }; }
	FieldValue<float> WildRandomScaleField() { return { this, "APrimalDinoCharacter.WildRandomScale" }; }
	FieldValue<float> HeldJumpSlowFallingGravityZScaleField() { return { this, "APrimalDinoCharacter.HeldJumpSlowFallingGravityZScale" }; }
	FieldValue<UAnimMontage *> SlowFallingAnimField() { return { this, "APrimalDinoCharacter.SlowFallingAnim" }; }
	FieldValue<float> SlowFallingStaminaCostPerSecondField() { return { this, "APrimalDinoCharacter.SlowFallingStaminaCostPerSecond" }; }
	FieldValue<float> NoRiderRotationModifierField() { return { this, "APrimalDinoCharacter.NoRiderRotationModifier" }; }
	FieldValue<FName> RiderFPVCameraUseSocketNameField() { return { this, "APrimalDinoCharacter.RiderFPVCameraUseSocketName" }; }
	FieldValue<FName> RiderLatchedFPVCameraUseSocketNameField() { return { this, "APrimalDinoCharacter.RiderLatchedFPVCameraUseSocketName" }; }
	FieldValue<FName> PassengerFPVCameraRootSocketField() { return { this, "APrimalDinoCharacter.PassengerFPVCameraRootSocket" }; }
	FieldValue<TArray<FName>> FPVRiderBoneNamesToHideField() { return { this, "APrimalDinoCharacter.FPVRiderBoneNamesToHide" }; }
	FieldValue<float> ExtraRunningSpeedModifierField() { return { this, "APrimalDinoCharacter.ExtraRunningSpeedModifier" }; }
	FieldValue<float> ScaleExtraRunningSpeedModifierMinField() { return { this, "APrimalDinoCharacter.ScaleExtraRunningSpeedModifierMin" }; }
	FieldValue<float> ScaleExtraRunningSpeedModifierMaxField() { return { this, "APrimalDinoCharacter.ScaleExtraRunningSpeedModifierMax" }; }
	FieldValue<float> ScaleExtraRunningSpeedModifierSpeedField() { return { this, "APrimalDinoCharacter.ScaleExtraRunningSpeedModifierSpeed" }; }
	FieldValue<float> LastHigherScaleExtraRunningSpeedValueField() { return { this, "APrimalDinoCharacter.LastHigherScaleExtraRunningSpeedValue" }; }
	FieldValue<long double> LastHigherScaleExtraRunningSpeedTimeField() { return { this, "APrimalDinoCharacter.LastHigherScaleExtraRunningSpeedTime" }; }
	FieldValue<float> RiderMovementSpeedScalingRotationRatePowerMultiplierField() { return { this, "APrimalDinoCharacter.RiderMovementSpeedScalingRotationRatePowerMultiplier" }; }
	FieldValue<int> LoadDestroyWildDinosUnderVersionField() { return { this, "APrimalDinoCharacter.LoadDestroyWildDinosUnderVersion" }; }
	FieldValue<int> SaveDestroyWildDinosUnderVersionField() { return { this, "APrimalDinoCharacter.SaveDestroyWildDinosUnderVersion" }; }
	FieldValue<float> AllowWaterSurfaceExtraJumpStaminaCostField() { return { this, "APrimalDinoCharacter.AllowWaterSurfaceExtraJumpStaminaCost" }; }
	FieldValue<USoundBase *> PlayKillLocalSoundField() { return { this, "APrimalDinoCharacter.PlayKillLocalSound" }; }
	FieldValue<TWeakObjectPtr<AActor>> RiderAttackTargetField() { return { this, "APrimalDinoCharacter.RiderAttackTarget" }; }
	FieldValue<FVector> RiderAttackLocationField() { return { this, "APrimalDinoCharacter.RiderAttackLocation" }; }
	FieldValue<char> TribeGroupPetOrderingRankField() { return { this, "APrimalDinoCharacter.TribeGroupPetOrderingRank" }; }
	FieldValue<char> TribeGroupPetRidingRankField() { return { this, "APrimalDinoCharacter.TribeGroupPetRidingRank" }; }
	FieldValue<char> FollowStoppingDistanceField() { return { this, "APrimalDinoCharacter.FollowStoppingDistance" }; }
	FieldValue<FString> ImprinterNameField() { return { this, "APrimalDinoCharacter.ImprinterName" }; }
	FieldValue<unsigned __int64> ImprinterPlayerDataIDField() { return { this, "APrimalDinoCharacter.ImprinterPlayerDataID" }; }
	FieldValue<float> BabyMinCuddleIntervalField() { return { this, "APrimalDinoCharacter.BabyMinCuddleInterval" }; }
	FieldValue<float> BabyMaxCuddleIntervalField() { return { this, "APrimalDinoCharacter.BabyMaxCuddleInterval" }; }
	FieldValue<float> BabyCuddleGracePeriodField() { return { this, "APrimalDinoCharacter.BabyCuddleGracePeriod" }; }
	FieldValue<float> BabyCuddleLoseImpringQualityPerSecondField() { return { this, "APrimalDinoCharacter.BabyCuddleLoseImpringQualityPerSecond" }; }
	FieldValue<float> BabyCuddleWalkDistanceField() { return { this, "APrimalDinoCharacter.BabyCuddleWalkDistance" }; }
	FieldValue<FVector> BabyCuddleWalkStartingLocationField() { return { this, "APrimalDinoCharacter.BabyCuddleWalkStartingLocation" }; }
	FieldValue<long double> BabyNextCuddleTimeField() { return { this, "APrimalDinoCharacter.BabyNextCuddleTime" }; }
	FieldValue<TEnumAsByte<enum EBabyCuddleType::Type>> BabyCuddleTypeField() { return { this, "APrimalDinoCharacter.BabyCuddleType" }; }
	FieldValue<TSubclassOf<UPrimalItem>> BabyCuddleFoodField() { return { this, "APrimalDinoCharacter.BabyCuddleFood" }; }
	FieldValue<UAnimMontage *> BabyCuddledAnimationField() { return { this, "APrimalDinoCharacter.BabyCuddledAnimation" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> MyBabyCuddleFoodTypesField() { return { this, "APrimalDinoCharacter.MyBabyCuddleFoodTypes" }; }
	FieldValue<float> RiderMaxImprintingQualityDamageReductionField() { return { this, "APrimalDinoCharacter.RiderMaxImprintingQualityDamageReduction" }; }
	FieldValue<float> RiderMaxImprintingQualityDamageMultiplierField() { return { this, "APrimalDinoCharacter.RiderMaxImprintingQualityDamageMultiplier" }; }
	FieldValue<float> BabyImprintingQualityTotalMaturationTimeField() { return { this, "APrimalDinoCharacter.BabyImprintingQualityTotalMaturationTime" }; }
	FieldValue<float> WakingTameMaxDistanceField() { return { this, "APrimalDinoCharacter.WakingTameMaxDistance" }; }
	FieldValue<float> TimeBetweenTamedWakingEatAnimationsField() { return { this, "APrimalDinoCharacter.TimeBetweenTamedWakingEatAnimations" }; }
	FieldValue<long double> LastEatAnimationTimeField() { return { this, "APrimalDinoCharacter.LastEatAnimationTime" }; }
	FieldValue<float> StepDamageFootDamageRunningMultiplierField() { return { this, "APrimalDinoCharacter.StepDamageFootDamageRunningMultiplier" }; }
	FieldValue<float> maxRangeForWeaponTriggeredTooltipField() { return { this, "APrimalDinoCharacter.maxRangeForWeaponTriggeredTooltip" }; }
	FieldValue<float> StepRadialDamageOffsetField() { return { this, "APrimalDinoCharacter.StepRadialDamageOffset" }; }
	FieldValue<float> ForcePawnBigPushingForTimeField() { return { this, "APrimalDinoCharacter.ForcePawnBigPushingForTime" }; }
	FieldValue<float> AIDinoForceActiveUntasisingRangeField() { return { this, "APrimalDinoCharacter.AIDinoForceActiveUntasisingRange" }; }
	FieldValue<float> WildRunningRotationRateModifierField() { return { this, "APrimalDinoCharacter.WildRunningRotationRateModifier" }; }
	FieldValue<float> TamedRunningRotationRateModifierField() { return { this, "APrimalDinoCharacter.TamedRunningRotationRateModifier" }; }
	FieldValue<float> TamedSwimmingRotationRateModifierField() { return { this, "APrimalDinoCharacter.TamedSwimmingRotationRateModifier" }; }
	FieldValue<float> WildSwimmingRotationRateModifierField() { return { this, "APrimalDinoCharacter.WildSwimmingRotationRateModifier" }; }
	FieldValue<float> RiderFlyingRotationRateModifierField() { return { this, "APrimalDinoCharacter.RiderFlyingRotationRateModifier" }; }
	FieldValue<float> NoRiderFlyingRotationRateModifierField() { return { this, "APrimalDinoCharacter.NoRiderFlyingRotationRateModifier" }; }
	FieldValue<float> AICombatRotationRateModifierField() { return { this, "APrimalDinoCharacter.AICombatRotationRateModifier" }; }
	FieldValue<float> WalkingRotationRateModifierField() { return { this, "APrimalDinoCharacter.WalkingRotationRateModifier" }; }
	FieldValue<float> SetAttackTargetTraceDistanceField() { return { this, "APrimalDinoCharacter.SetAttackTargetTraceDistance" }; }
	FieldValue<float> SetAttackTargetTraceWidthField() { return { this, "APrimalDinoCharacter.SetAttackTargetTraceWidth" }; }
	FieldValue<float> WanderRadiusMultiplierField() { return { this, "APrimalDinoCharacter.WanderRadiusMultiplier" }; }
	FieldValue<long double> RepeatPrimaryAttackLastSendTimeField() { return { this, "APrimalDinoCharacter.RepeatPrimaryAttackLastSendTime" }; }
	FieldValue<long double> NextTamedDinoCharacterStatusTickTimeField() { return { this, "APrimalDinoCharacter.NextTamedDinoCharacterStatusTickTime" }; }
	FieldValue<long double> LastTamedDinoCharacterStatusTickTimeField() { return { this, "APrimalDinoCharacter.LastTamedDinoCharacterStatusTickTime" }; }
	FieldValue<UAnimMontage *> PlayerMountedCarryAnimationField() { return { this, "APrimalDinoCharacter.PlayerMountedCarryAnimation" }; }
	FieldValue<float> HealthBarOffsetYField() { return { this, "APrimalDinoCharacter.HealthBarOffsetY" }; }
	FieldValue<float> LimitRiderYawOnLatchedRangeField() { return { this, "APrimalDinoCharacter.LimitRiderYawOnLatchedRange" }; }
	FieldValue<float> LatchingDistanceLimitField() { return { this, "APrimalDinoCharacter.LatchingDistanceLimit" }; }
	FieldValue<float> LatchingInitialYawField() { return { this, "APrimalDinoCharacter.LatchingInitialYaw" }; }
	FieldValue<float> LatchingInitialPitchField() { return { this, "APrimalDinoCharacter.LatchingInitialPitch" }; }
	FieldValue<float> LatchingInterpolatedPitchField() { return { this, "APrimalDinoCharacter.LatchingInterpolatedPitch" }; }
	FieldValue<float> LatchedFirstPersonViewAngleField() { return { this, "APrimalDinoCharacter.LatchedFirstPersonViewAngle" }; }
	FieldValue<float> LatchingCameraInterpolationSpeedField() { return { this, "APrimalDinoCharacter.LatchingCameraInterpolationSpeed" }; }
	FieldValue<float> TargetLatchingInitialYawField() { return { this, "APrimalDinoCharacter.TargetLatchingInitialYaw" }; }
	FieldValue<float> CurrentStrafeMagnitudeField() { return { this, "APrimalDinoCharacter.CurrentStrafeMagnitude" }; }
	FieldValue<float> GainStaminaWhenLatchedRateField() { return { this, "APrimalDinoCharacter.GainStaminaWhenLatchedRate" }; }
	FieldValue<int> LastFrameMoveRightField() { return { this, "APrimalDinoCharacter.LastFrameMoveRight" }; }
	FieldValue<int> LastFrameMoveLeftField() { return { this, "APrimalDinoCharacter.LastFrameMoveLeft" }; }
	FieldValue<FRotator> LastRiderMountedWeaponRotationField() { return { this, "APrimalDinoCharacter.LastRiderMountedWeaponRotation" }; }
	FieldValue<long double> LastRiderMountedWeaponRotationSentTimeField() { return { this, "APrimalDinoCharacter.LastRiderMountedWeaponRotationSentTime" }; }
	FieldValue<int> DeathGivesDossierIndexField() { return { this, "APrimalDinoCharacter.DeathGivesDossierIndex" }; }
	FieldValue<float> DeathGivesDossierDelayField() { return { this, "APrimalDinoCharacter.DeathGivesDossierDelay" }; }
	FieldValue<FName> SaddleRiderMovementTraceThruSocketNameField() { return { this, "APrimalDinoCharacter.SaddleRiderMovementTraceThruSocketName" }; }
	FieldValue<float> SwimmingRunSpeedModifierField() { return { this, "APrimalDinoCharacter.SwimmingRunSpeedModifier" }; }
	FieldValue<float> RidingSwimmingRunSpeedModifierField() { return { this, "APrimalDinoCharacter.RidingSwimmingRunSpeedModifier" }; }
	FieldValue<long double> DinoDownloadedAtTimeField() { return { this, "APrimalDinoCharacter.DinoDownloadedAtTime" }; }
	FieldValue<FString> UploadedFromServerNameField() { return { this, "APrimalDinoCharacter.UploadedFromServerName" }; }
	FieldValue<FString> LatestUploadedFromServerNameField() { return { this, "APrimalDinoCharacter.LatestUploadedFromServerName" }; }
	FieldValue<FString> PreviousUploadedFromServerNameField() { return { this, "APrimalDinoCharacter.PreviousUploadedFromServerName" }; }
	FieldValue<FString> TamedOnServerNameField() { return { this, "APrimalDinoCharacter.TamedOnServerName" }; }
	FieldValue<TArray<FDinoAncestorsEntry>> DinoAncestorsField() { return { this, "APrimalDinoCharacter.DinoAncestors" }; }
	FieldValue<TArray<FDinoAncestorsEntry>> DinoAncestorsMaleField() { return { this, "APrimalDinoCharacter.DinoAncestorsMale" }; }
	FieldValue<TArray<FDinoAncestorsEntry>> NextBabyDinoAncestorsField() { return { this, "APrimalDinoCharacter.NextBabyDinoAncestors" }; }
	FieldValue<TArray<FDinoAncestorsEntry>> NextBabyDinoAncestorsMaleField() { return { this, "APrimalDinoCharacter.NextBabyDinoAncestorsMale" }; }
	FieldValue<int> MaxAllowedRandomMutationsField() { return { this, "APrimalDinoCharacter.MaxAllowedRandomMutations" }; }
	FieldValue<int> RandomMutationRollsField() { return { this, "APrimalDinoCharacter.RandomMutationRolls" }; }
	FieldValue<float> RandomMutationChanceField() { return { this, "APrimalDinoCharacter.RandomMutationChance" }; }
	FieldValue<float> RandomMutationGivePointsField() { return { this, "APrimalDinoCharacter.RandomMutationGivePoints" }; }
	FieldValue<int> RandomMutationsMaleField() { return { this, "APrimalDinoCharacter.RandomMutationsMale" }; }
	FieldValue<int> RandomMutationsFemaleField() { return { this, "APrimalDinoCharacter.RandomMutationsFemale" }; }
	FieldValue<int> GestationEggRandomMutationsFemaleField() { return { this, "APrimalDinoCharacter.GestationEggRandomMutationsFemale" }; }
	FieldValue<int> GestationEggRandomMutationsMaleField() { return { this, "APrimalDinoCharacter.GestationEggRandomMutationsMale" }; }
	FieldValue<FName> WakingTameDistanceSocketNameField() { return { this, "APrimalDinoCharacter.WakingTameDistanceSocketName" }; }
	FieldValue<int> WakingTameConsumeEntireStackMaxQuantityField() { return { this, "APrimalDinoCharacter.WakingTameConsumeEntireStackMaxQuantity" }; }
	FieldValue<float> AttackPlayerDesirabilityMultiplierField() { return { this, "APrimalDinoCharacter.AttackPlayerDesirabilityMultiplier" }; }
	FieldValue<long double> LastAutoHealingItemUseField() { return { this, "APrimalDinoCharacter.LastAutoHealingItemUse" }; }
	FieldValue<long double> LastStartedCarryingCharacterTimeField() { return { this, "APrimalDinoCharacter.LastStartedCarryingCharacterTime" }; }
	FieldValue<float> FlyerAttachedExplosiveSpeedMultiplierField() { return { this, "APrimalDinoCharacter.FlyerAttachedExplosiveSpeedMultiplier" }; }
	FieldValue<TArray<FDinoExtraDefaultItemList>> DinoExtraDefaultInventoryItemsField() { return { this, "APrimalDinoCharacter.DinoExtraDefaultInventoryItems" }; }
	FieldValue<TArray<TSubclassOf<UPrimalItem>>> DeathGiveEngramClassesField() { return { this, "APrimalDinoCharacter.DeathGiveEngramClasses" }; }
	FieldValue<float> SinglePlayerOutgoingDamageModifierField() { return { this, "APrimalDinoCharacter.SinglePlayerOutgoingDamageModifier" }; }
	FieldValue<float> SinglePlayerIncomingDamageModifierField() { return { this, "APrimalDinoCharacter.SinglePlayerIncomingDamageModifier" }; }
	FieldValue<int> LastTickDelayFrameCountField() { return { this, "APrimalDinoCharacter.LastTickDelayFrameCount" }; }
	FieldValue<long double> NextTickDelayAllowTimeField() { return { this, "APrimalDinoCharacter.NextTickDelayAllowTime" }; }
	FieldValue<float> TickStatusTimeAccumulationField() { return { this, "APrimalDinoCharacter.TickStatusTimeAccumulation" }; }
	FieldValue<long double> LastServerTamedTickField() { return { this, "APrimalDinoCharacter.LastServerTamedTick" }; }
	FieldValue<int> LastTempDampenMovementInputAccelerationFrameField() { return { this, "APrimalDinoCharacter.LastTempDampenMovementInputAccelerationFrame" }; }
	FieldValue<UAnimMontage *> DinoLevelUpAnimationOverrideField() { return { this, "APrimalDinoCharacter.DinoLevelUpAnimationOverride" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> DamageVictimClassesIgnoreBlockingGeomtryTraceField() { return { this, "APrimalDinoCharacter.DamageVictimClassesIgnoreBlockingGeomtryTrace" }; }
	FieldValue<long double> LastVacuumSpaceCheckTimeField() { return { this, "APrimalDinoCharacter.LastVacuumSpaceCheckTime" }; }
	FieldValue<long double> LastGrappledTimeField() { return { this, "APrimalDinoCharacter.LastGrappledTime" }; }
	FieldValue<float> CloneBaseElementCostField() { return { this, "APrimalDinoCharacter.CloneBaseElementCost" }; }
	FieldValue<float> CloneElementCostPerLevelField() { return { this, "APrimalDinoCharacter.CloneElementCostPerLevel" }; }
	FieldValue<FName> NonDedicatedFreezeWildDinoPhysicsIfLevelUnloadedField() { return { this, "APrimalDinoCharacter.NonDedicatedFreezeWildDinoPhysicsIfLevelUnloaded" }; }
	FieldValue<TArray<FName>> NonDedicatedFreezeWildDinoPhysicsIfLevelsUnloadedField() { return { this, "APrimalDinoCharacter.NonDedicatedFreezeWildDinoPhysicsIfLevelsUnloaded" }; }
	FieldValue<FVector> UnboardLocationTraceOffsetField() { return { this, "APrimalDinoCharacter.UnboardLocationTraceOffset" }; }
	FieldValue<FName> AttackLineOfSightMeshSocketNameField() { return { this, "APrimalDinoCharacter.AttackLineOfSightMeshSocketName" }; }
	FieldValue<float> AttackForceWalkDistanceMultiplierField() { return { this, "APrimalDinoCharacter.AttackForceWalkDistanceMultiplier" }; }
	FieldValue<float> AttackForceWalkRotationRateMultiplierField() { return { this, "APrimalDinoCharacter.AttackForceWalkRotationRateMultiplier" }; }
	FieldValue<int> OverrideDinoTameSoundIndexField() { return { this, "APrimalDinoCharacter.OverrideDinoTameSoundIndex" }; }
	FieldValue<USoundBase *> SwimSoundField() { return { this, "APrimalDinoCharacter.SwimSound" }; }
	FieldValue<float> SwimSoundIntervalPerHundredSpeedField() { return { this, "APrimalDinoCharacter.SwimSoundIntervalPerHundredSpeed" }; }
	FieldValue<float> SwimSoundTimeCacheField() { return { this, "APrimalDinoCharacter.SwimSoundTimeCache" }; }
	FieldValue<TSubclassOf<AController>> TamedAIControllerOverrideField() { return { this, "APrimalDinoCharacter.TamedAIControllerOverride" }; }
	FieldValue<int> PersonalTamedDinoCostField() { return { this, "APrimalDinoCharacter.PersonalTamedDinoCost" }; }
	FieldValue<long double> UploadEarliestValidTimeField() { return { this, "APrimalDinoCharacter.UploadEarliestValidTime" }; }
	FieldValue<float> StasisAutoDestroyIntervalField() { return { this, "APrimalDinoCharacter.StasisAutoDestroyInterval" }; }
	FieldValue<float> CarryCameraYawOffsetField() { return { this, "APrimalDinoCharacter.CarryCameraYawOffset" }; }
	FieldValue<float> ExtraDamageMultiplierField() { return { this, "APrimalDinoCharacter.ExtraDamageMultiplier" }; }
	FieldValue<float> ExtraTamedBaseHealthMultiplierField() { return { this, "APrimalDinoCharacter.ExtraTamedBaseHealthMultiplier" }; }
	FieldValue<float> AttackRangeOffsetField() { return { this, "APrimalDinoCharacter.AttackRangeOffset" }; }
	FieldValue<char> CurrentPassengerSeatIndexField() { return { this, "APrimalDinoCharacter.CurrentPassengerSeatIndex" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bAttackStopsMovement() { return { this, "APrimalDinoCharacter.bAttackStopsMovement" }; }
	BitFieldValue<bool, unsigned __int32> bLocationBasedAttack() { return { this, "APrimalDinoCharacter.bLocationBasedAttack" }; }
	BitFieldValue<bool, unsigned __int32> bTamedWanderHarvestAllowUsableHarvestingAsWell() { return { this, "APrimalDinoCharacter.bTamedWanderHarvestAllowUsableHarvestingAsWell" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPKilledSomethingEvent() { return { this, "APrimalDinoCharacter.bUseBPKilledSomethingEvent" }; }
	BitFieldValue<bool, unsigned __int32> bPreventDinoResetAffinityOnUnsleep() { return { this, "APrimalDinoCharacter.bPreventDinoResetAffinityOnUnsleep" }; }
	BitFieldValue<bool, unsigned __int32> bKeepInventoryForWakingTame() { return { this, "APrimalDinoCharacter.bKeepInventoryForWakingTame" }; }
	BitFieldValue<bool, unsigned __int32> bForceReachedDestination() { return { this, "APrimalDinoCharacter.bForceReachedDestination" }; }
	BitFieldValue<bool, unsigned __int32> bHadLinkedSupplyCrate() { return { this, "APrimalDinoCharacter.bHadLinkedSupplyCrate" }; }
	BitFieldValue<bool, unsigned __int32> bRemovingStructuresOnDeath() { return { this, "APrimalDinoCharacter.bRemovingStructuresOnDeath" }; }
	BitFieldValue<bool, unsigned __int32> bResetUseAccelerationForRequestedMove() { return { this, "APrimalDinoCharacter.bResetUseAccelerationForRequestedMove" }; }
	BitFieldValue<bool, unsigned __int32> bHiddenForLocalPassenger() { return { this, "APrimalDinoCharacter.bHiddenForLocalPassenger" }; }
	BitFieldValue<bool, unsigned __int32> bRunCheckCarriedTrace() { return { this, "APrimalDinoCharacter.bRunCheckCarriedTrace" }; }
	BitFieldValue<bool, unsigned __int32> CanElevate() { return { this, "APrimalDinoCharacter.CanElevate" }; }
	BitFieldValue<bool, unsigned __int32> bIsElevating() { return { this, "APrimalDinoCharacter.bIsElevating" }; }
	BitFieldValue<bool, unsigned __int32> bIsBraking() { return { this, "APrimalDinoCharacter.bIsBraking" }; }
	BitFieldValue<bool, unsigned __int32> MovingForward() { return { this, "APrimalDinoCharacter.MovingForward" }; }
	BitFieldValue<bool, unsigned __int32> bTamedWanderCorpseHarvesting() { return { this, "APrimalDinoCharacter.bTamedWanderCorpseHarvesting" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyStructurePlacedNearby() { return { this, "APrimalDinoCharacter.bUseBPNotifyStructurePlacedNearby" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanTargetCorpse() { return { this, "APrimalDinoCharacter.bUseBPCanTargetCorpse" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPShouldForceFlee() { return { this, "APrimalDinoCharacter.bUseBPShouldForceFlee" }; }
	BitFieldValue<bool, unsigned __int32> bReceivedDinoAncestors() { return { this, "APrimalDinoCharacter.bReceivedDinoAncestors" }; }
	BitFieldValue<bool, unsigned __int32> bForceWanderOverrideNPCZoneManager() { return { this, "APrimalDinoCharacter.bForceWanderOverrideNPCZoneManager" }; }
	BitFieldValue<bool, unsigned __int32> bDeprecateDino() { return { this, "APrimalDinoCharacter.bDeprecateDino" }; }
	BitFieldValue<bool, unsigned __int32> bForceFoodItemAutoConsume() { return { this, "APrimalDinoCharacter.bForceFoodItemAutoConsume" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerAllowFlyingWithExplosive() { return { this, "APrimalDinoCharacter.bFlyerAllowFlyingWithExplosive" }; }
	BitFieldValue<bool, unsigned __int32> bForceUseDediAttackTiming() { return { this, "APrimalDinoCharacter.bForceUseDediAttackTiming" }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventExitingWater() { return { this, "APrimalDinoCharacter.bForcePreventExitingWater" }; }
	BitFieldValue<bool, unsigned __int32> bWakingTameConsumeEntireStack() { return { this, "APrimalDinoCharacter.bWakingTameConsumeEntireStack" }; }
	BitFieldValue<bool, unsigned __int32> bAllowCarryCharacterWithoutRider() { return { this, "APrimalDinoCharacter.bAllowCarryCharacterWithoutRider" }; }
	BitFieldValue<bool, unsigned __int32> bWildDinoPreventWeight() { return { this, "APrimalDinoCharacter.bWildDinoPreventWeight" }; }
	BitFieldValue<bool, unsigned __int32> bRetainCarriedCharacterOnDismount() { return { this, "APrimalDinoCharacter.bRetainCarriedCharacterOnDismount" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnTamedProcessOrder() { return { this, "APrimalDinoCharacter.bUseBPOnTamedProcessOrder" }; }
	BitFieldValue<bool, unsigned __int32> bIsLanding() { return { this, "APrimalDinoCharacter.bIsLanding" }; }
	BitFieldValue<bool, unsigned __int32> bCanCharge() { return { this, "APrimalDinoCharacter.bCanCharge" }; }
	BitFieldValue<bool, unsigned __int32> bCancelInterpolation() { return { this, "APrimalDinoCharacter.bCancelInterpolation" }; }
	BitFieldValue<bool, unsigned __int32> bIsCharging() { return { this, "APrimalDinoCharacter.bIsCharging" }; }
	BitFieldValue<bool, unsigned __int32> bChargeDamageStructures() { return { this, "APrimalDinoCharacter.bChargeDamageStructures" }; }
	BitFieldValue<bool, unsigned __int32> bReplicatePitchWhileSwimming() { return { this, "APrimalDinoCharacter.bReplicatePitchWhileSwimming" }; }
	BitFieldValue<bool, unsigned __int32> bIsFlying() { return { this, "APrimalDinoCharacter.bIsFlying" }; }
	BitFieldValue<bool, unsigned __int32> bIsWakingTame() { return { this, "APrimalDinoCharacter.bIsWakingTame" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRiding() { return { this, "APrimalDinoCharacter.bAllowRiding" }; }
	BitFieldValue<bool, unsigned __int32> bForceAutoTame() { return { this, "APrimalDinoCharacter.bForceAutoTame" }; }
	BitFieldValue<bool, unsigned __int32> bRiderJumpTogglesFlight() { return { this, "APrimalDinoCharacter.bRiderJumpTogglesFlight" }; }
	BitFieldValue<bool, unsigned __int32> bHasRider() { return { this, "APrimalDinoCharacter.bHasRider" }; }
	BitFieldValue<bool, unsigned __int32> bAllowCarryFlyerDinos() { return { this, "APrimalDinoCharacter.bAllowCarryFlyerDinos" }; }
	BitFieldValue<bool, unsigned __int32> bForcedLanding() { return { this, "APrimalDinoCharacter.bForcedLanding" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerForceNoPitch() { return { this, "APrimalDinoCharacter.bFlyerForceNoPitch" }; }
	BitFieldValue<bool, unsigned __int32> bPreventStasis() { return { this, "APrimalDinoCharacter.bPreventStasis" }; }
	BitFieldValue<bool, unsigned __int32> bAutoTameable() { return { this, "APrimalDinoCharacter.bAutoTameable" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysSetTamingTeamOnItemAdd() { return { this, "APrimalDinoCharacter.bAlwaysSetTamingTeamOnItemAdd" }; }
	BitFieldValue<bool, unsigned __int32> bDinoLoadedFromSaveGame() { return { this, "APrimalDinoCharacter.bDinoLoadedFromSaveGame" }; }
	BitFieldValue<bool, unsigned __int32> bCheatForceTameRide() { return { this, "APrimalDinoCharacter.bCheatForceTameRide" }; }
	BitFieldValue<bool, unsigned __int32> bIsFemale() { return { this, "APrimalDinoCharacter.bIsFemale" }; }
	BitFieldValue<bool, unsigned __int32> bRiderUseDirectionalAttackIndex() { return { this, "APrimalDinoCharacter.bRiderUseDirectionalAttackIndex" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeTamed() { return { this, "APrimalDinoCharacter.bCanBeTamed" }; }
	BitFieldValue<bool, unsigned __int32> bTargetingIgnoredByWildDinos() { return { this, "APrimalDinoCharacter.bTargetingIgnoredByWildDinos" }; }
	BitFieldValue<bool, unsigned __int32> bTargetingIgnoreWildDinos() { return { this, "APrimalDinoCharacter.bTargetingIgnoreWildDinos" }; }
	BitFieldValue<bool, unsigned __int32> bCanMountOnHumans() { return { this, "APrimalDinoCharacter.bCanMountOnHumans" }; }
	BitFieldValue<bool, unsigned __int32> bIKIgnoreSaddleStructures() { return { this, "APrimalDinoCharacter.bIKIgnoreSaddleStructures" }; }
	BitFieldValue<bool, unsigned __int32> bAttackTargetWhenLaunched() { return { this, "APrimalDinoCharacter.bAttackTargetWhenLaunched" }; }
	BitFieldValue<bool, unsigned __int32> bCanOpenLockedDoors() { return { this, "APrimalDinoCharacter.bCanOpenLockedDoors" }; }
	BitFieldValue<bool, unsigned __int32> bUseColorization() { return { this, "APrimalDinoCharacter.bUseColorization" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeSwingDamageBlockedByStrutures() { return { this, "APrimalDinoCharacter.bMeleeSwingDamageBlockedByStrutures" }; }
	BitFieldValue<bool, unsigned __int32> bAllowTargetingCorpses() { return { this, "APrimalDinoCharacter.bAllowTargetingCorpses" }; }
	BitFieldValue<bool, unsigned __int32> bRiderDontRequireSaddle() { return { this, "APrimalDinoCharacter.bRiderDontRequireSaddle" }; }
	BitFieldValue<bool, unsigned __int32> bAllowsFishingOnSaddle() { return { this, "APrimalDinoCharacter.bAllowsFishingOnSaddle" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeOrdered() { return { this, "APrimalDinoCharacter.bCanBeOrdered" }; }
	BitFieldValue<bool, unsigned __int32> bOverridePlatformStructureLimit() { return { this, "APrimalDinoCharacter.bOverridePlatformStructureLimit" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeAttackHarvetUsableComponents() { return { this, "APrimalDinoCharacter.bMeleeAttackHarvetUsableComponents" }; }
	BitFieldValue<bool, unsigned __int32> bPlatformSaddleIgnoreRotDotCheck() { return { this, "APrimalDinoCharacter.bPlatformSaddleIgnoreRotDotCheck" }; }
	BitFieldValue<bool, unsigned __int32> bUseInteprolatedVelocity() { return { this, "APrimalDinoCharacter.bUseInteprolatedVelocity" }; }
	BitFieldValue<bool, unsigned __int32> bIsCarnivore() { return { this, "APrimalDinoCharacter.bIsCarnivore" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRidingInWater() { return { this, "APrimalDinoCharacter.bAllowRidingInWater" }; }
	BitFieldValue<bool, unsigned __int32> bUsesGender() { return { this, "APrimalDinoCharacter.bUsesGender" }; }
	BitFieldValue<bool, unsigned __int32> bTargetEverything() { return { this, "APrimalDinoCharacter.bTargetEverything" }; }
	BitFieldValue<bool, unsigned __int32> bTamedWanderHarvestNonUsableHarvesting() { return { this, "APrimalDinoCharacter.bTamedWanderHarvestNonUsableHarvesting" }; }
	BitFieldValue<bool, unsigned __int32> bEnableTamedWandering() { return { this, "APrimalDinoCharacter.bEnableTamedWandering" }; }
	BitFieldValue<bool, unsigned __int32> bCollectVictimItems() { return { this, "APrimalDinoCharacter.bCollectVictimItems" }; }
	BitFieldValue<bool, unsigned __int32> bServerInitializedDino() { return { this, "APrimalDinoCharacter.bServerInitializedDino" }; }
	BitFieldValue<bool, unsigned __int32> bNPCSpawnerOverrideLevel() { return { this, "APrimalDinoCharacter.bNPCSpawnerOverrideLevel" }; }
	BitFieldValue<bool, unsigned __int32> bHasMateBoost() { return { this, "APrimalDinoCharacter.bHasMateBoost" }; }
	BitFieldValue<bool, unsigned __int32> NPCSpawnerAddLevelOffsetBeforeMultiplier() { return { this, "APrimalDinoCharacter.NPCSpawnerAddLevelOffsetBeforeMultiplier" }; }
	BitFieldValue<bool, unsigned __int32> bTamingHasFood() { return { this, "APrimalDinoCharacter.bTamingHasFood" }; }
	BitFieldValue<bool, unsigned __int32> bDontWander() { return { this, "APrimalDinoCharacter.bDontWander" }; }
	BitFieldValue<bool, unsigned __int32> bAnimIsMoving() { return { this, "APrimalDinoCharacter.bAnimIsMoving" }; }
	BitFieldValue<bool, unsigned __int32> bDoStepDamage() { return { this, "APrimalDinoCharacter.bDoStepDamage" }; }
	BitFieldValue<bool, unsigned __int32> bPreventBasingWhenUntamed() { return { this, "APrimalDinoCharacter.bPreventBasingWhenUntamed" }; }
	BitFieldValue<bool, unsigned __int32> bChargingRequiresWalking() { return { this, "APrimalDinoCharacter.bChargingRequiresWalking" }; }
	BitFieldValue<bool, unsigned __int32> bUseRootLocSwimOffset() { return { this, "APrimalDinoCharacter.bUseRootLocSwimOffset" }; }
	BitFieldValue<bool, unsigned __int32> bUseLowQualityAnimationTick() { return { this, "APrimalDinoCharacter.bUseLowQualityAnimationTick" }; }
	BitFieldValue<bool, unsigned __int32> bDisplaySummonedNotification() { return { this, "APrimalDinoCharacter.bDisplaySummonedNotification" }; }
	BitFieldValue<bool, unsigned __int32> bDisplayKilledNotification() { return { this, "APrimalDinoCharacter.bDisplayKilledNotification" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetAttackWeight() { return { this, "APrimalDinoCharacter.bUseBPGetAttackWeight" }; }
	BitFieldValue<bool, unsigned __int32> bServerForceUpdateDinoGameplayMeshNearPlayer() { return { this, "APrimalDinoCharacter.bServerForceUpdateDinoGameplayMeshNearPlayer" }; }
	BitFieldValue<bool, unsigned __int32> bPreventAllRiderWeapons() { return { this, "APrimalDinoCharacter.bPreventAllRiderWeapons" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDeathAutoGrab() { return { this, "APrimalDinoCharacter.bAllowDeathAutoGrab" }; }
	BitFieldValue<bool, unsigned __int32> bSupportWakingTame() { return { this, "APrimalDinoCharacter.bSupportWakingTame" }; }
	BitFieldValue<bool, unsigned __int32> bAllowAutoUnstasisDestroy() { return { this, "APrimalDinoCharacter.bAllowAutoUnstasisDestroy" }; }
	BitFieldValue<bool, unsigned __int32> bDebugBaby() { return { this, "APrimalDinoCharacter.bDebugBaby" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysUpdateAimOffsetInterpolation() { return { this, "APrimalDinoCharacter.bAlwaysUpdateAimOffsetInterpolation" }; }
	BitFieldValue<bool, unsigned __int32> WildAmbientHarvestingAnimationServerTickPose() { return { this, "APrimalDinoCharacter.WildAmbientHarvestingAnimationServerTickPose" }; }
	BitFieldValue<bool, unsigned __int32> bPreventSleepingTame() { return { this, "APrimalDinoCharacter.bPreventSleepingTame" }; }
	BitFieldValue<bool, unsigned __int32> bTamedWanderHarvest() { return { this, "APrimalDinoCharacter.bTamedWanderHarvest" }; }
	BitFieldValue<bool, unsigned __int32> bSimulatedNetLandCheckFloor() { return { this, "APrimalDinoCharacter.bSimulatedNetLandCheckFloor" }; }
	BitFieldValue<bool, unsigned __int32> bRefreshedColorization() { return { this, "APrimalDinoCharacter.bRefreshedColorization" }; }
	BitFieldValue<bool, unsigned __int32> bPoopIsEgg() { return { this, "APrimalDinoCharacter.bPoopIsEgg" }; }
	BitFieldValue<bool, unsigned __int32> bPoopIsDud() { return { this, "APrimalDinoCharacter.bPoopIsDud" }; }
	BitFieldValue<bool, unsigned __int32> bWasChargingBlocked() { return { this, "APrimalDinoCharacter.bWasChargingBlocked" }; }
	BitFieldValue<bool, unsigned __int32> bWasRidingFalling() { return { this, "APrimalDinoCharacter.bWasRidingFalling" }; }
	BitFieldValue<bool, unsigned __int32> bInitializedForReplicatedBasing() { return { this, "APrimalDinoCharacter.bInitializedForReplicatedBasing" }; }
	BitFieldValue<bool, unsigned __int32> bClientWasTamed() { return { this, "APrimalDinoCharacter.bClientWasTamed" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerPreventRiderAutoFly() { return { this, "APrimalDinoCharacter.bFlyerPreventRiderAutoFly" }; }
	BitFieldValue<bool, unsigned __int32> bAllowFlyerLandedRider() { return { this, "APrimalDinoCharacter.bAllowFlyerLandedRider" }; }
	BitFieldValue<bool, unsigned __int32> bPreventFlyerFlyingRider() { return { this, "APrimalDinoCharacter.bPreventFlyerFlyingRider" }; }
	BitFieldValue<bool, unsigned __int32> bPreventFlyerCapsuleExpansion() { return { this, "APrimalDinoCharacter.bPreventFlyerCapsuleExpansion" }; }
	BitFieldValue<bool, unsigned __int32> bIncludeCarryWeightOfBasedPawns() { return { this, "APrimalDinoCharacter.bIncludeCarryWeightOfBasedPawns" }; }
	BitFieldValue<bool, unsigned __int32> bForceRiderNetworkParent() { return { this, "APrimalDinoCharacter.bForceRiderNetworkParent" }; }
	BitFieldValue<bool, unsigned __int32> bForcePerfectTame() { return { this, "APrimalDinoCharacter.bForcePerfectTame" }; }
	BitFieldValue<bool, unsigned __int32> bCanHaveBaby() { return { this, "APrimalDinoCharacter.bCanHaveBaby" }; }
	BitFieldValue<bool, unsigned __int32> bUseBabyGestation() { return { this, "APrimalDinoCharacter.bUseBabyGestation" }; }
	BitFieldValue<bool, unsigned __int32> bPreventUnalignedDinoBasing() { return { this, "APrimalDinoCharacter.bPreventUnalignedDinoBasing" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideLevelMusicIfTamed() { return { this, "APrimalDinoCharacter.bOverrideLevelMusicIfTamed" }; }
	BitFieldValue<bool, unsigned __int32> bReachedMaxStructures() { return { this, "APrimalDinoCharacter.bReachedMaxStructures" }; }
	BitFieldValue<bool, unsigned __int32> bSupportsSaddleStructures() { return { this, "APrimalDinoCharacter.bSupportsSaddleStructures" }; }
	BitFieldValue<bool, unsigned __int32> bBonesHidden() { return { this, "APrimalDinoCharacter.bBonesHidden" }; }
	BitFieldValue<bool, unsigned __int32> bDelayedAttachement() { return { this, "APrimalDinoCharacter.bDelayedAttachement" }; }
	BitFieldValue<bool, unsigned __int32> bCanBeRepaired() { return { this, "APrimalDinoCharacter.bCanBeRepaired" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerDontAutoLandOnDismount() { return { this, "APrimalDinoCharacter.bFlyerDontAutoLandOnDismount" }; }
	BitFieldValue<bool, unsigned __int32> bIsRepairing() { return { this, "APrimalDinoCharacter.bIsRepairing" }; }
	BitFieldValue<bool, unsigned __int32> bIsBaby() { return { this, "APrimalDinoCharacter.bIsBaby" }; }
	BitFieldValue<bool, unsigned __int32> bWasBaby() { return { this, "APrimalDinoCharacter.bWasBaby" }; }
	BitFieldValue<bool, unsigned __int32> bCanUnclaimTame() { return { this, "APrimalDinoCharacter.bCanUnclaimTame" }; }
	BitFieldValue<bool, unsigned __int32> bAllowWildDinoEquipment() { return { this, "APrimalDinoCharacter.bAllowWildDinoEquipment" }; }
	BitFieldValue<bool, unsigned __int32> bUseTamedVisibleComponents() { return { this, "APrimalDinoCharacter.bUseTamedVisibleComponents" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDemolish() { return { this, "APrimalDinoCharacter.bAllowDemolish" }; }
	BitFieldValue<bool, unsigned __int32> bUseGang() { return { this, "APrimalDinoCharacter.bUseGang" }; }
	BitFieldValue<bool, unsigned __int32> bBlueprintDrawFloatingHUD() { return { this, "APrimalDinoCharacter.bBlueprintDrawFloatingHUD" }; }
	BitFieldValue<bool, unsigned __int32> bEggBoosted() { return { this, "APrimalDinoCharacter.bEggBoosted" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPTamedTick() { return { this, "APrimalDinoCharacter.bUseBPTamedTick" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideWantsToRun() { return { this, "APrimalDinoCharacter.bUseBPOverrideWantsToRun" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPlayDying() { return { this, "APrimalDinoCharacter.bUseBPPlayDying" }; }
	BitFieldValue<bool, unsigned __int32> bSupportsPassengerSeats() { return { this, "APrimalDinoCharacter.bSupportsPassengerSeats" }; }
	BitFieldValue<bool, unsigned __int32> bScaleInsulationByMeleeDamage() { return { this, "APrimalDinoCharacter.bScaleInsulationByMeleeDamage" }; }
	BitFieldValue<bool, unsigned __int32> bInventoryOnlyAllowCraftingWhenWandering() { return { this, "APrimalDinoCharacter.bInventoryOnlyAllowCraftingWhenWandering" }; }
	BitFieldValue<bool, unsigned __int32> bUseWildRandomScale() { return { this, "APrimalDinoCharacter.bUseWildRandomScale" }; }
	BitFieldValue<bool, unsigned __int32> bHeldJumpSlowFalling() { return { this, "APrimalDinoCharacter.bHeldJumpSlowFalling" }; }
	BitFieldValue<bool, unsigned __int32> bIsHeldJumpSlowFalling() { return { this, "APrimalDinoCharacter.bIsHeldJumpSlowFalling" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingSlowFallingAnim() { return { this, "APrimalDinoCharacter.bPlayingSlowFallingAnim" }; }
	BitFieldValue<bool, unsigned __int32> bTriggerBPUnstasis() { return { this, "APrimalDinoCharacter.bTriggerBPUnstasis" }; }
	BitFieldValue<bool, unsigned __int32> bWildProduceEggDynamically() { return { this, "APrimalDinoCharacter.bWildProduceEggDynamically" }; }
	BitFieldValue<bool, unsigned __int32> bPreventWakingTameFeeding() { return { this, "APrimalDinoCharacter.bPreventWakingTameFeeding" }; }
	BitFieldValue<bool, unsigned __int32> bForceDisablingTaming() { return { this, "APrimalDinoCharacter.bForceDisablingTaming" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerAllowRidingInCaves() { return { this, "APrimalDinoCharacter.bFlyerAllowRidingInCaves" }; }
	BitFieldValue<bool, unsigned __int32> bScaleExtraRunningSpeedModifier() { return { this, "APrimalDinoCharacter.bScaleExtraRunningSpeedModifier" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeSwingDamageBlockedByAllStationaryObjects() { return { this, "APrimalDinoCharacter.bMeleeSwingDamageBlockedByAllStationaryObjects" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPChargingModifyInputAcceleration() { return { this, "APrimalDinoCharacter.bUseBPChargingModifyInputAcceleration" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnRepIsCharging() { return { this, "APrimalDinoCharacter.bUseBPOnRepIsCharging" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventOrderAllowed() { return { this, "APrimalDinoCharacter.bUseBPPreventOrderAllowed" }; }
	BitFieldValue<bool, unsigned __int32> bPassengerDinosUsePassengerAnim() { return { this, "APrimalDinoCharacter.bPassengerDinosUsePassengerAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUsesPassengerAnimOnDinos() { return { this, "APrimalDinoCharacter.bUsesPassengerAnimOnDinos" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyDoStepDamageWhenRunning() { return { this, "APrimalDinoCharacter.bOnlyDoStepDamageWhenRunning" }; }
	BitFieldValue<bool, unsigned __int32> bShouldNotifyClientWhenLanded() { return { this, "APrimalDinoCharacter.bShouldNotifyClientWhenLanded" }; }
	BitFieldValue<bool, unsigned __int32> bPreventPlatformSaddleMultiFloors() { return { this, "APrimalDinoCharacter.bPreventPlatformSaddleMultiFloors" }; }
	BitFieldValue<bool, unsigned __int32> bPreventMountedDinoMeshHiding() { return { this, "APrimalDinoCharacter.bPreventMountedDinoMeshHiding" }; }
	BitFieldValue<bool, unsigned __int32> bUsePlayerMountedCarryingDinoAnimation() { return { this, "APrimalDinoCharacter.bUsePlayerMountedCarryingDinoAnimation" }; }
	BitFieldValue<bool, unsigned __int32> bPreventRotationRateModifier() { return { this, "APrimalDinoCharacter.bPreventRotationRateModifier" }; }
	BitFieldValue<bool, unsigned __int32> bStepDamageFoliageOnly() { return { this, "APrimalDinoCharacter.bStepDamageFoliageOnly" }; }
	BitFieldValue<bool, unsigned __int32> bPreventUntamedRun() { return { this, "APrimalDinoCharacter.bPreventUntamedRun" }; }
	BitFieldValue<bool, unsigned __int32> bAllowTogglingPublicSeating() { return { this, "APrimalDinoCharacter.bAllowTogglingPublicSeating" }; }
	BitFieldValue<bool, unsigned __int32> bAllowPublicSeating() { return { this, "APrimalDinoCharacter.bAllowPublicSeating" }; }
	BitFieldValue<bool, unsigned __int32> bAllowWaterSurfaceExtraJump() { return { this, "APrimalDinoCharacter.bAllowWaterSurfaceExtraJump" }; }
	BitFieldValue<bool, unsigned __int32> bUseVelocityForRequestedMoveIfStuck() { return { this, "APrimalDinoCharacter.bUseVelocityForRequestedMoveIfStuck" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDoAttack() { return { this, "APrimalDinoCharacter.bUseBPDoAttack" }; }
	BitFieldValue<bool, unsigned __int32> bStepDamageNonFoliageWithoutRunning() { return { this, "APrimalDinoCharacter.bStepDamageNonFoliageWithoutRunning" }; }
	BitFieldValue<bool, unsigned __int32> bStepDamageAllTargetables() { return { this, "APrimalDinoCharacter.bStepDamageAllTargetables" }; }
	BitFieldValue<bool, unsigned __int32> bDamageNonFoliageFeetSocketsOnly() { return { this, "APrimalDinoCharacter.bDamageNonFoliageFeetSocketsOnly" }; }
	BitFieldValue<bool, unsigned __int32> bRiderDontBeBlockedByPawnMesh() { return { this, "APrimalDinoCharacter.bRiderDontBeBlockedByPawnMesh" }; }
	BitFieldValue<bool, unsigned __int32> bUseExtendedUnstasisCheck() { return { this, "APrimalDinoCharacter.bUseExtendedUnstasisCheck" }; }
	BitFieldValue<bool, unsigned __int32> bTickedStasis() { return { this, "APrimalDinoCharacter.bTickedStasis" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDinoAutoConsumeInventoryFood() { return { this, "APrimalDinoCharacter.bAllowDinoAutoConsumeInventoryFood" }; }
	BitFieldValue<bool, unsigned __int32> bForceNoCharacterStatusComponentTick() { return { this, "APrimalDinoCharacter.bForceNoCharacterStatusComponentTick" }; }
	BitFieldValue<bool, unsigned __int32> bIsRaidDino() { return { this, "APrimalDinoCharacter.bIsRaidDino" }; }
	BitFieldValue<bool, unsigned __int32> bWildIgnoredByAutoTurrets() { return { this, "APrimalDinoCharacter.bWildIgnoredByAutoTurrets" }; }
	BitFieldValue<bool, unsigned __int32> bWildAllowTargetingNeutralStructures() { return { this, "APrimalDinoCharacter.bWildAllowTargetingNeutralStructures" }; }
	BitFieldValue<bool, unsigned __int32> bDoStepDamageTamedOnly() { return { this, "APrimalDinoCharacter.bDoStepDamageTamedOnly" }; }
	BitFieldValue<bool, unsigned __int32> bStepDamageNonFoliageTamedOnly() { return { this, "APrimalDinoCharacter.bStepDamageNonFoliageTamedOnly" }; }
	BitFieldValue<bool, unsigned __int32> bDroppedInventoryDeposit() { return { this, "APrimalDinoCharacter.bDroppedInventoryDeposit" }; }
	BitFieldValue<bool, unsigned __int32> bForceWildDeathInventoryDeposit() { return { this, "APrimalDinoCharacter.bForceWildDeathInventoryDeposit" }; }
	BitFieldValue<bool, unsigned __int32> bIsCarryingCharacter() { return { this, "APrimalDinoCharacter.bIsCarryingCharacter" }; }
	BitFieldValue<bool, unsigned __int32> bIsCarryingPassenger() { return { this, "APrimalDinoCharacter.bIsCarryingPassenger" }; }
	BitFieldValue<bool, unsigned __int32> bIsManualFoodEat() { return { this, "APrimalDinoCharacter.bIsManualFoodEat" }; }
	BitFieldValue<bool, unsigned __int32> bDontPlayAttackingMusic() { return { this, "APrimalDinoCharacter.bDontPlayAttackingMusic" }; }
	BitFieldValue<bool, unsigned __int32> bForceIgnoreRagdollHarvesting() { return { this, "APrimalDinoCharacter.bForceIgnoreRagdollHarvesting" }; }
	BitFieldValue<bool, unsigned __int32> bBPModifyAimOffsetTargetLocation() { return { this, "APrimalDinoCharacter.bBPModifyAimOffsetTargetLocation" }; }
	BitFieldValue<bool, unsigned __int32> bIsVehicle() { return { this, "APrimalDinoCharacter.bIsVehicle" }; }
	BitFieldValue<bool, unsigned __int32> bDisallowPostNetReplication() { return { this, "APrimalDinoCharacter.bDisallowPostNetReplication" }; }
	BitFieldValue<bool, unsigned __int32> bTakingOff() { return { this, "APrimalDinoCharacter.bTakingOff" }; }
	BitFieldValue<bool, unsigned __int32> bPreventMating() { return { this, "APrimalDinoCharacter.bPreventMating" }; }
	BitFieldValue<bool, unsigned __int32> bAttackStopsRotation() { return { this, "APrimalDinoCharacter.bAttackStopsRotation" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerDinoAllowBackwardsFlight() { return { this, "APrimalDinoCharacter.bFlyerDinoAllowBackwardsFlight" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerDinoAllowStrafing() { return { this, "APrimalDinoCharacter.bFlyerDinoAllowStrafing" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreTargetingLiveUnriddenDinos() { return { this, "APrimalDinoCharacter.bIgnoreTargetingLiveUnriddenDinos" }; }
	BitFieldValue<bool, unsigned __int32> bSleepedForceCreateInventory() { return { this, "APrimalDinoCharacter.bSleepedForceCreateInventory" }; }
	BitFieldValue<bool, unsigned __int32> bLocalForceNearbySkelMeshUpdate() { return { this, "APrimalDinoCharacter.bLocalForceNearbySkelMeshUpdate" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerDisableEnemyTargetingMaxDeltaZ() { return { this, "APrimalDinoCharacter.bFlyerDisableEnemyTargetingMaxDeltaZ" }; }
	BitFieldValue<bool, unsigned __int32> bIsBossDino() { return { this, "APrimalDinoCharacter.bIsBossDino" }; }
	BitFieldValue<bool, unsigned __int32> bTamedAIAllowSpecialAttacks() { return { this, "APrimalDinoCharacter.bTamedAIAllowSpecialAttacks" }; }
	BitFieldValue<bool, unsigned __int32> bTamedAIToggleSpecialAttacks() { return { this, "APrimalDinoCharacter.bTamedAIToggleSpecialAttacks" }; }
	BitFieldValue<bool, unsigned __int32> bLocalPrimaryAttackPressed() { return { this, "APrimalDinoCharacter.bLocalPrimaryAttackPressed" }; }
	BitFieldValue<bool, unsigned __int32> bRepeatPrimaryAttack() { return { this, "APrimalDinoCharacter.bRepeatPrimaryAttack" }; }
	BitFieldValue<bool, unsigned __int32> bPreventUploading() { return { this, "APrimalDinoCharacter.bPreventUploading" }; }
	BitFieldValue<bool, unsigned __int32> bPreventHibernation() { return { this, "APrimalDinoCharacter.bPreventHibernation" }; }
	BitFieldValue<bool, unsigned __int32> bRiderMovementLocked() { return { this, "APrimalDinoCharacter.bRiderMovementLocked" }; }
	BitFieldValue<bool, unsigned __int32> bTameTimerSet() { return { this, "APrimalDinoCharacter.bTameTimerSet" }; }
	BitFieldValue<bool, unsigned __int32> bNeutered() { return { this, "APrimalDinoCharacter.bNeutered" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreAllWhistles() { return { this, "APrimalDinoCharacter.bIgnoreAllWhistles" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDoHarvestAttack() { return { this, "APrimalDinoCharacter.bUseBPDoHarvestAttack" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyHarvestingQuantity() { return { this, "APrimalDinoCharacter.bUseBPModifyHarvestingQuantity" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyHarvestingWeightsArray() { return { this, "APrimalDinoCharacter.bUseBPModifyHarvestingWeightsArray" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyHarvestDamage() { return { this, "APrimalDinoCharacter.bUseBPModifyHarvestDamage" }; }
	BitFieldValue<bool, unsigned __int32> bHideFloatingHUD() { return { this, "APrimalDinoCharacter.bHideFloatingHUD" }; }
	BitFieldValue<bool, unsigned __int32> bDisableHarvesting() { return { this, "APrimalDinoCharacter.bDisableHarvesting" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDinoPostBeginPlay() { return { this, "APrimalDinoCharacter.bUseBPDinoPostBeginPlay" }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowTickingThisFrame() { return { this, "APrimalDinoCharacter.bForceAllowTickingThisFrame" }; }
	BitFieldValue<bool, unsigned __int32> bDrawHealthBar() { return { this, "APrimalDinoCharacter.bDrawHealthBar" }; }
	BitFieldValue<bool, unsigned __int32> bUseShoulderMountedLaunch() { return { this, "APrimalDinoCharacter.bUseShoulderMountedLaunch" }; }
	BitFieldValue<bool, unsigned __int32> bDidSetupTamed() { return { this, "APrimalDinoCharacter.bDidSetupTamed" }; }
	BitFieldValue<bool, unsigned __int32> bIncrementedNumDinos() { return { this, "APrimalDinoCharacter.bIncrementedNumDinos" }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowPvECarry() { return { this, "APrimalDinoCharacter.bForceAllowPvECarry" }; }
	BitFieldValue<bool, unsigned __int32> bUnderwaterMating() { return { this, "APrimalDinoCharacter.bUnderwaterMating" }; }
	BitFieldValue<bool, unsigned __int32> bBabyPreventExitingWater() { return { this, "APrimalDinoCharacter.bBabyPreventExitingWater" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerDontGainImpulseOnSubmerged() { return { this, "APrimalDinoCharacter.bFlyerDontGainImpulseOnSubmerged" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanAutodrag() { return { this, "APrimalDinoCharacter.bUseBPCanAutodrag" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanDragCharacter() { return { this, "APrimalDinoCharacter.bUseBPCanDragCharacter" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDraggingWhileFalling() { return { this, "APrimalDinoCharacter.bAllowDraggingWhileFalling" }; }
	BitFieldValue<bool, unsigned __int32> bSingleplayerFreezePhysicsWhenNoTarget() { return { this, "APrimalDinoCharacter.bSingleplayerFreezePhysicsWhenNoTarget" }; }
	BitFieldValue<bool, unsigned __int32> bIsSingleplayer() { return { this, "APrimalDinoCharacter.bIsSingleplayer" }; }
	BitFieldValue<bool, unsigned __int32> bIsCloneDino() { return { this, "APrimalDinoCharacter.bIsCloneDino" }; }
	BitFieldValue<bool, unsigned __int32> bUseAdvancedAnimLerp() { return { this, "APrimalDinoCharacter.bUseAdvancedAnimLerp" }; }
	BitFieldValue<bool, unsigned __int32> bPreventWanderingUnderWater() { return { this, "APrimalDinoCharacter.bPreventWanderingUnderWater" }; }
	BitFieldValue<bool, unsigned __int32> bWildAllowFollowTamedTarget() { return { this, "APrimalDinoCharacter.bWildAllowFollowTamedTarget" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDamageSameTeamAndClass() { return { this, "APrimalDinoCharacter.bAllowDamageSameTeamAndClass" }; }
	BitFieldValue<bool, unsigned __int32> bAllowsTurretMode() { return { this, "APrimalDinoCharacter.bAllowsTurretMode" }; }
	BitFieldValue<bool, unsigned __int32> bIsInTurretMode() { return { this, "APrimalDinoCharacter.bIsInTurretMode" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPShouldCancelDoAttack() { return { this, "APrimalDinoCharacter.bUseBPShouldCancelDoAttack" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyDesiredRotation() { return { this, "APrimalDinoCharacter.bUseBPModifyDesiredRotation" }; }
	BitFieldValue<bool, unsigned __int32> bUseLocalSpaceDesiredRotationWithRider() { return { this, "APrimalDinoCharacter.bUseLocalSpaceDesiredRotationWithRider" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPDesiredRotationIsLocalSpace() { return { this, "APrimalDinoCharacter.bUseBPDesiredRotationIsLocalSpace" }; }
	BitFieldValue<bool, unsigned __int32> bForcedLandingClearRider() { return { this, "APrimalDinoCharacter.bForcedLandingClearRider" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_CustomModifier_RotationRate() { return { this, "APrimalDinoCharacter.bUseBP_CustomModifier_RotationRate" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_CustomModifier_MaxSpeed() { return { this, "APrimalDinoCharacter.bUseBP_CustomModifier_MaxSpeed" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_OnStartLandingNotify() { return { this, "APrimalDinoCharacter.bUseBP_OnStartLandingNotify" }; }
	BitFieldValue<bool, unsigned __int32> bIsClearingRider() { return { this, "APrimalDinoCharacter.bIsClearingRider" }; }
	BitFieldValue<bool, unsigned __int32> bUseAttackForceWalkDistanceMultiplier() { return { this, "APrimalDinoCharacter.bUseAttackForceWalkDistanceMultiplier" }; }
	BitFieldValue<bool, unsigned __int32> bForcePerFrameTicking() { return { this, "APrimalDinoCharacter.bForcePerFrameTicking" }; }
	BitFieldValue<bool, unsigned __int32> bHadStaticBase() { return { this, "APrimalDinoCharacter.bHadStaticBase" }; }
	BitFieldValue<bool, unsigned __int32> bNoKillXP() { return { this, "APrimalDinoCharacter.bNoKillXP" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreAllyLook() { return { this, "APrimalDinoCharacter.bIgnoreAllyLook" }; }
	BitFieldValue<bool, unsigned __int32> bBabyInitiallyUnclaimed() { return { this, "APrimalDinoCharacter.bBabyInitiallyUnclaimed" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPForceTurretFastTargeting() { return { this, "APrimalDinoCharacter.bUseBPForceTurretFastTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bLastAnyLegOnGround() { return { this, "APrimalDinoCharacter.bLastAnyLegOnGround" }; }
	BitFieldValue<bool, unsigned __int32> bSuppressWakingTameMessage() { return { this, "APrimalDinoCharacter.bSuppressWakingTameMessage" }; }
	BitFieldValue<bool, unsigned __int32> bPreventFlyerLanding() { return { this, "APrimalDinoCharacter.bPreventFlyerLanding" }; }
	BitFieldValue<bool, unsigned __int32> bHasDied() { return { this, "APrimalDinoCharacter.bHasDied" }; }
	BitFieldValue<bool, unsigned __int32> bHasPlayDying() { return { this, "APrimalDinoCharacter.bHasPlayDying" }; }
	BitFieldValue<bool, unsigned __int32> bDisableCollisionWithDinosWhenFlying() { return { this, "APrimalDinoCharacter.bDisableCollisionWithDinosWhenFlying" }; }
	BitFieldValue<bool, unsigned __int32> bAllowTrapping() { return { this, "APrimalDinoCharacter.bAllowTrapping" }; }
	BitFieldValue<bool, unsigned __int32> bPreventWildTrapping() { return { this, "APrimalDinoCharacter.bPreventWildTrapping" }; }
	BitFieldValue<bool, unsigned __int32> bIsTrapTamed() { return { this, "APrimalDinoCharacter.bIsTrapTamed" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreDestroyOnRapidDeath() { return { this, "APrimalDinoCharacter.bIgnoreDestroyOnRapidDeath" }; }
	BitFieldValue<bool, unsigned __int32> bPreventFallingBumpCheck() { return { this, "APrimalDinoCharacter.bPreventFallingBumpCheck" }; }
	BitFieldValue<bool, unsigned __int32> bIsDestroyingDino() { return { this, "APrimalDinoCharacter.bIsDestroyingDino" }; }
	BitFieldValue<bool, unsigned __int32> bCheckBPAllowClaiming() { return { this, "APrimalDinoCharacter.bCheckBPAllowClaiming" }; }
	BitFieldValue<bool, unsigned __int32> bUseBlueprintExtraBabyScale() { return { this, "APrimalDinoCharacter.bUseBlueprintExtraBabyScale" }; }
	BitFieldValue<bool, unsigned __int32> bPreventNeuter() { return { this, "APrimalDinoCharacter.bPreventNeuter" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetDragSocketDinoName() { return { this, "APrimalDinoCharacter.bUseBPGetDragSocketDinoName" }; }
	BitFieldValue<bool, unsigned __int32> bTargetEverythingIncludingSameTeamInPVE() { return { this, "APrimalDinoCharacter.bTargetEverythingIncludingSameTeamInPVE" }; }
	BitFieldValue<bool, unsigned __int32> bForceUsePhysicalFootSurfaceTrace() { return { this, "APrimalDinoCharacter.bForceUsePhysicalFootSurfaceTrace" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_OnPostNetReplication() { return { this, "APrimalDinoCharacter.bUseBP_OnPostNetReplication" }; }
	BitFieldValue<bool, unsigned __int32> bPassiveFlee() { return { this, "APrimalDinoCharacter.bPassiveFlee" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyTargetConscious() { return { this, "APrimalDinoCharacter.bOnlyTargetConscious" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnMountStateChanged() { return { this, "APrimalDinoCharacter.bUseBPOnMountStateChanged" }; }
	BitFieldValue<bool, unsigned __int32> bHandleUseButtonPressBP() { return { this, "APrimalDinoCharacter.bHandleUseButtonPressBP" }; }
	BitFieldValue<bool, unsigned __int32> bGlideWhenFalling() { return { this, "APrimalDinoCharacter.bGlideWhenFalling" }; }
	BitFieldValue<bool, unsigned __int32> bGlideWhenMounted() { return { this, "APrimalDinoCharacter.bGlideWhenMounted" }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowBackwardsMovement() { return { this, "APrimalDinoCharacter.bForceAllowBackwardsMovement" }; }
	BitFieldValue<bool, unsigned __int32> bPreventBackwardsWalking() { return { this, "APrimalDinoCharacter.bPreventBackwardsWalking" }; }
	BitFieldValue<bool, unsigned __int32> bSupplyPlayerMountedCarryAnimation() { return { this, "APrimalDinoCharacter.bSupplyPlayerMountedCarryAnimation" }; }
	BitFieldValue<bool, unsigned __int32> bForceAllowMountedCarryRunning() { return { this, "APrimalDinoCharacter.bForceAllowMountedCarryRunning" }; }
	BitFieldValue<bool, unsigned __int32> bCanLatch() { return { this, "APrimalDinoCharacter.bCanLatch" }; }
	BitFieldValue<bool, unsigned __int32> bIsLatched() { return { this, "APrimalDinoCharacter.bIsLatched" }; }
	BitFieldValue<bool, unsigned __int32> bIsLatchedDownward() { return { this, "APrimalDinoCharacter.bIsLatchedDownward" }; }
	BitFieldValue<bool, unsigned __int32> bIsLatching() { return { this, "APrimalDinoCharacter.bIsLatching" }; }
	BitFieldValue<bool, unsigned __int32> bRotateToFaceLatchingObject() { return { this, "APrimalDinoCharacter.bRotateToFaceLatchingObject" }; }
	BitFieldValue<bool, unsigned __int32> bLimitRiderYawOnLatched() { return { this, "APrimalDinoCharacter.bLimitRiderYawOnLatched" }; }
	BitFieldValue<bool, unsigned __int32> bAllowMountedWeaponry() { return { this, "APrimalDinoCharacter.bAllowMountedWeaponry" }; }
	BitFieldValue<bool, unsigned __int32> bKeepAffinityOnDamageRecievedWakingTame() { return { this, "APrimalDinoCharacter.bKeepAffinityOnDamageRecievedWakingTame" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPFedWakingTameEvent() { return { this, "APrimalDinoCharacter.bUseBPFedWakingTameEvent" }; }
	BitFieldValue<bool, unsigned __int32> bForceRiderDrawCrosshair() { return { this, "APrimalDinoCharacter.bForceRiderDrawCrosshair" }; }
	BitFieldValue<bool, unsigned __int32> bForceDrawHUD() { return { this, "APrimalDinoCharacter.bForceDrawHUD" }; }
	BitFieldValue<bool, unsigned __int32> bForceDrawHUDWithoutRecentlyRendered() { return { this, "APrimalDinoCharacter.bForceDrawHUDWithoutRecentlyRendered" }; }
	BitFieldValue<bool, unsigned __int32> bHideFloatingName() { return { this, "APrimalDinoCharacter.bHideFloatingName" }; }
	BitFieldValue<bool, unsigned __int32> bCanTargetVehicles() { return { this, "APrimalDinoCharacter.bCanTargetVehicles" }; }
	BitFieldValue<bool, unsigned __int32> bRidingRequiresTamed() { return { this, "APrimalDinoCharacter.bRidingRequiresTamed" }; }
	BitFieldValue<bool, unsigned __int32> bSuppressDeathNotification() { return { this, "APrimalDinoCharacter.bSuppressDeathNotification" }; }
	BitFieldValue<bool, unsigned __int32> bUseCustomHealthBarColor() { return { this, "APrimalDinoCharacter.bUseCustomHealthBarColor" }; }
	BitFieldValue<bool, unsigned __int32> bUseOnUpdateMountedDinoMeshHiding() { return { this, "APrimalDinoCharacter.bUseOnUpdateMountedDinoMeshHiding" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPInterceptMoveInputEvents() { return { this, "APrimalDinoCharacter.bUseBPInterceptMoveInputEvents" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPAdjustAttackIndex() { return { this, "APrimalDinoCharacter.bUseBPAdjustAttackIndex" }; }
	BitFieldValue<bool, unsigned __int32> bCheckBPAllowCarryCharacter() { return { this, "APrimalDinoCharacter.bCheckBPAllowCarryCharacter" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnEndCharging() { return { this, "APrimalDinoCharacter.bUseBPOnEndCharging" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPNotifyMateBoostChanged() { return { this, "APrimalDinoCharacter.bUseBPNotifyMateBoostChanged" }; }

	// Functions

	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "APrimalDinoCharacter.GetPrivateStaticClass"); }
	void CheckAndHandleBasedPlayersBeingPushedThroughWalls() { NativeCall<void>(this, "APrimalDinoCharacter.CheckAndHandleBasedPlayersBeingPushedThroughWalls"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalDinoCharacter.Tick", DeltaSeconds); }
	void PlayHardEndChargingShake_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.PlayHardEndChargingShake_Implementation"); }
	void SetForcedAggro(ITargetableInterface * Targetable, float AggroAmount, float ForcedAggroTime) { NativeCall<void, ITargetableInterface *, float, float>(this, "APrimalDinoCharacter.SetForcedAggro", Targetable, AggroAmount, ForcedAggroTime); }
	float GetAttackRangeOffset() { return NativeCall<float>(this, "APrimalDinoCharacter.GetAttackRangeOffset"); }
	void PlayDying(float KillingDamage, FDamageEvent * DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "APrimalDinoCharacter.PlayDying", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void AutoDrag() { NativeCall<void>(this, "APrimalDinoCharacter.AutoDrag"); }
	bool CanRide(AShooterCharacter * byPawn, char * bOutHasSaddle, char * bOutCanRideOtherThanSaddle, bool bDontCheckDistance) { return NativeCall<bool, AShooterCharacter *, char *, char *, bool>(this, "APrimalDinoCharacter.CanRide", byPawn, bOutHasSaddle, bOutCanRideOtherThanSaddle, bDontCheckDistance); }
	void Stasis() { NativeCall<void>(this, "APrimalDinoCharacter.Stasis"); }
	void Unstasis() { NativeCall<void>(this, "APrimalDinoCharacter.Unstasis"); }
	void HandleUnstasised(bool bWasFromHibernation) { NativeCall<void, bool>(this, "APrimalDinoCharacter.HandleUnstasised", bWasFromHibernation); }
	void PostInitializeComponents() { NativeCall<void>(this, "APrimalDinoCharacter.PostInitializeComponents"); }
	void RegisterAllComponents() { NativeCall<void>(this, "APrimalDinoCharacter.RegisterAllComponents"); }
	int GetRandomBaseLevel() { return NativeCall<int>(this, "APrimalDinoCharacter.GetRandomBaseLevel"); }
	bool AllowZoneAutoKill() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowZoneAutoKill"); }
	void StopActiveState(bool bShouldResetAttackIndex) { NativeCall<void, bool>(this, "APrimalDinoCharacter.StopActiveState", bShouldResetAttackIndex); }
	bool DoAttack(int AttackIndex, bool bSetCurrentAttack) { return NativeCall<bool, int, bool>(this, "APrimalDinoCharacter.DoAttack", AttackIndex, bSetCurrentAttack); }
	void ApplyRidingAttackExtraVelocity() { NativeCall<void>(this, "APrimalDinoCharacter.ApplyRidingAttackExtraVelocity"); }
	bool HasReachedDestination(FVector * Goal) { return NativeCall<bool, FVector *>(this, "APrimalDinoCharacter.HasReachedDestination", Goal); }
	bool IsDamageOccludedByStructures(AActor * DamageCauser) { return NativeCall<bool, AActor *>(this, "APrimalDinoCharacter.IsDamageOccludedByStructures", DamageCauser); }
	float TakeDamage(float Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { return NativeCall<float, float, FDamageEvent *, AController *, AActor *>(this, "APrimalDinoCharacter.TakeDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool CanAttack(int AttackIndex) { return NativeCall<bool, int>(this, "APrimalDinoCharacter.CanAttack", AttackIndex); }
	bool IsAttacking() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsAttacking"); }
	void PlayAttackAnimationOfAnimationArray(int AnimationIndex, TArray<UAnimMontage *> attackAnimations) { NativeCall<void, int, TArray<UAnimMontage *>>(this, "APrimalDinoCharacter.PlayAttackAnimationOfAnimationArray", AnimationIndex, attackAnimations); }
	void PlayWeightedAttackAnimation() { NativeCall<void>(this, "APrimalDinoCharacter.PlayWeightedAttackAnimation"); }
	bool IsCurrentlyPlayingAttackAnimation() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsCurrentlyPlayingAttackAnimation"); }
	bool AddToMeleeSwingHurtList(AActor * AnActor) { return NativeCall<bool, AActor *>(this, "APrimalDinoCharacter.AddToMeleeSwingHurtList", AnActor); }
	bool ShouldDealDamage(AActor * TestActor) { return NativeCall<bool, AActor *>(this, "APrimalDinoCharacter.ShouldDealDamage", TestActor); }
	void DealDamage(FHitResult * Impact, FVector * ShootDir, int DamageAmount, TSubclassOf<UDamageType> DamageType, float Impulse) { NativeCall<void, FHitResult *, FVector *, int, TSubclassOf<UDamageType>, float>(this, "APrimalDinoCharacter.DealDamage", Impact, ShootDir, DamageAmount, DamageType, Impulse); }
	bool CanCarryCharacter(APrimalCharacter * CanCarryPawn) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.CanCarryCharacter", CanCarryPawn); }
	bool AllowCarryCharacter(APrimalCharacter * CanCarryPawn) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.AllowCarryCharacter", CanCarryPawn); }
	bool CarryCharacter(APrimalCharacter * character, bool byPassCanCarryCheck) { return NativeCall<bool, APrimalCharacter *, bool>(this, "APrimalDinoCharacter.CarryCharacter", character, byPassCanCarryCheck); }
	void ClearCarriedCharacter(bool fromCarriedCharacter, bool bCancelAnyCarryBuffs) { NativeCall<void, bool, bool>(this, "APrimalDinoCharacter.ClearCarriedCharacter", fromCarriedCharacter, bCancelAnyCarryBuffs); }
	void ClearPassengers() { NativeCall<void>(this, "APrimalDinoCharacter.ClearPassengers"); }
	bool AddPassenger(APrimalCharacter * Character, int PassengerSeatIndex, bool bForcePassenger, bool bAllowFlyersAndWaterDinos) { return NativeCall<bool, APrimalCharacter *, int, bool, bool>(this, "APrimalDinoCharacter.AddPassenger", Character, PassengerSeatIndex, bForcePassenger, bAllowFlyersAndWaterDinos); }
	void RemovePassenger(APrimalCharacter * Character, bool bFromCharacter, bool bFromPlayerController) { NativeCall<void, APrimalCharacter *, bool, bool>(this, "APrimalDinoCharacter.RemovePassenger", Character, bFromCharacter, bFromPlayerController); }
	bool CheckLocalPassengers() { return NativeCall<bool>(this, "APrimalDinoCharacter.CheckLocalPassengers"); }
	bool IsPassengerSeatAvailable(int PassengerSeatIndex) { return NativeCall<bool, int>(this, "APrimalDinoCharacter.IsPassengerSeatAvailable", PassengerSeatIndex); }
	bool CanTakePassenger(APrimalCharacter * Character, int PassengerSeatIndex, bool bForcePassenger, bool bAllowFlyersAndWaterDinos) { return NativeCall<bool, APrimalCharacter *, int, bool, bool>(this, "APrimalDinoCharacter.CanTakePassenger", Character, PassengerSeatIndex, bForcePassenger, bAllowFlyersAndWaterDinos); }
	int GetNumPassengerSeats(bool bOnlyManualPassengerSeats) { return NativeCall<int, bool>(this, "APrimalDinoCharacter.GetNumPassengerSeats", bOnlyManualPassengerSeats); }
	FSaddlePassengerSeatDefinition * GetPassengerSeatDefinition(char SeatIndex) { return NativeCall<FSaddlePassengerSeatDefinition *, char>(this, "APrimalDinoCharacter.GetPassengerSeatDefinition", SeatIndex); }
	void OnRep_PassengerPerSeat() { NativeCall<void>(this, "APrimalDinoCharacter.OnRep_PassengerPerSeat"); }
	void ServerToggleCharging_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerToggleCharging_Implementation"); }
	void StartCharging(bool bForce) { NativeCall<void, bool>(this, "APrimalDinoCharacter.StartCharging", bForce); }
	void PlayChargingAnim() { NativeCall<void>(this, "APrimalDinoCharacter.PlayChargingAnim"); }
	void EndCharging(bool bForce) { NativeCall<void, bool>(this, "APrimalDinoCharacter.EndCharging", bForce); }
	bool AllowHurtAnimation() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowHurtAnimation"); }
	void SetRider(AShooterCharacter * aRider) { NativeCall<void, AShooterCharacter *>(this, "APrimalDinoCharacter.SetRider", aRider); }
	void OnRep_Rider() { NativeCall<void>(this, "APrimalDinoCharacter.OnRep_Rider"); }
	void OnRep_CarriedCharacter() { NativeCall<void>(this, "APrimalDinoCharacter.OnRep_CarriedCharacter"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APrimalDinoCharacter.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void ForceUpdateColorSets_Implementation(int ColorRegion, int ColorSet) { NativeCall<void, int, int>(this, "APrimalDinoCharacter.ForceUpdateColorSets_Implementation", ColorRegion, ColorSet); }
	FString * GetDescriptiveName(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalDinoCharacter.GetDescriptiveName", result); }
	FString * GetShortName(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalDinoCharacter.GetShortName", result); }
	void ForceClearRider() { NativeCall<void>(this, "APrimalDinoCharacter.ForceClearRider"); }
	void ClearRider(bool FromRider, bool bCancelForceLand, bool SpawnDinoDefaultController, int OverrideUnboardDirection) { NativeCall<void, bool, bool, bool, int>(this, "APrimalDinoCharacter.ClearRider", FromRider, bCancelForceLand, SpawnDinoDefaultController, OverrideUnboardDirection); }
	void ControllerLeavingGame(AShooterPlayerController * theController) { NativeCall<void, AShooterPlayerController *>(this, "APrimalDinoCharacter.ControllerLeavingGame", theController); }
	FString * GetEntryString(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalDinoCharacter.GetEntryString", result); }
	UTexture2D * GetEntryIcon(UObject * AssociatedDataObject, bool bIsEnabled) { return NativeCall<UTexture2D *, UObject *, bool>(this, "APrimalDinoCharacter.GetEntryIcon", AssociatedDataObject, bIsEnabled); }
	UMaterialInterface * GetEntryIconMaterial(UObject * AssociatedDataObject, bool bIsEnabled) { return NativeCall<UMaterialInterface *, UObject *, bool>(this, "APrimalDinoCharacter.GetEntryIconMaterial", AssociatedDataObject, bIsEnabled); }
	UObject * GetUObjectInterfaceDataListEntryInterface() { return NativeCall<UObject *>(this, "APrimalDinoCharacter.GetUObjectInterfaceDataListEntryInterface"); }
	FString * GetEntryDescription(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalDinoCharacter.GetEntryDescription", result); }
	void DrawHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "APrimalDinoCharacter.DrawHUD", HUD); }
	bool CanOrder(APrimalCharacter * FromCharacter, bool bBuildingStructures) { return NativeCall<bool, APrimalCharacter *, bool>(this, "APrimalDinoCharacter.CanOrder", FromCharacter, bBuildingStructures); }
	bool TamedProcessOrder(APrimalCharacter * FromCharacter, EDinoTamedOrder::Type OrderType, bool bForce, AActor * enemyTarget) { return NativeCall<bool, APrimalCharacter *, EDinoTamedOrder::Type, bool, AActor *>(this, "APrimalDinoCharacter.TamedProcessOrder", FromCharacter, OrderType, bForce, enemyTarget); }
	void ServerSleepingTick() { NativeCall<void>(this, "APrimalDinoCharacter.ServerSleepingTick"); }
	float GetAffinityIncreaseForFoodItem(UPrimalItem * foodItem) { return NativeCall<float, UPrimalItem *>(this, "APrimalDinoCharacter.GetAffinityIncreaseForFoodItem", foodItem); }
	void ServerTamedTick() { NativeCall<void>(this, "APrimalDinoCharacter.ServerTamedTick"); }
	UPrimalItem * GetBestInventoryFoodItem(float * FoodIncrease, bool bLookForAffinity, bool bFoodItemRequiresLivePlayerCharacter, UPrimalItem ** foundFoodItem, bool bLookForWorstFood) { return NativeCall<UPrimalItem *, float *, bool, bool, UPrimalItem **, bool>(this, "APrimalDinoCharacter.GetBestInventoryFoodItem", FoodIncrease, bLookForAffinity, bFoodItemRequiresLivePlayerCharacter, foundFoodItem, bLookForWorstFood); }
	AShooterCharacter * ConsumeInventoryFoodItem(UPrimalItem * foodItem, float * AffinityIncrease, bool bDontDecrementItem, float * FoodIncrease, float FoodAmountMultiplier, bool bConsumeEntireStack) { return NativeCall<AShooterCharacter *, UPrimalItem *, float *, bool, float *, float, bool>(this, "APrimalDinoCharacter.ConsumeInventoryFoodItem", foodItem, AffinityIncrease, bDontDecrementItem, FoodIncrease, FoodAmountMultiplier, bConsumeEntireStack); }
	AShooterCharacter * FindFirstFoodItemPlayerCharacter() { return NativeCall<AShooterCharacter *>(this, "APrimalDinoCharacter.FindFirstFoodItemPlayerCharacter"); }
	int GetFoodItemEffectivenessMultipliersIndex(UPrimalItem * foodItem) { return NativeCall<int, UPrimalItem *>(this, "APrimalDinoCharacter.GetFoodItemEffectivenessMultipliersIndex", foodItem); }
	TSubclassOf<UPrimalItem> * GetFirstAffinityFoodItemClass(TSubclassOf<UPrimalItem> * result) { return NativeCall<TSubclassOf<UPrimalItem> *, TSubclassOf<UPrimalItem> *>(this, "APrimalDinoCharacter.GetFirstAffinityFoodItemClass", result); }
	int GetExtraFoodItemEffectivenessMultipliersIndex(UPrimalItem * foodItem) { return NativeCall<int, UPrimalItem *>(this, "APrimalDinoCharacter.GetExtraFoodItemEffectivenessMultipliersIndex", foodItem); }
	void ServerClearRider_Implementation(int OverrideUnboardDirection) { NativeCall<void, int>(this, "APrimalDinoCharacter.ServerClearRider_Implementation", OverrideUnboardDirection); }
	void OnElevateDino(float Val) { NativeCall<void, float>(this, "APrimalDinoCharacter.OnElevateDino", Val); }
	void OnLowerDino(float Val) { NativeCall<void, float>(this, "APrimalDinoCharacter.OnLowerDino", Val); }
	void OnBrake() { NativeCall<void>(this, "APrimalDinoCharacter.OnBrake"); }
	void OffBrake() { NativeCall<void>(this, "APrimalDinoCharacter.OffBrake"); }
	void ServerRequestBraking_Implementation(bool bWantsToBrake) { NativeCall<void, bool>(this, "APrimalDinoCharacter.ServerRequestBraking_Implementation", bWantsToBrake); }
	void OnStartFire(bool bFromGamepadRight) { NativeCall<void, bool>(this, "APrimalDinoCharacter.OnStartFire", bFromGamepadRight); }
	void OnStopFire(bool bFromGamepadRight) { NativeCall<void, bool>(this, "APrimalDinoCharacter.OnStopFire", bFromGamepadRight); }
	void OnStartTargeting(bool bFromGamepadLeft) { NativeCall<void, bool>(this, "APrimalDinoCharacter.OnStartTargeting", bFromGamepadLeft); }
	void OnControllerInitiatedAttack(int AttackIndex) { NativeCall<void, int>(this, "APrimalDinoCharacter.OnControllerInitiatedAttack", AttackIndex); }
	void UpdateAttackTargets() { NativeCall<void>(this, "APrimalDinoCharacter.UpdateAttackTargets"); }
	void ServerUpdateAttackTargets_Implementation(AActor * AttackTarget, FVector AttackLocation) { NativeCall<void, AActor *, FVector>(this, "APrimalDinoCharacter.ServerUpdateAttackTargets_Implementation", AttackTarget, AttackLocation); }
	void GetAttackTargets(AActor ** attackActor, FVector * attackLoc) { NativeCall<void, AActor **, FVector *>(this, "APrimalDinoCharacter.GetAttackTargets", attackActor, attackLoc); }
	void ServerRequestAttack_Implementation(int attackIndex) { NativeCall<void, int>(this, "APrimalDinoCharacter.ServerRequestAttack_Implementation", attackIndex); }
	void OnPrimalCharacterSleeped() { NativeCall<void>(this, "APrimalDinoCharacter.OnPrimalCharacterSleeped"); }
	void UnPossessed() { NativeCall<void>(this, "APrimalDinoCharacter.UnPossessed"); }
	FRotator * ProcessRootRotAndLoc(FRotator * result, float DeltaTime, FVector * RootLocOffset, FRotator * RootRotOffset, float * RootYawSpeed, float MaxYawAimClamp, float CurrentAimBlending, FRotator * TargetAimRot, float * RootRot) { return NativeCall<FRotator *, FRotator *, float, FVector *, FRotator *, float *, float, float, FRotator *, float *>(this, "APrimalDinoCharacter.ProcessRootRotAndLoc", result, DeltaTime, RootLocOffset, RootRotOffset, RootYawSpeed, MaxYawAimClamp, CurrentAimBlending, TargetAimRot, RootRot); }
	FRotator * GetAimOffsets(FRotator * result, float DeltaTime, FRotator * RootRotOffset, float * RootYawSpeed, float MaxYawAimClamp, FVector * RootLocOffset) { return NativeCall<FRotator *, FRotator *, float, FRotator *, float *, float, FVector *>(this, "APrimalDinoCharacter.GetAimOffsets", result, DeltaTime, RootRotOffset, RootYawSpeed, MaxYawAimClamp, RootLocOffset); }
	FRotator * GetAimOffsetsTransform(FRotator * result, float DeltaTime, FTransform * RootRotOffsetTransform, float * RootYawSpeed, float MaxYawAimClamp, FVector * RootLocOffset) { return NativeCall<FRotator *, FRotator *, float, FTransform *, float *, float, FVector *>(this, "APrimalDinoCharacter.GetAimOffsetsTransform", result, DeltaTime, RootRotOffsetTransform, RootYawSpeed, MaxYawAimClamp, RootLocOffset); }
	void TempDampenInputAcceleration() { NativeCall<void>(this, "APrimalDinoCharacter.TempDampenInputAcceleration"); }
	bool ModifyInputAcceleration(FVector * InputAcceleration) { return NativeCall<bool, FVector *>(this, "APrimalDinoCharacter.ModifyInputAcceleration", InputAcceleration); }
	float GetMaxSpeedModifier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetMaxSpeedModifier"); }
	float GetSpeedModifier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetSpeedModifier"); }
	float GetRotationRateModifier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetRotationRateModifier"); }
	bool IsFleeing() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsFleeing"); }
	void FaceRotation(FRotator NewControlRotation, float DeltaTime, bool bFromController) { NativeCall<void, FRotator, float, bool>(this, "APrimalDinoCharacter.FaceRotation", NewControlRotation, DeltaTime, bFromController); }
	void MoveForward(float Val) { NativeCall<void, float>(this, "APrimalDinoCharacter.MoveForward", Val); }
	void MoveRight(float Val) { NativeCall<void, float>(this, "APrimalDinoCharacter.MoveRight", Val); }
	void MoveUp(float Val) { NativeCall<void, float>(this, "APrimalDinoCharacter.MoveUp", Val); }
	void SetCurrentAttackIndex(char index) { NativeCall<void, char>(this, "APrimalDinoCharacter.SetCurrentAttackIndex", index); }
	char GetWiegthedAttack(float distance, float attackRangeOffset, AActor * OtherTarget) { return NativeCall<char, float, float, AActor *>(this, "APrimalDinoCharacter.GetWiegthedAttack", distance, attackRangeOffset, OtherTarget); }
	void FireProjectileLocal(FVector Origin, FVector_NetQuantizeNormal ShootDir, bool bScaleProjDamageByDinoDamage) { NativeCall<void, FVector, FVector_NetQuantizeNormal, bool>(this, "APrimalDinoCharacter.FireProjectileLocal", Origin, ShootDir, bScaleProjDamageByDinoDamage); }
	void FireProjectile_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir, bool bScaleProjDamageByDinoDamage) { NativeCall<void, FVector, FVector_NetQuantizeNormal, bool>(this, "APrimalDinoCharacter.FireProjectile_Implementation", Origin, ShootDir, bScaleProjDamageByDinoDamage); }
	void ServerToClientsPlayAttackAnimation_Implementation(char AttackinfoIndex, char AnimationIndex, float InPlayRate, FName StartSectionName, bool bForceTickPoseAndServerUpdateMesh, bool bForceTickPoseOnServer, AActor * MyTarget) { NativeCall<void, char, char, float, FName, bool, bool, AActor *>(this, "APrimalDinoCharacter.ServerToClientsPlayAttackAnimation_Implementation", AttackinfoIndex, AnimationIndex, InPlayRate, StartSectionName, bForceTickPoseAndServerUpdateMesh, bForceTickPoseOnServer, MyTarget); }
	void ServerRequestToggleFlight_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerRequestToggleFlight_Implementation"); }
	void CalcCapsuleHalfHeight() { NativeCall<void>(this, "APrimalDinoCharacter.CalcCapsuleHalfHeight"); }
	void ClientStartLanding_Implementation(FVector loc) { NativeCall<void, FVector>(this, "APrimalDinoCharacter.ClientStartLanding_Implementation", loc); }
	void StartLanding(FVector OverrideLandingLocation) { NativeCall<void, FVector>(this, "APrimalDinoCharacter.StartLanding", OverrideLandingLocation); }
	void ServerInterruptLanding_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerInterruptLanding_Implementation"); }
	void InterruptLanding() { NativeCall<void>(this, "APrimalDinoCharacter.InterruptLanding"); }
	void ClientInterruptLanding_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ClientInterruptLanding_Implementation"); }
	void ServerFinishedLanding_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerFinishedLanding_Implementation"); }
	void FinishedLanding() { NativeCall<void>(this, "APrimalDinoCharacter.FinishedLanding"); }
	void ClientShouldNotifyLanded_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ClientShouldNotifyLanded_Implementation"); }
	FVector * GetLandingLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalDinoCharacter.GetLandingLocation", result); }
	void SetFlight(bool bFly, bool bCancelForceLand) { NativeCall<void, bool, bool>(this, "APrimalDinoCharacter.SetFlight", bFly, bCancelForceLand); }
	void KeepFlightTimer() { NativeCall<void>(this, "APrimalDinoCharacter.KeepFlightTimer"); }
	void DidLand() { NativeCall<void>(this, "APrimalDinoCharacter.DidLand"); }
	void AddFlyerTakeOffImpulse() { NativeCall<void>(this, "APrimalDinoCharacter.AddFlyerTakeOffImpulse"); }
	void OnStartJump() { NativeCall<void>(this, "APrimalDinoCharacter.OnStartJump"); }
	void ServerRequestWaterSurfaceJump_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerRequestWaterSurfaceJump_Implementation"); }
	bool IsUpdatingComponentTransforms(USceneComponent * InSceneComponent) { return NativeCall<bool, USceneComponent *>(this, "APrimalDinoCharacter.IsUpdatingComponentTransforms", InSceneComponent); }
	bool UseLowQualityMovementTick() { return NativeCall<bool>(this, "APrimalDinoCharacter.UseLowQualityMovementTick"); }
	bool UseLowQualityAnimationTick() { return NativeCall<bool>(this, "APrimalDinoCharacter.UseLowQualityAnimationTick"); }
	bool UseLowQualityBehaviorTreeTick() { return NativeCall<bool>(this, "APrimalDinoCharacter.UseLowQualityBehaviorTreeTick"); }
	bool CanTame(AShooterPlayerController * ForPC, bool bIgnoreMaxTamedDinos) { return NativeCall<bool, AShooterPlayerController *, bool>(this, "APrimalDinoCharacter.CanTame", ForPC, bIgnoreMaxTamedDinos); }
	void SetupTamed(bool bWasJustTamed) { NativeCall<void, bool>(this, "APrimalDinoCharacter.SetupTamed", bWasJustTamed); }
	void TameDino(AShooterPlayerController * ForPC, bool bIgnoreMaxTameLimit, int OverrideTamingTeamID) { NativeCall<void, AShooterPlayerController *, bool, int>(this, "APrimalDinoCharacter.TameDino", ForPC, bIgnoreMaxTameLimit, OverrideTamingTeamID); }
	void SetCharacterStatusTameable(bool bSetTameable, bool bCreateInventory, bool keepInventoryForWakingTame) { NativeCall<void, bool, bool, bool>(this, "APrimalDinoCharacter.SetCharacterStatusTameable", bSetTameable, bCreateInventory, keepInventoryForWakingTame); }
	void OnPrimalCharacterUnsleeped() { NativeCall<void>(this, "APrimalDinoCharacter.OnPrimalCharacterUnsleeped"); }
	bool IsValidForStatusUpdate() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsValidForStatusUpdate"); }
	AActor * GetOtherActorToIgnore() { return NativeCall<AActor *>(this, "APrimalDinoCharacter.GetOtherActorToIgnore"); }
	long double GetForceClaimTime() { return NativeCall<long double>(this, "APrimalDinoCharacter.GetForceClaimTime"); }
	void UnclaimDino(bool bDestroyAI) { NativeCall<void, bool>(this, "APrimalDinoCharacter.UnclaimDino", bDestroyAI); }
	bool TryMultiUse(APlayerController * ForPC, int UseIndex) { return NativeCall<bool, APlayerController *, int>(this, "APrimalDinoCharacter.TryMultiUse", ForPC, UseIndex); }
	bool SetTurretMode_Implementation(bool enabled) { return NativeCall<bool, bool>(this, "APrimalDinoCharacter.SetTurretMode_Implementation", enabled); }
	void SetTurretModeMovementRestrictions(bool enabled) { NativeCall<void, bool>(this, "APrimalDinoCharacter.SetTurretModeMovementRestrictions", enabled); }
	void ClientMultiUse(APlayerController * ForPC, int UseIndex) { NativeCall<void, APlayerController *, int>(this, "APrimalDinoCharacter.ClientMultiUse", ForPC, UseIndex); }
	void ChangeActorTeam(int NewTeam) { NativeCall<void, int>(this, "APrimalDinoCharacter.ChangeActorTeam", NewTeam); }
	void LinkedSupplyCrateDestroyed(APrimalStructureItemContainer_SupplyCrate * aCrate) { NativeCall<void, APrimalStructureItemContainer_SupplyCrate *>(this, "APrimalDinoCharacter.LinkedSupplyCrateDestroyed", aCrate); }
	bool AllowNewEggAtLocation(FVector * AtLocation) { return NativeCall<bool, FVector *>(this, "APrimalDinoCharacter.AllowNewEggAtLocation", AtLocation); }
	void SpawnEgg() { NativeCall<void>(this, "APrimalDinoCharacter.SpawnEgg"); }
	float GetRunningSpeedModifier(bool bIsForDefaultSpeed) { return NativeCall<float, bool>(this, "APrimalDinoCharacter.GetRunningSpeedModifier", bIsForDefaultSpeed); }
	void BeginPlay() { NativeCall<void>(this, "APrimalDinoCharacter.BeginPlay"); }
	void ForceRefreshTransform() { NativeCall<void>(this, "APrimalDinoCharacter.ForceRefreshTransform"); }
	void AutoTame() { NativeCall<void>(this, "APrimalDinoCharacter.AutoTame"); }
	void SetupColorization() { NativeCall<void>(this, "APrimalDinoCharacter.SetupColorization"); }
	void RefreshColorization() { NativeCall<void>(this, "APrimalDinoCharacter.RefreshColorization"); }
	bool CanTarget(ITargetableInterface * Victim) { return NativeCall<bool, ITargetableInterface *>(this, "APrimalDinoCharacter.CanTarget", Victim); }
	int GetOriginalTargetingTeam() { return NativeCall<int>(this, "APrimalDinoCharacter.GetOriginalTargetingTeam"); }
	float GetTargetingDesirability(ITargetableInterface * Attacker) { return NativeCall<float, ITargetableInterface *>(this, "APrimalDinoCharacter.GetTargetingDesirability", Attacker); }
	bool ShouldReplicateRotPitch() { return NativeCall<bool>(this, "APrimalDinoCharacter.ShouldReplicateRotPitch"); }
	void NetUpdateDinoNameStrings_Implementation(FString * NewTamerString, FString * NewTamedName) { NativeCall<void, FString *, FString *>(this, "APrimalDinoCharacter.NetUpdateDinoNameStrings_Implementation", NewTamerString, NewTamedName); }
	void ProcessEditText(AShooterPlayerController * ForPC, FString * TextToUse, bool checkedBox) { NativeCall<void, AShooterPlayerController *, FString *, bool>(this, "APrimalDinoCharacter.ProcessEditText", ForPC, TextToUse, checkedBox); }
	static APrimalDinoCharacter * FindDinoWithID(UWorld * aWorld, unsigned int DinoID1, unsigned int DinoID2) { return NativeCall<APrimalDinoCharacter *, UWorld *, unsigned int, unsigned int>(nullptr, "APrimalDinoCharacter.FindDinoWithID", aWorld, DinoID1, DinoID2); }
	void TargetingTeamChanged() { NativeCall<void>(this, "APrimalDinoCharacter.TargetingTeamChanged"); }
	void Destroyed() { NativeCall<void>(this, "APrimalDinoCharacter.Destroyed"); }
	void DrawFloatingHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "APrimalDinoCharacter.DrawFloatingHUD", HUD); }
	void DrawDinoFloatingHUD(AShooterHUD * HUD, bool bDrawDinoOrderIcon) { NativeCall<void, AShooterHUD *, bool>(this, "APrimalDinoCharacter.DrawDinoFloatingHUD", HUD, bDrawDinoOrderIcon); }
	bool IsNearFeed(AShooterPlayerState * ForPlayer) { return NativeCall<bool, AShooterPlayerState *>(this, "APrimalDinoCharacter.IsNearFeed", ForPlayer); }
	void DeathHarvestingFadeOut_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.DeathHarvestingFadeOut_Implementation"); }
	void NotifyItemAdded(UPrimalItem * anItem, bool bEquipItem) { NativeCall<void, UPrimalItem *, bool>(this, "APrimalDinoCharacter.NotifyItemAdded", anItem, bEquipItem); }
	FString * GetDinoDescriptiveName(FString * result) { return NativeCall<FString *, FString *>(this, "APrimalDinoCharacter.GetDinoDescriptiveName", result); }
	void ServerGiveDefaultWeapon_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerGiveDefaultWeapon_Implementation"); }
	void ServerCallFollow_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallFollow_Implementation"); }
	void ServerCallFollowOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "APrimalDinoCharacter.ServerCallFollowOne_Implementation", ForDinoChar); }
	void ServerCallStay_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallStay_Implementation"); }
	void ServerCallStayOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "APrimalDinoCharacter.ServerCallStayOne_Implementation", ForDinoChar); }
	void ServerCallFollowDistanceCycleOne_Implementation(APrimalDinoCharacter * ForDinoChar) { NativeCall<void, APrimalDinoCharacter *>(this, "APrimalDinoCharacter.ServerCallFollowDistanceCycleOne_Implementation", ForDinoChar); }
	void ServerCallAggressive_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallAggressive_Implementation"); }
	void ServerCallSetAggressive_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallSetAggressive_Implementation"); }
	void ServerCallNeutral_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallNeutral_Implementation"); }
	void ServerCallPassive_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerCallPassive_Implementation"); }
	void ServerCallAttackTarget_Implementation(AActor * TheTarget) { NativeCall<void, AActor *>(this, "APrimalDinoCharacter.ServerCallAttackTarget_Implementation", TheTarget); }
	void ServerCallMoveTo_Implementation(FVector MoveToLoc) { NativeCall<void, FVector>(this, "APrimalDinoCharacter.ServerCallMoveTo_Implementation", MoveToLoc); }
	void NotifyItemRemoved(UPrimalItem * anItem) { NativeCall<void, UPrimalItem *>(this, "APrimalDinoCharacter.NotifyItemRemoved", anItem); }
	float GetCorpseLifespan() { return NativeCall<float>(this, "APrimalDinoCharacter.GetCorpseLifespan"); }
	void UpdateMateBoost() { NativeCall<void>(this, "APrimalDinoCharacter.UpdateMateBoost"); }
	void AdjustDamage(float * Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { NativeCall<void, float *, FDamageEvent *, AController *, AActor *>(this, "APrimalDinoCharacter.AdjustDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	void SpawnDefaultController() { NativeCall<void>(this, "APrimalDinoCharacter.SpawnDefaultController"); }
	bool AllowFallDamage() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowFallDamage"); }
	void ApplyDamageMomentum(float DamageTaken, FDamageEvent * DamageEvent, APawn * PawnInstigator, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "APrimalDinoCharacter.ApplyDamageMomentum", DamageTaken, DamageEvent, PawnInstigator, DamageCauser); }
	void UpdateIK() { NativeCall<void>(this, "APrimalDinoCharacter.UpdateIK"); }
	bool AllowIKFreeze() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowIKFreeze"); }
	void SetSleeping(bool bSleeping, bool bUseRagdollLocationOffset) { NativeCall<void, bool, bool>(this, "APrimalDinoCharacter.SetSleeping", bSleeping, bUseRagdollLocationOffset); }
	bool Die(float KillingDamage, FDamageEvent * DamageEvent, AController * Killer, AActor * DamageCauser) { return NativeCall<bool, float, FDamageEvent *, AController *, AActor *>(this, "APrimalDinoCharacter.Die", KillingDamage, DamageEvent, Killer, DamageCauser); }
	bool AllowPenetrationCheck(AActor * OtherActor) { return NativeCall<bool, AActor *>(this, "APrimalDinoCharacter.AllowPenetrationCheck", OtherActor); }
	bool PreventCharacterBasing(AActor * OtherActor, UPrimitiveComponent * BasedOnComponent) { return NativeCall<bool, AActor *, UPrimitiveComponent *>(this, "APrimalDinoCharacter.PreventCharacterBasing", OtherActor, BasedOnComponent); }
	void LoadedFromSaveGame() { NativeCall<void>(this, "APrimalDinoCharacter.LoadedFromSaveGame"); }
	float GetCorpseTargetingMultiplier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetCorpseTargetingMultiplier"); }
	void UpdateStatusComponent(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalDinoCharacter.UpdateStatusComponent", DeltaSeconds); }
	void TamedDinoUnstasisConsumeFood(long double ForceTimeSinceStasis) { NativeCall<void, long double>(this, "APrimalDinoCharacter.TamedDinoUnstasisConsumeFood", ForceTimeSinceStasis); }
	AActor * GetTamedFollowTarget() { return NativeCall<AActor *>(this, "APrimalDinoCharacter.GetTamedFollowTarget"); }
	void DinoKillerTransferItemsToInventory(UPrimalInventoryComponent * FromInventory) { NativeCall<void, UPrimalInventoryComponent *>(this, "APrimalDinoCharacter.DinoKillerTransferItemsToInventory", FromInventory); }
	bool FlyingUseHighQualityCollision() { return NativeCall<bool>(this, "APrimalDinoCharacter.FlyingUseHighQualityCollision"); }
	bool AllowWalkableSlopeOverride() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowWalkableSlopeOverride"); }
	float GetCarryingSocketYaw(bool RefreshBones) { return NativeCall<float, bool>(this, "APrimalDinoCharacter.GetCarryingSocketYaw", RefreshBones); }
	void GetRidingCarryingIgnoreList(TArray<AActor *> * IgnoreList) { NativeCall<void, TArray<AActor *> *>(this, "APrimalDinoCharacter.GetRidingCarryingIgnoreList", IgnoreList); }
	void SetCarryingDino(APrimalDinoCharacter * aDino) { NativeCall<void, APrimalDinoCharacter *>(this, "APrimalDinoCharacter.SetCarryingDino", aDino); }
	void ClearCarryingDino(bool bFromDino, bool bCancelAnyCarryBuffs) { NativeCall<void, bool, bool>(this, "APrimalDinoCharacter.ClearCarryingDino", bFromDino, bCancelAnyCarryBuffs); }
	void UpdateCarriedLocationAndRotation(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalDinoCharacter.UpdateCarriedLocationAndRotation", DeltaSeconds); }
	bool CanBeCarried(APrimalCharacter * ByCarrier) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.CanBeCarried", ByCarrier); }
	void SetMountCharacter(APrimalCharacter * aCharacter) { NativeCall<void, APrimalCharacter *>(this, "APrimalDinoCharacter.SetMountCharacter", aCharacter); }
	void StartForceSkelUpdate(float ForTime, bool bForceUpdateMesh, bool bServerOnly) { NativeCall<void, float, bool, bool>(this, "APrimalDinoCharacter.StartForceSkelUpdate", ForTime, bForceUpdateMesh, bServerOnly); }
	void ClearMountCharacter(bool bFromMountCharacter) { NativeCall<void, bool>(this, "APrimalDinoCharacter.ClearMountCharacter", bFromMountCharacter); }
	bool CanMount(APrimalCharacter * aCharacter) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.CanMount", aCharacter); }
	static APrimalDinoCharacter * SpawnDino(UWorld * World, TSubclassOf<APrimalDinoCharacter> DinoClass, FVector SpawnLoc, FRotator SpawnRot, float LevelMultiplier, int ExtraLevelOffset, bool AddLevelOffsetBeforeMultiplier, bool bOverrideBaseNPCLevel, int BaseLevelOverrideValue, bool bNPCDontWander, float NPCAIRangeMultiplier, int NPCAbsoluteBaseLevel, bool bSpawnWithoutCapsuleOffset) { return NativeCall<APrimalDinoCharacter *, UWorld *, TSubclassOf<APrimalDinoCharacter>, FVector, FRotator, float, int, bool, bool, int, bool, float, int, bool>(nullptr, "APrimalDinoCharacter.SpawnDino", World, DinoClass, SpawnLoc, SpawnRot, LevelMultiplier, ExtraLevelOffset, AddLevelOffsetBeforeMultiplier, bOverrideBaseNPCLevel, BaseLevelOverrideValue, bNPCDontWander, NPCAIRangeMultiplier, NPCAbsoluteBaseLevel, bSpawnWithoutCapsuleOffset); }
	void InitDownloadedTamedDino(AShooterPlayerController * TamerController, int AltTeam) { NativeCall<void, AShooterPlayerController *, int>(this, "APrimalDinoCharacter.InitDownloadedTamedDino", TamerController, AltTeam); }
	void NetUpdateDinoOwnerData_Implementation(FString * NewOwningPlayerName, int NewOwningPlayerID) { NativeCall<void, FString *, int>(this, "APrimalDinoCharacter.NetUpdateDinoOwnerData_Implementation", NewOwningPlayerName, NewOwningPlayerID); }
	bool RemoveInventoryAllowViewing(APlayerController * ForPC) { return NativeCall<bool, APlayerController *>(this, "APrimalDinoCharacter.RemoveInventoryAllowViewing", ForPC); }
	bool ForceAllowBackwardsMovement() { return NativeCall<bool>(this, "APrimalDinoCharacter.ForceAllowBackwardsMovement"); }
	bool CanDragCharacter(APrimalCharacter * Character) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.CanDragCharacter", Character); }
	bool IsTaming() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsTaming"); }
	void UpdateWakingTame(float DeltaTime) { NativeCall<void, float>(this, "APrimalDinoCharacter.UpdateWakingTame", DeltaTime); }
	void FedWakingTameDino_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.FedWakingTameDino_Implementation"); }
	void AddStructure(APrimalStructure * Structure, FVector RelLoc, FRotator RelRot, FName BoneName) { NativeCall<void, APrimalStructure *, FVector, FRotator, FName>(this, "APrimalDinoCharacter.AddStructure", Structure, RelLoc, RelRot, BoneName); }
	void RemoveStructure(APrimalStructure * Structure) { NativeCall<void, APrimalStructure *>(this, "APrimalDinoCharacter.RemoveStructure", Structure); }
	void OnRep_Saddle() { NativeCall<void>(this, "APrimalDinoCharacter.OnRep_Saddle"); }
	void ServerUploadCharacter(AShooterPlayerController * UploadedBy) { NativeCall<void, AShooterPlayerController *>(this, "APrimalDinoCharacter.ServerUploadCharacter", UploadedBy); }
	void EmitPoop() { NativeCall<void>(this, "APrimalDinoCharacter.EmitPoop"); }
	void CheckForWildAmbientHarvesting() { NativeCall<void>(this, "APrimalDinoCharacter.CheckForWildAmbientHarvesting"); }
	void OverrideRandomWanderLocation_Implementation(FVector * originalDestination, FVector * inVec) { NativeCall<void, FVector *, FVector *>(this, "APrimalDinoCharacter.OverrideRandomWanderLocation_Implementation", originalDestination, inVec); }
	bool AllowEquippingItemType(EPrimalEquipmentType::Type equipmentType) { return NativeCall<bool, EPrimalEquipmentType::Type>(this, "APrimalDinoCharacter.AllowEquippingItemType", equipmentType); }
	void OnPressReload() { NativeCall<void>(this, "APrimalDinoCharacter.OnPressReload"); }
	void OnPressCrouch() { NativeCall<void>(this, "APrimalDinoCharacter.OnPressCrouch"); }
	void NotifyBumpedPawn(APawn * BumpedPawn) { NativeCall<void, APawn *>(this, "APrimalDinoCharacter.NotifyBumpedPawn", BumpedPawn); }
	void NotifyBumpedStructure(AActor * BumpedStructure) { NativeCall<void, AActor *>(this, "APrimalDinoCharacter.NotifyBumpedStructure", BumpedStructure); }
	void StartRepair() { NativeCall<void>(this, "APrimalDinoCharacter.StartRepair"); }
	void RepairCheckTimer() { NativeCall<void>(this, "APrimalDinoCharacter.RepairCheckTimer"); }
	bool InitializeForReplicatedBasing() { return NativeCall<bool>(this, "APrimalDinoCharacter.InitializeForReplicatedBasing"); }
	void RemoveBasedPawn(AActor * anPawn) { NativeCall<void, AActor *>(this, "APrimalDinoCharacter.RemoveBasedPawn", anPawn); }
	bool AllowMovementMode(EMovementMode NewMovementMode, char NewCustomMode) { return NativeCall<bool, EMovementMode, char>(this, "APrimalDinoCharacter.AllowMovementMode", NewMovementMode, NewCustomMode); }
	void OnRep_bBonesHidden() { NativeCall<void>(this, "APrimalDinoCharacter.OnRep_bBonesHidden"); }
	void SetBabyAge(float TheAge) { NativeCall<void, float>(this, "APrimalDinoCharacter.SetBabyAge", TheAge); }
	void ApplyBoneModifiers(bool bForce) { NativeCall<void, bool>(this, "APrimalDinoCharacter.ApplyBoneModifiers", bForce); }
	void ApplyGestationBoneModifiers() { NativeCall<void>(this, "APrimalDinoCharacter.ApplyGestationBoneModifiers"); }
	float GetAttachedSoundPitchMultiplier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetAttachedSoundPitchMultiplier"); }
	float GetAttachedSoundVolumeMultiplier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetAttachedSoundVolumeMultiplier"); }
	void Poop(bool bForcePoop) { NativeCall<void, bool>(this, "APrimalDinoCharacter.Poop", bForcePoop); }
	float GetBaseDragWeight() { return NativeCall<float>(this, "APrimalDinoCharacter.GetBaseDragWeight"); }
	void ServerUpdateBabyAge(float overrideAgePercent) { NativeCall<void, float>(this, "APrimalDinoCharacter.ServerUpdateBabyAge", overrideAgePercent); }
	void ServerUpdateGestation() { NativeCall<void>(this, "APrimalDinoCharacter.ServerUpdateGestation"); }
	float GetHealthPercentage() { return NativeCall<float>(this, "APrimalDinoCharacter.GetHealthPercentage"); }
	void UpdateMating() { NativeCall<void>(this, "APrimalDinoCharacter.UpdateMating"); }
	void DoMate(APrimalDinoCharacter * WithMate) { NativeCall<void, APrimalDinoCharacter *>(this, "APrimalDinoCharacter.DoMate", WithMate); }
	ADroppedItem * CreateCloneFertilizedEgg(FVector AtLoc, FRotator AtRot, TSubclassOf<ADroppedItem> DroppedItemTemplateOverride) { return NativeCall<ADroppedItem *, FVector, FRotator, TSubclassOf<ADroppedItem>>(this, "APrimalDinoCharacter.CreateCloneFertilizedEgg", AtLoc, AtRot, DroppedItemTemplateOverride); }
	FVector * GetInterpolatedLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalDinoCharacter.GetInterpolatedLocation", result); }
	static APrimalDinoCharacter * BPStaticCreateBabyDinoNoAncestors(UWorld * TheWorld, TSubclassOf<APrimalDinoCharacter> EggDinoClassToSpawn, FVector * theGroundLoc, float actorRotationYaw, TArray<unsigned char> EggColorSetIndices, TArray<unsigned char> EggNumberOfLevelUpPointsApplied, float EggTamedIneffectivenessModifier, int NotifyTeamOverride, int EggRandomMutationsFemale, int EggRandomMutationsMale) { return NativeCall<APrimalDinoCharacter *, UWorld *, TSubclassOf<APrimalDinoCharacter>, FVector *, float, TArray<unsigned char>, TArray<unsigned char>, float, int, int, int>(nullptr, "APrimalDinoCharacter.BPStaticCreateBabyDinoNoAncestors", TheWorld, EggDinoClassToSpawn, theGroundLoc, actorRotationYaw, EggColorSetIndices, EggNumberOfLevelUpPointsApplied, EggTamedIneffectivenessModifier, NotifyTeamOverride, EggRandomMutationsFemale, EggRandomMutationsMale); }
	static APrimalDinoCharacter * BPStaticCreateBabyDino(UWorld * TheWorld, TSubclassOf<APrimalDinoCharacter> EggDinoClassToSpawn, FVector * theGroundLoc, float actorRotationYaw, TArray<unsigned char> EggColorSetIndices, TArray<unsigned char> EggNumberOfLevelUpPointsApplied, float EggTamedIneffectivenessModifier, TArray<FDinoAncestorsEntry> EggDinoAncestors, TArray<FDinoAncestorsEntry> EggDinoAncestorsMale, int NotifyTeamOverride, int EggRandomMutationsFemale, int EggRandomMutationsMale) { return NativeCall<APrimalDinoCharacter *, UWorld *, TSubclassOf<APrimalDinoCharacter>, FVector *, float, TArray<unsigned char>, TArray<unsigned char>, float, TArray<FDinoAncestorsEntry>, TArray<FDinoAncestorsEntry>, int, int, int>(nullptr, "APrimalDinoCharacter.BPStaticCreateBabyDino", TheWorld, EggDinoClassToSpawn, theGroundLoc, actorRotationYaw, EggColorSetIndices, EggNumberOfLevelUpPointsApplied, EggTamedIneffectivenessModifier, EggDinoAncestors, EggDinoAncestorsMale, NotifyTeamOverride, EggRandomMutationsFemale, EggRandomMutationsMale); }
	static APrimalDinoCharacter * StaticCreateBabyDino(UWorld * theWorld, TSubclassOf<APrimalDinoCharacter> EggDinoClassToSpawn, FVector * theGroundLoc, float actorRotationYaw, char * EggColorSetIndices, char * EggNumberOfLevelUpPointsApplied, float EggTamedIneffectivenessModifier, int NotifyTeamOverride, TArray<FDinoAncestorsEntry> * EggDinoAncestors, TArray<FDinoAncestorsEntry> * EggDinoAncestorsMale, int EggRandomMutationsFemale, int EggRandomMutationsMale) { return NativeCall<APrimalDinoCharacter *, UWorld *, TSubclassOf<APrimalDinoCharacter>, FVector *, float, char *, char *, float, int, TArray<FDinoAncestorsEntry> *, TArray<FDinoAncestorsEntry> *, int, int>(nullptr, "APrimalDinoCharacter.StaticCreateBabyDino", theWorld, EggDinoClassToSpawn, theGroundLoc, actorRotationYaw, EggColorSetIndices, EggNumberOfLevelUpPointsApplied, EggTamedIneffectivenessModifier, NotifyTeamOverride, EggDinoAncestors, EggDinoAncestorsMale, EggRandomMutationsFemale, EggRandomMutationsMale); }
	void UpdateGang() { NativeCall<void>(this, "APrimalDinoCharacter.UpdateGang"); }
	TSubclassOf<UDamageType> * BlueprintOverrideHarvestDamageType_Implementation(TSubclassOf<UDamageType> * result, float * OutHarvestDamageMultiplier) { return NativeCall<TSubclassOf<UDamageType> *, TSubclassOf<UDamageType> *, float *>(this, "APrimalDinoCharacter.BlueprintOverrideHarvestDamageType_Implementation", result, OutHarvestDamageMultiplier); }
	float GetGravityZScale() { return NativeCall<float>(this, "APrimalDinoCharacter.GetGravityZScale"); }
	bool ForceAllowAccelerationRotationWhenFalling() { return NativeCall<bool>(this, "APrimalDinoCharacter.ForceAllowAccelerationRotationWhenFalling"); }
	bool ShouldDisableControllerDesiredRotation() { return NativeCall<bool>(this, "APrimalDinoCharacter.ShouldDisableControllerDesiredRotation"); }
	bool AllowExtendedCraftingFunctionality() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowExtendedCraftingFunctionality"); }
	void UpdateTribeGroupRanks_Implementation(char NewTribeGroupPetOrderingRank, char NewTribeGroupPetRidingRank) { NativeCall<void, char, char>(this, "APrimalDinoCharacter.UpdateTribeGroupRanks_Implementation", NewTribeGroupPetOrderingRank, NewTribeGroupPetRidingRank); }
	FVector * GetFloatingHUDLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalDinoCharacter.GetFloatingHUDLocation", result); }
	void WasPushed(ACharacter * ByOtherCharacter) { NativeCall<void, ACharacter *>(this, "APrimalDinoCharacter.WasPushed", ByOtherCharacter); }
	void UpdateImprintingDetails_Implementation(FString * NewImprinterName, unsigned __int64 NewImprinterPlayerDataID) { NativeCall<void, FString *, unsigned __int64>(this, "APrimalDinoCharacter.UpdateImprintingDetails_Implementation", NewImprinterName, NewImprinterPlayerDataID); }
	void UpdateImprintingQuality_Implementation(float NewImprintingQuality) { NativeCall<void, float>(this, "APrimalDinoCharacter.UpdateImprintingQuality_Implementation", NewImprintingQuality); }
	void UpdateBabyCuddling_Implementation(long double NewBabyNextCuddleTime, char NewBabyCuddleType, TSubclassOf<UPrimalItem> NewBabyCuddleFood) { NativeCall<void, long double, char, TSubclassOf<UPrimalItem>>(this, "APrimalDinoCharacter.UpdateBabyCuddling_Implementation", NewBabyNextCuddleTime, NewBabyCuddleType, NewBabyCuddleFood); }
	TSubclassOf<UPrimalItem> * GetBabyCuddleFood(TSubclassOf<UPrimalItem> * result) { return NativeCall<TSubclassOf<UPrimalItem> *, TSubclassOf<UPrimalItem> *>(this, "APrimalDinoCharacter.GetBabyCuddleFood", result); }
	void IncrementImprintingQuality() { NativeCall<void>(this, "APrimalDinoCharacter.IncrementImprintingQuality"); }
	void AddedImprintingQuality_Implementation(float Amount) { NativeCall<void, float>(this, "APrimalDinoCharacter.AddedImprintingQuality_Implementation", Amount); }
	bool AllowWakingTame_Implementation(APlayerController * ForPC) { return NativeCall<bool, APlayerController *>(this, "APrimalDinoCharacter.AllowWakingTame_Implementation", ForPC); }
	float GetBaseTargetingDesire(ITargetableInterface * Attacker) { return NativeCall<float, ITargetableInterface *>(this, "APrimalDinoCharacter.GetBaseTargetingDesire", Attacker); }
	void PostNetReceiveLocationAndRotation() { NativeCall<void>(this, "APrimalDinoCharacter.PostNetReceiveLocationAndRotation"); }
	void ResetTakingOff() { NativeCall<void>(this, "APrimalDinoCharacter.ResetTakingOff"); }
	void FireMultipleProjectiles_Implementation(TArray<FVector> * Locations, TArray<FVector> * Directions, bool bScaleProjectileDamageByDinoDamage) { NativeCall<void, TArray<FVector> *, TArray<FVector> *, bool>(this, "APrimalDinoCharacter.FireMultipleProjectiles_Implementation", Locations, Directions, bScaleProjectileDamageByDinoDamage); }
	void CycleAttackWeightsForAttackAtIndex(int attackIndex) { NativeCall<void, int>(this, "APrimalDinoCharacter.CycleAttackWeightsForAttackAtIndex", attackIndex); }
	void SetAnimWeightsForAttackAtIndex(int attackIndex, TArray<float> newWeights) { NativeCall<void, int, TArray<float>>(this, "APrimalDinoCharacter.SetAnimWeightsForAttackAtIndex", attackIndex, newWeights); }
	void AddDinoReferenceInLatchingStructure(APrimalStructure * Structure) { NativeCall<void, APrimalStructure *>(this, "APrimalDinoCharacter.AddDinoReferenceInLatchingStructure", Structure); }
	void RemoveDinoReferenceFromLatchingStructure() { NativeCall<void>(this, "APrimalDinoCharacter.RemoveDinoReferenceFromLatchingStructure"); }
	void StartSurfaceCameraForPassengers(float yaw, float pitch, float roll) { NativeCall<void, float, float, float>(this, "APrimalDinoCharacter.StartSurfaceCameraForPassengers", yaw, pitch, roll); }
	TArray<APrimalCharacter *> * GetPassengers(TArray<APrimalCharacter *> * result) { return NativeCall<TArray<APrimalCharacter *> *, TArray<APrimalCharacter *> *>(this, "APrimalDinoCharacter.GetPassengers", result); }
	void GetPassengersAndSeatIndexes(TArray<APrimalCharacter *> * Passengers, TArray<int> * Indexes) { NativeCall<void, TArray<APrimalCharacter *> *, TArray<int> *>(this, "APrimalDinoCharacter.GetPassengersAndSeatIndexes", Passengers, Indexes); }
	bool ShouldIgnoreMoveCombiningOverlap() { return NativeCall<bool>(this, "APrimalDinoCharacter.ShouldIgnoreMoveCombiningOverlap"); }
	bool AllowMountedWeaponry(bool bIgnoreCurrentWeapon, bool bWeaponForcesMountedWeaponry) { return NativeCall<bool, bool, bool>(this, "APrimalDinoCharacter.AllowMountedWeaponry", bIgnoreCurrentWeapon, bWeaponForcesMountedWeaponry); }
	void ModifyDesiredRotation(FRotator * InDesiredRotation) { NativeCall<void, FRotator *>(this, "APrimalDinoCharacter.ModifyDesiredRotation", InDesiredRotation); }
	void GiveDeathDossier() { NativeCall<void>(this, "APrimalDinoCharacter.GiveDeathDossier"); }
	void ServerSetRiderMountedWeaponRotation_Implementation(FRotator InVal) { NativeCall<void, FRotator>(this, "APrimalDinoCharacter.ServerSetRiderMountedWeaponRotation_Implementation", InVal); }
	void DoNeuter_Implementation() { NativeCall<void>(this, "APrimalDinoCharacter.DoNeuter_Implementation"); }
	bool OverrideForcePreventExitingWater() { return NativeCall<bool>(this, "APrimalDinoCharacter.OverrideForcePreventExitingWater"); }
	APrimalStructureExplosive * GetAttachedExplosive() { return NativeCall<APrimalStructureExplosive *>(this, "APrimalDinoCharacter.GetAttachedExplosive"); }
	void OnStopTargeting(bool bFromGamepadLeft) { NativeCall<void, bool>(this, "APrimalDinoCharacter.OnStopTargeting", bFromGamepadLeft); }
	void SetDynamicMusic(USoundBase * newMusic) { NativeCall<void, USoundBase *>(this, "APrimalDinoCharacter.SetDynamicMusic", newMusic); }
	FLinearColor * GetDinoColor(FLinearColor * result, int ColorRegionIndex) { return NativeCall<FLinearColor *, FLinearColor *, int>(this, "APrimalDinoCharacter.GetDinoColor", result, ColorRegionIndex); }
	bool SpecialActorWantsPerFrameTicking() { return NativeCall<bool>(this, "APrimalDinoCharacter.SpecialActorWantsPerFrameTicking"); }
	int IsActorTickAllowed() { return NativeCall<int>(this, "APrimalDinoCharacter.IsActorTickAllowed"); }
	void IncrementNumTamedDinos() { NativeCall<void>(this, "APrimalDinoCharacter.IncrementNumTamedDinos"); }
	bool ShouldStillAllowRequestedMoveAcceleration() { return NativeCall<bool>(this, "APrimalDinoCharacter.ShouldStillAllowRequestedMoveAcceleration"); }
	bool AreSpawnerSublevelsLoaded() { return NativeCall<bool>(this, "APrimalDinoCharacter.AreSpawnerSublevelsLoaded"); }
	void SetLastMovementDesiredRotation(FRotator * InRotation) { NativeCall<void, FRotator *>(this, "APrimalDinoCharacter.SetLastMovementDesiredRotation", InRotation); }
	USoundBase * GetDinoTameSound_Implementation() { return NativeCall<USoundBase *>(this, "APrimalDinoCharacter.GetDinoTameSound_Implementation"); }
	bool AllowTickPhysics() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowTickPhysics"); }
	void CheckForTamedFoodConsumption() { NativeCall<void>(this, "APrimalDinoCharacter.CheckForTamedFoodConsumption"); }
	bool ShouldIgnoreHitResult(UWorld * InWorld, FHitResult * TestHit, FVector * MovementDirDenormalized) { return NativeCall<bool, UWorld *, FHitResult *, FVector *>(this, "APrimalDinoCharacter.ShouldIgnoreHitResult", InWorld, TestHit, MovementDirDenormalized); }
	bool WalkingAllowCheckFall(FVector * DeltaWalk) { return NativeCall<bool, FVector *>(this, "APrimalDinoCharacter.WalkingAllowCheckFall", DeltaWalk); }
	float GetGestationTimeRemaining() { return NativeCall<float>(this, "APrimalDinoCharacter.GetGestationTimeRemaining"); }
	int GetTamedDinoCountCost() { return NativeCall<int>(this, "APrimalDinoCharacter.GetTamedDinoCountCost"); }
	void ClearAllSaddleStructures() { NativeCall<void>(this, "APrimalDinoCharacter.ClearAllSaddleStructures"); }
	bool IsReadyToUpload(UWorld * theWorld) { return NativeCall<bool, UWorld *>(this, "APrimalDinoCharacter.IsReadyToUpload", theWorld); }
	void ImprintOnPlayerTarget(AShooterPlayerController * ForPC, bool bIgnoreMaxTameLimit) { NativeCall<void, AShooterPlayerController *, bool>(this, "APrimalDinoCharacter.ImprintOnPlayerTarget", ForPC, bIgnoreMaxTameLimit); }
	void BPNotifyNameEditText(AShooterPlayerController * ForPC) { NativeCall<void, AShooterPlayerController *>(this, "APrimalDinoCharacter.BPNotifyNameEditText", ForPC); }
	void SetRidingDinoAsPassenger(APrimalDinoCharacter * aDino, FSaddlePassengerSeatDefinition * SeatDefinition) { NativeCall<void, APrimalDinoCharacter *, FSaddlePassengerSeatDefinition *>(this, "APrimalDinoCharacter.SetRidingDinoAsPassenger", aDino, SeatDefinition); }
	void ClearRidingDinoAsPassenger(bool bFromDino) { NativeCall<void, bool>(this, "APrimalDinoCharacter.ClearRidingDinoAsPassenger", bFromDino); }
	APrimalCharacter * GetPassengerPerSeat(int SeatIndex) { return NativeCall<APrimalCharacter *, int>(this, "APrimalDinoCharacter.GetPassengerPerSeat", SeatIndex); }
	void SpawnNewAIController(TSubclassOf<AController> NewAIController) { NativeCall<void, TSubclassOf<AController>>(this, "APrimalDinoCharacter.SpawnNewAIController", NewAIController); }
	int GetSeatIndexForPassenger(APrimalCharacter * PassengerChar) { return NativeCall<int, APrimalCharacter *>(this, "APrimalDinoCharacter.GetSeatIndexForPassenger", PassengerChar); }
	bool IsPrimalCharFriendly(APrimalCharacter * primalChar) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.IsPrimalCharFriendly", primalChar); }
	void PrepareForSaving() { NativeCall<void>(this, "APrimalDinoCharacter.PrepareForSaving"); }
	void FinalLoadedFromSaveGame() { NativeCall<void>(this, "APrimalDinoCharacter.FinalLoadedFromSaveGame"); }
	void RefreshBabyScaling() { NativeCall<void>(this, "APrimalDinoCharacter.RefreshBabyScaling"); }
	float GetXPMultiplier() { return NativeCall<float>(this, "APrimalDinoCharacter.GetXPMultiplier"); }
	bool UseHighQualityMovement() { return NativeCall<bool>(this, "APrimalDinoCharacter.UseHighQualityMovement"); }
	bool AllowPushOthers() { return NativeCall<bool>(this, "APrimalDinoCharacter.AllowPushOthers"); }
	bool IsVehicle() { return NativeCall<bool>(this, "APrimalDinoCharacter.IsVehicle"); }
	static void StaticRegisterNativesAPrimalDinoCharacter() { NativeCall<void>(nullptr, "APrimalDinoCharacter.StaticRegisterNativesAPrimalDinoCharacter"); }
	bool AllowWakingTame(APlayerController * ForPC) { return NativeCall<bool, APlayerController *>(this, "APrimalDinoCharacter.AllowWakingTame", ForPC); }
	float BlueprintAdjustOutputDamage(int AttackIndex, float OriginalDamageAmount, AActor * HitActor, TSubclassOf<UDamageType> * OutDamageType, float * OutDamageImpulse) { return NativeCall<float, int, float, AActor *, TSubclassOf<UDamageType> *, float *>(this, "APrimalDinoCharacter.BlueprintAdjustOutputDamage", AttackIndex, OriginalDamageAmount, HitActor, OutDamageType, OutDamageImpulse); }
	void BlueprintDrawFloatingHUD(AShooterHUD * HUD, float CenterX, float CenterY, float DrawScale) { NativeCall<void, AShooterHUD *, float, float, float>(this, "APrimalDinoCharacter.BlueprintDrawFloatingHUD", HUD, CenterX, CenterY, DrawScale); }
	float BlueprintExtraBabyScaling() { return NativeCall<float>(this, "APrimalDinoCharacter.BlueprintExtraBabyScaling"); }
	float BlueprintGetAttackWeight(int AttackIndex, float inputWeight, float distance, float attackRangeOffset, AActor * OtherTarget) { return NativeCall<float, int, float, float, float, AActor *>(this, "APrimalDinoCharacter.BlueprintGetAttackWeight", AttackIndex, inputWeight, distance, attackRangeOffset, OtherTarget); }
	bool BlueprintOverrideWantsToRun(bool bInputWantsToRun) { return NativeCall<bool, bool>(this, "APrimalDinoCharacter.BlueprintOverrideWantsToRun", bInputWantsToRun); }
	void BlueprintPlayDying(float KillingDamage, FDamageEvent * DamageEvent, APawn * InstigatingPawn, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, APawn *, AActor *>(this, "APrimalDinoCharacter.BlueprintPlayDying", KillingDamage, DamageEvent, InstigatingPawn, DamageCauser); }
	void BP_OnStartLandingNotify() { NativeCall<void>(this, "APrimalDinoCharacter.BP_OnStartLandingNotify"); }
	bool BPAllowClaiming(AShooterPlayerController * forPlayer) { return NativeCall<bool, AShooterPlayerController *>(this, "APrimalDinoCharacter.BPAllowClaiming", forPlayer); }
	bool BPCanAutodrag(APrimalCharacter * characterToDrag) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalDinoCharacter.BPCanAutodrag", characterToDrag); }
	bool BPCanTargetCorpse() { return NativeCall<bool>(this, "APrimalDinoCharacter.BPCanTargetCorpse"); }
	bool BPDesiredRotationIsLocalSpace() { return NativeCall<bool>(this, "APrimalDinoCharacter.BPDesiredRotationIsLocalSpace"); }
	void BPDinoARKDownloadedBegin() { NativeCall<void>(this, "APrimalDinoCharacter.BPDinoARKDownloadedBegin"); }
	void BPDinoARKDownloadedEnd() { NativeCall<void>(this, "APrimalDinoCharacter.BPDinoARKDownloadedEnd"); }
	void BPDoHarvestAttack(int harvestIndex) { NativeCall<void, int>(this, "APrimalDinoCharacter.BPDoHarvestAttack", harvestIndex); }
	void BPFedWakingTameEvent(APlayerController * ForPC) { NativeCall<void, APlayerController *>(this, "APrimalDinoCharacter.BPFedWakingTameEvent", ForPC); }
	FVector * BPGetHealthBarColor(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalDinoCharacter.BPGetHealthBarColor", result); }
	bool BPHandleUseButtonPress(AShooterPlayerController * RiderController) { return NativeCall<bool, AShooterPlayerController *>(this, "APrimalDinoCharacter.BPHandleUseButtonPress", RiderController); }
	bool BPModifyDesiredRotation(FRotator * InDesiredRotation, FRotator * OutDesiredRotation) { return NativeCall<bool, FRotator *, FRotator *>(this, "APrimalDinoCharacter.BPModifyDesiredRotation", InDesiredRotation, OutDesiredRotation); }
	float BPModifyHarvestingQuantity(float originalQuantity, TSubclassOf<UPrimalItem> resourceSelected) { return NativeCall<float, float, TSubclassOf<UPrimalItem>>(this, "APrimalDinoCharacter.BPModifyHarvestingQuantity", originalQuantity, resourceSelected); }
	void BPModifyHarvestingWeightsArray(TArray<float> * resourceWeightsIn, TArray<UPrimalItem *> * resourceItems, TArray<float> * resourceWeightsOut) { NativeCall<void, TArray<float> *, TArray<UPrimalItem *> *, TArray<float> *>(this, "APrimalDinoCharacter.BPModifyHarvestingWeightsArray", resourceWeightsIn, resourceItems, resourceWeightsOut); }
	void BPNotifyBabyAgeIncrement(float PreviousAge, float NewAge) { NativeCall<void, float, float>(this, "APrimalDinoCharacter.BPNotifyBabyAgeIncrement", PreviousAge, NewAge); }
	void BPNotifyCarriedDinoBabyAgeIncrement(APrimalDinoCharacter * AgingCarriedDino, float PreviousAge, float NewAge) { NativeCall<void, APrimalDinoCharacter *, float, float>(this, "APrimalDinoCharacter.BPNotifyCarriedDinoBabyAgeIncrement", AgingCarriedDino, PreviousAge, NewAge); }
	void BPNotifyMateBoostChanged() { NativeCall<void>(this, "APrimalDinoCharacter.BPNotifyMateBoostChanged"); }
	void BPNotifyStructurePlacedNearby(APrimalStructure * NewStructure) { NativeCall<void, APrimalStructure *>(this, "APrimalDinoCharacter.BPNotifyStructurePlacedNearby", NewStructure); }
	void BPOnClearMountedDino() { NativeCall<void>(this, "APrimalDinoCharacter.BPOnClearMountedDino"); }
	bool BPPreventRiding(AShooterCharacter * byPawn, bool bDontCheckDistance) { return NativeCall<bool, AShooterCharacter *, bool>(this, "APrimalDinoCharacter.BPPreventRiding", byPawn, bDontCheckDistance); }
	void FireProjectile(FVector Origin, FVector_NetQuantizeNormal ShootDir, bool bScaleProjDamageByDinoDamage) { NativeCall<void, FVector, FVector_NetQuantizeNormal, bool>(this, "APrimalDinoCharacter.FireProjectile", Origin, ShootDir, bScaleProjDamageByDinoDamage); }
	void InterruptLatching() { NativeCall<void>(this, "APrimalDinoCharacter.InterruptLatching"); }
	void NetUpdateDinoNameStrings(FString * NewTamerString, FString * NewTamedName) { NativeCall<void, FString *, FString *>(this, "APrimalDinoCharacter.NetUpdateDinoNameStrings", NewTamerString, NewTamedName); }
	void NetUpdateDinoOwnerData(FString * NewOwningPlayerName, int NewOwningPlayerID) { NativeCall<void, FString *, int>(this, "APrimalDinoCharacter.NetUpdateDinoOwnerData", NewOwningPlayerName, NewOwningPlayerID); }
	void OverrideRandomWanderLocation(FVector * originalDestination, FVector * inVec) { NativeCall<void, FVector *, FVector *>(this, "APrimalDinoCharacter.OverrideRandomWanderLocation", originalDestination, inVec); }
	void PlayHardEndChargingShake() { NativeCall<void>(this, "APrimalDinoCharacter.PlayHardEndChargingShake"); }
	void RidingTick() { NativeCall<void>(this, "APrimalDinoCharacter.RidingTick"); }
	void ServerClearRider(int OverrideUnboardDirection) { NativeCall<void, int>(this, "APrimalDinoCharacter.ServerClearRider", OverrideUnboardDirection); }
	void ServerRequestAttack(int attackIndex) { NativeCall<void, int>(this, "APrimalDinoCharacter.ServerRequestAttack", attackIndex); }
	void UpdateBabyCuddling(long double NewBabyNextCuddleTime, char NewBabyCuddleType, TSubclassOf<UPrimalItem> NewBabyCuddleFood) { NativeCall<void, long double, char, TSubclassOf<UPrimalItem>>(this, "APrimalDinoCharacter.UpdateBabyCuddling", NewBabyNextCuddleTime, NewBabyCuddleType, NewBabyCuddleFood); }
	void UpdateImprintingDetails(FString * NewImprinterName, unsigned __int64 NewImprinterPlayerDataID) { NativeCall<void, FString *, unsigned __int64>(this, "APrimalDinoCharacter.UpdateImprintingDetails", NewImprinterName, NewImprinterPlayerDataID); }
	void UpdateImprintingQuality(float NewImprintingQuality) { NativeCall<void, float>(this, "APrimalDinoCharacter.UpdateImprintingQuality", NewImprintingQuality); }
};

struct AShooterWeapon : AActor
{
	FieldValue<float> EquipTimeField() { return { this, "AShooterWeapon.EquipTime" }; }
	FieldValue<UAnimMontage *> OverrideProneInAnimField() { return { this, "AShooterWeapon.OverrideProneInAnim" }; }
	FieldValue<UAnimMontage *> OverrideProneOutAnimField() { return { this, "AShooterWeapon.OverrideProneOutAnim" }; }
	FieldValue<UAnimMontage *> OverrideJumpAnimField() { return { this, "AShooterWeapon.OverrideJumpAnim" }; }
	FieldValue<UAnimMontage *> OverrideLandedAnimField() { return { this, "AShooterWeapon.OverrideLandedAnim" }; }
	FieldValue<TArray<UAnimSequence *>> OverrideRiderAnimSequenceFromField() { return { this, "AShooterWeapon.OverrideRiderAnimSequenceFrom" }; }
	FieldValue<TArray<UAnimSequence *>> OverrideRiderAnimSequenceToField() { return { this, "AShooterWeapon.OverrideRiderAnimSequenceTo" }; }
	FieldValue<float> ItemDurabilityToConsumePerMeleeHitField() { return { this, "AShooterWeapon.ItemDurabilityToConsumePerMeleeHit" }; }
	FieldValue<float> AmmoIconsCountField() { return { this, "AShooterWeapon.AmmoIconsCount" }; }
	FieldValue<float> TargetingTooltipCheckRangeField() { return { this, "AShooterWeapon.TargetingTooltipCheckRange" }; }
	FieldValue<int> PrimaryClipIconOffsetField() { return { this, "AShooterWeapon.PrimaryClipIconOffset" }; }
	FieldValue<int> SecondaryClipIconOffsetField() { return { this, "AShooterWeapon.SecondaryClipIconOffset" }; }
	FieldValue<FVector2D> TargetingInfoTooltipPaddingField() { return { this, "AShooterWeapon.TargetingInfoTooltipPadding" }; }
	FieldValue<FVector2D> TargetingInfoTooltipScaleField() { return { this, "AShooterWeapon.TargetingInfoTooltipScale" }; }
	FieldValue<bool> bOnlyPassiveDurabilityWhenAccessoryActiveField() { return { this, "AShooterWeapon.bOnlyPassiveDurabilityWhenAccessoryActive" }; }
	FieldValue<bool> bDisableShooterOnElectricStormField() { return { this, "AShooterWeapon.bDisableShooterOnElectricStorm" }; }
	FieldValue<FName> OverrideAttachPointField() { return { this, "AShooterWeapon.OverrideAttachPoint" }; }
	FieldValue<FVector> FPVRelativeLocationField() { return { this, "AShooterWeapon.FPVRelativeLocation" }; }
	FieldValue<FRotator> FPVRelativeRotationField() { return { this, "AShooterWeapon.FPVRelativeRotation" }; }
	FieldValue<FVector> FPVRelativeLocation_TargetingField() { return { this, "AShooterWeapon.FPVRelativeLocation_Targeting" }; }
	FieldValue<FRotator> FPVRelativeRotation_TargetingField() { return { this, "AShooterWeapon.FPVRelativeRotation_Targeting" }; }
	FieldValue<float> FPVEnterTargetingInterpSpeedField() { return { this, "AShooterWeapon.FPVEnterTargetingInterpSpeed" }; }
	FieldValue<float> FPVExitTargetingInterpSpeedField() { return { this, "AShooterWeapon.FPVExitTargetingInterpSpeed" }; }
	FieldValue<float> EndDoMeleeSwingTimeField() { return { this, "AShooterWeapon.EndDoMeleeSwingTime" }; }
	FieldValue<FRotator> FPVLookAtMaximumOffsetField() { return { this, "AShooterWeapon.FPVLookAtMaximumOffset" }; }
	FieldValue<FRotator> FPVLookAtSpeedBaseField() { return { this, "AShooterWeapon.FPVLookAtSpeedBase" }; }
	FieldValue<FRotator> FPVLookAtInterpSpeedField() { return { this, "AShooterWeapon.FPVLookAtInterpSpeed" }; }
	FieldValue<FRotator> FPVLookAtMaximumOffset_TargetingField() { return { this, "AShooterWeapon.FPVLookAtMaximumOffset_Targeting" }; }
	FieldValue<FRotator> FPVLookAtSpeedBase_TargetingField() { return { this, "AShooterWeapon.FPVLookAtSpeedBase_Targeting" }; }
	FieldValue<FRotator> FPVLookAtInterpSpeed_TargetingField() { return { this, "AShooterWeapon.FPVLookAtInterpSpeed_Targeting" }; }
	FieldValue<FVector> FPVImmobilizedLocationOffsetField() { return { this, "AShooterWeapon.FPVImmobilizedLocationOffset" }; }
	FieldValue<FRotator> FPVImmobilizedRotationOffsetField() { return { this, "AShooterWeapon.FPVImmobilizedRotationOffset" }; }
	FieldValue<float> FPVImmobilizedInterpSpeedField() { return { this, "AShooterWeapon.FPVImmobilizedInterpSpeed" }; }
	FieldValue<bool> bUseBlueprintAnimNotificationsField() { return { this, "AShooterWeapon.bUseBlueprintAnimNotifications" }; }
	FieldValue<TArray<FName>> MeleeSwingSocketsField() { return { this, "AShooterWeapon.MeleeSwingSockets" }; }
	FieldValue<float> AllowMeleeTimeBeforeAnimationEndField() { return { this, "AShooterWeapon.AllowMeleeTimeBeforeAnimationEnd" }; }
	FieldValue<UPrimalItem *> AssociatedPrimalItemField() { return { this, "AShooterWeapon.AssociatedPrimalItem" }; }
	FieldValue<bool> bCanBeUsedAsEquipmentField() { return { this, "AShooterWeapon.bCanBeUsedAsEquipment" }; }
	FieldValue<FItemNetInfo> AssociatedItemNetInfoField() { return { this, "AShooterWeapon.AssociatedItemNetInfo" }; }
	FieldValue<FWeaponData> WeaponConfigField() { return { this, "AShooterWeapon.WeaponConfig" }; }
	FieldValue<TSubclassOf<UPrimalItem>> WeaponAmmoItemTemplateField() { return { this, "AShooterWeapon.WeaponAmmoItemTemplate" }; }
	FieldValue<long double> NextAllowedMeleeTimeField() { return { this, "AShooterWeapon.NextAllowedMeleeTime" }; }
	FieldValue<TArray<FVector>> LastSocketPositionsField() { return { this, "AShooterWeapon.LastSocketPositions" }; }
	FieldValue<TArray<AActor *>> MeleeSwingHurtListField() { return { this, "AShooterWeapon.MeleeSwingHurtList" }; }
	FieldValue<long double> LastFPVRenderTimeField() { return { this, "AShooterWeapon.LastFPVRenderTime" }; }
	FieldValue<FRotator> LastCameraRotationField() { return { this, "AShooterWeapon.LastCameraRotation" }; }
	FieldValue<FRotator> FPVAdditionalLookRotOffsetField() { return { this, "AShooterWeapon.FPVAdditionalLookRotOffset" }; }
	FieldValue<FVector> FPVLastLocOffsetField() { return { this, "AShooterWeapon.FPVLastLocOffset" }; }
	FieldValue<FVector> FPVLastVROffsetField() { return { this, "AShooterWeapon.FPVLastVROffset" }; }
	FieldValue<FVector> FPVRelativeLocationOffscreenOffsetField() { return { this, "AShooterWeapon.FPVRelativeLocationOffscreenOffset" }; }
	FieldValue<FRotator> FPVLastRotOffsetField() { return { this, "AShooterWeapon.FPVLastRotOffset" }; }
	FieldValue<AShooterCharacter *> MyPawnField() { return { this, "AShooterWeapon.MyPawn" }; }
	FieldValue<UAudioComponent *> FireACField() { return { this, "AShooterWeapon.FireAC" }; }
	FieldValue<FName> MuzzleAttachPointField() { return { this, "AShooterWeapon.MuzzleAttachPoint" }; }
	FieldValue<USoundCue *> FireSoundField() { return { this, "AShooterWeapon.FireSound" }; }
	FieldValue<USoundCue *> AltFireSoundField() { return { this, "AShooterWeapon.AltFireSound" }; }
	FieldValue<USoundCue *> FireFinishSoundField() { return { this, "AShooterWeapon.FireFinishSound" }; }
	FieldValue<USoundCue *> OutOfAmmoSoundField() { return { this, "AShooterWeapon.OutOfAmmoSound" }; }
	FieldValue<int> MeleeDamageAmountField() { return { this, "AShooterWeapon.MeleeDamageAmount" }; }
	FieldValue<float> TheMeleeSwingRadiusField() { return { this, "AShooterWeapon.TheMeleeSwingRadius" }; }
	FieldValue<float> MeleeDamageImpulseField() { return { this, "AShooterWeapon.MeleeDamageImpulse" }; }
	FieldValue<UAnimMontage *> WeaponMesh3PReloadAnimField() { return { this, "AShooterWeapon.WeaponMesh3PReloadAnim" }; }
	FieldValue<USoundCue *> EquipSoundField() { return { this, "AShooterWeapon.EquipSound" }; }
	FieldValue<UAnimMontage *> WeaponMesh3PFireAnimField() { return { this, "AShooterWeapon.WeaponMesh3PFireAnim" }; }
	FieldValue<float> FPVMoveOffscreenWhenTurningMaxMoveWeaponSpeedField() { return { this, "AShooterWeapon.FPVMoveOffscreenWhenTurningMaxMoveWeaponSpeed" }; }
	FieldValue<float> FPVMoveOffscreenWhenTurningMinMoveWeaponSpeedField() { return { this, "AShooterWeapon.FPVMoveOffscreenWhenTurningMinMoveWeaponSpeed" }; }
	FieldValue<float> FPVMoveOffscreenWhenTurningMinViewRotSpeedField() { return { this, "AShooterWeapon.FPVMoveOffscreenWhenTurningMinViewRotSpeed" }; }
	FieldValue<float> FPVMoveOffscreenWhenTurningMaxViewRotSpeedField() { return { this, "AShooterWeapon.FPVMoveOffscreenWhenTurningMaxViewRotSpeed" }; }
	FieldValue<float> FPVMoveOffscreenIdleRestoreIntervalField() { return { this, "AShooterWeapon.FPVMoveOffscreenIdleRestoreInterval" }; }
	FieldValue<float> FPVMoveOffscreenIdleRestoreSpeedField() { return { this, "AShooterWeapon.FPVMoveOffscreenIdleRestoreSpeed" }; }
	FieldValue<float> FPVMoveOffscreenWhenTurningMaxOffsetField() { return { this, "AShooterWeapon.FPVMoveOffscreenWhenTurningMaxOffset" }; }
	FieldValue<long double> FPVStoppedTurningTimeField() { return { this, "AShooterWeapon.FPVStoppedTurningTime" }; }
	FieldValue<float> ItemDestructionUnequipWeaponDelayField() { return { this, "AShooterWeapon.ItemDestructionUnequipWeaponDelay" }; }
	FieldValue<EWeaponState::Type> CurrentStateField() { return { this, "AShooterWeapon.CurrentState" }; }
	FieldValue<long double> LastFireTimeField() { return { this, "AShooterWeapon.LastFireTime" }; }
	FieldValue<int> CurrentAmmoField() { return { this, "AShooterWeapon.CurrentAmmo" }; }
	FieldValue<int> CurrentAmmoInClipField() { return { this, "AShooterWeapon.CurrentAmmoInClip" }; }
	FieldValue<bool> bReplicateCurrentAmmoInClipToNonOwnersField() { return { this, "AShooterWeapon.bReplicateCurrentAmmoInClipToNonOwners" }; }
	FieldValue<bool> bUseBPAdjustAmmoPerShotField() { return { this, "AShooterWeapon.bUseBPAdjustAmmoPerShot" }; }
	FieldValue<FName> FPVAccessoryToggleComponentField() { return { this, "AShooterWeapon.FPVAccessoryToggleComponent" }; }
	FieldValue<FName> TPVAccessoryToggleComponentField() { return { this, "AShooterWeapon.TPVAccessoryToggleComponent" }; }
	FieldValue<float> TimeToAutoReloadField() { return { this, "AShooterWeapon.TimeToAutoReload" }; }
	FieldValue<USoundBase *> ToggleAccessorySoundField() { return { this, "AShooterWeapon.ToggleAccessorySound" }; }
	FieldValue<int> FiredLastNoAmmoShotField() { return { this, "AShooterWeapon.FiredLastNoAmmoShot" }; }
	FieldValue<long double> LastNotifyShotTimeField() { return { this, "AShooterWeapon.LastNotifyShotTime" }; }
	FieldValue<TSubclassOf<UDamageType>> MeleeDamageTypeField() { return { this, "AShooterWeapon.MeleeDamageType" }; }
	FieldValue<FVector> VRTargetingModelOffsetField() { return { this, "AShooterWeapon.VRTargetingModelOffset" }; }
	FieldValue<FVector> VRTargetingAimOriginOffsetField() { return { this, "AShooterWeapon.VRTargetingAimOriginOffset" }; }
	FieldValue<UMaterialInterface *> ScopeOverlayMIField() { return { this, "AShooterWeapon.ScopeOverlayMI" }; }
	FieldValue<UMaterialInterface *> ScopeCrosshairMIField() { return { this, "AShooterWeapon.ScopeCrosshairMI" }; }
	FieldValue<float> ScopeCrosshairSizeField() { return { this, "AShooterWeapon.ScopeCrosshairSize" }; }
	FieldValue<FName> ScopeCrosshairColorParameterField() { return { this, "AShooterWeapon.ScopeCrosshairColorParameter" }; }
	FieldValue<float> MinItemDurabilityPercentageForShotField() { return { this, "AShooterWeapon.MinItemDurabilityPercentageForShot" }; }
	FieldValue<float> OverrideTargetingFOVField() { return { this, "AShooterWeapon.OverrideTargetingFOV" }; }
	FieldValue<float> TargetingDelayTimeField() { return { this, "AShooterWeapon.TargetingDelayTime" }; }
	FieldValue<float> TargetingFOVInterpSpeedField() { return { this, "AShooterWeapon.TargetingFOVInterpSpeed" }; }
	FieldValue<float> AimDriftYawAngleField() { return { this, "AShooterWeapon.AimDriftYawAngle" }; }
	FieldValue<float> AimDriftPitchAngleField() { return { this, "AShooterWeapon.AimDriftPitchAngle" }; }
	FieldValue<float> AimDriftYawFrequencyField() { return { this, "AShooterWeapon.AimDriftYawFrequency" }; }
	FieldValue<float> AimDriftPitchFrequencyField() { return { this, "AShooterWeapon.AimDriftPitchFrequency" }; }
	FieldValue<UAnimMontage *> AlternateInventoryEquipAnimField() { return { this, "AShooterWeapon.AlternateInventoryEquipAnim" }; }
	FieldValue<float> MeleeHitRandomChanceToDestroyItemField() { return { this, "AShooterWeapon.MeleeHitRandomChanceToDestroyItem" }; }
	FieldValue<float> GlobalFireCameraShakeScaleField() { return { this, "AShooterWeapon.GlobalFireCameraShakeScale" }; }
	FieldValue<float> DurabilityCostToEquipField() { return { this, "AShooterWeapon.DurabilityCostToEquip" }; }
	FieldValue<float> PassiveDurabilityCostPerIntervalField() { return { this, "AShooterWeapon.PassiveDurabilityCostPerInterval" }; }
	FieldValue<float> PassiveDurabilityCostIntervalField() { return { this, "AShooterWeapon.PassiveDurabilityCostInterval" }; }
	FieldValue<float> GlobalFireCameraShakeScaleTargetingField() { return { this, "AShooterWeapon.GlobalFireCameraShakeScaleTargeting" }; }
	FieldValue<float> MeleeCameraShakeSpeedScaleField() { return { this, "AShooterWeapon.MeleeCameraShakeSpeedScale" }; }
	FieldValue<float> ReloadCameraShakeSpeedScaleField() { return { this, "AShooterWeapon.ReloadCameraShakeSpeedScale" }; }
	FieldValue<float> MeleeConsumesStaminaField() { return { this, "AShooterWeapon.MeleeConsumesStamina" }; }
	FieldValue<float> HypoThermiaInsulationField() { return { this, "AShooterWeapon.HypoThermiaInsulation" }; }
	FieldValue<float> HyperThermiaInsulationField() { return { this, "AShooterWeapon.HyperThermiaInsulation" }; }
	FieldValue<float> InsulationRangeField() { return { this, "AShooterWeapon.InsulationRange" }; }
	FieldValue<long double> LastDurabilityConsumptionTimeField() { return { this, "AShooterWeapon.LastDurabilityConsumptionTime" }; }
	FieldValue<bool> bLastMeleeHitField() { return { this, "AShooterWeapon.bLastMeleeHit" }; }
	FieldValue<bool> bLastMeleeHitStationaryField() { return { this, "AShooterWeapon.bLastMeleeHitStationary" }; }
	FieldValue<bool> bClientAlreadyReloadedField() { return { this, "AShooterWeapon.bClientAlreadyReloaded" }; }
	FieldValue<float> AutoReloadTimerField() { return { this, "AShooterWeapon.AutoReloadTimer" }; }
	FieldValue<bool> bConsumedDurabilityForThisMeleeHitField() { return { this, "AShooterWeapon.bConsumedDurabilityForThisMeleeHit" }; }
	FieldValue<USoundCue *> TargetingSoundField() { return { this, "AShooterWeapon.TargetingSound" }; }
	FieldValue<USoundCue *> UntargetingSoundField() { return { this, "AShooterWeapon.UntargetingSound" }; }
	FieldValue<float> FPVMeleeTraceFXRangeField() { return { this, "AShooterWeapon.FPVMeleeTraceFXRange" }; }
	FieldValue<float> MeleeAttackHarvetUsableComponentsRadiusField() { return { this, "AShooterWeapon.MeleeAttackHarvetUsableComponentsRadius" }; }
	FieldValue<float> MeleeAttackUsableHarvestDamageMultiplierField() { return { this, "AShooterWeapon.MeleeAttackUsableHarvestDamageMultiplier" }; }
	FieldArray<bool, 6> bColorizeRegionsField() { return { this, "AShooterWeapon.bColorizeRegions" }; }
	FieldValue<UAnimMontage *> TPVForcePlayAnimField() { return { this, "AShooterWeapon.TPVForcePlayAnim" }; }
	FieldValue<bool> bPreventOpeningInventoryField() { return { this, "AShooterWeapon.bPreventOpeningInventory" }; }
	FieldValue<bool> bAllowUseOnSeatingStructureField() { return { this, "AShooterWeapon.bAllowUseOnSeatingStructure" }; }
	FieldValue<bool> bOnlyUseOnSeatingStructureField() { return { this, "AShooterWeapon.bOnlyUseOnSeatingStructure" }; }
	FieldValue<bool> bBPDoClientCheckCanFireField() { return { this, "AShooterWeapon.bBPDoClientCheckCanFire" }; }
	FieldValue<bool> bRestrictTPVCameraYawField() { return { this, "AShooterWeapon.bRestrictTPVCameraYaw" }; }
	FieldValue<float> TPVCameraYawRangeField() { return { this, "AShooterWeapon.TPVCameraYawRange" }; }
	FieldValue<bool> bFoceSimulatedTickField() { return { this, "AShooterWeapon.bFoceSimulatedTick" }; }
	FieldValue<bool> bWasLastFireFromGamePadField() { return { this, "AShooterWeapon.bWasLastFireFromGamePad" }; }
	FieldValue<bool> bDisableWeaponCrosshairField() { return { this, "AShooterWeapon.bDisableWeaponCrosshair" }; }
	FieldValue<UStaticMesh *> DyePreviewMeshOverrideSMField() { return { this, "AShooterWeapon.DyePreviewMeshOverrideSM" }; }
	FieldValue<bool> bBPOverrideAspectRatioField() { return { this, "AShooterWeapon.bBPOverrideAspectRatio" }; }
	FieldValue<bool> bForceAllowMountedWeaponryField() { return { this, "AShooterWeapon.bForceAllowMountedWeaponry" }; }
	FieldValue<float> FireCameraShakeSpreadScaleExponentField() { return { this, "AShooterWeapon.FireCameraShakeSpreadScaleExponent" }; }
	FieldValue<float> FireCameraShakeSpreadScaleExponentLessThanField() { return { this, "AShooterWeapon.FireCameraShakeSpreadScaleExponentLessThan" }; }
	FieldValue<float> FireCameraShakeSpreadScaleMultiplierLessThanField() { return { this, "AShooterWeapon.FireCameraShakeSpreadScaleMultiplierLessThan" }; }
	FieldValue<float> FireCameraShakeSpreadScaleMultiplierField() { return { this, "AShooterWeapon.FireCameraShakeSpreadScaleMultiplier" }; }
	FieldValue<bool> bUseFireCameraShakeScaleField() { return { this, "AShooterWeapon.bUseFireCameraShakeScale" }; }
	FieldValue<bool> bForceTickWithNoControllerField() { return { this, "AShooterWeapon.bForceTickWithNoController" }; }
	FieldValue<float> CurrentFiringSpreadField() { return { this, "AShooterWeapon.CurrentFiringSpread" }; }
	FieldValue<TSubclassOf<APrimalBuff>> ScopedBuffField() { return { this, "AShooterWeapon.ScopedBuff" }; }
	FieldValue<TWeakObjectPtr<APrimalBuff>> MyScopedBuffField() { return { this, "AShooterWeapon.MyScopedBuff" }; }
	FieldValue<UAnimSequence *> OverrideTPVShieldAnimationField() { return { this, "AShooterWeapon.OverrideTPVShieldAnimation" }; }
	FieldValue<bool> bAllowTargetingDuringMeleeSwingField() { return { this, "AShooterWeapon.bAllowTargetingDuringMeleeSwing" }; }
	FieldValue<FVector> FPVMuzzleLocationOffsetField() { return { this, "AShooterWeapon.FPVMuzzleLocationOffset" }; }
	FieldValue<FVector> TPVMuzzleLocationOffsetField() { return { this, "AShooterWeapon.TPVMuzzleLocationOffset" }; }
	FieldValue<bool> bForceTPV_EquippedWhileRidingField() { return { this, "AShooterWeapon.bForceTPV_EquippedWhileRiding" }; }
	FieldValue<bool> bCutsEnemyGrapplingCableField() { return { this, "AShooterWeapon.bCutsEnemyGrapplingCable" }; }
	FieldValue<FVector> FPVInventoryReequipOffsetField() { return { this, "AShooterWeapon.FPVInventoryReequipOffset" }; }
	FieldValue<long double> LocalInventoryViewingSkippedEquipAnimTimeField() { return { this, "AShooterWeapon.LocalInventoryViewingSkippedEquipAnimTime" }; }
	FieldValue<float> DraggingOffsetInterpField() { return { this, "AShooterWeapon.DraggingOffsetInterp" }; }
	FieldValue<bool> bForceTPVCameraOffsetField() { return { this, "AShooterWeapon.bForceTPVCameraOffset" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bUseDinoRangeForTooltip() { return { this, "AShooterWeapon.bUseDinoRangeForTooltip" }; }
	BitFieldValue<bool, unsigned __int32> bFPVUsingImmobilizedTransform() { return { this, "AShooterWeapon.bFPVUsingImmobilizedTransform" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyUseFirstMeleeAnimWithShield() { return { this, "AShooterWeapon.bOnlyUseFirstMeleeAnimWithShield" }; }
	BitFieldValue<bool, unsigned __int32> bForceShowCrosshairWhileFiring() { return { this, "AShooterWeapon.bForceShowCrosshairWhileFiring" }; }
	BitFieldValue<bool, unsigned __int32> bIsFireActivelyHeld() { return { this, "AShooterWeapon.bIsFireActivelyHeld" }; }
	BitFieldValue<bool, unsigned __int32> bAllowSubmergedFiring() { return { this, "AShooterWeapon.bAllowSubmergedFiring" }; }
	BitFieldValue<bool, unsigned __int32> bIsInMeleeSwing() { return { this, "AShooterWeapon.bIsInMeleeSwing" }; }
	BitFieldValue<bool, unsigned __int32> bDoMeleeSwing() { return { this, "AShooterWeapon.bDoMeleeSwing" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingCameraAnimFPV() { return { this, "AShooterWeapon.bPlayingCameraAnimFPV" }; }
	BitFieldValue<bool, unsigned __int32> bIsWeaponBreaking() { return { this, "AShooterWeapon.bIsWeaponBreaking" }; }
	BitFieldValue<bool, unsigned __int32> bHideFPVMesh() { return { this, "AShooterWeapon.bHideFPVMesh" }; }
	BitFieldValue<bool, unsigned __int32> bForceTargeting() { return { this, "AShooterWeapon.bForceTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bCanAltFire() { return { this, "AShooterWeapon.bCanAltFire" }; }
	BitFieldValue<bool, unsigned __int32> bAltFireDoesMeleeAttack() { return { this, "AShooterWeapon.bAltFireDoesMeleeAttack" }; }
	BitFieldValue<bool, unsigned __int32> bAltFireDoesNotStopFire() { return { this, "AShooterWeapon.bAltFireDoesNotStopFire" }; }
	BitFieldValue<bool, unsigned __int32> bHideDamageSourceFromLogs() { return { this, "AShooterWeapon.bHideDamageSourceFromLogs" }; }
	BitFieldValue<bool, unsigned __int32> bUseTargetingFireAnim() { return { this, "AShooterWeapon.bUseTargetingFireAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseTargetingReloadAnim() { return { this, "AShooterWeapon.bUseTargetingReloadAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUsePartialReloadAnim() { return { this, "AShooterWeapon.bUsePartialReloadAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseEquipNoAmmoClipAnim() { return { this, "AShooterWeapon.bUseEquipNoAmmoClipAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseUnequipNoAmmoClipAnim() { return { this, "AShooterWeapon.bUseUnequipNoAmmoClipAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseMeleeNoAmmoClipAnim() { return { this, "AShooterWeapon.bUseMeleeNoAmmoClipAnim" }; }
	BitFieldValue<bool, unsigned __int32> bHideLeftArmFPV() { return { this, "AShooterWeapon.bHideLeftArmFPV" }; }
	BitFieldValue<bool, unsigned __int32> bLoopedMuzzleFX() { return { this, "AShooterWeapon.bLoopedMuzzleFX" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeHitUseMuzzleFX() { return { this, "AShooterWeapon.bMeleeHitUseMuzzleFX" }; }
	BitFieldValue<bool, unsigned __int32> bUsePostUpdateTickForFPVParticles() { return { this, "AShooterWeapon.bUsePostUpdateTickForFPVParticles" }; }
	BitFieldValue<bool, unsigned __int32> bFPVMoveOffscreenWhenTurning() { return { this, "AShooterWeapon.bFPVMoveOffscreenWhenTurning" }; }
	BitFieldValue<bool, unsigned __int32> bReloadAnimForceTickPoseOnServer() { return { this, "AShooterWeapon.bReloadAnimForceTickPoseOnServer" }; }
	BitFieldValue<bool, unsigned __int32> bLoopedFireSound() { return { this, "AShooterWeapon.bLoopedFireSound" }; }
	BitFieldValue<bool, unsigned __int32> bAllowTargetingWhileReloading() { return { this, "AShooterWeapon.bAllowTargetingWhileReloading" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeHitColorizesStructures() { return { this, "AShooterWeapon.bMeleeHitColorizesStructures" }; }
	BitFieldValue<bool, unsigned __int32> bLoopedFireAnim() { return { this, "AShooterWeapon.bLoopedFireAnim" }; }
	BitFieldValue<bool, unsigned __int32> bPlayingFireAnim() { return { this, "AShooterWeapon.bPlayingFireAnim" }; }
	BitFieldValue<bool, unsigned __int32> bFPVWasTurning() { return { this, "AShooterWeapon.bFPVWasTurning" }; }
	BitFieldValue<bool, unsigned __int32> bAutoRefire() { return { this, "AShooterWeapon.bAutoRefire" }; }
	BitFieldValue<bool, unsigned __int32> bConsumeAmmoOnUseAmmo() { return { this, "AShooterWeapon.bConsumeAmmoOnUseAmmo" }; }
	BitFieldValue<bool, unsigned __int32> bTargetUnTargetWithClick() { return { this, "AShooterWeapon.bTargetUnTargetWithClick" }; }
	BitFieldValue<bool, unsigned __int32> bDontActuallyConsumeItemAmmo() { return { this, "AShooterWeapon.bDontActuallyConsumeItemAmmo" }; }
	BitFieldValue<bool, unsigned __int32> bBPUseWeaponCanFire() { return { this, "AShooterWeapon.bBPUseWeaponCanFire" }; }
	BitFieldValue<bool, unsigned __int32> bIsEquipped() { return { this, "AShooterWeapon.bIsEquipped" }; }
	BitFieldValue<bool, unsigned __int32> bWantsToFire() { return { this, "AShooterWeapon.bWantsToFire" }; }
	BitFieldValue<bool, unsigned __int32> bWantsToAltFire() { return { this, "AShooterWeapon.bWantsToAltFire" }; }
	BitFieldValue<bool, unsigned __int32> bPendingReload() { return { this, "AShooterWeapon.bPendingReload" }; }
	BitFieldValue<bool, unsigned __int32> bPendingEquip() { return { this, "AShooterWeapon.bPendingEquip" }; }
	BitFieldValue<bool, unsigned __int32> bUnequipping() { return { this, "AShooterWeapon.bUnequipping" }; }
	BitFieldValue<bool, unsigned __int32> bNotifiedOutOfAmmo() { return { this, "AShooterWeapon.bNotifiedOutOfAmmo" }; }
	BitFieldValue<bool, unsigned __int32> bPlayedTargetingSound() { return { this, "AShooterWeapon.bPlayedTargetingSound" }; }
	BitFieldValue<bool, unsigned __int32> bUseAmmoOnFiring() { return { this, "AShooterWeapon.bUseAmmoOnFiring" }; }
	BitFieldValue<bool, unsigned __int32> bUseAmmoServerOnly() { return { this, "AShooterWeapon.bUseAmmoServerOnly" }; }
	BitFieldValue<bool, unsigned __int32> bListenToAppliedForeces() { return { this, "AShooterWeapon.bListenToAppliedForeces" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideAimOffsets() { return { this, "AShooterWeapon.bOverrideAimOffsets" }; }
	BitFieldValue<bool, unsigned __int32> bHasToggleableAccessory() { return { this, "AShooterWeapon.bHasToggleableAccessory" }; }
	BitFieldValue<bool, unsigned __int32> bToggleAccessoryUseAltMuzzleFX() { return { this, "AShooterWeapon.bToggleAccessoryUseAltMuzzleFX" }; }
	BitFieldValue<bool, unsigned __int32> bToggleAccessoryUseAltFireSound() { return { this, "AShooterWeapon.bToggleAccessoryUseAltFireSound" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanToggleAccessory() { return { this, "AShooterWeapon.bUseBPCanToggleAccessory" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnScoped() { return { this, "AShooterWeapon.bUseBPOnScoped" }; }
	BitFieldValue<bool, unsigned __int32> bIsDefaultWeapon() { return { this, "AShooterWeapon.bIsDefaultWeapon" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyAllowUseWhenRidingDino() { return { this, "AShooterWeapon.bOnlyAllowUseWhenRidingDino" }; }
	BitFieldValue<bool, unsigned __int32> bPrimaryFireDoesMeleeAttack() { return { this, "AShooterWeapon.bPrimaryFireDoesMeleeAttack" }; }
	BitFieldValue<bool, unsigned __int32> bIsAccessoryActive() { return { this, "AShooterWeapon.bIsAccessoryActive" }; }
	BitFieldValue<bool, unsigned __int32> bCanAccessoryBeSetOn() { return { this, "AShooterWeapon.bCanAccessoryBeSetOn" }; }
	BitFieldValue<bool, unsigned __int32> bConsumeAmmoItemOnReload() { return { this, "AShooterWeapon.bConsumeAmmoItemOnReload" }; }
	BitFieldValue<bool, unsigned __int32> bUseAutoReload() { return { this, "AShooterWeapon.bUseAutoReload" }; }
	BitFieldValue<bool, unsigned __int32> bWantsToAutoReload() { return { this, "AShooterWeapon.bWantsToAutoReload" }; }
	BitFieldValue<bool, unsigned __int32> bHasPlayedReload() { return { this, "AShooterWeapon.bHasPlayedReload" }; }
	BitFieldValue<bool, unsigned __int32> bNetLoopedSimulatingWeaponFire() { return { this, "AShooterWeapon.bNetLoopedSimulatingWeaponFire" }; }
	BitFieldValue<bool, unsigned __int32> bClientLoopingSimulateWeaponFire() { return { this, "AShooterWeapon.bClientLoopingSimulateWeaponFire" }; }
	BitFieldValue<bool, unsigned __int32> bBPHandleMeleeAttack() { return { this, "AShooterWeapon.bBPHandleMeleeAttack" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPShouldDealDamage() { return { this, "AShooterWeapon.bUseBPShouldDealDamage" }; }
	BitFieldValue<bool, unsigned __int32> bDoesntUsePrimalItem() { return { this, "AShooterWeapon.bDoesntUsePrimalItem" }; }
	BitFieldValue<bool, unsigned __int32> bUseCanAccessoryBeSetOn() { return { this, "AShooterWeapon.bUseCanAccessoryBeSetOn" }; }
	BitFieldValue<bool, unsigned __int32> bLoopingSimulateWeaponFire() { return { this, "AShooterWeapon.bLoopingSimulateWeaponFire" }; }
	BitFieldValue<bool, unsigned __int32> bFiredFirstBurstShot() { return { this, "AShooterWeapon.bFiredFirstBurstShot" }; }
	BitFieldValue<bool, unsigned __int32> bClientTriggersHandleFiring() { return { this, "AShooterWeapon.bClientTriggersHandleFiring" }; }
	BitFieldValue<bool, unsigned __int32> bAllowUseHarvesting() { return { this, "AShooterWeapon.bAllowUseHarvesting" }; }
	BitFieldValue<bool, unsigned __int32> bPreventItemColors() { return { this, "AShooterWeapon.bPreventItemColors" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPGetSelectedMeleeAttackAnim() { return { this, "AShooterWeapon.bUseBPGetSelectedMeleeAttackAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPWeaponDealDamage() { return { this, "AShooterWeapon.bUseBPWeaponDealDamage" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOnWeaponAnimPlayedNotify() { return { this, "AShooterWeapon.bUseBPOnWeaponAnimPlayedNotify" }; }
	BitFieldValue<bool, unsigned __int32> bColorCrosshairBasedOnTarget() { return { this, "AShooterWeapon.bColorCrosshairBasedOnTarget" }; }
	BitFieldValue<bool, unsigned __int32> bAllowTargeting() { return { this, "AShooterWeapon.bAllowTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bAllowDropAndPickup() { return { this, "AShooterWeapon.bAllowDropAndPickup" }; }
	BitFieldValue<bool, unsigned __int32> bApplyAimDriftWhenTargeting() { return { this, "AShooterWeapon.bApplyAimDriftWhenTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bUseScopeOverlay() { return { this, "AShooterWeapon.bUseScopeOverlay" }; }
	BitFieldValue<bool, unsigned __int32> bHideFPVMeshWhileTargeting() { return { this, "AShooterWeapon.bHideFPVMeshWhileTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bGamepadRightIsSecondaryAction() { return { this, "AShooterWeapon.bGamepadRightIsSecondaryAction" }; }
	BitFieldValue<bool, unsigned __int32> bGamepadLeftIsPrimaryFire() { return { this, "AShooterWeapon.bGamepadLeftIsPrimaryFire" }; }
	BitFieldValue<bool, unsigned __int32> bDirectPrimaryFireToAltFire() { return { this, "AShooterWeapon.bDirectPrimaryFireToAltFire" }; }
	BitFieldValue<bool, unsigned __int32> bCanFire() { return { this, "AShooterWeapon.bCanFire" }; }
	BitFieldValue<bool, unsigned __int32> bForceTargetingOnDino() { return { this, "AShooterWeapon.bForceTargetingOnDino" }; }
	BitFieldValue<bool, unsigned __int32> bDirectTargetingToPrimaryFire() { return { this, "AShooterWeapon.bDirectTargetingToPrimaryFire" }; }
	BitFieldValue<bool, unsigned __int32> bDirectTargetingToAltFire() { return { this, "AShooterWeapon.bDirectTargetingToAltFire" }; }
	BitFieldValue<bool, unsigned __int32> bDirectTargetingToSecondaryAction() { return { this, "AShooterWeapon.bDirectTargetingToSecondaryAction" }; }
	BitFieldValue<bool, unsigned __int32> bPreventEquippingUnderwater() { return { this, "AShooterWeapon.bPreventEquippingUnderwater" }; }
	BitFieldValue<bool, unsigned __int32> bUseTPVWeaponMeshMeleeSockets() { return { this, "AShooterWeapon.bUseTPVWeaponMeshMeleeSockets" }; }
	BitFieldValue<bool, unsigned __int32> bTargetingForceTraceFloatingHUD() { return { this, "AShooterWeapon.bTargetingForceTraceFloatingHUD" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRunning() { return { this, "AShooterWeapon.bAllowRunning" }; }
	BitFieldValue<bool, unsigned __int32> bAllowUseWhileRidingDino() { return { this, "AShooterWeapon.bAllowUseWhileRidingDino" }; }
	BitFieldValue<bool, unsigned __int32> bSupportsOffhandShield() { return { this, "AShooterWeapon.bSupportsOffhandShield" }; }
	BitFieldValue<bool, unsigned __int32> bMeleeAttackHarvetUsableComponents() { return { this, "AShooterWeapon.bMeleeAttackHarvetUsableComponents" }; }
	BitFieldValue<bool, unsigned __int32> bAllowSettingColorizeRegions() { return { this, "AShooterWeapon.bAllowSettingColorizeRegions" }; }
	BitFieldValue<bool, unsigned __int32> bAttemptToDyeWithMeleeAttack() { return { this, "AShooterWeapon.bAttemptToDyeWithMeleeAttack" }; }
	BitFieldValue<bool, unsigned __int32> bOnlyDamagePawns() { return { this, "AShooterWeapon.bOnlyDamagePawns" }; }
	BitFieldValue<bool, unsigned __int32> bUseCharacterMeleeDamageModifier() { return { this, "AShooterWeapon.bUseCharacterMeleeDamageModifier" }; }
	BitFieldValue<bool, unsigned __int32> bConsumeZoomInOut() { return { this, "AShooterWeapon.bConsumeZoomInOut" }; }
	BitFieldValue<bool, unsigned __int32> bClipScopeInY() { return { this, "AShooterWeapon.bClipScopeInY" }; }
	BitFieldValue<bool, unsigned __int32> bScopeFullscreen() { return { this, "AShooterWeapon.bScopeFullscreen" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRunningWhileFiring() { return { this, "AShooterWeapon.bAllowRunningWhileFiring" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRunningWhileReloading() { return { this, "AShooterWeapon.bAllowRunningWhileReloading" }; }
	BitFieldValue<bool, unsigned __int32> bAllowRunningWhileMeleeAttacking() { return { this, "AShooterWeapon.bAllowRunningWhileMeleeAttacking" }; }
	BitFieldValue<bool, unsigned __int32> bColorizeMuzzleFX() { return { this, "AShooterWeapon.bColorizeMuzzleFX" }; }
	BitFieldValue<bool, unsigned __int32> bForceFirstPersonWhileTargeting() { return { this, "AShooterWeapon.bForceFirstPersonWhileTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPStartEquippedNotify() { return { this, "AShooterWeapon.bUseBPStartEquippedNotify" }; }
	BitFieldValue<bool, unsigned __int32> bDirectPrimaryFireToSecondaryAction() { return { this, "AShooterWeapon.bDirectPrimaryFireToSecondaryAction" }; }
	BitFieldValue<bool, unsigned __int32> bOverrideStandingAnim() { return { this, "AShooterWeapon.bOverrideStandingAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseCustomSeatedAnim() { return { this, "AShooterWeapon.bUseCustomSeatedAnim" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPForceTPVTargetingAnimation() { return { this, "AShooterWeapon.bUseBPForceTPVTargetingAnimation" }; }
	BitFieldValue<bool, unsigned __int32> bForcePreventUseWhileRidingDino() { return { this, "AShooterWeapon.bForcePreventUseWhileRidingDino" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPPreventSwitchingWeapon() { return { this, "AShooterWeapon.bUseBPPreventSwitchingWeapon" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPCanEquip() { return { this, "AShooterWeapon.bUseBPCanEquip" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPRemainEquipped() { return { this, "AShooterWeapon.bUseBPRemainEquipped" }; }
	BitFieldValue<bool, unsigned __int32> bIsInDestruction() { return { this, "AShooterWeapon.bIsInDestruction" }; }
	BitFieldValue<bool, unsigned __int32> bForceReloadOnDestruction() { return { this, "AShooterWeapon.bForceReloadOnDestruction" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPModifyFOV() { return { this, "AShooterWeapon.bUseBPModifyFOV" }; }
	BitFieldValue<bool, unsigned __int32> bServerIgnoreCheckCanFire() { return { this, "AShooterWeapon.bServerIgnoreCheckCanFire" }; }
	BitFieldValue<bool, unsigned __int32> bForceAlwaysPlayEquipAnim() { return { this, "AShooterWeapon.bForceAlwaysPlayEquipAnim" }; }
	BitFieldValue<bool, unsigned __int32> bLastMeleeAttacked() { return { this, "AShooterWeapon.bLastMeleeAttacked" }; }

	// Functions

	static UClass * StaticClass() { return NativeCall<UClass *>(nullptr, "AShooterWeapon.StaticClass"); }
	USceneComponent * FindComponentByName(FName ComponentName) { return NativeCall<USceneComponent *, FName>(this, "AShooterWeapon.FindComponentByName", ComponentName); }
	void ZoomOut() { NativeCall<void>(this, "AShooterWeapon.ZoomOut"); }
	void ZoomIn() { NativeCall<void>(this, "AShooterWeapon.ZoomIn"); }
	void PostInitializeComponents() { NativeCall<void>(this, "AShooterWeapon.PostInitializeComponents"); }
	void DrawHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "AShooterWeapon.DrawHUD", HUD); }
	void UpdateFirstPersonMeshes(bool bIsFirstPerson) { NativeCall<void, bool>(this, "AShooterWeapon.UpdateFirstPersonMeshes", bIsFirstPerson); }
	void Destroyed() { NativeCall<void>(this, "AShooterWeapon.Destroyed"); }
	void OnEquip() { NativeCall<void>(this, "AShooterWeapon.OnEquip"); }
	void OnEquipFinished() { NativeCall<void>(this, "AShooterWeapon.OnEquipFinished"); }
	void StartUnequip_Implementation() { NativeCall<void>(this, "AShooterWeapon.StartUnequip_Implementation"); }
	void PlayUnequipAnimation() { NativeCall<void>(this, "AShooterWeapon.PlayUnequipAnimation"); }
	void AttachMeshToPawn() { NativeCall<void>(this, "AShooterWeapon.AttachMeshToPawn"); }
	void ApplyPrimalItemSettingsToWeapon(bool bShallowUpdate) { NativeCall<void, bool>(this, "AShooterWeapon.ApplyPrimalItemSettingsToWeapon", bShallowUpdate); }
	void DetachMeshFromPawn() { NativeCall<void>(this, "AShooterWeapon.DetachMeshFromPawn"); }
	void StartFire(bool bFromGamepad) { NativeCall<void, bool>(this, "AShooterWeapon.StartFire", bFromGamepad); }
	void StopFire() { NativeCall<void>(this, "AShooterWeapon.StopFire"); }
	void StartAltFire() { NativeCall<void>(this, "AShooterWeapon.StartAltFire"); }
	void StartSecondaryAction() { NativeCall<void>(this, "AShooterWeapon.StartSecondaryAction"); }
	bool CanToggleAccessory() { return NativeCall<bool>(this, "AShooterWeapon.CanToggleAccessory"); }
	void ToggleAccessory() { NativeCall<void>(this, "AShooterWeapon.ToggleAccessory"); }
	void RefreshToggleAccessory() { NativeCall<void>(this, "AShooterWeapon.RefreshToggleAccessory"); }
	bool CanMeleeAttack() { return NativeCall<bool>(this, "AShooterWeapon.CanMeleeAttack"); }
	void DoMeleeAttack() { NativeCall<void>(this, "AShooterWeapon.DoMeleeAttack"); }
	void StopAltFire() { NativeCall<void>(this, "AShooterWeapon.StopAltFire"); }
	void CheckForMeleeAttack() { NativeCall<void>(this, "AShooterWeapon.CheckForMeleeAttack"); }
	void StopCheckForMeleeAttack() { NativeCall<void>(this, "AShooterWeapon.StopCheckForMeleeAttack"); }
	bool CanRun() { return NativeCall<bool>(this, "AShooterWeapon.CanRun"); }
	void StartReload(bool bFromReplication) { NativeCall<void, bool>(this, "AShooterWeapon.StartReload", bFromReplication); }
	void ClearClientReload() { NativeCall<void>(this, "AShooterWeapon.ClearClientReload"); }
	float PlayReloadAnimation() { return NativeCall<float>(this, "AShooterWeapon.PlayReloadAnimation"); }
	void StopReloadAnimation() { NativeCall<void>(this, "AShooterWeapon.StopReloadAnimation"); }
	void ServerStartFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStartFire_Implementation"); }
	void ServerStopFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStopFire_Implementation"); }
	void ServerStartAltFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStartAltFire_Implementation"); }
	void ServerStopAltFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStopAltFire_Implementation"); }
	void ServerStartSecondaryAction_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStartSecondaryAction_Implementation"); }
	void ServerStopSecondaryAction_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStopSecondaryAction_Implementation"); }
	void ServerToggleAccessory_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerToggleAccessory_Implementation"); }
	void ServerStartReload_Implementation() { NativeCall<void>(this, "AShooterWeapon.ServerStartReload_Implementation"); }
	void ClientStartReload_Implementation() { NativeCall<void>(this, "AShooterWeapon.ClientStartReload_Implementation"); }
	bool CanFire(bool bForceAllowSubmergedFiring) { return NativeCall<bool, bool>(this, "AShooterWeapon.CanFire", bForceAllowSubmergedFiring); }
	bool AllowFiring() { return NativeCall<bool>(this, "AShooterWeapon.AllowFiring"); }
	bool CanReload() { return NativeCall<bool>(this, "AShooterWeapon.CanReload"); }
	void UseAmmo(int UseAmmoAmountOverride) { NativeCall<void, int>(this, "AShooterWeapon.UseAmmo", UseAmmoAmountOverride); }
	float GetFireCameraShakeScale() { return NativeCall<float>(this, "AShooterWeapon.GetFireCameraShakeScale"); }
	void HandleFiring(bool bSentFromClient) { NativeCall<void, bool>(this, "AShooterWeapon.HandleFiring", bSentFromClient); }
	bool CanTarget() { return NativeCall<bool>(this, "AShooterWeapon.CanTarget"); }
	float GetConsumeDurabilityPerShot() { return NativeCall<float>(this, "AShooterWeapon.GetConsumeDurabilityPerShot"); }
	void ReloadWeapon() { NativeCall<void>(this, "AShooterWeapon.ReloadWeapon"); }
	void RefreshAmmoItemQuantity() { NativeCall<void>(this, "AShooterWeapon.RefreshAmmoItemQuantity"); }
	void ConsumeAmmoItem(int Quantity) { NativeCall<void, int>(this, "AShooterWeapon.ConsumeAmmoItem", Quantity); }
	void SetWeaponState(EWeaponState::Type NewState) { NativeCall<void, EWeaponState::Type>(this, "AShooterWeapon.SetWeaponState", NewState); }
	void DetermineWeaponState() { NativeCall<void>(this, "AShooterWeapon.DetermineWeaponState"); }
	void SetAutoReload() { NativeCall<void>(this, "AShooterWeapon.SetAutoReload"); }
	void OnBurstStarted() { NativeCall<void>(this, "AShooterWeapon.OnBurstStarted"); }
	void OnBurstFinished() { NativeCall<void>(this, "AShooterWeapon.OnBurstFinished"); }
	void ClientStopSimulatingWeaponFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ClientStopSimulatingWeaponFire_Implementation"); }
	void ClientSimulateWeaponFire_Implementation() { NativeCall<void>(this, "AShooterWeapon.ClientSimulateWeaponFire_Implementation"); }
	UAudioComponent * PlayWeaponSound(USoundCue * Sound) { return NativeCall<UAudioComponent *, USoundCue *>(this, "AShooterWeapon.PlayWeaponSound", Sound); }
	float PlayCameraAnimationFPV(UAnimMontage * Animation1P) { return NativeCall<float, UAnimMontage *>(this, "AShooterWeapon.PlayCameraAnimationFPV", Animation1P); }
	void StopCameraAnimationFPV() { NativeCall<void>(this, "AShooterWeapon.StopCameraAnimationFPV"); }
	void ClientPlayShieldHitAnim_Implementation() { NativeCall<void>(this, "AShooterWeapon.ClientPlayShieldHitAnim_Implementation"); }
	FVector * GetAdjustedAim(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AShooterWeapon.GetAdjustedAim", result); }
	FVector * GetCameraDamageStartLocation(FVector * result, FVector * AimDir) { return NativeCall<FVector *, FVector *, FVector *>(this, "AShooterWeapon.GetCameraDamageStartLocation", result, AimDir); }
	FVector * GetShootingCameraLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AShooterWeapon.GetShootingCameraLocation", result); }
	FVector * GetMuzzleLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AShooterWeapon.GetMuzzleLocation", result); }
	FHitResult * WeaponTrace(FHitResult * result, FVector * StartTrace, FVector * EndTrace) { return NativeCall<FHitResult *, FHitResult *, FVector *, FVector *>(this, "AShooterWeapon.WeaponTrace", result, StartTrace, EndTrace); }
	void WeaponTraceHits(TArray<FHitResult> * HitResults, FVector * StartTrace, FVector * EndTrace) { NativeCall<void, TArray<FHitResult> *, FVector *, FVector *>(this, "AShooterWeapon.WeaponTraceHits", HitResults, StartTrace, EndTrace); }
	void SetOwningPawn(AShooterCharacter * NewOwner) { NativeCall<void, AShooterCharacter *>(this, "AShooterWeapon.SetOwningPawn", NewOwner); }
	void OnCameraUpdate(FVector * CameraLocation, FRotator * CameraRotation, FVector * WeaponBob) { NativeCall<void, FVector *, FRotator *, FVector *>(this, "AShooterWeapon.OnCameraUpdate", CameraLocation, CameraRotation, WeaponBob); }
	void SimulateWeaponFire() { NativeCall<void>(this, "AShooterWeapon.SimulateWeaponFire"); }
	void StartMuzzleFX() { NativeCall<void>(this, "AShooterWeapon.StartMuzzleFX"); }
	void StopMuzzleFX() { NativeCall<void>(this, "AShooterWeapon.StopMuzzleFX"); }
	void PlayFireAnimation() { NativeCall<void>(this, "AShooterWeapon.PlayFireAnimation"); }
	void StopSimulatingWeaponFire() { NativeCall<void>(this, "AShooterWeapon.StopSimulatingWeaponFire"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AShooterWeapon.GetLifetimeReplicatedProps", OutLifetimeProps); }
	bool HasInfiniteAmmo() { return NativeCall<bool>(this, "AShooterWeapon.HasInfiniteAmmo"); }
	void StartMeleeSwing() { NativeCall<void>(this, "AShooterWeapon.StartMeleeSwing"); }
	void EndMeleeSwing() { NativeCall<void>(this, "AShooterWeapon.EndMeleeSwing"); }
	void EndDoMeleeSwing() { NativeCall<void>(this, "AShooterWeapon.EndDoMeleeSwing"); }
	bool AddToMeleeSwingHurtList(AActor * AnActor) { return NativeCall<bool, AActor *>(this, "AShooterWeapon.AddToMeleeSwingHurtList", AnActor); }
	bool ShouldDealDamage(AActor * TestActor) { return NativeCall<bool, AActor *>(this, "AShooterWeapon.ShouldDealDamage", TestActor); }
	void DealDamage(FHitResult * Impact, FVector * ShootDir, int DamageAmount, TSubclassOf<UDamageType> DamageType, float Impulse) { NativeCall<void, FHitResult *, FVector *, int, TSubclassOf<UDamageType>, float>(this, "AShooterWeapon.DealDamage", Impact, ShootDir, DamageAmount, DamageType, Impulse); }
	void TickMeleeSwing(float DeltaTime) { NativeCall<void, float>(this, "AShooterWeapon.TickMeleeSwing", DeltaTime); }
	void ClientStartMuzzleFX_Implementation() { NativeCall<void>(this, "AShooterWeapon.ClientStartMuzzleFX_Implementation"); }
	void CosumeMeleeHitDurability(float DurabilityConsumptionMultiplier) { NativeCall<void, float>(this, "AShooterWeapon.CosumeMeleeHitDurability", DurabilityConsumptionMultiplier); }
	void PlayWeaponBreakAnimation_Implementation() { NativeCall<void>(this, "AShooterWeapon.PlayWeaponBreakAnimation_Implementation"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "AShooterWeapon.Tick", DeltaSeconds); }
	void BeginPlay() { NativeCall<void>(this, "AShooterWeapon.BeginPlay"); }
	void LocalPossessed() { NativeCall<void>(this, "AShooterWeapon.LocalPossessed"); }
	bool IsLocallyOwned() { return NativeCall<bool>(this, "AShooterWeapon.IsLocallyOwned"); }
	void CheckItemAssocation() { NativeCall<void>(this, "AShooterWeapon.CheckItemAssocation"); }
	void OnRep_CurrentAmmoInClip() { NativeCall<void>(this, "AShooterWeapon.OnRep_CurrentAmmoInClip"); }
	void LoadedFromSaveGame() { NativeCall<void>(this, "AShooterWeapon.LoadedFromSaveGame"); }
	void PlayUseHarvestAnimation_Implementation() { NativeCall<void>(this, "AShooterWeapon.PlayUseHarvestAnimation_Implementation"); }
	void OwnerDied() { NativeCall<void>(this, "AShooterWeapon.OwnerDied"); }
	void OnRep_NetLoopedWeaponFire() { NativeCall<void>(this, "AShooterWeapon.OnRep_NetLoopedWeaponFire"); }
	void ClientSetClipAmmo_Implementation(int newClipAmmo, bool bOnlyUpdateItem) { NativeCall<void, int, bool>(this, "AShooterWeapon.ClientSetClipAmmo_Implementation", newClipAmmo, bOnlyUpdateItem); }
	void DoHandleFiring() { NativeCall<void>(this, "AShooterWeapon.DoHandleFiring"); }
	bool IsFirstPersonMeshVisible() { return NativeCall<bool>(this, "AShooterWeapon.IsFirstPersonMeshVisible"); }
	void ServerSetColorizeRegion_Implementation(int theRegion, bool bValToUse) { NativeCall<void, int, bool>(this, "AShooterWeapon.ServerSetColorizeRegion_Implementation", theRegion, bValToUse); }
	void DoReregisterAllComponents() { NativeCall<void>(this, "AShooterWeapon.DoReregisterAllComponents"); }
	bool ForceTPVTargetingAnimation() { return NativeCall<bool>(this, "AShooterWeapon.ForceTPVTargetingAnimation"); }
	void FireWeapon() { NativeCall<void>(this, "AShooterWeapon.FireWeapon"); }
	bool PreventSwitchingWeapon() { return NativeCall<bool>(this, "AShooterWeapon.PreventSwitchingWeapon"); }
	bool ForceFirstPerson() { return NativeCall<bool>(this, "AShooterWeapon.ForceFirstPerson"); }
	bool TryFireWeapon() { return NativeCall<bool>(this, "AShooterWeapon.TryFireWeapon"); }
	bool ForcesTPVCameraOffset_Implementation() { return NativeCall<bool>(this, "AShooterWeapon.ForcesTPVCameraOffset_Implementation"); }
	static void StaticRegisterNativesAShooterWeapon() { NativeCall<void>(nullptr, "AShooterWeapon.StaticRegisterNativesAShooterWeapon"); }
	bool BPConstrainAspectRatio(float * OutAspectRatio) { return NativeCall<bool, float *>(this, "AShooterWeapon.BPConstrainAspectRatio", OutAspectRatio); }
	bool BPWeaponCanFire() { return NativeCall<bool>(this, "AShooterWeapon.BPWeaponCanFire"); }
	int BPWeaponDealDamage(FHitResult * Impact, FVector * ShootDir, int DamageAmount, TSubclassOf<UDamageType> DamageType, float Impulse) { return NativeCall<int, FHitResult *, FVector *, int, TSubclassOf<UDamageType>, float>(this, "AShooterWeapon.BPWeaponDealDamage", Impact, ShootDir, DamageAmount, DamageType, Impulse); }
	void ClientStartMuzzleFX() { NativeCall<void>(this, "AShooterWeapon.ClientStartMuzzleFX"); }
	bool ForcesTPVCameraOffset() { return NativeCall<bool>(this, "AShooterWeapon.ForcesTPVCameraOffset"); }
	UAnimSequence * GetStandingAnimation(float * OutBlendInTime, float * OutBlendOutTime) { return NativeCall<UAnimSequence *, float *, float *>(this, "AShooterWeapon.GetStandingAnimation", OutBlendInTime, OutBlendOutTime); }
	void PlayWeaponBreakAnimation() { NativeCall<void>(this, "AShooterWeapon.PlayWeaponBreakAnimation"); }
	void ServerSetColorizeRegion(int theRegion, bool bValToUse) { NativeCall<void, int, bool>(this, "AShooterWeapon.ServerSetColorizeRegion", theRegion, bValToUse); }
	void ServerStartFire() { NativeCall<void>(this, "AShooterWeapon.ServerStartFire"); }
	void StartUnequip() { NativeCall<void>(this, "AShooterWeapon.StartUnequip"); }
};

struct AAIController : AController
{
	FieldValue<FVector> MoveTowardTargetOffsetField() { return { this, "AAIController.MoveTowardTargetOffset" }; }
	FieldValue<FVector> TargetFocalPositionOffsetField() { return { this, "AAIController.TargetFocalPositionOffset" }; }
	FieldValue<float> ReachedDestinationThresholdOffsetField() { return { this, "AAIController.ReachedDestinationThresholdOffset" }; }
	FieldValue<float> MovementGoalHeightField() { return { this, "AAIController.MovementGoalHeight" }; }
	FieldValue<unsigned int> RequestMoveIDField() { return { this, "AAIController.RequestMoveID" }; }
	FieldValue<TWeakObjectPtr<AActor>> CurrentGoalField() { return { this, "AAIController.CurrentGoal" }; }
	FieldValue<FVector> MoveSegmentDirectionField() { return { this, "AAIController.MoveSegmentDirection" }; }
	FieldValue<int> MoveSegmentStartIndexField() { return { this, "AAIController.MoveSegmentStartIndex" }; }
	FieldValue<int> MoveSegmentEndIndexField() { return { this, "AAIController.MoveSegmentEndIndex" }; }
	FieldValue<float> CurrentAcceptanceRadiusField() { return { this, "AAIController.CurrentAcceptanceRadius" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bLOSflag() { return { this, "AAIController.bLOSflag" }; }
	BitFieldValue<bool, unsigned __int32> bSkipExtraLOSChecks() { return { this, "AAIController.bSkipExtraLOSChecks" }; }
	BitFieldValue<bool, unsigned __int32> bAllowStrafe() { return { this, "AAIController.bAllowStrafe" }; }
	BitFieldValue<bool, unsigned __int32> bWantsPlayerState() { return { this, "AAIController.bWantsPlayerState" }; }
	BitFieldValue<bool, unsigned __int32> bUse3DGoalRadius() { return { this, "AAIController.bUse3DGoalRadius" }; }
	BitFieldValue<bool, unsigned __int32> bCurrentStopOnOverlap() { return { this, "AAIController.bCurrentStopOnOverlap" }; }
	BitFieldValue<bool, unsigned __int32> bLastMoveReachedGoal() { return { this, "AAIController.bLastMoveReachedGoal" }; }
	BitFieldValue<bool, unsigned __int32> bLastRequestedMoveToLocationWasPlayerCommand() { return { this, "AAIController.bLastRequestedMoveToLocationWasPlayerCommand" }; }

	// Functions

	UField * StaticClass() { return NativeCall<UField *>(this, "AAIController.StaticClass"); }
	UObject * GetUObjectInterfaceAIPerceptionListenerInterface() { return NativeCall<UObject *>(this, "AAIController.GetUObjectInterfaceAIPerceptionListenerInterface"); }
	void Tick(float DeltaTime) { NativeCall<void, float>(this, "AAIController.Tick", DeltaTime); }
	void PostInitializeComponents() { NativeCall<void>(this, "AAIController.PostInitializeComponents"); }
	void PostRegisterAllComponents() { NativeCall<void>(this, "AAIController.PostRegisterAllComponents"); }
	void Reset() { NativeCall<void>(this, "AAIController.Reset"); }
	void GetPlayerViewPoint(FVector * out_Location, FRotator * out_Rotation) { NativeCall<void, FVector *, FRotator *>(this, "AAIController.GetPlayerViewPoint", out_Location, out_Rotation); }
	void SetFocalPoint(FVector FP, bool bOffsetFromBase, char InPriority) { NativeCall<void, FVector, bool, char>(this, "AAIController.SetFocalPoint", FP, bOffsetFromBase, InPriority); }
	FVector * GetFocalPoint(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AAIController.GetFocalPoint", result); }
	AActor * GetFocusActor() { return NativeCall<AActor *>(this, "AAIController.GetFocusActor"); }
	void SetFocus(AActor * NewFocus, char InPriority) { NativeCall<void, AActor *, char>(this, "AAIController.SetFocus", NewFocus, InPriority); }
	void ClearFocus(char InPriority) { NativeCall<void, char>(this, "AAIController.ClearFocus", InPriority); }
	bool LineOfSightTo(AActor * Other, FVector ViewPoint, bool bAlternateChecks) { return NativeCall<bool, AActor *, FVector, bool>(this, "AAIController.LineOfSightTo", Other, ViewPoint, bAlternateChecks); }
	void UpdateControlRotation(float DeltaTime, bool bUpdatePawn) { NativeCall<void, float, bool>(this, "AAIController.UpdateControlRotation", DeltaTime, bUpdatePawn); }
	void Possess(APawn * InPawn) { NativeCall<void, APawn *>(this, "AAIController.Possess", InPawn); }
	void UnPossess() { NativeCall<void>(this, "AAIController.UnPossess"); }
	EPathFollowingRequestResult::Type MoveToActor(AActor * Goal, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass) { return NativeCall<EPathFollowingRequestResult::Type, AActor *, float, bool, bool, bool, TSubclassOf<UNavigationQueryFilter>>(this, "AAIController.MoveToActor", Goal, AcceptanceRadius, bStopOnOverlap, bUsePathfinding, bCanStrafe, FilterClass); }
	EPathFollowingRequestResult::Type MoveToLocation(FVector * Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool WasPlayerCommand) { return NativeCall<EPathFollowingRequestResult::Type, FVector *, float, bool, bool, bool, bool, TSubclassOf<UNavigationQueryFilter>, bool>(this, "AAIController.MoveToLocation", Dest, AcceptanceRadius, bStopOnOverlap, bUsePathfinding, bProjectDestinationToNavigation, bCanStrafe, FilterClass, WasPlayerCommand); }
	bool HasReached(FVector * TestPoint, float InAcceptanceRadius, bool bExactSpot) { return NativeCall<bool, FVector *, float, bool>(this, "AAIController.HasReached", TestPoint, InAcceptanceRadius, bExactSpot); }
	bool HasReached(AActor * TestGoal, float InAcceptanceRadius, bool bExactSpot) { return NativeCall<bool, AActor *, float, bool>(this, "AAIController.HasReached", TestGoal, InAcceptanceRadius, bExactSpot); }
	bool HasReachedDestination(FVector * CurrentLocation) { return NativeCall<bool, FVector *>(this, "AAIController.HasReachedDestination", CurrentLocation); }
	bool HasReachedCurrentTarget(FVector * CurrentLocation) { return NativeCall<bool, FVector *>(this, "AAIController.HasReachedCurrentTarget", CurrentLocation); }
	bool HasReachedInternal(FVector * Goal, float GoalRadius, float GoalHalfHeight, FVector * AgentLocation, float RadiusThreshold, bool bUseAgentRadius) { return NativeCall<bool, FVector *, float, float, FVector *, float, bool>(this, "AAIController.HasReachedInternal", Goal, GoalRadius, GoalHalfHeight, AgentLocation, RadiusThreshold, bUseAgentRadius); }
	void AbortMove(FString * Reason, FAIRequestID RequestID, bool bResetVelocity, bool bSilent, char MessageFlags) { NativeCall<void, FString *, FAIRequestID, bool, bool, char>(this, "AAIController.AbortMove", Reason, RequestID, bResetVelocity, bSilent, MessageFlags); }
	void UpdatePathSegment() { NativeCall<void>(this, "AAIController.UpdatePathSegment"); }
	void FollowPathSegment(float DeltaTime) { NativeCall<void, float>(this, "AAIController.FollowPathSegment", DeltaTime); }
	void ResetMovement() { NativeCall<void>(this, "AAIController.ResetMovement"); }
	void OnPathFinished(EPathFollowingResult::Type Result) { NativeCall<void, EPathFollowingResult::Type>(this, "AAIController.OnPathFinished", Result); }
	FVector * GetMoveFocus(FVector * result) { return NativeCall<FVector *, FVector *>(this, "AAIController.GetMoveFocus", result); }
	void UpdateMoveFocus() { NativeCall<void>(this, "AAIController.UpdateMoveFocus"); }
	void SetMoveSegment(int SegmentStartIndex) { NativeCall<void, int>(this, "AAIController.SetMoveSegment", SegmentStartIndex); }
	void StopMovement() { NativeCall<void>(this, "AAIController.StopMovement"); }
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) { NativeCall<void, FAIRequestID, EPathFollowingResult::Type>(this, "AAIController.OnMoveCompleted", RequestID, Result); }
};

struct APrimalDinoAIController : AAIController
{
	FieldValue<float> DieIfLeftWaterWanderMinimumWaterHeightMultiplierField() { return { this, "APrimalDinoAIController.DieIfLeftWaterWanderMinimumWaterHeightMultiplier" }; }
	FieldValue<float> DieIfLeftWaterReachedRadiusDistanceCheckMultiplierField() { return { this, "APrimalDinoAIController.DieIfLeftWaterReachedRadiusDistanceCheckMultiplier" }; }
	FieldValue<float> DieIfLeftWaterTargetUnsubmergedTimeoutField() { return { this, "APrimalDinoAIController.DieIfLeftWaterTargetUnsubmergedTimeout" }; }
	FieldValue<float> LandDinoMaxWaterTargetDepthCapsuleMultiplierField() { return { this, "APrimalDinoAIController.LandDinoMaxWaterTargetDepthCapsuleMultiplier" }; }
	FieldValue<float> ExtraCorpseTargetingRangeField() { return { this, "APrimalDinoAIController.ExtraCorpseTargetingRange" }; }
	FieldValue<float> FleeFromAttackCoolDownTimeField() { return { this, "APrimalDinoAIController.FleeFromAttackCoolDownTime" }; }
	FieldValue<float> FleeFromAttackTimeLimitField() { return { this, "APrimalDinoAIController.FleeFromAttackTimeLimit" }; }
	FieldValue<float> ForceFleeUnderHealthPercentageField() { return { this, "APrimalDinoAIController.ForceFleeUnderHealthPercentage" }; }
	FieldValue<bool> bFleeOnCriticalHealthField() { return { this, "APrimalDinoAIController.bFleeOnCriticalHealth" }; }
	FieldValue<float> DieIfLeftWaterTargetingRequiresFreeDepthField() { return { this, "APrimalDinoAIController.DieIfLeftWaterTargetingRequiresFreeDepth" }; }
	FieldValue<long double> LastBlockadeCheckTimeField() { return { this, "APrimalDinoAIController.LastBlockadeCheckTime" }; }
	FieldValue<long double> LastMovingAroundBlockadeTimeField() { return { this, "APrimalDinoAIController.LastMovingAroundBlockadeTime" }; }
	FieldValue<float> MovingAroundBlockadeDirectionField() { return { this, "APrimalDinoAIController.MovingAroundBlockadeDirection" }; }
	FieldValue<FVector> MovingAroundBlockadePointField() { return { this, "APrimalDinoAIController.MovingAroundBlockadePoint" }; }
	FieldValue<float> LastBlockadeWidthField() { return { this, "APrimalDinoAIController.LastBlockadeWidth" }; }
	FieldValue<FVector> LastBlockadeHitNormalField() { return { this, "APrimalDinoAIController.LastBlockadeHitNormal" }; }
	FieldValue<FVector> LastBlockadeHitLocationField() { return { this, "APrimalDinoAIController.LastBlockadeHitLocation" }; }
	FieldValue<FVector> StartMovingAroundBlockadeLocationField() { return { this, "APrimalDinoAIController.StartMovingAroundBlockadeLocation" }; }
	FieldValue<AActor *> LastMovingAroundBlockadeActorField() { return { this, "APrimalDinoAIController.LastMovingAroundBlockadeActor" }; }
	FieldValue<AActor *> TargetField() { return { this, "APrimalDinoAIController.Target" }; }
	FieldValue<float> AttackDestinationOffsetField() { return { this, "APrimalDinoAIController.AttackDestinationOffset" }; }
	FieldValue<bool> bUseOverlapTargetCheckField() { return { this, "APrimalDinoAIController.bUseOverlapTargetCheck" }; }
	FieldValue<bool> bNotifyNeighborsWithoutDamageField() { return { this, "APrimalDinoAIController.bNotifyNeighborsWithoutDamage" }; }
	FieldValue<bool> bUseBPShouldNotifyNeighborField() { return { this, "APrimalDinoAIController.bUseBPShouldNotifyNeighbor" }; }
	FieldValue<bool> bRequireAbsoluteDamageForNeighborNotificationField() { return { this, "APrimalDinoAIController.bRequireAbsoluteDamageForNeighborNotification" }; }
	FieldValue<float> AboveDeltaZAttackRangeField() { return { this, "APrimalDinoAIController.AboveDeltaZAttackRange" }; }
	FieldValue<float> BelowDeltaZAttackRangeField() { return { this, "APrimalDinoAIController.BelowDeltaZAttackRange" }; }
	FieldValue<float> WildAboveDeltaZTargetingRangeField() { return { this, "APrimalDinoAIController.WildAboveDeltaZTargetingRange" }; }
	FieldValue<float> WildBelowDeltaZTargetingRangeField() { return { this, "APrimalDinoAIController.WildBelowDeltaZTargetingRange" }; }
	FieldValue<bool> bWildUseDeltaZTargetingForFlyerPawnOrBigDinoField() { return { this, "APrimalDinoAIController.bWildUseDeltaZTargetingForFlyerPawnOrBigDino" }; }
	FieldValue<bool> bDontWanderField() { return { this, "APrimalDinoAIController.bDontWander" }; }
	FieldValue<bool> bOnlyOverlapTargetCorpsesUnlessHasTargetField() { return { this, "APrimalDinoAIController.bOnlyOverlapTargetCorpsesUnlessHasTarget" }; }
	FieldValue<float> NaturalTargetingRangeField() { return { this, "APrimalDinoAIController.NaturalTargetingRange" }; }
	FieldValue<float> TamedTargetingRangeField() { return { this, "APrimalDinoAIController.TamedTargetingRange" }; }
	FieldValue<float> TamedCorpseFoodTargetingRangeField() { return { this, "APrimalDinoAIController.TamedCorpseFoodTargetingRange" }; }
	FieldValue<float> WanderRandomDistanceAmountField() { return { this, "APrimalDinoAIController.WanderRandomDistanceAmount" }; }
	FieldValue<float> FlyingWanderFixedDistanceAmountField() { return { this, "APrimalDinoAIController.FlyingWanderFixedDistanceAmount" }; }
	FieldValue<float> FlyingWanderRandomDistanceAmountField() { return { this, "APrimalDinoAIController.FlyingWanderRandomDistanceAmount" }; }
	FieldValue<float> MaxFlyingTargetDeltaZField() { return { this, "APrimalDinoAIController.MaxFlyingTargetDeltaZ" }; }
	FieldValue<float> WanderFlyingZScalerField() { return { this, "APrimalDinoAIController.WanderFlyingZScaler" }; }
	FieldValue<float> WanderFlyingClampZHeightAboveGroundField() { return { this, "APrimalDinoAIController.WanderFlyingClampZHeightAboveGround" }; }
	FieldValue<float> WanderFlyingMinZHeightAboveGroundField() { return { this, "APrimalDinoAIController.WanderFlyingMinZHeightAboveGround" }; }
	FieldValue<float> WanderFixedDistanceAmountField() { return { this, "APrimalDinoAIController.WanderFixedDistanceAmount" }; }
	FieldValue<bool> bUseAggroField() { return { this, "APrimalDinoAIController.bUseAggro" }; }
	FieldValue<float> MinAggroValueField() { return { this, "APrimalDinoAIController.MinAggroValue" }; }
	FieldValue<float> AggroToAddUponRemovingTargetField() { return { this, "APrimalDinoAIController.AggroToAddUponRemovingTarget" }; }
	FieldValue<float> AggroToAddUponAcquiringTargetField() { return { this, "APrimalDinoAIController.AggroToAddUponAcquiringTarget" }; }
	FieldValue<float> AggroFactorDecreaseSpeedField() { return { this, "APrimalDinoAIController.AggroFactorDecreaseSpeed" }; }
	FieldValue<float> AggroFactorDecreaseGracePeriodField() { return { this, "APrimalDinoAIController.AggroFactorDecreaseGracePeriod" }; }
	FieldValue<float> AggroFactorDamagePercentageMultiplierField() { return { this, "APrimalDinoAIController.AggroFactorDamagePercentageMultiplier" }; }
	FieldValue<float> AggroNotifyNeighborsMultiplierField() { return { this, "APrimalDinoAIController.AggroNotifyNeighborsMultiplier" }; }
	FieldValue<float> AggroNotifyNeighborsRangeField() { return { this, "APrimalDinoAIController.AggroNotifyNeighborsRange" }; }
	FieldValue<float> AggroNotifyNeighborsRangeFalloffField() { return { this, "APrimalDinoAIController.AggroNotifyNeighborsRangeFalloff" }; }
	FieldValue<float> TargetingDistanceReductionFactorLinearField() { return { this, "APrimalDinoAIController.TargetingDistanceReductionFactorLinear" }; }
	FieldValue<float> TargetingDistanceReductionFactorExponentField() { return { this, "APrimalDinoAIController.TargetingDistanceReductionFactorExponent" }; }
	FieldValue<float> BeyondTargetingRangeAggroAdditionField() { return { this, "APrimalDinoAIController.BeyondTargetingRangeAggroAddition" }; }
	FieldValue<float> AggroFactorDesirabilityMultiplierField() { return { this, "APrimalDinoAIController.AggroFactorDesirabilityMultiplier" }; }
	FieldValue<float> AttackRangeField() { return { this, "APrimalDinoAIController.AttackRange" }; }
	FieldValue<float> AttackIntervalField() { return { this, "APrimalDinoAIController.AttackInterval" }; }
	FieldValue<float> AttackRotationRangeDegreesField() { return { this, "APrimalDinoAIController.AttackRotationRangeDegrees" }; }
	FieldValue<float> AttackRotationGroundSpeedMultiplierField() { return { this, "APrimalDinoAIController.AttackRotationGroundSpeedMultiplier" }; }
	FieldValue<float> RangeTargetWildDinosMultiplierField() { return { this, "APrimalDinoAIController.RangeTargetWildDinosMultiplier" }; }
	FieldValue<FRotator> AttackRotationRateField() { return { this, "APrimalDinoAIController.AttackRotationRate" }; }
	FieldValue<bool> bFocusOnTargetDuringAttackField() { return { this, "APrimalDinoAIController.bFocusOnTargetDuringAttack" }; }
	FieldValue<FVector> FlyingMoveTowardsTargetOffsetField() { return { this, "APrimalDinoAIController.FlyingMoveTowardsTargetOffset" }; }
	FieldValue<FVector> CombatFlyingMoveTowardsTargetOffsetField() { return { this, "APrimalDinoAIController.CombatFlyingMoveTowardsTargetOffset" }; }
	FieldValue<FVector> FlyingTargetFocalPositionOffsetField() { return { this, "APrimalDinoAIController.FlyingTargetFocalPositionOffset" }; }
	FieldValue<float> FlyingReachedDestinationThresholdOffsetField() { return { this, "APrimalDinoAIController.FlyingReachedDestinationThresholdOffset" }; }
	FieldValue<float> SeekingIntervalCheckToFlyField() { return { this, "APrimalDinoAIController.SeekingIntervalCheckToFly" }; }
	FieldValue<float> SeekingPercentChanceToFlyField() { return { this, "APrimalDinoAIController.SeekingPercentChanceToFly" }; }
	FieldValue<float> SeekingIntervalCheckToLandField() { return { this, "APrimalDinoAIController.SeekingIntervalCheckToLand" }; }
	FieldValue<float> SeekingPercentChanceToLandField() { return { this, "APrimalDinoAIController.SeekingPercentChanceToLand" }; }
	FieldValue<float> MinimumWanderGroundNormalZField() { return { this, "APrimalDinoAIController.MinimumWanderGroundNormalZ" }; }
	FieldValue<float> FollowStoppingDistanceField() { return { this, "APrimalDinoAIController.FollowStoppingDistance" }; }
	FieldValue<bool> bUseOverlapTargetCheckTracesField() { return { this, "APrimalDinoAIController.bUseOverlapTargetCheckTraces" }; }
	FieldValue<bool> bUseAlternateMovePointField() { return { this, "APrimalDinoAIController.bUseAlternateMovePoint" }; }
	FieldValue<bool> bTotallyIgnoreWaterTargetsField() { return { this, "APrimalDinoAIController.bTotallyIgnoreWaterTargets" }; }
	FieldValue<bool> bWaterDinoAllowUnsubmergedTargetsField() { return { this, "APrimalDinoAIController.bWaterDinoAllowUnsubmergedTargets" }; }
	FieldValue<FVector> LastCheckAttackRangePawnLocationField() { return { this, "APrimalDinoAIController.LastCheckAttackRangePawnLocation" }; }
	FieldValue<FVector> LastCheckAttackRangeClosestPointField() { return { this, "APrimalDinoAIController.LastCheckAttackRangeClosestPoint" }; }
	FieldValue<FVector> LastCheckAttackRangeTargetLocationField() { return { this, "APrimalDinoAIController.LastCheckAttackRangeTargetLocation" }; }
	FieldValue<AActor *> LastCheckAttackRangeTargetField() { return { this, "APrimalDinoAIController.LastCheckAttackRangeTarget" }; }
	FieldValue<TArray<float>> TamedAITargetingRangeMultipliersField() { return { this, "APrimalDinoAIController.TamedAITargetingRangeMultipliers" }; }
	FieldValue<float> MateBoostAggroNotifyNeighborsMultiplierField() { return { this, "APrimalDinoAIController.MateBoostAggroNotifyNeighborsMultiplier" }; }
	FieldValue<TArray<TSubclassOf<APrimalDinoCharacter>>> AggroNotifyNeighborsClassesField() { return { this, "APrimalDinoAIController.AggroNotifyNeighborsClasses" }; }
	FieldValue<float> MoveAroundBlockadeAdditionalWidthField() { return { this, "APrimalDinoAIController.MoveAroundBlockadeAdditionalWidth" }; }
	FieldValue<float> MoveAroundObjectMaxVelocityField() { return { this, "APrimalDinoAIController.MoveAroundObjectMaxVelocity" }; }
	FieldValue<float> ForcedAggroTimeCounterField() { return { this, "APrimalDinoAIController.ForcedAggroTimeCounter" }; }
	FieldValue<float> TamedMaxFollowDistanceField() { return { this, "APrimalDinoAIController.TamedMaxFollowDistance" }; }
	FieldValue<float> LandDinoMaxFlyerTargetDeltaZField() { return { this, "APrimalDinoAIController.LandDinoMaxFlyerTargetDeltaZ" }; }
	FieldValue<float> NaturalMaxDepthZField() { return { this, "APrimalDinoAIController.NaturalMaxDepthZ" }; }
	FieldValue<TWeakObjectPtr<AActor>> ForcedAttackTargetField() { return { this, "APrimalDinoAIController.ForcedAttackTarget" }; }
	FieldValue<int> ForcedAttackEnemyTeamField() { return { this, "APrimalDinoAIController.ForcedAttackEnemyTeam" }; }
	FieldValue<long double> LastForcedAttackEnemyTeamTimeField() { return { this, "APrimalDinoAIController.LastForcedAttackEnemyTeamTime" }; }
	FieldValue<int> LastCharacterTargetTeamField() { return { this, "APrimalDinoAIController.LastCharacterTargetTeam" }; }
	FieldValue<float> ForcedFleeDurationField() { return { this, "APrimalDinoAIController.ForcedFleeDuration" }; }
	FieldValue<float> MinAttackIntervalForFleeingField() { return { this, "APrimalDinoAIController.MinAttackIntervalForFleeing" }; }
	FieldValue<float> MinLocChangeIntervalForFleeingField() { return { this, "APrimalDinoAIController.MinLocChangeIntervalForFleeing" }; }
	FieldValue<float> PercentageTorporForFleeingField() { return { this, "APrimalDinoAIController.PercentageTorporForFleeing" }; }
	FieldValue<float> DamagedForceAggroIntervalField() { return { this, "APrimalDinoAIController.DamagedForceAggroInterval" }; }
	FieldValue<long double> ForceAggroUntilTimeField() { return { this, "APrimalDinoAIController.ForceAggroUntilTime" }; }
	FieldValue<long double> LastExecutedAttackTimeField() { return { this, "APrimalDinoAIController.LastExecutedAttackTime" }; }
	FieldValue<long double> LastForcedFleeTimeField() { return { this, "APrimalDinoAIController.LastForcedFleeTime" }; }
	FieldValue<long double> LastFleeLocCheckTimeField() { return { this, "APrimalDinoAIController.LastFleeLocCheckTime" }; }
	FieldValue<FVector> LastFleeLocCheckField() { return { this, "APrimalDinoAIController.LastFleeLocCheck" }; }
	FieldValue<int> NumAlliesToAttackField() { return { this, "APrimalDinoAIController.NumAlliesToAttack" }; }
	FieldValue<float> FindLandingPositionZOffsetField() { return { this, "APrimalDinoAIController.FindLandingPositionZOffset" }; }
	FieldValue<float> TamedFollowAcceptanceRadiusOffsetField() { return { this, "APrimalDinoAIController.TamedFollowAcceptanceRadiusOffset" }; }
	FieldValue<float> TamedFollowAcceptanceHeightOffsetField() { return { this, "APrimalDinoAIController.TamedFollowAcceptanceHeightOffset" }; }
	FieldValue<float> AIFlightMaxLandingZDistanceField() { return { this, "APrimalDinoAIController.AIFlightMaxLandingZDistance" }; }
	FieldValue<long double> ForcedMoveToUntilTimeField() { return { this, "APrimalDinoAIController.ForcedMoveToUntilTime" }; }
	FieldValue<long double> LastHadAggroEntriesTimeField() { return { this, "APrimalDinoAIController.LastHadAggroEntriesTime" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> WildTargetingDesireMultiplierClassesField() { return { this, "APrimalDinoAIController.WildTargetingDesireMultiplierClasses" }; }
	FieldValue<TArray<float>> WildTargetingDesireMultiplierValuesField() { return { this, "APrimalDinoAIController.WildTargetingDesireMultiplierValues" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> TamedTargetingDesireMultiplierClassesField() { return { this, "APrimalDinoAIController.TamedTargetingDesireMultiplierClasses" }; }
	FieldValue<TArray<float>> TamedTargetingDesireMultiplierValuesField() { return { this, "APrimalDinoAIController.TamedTargetingDesireMultiplierValues" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bForcedAggro() { return { this, "APrimalDinoAIController.bForcedAggro" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreMoveAroundBlockade() { return { this, "APrimalDinoAIController.bIgnoreMoveAroundBlockade" }; }
	BitFieldValue<bool, unsigned __int32> bFlyingUseMoveAroundBlockade() { return { this, "APrimalDinoAIController.bFlyingUseMoveAroundBlockade" }; }
	BitFieldValue<bool, unsigned __int32> bUseGeometryInsteadOfStationObjForFreeDepthTest() { return { this, "APrimalDinoAIController.bUseGeometryInsteadOfStationObjForFreeDepthTest" }; }
	BitFieldValue<bool, unsigned __int32> bNotifyBPTargetSet() { return { this, "APrimalDinoAIController.bNotifyBPTargetSet" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPSetupFindTarget() { return { this, "APrimalDinoAIController.bUseBPSetupFindTarget" }; }
	BitFieldValue<bool, unsigned __int32> bNotAllowedToFindTargets() { return { this, "APrimalDinoAIController.bNotAllowedToFindTargets" }; }
	BitFieldValue<bool, unsigned __int32> bAllowForceFleeToSameTargetingTeam() { return { this, "APrimalDinoAIController.bAllowForceFleeToSameTargetingTeam" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPUpdateBestTarget() { return { this, "APrimalDinoAIController.bUseBPUpdateBestTarget" }; }
	BitFieldValue<bool, unsigned __int32> bTargetChanged() { return { this, "APrimalDinoAIController.bTargetChanged" }; }
	BitFieldValue<bool, unsigned __int32> bAttackForcesRunning() { return { this, "APrimalDinoAIController.bAttackForcesRunning" }; }
	BitFieldValue<bool, unsigned __int32> bUseFlyingTargetOffsets() { return { this, "APrimalDinoAIController.bUseFlyingTargetOffsets" }; }
	BitFieldValue<bool, unsigned __int32> bRidingDinoTargetPlayer() { return { this, "APrimalDinoAIController.bRidingDinoTargetPlayer" }; }
	BitFieldValue<bool, unsigned __int32> bRidingPlayerTargetDino() { return { this, "APrimalDinoAIController.bRidingPlayerTargetDino" }; }
	BitFieldValue<bool, unsigned __int32> bIgnoreWaterOrAmphibiousTargets() { return { this, "APrimalDinoAIController.bIgnoreWaterOrAmphibiousTargets" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPTargetingDesire() { return { this, "APrimalDinoAIController.bUseBPTargetingDesire" }; }
	BitFieldValue<bool, unsigned __int32> bDisableForceFlee() { return { this, "APrimalDinoAIController.bDisableForceFlee" }; }
	BitFieldValue<bool, unsigned __int32> bUseCombatMoveTowardsTargetOffset() { return { this, "APrimalDinoAIController.bUseCombatMoveTowardsTargetOffset" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPOverrideIgnoredByWildDino() { return { this, "APrimalDinoAIController.bUseBPOverrideIgnoredByWildDino" }; }
	BitFieldValue<bool, unsigned __int32> bCanUseAttackStateOnTargetChange() { return { this, "APrimalDinoAIController.bCanUseAttackStateOnTargetChange" }; }
	BitFieldValue<bool, unsigned __int32> bModifiedWanderRadius() { return { this, "APrimalDinoAIController.bModifiedWanderRadius" }; }
	BitFieldValue<bool, unsigned __int32> bForceOnlyTargetingPlayerOrTamed() { return { this, "APrimalDinoAIController.bForceOnlyTargetingPlayerOrTamed" }; }
	BitFieldValue<bool, unsigned __int32> bForceTargetingAllStructures() { return { this, "APrimalDinoAIController.bForceTargetingAllStructures" }; }
	BitFieldValue<bool, unsigned __int32> bForceTargetDinoRider() { return { this, "APrimalDinoAIController.bForceTargetDinoRider" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerAllowWaterTargeting() { return { this, "APrimalDinoAIController.bFlyerAllowWaterTargeting" }; }
	BitFieldValue<bool, unsigned __int32> bUseBPForceTargetDinoRider() { return { this, "APrimalDinoAIController.bUseBPForceTargetDinoRider" }; }
	BitFieldValue<bool, unsigned __int32> bAlwaysStartledWhenAggroedByNeighbor() { return { this, "APrimalDinoAIController.bAlwaysStartledWhenAggroedByNeighbor" }; }
	BitFieldValue<bool, unsigned __int32> bForceOnlyTargetingPlayers() { return { this, "APrimalDinoAIController.bForceOnlyTargetingPlayers" }; }
	BitFieldValue<bool, unsigned __int32> bUseBP_TamedOverrideHorizontalLandingRange() { return { this, "APrimalDinoAIController.bUseBP_TamedOverrideHorizontalLandingRange" }; }
	BitFieldValue<bool, unsigned __int32> bFlyerWanderDefaultToOrigin() { return { this, "APrimalDinoAIController.bFlyerWanderDefaultToOrigin" }; }

	// Functions

	void ForceLand() { NativeCall<void>(this, "APrimalDinoAIController.ForceLand"); }
	FVector * GetRandomWanderDestination(FVector * result, FVector LocOverride, float RandomOffsetMultiplier, bool bUseRandomNegativeXDir, bool bOrientRandOffsetByRotation, FRotator OrientRandOffsetByRotation) { return NativeCall<FVector *, FVector *, FVector, float, bool, bool, FRotator>(this, "APrimalDinoAIController.GetRandomWanderDestination", result, LocOverride, RandomOffsetMultiplier, bUseRandomNegativeXDir, bOrientRandOffsetByRotation, OrientRandOffsetByRotation); }
	static FVector * StaticGetRandomWanderDestination(FVector * result, APrimalDinoCharacter * TargetCharacter, APrimalDinoAIController * TargetAIController, FVector LocOverride, float RandomOffsetMultiplier, bool bUseRandomNegativeXDir, bool bOrientRandOffsetByRotation, FRotator OrientRandOffsetByRotation, float GroundCheckSpreadOverride) { return NativeCall<FVector *, FVector *, APrimalDinoCharacter *, APrimalDinoAIController *, FVector, float, bool, bool, FRotator, float>(nullptr, "APrimalDinoAIController.StaticGetRandomWanderDestination", result, TargetCharacter, TargetAIController, LocOverride, RandomOffsetMultiplier, bUseRandomNegativeXDir, bOrientRandOffsetByRotation, OrientRandOffsetByRotation, GroundCheckSpreadOverride); }
	void Unstasis() { NativeCall<void>(this, "APrimalDinoAIController.Unstasis"); }
	AActor * GetCorpseFoodTarget() { return NativeCall<AActor *>(this, "APrimalDinoAIController.GetCorpseFoodTarget"); }
	AActor * FindTarget(bool bDontSet) { return NativeCall<AActor *, bool>(this, "APrimalDinoAIController.FindTarget", bDontSet); }
	float GetTargetingDesire(AActor * InTarget) { return NativeCall<float, AActor *>(this, "APrimalDinoAIController.GetTargetingDesire", InTarget); }
	void SetTarget(AActor * InTarget, bool bDontAddAggro, bool bOverlapFoundTarget) { NativeCall<void, AActor *, bool, bool>(this, "APrimalDinoAIController.SetTarget", InTarget, bDontAddAggro, bOverlapFoundTarget); }
	void AddToAggro(AActor * Attacker, float DamagePercent, bool bNotifyNeighbors, bool SetValue, bool bIsFromDamage, bool skipTeamCheck) { NativeCall<void, AActor *, float, bool, bool, bool, bool>(this, "APrimalDinoAIController.AddToAggro", Attacker, DamagePercent, bNotifyNeighbors, SetValue, bIsFromDamage, skipTeamCheck); }
	void UpdateAggro() { NativeCall<void>(this, "APrimalDinoAIController.UpdateAggro"); }
	bool IsWithinAttackRange(AActor * Other, bool bForceUseLastAttackIndex) { return NativeCall<bool, AActor *, bool>(this, "APrimalDinoAIController.IsWithinAttackRange", Other, bForceUseLastAttackIndex); }
	FVector * GetWanderAroundActorDestination(FVector * result, APrimalDinoCharacter * dinoCharacter, FVector originalDestination) { return NativeCall<FVector *, FVector *, APrimalDinoCharacter *, FVector>(this, "APrimalDinoAIController.GetWanderAroundActorDestination", result, dinoCharacter, originalDestination); }
	bool IsWithinAttackRangeAndCalculateBestAttack(AActor * Other, bool * bAttackChanged) { return NativeCall<bool, AActor *, bool *>(this, "APrimalDinoAIController.IsWithinAttackRangeAndCalculateBestAttack", Other, bAttackChanged); }
	bool CalculateAndSetWonderingAIState(bool * StateChanged) { return NativeCall<bool, bool *>(this, "APrimalDinoAIController.CalculateAndSetWonderingAIState", StateChanged); }
	float GetAggroDesirability(AActor * InTarget) { return NativeCall<float, AActor *>(this, "APrimalDinoAIController.GetAggroDesirability", InTarget); }
	void NotifyTakeDamage(float Damage, FDamageEvent * DamageEvent, AController * EventInstigator, AActor * DamageCauser) { NativeCall<void, float, FDamageEvent *, AController *, AActor *>(this, "APrimalDinoAIController.NotifyTakeDamage", Damage, DamageEvent, EventInstigator, DamageCauser); }
	bool CheckMoveAroundBlockadePoint(FVector moveToPoint) { return NativeCall<bool, FVector>(this, "APrimalDinoAIController.CheckMoveAroundBlockadePoint", moveToPoint); }
	bool MoveAroundBlockade(FVector PreBumpLocation, AActor * BlockadeActor, UPrimitiveComponent * OtherComp, float BlockadeWidth, FVector HitNormal, FVector HitLocation, bool SkipBlockingCheck) { return NativeCall<bool, FVector, AActor *, UPrimitiveComponent *, float, FVector, FVector, bool>(this, "APrimalDinoAIController.MoveAroundBlockade", PreBumpLocation, BlockadeActor, OtherComp, BlockadeWidth, HitNormal, HitLocation, SkipBlockingCheck); }
	void NotifyBump(FVector PreBumpLocation, AActor * Other, UPrimitiveComponent * OtherComp, FVector * HitNormal, FVector * HitLocation) { NativeCall<void, FVector, AActor *, UPrimitiveComponent *, FVector *, FVector *>(this, "APrimalDinoAIController.NotifyBump", PreBumpLocation, Other, OtherComp, HitNormal, HitLocation); }
	void RecoverMovement() { NativeCall<void>(this, "APrimalDinoAIController.RecoverMovement"); }
	void PlayStartledAnim() { NativeCall<void>(this, "APrimalDinoAIController.PlayStartledAnim"); }
	void Destroyed() { NativeCall<void>(this, "APrimalDinoAIController.Destroyed"); }
	bool CanLand() { return NativeCall<bool>(this, "APrimalDinoAIController.CanLand"); }
	FVector * GetLandingLocation(FVector * result) { return NativeCall<FVector *, FVector *>(this, "APrimalDinoAIController.GetLandingLocation", result); }
	void ResetRotationRate() { NativeCall<void>(this, "APrimalDinoAIController.ResetRotationRate"); }
	void SetAttackGroundSpeed() { NativeCall<void>(this, "APrimalDinoAIController.SetAttackGroundSpeed"); }
	void AvoidOutOfWater() { NativeCall<void>(this, "APrimalDinoAIController.AvoidOutOfWater"); }
	bool UseLowQualityBehaviorTreeTick() { return NativeCall<bool>(this, "APrimalDinoAIController.UseLowQualityBehaviorTreeTick"); }
	void Possess(APawn * InPawn) { NativeCall<void, APawn *>(this, "APrimalDinoAIController.Possess", InPawn); }
	bool ShouldForceFlee() { return NativeCall<bool>(this, "APrimalDinoAIController.ShouldForceFlee"); }
	AActor * GetAggroEntriesAttackerAtIndex(int Index) { return NativeCall<AActor *, int>(this, "APrimalDinoAIController.GetAggroEntriesAttackerAtIndex", Index); }
	bool ShouldForceRunWhenAttacking() { return NativeCall<bool>(this, "APrimalDinoAIController.ShouldForceRunWhenAttacking"); }
	float GetAcceptanceHeightOffset() { return NativeCall<float>(this, "APrimalDinoAIController.GetAcceptanceHeightOffset"); }
	float GetAcceptanceRadiusOffset() { return NativeCall<float>(this, "APrimalDinoAIController.GetAcceptanceRadiusOffset"); }
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) { NativeCall<void, FAIRequestID, EPathFollowingResult::Type>(this, "APrimalDinoAIController.OnMoveCompleted", RequestID, Result); }
	void StopBrainComponent(FString reason) { NativeCall<void, FString>(this, "APrimalDinoAIController.StopBrainComponent", reason); }
	float GetAggroNotifyNeighborsRange_Implementation() { return NativeCall<float>(this, "APrimalDinoAIController.GetAggroNotifyNeighborsRange_Implementation"); }
	bool IsForceTargetDinoRider(AShooterCharacter * playerTarget) { return NativeCall<bool, AShooterCharacter *>(this, "APrimalDinoAIController.IsForceTargetDinoRider", playerTarget); }
	float BPGetTargetingDesire(AActor * ForTarget, float ForTargetingDesireValue) { return NativeCall<float, AActor *, float>(this, "APrimalDinoAIController.BPGetTargetingDesire", ForTarget, ForTargetingDesireValue); }
	void BPOnFleeEvent() { NativeCall<void>(this, "APrimalDinoAIController.BPOnFleeEvent"); }
	AActor * BPUpdateBestTarget(AActor * bestTarget, bool dontSetIn, bool * dontSetOut) { return NativeCall<AActor *, AActor *, bool, bool *>(this, "APrimalDinoAIController.BPUpdateBestTarget", bestTarget, dontSetIn, dontSetOut); }
	void ChangedAITarget() { NativeCall<void>(this, "APrimalDinoAIController.ChangedAITarget"); }
};

struct ADroppedItem : AActor
{
	FieldValue<FItemNetInfo> MyItemInfoField() { return { this, "ADroppedItem.MyItemInfo" }; }
	FieldValue<UPrimalItem *> MyItemField() { return { this, "ADroppedItem.MyItem" }; }
	FieldValue<float> ImpulseMagnitudeField() { return { this, "ADroppedItem.ImpulseMagnitude" }; }
	FieldValue<float> ForceSleepTimerField() { return { this, "ADroppedItem.ForceSleepTimer" }; }
	FieldValue<FVector> DroppedItemScaleField() { return { this, "ADroppedItem.DroppedItemScale" }; }
	FieldValue<FVector2D> OverlayTooltipPaddingField() { return { this, "ADroppedItem.OverlayTooltipPadding" }; }
	FieldValue<FVector2D> OverlayTooltipScaleField() { return { this, "ADroppedItem.OverlayTooltipScale" }; }
	FieldValue<FString> DroppedByNameField() { return { this, "ADroppedItem.DroppedByName" }; }
	FieldValue<unsigned __int64> DroppedByPlayerIDField() { return { this, "ADroppedItem.DroppedByPlayerID" }; }
	FieldValue<long double> DroppedItemDestructionTimeField() { return { this, "ADroppedItem.DroppedItemDestructionTime" }; }
	FieldValue<bool> bClientDisablePhysicsField() { return { this, "ADroppedItem.bClientDisablePhysics" }; }
	FieldValue<UStaticMesh *> NetDroppedMeshOverrideField() { return { this, "ADroppedItem.NetDroppedMeshOverride" }; }
	FieldValue<UMaterialInterface *> NetDroppedMeshMaterialOverrideField() { return { this, "ADroppedItem.NetDroppedMeshMaterialOverride" }; }
	FieldValue<FVector> NetDroppedMeshOverrideScale3DField() { return { this, "ADroppedItem.NetDroppedMeshOverrideScale3D" }; }
	FieldValue<float> MaxPickUpDistanceField() { return { this, "ADroppedItem.MaxPickUpDistance" }; }
	FieldValue<float> PrevLinearDampingField() { return { this, "ADroppedItem.PrevLinearDamping" }; }
	FieldValue<float> PrevAngularDampingField() { return { this, "ADroppedItem.PrevAngularDamping" }; }
	FieldValue<long double> SpawnDropSoundTimeField() { return { this, "ADroppedItem.SpawnDropSoundTime" }; }
	FieldValue<FVector> PreviousLocationField() { return { this, "ADroppedItem.PreviousLocation" }; }
	FieldValue<TWeakObjectPtr<AActor>> DroppedByActorField() { return { this, "ADroppedItem.DroppedByActor" }; }
	FieldValue<float> FreezePhysicsAfterTimeField() { return { this, "ADroppedItem.FreezePhysicsAfterTime" }; }
	FieldValue<float> DroppedLifeSpanOverrideField() { return { this, "ADroppedItem.DroppedLifeSpanOverride" }; }

	// Bit fields

	BitFieldValue<bool, unsigned __int32> bApplyImpulseOnSpawn() { return { this, "ADroppedItem.bApplyImpulseOnSpawn" }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOnStasis() { return { this, "ADroppedItem.bDestroyOnStasis" }; }
	BitFieldValue<bool, unsigned __int32> bUseCollisionTrace() { return { this, "ADroppedItem.bUseCollisionTrace" }; }
	BitFieldValue<bool, unsigned __int32> bPreventPickup() { return { this, "ADroppedItem.bPreventPickup" }; }
	BitFieldValue<bool, unsigned __int32> bDestroyOutOfWater() { return { this, "ADroppedItem.bDestroyOutOfWater" }; }
	BitFieldValue<bool, unsigned __int32> bIsUnderwater() { return { this, "ADroppedItem.bIsUnderwater" }; }
	BitFieldValue<bool, unsigned __int32> bNotifyPreviousOwnerOfPickup() { return { this, "ADroppedItem.bNotifyPreviousOwnerOfPickup" }; }

	// Functions

	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "ADroppedItem.Tick", DeltaSeconds); }
	void Stasis() { NativeCall<void>(this, "ADroppedItem.Stasis"); }
	float GetDroppedItemLifeTime(bool bIgnoreTrueBlack, bool bUseGrayscale) { return NativeCall<float, bool, bool>(this, "ADroppedItem.GetDroppedItemLifeTime", bIgnoreTrueBlack, bUseGrayscale); }
	bool TryMultiUse(APlayerController * ForPC, int UseIndex) { return NativeCall<bool, APlayerController *, int>(this, "ADroppedItem.TryMultiUse", ForPC, UseIndex); }
	void BeginPlay() { NativeCall<void>(this, "ADroppedItem.BeginPlay"); }
	void FreezePhysics() { NativeCall<void>(this, "ADroppedItem.FreezePhysics"); }
	void DrawHUD(AShooterHUD * HUD) { NativeCall<void, AShooterHUD *>(this, "ADroppedItem.DrawHUD", HUD); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "ADroppedItem.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void ForceSleep() { NativeCall<void>(this, "ADroppedItem.ForceSleep"); }
	void SetupVisuals() { NativeCall<void>(this, "ADroppedItem.SetupVisuals"); }
	void PreInitializeComponents() { NativeCall<void>(this, "ADroppedItem.PreInitializeComponents"); }
	static void StaticRegisterNativesADroppedItem() { NativeCall<void>(nullptr, "ADroppedItem.StaticRegisterNativesADroppedItem"); }
};

struct AMatineeActor : AActor
{
	FieldValue<FName> MatineeControllerNameField() { return { this, "AMatineeActor.MatineeControllerName" }; }
	FieldValue<float> PlayRateField() { return { this, "AMatineeActor.PlayRate" }; }
	FieldValue<float> ForceStartPositionField() { return { this, "AMatineeActor.ForceStartPosition" }; }
	FieldValue<int> MatineeManagerPriorityField() { return { this, "AMatineeActor.MatineeManagerPriority" }; }
	FieldValue<int> PreferredSplitScreenNumField() { return { this, "AMatineeActor.PreferredSplitScreenNum" }; }
	FieldValue<float> InterpPositionField() { return { this, "AMatineeActor.InterpPosition" }; }
	FieldValue<float> ClientSidePositionErrorToleranceField() { return { this, "AMatineeActor.ClientSidePositionErrorTolerance" }; }
	FieldValue<char> ReplicationForceIsPlayingField() { return { this, "AMatineeActor.ReplicationForceIsPlaying" }; }

	// Functions

	void AddActorToGroup(FName GroupName, AActor * TheGroupActor) { NativeCall<void, FName, AActor *>(this, "AMatineeActor.AddActorToGroup", GroupName, TheGroupActor); }
	FName * GetFunctionNameForEvent(FName * result, FName EventName) { return NativeCall<FName *, FName *, FName>(this, "AMatineeActor.GetFunctionNameForEvent", result, EventName); }
	void NotifyEventTriggered(FName EventName, float EventTime) { NativeCall<void, FName, float>(this, "AMatineeActor.NotifyEventTriggered", EventName, EventTime); }
	void Play(float OverrideSetPosition, bool bOverridePositionJump) { NativeCall<void, float, bool>(this, "AMatineeActor.Play", OverrideSetPosition, bOverridePositionJump); }
	void Reverse() { NativeCall<void>(this, "AMatineeActor.Reverse"); }
	void Stop() { NativeCall<void>(this, "AMatineeActor.Stop"); }
	void Pause() { NativeCall<void>(this, "AMatineeActor.Pause"); }
	void ChangePlaybackDirection() { NativeCall<void>(this, "AMatineeActor.ChangePlaybackDirection"); }
	void SetLoopingState(bool bNewLooping) { NativeCall<void, bool>(this, "AMatineeActor.SetLoopingState", bNewLooping); }
	void SetPosition(float NewPosition, bool bJump, bool bForceJumpFromBeginningForEvents, bool bSkipMatineeUpdate) { NativeCall<void, float, bool, bool, bool>(this, "AMatineeActor.SetPosition", NewPosition, bJump, bForceJumpFromBeginningForEvents, bSkipMatineeUpdate); }
	void AddPlayerToDirectorTracks(APlayerController * PC) { NativeCall<void, APlayerController *>(this, "AMatineeActor.AddPlayerToDirectorTracks", PC); }
	void Tick(float DeltaTime) { NativeCall<void, float>(this, "AMatineeActor.Tick", DeltaTime); }
	void UpdateStreamingForCameraCuts(float CurrentTime, bool bPreview) { NativeCall<void, float, bool>(this, "AMatineeActor.UpdateStreamingForCameraCuts", CurrentTime, bPreview); }
	void UpdateInterp(float NewPosition, bool bPreview, bool bJump, bool bSkipMatineeUpdate) { NativeCall<void, float, bool, bool, bool>(this, "AMatineeActor.UpdateInterp", NewPosition, bPreview, bJump, bSkipMatineeUpdate); }
	void InitInterp() { NativeCall<void>(this, "AMatineeActor.InitInterp"); }
	void TermInterp() { NativeCall<void>(this, "AMatineeActor.TermInterp"); }
	void SetupCameraCuts() { NativeCall<void>(this, "AMatineeActor.SetupCameraCuts"); }
	bool IsMatineeCompatibleWithPlayer(APlayerController * InPC) { return NativeCall<bool, APlayerController *>(this, "AMatineeActor.IsMatineeCompatibleWithPlayer", InPC); }
	void StepInterp(float DeltaTime, bool bPreview) { NativeCall<void, float, bool>(this, "AMatineeActor.StepInterp", DeltaTime, bPreview); }
	void EnableCinematicMode(bool bEnable) { NativeCall<void, bool>(this, "AMatineeActor.EnableCinematicMode", bEnable); }
	void PostLoadSubobjects(FObjectInstancingGraph * OuterInstanceGraph) { NativeCall<void, FObjectInstancingGraph *>(this, "AMatineeActor.PostLoadSubobjects", OuterInstanceGraph); }
	void UpdateReplicatedData(bool bIsBeginningPlay) { NativeCall<void, bool>(this, "AMatineeActor.UpdateReplicatedData", bIsBeginningPlay); }
	void BeginPlay() { NativeCall<void>(this, "AMatineeActor.BeginPlay"); }
	void ApplyWorldOffset(FVector * InOffset, bool bWorldShift) { NativeCall<void, FVector *, bool>(this, "AMatineeActor.ApplyWorldOffset", InOffset, bWorldShift); }
	void CheckPriorityRefresh() { NativeCall<void>(this, "AMatineeActor.CheckPriorityRefresh"); }
	void PostInitializeComponents() { NativeCall<void>(this, "AMatineeActor.PostInitializeComponents"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "AMatineeActor.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void PreNetReceive() { NativeCall<void>(this, "AMatineeActor.PreNetReceive"); }
	void PostNetReceive() { NativeCall<void>(this, "AMatineeActor.PostNetReceive"); }
	void InitClientMatinee() { NativeCall<void>(this, "AMatineeActor.InitClientMatinee"); }
	static UClass * GetPrivateStaticClass() { return NativeCall<UClass *>(nullptr, "AMatineeActor.GetPrivateStaticClass"); }
};

struct UCharacterMovementComponent
{
	FieldValue<ACharacter *> CharacterOwnerField() { return { this, "UCharacterMovementComponent.CharacterOwner" }; }
	FieldValue<float> MaxStepHeightField() { return { this, "UCharacterMovementComponent.MaxStepHeight" }; }
	FieldValue<float> JumpZVelocityField() { return { this, "UCharacterMovementComponent.JumpZVelocity" }; }
	FieldValue<float> JumpOffJumpZFactorField() { return { this, "UCharacterMovementComponent.JumpOffJumpZFactor" }; }
	FieldValue<bool> bSlipOffLedgesField() { return { this, "UCharacterMovementComponent.bSlipOffLedges" }; }
	FieldValue<float> LedgeSlipCapsuleRadiusMultiplierField() { return { this, "UCharacterMovementComponent.LedgeSlipCapsuleRadiusMultiplier" }; }
	FieldValue<float> LedgeSlipPushVelocityField() { return { this, "UCharacterMovementComponent.LedgeSlipPushVelocity" }; }
	FieldValue<float> LedgeSlipVelocityBuildUpMultiplierField() { return { this, "UCharacterMovementComponent.LedgeSlipVelocityBuildUpMultiplier" }; }
	FieldValue<float> WalkableFloorAngleField() { return { this, "UCharacterMovementComponent.WalkableFloorAngle" }; }
	FieldValue<float> WalkableFloorZField() { return { this, "UCharacterMovementComponent.WalkableFloorZ" }; }
	FieldValue<TEnumAsByte<enum EMovementMode>> MovementModeField() { return { this, "UCharacterMovementComponent.MovementMode" }; }
	FieldValue<char> CustomMovementModeField() { return { this, "UCharacterMovementComponent.CustomMovementMode" }; }
	FieldValue<FVector> OldBaseLocationField() { return { this, "UCharacterMovementComponent.OldBaseLocation" }; }
	FieldValue<FQuat> OldBaseQuatField() { return { this, "UCharacterMovementComponent.OldBaseQuat" }; }
	FieldValue<long double> LastNonZeroAccelField() { return { this, "UCharacterMovementComponent.LastNonZeroAccel" }; }
	FieldValue<float> CurrentLedgeSlipPushVelocityField() { return { this, "UCharacterMovementComponent.CurrentLedgeSlipPushVelocity" }; }
	FieldValue<int> LastFrameDisabledFloorBasingField() { return { this, "UCharacterMovementComponent.LastFrameDisabledFloorBasing" }; }
	FieldValue<long double> ForceBigPushingTimeField() { return { this, "UCharacterMovementComponent.ForceBigPushingTime" }; }
	FieldValue<float> GravityScaleField() { return { this, "UCharacterMovementComponent.GravityScale" }; }
	FieldValue<float> GroundFrictionField() { return { this, "UCharacterMovementComponent.GroundFriction" }; }
	FieldValue<float> MaxWalkSpeedField() { return { this, "UCharacterMovementComponent.MaxWalkSpeed" }; }
	FieldValue<float> MaxWalkSpeedCrouchedField() { return { this, "UCharacterMovementComponent.MaxWalkSpeedCrouched" }; }
	FieldValue<float> MaxWalkSpeedProneField() { return { this, "UCharacterMovementComponent.MaxWalkSpeedProne" }; }
	FieldValue<float> MaxCustomMovementSpeedField() { return { this, "UCharacterMovementComponent.MaxCustomMovementSpeed" }; }
	FieldValue<float> MaxSwimSpeedField() { return { this, "UCharacterMovementComponent.MaxSwimSpeed" }; }
	FieldValue<float> MaxFlySpeedField() { return { this, "UCharacterMovementComponent.MaxFlySpeed" }; }
	FieldValue<float> LandedPreventRequestedMoveIntervalField() { return { this, "UCharacterMovementComponent.LandedPreventRequestedMoveInterval" }; }
	FieldValue<float> LandedPreventRequestedMoveMinVelocityMagnitudeField() { return { this, "UCharacterMovementComponent.LandedPreventRequestedMoveMinVelocityMagnitude" }; }
	FieldValue<float> MinimumImpulseToApplyField() { return { this, "UCharacterMovementComponent.MinimumImpulseToApply" }; }
	FieldValue<long double> LastLandedTimeField() { return { this, "UCharacterMovementComponent.LastLandedTime" }; }
	FieldValue<float> MaxAccelerationField() { return { this, "UCharacterMovementComponent.MaxAcceleration" }; }
	FieldValue<float> MaxImpulseVelocityMagnitudeField() { return { this, "UCharacterMovementComponent.MaxImpulseVelocityMagnitude" }; }
	FieldValue<float> MaxImpulseVelocityZField() { return { this, "UCharacterMovementComponent.MaxImpulseVelocityZ" }; }
	FieldValue<float> BrakingDecelerationWalkingField() { return { this, "UCharacterMovementComponent.BrakingDecelerationWalking" }; }
	FieldValue<float> BrakingDecelerationFallingField() { return { this, "UCharacterMovementComponent.BrakingDecelerationFalling" }; }
	FieldValue<float> BrakingDecelerationSwimmingField() { return { this, "UCharacterMovementComponent.BrakingDecelerationSwimming" }; }
	FieldValue<float> BrakingDecelerationFlyingField() { return { this, "UCharacterMovementComponent.BrakingDecelerationFlying" }; }
	FieldValue<float> AirControlField() { return { this, "UCharacterMovementComponent.AirControl" }; }
	FieldValue<float> AirControlBoostMultiplierField() { return { this, "UCharacterMovementComponent.AirControlBoostMultiplier" }; }
	FieldValue<float> AirControlBoostVelocityThresholdField() { return { this, "UCharacterMovementComponent.AirControlBoostVelocityThreshold" }; }
	FieldValue<float> FallingLateralFrictionField() { return { this, "UCharacterMovementComponent.FallingLateralFriction" }; }
	FieldValue<float> CrouchedHalfHeightField() { return { this, "UCharacterMovementComponent.CrouchedHalfHeight" }; }
	FieldValue<float> ProneHalfHeightField() { return { this, "UCharacterMovementComponent.ProneHalfHeight" }; }
	FieldValue<float> BuoyancyField() { return { this, "UCharacterMovementComponent.Buoyancy" }; }
	FieldValue<float> PerchRadiusThresholdField() { return { this, "UCharacterMovementComponent.PerchRadiusThreshold" }; }
	FieldValue<float> PerchAdditionalHeightField() { return { this, "UCharacterMovementComponent.PerchAdditionalHeight" }; }
	FieldValue<FRotator> RotationRateField() { return { this, "UCharacterMovementComponent.RotationRate" }; }
	FieldValue<UPrimitiveComponent *> DeferredUpdatedMoveComponentField() { return { this, "UCharacterMovementComponent.DeferredUpdatedMoveComponent" }; }
	FieldValue<float> MaxOutOfWaterStepHeightField() { return { this, "UCharacterMovementComponent.MaxOutOfWaterStepHeight" }; }
	FieldValue<float> OutofWaterZField() { return { this, "UCharacterMovementComponent.OutofWaterZ" }; }
	FieldValue<float> MassField() { return { this, "UCharacterMovementComponent.Mass" }; }
	FieldValue<float> DinoClientPositionErrorToleranceStoppedField() { return { this, "UCharacterMovementComponent.DinoClientPositionErrorToleranceStopped" }; }
	FieldValue<float> DinoClientPositionErrorToleranceMovingFlyingField() { return { this, "UCharacterMovementComponent.DinoClientPositionErrorToleranceMovingFlying" }; }
	FieldValue<float> PlayerClientPositionErrorToleranceOverrideField() { return { this, "UCharacterMovementComponent.PlayerClientPositionErrorToleranceOverride" }; }
	FieldValue<float> SimulatedTickSkipDistanceSQField() { return { this, "UCharacterMovementComponent.SimulatedTickSkipDistanceSQ" }; }
	FieldValue<bool> bEnablePhysicsInteractionField() { return { this, "UCharacterMovementComponent.bEnablePhysicsInteraction" }; }
	FieldValue<bool> bTouchForceScaledToMassField() { return { this, "UCharacterMovementComponent.bTouchForceScaledToMass" }; }
	FieldValue<bool> bPushForceScaledToMassField() { return { this, "UCharacterMovementComponent.bPushForceScaledToMass" }; }
	FieldValue<bool> bScalePushForceToVelocityField() { return { this, "UCharacterMovementComponent.bScalePushForceToVelocity" }; }
	FieldValue<float> StandingDownwardForceScaleField() { return { this, "UCharacterMovementComponent.StandingDownwardForceScale" }; }
	FieldValue<float> InitialPushForceFactorField() { return { this, "UCharacterMovementComponent.InitialPushForceFactor" }; }
	FieldValue<float> PushForceFactorField() { return { this, "UCharacterMovementComponent.PushForceFactor" }; }
	FieldValue<float> PushForcePointZOffsetFactorField() { return { this, "UCharacterMovementComponent.PushForcePointZOffsetFactor" }; }
	FieldValue<float> TouchForceFactorField() { return { this, "UCharacterMovementComponent.TouchForceFactor" }; }
	FieldValue<float> MinTouchForceField() { return { this, "UCharacterMovementComponent.MinTouchForce" }; }
	FieldValue<float> MaxTouchForceField() { return { this, "UCharacterMovementComponent.MaxTouchForce" }; }
	FieldValue<float> RepulsionForceField() { return { this, "UCharacterMovementComponent.RepulsionForce" }; }
	FieldValue<FVector> LastUpdateLocationField() { return { this, "UCharacterMovementComponent.LastUpdateLocation" }; }
	FieldValue<FVector> MoveStartLocationField() { return { this, "UCharacterMovementComponent.MoveStartLocation" }; }
	FieldValue<float> AnalogInputModifierField() { return { this, "UCharacterMovementComponent.AnalogInputModifier" }; }
	FieldValue<float> BackwardsMaxSpeedMultiplierField() { return { this, "UCharacterMovementComponent.BackwardsMaxSpeedMultiplier" }; }
	FieldValue<float> BackwardsMovementDotThresholdField() { return { this, "UCharacterMovementComponent.BackwardsMovementDotThreshold" }; }
	FieldValue<FVector> PendingForceToApplyField() { return { this, "UCharacterMovementComponent.PendingForceToApply" }; }
	FieldValue<FVector> PendingImpulseToApplyField() { return { this, "UCharacterMovementComponent.PendingImpulseToApply" }; }
	FieldValue<FVector> AccelerationField() { return { this, "UCharacterMovementComponent.Acceleration" }; }
	FieldValue<float> MaxSimulationTimeStepField() { return { this, "UCharacterMovementComponent.MaxSimulationTimeStep" }; }
	FieldValue<int> MaxSimulationIterationsField() { return { this, "UCharacterMovementComponent.MaxSimulationIterations" }; }
	FieldValue<float> LedgeCheckThresholdField() { return { this, "UCharacterMovementComponent.LedgeCheckThreshold" }; }
	FieldValue<float> JumpOutOfWaterPitchField() { return { this, "UCharacterMovementComponent.JumpOutOfWaterPitch" }; }
	FieldValue<float> UpperImpactNormalScaleField() { return { this, "UCharacterMovementComponent.UpperImpactNormalScale" }; }
	FieldValue<TEnumAsByte<enum EMovementMode>> DefaultLandMovementModeField() { return { this, "UCharacterMovementComponent.DefaultLandMovementMode" }; }
	FieldValue<TEnumAsByte<enum EMovementMode>> DefaultWaterMovementModeField() { return { this, "UCharacterMovementComponent.DefaultWaterMovementMode" }; }
	FieldValue<float> PreventWaterHoppingPlaneOffsetField() { return { this, "UCharacterMovementComponent.PreventWaterHoppingPlaneOffset" }; }
	FieldValue<long double> PreventWaterHopping_LastTimeAtSurfaceField() { return { this, "UCharacterMovementComponent.PreventWaterHopping_LastTimeAtSurface" }; }
	FieldValue<float> AccelerationFollowsRotationMinDotField() { return { this, "UCharacterMovementComponent.AccelerationFollowsRotationMinDot" }; }
	FieldValue<float> AccelerationFollowsRotationStopDistanceField() { return { this, "UCharacterMovementComponent.AccelerationFollowsRotationStopDistance" }; }
	FieldValue<float> RotationAccelerationField() { return { this, "UCharacterMovementComponent.RotationAcceleration" }; }
	FieldValue<float> RotationBrakingField() { return { this, "UCharacterMovementComponent.RotationBraking" }; }
	FieldValue<float> AngleToStartRotationBrakingField() { return { this, "UCharacterMovementComponent.AngleToStartRotationBraking" }; }
	FieldValue<float> SwimmingAccelZMultiplierField() { return { this, "UCharacterMovementComponent.SwimmingAccelZMultiplier" }; }
	FieldValue<float> TamedSwimmingAccelZMultiplierField() { return { this, "UCharacterMovementComponent.TamedSwimmingAccelZMultiplier" }; }
	FieldValue<bool> bHACKTickedField() { return { this, "UCharacterMovementComponent.bHACKTicked" }; }
	FieldValue<bool> bHackTestDisableRotationCodeField() { return { this, "UCharacterMovementComponent.bHackTestDisableRotationCode" }; }
	FieldValue<FVector> LastForcedNetVelocityField() { return { this, "UCharacterMovementComponent.LastForcedNetVelocity" }; }
	FieldValue<long double> LastStepUpTimeField() { return { this, "UCharacterMovementComponent.LastStepUpTime" }; }
	FieldValue<int> BadFloorPenetrationCountField() { return { this, "UCharacterMovementComponent.BadFloorPenetrationCount" }; }
	FieldValue<FVector> AvoidanceLockVelocityField() { return { this, "UCharacterMovementComponent.AvoidanceLockVelocity" }; }
	FieldValue<float> AvoidanceLockTimerField() { return { this, "UCharacterMovementComponent.AvoidanceLockTimer" }; }
	FieldValue<long double> LastSkippedMoveTimeField() { return { this, "UCharacterMovementComponent.LastSkippedMoveTime" }; }
	FieldValue<long double> LastSwimTimeField() { return { this, "UCharacterMovementComponent.LastSwimTime" }; }
	FieldValue<FRotator> CurrentRotationSpeedField() { return { this, "UCharacterMovementComponent.CurrentRotationSpeed" }; }
	FieldValue<FVector> RequestedVelocityField() { return { this, "UCharacterMovementComponent.RequestedVelocity" }; }
	FieldValue<long double> DisableMovementPhysicsUntilTimeField() { return { this, "UCharacterMovementComponent.DisableMovementPhysicsUntilTime" }; }
	FieldValue<float> LostDeltaTimeField() { return { this, "UCharacterMovementComponent.LostDeltaTime" }; }
	FieldValue<float> LastLostDeltaTimeField() { return { this, "UCharacterMovementComponent.LastLostDeltaTime" }; }
	FieldValue<int> AvoidanceUIDField() { return { this, "UCharacterMovementComponent.AvoidanceUID" }; }
	FieldValue<float> AvoidanceWeightField() { return { this, "UCharacterMovementComponent.AvoidanceWeight" }; }
	FieldValue<FVector> PendingLaunchVelocityField() { return { this, "UCharacterMovementComponent.PendingLaunchVelocity" }; }
	FieldValue<float> MinTimeBetweenTimeStampResetsField() { return { this, "UCharacterMovementComponent.MinTimeBetweenTimeStampResets" }; }
	FieldValue<bool> bWasSimulatingRootMotionField() { return { this, "UCharacterMovementComponent.bWasSimulatingRootMotion" }; }
	FieldValue<FVector> LastCheckedFloorAtRelativeLocField() { return { this, "UCharacterMovementComponent.LastCheckedFloorAtRelativeLoc" }; }

	// Functions

	bool HasPredictionData_Server() { return NativeCall<bool>(this, "UCharacterMovementComponent.HasPredictionData_Server"); }
	bool HasPredictionData_Client() { return NativeCall<bool>(this, "UCharacterMovementComponent.HasPredictionData_Client"); }
	UObject * GetUObjectInterfaceNetworkPredictionInterface() { return NativeCall<UObject *>(this, "UCharacterMovementComponent.GetUObjectInterfaceNetworkPredictionInterface"); }
	float GetJumpZVelocity() { return NativeCall<float>(this, "UCharacterMovementComponent.GetJumpZVelocity"); }
	void OnUnregister() { NativeCall<void>(this, "UCharacterMovementComponent.OnUnregister"); }
	void PostLoad() { NativeCall<void>(this, "UCharacterMovementComponent.PostLoad"); }
	void OnRegister() { NativeCall<void>(this, "UCharacterMovementComponent.OnRegister"); }
	void BeginDestroy() { NativeCall<void>(this, "UCharacterMovementComponent.BeginDestroy"); }
	void SetUpdatedComponent(UPrimitiveComponent * NewUpdatedComponent) { NativeCall<void, UPrimitiveComponent *>(this, "UCharacterMovementComponent.SetUpdatedComponent", NewUpdatedComponent); }
	bool HasValidData() { return NativeCall<bool>(this, "UCharacterMovementComponent.HasValidData"); }
	bool DoJump(bool bReplayingMoves) { return NativeCall<bool, bool>(this, "UCharacterMovementComponent.DoJump", bReplayingMoves); }
	FVector * GetImpartedMovementBaseVelocity(FVector * result) { return NativeCall<FVector *, FVector *>(this, "UCharacterMovementComponent.GetImpartedMovementBaseVelocity", result); }
	void Launch(FVector * LaunchVel, bool bNoLowerVelocity) { NativeCall<void, FVector *, bool>(this, "UCharacterMovementComponent.Launch", LaunchVel, bNoLowerVelocity); }
	bool HandlePendingLaunch() { return NativeCall<bool>(this, "UCharacterMovementComponent.HandlePendingLaunch"); }
	void JumpOff(AActor * MovementBaseActor) { NativeCall<void, AActor *>(this, "UCharacterMovementComponent.JumpOff", MovementBaseActor); }
	FVector * GetBestDirectionOffActor(FVector * result, AActor * BaseActor) { return NativeCall<FVector *, FVector *, AActor *>(this, "UCharacterMovementComponent.GetBestDirectionOffActor", result, BaseActor); }
	float GetNetworkSafeRandomAngleDegrees() { return NativeCall<float>(this, "UCharacterMovementComponent.GetNetworkSafeRandomAngleDegrees"); }
	void SetDefaultMovementMode() { NativeCall<void>(this, "UCharacterMovementComponent.SetDefaultMovementMode"); }
	void SetMovementMode(EMovementMode NewMovementMode, char NewCustomMode) { NativeCall<void, EMovementMode, char>(this, "UCharacterMovementComponent.SetMovementMode", NewMovementMode, NewCustomMode); }
	void OnMovementModeChanged(EMovementMode PreviousMovementMode, char PreviousCustomMode) { NativeCall<void, EMovementMode, char>(this, "UCharacterMovementComponent.OnMovementModeChanged", PreviousMovementMode, PreviousCustomMode); }
	void ApplyNetworkMovementMode(const char ReceivedMode) { NativeCall<void, const char>(this, "UCharacterMovementComponent.ApplyNetworkMovementMode", ReceivedMode); }
	void PerformAirControl(FVector Direction, float ZDiff) { NativeCall<void, FVector, float>(this, "UCharacterMovementComponent.PerformAirControl", Direction, ZDiff); }
	void PerformAirControlForPathFollowing(FVector Direction, float ZDiff) { NativeCall<void, FVector, float>(this, "UCharacterMovementComponent.PerformAirControlForPathFollowing", Direction, ZDiff); }
	void ExecuteStoredMoves() { NativeCall<void>(this, "UCharacterMovementComponent.ExecuteStoredMoves"); }
	void AdjustProxyCapsuleSize() { NativeCall<void>(this, "UCharacterMovementComponent.AdjustProxyCapsuleSize"); }
	void SimulatedTick(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.SimulatedTick", DeltaSeconds); }
	void SimulateRootMotion(float DeltaSeconds, FTransform * LocalRootMotionTransform) { NativeCall<void, float, FTransform *>(this, "UCharacterMovementComponent.SimulateRootMotion", DeltaSeconds, LocalRootMotionTransform); }
	void SimulateMovement(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.SimulateMovement", DeltaSeconds); }
	UPrimitiveComponent * GetMovementBase() { return NativeCall<UPrimitiveComponent *>(this, "UCharacterMovementComponent.GetMovementBase"); }
	void SetBase(UPrimitiveComponent * NewBase, FName BoneName, bool bNotifyActor) { NativeCall<void, UPrimitiveComponent *, FName, bool>(this, "UCharacterMovementComponent.SetBase", NewBase, BoneName, bNotifyActor); }
	void MaybeUpdateBasedMovement(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.MaybeUpdateBasedMovement", DeltaSeconds); }
	void MaybeSaveBaseLocation() { NativeCall<void>(this, "UCharacterMovementComponent.MaybeSaveBaseLocation"); }
	void UpdateBasedMovement(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.UpdateBasedMovement", DeltaSeconds); }
	void UpdateBasedRotation(FRotator * FinalRotation, FRotator * ReducedRotation) { NativeCall<void, FRotator *, FRotator *>(this, "UCharacterMovementComponent.UpdateBasedRotation", FinalRotation, ReducedRotation); }
	void DisableMovement() { NativeCall<void>(this, "UCharacterMovementComponent.DisableMovement"); }
	void PerformMovement(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.PerformMovement", DeltaSeconds); }
	void CallMovementUpdateDelegate(float DeltaTime, FVector * OldLocation, FVector * OldVelocity) { NativeCall<void, float, FVector *, FVector *>(this, "UCharacterMovementComponent.CallMovementUpdateDelegate", DeltaTime, OldLocation, OldVelocity); }
	void SaveBaseLocation() { NativeCall<void>(this, "UCharacterMovementComponent.SaveBaseLocation"); }
	bool CanCrouchInCurrentState() { return NativeCall<bool>(this, "UCharacterMovementComponent.CanCrouchInCurrentState"); }
	bool CanProneInCurrentState() { return NativeCall<bool>(this, "UCharacterMovementComponent.CanProneInCurrentState"); }
	void Crouch(bool bClientSimulation) { NativeCall<void, bool>(this, "UCharacterMovementComponent.Crouch", bClientSimulation); }
	void UnCrouch(bool bClientSimulation, bool bForce) { NativeCall<void, bool, bool>(this, "UCharacterMovementComponent.UnCrouch", bClientSimulation, bForce); }
	void StartNewPhysics(float deltaTime, int Iterations) { NativeCall<void, float, int>(this, "UCharacterMovementComponent.StartNewPhysics", deltaTime, Iterations); }
	float GetGravityZ() { return NativeCall<float>(this, "UCharacterMovementComponent.GetGravityZ"); }
	float GetMaxSpeed() { return NativeCall<float>(this, "UCharacterMovementComponent.GetMaxSpeed"); }
	bool ResolvePenetrationImpl(FVector * Adjustment, FHitResult * Hit, FQuat * NewRotation) { return NativeCall<bool, FVector *, FHitResult *, FQuat *>(this, "UCharacterMovementComponent.ResolvePenetrationImpl", Adjustment, Hit, NewRotation); }
	float SlideAlongSurface(FVector * Delta, float Time, FVector * InNormal, FHitResult * Hit, bool bHandleImpact) { return NativeCall<float, FVector *, float, FVector *, FHitResult *, bool>(this, "UCharacterMovementComponent.SlideAlongSurface", Delta, Time, InNormal, Hit, bHandleImpact); }
	void TwoWallAdjust(FVector * Delta, FHitResult * Hit, FVector * OldHitNormal) { NativeCall<void, FVector *, FHitResult *, FVector *>(this, "UCharacterMovementComponent.TwoWallAdjust", Delta, Hit, OldHitNormal); }
	FVector * ComputeSlideVector(FVector * result, FVector * InDelta, const float Time, FVector * Normal, FHitResult * Hit) { return NativeCall<FVector *, FVector *, FVector *, const float, FVector *, FHitResult *>(this, "UCharacterMovementComponent.ComputeSlideVector", result, InDelta, Time, Normal, Hit); }
	FVector * HandleSlopeBoosting(FVector * result, FVector * SlideResult, FVector * Delta, const float Time, FVector * Normal, FHitResult * Hit) { return NativeCall<FVector *, FVector *, FVector *, FVector *, const float, FVector *, FHitResult *>(this, "UCharacterMovementComponent.HandleSlopeBoosting", result, SlideResult, Delta, Time, Normal, Hit); }
	FVector * AdjustUpperHemisphereImpact(FVector * result, FVector * Delta, FHitResult * Hit) { return NativeCall<FVector *, FVector *, FVector *, FHitResult *>(this, "UCharacterMovementComponent.AdjustUpperHemisphereImpact", result, Delta, Hit); }
	FVector * NewFallVelocity(FVector * result, FVector * InitialVelocity, FVector * Gravity, float DeltaTime) { return NativeCall<FVector *, FVector *, FVector *, FVector *, float>(this, "UCharacterMovementComponent.NewFallVelocity", result, InitialVelocity, Gravity, DeltaTime); }
	float ImmersionDepth(bool bUseLineTrace) { return NativeCall<float, bool>(this, "UCharacterMovementComponent.ImmersionDepth", bUseLineTrace); }
	bool IsFlying() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsFlying"); }
	bool IsMovingOnGround() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsMovingOnGround"); }
	bool IsFalling() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsFalling"); }
	bool IsSwimming() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsSwimming"); }
	bool IsCrouching() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsCrouching"); }
	bool IsProne() { return NativeCall<bool>(this, "UCharacterMovementComponent.IsProne"); }
	void CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration) { NativeCall<void, float, float, bool, float>(this, "UCharacterMovementComponent.CalcVelocity", DeltaTime, Friction, bFluid, BrakingDeceleration); }
	bool ApplyRequestedMove(float DeltaTime, float MaxAccel, float MaxSpeed, float Friction, float BrakingDeceleration, FVector * OutAcceleration, float * OutRequestedSpeed) { return NativeCall<bool, float, float, float, float, float, FVector *, float *>(this, "UCharacterMovementComponent.ApplyRequestedMove", DeltaTime, MaxAccel, MaxSpeed, Friction, BrakingDeceleration, OutAcceleration, OutRequestedSpeed); }
	void RequestDirectMove(FVector * MoveVelocity, bool bForceMaxSpeed) { NativeCall<void, FVector *, bool>(this, "UCharacterMovementComponent.RequestDirectMove", MoveVelocity, bForceMaxSpeed); }
	bool CanStopPathFollowing() { return NativeCall<bool>(this, "UCharacterMovementComponent.CanStopPathFollowing"); }
	void NotifyBumpedPawn(APawn * BumpedPawn) { NativeCall<void, APawn *>(this, "UCharacterMovementComponent.NotifyBumpedPawn", BumpedPawn); }
	float GetMaxJumpHeight() { return NativeCall<float>(this, "UCharacterMovementComponent.GetMaxJumpHeight"); }
	float GetModifiedMaxAcceleration() { return NativeCall<float>(this, "UCharacterMovementComponent.GetModifiedMaxAcceleration"); }
	float K2_GetModifiedMaxAcceleration() { return NativeCall<float>(this, "UCharacterMovementComponent.K2_GetModifiedMaxAcceleration"); }
	float GetMaxAcceleration() { return NativeCall<float>(this, "UCharacterMovementComponent.GetMaxAcceleration"); }
	void ApplyVelocityBraking(float DeltaTime, float Friction, float BrakingDeceleration) { NativeCall<void, float, float, float>(this, "UCharacterMovementComponent.ApplyVelocityBraking", DeltaTime, Friction, BrakingDeceleration); }
	bool PhysFlyingAsync(float deltaTime, int Iterations, float friction, float brakingDeceleration) { return NativeCall<bool, float, int, float, float>(this, "UCharacterMovementComponent.PhysFlyingAsync", deltaTime, Iterations, friction, brakingDeceleration); }
	void PhysFlying(float deltaTime, int Iterations, float friction, float brakingDeceleration) { NativeCall<void, float, int, float, float>(this, "UCharacterMovementComponent.PhysFlying", deltaTime, Iterations, friction, brakingDeceleration); }
	void PhysSwimming(float deltaTime, int Iterations) { NativeCall<void, float, int>(this, "UCharacterMovementComponent.PhysSwimming", deltaTime, Iterations); }
	void StartSwimming(FVector OldLocation, FVector OldVelocity, float timeTick, float remainingTime, int Iterations) { NativeCall<void, FVector, FVector, float, float, int>(this, "UCharacterMovementComponent.StartSwimming", OldLocation, OldVelocity, timeTick, remainingTime, Iterations); }
	float Swim(FVector Delta, FHitResult * Hit) { return NativeCall<float, FVector, FHitResult *>(this, "UCharacterMovementComponent.Swim", Delta, Hit); }
	FVector * FindWaterLine(FVector * result, FVector InWater, FVector OutofWater) { return NativeCall<FVector *, FVector *, FVector, FVector>(this, "UCharacterMovementComponent.FindWaterLine", result, InWater, OutofWater); }
	void NotifyJumpApex() { NativeCall<void>(this, "UCharacterMovementComponent.NotifyJumpApex"); }
	FVector * GetFallingLateralAcceleration(FVector * result, float DeltaTime) { return NativeCall<FVector *, FVector *, float>(this, "UCharacterMovementComponent.GetFallingLateralAcceleration", result, DeltaTime); }
	float GetAirControl(float DeltaTime, float TickAirControl, FVector * FallAcceleration) { return NativeCall<float, float, float, FVector *>(this, "UCharacterMovementComponent.GetAirControl", DeltaTime, TickAirControl, FallAcceleration); }
	float BoostAirControl(float DeltaTime, float TickAirControl, FVector * FallAcceleration) { return NativeCall<float, float, float, FVector *>(this, "UCharacterMovementComponent.BoostAirControl", DeltaTime, TickAirControl, FallAcceleration); }
	void PhysFalling(float deltaTime, int Iterations) { NativeCall<void, float, int>(this, "UCharacterMovementComponent.PhysFalling", deltaTime, Iterations); }
	bool FindAirControlImpact(float DeltaTime, float TickAirControl, FVector * FallAcceleration, FHitResult * OutHitResult) { return NativeCall<bool, float, float, FVector *, FHitResult *>(this, "UCharacterMovementComponent.FindAirControlImpact", DeltaTime, TickAirControl, FallAcceleration, OutHitResult); }
	float LimitAirControl(float DeltaTime, float TickAirControl, FVector * FallAcceleration, FHitResult * HitResult) { return NativeCall<float, float, float, FVector *, FHitResult *>(this, "UCharacterMovementComponent.LimitAirControl", DeltaTime, TickAirControl, FallAcceleration, HitResult); }
	bool CheckLedgeDirection(FVector * OldLocation, FVector * SideStep, FVector * GravDir) { return NativeCall<bool, FVector *, FVector *, FVector *>(this, "UCharacterMovementComponent.CheckLedgeDirection", OldLocation, SideStep, GravDir); }
	FVector * GetLedgeMove(FVector * result, FVector * OldLocation, FVector * Delta, FVector * GravDir) { return NativeCall<FVector *, FVector *, FVector *, FVector *, FVector *>(this, "UCharacterMovementComponent.GetLedgeMove", result, OldLocation, Delta, GravDir); }
	bool CanWalkOffLedges() { return NativeCall<bool>(this, "UCharacterMovementComponent.CanWalkOffLedges"); }
	bool CheckFall(FHitResult * Hit, FVector Delta, FVector subLoc, float remainingTime, float timeTick, int Iterations, bool bMustJump) { return NativeCall<bool, FHitResult *, FVector, FVector, float, float, int, bool>(this, "UCharacterMovementComponent.CheckFall", Hit, Delta, subLoc, remainingTime, timeTick, Iterations, bMustJump); }
	void StartFalling(int Iterations, float remainingTime, float timeTick, FVector * Delta, FVector * subLoc) { NativeCall<void, int, float, float, FVector *, FVector *>(this, "UCharacterMovementComponent.StartFalling", Iterations, remainingTime, timeTick, Delta, subLoc); }
	FVector * ComputeGroundMovementDelta(FVector * result, FVector * Delta, FHitResult * RampHit, const bool bHitFromLineTrace) { return NativeCall<FVector *, FVector *, FVector *, FHitResult *, const bool>(this, "UCharacterMovementComponent.ComputeGroundMovementDelta", result, Delta, RampHit, bHitFromLineTrace); }
	void MaintainHorizontalGroundVelocity() { NativeCall<void>(this, "UCharacterMovementComponent.MaintainHorizontalGroundVelocity"); }
	bool PhysWalkingAsync(float deltaTime, int Iterations) { return NativeCall<bool, float, int>(this, "UCharacterMovementComponent.PhysWalkingAsync", deltaTime, Iterations); }
	void PhysWalking(float deltaTime, int Iterations) { NativeCall<void, float, int>(this, "UCharacterMovementComponent.PhysWalking", deltaTime, Iterations); }
	void PhysCustom(float deltaTime, int Iterations) { NativeCall<void, float, int>(this, "UCharacterMovementComponent.PhysCustom", deltaTime, Iterations); }
	void AdjustFloorHeight() { NativeCall<void>(this, "UCharacterMovementComponent.AdjustFloorHeight"); }
	void StopActiveMovement() { NativeCall<void>(this, "UCharacterMovementComponent.StopActiveMovement"); }
	void ProcessLanded(FHitResult * Hit, float remainingTime, int Iterations) { NativeCall<void, FHitResult *, float, int>(this, "UCharacterMovementComponent.ProcessLanded", Hit, remainingTime, Iterations); }
	void SetPostLandedPhysics(FHitResult * Hit) { NativeCall<void, FHitResult *>(this, "UCharacterMovementComponent.SetPostLandedPhysics", Hit); }
	void OnTeleported() { NativeCall<void>(this, "UCharacterMovementComponent.OnTeleported"); }
	FRotator * GetDeltaRotation(FRotator * result, float DeltaTime) { return NativeCall<FRotator *, FRotator *, float>(this, "UCharacterMovementComponent.GetDeltaRotation", result, DeltaTime); }
	FRotator * ComputeOrientToMovementRotation(FRotator * result, FRotator * CurrentRotation, float DeltaTime, FRotator * DeltaRotation) { return NativeCall<FRotator *, FRotator *, FRotator *, float, FRotator *>(this, "UCharacterMovementComponent.ComputeOrientToMovementRotation", result, CurrentRotation, DeltaTime, DeltaRotation); }
	void PhysicsRotation(float DeltaTime) { NativeCall<void, float>(this, "UCharacterMovementComponent.PhysicsRotation", DeltaTime); }
	bool ShouldJumpOutOfWater(FVector * JumpDir) { return NativeCall<bool, FVector *>(this, "UCharacterMovementComponent.ShouldJumpOutOfWater", JumpDir); }
	void ServerJumpOutOfWater_Implementation(FVector_NetQuantize100 WallNormal, char JumpFlag) { NativeCall<void, FVector_NetQuantize100, char>(this, "UCharacterMovementComponent.ServerJumpOutOfWater_Implementation", WallNormal, JumpFlag); }
	bool CheckWaterJump(FVector CheckPoint, FVector * WallNormal) { return NativeCall<bool, FVector, FVector *>(this, "UCharacterMovementComponent.CheckWaterJump", CheckPoint, WallNormal); }
	void AddImpulse(FVector Impulse, bool bVelocityChange, float MassScaleImpulseExponent, bool bOverrideMaxImpulseZ) { NativeCall<void, FVector, bool, float, bool>(this, "UCharacterMovementComponent.AddImpulse", Impulse, bVelocityChange, MassScaleImpulseExponent, bOverrideMaxImpulseZ); }
	void AddForce(FVector Force) { NativeCall<void, FVector>(this, "UCharacterMovementComponent.AddForce", Force); }
	bool IsWalkable(FHitResult * Hit) { return NativeCall<bool, FHitResult *>(this, "UCharacterMovementComponent.IsWalkable", Hit); }
	void SetWalkableFloorZ(float InWalkableFloorZ) { NativeCall<void, float>(this, "UCharacterMovementComponent.SetWalkableFloorZ", InWalkableFloorZ); }
	bool IsWithinEdgeTolerance(FVector * CapsuleLocation, FVector * TestImpactPoint, const float CapsuleRadius) { return NativeCall<bool, FVector *, FVector *, const float>(this, "UCharacterMovementComponent.IsWithinEdgeTolerance", CapsuleLocation, TestImpactPoint, CapsuleRadius); }
	bool IsValidLandingSpot(FVector * CapsuleLocation, FHitResult * Hit) { return NativeCall<bool, FVector *, FHitResult *>(this, "UCharacterMovementComponent.IsValidLandingSpot", CapsuleLocation, Hit); }
	bool ShouldCheckForValidLandingSpot(float DeltaTime, FVector * Delta, FHitResult * Hit) { return NativeCall<bool, float, FVector *, FHitResult *>(this, "UCharacterMovementComponent.ShouldCheckForValidLandingSpot", DeltaTime, Delta, Hit); }
	float GetPerchRadiusThreshold() { return NativeCall<float>(this, "UCharacterMovementComponent.GetPerchRadiusThreshold"); }
	float GetValidPerchRadius() { return NativeCall<float>(this, "UCharacterMovementComponent.GetValidPerchRadius"); }
	bool ShouldComputePerchResult(FHitResult * InHit, bool bCheckRadius) { return NativeCall<bool, FHitResult *, bool>(this, "UCharacterMovementComponent.ShouldComputePerchResult", InHit, bCheckRadius); }
	bool CanStepUp(FHitResult * Hit) { return NativeCall<bool, FHitResult *>(this, "UCharacterMovementComponent.CanStepUp", Hit); }
	void HandleImpact(FHitResult * Impact, float TimeSlice, FVector * MoveDelta) { NativeCall<void, FHitResult *, float, FVector *>(this, "UCharacterMovementComponent.HandleImpact", Impact, TimeSlice, MoveDelta); }
	void ApplyImpactPhysicsForces(FHitResult * Impact, FVector * ImpactAcceleration, FVector * ImpactVelocity) { NativeCall<void, FHitResult *, FVector *, FVector *>(this, "UCharacterMovementComponent.ApplyImpactPhysicsForces", Impact, ImpactAcceleration, ImpactVelocity); }
	FString * GetMovementName(FString * result) { return NativeCall<FString *, FString *>(this, "UCharacterMovementComponent.GetMovementName", result); }
	void ForceReplicationUpdate() { NativeCall<void>(this, "UCharacterMovementComponent.ForceReplicationUpdate"); }
	FVector * ConstrainInputAcceleration(FVector * result, FVector * InputAcceleration) { return NativeCall<FVector *, FVector *, FVector *>(this, "UCharacterMovementComponent.ConstrainInputAcceleration", result, InputAcceleration); }
	FVector * ScaleInputAcceleration(FVector * result, FVector * InputAcceleration) { return NativeCall<FVector *, FVector *, FVector *>(this, "UCharacterMovementComponent.ScaleInputAcceleration", result, InputAcceleration); }
	float ComputeAnalogInputModifier() { return NativeCall<float>(this, "UCharacterMovementComponent.ComputeAnalogInputModifier"); }
	bool ClientUpdatePositionAfterServerUpdate() { return NativeCall<bool>(this, "UCharacterMovementComponent.ClientUpdatePositionAfterServerUpdate"); }
	void ForcePositionUpdate(float DeltaTime) { NativeCall<void, float>(this, "UCharacterMovementComponent.ForcePositionUpdate", DeltaTime); }
	void ResetPredictionData_Client() { NativeCall<void>(this, "UCharacterMovementComponent.ResetPredictionData_Client"); }
	void ResetPredictionData_Server() { NativeCall<void>(this, "UCharacterMovementComponent.ResetPredictionData_Server"); }
	void ReplicateMoveToServer(float DeltaTime, FVector * NewAcceleration) { NativeCall<void, float, FVector *>(this, "UCharacterMovementComponent.ReplicateMoveToServer", DeltaTime, NewAcceleration); }
	void ServerMoveOld_Implementation(float OldTimeStamp, FVector_NetQuantize100 OldAccel, char OldMoveFlags) { NativeCall<void, float, FVector_NetQuantize100, char>(this, "UCharacterMovementComponent.ServerMoveOld_Implementation", OldTimeStamp, OldAccel, OldMoveFlags); }
	void ServerMoveWithRotation_Implementation(float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char MoveFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode, FRotator ClientRotation) { NativeCall<void, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char, FRotator>(this, "UCharacterMovementComponent.ServerMoveWithRotation_Implementation", TimeStamp, InAccel, ClientLoc, MoveFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode, ClientRotation); }
	void ServerMoveOldWithRotation_Implementation(float OldTimeStamp, FVector_NetQuantize100 OldAccel, char OldMoveFlags, FRotator OldRotation) { NativeCall<void, float, FVector_NetQuantize100, char, FRotator>(this, "UCharacterMovementComponent.ServerMoveOldWithRotation_Implementation", OldTimeStamp, OldAccel, OldMoveFlags, OldRotation); }
	void ServerMoveDualWithRotation_Implementation(float TimeStamp0, FVector_NetQuantize100 InAccel0, char PendingFlags, unsigned int View0, float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char NewFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBone, char ClientMovementMode, FRotator InRotation0, FRotator InRotation) { NativeCall<void, float, FVector_NetQuantize100, char, unsigned int, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char, FRotator, FRotator>(this, "UCharacterMovementComponent.ServerMoveDualWithRotation_Implementation", TimeStamp0, InAccel0, PendingFlags, View0, TimeStamp, InAccel, ClientLoc, NewFlags, ClientRoll, View, ClientMovementBase, ClientBaseBone, ClientMovementMode, InRotation0, InRotation); }
	void ServerMoveHandleClientErrorForDinos(float TimeStamp, float DeltaTime, FVector * Accel, FVector * RelativeClientLoc, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode, FRotator * InClientRot) { NativeCall<void, float, float, FVector *, FVector *, UPrimitiveComponent *, FName, char, FRotator *>(this, "UCharacterMovementComponent.ServerMoveHandleClientErrorForDinos", TimeStamp, DeltaTime, Accel, RelativeClientLoc, ClientMovementBase, ClientBaseBoneName, ClientMovementMode, InClientRot); }
	void ServerMoveDual_Implementation(float TimeStamp0, FVector_NetQuantize100 InAccel0, char PendingFlags, unsigned int View0, float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char NewFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBone, char ClientMovementMode) { NativeCall<void, float, FVector_NetQuantize100, char, unsigned int, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char>(this, "UCharacterMovementComponent.ServerMoveDual_Implementation", TimeStamp0, InAccel0, PendingFlags, View0, TimeStamp, InAccel, ClientLoc, NewFlags, ClientRoll, View, ClientMovementBase, ClientBaseBone, ClientMovementMode); }
	void ServerMove_Implementation(float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char MoveFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode) { NativeCall<void, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char>(this, "UCharacterMovementComponent.ServerMove_Implementation", TimeStamp, InAccel, ClientLoc, MoveFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode); }
	void ServerMoveHandleClientError(float TimeStamp, float DeltaTime, FVector * Accel, FVector * RelativeClientLoc, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode) { NativeCall<void, float, float, FVector *, FVector *, UPrimitiveComponent *, FName, char>(this, "UCharacterMovementComponent.ServerMoveHandleClientError", TimeStamp, DeltaTime, Accel, RelativeClientLoc, ClientMovementBase, ClientBaseBoneName, ClientMovementMode); }
	void ServerMoveOnlyRotation_Implementation(float TimeStamp, char ClientRoll, unsigned int View) { NativeCall<void, float, char, unsigned int>(this, "UCharacterMovementComponent.ServerMoveOnlyRotation_Implementation", TimeStamp, ClientRoll, View); }
	void ServerMoveDualOnlyRotation_Implementation(float TimeStamp0, unsigned int View0, float TimeStamp, char ClientRoll, unsigned int View) { NativeCall<void, float, unsigned int, float, char, unsigned int>(this, "UCharacterMovementComponent.ServerMoveDualOnlyRotation_Implementation", TimeStamp0, View0, TimeStamp, ClientRoll, View); }
	void MoveAutonomous(float ClientTimeStamp, float DeltaTime, char CompressedFlags, FVector * NewAccel) { NativeCall<void, float, float, char, FVector *>(this, "UCharacterMovementComponent.MoveAutonomous", ClientTimeStamp, DeltaTime, CompressedFlags, NewAccel); }
	void UpdateFloorFromAdjustment() { NativeCall<void>(this, "UCharacterMovementComponent.UpdateFloorFromAdjustment"); }
	void SendClientAdjustment() { NativeCall<void>(this, "UCharacterMovementComponent.SendClientAdjustment"); }
	void ClientVeryShortAdjustPosition_Implementation(float TimeStamp, FVector NewLoc, UPrimitiveComponent * NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, char ServerMovementMode) { NativeCall<void, float, FVector, UPrimitiveComponent *, FName, bool, bool, char>(this, "UCharacterMovementComponent.ClientVeryShortAdjustPosition_Implementation", TimeStamp, NewLoc, NewBase, NewBaseBoneName, bHasBase, bBaseRelativePosition, ServerMovementMode); }
	void ClientAdjustPosition_Implementation(float TimeStamp, FVector NewLocation, FVector NewVelocity, UPrimitiveComponent * NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, char ServerMovementMode) { NativeCall<void, float, FVector, FVector, UPrimitiveComponent *, FName, bool, bool, char>(this, "UCharacterMovementComponent.ClientAdjustPosition_Implementation", TimeStamp, NewLocation, NewVelocity, NewBase, NewBaseBoneName, bHasBase, bBaseRelativePosition, ServerMovementMode); }
	void ClientAdjustRootMotionPosition_Implementation(float TimeStamp, float ServerMontageTrackPosition, FVector ServerLoc, FVector_NetQuantizeNormal ServerRotation, float ServerVelZ, UPrimitiveComponent * ServerBase, FName ServerBaseBoneName, bool bHasBase, bool bBaseRelativePosition, char ServerMovementMode) { NativeCall<void, float, float, FVector, FVector_NetQuantizeNormal, float, UPrimitiveComponent *, FName, bool, bool, char>(this, "UCharacterMovementComponent.ClientAdjustRootMotionPosition_Implementation", TimeStamp, ServerMontageTrackPosition, ServerLoc, ServerRotation, ServerVelZ, ServerBase, ServerBaseBoneName, bHasBase, bBaseRelativePosition, ServerMovementMode); }
	void ClientAckGoodMove_Implementation(float TimeStamp) { NativeCall<void, float>(this, "UCharacterMovementComponent.ClientAckGoodMove_Implementation", TimeStamp); }
	void CapsuleTouched(AActor * Other, UPrimitiveComponent * OtherComp, int OtherBodyIndex, bool bFromSweep, FHitResult * SweepResult) { NativeCall<void, AActor *, UPrimitiveComponent *, int, bool, FHitResult *>(this, "UCharacterMovementComponent.CapsuleTouched", Other, OtherComp, OtherBodyIndex, bFromSweep, SweepResult); }
	void ApplyRepulsionForce(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.ApplyRepulsionForce", DeltaSeconds); }
	void ApplyAccumulatedForces(float DeltaSeconds) { NativeCall<void, float>(this, "UCharacterMovementComponent.ApplyAccumulatedForces", DeltaSeconds); }
	void AddRadialForce(FVector * Origin, float Radius, float Strength, ERadialImpulseFalloff Falloff) { NativeCall<void, FVector *, float, float, ERadialImpulseFalloff>(this, "UCharacterMovementComponent.AddRadialForce", Origin, Radius, Strength, Falloff); }
	void AddRadialImpulse(FVector * Origin, float Radius, float Strength, ERadialImpulseFalloff Falloff, bool bVelChange) { NativeCall<void, FVector *, float, float, ERadialImpulseFalloff, bool>(this, "UCharacterMovementComponent.AddRadialImpulse", Origin, Radius, Strength, Falloff, bVelChange); }
	void RegisterComponentTickFunctions(bool bRegister, bool bSaveAndRestoreComponentTickState) { NativeCall<void, bool, bool>(this, "UCharacterMovementComponent.RegisterComponentTickFunctions", bRegister, bSaveAndRestoreComponentTickState); }
	void UpdateFromCompressedFlags(char Flags) { NativeCall<void, char>(this, "UCharacterMovementComponent.UpdateFromCompressedFlags", Flags); }
	void Prone(bool bClientSimulation) { NativeCall<void, bool>(this, "UCharacterMovementComponent.Prone", bClientSimulation); }
	void UnProne(bool bClientSimulation, bool bForce) { NativeCall<void, bool, bool>(this, "UCharacterMovementComponent.UnProne", bClientSimulation, bForce); }
	void ClientAckGoodMove(float TimeStamp) { NativeCall<void, float>(this, "UCharacterMovementComponent.ClientAckGoodMove", TimeStamp); }
	void ClientAdjustPosition(float TimeStamp, FVector NewLoc, FVector NewVel, UPrimitiveComponent * NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, char ServerMovementMode) { NativeCall<void, float, FVector, FVector, UPrimitiveComponent *, FName, bool, bool, char>(this, "UCharacterMovementComponent.ClientAdjustPosition", TimeStamp, NewLoc, NewVel, NewBase, NewBaseBoneName, bHasBase, bBaseRelativePosition, ServerMovementMode); }
	void ClientVeryShortAdjustPosition(float TimeStamp, FVector NewLoc, UPrimitiveComponent * NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, char ServerMovementMode) { NativeCall<void, float, FVector, UPrimitiveComponent *, FName, bool, bool, char>(this, "UCharacterMovementComponent.ClientVeryShortAdjustPosition", TimeStamp, NewLoc, NewBase, NewBaseBoneName, bHasBase, bBaseRelativePosition, ServerMovementMode); }
	void ServerMove(float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char CompressedMoveFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode) { NativeCall<void, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char>(this, "UCharacterMovementComponent.ServerMove", TimeStamp, InAccel, ClientLoc, CompressedMoveFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode); }
	void ServerMoveDual(float TimeStamp0, FVector_NetQuantize100 InAccel0, char PendingFlags, unsigned int View0, float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char NewFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode) { NativeCall<void, float, FVector_NetQuantize100, char, unsigned int, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char>(this, "UCharacterMovementComponent.ServerMoveDual", TimeStamp0, InAccel0, PendingFlags, View0, TimeStamp, InAccel, ClientLoc, NewFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode); }
	void ServerMoveDualOnlyRotation(float TimeStamp0, unsigned int View0, float TimeStamp, char ClientRoll, unsigned int View) { NativeCall<void, float, unsigned int, float, char, unsigned int>(this, "UCharacterMovementComponent.ServerMoveDualOnlyRotation", TimeStamp0, View0, TimeStamp, ClientRoll, View); }
	void ServerMoveDualWithRotation(float TimeStamp0, FVector_NetQuantize100 InAccel0, char PendingFlags, unsigned int View0, float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char NewFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode, FRotator InRotation0, FRotator InRotation) { NativeCall<void, float, FVector_NetQuantize100, char, unsigned int, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char, FRotator, FRotator>(this, "UCharacterMovementComponent.ServerMoveDualWithRotation", TimeStamp0, InAccel0, PendingFlags, View0, TimeStamp, InAccel, ClientLoc, NewFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode, InRotation0, InRotation); }
	void ServerMoveOld(float OldTimeStamp, FVector_NetQuantize100 OldAccel, char OldMoveFlags) { NativeCall<void, float, FVector_NetQuantize100, char>(this, "UCharacterMovementComponent.ServerMoveOld", OldTimeStamp, OldAccel, OldMoveFlags); }
	void ServerMoveOldWithRotation(float OldTimeStamp, FVector_NetQuantize100 OldAccel, char OldMoveFlags, FRotator OldRotation) { NativeCall<void, float, FVector_NetQuantize100, char, FRotator>(this, "UCharacterMovementComponent.ServerMoveOldWithRotation", OldTimeStamp, OldAccel, OldMoveFlags, OldRotation); }
	void ServerMoveOnlyRotation(float TimeStamp, char ClientRoll, unsigned int View) { NativeCall<void, float, char, unsigned int>(this, "UCharacterMovementComponent.ServerMoveOnlyRotation", TimeStamp, ClientRoll, View); }
	void ServerMoveWithRotation(float TimeStamp, FVector_NetQuantize100 InAccel, FVector_NetQuantize100 ClientLoc, char CompressedMoveFlags, char ClientRoll, unsigned int View, UPrimitiveComponent * ClientMovementBase, FName ClientBaseBoneName, char ClientMovementMode, FRotator ClientRotation) { NativeCall<void, float, FVector_NetQuantize100, FVector_NetQuantize100, char, char, unsigned int, UPrimitiveComponent *, FName, char, FRotator>(this, "UCharacterMovementComponent.ServerMoveWithRotation", TimeStamp, InAccel, ClientLoc, CompressedMoveFlags, ClientRoll, View, ClientMovementBase, ClientBaseBoneName, ClientMovementMode, ClientRotation); }
};

struct ABrush : AActor
{

};

struct AVolume : ABrush
{

};

struct ANPCZoneVolume : AVolume
{
	// Fields
	/*unsigned __int32 bOnlyCountWaterDinos : 1;
	unsigned __int32 bOnlyCountLandDinos : 1;
	unsigned __int32 bCountTamedDinos : 1;
	TArray<TSubclassOf<APrimalDinoCharacter>, FDefaultAllocator> OnlyCountDinoClasses;
	TArray<TSubclassOf<APrimalDinoCharacter>, FDefaultAllocator> IgnoreDinoClasses;
	TArray<FHibernationCountInfo, FDefaultAllocator> HibernatedEntities;
	float HibernatedCountWeights;
	TArray<APrimalDinoCharacter *, FDefaultAllocator> OverlappedDinos;
	float CountWeights;*/
};

struct ANPCZoneSpawnVolume : AVolume
{
};

struct FLinkedZoneSpawnVolumeEntry
{
	ANPCZoneSpawnVolume * GetLinkedLinkedZoneSpawnVolumeField() const { return GetNativeField<ANPCZoneSpawnVolume *>(this, "FLinkedZoneSpawnVolumeEntry.LinkedZoneSpawnVolume"); }
	// Fields
	/*ANPCZoneSpawnVolume *LinkedZoneSpawnVolume;
	TArray<AActor *, FDefaultAllocator> ZoneSpawnVolumeFloors;
	TArray<FName, FDefaultAllocator> ZoneSpawnVolumeFloorTags;
	float EntryWeight;*/
};

struct AInfo : AActor
{

};

struct AWorldSettings : AInfo
{
};

struct APrimalWorldSettings : AWorldSettings
{
	TArray<FClassRemappingWeight> GetNPCRandomSpawnClassWeightsField() const { return GetNativeField<TArray<FClassRemappingWeight>>(this, "APrimalWorldSettings.NPCRandomSpawnClassWeights"); }
};

struct ANPCZoneManager : AInfo
{
	FieldValue<TArray<FLinkedZoneSpawnVolumeEntry>> LinkedZoneSpawnVolumeEntriesField() { return { this, "ANPCZoneManager.LinkedZoneSpawnVolumeEntries" }; }
	FieldValue<TArray<AActor *>> DefaultZoneSpawnVolumeFloorsField() { return { this, "ANPCZoneManager.DefaultZoneSpawnVolumeFloors" }; }
	FieldValue<TArray<FName>> DefaultZoneSpawnVolumeFloorTagsField() { return { this, "ANPCZoneManager.DefaultZoneSpawnVolumeFloorTags" }; }
	FieldValue<TSubclassOf<UNPCSpawnEntriesContainer>> NPCSpawnEntriesContainerObjectField() { return { this, "ANPCZoneManager.NPCSpawnEntriesContainerObject" }; }
	FieldValue<bool> bEnabledField() { return { this, "ANPCZoneManager.bEnabled" }; }
	FieldValue<bool> bForceInEditorField() { return { this, "ANPCZoneManager.bForceInEditor" }; }
	FieldValue<bool> bNeverSpawnInWaterField() { return { this, "ANPCZoneManager.bNeverSpawnInWater" }; }
	FieldValue<bool> bOnlySpawnInWaterField() { return { this, "ANPCZoneManager.bOnlySpawnInWater" }; }
	FieldValue<bool> bAllowExtentTestField() { return { this, "ANPCZoneManager.bAllowExtentTest" }; }
	FieldValue<bool> bOnlyCheckMySublevelWaterField() { return { this, "ANPCZoneManager.bOnlyCheckMySublevelWater" }; }
	FieldValue<int> MinDesiredNumberOfNPCField() { return { this, "ANPCZoneManager.MinDesiredNumberOfNPC" }; }
	FieldValue<int> SP_MinDesiredNumberOfNPCField() { return { this, "ANPCZoneManager.SP_MinDesiredNumberOfNPC" }; }
	FieldValue<int> MaxNumberOfNPCField() { return { this, "ANPCZoneManager.MaxNumberOfNPC" }; }
	FieldValue<float> DesiredNumberOfNPCMultiplierField() { return { this, "ANPCZoneManager.DesiredNumberOfNPCMultiplier" }; }
	FieldValue<float> TheSpawnPointMinimumFloorNormalField() { return { this, "ANPCZoneManager.TheSpawnPointMinimumFloorNormal" }; }
	FieldValue<float> TheNewNewEditorNumberOfNPCMultiplierField() { return { this, "ANPCZoneManager.TheNewNewEditorNumberOfNPCMultiplier" }; }
	FieldValue<float> KillOffOverweightNPCStasisTimeField() { return { this, "ANPCZoneManager.KillOffOverweightNPCStasisTime" }; }
	FieldValue<float> TheMaximumWorldTimeForFullIncreaseField() { return { this, "ANPCZoneManager.TheMaximumWorldTimeForFullIncrease" }; }
	FieldValue<float> TheMinimumPlayerDistanceFromSpawnPointField() { return { this, "ANPCZoneManager.TheMinimumPlayerDistanceFromSpawnPoint" }; }
	FieldValue<float> TheIncreaseNPCIntervalField() { return { this, "ANPCZoneManager.TheIncreaseNPCInterval" }; }
	FieldValue<float> SP_TheIncreaseNPCIntervalField() { return { this, "ANPCZoneManager.SP_TheIncreaseNPCInterval" }; }
	FieldValue<float> TheIncreaseNPCIntervalMaxField() { return { this, "ANPCZoneManager.TheIncreaseNPCIntervalMax" }; }
	FieldValue<float> TheDecreaseNPCIntervalField() { return { this, "ANPCZoneManager.TheDecreaseNPCInterval" }; }
	FieldValue<float> NPCAIRangeMultiplierField() { return { this, "ANPCZoneManager.NPCAIRangeMultiplier" }; }
	FieldValue<bool> bNPCDontWanderField() { return { this, "ANPCZoneManager.bNPCDontWander" }; }
	FieldValue<bool> bNPCWildIgnoreWildField() { return { this, "ANPCZoneManager.bNPCWildIgnoreWild" }; }
	FieldValue<bool> bNPCNoKillXPField() { return { this, "ANPCZoneManager.bNPCNoKillXP" }; }
	FieldValue<bool> bNPCPreventSavingField() { return { this, "ANPCZoneManager.bNPCPreventSaving" }; }
	FieldValue<bool> bForceUntameableField() { return { this, "ANPCZoneManager.bForceUntameable" }; }
	FieldValue<bool> bUsesManualSpawningField() { return { this, "ANPCZoneManager.bUsesManualSpawning" }; }
	FieldValue<bool> bIgnoreVolumeEcompassingCheckField() { return { this, "ANPCZoneManager.bIgnoreVolumeEcompassingCheck" }; }
	FieldValue<bool> bSpawnAllNPCEntriesField() { return { this, "ANPCZoneManager.bSpawnAllNPCEntries" }; }
	FieldValue<bool> bOnlyUseInSingleplayerField() { return { this, "ANPCZoneManager.bOnlyUseInSingleplayer" }; }
	FieldValue<bool> bOnlyUseInDedicatedServerField() { return { this, "ANPCZoneManager.bOnlyUseInDedicatedServer" }; }
	FieldValue<float> NPCWanderRadiusMultiplierField() { return { this, "ANPCZoneManager.NPCWanderRadiusMultiplier" }; }
	FieldValue<int> MaxNumberSpawnZoneRandomPointChecksField() { return { this, "ANPCZoneManager.MaxNumberSpawnZoneRandomPointChecks" }; }
	FieldValue<int> TheNPCFullIncreaseMaximumIterationsField() { return { this, "ANPCZoneManager.TheNPCFullIncreaseMaximumIterations" }; }
	FieldValue<float> TheMinimumTamedDinoDistanceFromSpawnPointField() { return { this, "ANPCZoneManager.TheMinimumTamedDinoDistanceFromSpawnPoint" }; }
	FieldValue<float> TheMinimumStructureDistanceFromSpawnPointField() { return { this, "ANPCZoneManager.TheMinimumStructureDistanceFromSpawnPoint" }; }
	FieldValue<float> NPCLerpToMaxRandomBaseLevelField() { return { this, "ANPCZoneManager.NPCLerpToMaxRandomBaseLevel" }; }
	FieldValue<float> ManualSpawningNPCLerpToMaxRandomBaseLevelField() { return { this, "ANPCZoneManager.ManualSpawningNPCLerpToMaxRandomBaseLevel" }; }
	FieldValue<int> MaximumNumberNearbyCoreStructuresField() { return { this, "ANPCZoneManager.MaximumNumberNearbyCoreStructures" }; }
	FieldValue<int> AbsoluteMaximumNumberNearbyCoreStructuresField() { return { this, "ANPCZoneManager.AbsoluteMaximumNumberNearbyCoreStructures" }; }
	FieldValue<bool> bAutoKillUseGlobalStasisArrayField() { return { this, "ANPCZoneManager.bAutoKillUseGlobalStasisArray" }; }
	FieldValue<bool> bTraceForSpawnAgainstWaterField() { return { this, "ANPCZoneManager.bTraceForSpawnAgainstWater" }; }
	FieldValue<bool> bNPCForcePreventExitingWaterField() { return { this, "ANPCZoneManager.bNPCForcePreventExitingWater" }; }
	FieldValue<bool> bUseSpawnPointOverrideRotationField() { return { this, "ANPCZoneManager.bUseSpawnPointOverrideRotation" }; }
	FieldValue<float> NPCLevelMultiplierField() { return { this, "ANPCZoneManager.NPCLevelMultiplier" }; }
	FieldValue<int> ForceOverrideNPCBaseLevelField() { return { this, "ANPCZoneManager.ForceOverrideNPCBaseLevel" }; }
	FieldValue<TArray<FNPCSpawnEntry>> NPCSpawnEntriesField() { return { this, "ANPCZoneManager.NPCSpawnEntries" }; }
	FieldValue<TArray<FNPCSpawnLimit>> NPCSpawnLimitsField() { return { this, "ANPCZoneManager.NPCSpawnLimits" }; }
	FieldValue<int> UseDesiredNumberOfNPCField() { return { this, "ANPCZoneManager.UseDesiredNumberOfNPC" }; }
	FieldValue<int> NumNPCSpawnedField() { return { this, "ANPCZoneManager.NumNPCSpawned" }; }
	FieldValue<int> NumSpawnFailuresField() { return { this, "ANPCZoneManager.NumSpawnFailures" }; }
	FieldValue<long double> LastIncreaseNPCTimeField() { return { this, "ANPCZoneManager.LastIncreaseNPCTime" }; }
	FieldValue<long double> LastDecreaseNPCTimeField() { return { this, "ANPCZoneManager.LastDecreaseNPCTime" }; }
	FieldValue<bool> bForceRespawnDinosField() { return { this, "ANPCZoneManager.bForceRespawnDinos" }; }
	FieldValue<bool> bTriedFullIncreaseField() { return { this, "ANPCZoneManager.bTriedFullIncrease" }; }
	FieldValue<bool> bSpawnsWaterDinosField() { return { this, "ANPCZoneManager.bSpawnsWaterDinos" }; }
	FieldValue<bool> bSpawnsAmphibiousDinosField() { return { this, "ANPCZoneManager.bSpawnsAmphibiousDinos" }; }
	FieldValue<float> TheNextIncreaseNPCIntervalField() { return { this, "ANPCZoneManager.TheNextIncreaseNPCInterval" }; }
	FieldValue<float> CloseStructureDistanceFromSpawnPointField() { return { this, "ANPCZoneManager.CloseStructureDistanceFromSpawnPoint" }; }
	FieldValue<TArray<AActor *>> SpawnPointOverridesField() { return { this, "ANPCZoneManager.SpawnPointOverrides" }; }
	FieldValue<FName> NonDedicatedFreezeWildDinoPhysicsIfLevelUnloadedField() { return { this, "ANPCZoneManager.NonDedicatedFreezeWildDinoPhysicsIfLevelUnloaded" }; }
	FieldValue<TArray<FName>> NonDedicatedFreezeWildDinoPhysicsIfLevelsUnloadedField() { return { this, "ANPCZoneManager.NonDedicatedFreezeWildDinoPhysicsIfLevelsUnloaded" }; }
	FieldValue<float> MinimumManualSpawnIntervalField() { return { this, "ANPCZoneManager.MinimumManualSpawnInterval" }; }
	FieldValue<long double> LastManuallySpawnedTimeField() { return { this, "ANPCZoneManager.LastManuallySpawnedTime" }; }
	FieldValue<bool> bIgnoreNPCRandomClassReplacementsField() { return { this, "ANPCZoneManager.bIgnoreNPCRandomClassReplacements" }; }
	FieldValue<int> TheNPCDynamicIncreaseMaximumIterationsField() { return { this, "ANPCZoneManager.TheNPCDynamicIncreaseMaximumIterations" }; }

	// Functions

	static UClass* GetPrivateStaticClass() { return NativeCall<UClass *, __int64, UClass **, void(__cdecl *)()>(nullptr, "ANPCZoneManager.GetPrivateStaticClass", 0, nullptr, nullptr); }
	void BeginPlay() { NativeCall<void>(this, "ANPCZoneManager.BeginPlay"); }
	int GetNumberOfNPCTouching() { return NativeCall<int>(this, "ANPCZoneManager.GetNumberOfNPCTouching"); }
	int GetNumberOfClassNPCTouching(TSubclassOf<APrimalDinoCharacter> ADinoClass) { return NativeCall<int, TSubclassOf<APrimalDinoCharacter>>(this, "ANPCZoneManager.GetNumberOfClassNPCTouching", ADinoClass); }
	void CheckDecreaseNPC() { NativeCall<void>(this, "ANPCZoneManager.CheckDecreaseNPC"); }
	void CheckIncreaseNPC() { NativeCall<void>(this, "ANPCZoneManager.CheckIncreaseNPC"); }
	bool SpawnNPCs() { return NativeCall<bool>(this, "ANPCZoneManager.SpawnNPCs"); }
	bool IsValidNPCEntry(FNPCSpawnEntry * NPCEntry) { return NativeCall<bool, FNPCSpawnEntry *>(this, "ANPCZoneManager.IsValidNPCEntry", NPCEntry); }
	APrimalDinoCharacter * SpawnFromEntries(int SpawnVolumeEntry, TArray<FNPCSpawnEntry> * spawnEntries, FVector * AtSpawnPoint, TArray<APrimalDinoCharacter *> * AllSpawnedNPCs, float OverrideYaw) { return NativeCall<APrimalDinoCharacter *, int, TArray<FNPCSpawnEntry> *, FVector *, TArray<APrimalDinoCharacter *> *, float>(this, "ANPCZoneManager.SpawnFromEntries", SpawnVolumeEntry, spawnEntries, AtSpawnPoint, AllSpawnedNPCs, OverrideYaw); }
	int FindLinkedSpawnVolumeEntryContainingPoint(FVector AtPoint) { return NativeCall<int, FVector>(this, "ANPCZoneManager.FindLinkedSpawnVolumeEntryContainingPoint", AtPoint); }
	bool GetValidSpawnPoint(int volumeEntryIndex, FVector extentCheck, FVector * ValidSpawnPoint, FVector * OverrideStartPoint, float OverrideStartPointExpansionRadius, float WaterOnlySpawnMinimumWaterHeight, float MaximumWaterHeight, float SpawnMinDistanceFromStructuresMultiplier, float SpawnMinDistanceFromPlayersMultiplier, float SpawnMinDistanceFromTamedDinosMultiplier, float * OverrideYawOut) { return NativeCall<bool, int, FVector, FVector *, FVector *, float, float, float, float, float, float, float *>(this, "ANPCZoneManager.GetValidSpawnPoint", volumeEntryIndex, extentCheck, ValidSpawnPoint, OverrideStartPoint, OverrideStartPointExpansionRadius, WaterOnlySpawnMinimumWaterHeight, MaximumWaterHeight, SpawnMinDistanceFromStructuresMultiplier, SpawnMinDistanceFromPlayersMultiplier, SpawnMinDistanceFromTamedDinosMultiplier, OverrideYawOut); }
	APrimalDinoCharacter * SpawnNPC(TSubclassOf<APrimalDinoCharacter> PawnTemplate, FVector SpawnLoc, bool bOverrideNPCLevel, int NPCLevelOffset, float NPCLevelMultiplier, bool bAddLevelOffsetBeforeMultiplier, float WaterOnlySpawnMinimumWaterHeight, float SpawnVolumeStartExtentZ, float OverrideYaw, float MaximumWaterHeight) { return NativeCall<APrimalDinoCharacter *, TSubclassOf<APrimalDinoCharacter>, FVector, bool, int, float, bool, float, float, float, float>(this, "ANPCZoneManager.SpawnNPC", PawnTemplate, SpawnLoc, bOverrideNPCLevel, NPCLevelOffset, NPCLevelMultiplier, bAddLevelOffsetBeforeMultiplier, WaterOnlySpawnMinimumWaterHeight, SpawnVolumeStartExtentZ, OverrideYaw, MaximumWaterHeight); }
	APrimalDinoCharacter * GetBestNPCToAutoKill() { return NativeCall<APrimalDinoCharacter *>(this, "ANPCZoneManager.GetBestNPCToAutoKill"); }
	void EndPlay(EEndPlayReason::Type EndPlayReason) { NativeCall<void, EEndPlayReason::Type>(this, "ANPCZoneManager.EndPlay", EndPlayReason); }
	static TArray<APrimalDinoCharacter *> * StaticSpawnNPCs(TArray<APrimalDinoCharacter *> * result, UObject * WorldContext, ANPCZoneManager * AtZoneManager, TSubclassOf<UNPCSpawnEntriesContainer> TheNPCSpawnEntries, FVector AtSpawnPoint, FRotator AtRotation, int UseSpawnVolumeIndex) { return NativeCall<TArray<APrimalDinoCharacter *> *, TArray<APrimalDinoCharacter *> *, UObject *, ANPCZoneManager *, TSubclassOf<UNPCSpawnEntriesContainer>, FVector, FRotator, int>(nullptr, "ANPCZoneManager.StaticSpawnNPCs", result, WorldContext, AtZoneManager, TheNPCSpawnEntries, AtSpawnPoint, AtRotation, UseSpawnVolumeIndex); }
	static void StaticRegisterNativesANPCZoneManager() { NativeCall<void>(nullptr, "ANPCZoneManager.StaticRegisterNativesANPCZoneManager"); }
};

