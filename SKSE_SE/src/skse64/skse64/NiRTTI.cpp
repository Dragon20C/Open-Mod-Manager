#include "skse64/NiRTTI.h"
#include "skse64/NiObjects.h"

NiObject * DoNiRTTICast(NiObject * src, const NiRTTI * typeInfo)
{
	uintptr_t typeAddr = uintptr_t(typeInfo) + RelocationManager::s_baseAddr;
	if (src)
		for (NiRTTI * iter = src->GetRTTI(); iter; iter = iter->parent)
			if (iter == (NiRTTI *)typeAddr)
				return src;

	return nullptr;
}

bool IsType(NiRTTI * rtti, const NiRTTI * typeInfo)
{
	uintptr_t typeAddr = uintptr_t(typeInfo) + RelocationManager::s_baseAddr;
	if (rtti)
		return uintptr_t(rtti) == typeAddr;

	return false;
}

const NiRTTI *	NiRTTI_BGSDecalNode = (NiRTTI *)0x01EC4338;
const NiRTTI *	NiRTTI_BSAnimGroupSequence = (NiRTTI *)0x01EC44B0;
const NiRTTI *	NiRTTI_BSSplatterExtraData = (NiRTTI *)0x02EC5500;
const NiRTTI *	NiRTTI_BGSAddonNodeSoundHandleExtra = (NiRTTI *)0x02EC5968;
const NiRTTI *	NiRTTI_REFRSyncController = (NiRTTI *)0x02EFF9C0;
const NiRTTI *	NiRTTI_bhkCartTether = (NiRTTI *)0x02F01118;
const NiRTTI *	NiRTTI_bhkTiltPreventAction = (NiRTTI *)0x02F01128;
const NiRTTI *	NiRTTI_bhkWheelAction = (NiRTTI *)0x02F01138;
const NiRTTI *	NiRTTI_BSFaceGenAnimationData = (NiRTTI *)0x02F01780;
const NiRTTI *	NiRTTI_BSFaceGenModelExtraData = (NiRTTI *)0x02F07CA0;
const NiRTTI *	NiRTTI_BSFaceGenBaseMorphExtraData = (NiRTTI *)0x02F07CC8;
const NiRTTI *	NiRTTI_BSFaceGenMorphData = (NiRTTI *)0x02F07CD8;
const NiRTTI *	NiRTTI_BSFaceGenMorphDataHead = (NiRTTI *)0x02F07CE8;
const NiRTTI *	NiRTTI_BSFaceGenMorphDataHair = (NiRTTI *)0x02F07CF8;
const NiRTTI *	NiRTTI_BSFaceGenNiNode = (NiRTTI *)0x02F07D38;
const NiRTTI *	NiRTTI_BSTempEffect = (NiRTTI *)0x02F0D428;
const NiRTTI *	NiRTTI_BSTempEffectDebris = (NiRTTI *)0x02F0D4A8;
const NiRTTI *	NiRTTI_BSTempEffectGeometryDecal = (NiRTTI *)0x02F0D4C8;
const NiRTTI *	NiRTTI_BSTempEffectParticle = (NiRTTI *)0x02F0D578;
const NiRTTI *	NiRTTI_BSTempEffectSimpleDecal = (NiRTTI *)0x02F0D5A0;
const NiRTTI *	NiRTTI_BSTempEffectSPG = (NiRTTI *)0x02F0D5B8;
const NiRTTI *	NiRTTI_bhkAutoWater = (NiRTTI *)0x02F249A0;
const NiRTTI *	NiRTTI_ModelReferenceEffect = (NiRTTI *)0x02F261D8;
const NiRTTI *	NiRTTI_ReferenceEffect = (NiRTTI *)0x02F26210;
const NiRTTI *	NiRTTI_ShaderReferenceEffect = (NiRTTI *)0x02F26240;
const NiRTTI *	NiRTTI_SummonPlacementEffect = (NiRTTI *)0x02F26270;
const NiRTTI *	NiRTTI_SceneGraph = (NiRTTI *)0x02F38950;
const NiRTTI *	NiRTTI_BSDoorHavokController = (NiRTTI *)0x02F3A680;
const NiRTTI *	NiRTTI_BSPlayerDistanceCheckController = (NiRTTI *)0x02F3A690;
const NiRTTI *	NiRTTI_BSSimpleScaleController = (NiRTTI *)0x02F3A6A0;
const NiRTTI *	NiRTTI_NiObject = (NiRTTI *)0x03012388;
const NiRTTI *	NiRTTI_NiAVObject = (NiRTTI *)0x030123C0;
const NiRTTI *	NiRTTI_NiNode = (NiRTTI *)0x030123E0;
const NiRTTI *	NiRTTI_NiObjectNET = (NiRTTI *)0x03012508;
const NiRTTI *	NiRTTI_NiLight = (NiRTTI *)0x03012568;
const NiRTTI *	NiRTTI_NiSwitchNode = (NiRTTI *)0x03012578;
const NiRTTI *	NiRTTI_NiStringsExtraData = (NiRTTI *)0x03012588;
const NiRTTI *	NiRTTI_NiCamera = (NiRTTI *)0x03012598;
const NiRTTI *	NiRTTI_BSTriShape = (NiRTTI *)0x030125B0;
const NiRTTI *	NiRTTI_NiProperty = (NiRTTI *)0x030125C0;
const NiRTTI *	NiRTTI_NiAlphaProperty = (NiRTTI *)0x030125D8;
const NiRTTI *	NiRTTI_NiSourceTexture = (NiRTTI *)0x03013608;
const NiRTTI *	NiRTTI_BSFlattenedBoneTree = (NiRTTI *)0x03013618;
const NiRTTI *	NiRTTI_BSDismemberSkinInstance = (NiRTTI *)0x03013660;
const NiRTTI *	NiRTTI_NiStringExtraData = (NiRTTI *)0x03013670;
const NiRTTI *	NiRTTI_NiTimeController = (NiRTTI *)0x03013680;
const NiRTTI *	NiRTTI_NiExtraData = (NiRTTI *)0x030136A0;
const NiRTTI *	NiRTTI_NiGeometryData = (NiRTTI *)0x030136B0;
const NiRTTI *	NiRTTI_BSGeometry = (NiRTTI *)0x030136C8;
const NiRTTI *	NiRTTI_BSDynamicTriShape = (NiRTTI *)0x030136E0;
const NiRTTI *	NiRTTI_NiPointLight = (NiRTTI *)0x030136F0;
const NiRTTI *	NiRTTI_NiDefaultAVObjectPalette = (NiRTTI *)0x03013700;
const NiRTTI *	NiRTTI_NiBillboardNode = (NiRTTI *)0x03013728;
const NiRTTI *	NiRTTI_NiDirectionalLight = (NiRTTI *)0x03013738;
const NiRTTI *	NiRTTI_NiCullingProcess = (NiRTTI *)0x03013748;
const NiRTTI *	NiRTTI_NiParticles = (NiRTTI *)0x03013760;
const NiRTTI *	NiRTTI_NiTexture = (NiRTTI *)0x030137A0;
const NiRTTI *	NiRTTI_NiSkinPartition = (NiRTTI *)0x030138B0;
const NiRTTI *	NiRTTI_NiVertWeightsExtraData = (NiRTTI *)0x030138C0;
const NiRTTI *	NiRTTI_NiSkinInstance = (NiRTTI *)0x030138D0;
const NiRTTI *	NiRTTI_NiAVObjectPalette = (NiRTTI *)0x030138E0;
const NiRTTI *	NiRTTI_NiGeometry = (NiRTTI *)0x030138F0;
const NiRTTI *	NiRTTI_NiSkinData = (NiRTTI *)0x03013920;
const NiRTTI *	NiRTTI_NiShadeProperty = (NiRTTI *)0x03013930;
const NiRTTI *	NiRTTI_NiAlphaAccumulator = (NiRTTI *)0x03013948;
const NiRTTI *	NiRTTI_NiAmbientLight = (NiRTTI *)0x03013958;
const NiRTTI *	NiRTTI_NiBinaryExtraData = (NiRTTI *)0x03013968;
const NiRTTI *	NiRTTI_NiBooleanExtraData = (NiRTTI *)0x03013978;
const NiRTTI *	NiRTTI_NiBSPNode = (NiRTTI *)0x03013988;
const NiRTTI *	NiRTTI_NiColorExtraData = (NiRTTI *)0x03013998;
const NiRTTI *	NiRTTI_NiFloatExtraData = (NiRTTI *)0x030139A8;
const NiRTTI *	NiRTTI_NiFloatsExtraData = (NiRTTI *)0x030139B8;
const NiRTTI *	NiRTTI_NiFogProperty = (NiRTTI *)0x030139C8;
const NiRTTI *	NiRTTI_NiIntegerExtraData = (NiRTTI *)0x030139E0;
const NiRTTI *	NiRTTI_NiIntegersExtraData = (NiRTTI *)0x030139F0;
const NiRTTI *	NiRTTI_NiParticlesData = (NiRTTI *)0x03013A38;
const NiRTTI *	NiRTTI_NiParticleMeshesData = (NiRTTI *)0x03013A48;
const NiRTTI *	NiRTTI_NiParticleMeshes = (NiRTTI *)0x03013A58;
const NiRTTI *	NiRTTI_NiSpotLight = (NiRTTI *)0x03013A68;
const NiRTTI *	NiRTTI_NiSwitchStringExtraData = (NiRTTI *)0x03013A78;
const NiRTTI *	NiRTTI_NiTriShapeData = (NiRTTI *)0x03013A88;
const NiRTTI *	NiRTTI_NiTriShape = (NiRTTI *)0x03013A98;
const NiRTTI *	NiRTTI_NiTriStripsData = (NiRTTI *)0x03013AA8;
const NiRTTI *	NiRTTI_NiTriStrips = (NiRTTI *)0x03013AB8;
const NiRTTI *	NiRTTI_NiVectorExtraData = (NiRTTI *)0x03013AC8;
const NiRTTI *	NiRTTI_BSLODTriShape = (NiRTTI *)0x03013AF0;
const NiRTTI *	NiRTTI_NiAdditionalGeometryData = (NiRTTI *)0x03013B00;
const NiRTTI *	NiRTTI_BSSegmentedTriShape = (NiRTTI *)0x03013B18;
const NiRTTI *	NiRTTI_NiAccumulator = (NiRTTI *)0x03013B50;
const NiRTTI *	NiRTTI_NiBackToFrontAccumulator = (NiRTTI *)0x03013B60;
const NiRTTI *	NiRTTI_NiTriBasedGeomData = (NiRTTI *)0x03013B70;
const NiRTTI *	NiRTTI_NiTriBasedGeom = (NiRTTI *)0x03013B80;
const NiRTTI *	NiRTTI_NiCollisionData = (NiRTTI *)0x03013BC8;
const NiRTTI *	NiRTTI_NiControllerManager = (NiRTTI *)0x03013C58;
const NiRTTI *	NiRTTI_NiControllerSequence = (NiRTTI *)0x03013C78;
const NiRTTI *	NiRTTI_NiBlendInterpolator = (NiRTTI *)0x03013CA8;
const NiRTTI *	NiRTTI_NiMultiTargetTransformController = (NiRTTI *)0x03013CB8;
const NiRTTI *	NiRTTI_BSMultiTargetTreadTransfController = (NiRTTI *)0x03013CC8;
const NiRTTI *	NiRTTI_NiInterpController = (NiRTTI *)0x03013CD8;
const NiRTTI *	NiRTTI_NiFloatData = (NiRTTI *)0x03014AA8;
const NiRTTI *	NiRTTI_NiFloatInterpolator = (NiRTTI *)0x03014AB8;
const NiRTTI *	NiRTTI_NiColorData = (NiRTTI *)0x03014AC8;
const NiRTTI *	NiRTTI_NiColorInterpolator = (NiRTTI *)0x03014AD8;
const NiRTTI *	NiRTTI_NiSingleInterpController = (NiRTTI *)0x03014AE8;
const NiRTTI *	NiRTTI_NiTransformInterpolator = (NiRTTI *)0x03014AF8;
const NiRTTI *	NiRTTI_NiPathInterpolator = (NiRTTI *)0x03014B08;
const NiRTTI *	NiRTTI_NiBlendTransformInterpolator = (NiRTTI *)0x03014B28;
const NiRTTI *	NiRTTI_NiBlendFloatInterpolator = (NiRTTI *)0x03014B38;
const NiRTTI *	NiRTTI_NiFloatExtraDataController = (NiRTTI *)0x03014B48;
const NiRTTI *	NiRTTI_NiTransformController = (NiRTTI *)0x03014B58;
const NiRTTI *	NiRTTI_NiBlendAccumTransformInterpolator = (NiRTTI *)0x03014B70;
const NiRTTI *	NiRTTI_NiInterpolator = (NiRTTI *)0x03014B80;
const NiRTTI *	NiRTTI_BSBlendTreadTransfInterpolator = (NiRTTI *)0x03014BA0;
const NiRTTI *	NiRTTI_NiKeyBasedInterpolator = (NiRTTI *)0x03014BB8;
const NiRTTI *	NiRTTI_NiTransformData = (NiRTTI *)0x03014C38;
const NiRTTI *	NiRTTI_NiPosData = (NiRTTI *)0x03014C48;
const NiRTTI *	NiRTTI_NiBlendBoolInterpolator = (NiRTTI *)0x03014C58;
const NiRTTI *	NiRTTI_NiBlendColorInterpolator = (NiRTTI *)0x03014C68;
const NiRTTI *	NiRTTI_NiBlendPoint3Interpolator = (NiRTTI *)0x03014C78;
const NiRTTI *	NiRTTI_NiBlendQuaternionInterpolator = (NiRTTI *)0x03014C88;
const NiRTTI *	NiRTTI_NiBoolData = (NiRTTI *)0x03014C98;
const NiRTTI *	NiRTTI_NiBoolInterpolator = (NiRTTI *)0x03014CA8;
const NiRTTI *	NiRTTI_NiBoolTimelineInterpolator = (NiRTTI *)0x03014CB8;
const NiRTTI *	NiRTTI_NiBSplineBasisData = (NiRTTI *)0x03014CC8;
const NiRTTI *	NiRTTI_NiBSplineData = (NiRTTI *)0x03014CD8;
const NiRTTI *	NiRTTI_NiBSplineColorInterpolator = (NiRTTI *)0x03014CE8;
const NiRTTI *	NiRTTI_NiBSplineCompColorInterpolator = (NiRTTI *)0x03014CF8;
const NiRTTI *	NiRTTI_NiBSplineCompFloatInterpolator = (NiRTTI *)0x03014D08;
const NiRTTI *	NiRTTI_NiBSplineCompPoint3Interpolator = (NiRTTI *)0x03014D18;
const NiRTTI *	NiRTTI_NiBSplineCompTransformInterpolator = (NiRTTI *)0x03014D28;
const NiRTTI *	NiRTTI_NiBSplineFloatInterpolator = (NiRTTI *)0x03014D38;
const NiRTTI *	NiRTTI_NiBSplinePoint3Interpolator = (NiRTTI *)0x03014D48;
const NiRTTI *	NiRTTI_NiBSplineTransformInterpolator = (NiRTTI *)0x03014D58;
const NiRTTI *	NiRTTI_NiColorExtraDataController = (NiRTTI *)0x03014D68;
const NiRTTI *	NiRTTI_NiFloatsExtraDataController = (NiRTTI *)0x03014D78;
const NiRTTI *	NiRTTI_NiFloatsExtraDataPoint3Controller = (NiRTTI *)0x03014D88;
const NiRTTI *	NiRTTI_NiKeyframeManager = (NiRTTI *)0x03014DA0;
const NiRTTI *	NiRTTI_NiLightColorController = (NiRTTI *)0x03014DB0;
const NiRTTI *	NiRTTI_NiLightDimmerController = (NiRTTI *)0x03014DC0;
const NiRTTI *	NiRTTI_NiLookAtController = (NiRTTI *)0x03014DD0;
const NiRTTI *	NiRTTI_NiLookAtInterpolator = (NiRTTI *)0x03014DE0;
const NiRTTI *	NiRTTI_NiMorphData = (NiRTTI *)0x03014DF0;
const NiRTTI *	NiRTTI_NiPathController = (NiRTTI *)0x03014E00;
const NiRTTI *	NiRTTI_NiPoint3Interpolator = (NiRTTI *)0x03014E10;
const NiRTTI *	NiRTTI_NiQuaternionInterpolator = (NiRTTI *)0x03014E20;
const NiRTTI *	NiRTTI_NiRollController = (NiRTTI *)0x03014E30;
const NiRTTI *	NiRTTI_NiRotData = (NiRTTI *)0x03014E40;
const NiRTTI *	NiRTTI_NiSequence = (NiRTTI *)0x03014E50;
const NiRTTI *	NiRTTI_NiSequenceStreamHelper = (NiRTTI *)0x03014E70;
const NiRTTI *	NiRTTI_NiStringPalette = (NiRTTI *)0x03014E80;
const NiRTTI *	NiRTTI_NiTextKeyExtraData = (NiRTTI *)0x03014E90;
const NiRTTI *	NiRTTI_NiUVData = (NiRTTI *)0x03014EA0;
const NiRTTI *	NiRTTI_NiVisController = (NiRTTI *)0x03014EB0;
const NiRTTI *	NiRTTI_BSAnimNote = (NiRTTI *)0x03014EC0;
const NiRTTI *	NiRTTI_BSAnimNotes = (NiRTTI *)0x03014ED0;
const NiRTTI *	NiRTTI_BSGrabIKNote = (NiRTTI *)0x03014EE0;
const NiRTTI *	NiRTTI_BSLookIKNote = (NiRTTI *)0x03014EF0;
const NiRTTI *	NiRTTI_BSRotAccumTransfInterpolator = (NiRTTI *)0x03014F00;
const NiRTTI *	NiRTTI_BSTreadTransfInterpolator = (NiRTTI *)0x03014F10;
const NiRTTI *	NiRTTI_BSFrustumFOVController = (NiRTTI *)0x03014F20;
const NiRTTI *	NiRTTI_NiExtraDataController = (NiRTTI *)0x03014FB8;
const NiRTTI *	NiRTTI_NiBSplineInterpolator = (NiRTTI *)0x03014FC8;
const NiRTTI *	NiRTTI_NiPoint3InterpController = (NiRTTI *)0x03014FD8;
const NiRTTI *	NiRTTI_NiFloatInterpController = (NiRTTI *)0x03014FE8;
const NiRTTI *	NiRTTI_NiFloatController = (NiRTTI *)0x03014FF8;
const NiRTTI *	NiRTTI_NiBoolInterpController = (NiRTTI *)0x03015008;
const NiRTTI *	NiRTTI_NiParticleSystem = (NiRTTI *)0x03015020;
const NiRTTI *	NiRTTI_NiPSysEmitterCtlr = (NiRTTI *)0x03015030;
const NiRTTI *	NiRTTI_NiPSysGravityModifier = (NiRTTI *)0x03015040;
const NiRTTI *	NiRTTI_BSPSysHavokUpdateModifier = (NiRTTI *)0x03015050;
const NiRTTI *	NiRTTI_NiMeshParticleSystem = (NiRTTI *)0x03015068;
const NiRTTI *	NiRTTI_NiPSysCylinderEmitter = (NiRTTI *)0x03015080;
const NiRTTI *	NiRTTI_BSStripParticleSystem = (NiRTTI *)0x03015090;
const NiRTTI *	NiRTTI_NiPSysEmitter = (NiRTTI *)0x030150A0;
const NiRTTI *	NiRTTI_NiPSysModifierCtlr = (NiRTTI *)0x030150B8;
const NiRTTI *	NiRTTI_NiPSysModifier = (NiRTTI *)0x030150C8;
const NiRTTI *	NiRTTI_NiPSysMeshUpdateModifier = (NiRTTI *)0x030150D8;
const NiRTTI *	NiRTTI_NiPSysUpdateCtlr = (NiRTTI *)0x030150E8;
const NiRTTI *	NiRTTI_NiMeshPSysData = (NiRTTI *)0x030150F8;
const NiRTTI *	NiRTTI_NiPSysAirFieldAirFrictionCtlr = (NiRTTI *)0x03015108;
const NiRTTI *	NiRTTI_NiPSysAirFieldInheritVelocityCtlr = (NiRTTI *)0x03015118;
const NiRTTI *	NiRTTI_NiPSysAirFieldModifier = (NiRTTI *)0x03015128;
const NiRTTI *	NiRTTI_NiPSysAirFieldSpreadCtlr = (NiRTTI *)0x03015138;
const NiRTTI *	NiRTTI_NiPSysAgeDeathModifier = (NiRTTI *)0x03015148;
const NiRTTI *	NiRTTI_NiPSysBombModifier = (NiRTTI *)0x03015158;
const NiRTTI *	NiRTTI_NiPSysBoundUpdateModifier = (NiRTTI *)0x03015168;
const NiRTTI *	NiRTTI_NiPSysBoxEmitter = (NiRTTI *)0x03015178;
const NiRTTI *	NiRTTI_NiPSysColliderManager = (NiRTTI *)0x03015188;
const NiRTTI *	NiRTTI_NiPSysColorModifier = (NiRTTI *)0x03015198;
const NiRTTI *	NiRTTI_NiPSysData = (NiRTTI *)0x030151A8;
const NiRTTI *	NiRTTI_NiPSysDragFieldModifier = (NiRTTI *)0x030151B8;
const NiRTTI *	NiRTTI_NiPSysDragModifier = (NiRTTI *)0x030151C8;
const NiRTTI *	NiRTTI_NiPSysEmitterCtlrData = (NiRTTI *)0x030151D8;
const NiRTTI *	NiRTTI_NiPSysEmitterDeclinationCtlr = (NiRTTI *)0x030151E8;
const NiRTTI *	NiRTTI_NiPSysEmitterDeclinationVarCtlr = (NiRTTI *)0x030151F8;
const NiRTTI *	NiRTTI_NiPSysEmitterInitialRadiusCtlr = (NiRTTI *)0x03015208;
const NiRTTI *	NiRTTI_NiPSysEmitterLifeSpanCtlr = (NiRTTI *)0x03015218;
const NiRTTI *	NiRTTI_NiPSysEmitterPlanarAngleCtlr = (NiRTTI *)0x03015228;
const NiRTTI *	NiRTTI_NiPSysEmitterPlanarAngleVarCtlr = (NiRTTI *)0x03015238;
const NiRTTI *	NiRTTI_NiPSysEmitterSpeedCtlr = (NiRTTI *)0x03015248;
const NiRTTI *	NiRTTI_NiPSysFieldAttenuationCtlr = (NiRTTI *)0x03015258;
const NiRTTI *	NiRTTI_NiPSysFieldMagnitudeCtlr = (NiRTTI *)0x03015268;
const NiRTTI *	NiRTTI_NiPSysFieldMaxDistanceCtlr = (NiRTTI *)0x03015278;
const NiRTTI *	NiRTTI_NiPSysGravityFieldModifier = (NiRTTI *)0x03015288;
const NiRTTI *	NiRTTI_NiPSysGravityStrengthCtlr = (NiRTTI *)0x03015298;
const NiRTTI *	NiRTTI_NiPSysGrowFadeModifier = (NiRTTI *)0x030152A8;
const NiRTTI *	NiRTTI_NiPSysInitialRotAngleCtlr = (NiRTTI *)0x030152B8;
const NiRTTI *	NiRTTI_NiPSysInitialRotAngleVarCtlr = (NiRTTI *)0x030152C8;
const NiRTTI *	NiRTTI_NiPSysInitialRotSpeedCtlr = (NiRTTI *)0x030152D8;
const NiRTTI *	NiRTTI_NiPSysInitialRotSpeedVarCtlr = (NiRTTI *)0x030152E8;
const NiRTTI *	NiRTTI_NiPSysMeshEmitter = (NiRTTI *)0x030152F8;
const NiRTTI *	NiRTTI_NiPSysModifierActiveCtlr = (NiRTTI *)0x03015328;
const NiRTTI *	NiRTTI_NiPSysPlanarCollider = (NiRTTI *)0x03015338;
const NiRTTI *	NiRTTI_NiPSysPositionModifier = (NiRTTI *)0x03015350;
const NiRTTI *	NiRTTI_NiPSysRadialFieldModifier = (NiRTTI *)0x03015360;
const NiRTTI *	NiRTTI_NiPSysResetOnLoopCtlr = (NiRTTI *)0x03015370;
const NiRTTI *	NiRTTI_NiPSysRotationModifier = (NiRTTI *)0x03015380;
const NiRTTI *	NiRTTI_NiPSysSpawnModifier = (NiRTTI *)0x03015390;
const NiRTTI *	NiRTTI_NiPSysSphereEmitter = (NiRTTI *)0x030153A0;
const NiRTTI *	NiRTTI_NiPSysSphericalCollider = (NiRTTI *)0x030153B0;
const NiRTTI *	NiRTTI_NiPSysTurbulenceFieldModifier = (NiRTTI *)0x030153C0;
const NiRTTI *	NiRTTI_NiPSysVortexFieldModifier = (NiRTTI *)0x030153D0;
const NiRTTI *	NiRTTI_BSStripPSysData = (NiRTTI *)0x030153E0;
const NiRTTI *	NiRTTI_BSPSysRecycleBoundModifier = (NiRTTI *)0x030153F8;
const NiRTTI *	NiRTTI_BSPSysInheritVelocityModifier = (NiRTTI *)0x03015408;
const NiRTTI *	NiRTTI_NiPSysVolumeEmitter = (NiRTTI *)0x03015418;
const NiRTTI *	NiRTTI_NiPSysModifierFloatCtlr = (NiRTTI *)0x03015428;
const NiRTTI *	NiRTTI_NiPSysFieldModifier = (NiRTTI *)0x03015438;
const NiRTTI *	NiRTTI_NiPSysModifierBoolCtlr = (NiRTTI *)0x03015448;
const NiRTTI *	NiRTTI_NiPSysCollider = (NiRTTI *)0x03015458;
const NiRTTI *	NiRTTI_BSMultiBound = (NiRTTI *)0x0301D708;
const NiRTTI *	NiRTTI_BSMultiBoundRoom = (NiRTTI *)0x0301D718;
const NiRTTI *	NiRTTI_BSMultiBoundAABB = (NiRTTI *)0x0301D730;
const NiRTTI *	NiRTTI_BSMultiBoundOBB = (NiRTTI *)0x0301D748;
const NiRTTI *	NiRTTI_BSXFlags = (NiRTTI *)0x0301D768;
const NiRTTI *	NiRTTI_BSValueNode = (NiRTTI *)0x0301D780;
const NiRTTI *	NiRTTI_BSWindModifier = (NiRTTI *)0x03023D00;
const NiRTTI *	NiRTTI_BSTempNodeManager = (NiRTTI *)0x03023D20;
const NiRTTI *	NiRTTI_BSTempNode = (NiRTTI *)0x03023D30;
const NiRTTI *	NiRTTI_BSOcclusionShape = (NiRTTI *)0x03023D50;
const NiRTTI *	NiRTTI_BSRangeNode = (NiRTTI *)0x03023E48;
const NiRTTI *	NiRTTI_BSBlastNode = (NiRTTI *)0x03024080;
const NiRTTI *	NiRTTI_BSDebrisNode = (NiRTTI *)0x03024090;
const NiRTTI *	NiRTTI_BSDamageStage = (NiRTTI *)0x030240A0;
const NiRTTI *	NiRTTI_BSPSysArrayEmitter = (NiRTTI *)0x030240B0;
const NiRTTI *	NiRTTI_PArrayPoint = (NiRTTI *)0x030240C0;
const NiRTTI *	NiRTTI_BSMultiStreamInstanceTriShape = (NiRTTI *)0x030240E8;
const NiRTTI *	NiRTTI_BSMultiBoundShape = (NiRTTI *)0x03024118;
const NiRTTI *	NiRTTI_BSMultiBoundSphere = (NiRTTI *)0x03024128;
const NiRTTI *	NiRTTI_BSOcclusionBox = (NiRTTI *)0x03024140;
const NiRTTI *	NiRTTI_BSOcclusionPlane = (NiRTTI *)0x03024158;
const NiRTTI *	NiRTTI_BSPortal = (NiRTTI *)0x03024168;
const NiRTTI *	NiRTTI_BSPortalSharedNode = (NiRTTI *)0x03024178;
const NiRTTI *	NiRTTI_BSBodyMorphOffsetsExtraData = (NiRTTI *)0x03024190;
const NiRTTI *	NiRTTI_BSBehaviorGraphExtraData = (NiRTTI *)0x030241A0;
const NiRTTI *	NiRTTI_NiBSBoneLODController = (NiRTTI *)0x030241B8;
const NiRTTI *	NiRTTI_BSCullingProcess = (NiRTTI *)0x030241D8;
const NiRTTI *	NiRTTI_BSParticleSystemManager = (NiRTTI *)0x030241F8;
const NiRTTI *	NiRTTI_BSFurnitureMarkerNode = (NiRTTI *)0x03024220;
const NiRTTI *	NiRTTI_BSBound = (NiRTTI *)0x030242A0;
const NiRTTI *	NiRTTI_BSMultiBoundNode = (NiRTTI *)0x03024330;
const NiRTTI *	NiRTTI_BSBoneMap = (NiRTTI *)0x03024340;
const NiRTTI *	NiRTTI_BSAnimInteractionMarker = (NiRTTI *)0x03024358;
const NiRTTI *	NiRTTI_BSSceneGraph = (NiRTTI *)0x03024370;
const NiRTTI *	NiRTTI_BSPSysMultiTargetEmitterCtlr = (NiRTTI *)0x03024388;
const NiRTTI *	NiRTTI_BSGeometryListCullingProcess = (NiRTTI *)0x030243A0;
const NiRTTI *	NiRTTI_BSSubIndexTriShape = (NiRTTI *)0x030243B8;
const NiRTTI *	NiRTTI_BSDistantObjectLargeRefExtraData = (NiRTTI *)0x030243C8;
const NiRTTI *	NiRTTI_BSMasterParticleSystem = (NiRTTI *)0x03025D90;
const NiRTTI *	NiRTTI_BSProceduralLightningController = (NiRTTI *)0x03025DB8;
const NiRTTI *	NiRTTI_BSInvMarker = (NiRTTI *)0x03025DC8;
const NiRTTI *	NiRTTI_BSBoneLODExtraData = (NiRTTI *)0x03025DE0;
const NiRTTI *	NiRTTI_BSReference = (NiRTTI *)0x03025E00;
const NiRTTI *	NiRTTI_BSNodeReferences = (NiRTTI *)0x03025E10;
const NiRTTI *	NiRTTI_BSDecalPlacementVectorExtraData = (NiRTTI *)0x03025E20;
const NiRTTI *	NiRTTI_BSParentVelocityModifier = (NiRTTI *)0x03025E30;
const NiRTTI *	NiRTTI_BSWArray = (NiRTTI *)0x03025E40;
const NiRTTI *	NiRTTI_BSMultiBoundCapsule = (NiRTTI *)0x03025E58;
const NiRTTI *	NiRTTI_BSPSysStripUpdateModifier = (NiRTTI *)0x03025E68;
const NiRTTI *	NiRTTI_BSPSysSubTexModifier = (NiRTTI *)0x03025E78;
const NiRTTI *	NiRTTI_BSPSysScaleModifier = (NiRTTI *)0x03025E88;
const NiRTTI *	NiRTTI_BSLagBoneController = (NiRTTI *)0x03025E98;
const NiRTTI *	NiRTTI_BSNonUniformScaleExtraData = (NiRTTI *)0x03025EA8;
const NiRTTI *	NiRTTI_BSNiNode = (NiRTTI *)0x03025EC0;
const NiRTTI *	NiRTTI_BSInstanceTriShape = (NiRTTI *)0x03025ED0;
const NiRTTI *	NiRTTI_bhkWorldObject = (NiRTTI *)0x0302CC68;
const NiRTTI *	NiRTTI_bhkWorld = (NiRTTI *)0x0302CCA8;
const NiRTTI *	NiRTTI_bhkRigidBody = (NiRTTI *)0x0302DDE8;
const NiRTTI *	NiRTTI_bhkCollisionObject = (NiRTTI *)0x0302DE00;
const NiRTTI *	NiRTTI_bhkNiCollisionObject = (NiRTTI *)0x0302DEB0;
const NiRTTI *	NiRTTI_bhkAttachmentCollisionObject = (NiRTTI *)0x0302DF40;
const NiRTTI *	NiRTTI_WeaponObject = (NiRTTI *)0x0302DF50;
const NiRTTI *	NiRTTI_bhkRigidBodyT = (NiRTTI *)0x0302DF78;
const NiRTTI *	NiRTTI_bhkWorldM = (NiRTTI *)0x0302DF88;
const NiRTTI *	NiRTTI_bhkRefObject = (NiRTTI *)0x0302DFB0;
const NiRTTI *	NiRTTI_bhkSerializable = (NiRTTI *)0x0302DFC0;
const NiRTTI *	NiRTTI_bhkShape = (NiRTTI *)0x0302DFF0;
const NiRTTI *	NiRTTI_bhkEntity = (NiRTTI *)0x0302E008;
const NiRTTI *	NiRTTI_bhkPhantom = (NiRTTI *)0x0302E020;
const NiRTTI *	NiRTTI_bhkAabbPhantom = (NiRTTI *)0x0302E038;
const NiRTTI *	NiRTTI_bhkSphereRepShape = (NiRTTI *)0x0302E050;
const NiRTTI *	NiRTTI_bhkConvexShape = (NiRTTI *)0x0302E068;
const NiRTTI *	NiRTTI_bhkPCollisionObject = (NiRTTI *)0x0302E078;
const NiRTTI *	NiRTTI_hkPackedNiTriStripsData = (NiRTTI *)0x0302E088;
const NiRTTI *	NiRTTI_bhkShapePhantom = (NiRTTI *)0x0302E0A0;
const NiRTTI *	NiRTTI_bhkSimpleShapePhantom = (NiRTTI *)0x0302E0B8;
const NiRTTI *	NiRTTI_bhkCapsuleShape = (NiRTTI *)0x0302E0D0;
const NiRTTI *	NiRTTI_bhkBoxShape = (NiRTTI *)0x0302E0E8;
const NiRTTI *	NiRTTI_bhkSphereShape = (NiRTTI *)0x0302E100;
const NiRTTI *	NiRTTI_bhkBvTreeShape = (NiRTTI *)0x0302E118;
const NiRTTI *	NiRTTI_bhkNiTriStripsShape = (NiRTTI *)0x0302E130;
const NiRTTI *	NiRTTI_bhkPackedNiTriStripsShape = (NiRTTI *)0x0302E158;
const NiRTTI *	NiRTTI_bhkBlendCollisionObject = (NiRTTI *)0x0302E170;
const NiRTTI *	NiRTTI_bhkAvoidBox = (NiRTTI *)0x0302E190;
const NiRTTI *	NiRTTI_bhkLimitedHingeConstraint = (NiRTTI *)0x0302E1A8;
const NiRTTI *	NiRTTI_bhkMalleableConstraint = (NiRTTI *)0x0302E1C0;
const NiRTTI *	NiRTTI_bhkConstraint = (NiRTTI *)0x0302E1D8;
const NiRTTI *	NiRTTI_bhkPrismaticConstraint = (NiRTTI *)0x0302E1F0;
const NiRTTI *	NiRTTI_bhkAction = (NiRTTI *)0x0302E208;
const NiRTTI *	NiRTTI_bhkUnaryAction = (NiRTTI *)0x0302E220;
const NiRTTI *	NiRTTI_bhkTriSampledHeightFieldBvTreeShape = (NiRTTI *)0x0302E238;
const NiRTTI *	NiRTTI_bhkCachingShapePhantom = (NiRTTI *)0x0302EEA8;
const NiRTTI *	NiRTTI_bhkRagdollTemplateData = (NiRTTI *)0x0302EED0;
const NiRTTI *	NiRTTI_bhkRagdollTemplate = (NiRTTI *)0x0302EEE0;
const NiRTTI *	NiRTTI_bhkSPCollisionObject = (NiRTTI *)0x0302EEF0;
const NiRTTI *	NiRTTI_bhkMouseSpringAction = (NiRTTI *)0x0302EF08;
const NiRTTI *	NiRTTI_bhkHingeConstraint = (NiRTTI *)0x0302EF20;
const NiRTTI *	NiRTTI_bhkCompressedMeshShape = (NiRTTI *)0x0302EF98;
const NiRTTI *	NiRTTI_bhkCompressedMeshShapeData = (NiRTTI *)0x0302EFA8;
const NiRTTI *	NiRTTI_bhkConvexSweepShape = (NiRTTI *)0x0302EFC0;
const NiRTTI *	NiRTTI_bhkConvexTransformShape = (NiRTTI *)0x0302EFD8;
const NiRTTI *	NiRTTI_bhkConvexTranslateShape = (NiRTTI *)0x0302EFF0;
const NiRTTI *	NiRTTI_bhkConvexVerticesShape = (NiRTTI *)0x0302F008;
const NiRTTI *	NiRTTI_bhkCylinderShape = (NiRTTI *)0x0302F020;
const NiRTTI *	NiRTTI_bhkMultiSphereShape = (NiRTTI *)0x0302F038;
const NiRTTI *	NiRTTI_bhkPlaneShape = (NiRTTI *)0x0302F050;
const NiRTTI *	NiRTTI_bhkTriangleShape = (NiRTTI *)0x0302F068;
const NiRTTI *	NiRTTI_bhkMoppBvTreeShape = (NiRTTI *)0x0302F080;
const NiRTTI *	NiRTTI_bhkTransformShape = (NiRTTI *)0x0302F098;
const NiRTTI *	NiRTTI_bhkListShape = (NiRTTI *)0x0302F0B0;
const NiRTTI *	NiRTTI_bhkBallAndSocketConstraint = (NiRTTI *)0x0302F0C8;
const NiRTTI *	NiRTTI_bhkBallSocketConstraintChain = (NiRTTI *)0x0302F0E0;
const NiRTTI *	NiRTTI_bhkGroupConstraint = (NiRTTI *)0x0302F0F8;
const NiRTTI *	NiRTTI_bhkHingeLimitsConstraint = (NiRTTI *)0x0302F110;
const NiRTTI *	NiRTTI_bhkFixedConstraint = (NiRTTI *)0x0302F128;
const NiRTTI *	NiRTTI_bhkRagdollConstraint = (NiRTTI *)0x0302F140;
const NiRTTI *	NiRTTI_bhkRagdollLimitsConstraint = (NiRTTI *)0x0302F158;
const NiRTTI *	NiRTTI_bhkStiffSpringConstraint = (NiRTTI *)0x0302F170;
const NiRTTI *	NiRTTI_bhkWheelConstraint = (NiRTTI *)0x0302F188;
const NiRTTI *	NiRTTI_bhkBreakableConstraint = (NiRTTI *)0x0302F1A0;
const NiRTTI *	NiRTTI_bhkAngularDashpotAction = (NiRTTI *)0x0302F1B8;
const NiRTTI *	NiRTTI_bhkDashpotAction = (NiRTTI *)0x0302F1D0;
const NiRTTI *	NiRTTI_bhkLiquidAction = (NiRTTI *)0x0302F1E8;
const NiRTTI *	NiRTTI_bhkMotorAction = (NiRTTI *)0x0302F208;
const NiRTTI *	NiRTTI_bhkOrientHingedBodyAction = (NiRTTI *)0x0302F220;
const NiRTTI *	NiRTTI_bhkSpringAction = (NiRTTI *)0x0302F238;
const NiRTTI *	NiRTTI_bhkBlendController = (NiRTTI *)0x0302F248;
const NiRTTI *	NiRTTI_bhkExtraData = (NiRTTI *)0x0302F258;
const NiRTTI *	NiRTTI_bhkPoseArray = (NiRTTI *)0x0302F268;
const NiRTTI *	NiRTTI_bhkGenericConstraint = (NiRTTI *)0x0302F288;
const NiRTTI *	NiRTTI_bhkCharControllerShape = (NiRTTI *)0x0302F298;
const NiRTTI *	NiRTTI_bhkCollisionBox = (NiRTTI *)0x0302F2B0;
const NiRTTI *	NiRTTI_bhkShapeCollection = (NiRTTI *)0x0302F2C8;
const NiRTTI *	NiRTTI_bhkPositionConstraintMotor = (NiRTTI *)0x0302F330;
const NiRTTI *	NiRTTI_bhkVelocityConstraintMotor = (NiRTTI *)0x0302F340;
const NiRTTI *	NiRTTI_bhkSpringDamperConstraintMotor = (NiRTTI *)0x0302F350;
const NiRTTI *	NiRTTI_bhkCharacterProxy = (NiRTTI *)0x03030108;
const NiRTTI *	NiRTTI_bhkCharacterRigidBody = (NiRTTI *)0x03030120;
const NiRTTI *	NiRTTI_bhkHeightFieldShape = (NiRTTI *)0x03031428;
const NiRTTI *	NiRTTI_bhkConstraintChain = (NiRTTI *)0x03031440;
const NiRTTI *	NiRTTI_bhkBinaryAction = (NiRTTI *)0x03031458;
const NiRTTI *	NiRTTI_bhkPointToPathConstraint = (NiRTTI *)0x03031490;
const NiRTTI *	NiRTTI_DebugTextExtraData = (NiRTTI *)0x03032C80;
const NiRTTI *	NiRTTI_BSFadeNode = (NiRTTI *)0x031D0D90;
const NiRTTI *	NiRTTI_BSShaderProperty = (NiRTTI *)0x031D0DC0;
const NiRTTI *	NiRTTI_BSLeafAnimNode = (NiRTTI *)0x031D0DD0;
const NiRTTI *	NiRTTI_BSTreeNode = (NiRTTI *)0x031D0DE0;
const NiRTTI *	NiRTTI_ShadowSceneNode = (NiRTTI *)0x031D1200;
const NiRTTI *	NiRTTI_BSLightingShaderProperty = (NiRTTI *)0x031D1AF8;
const NiRTTI *	NiRTTI_BSGrassShaderProperty = (NiRTTI *)0x031D1B30;
const NiRTTI *	NiRTTI_BSShaderAccumulator = (NiRTTI *)0x031D1D40;
const NiRTTI *	NiRTTI_BSEffectShaderProperty = (NiRTTI *)0x031D1F00;
const NiRTTI *	NiRTTI_BSWaterShaderProperty = (NiRTTI *)0x03232D28;
const NiRTTI *	NiRTTI_BSBloodSplatterShaderProperty = (NiRTTI *)0x03232D38;
const NiRTTI *	NiRTTI_BSParticleShaderProperty = (NiRTTI *)0x032331B8;
const NiRTTI *	NiRTTI_BSTextureSet = (NiRTTI *)0x03233508;
const NiRTTI *	NiRTTI_BSShaderTextureSet = (NiRTTI *)0x03233518;
const NiRTTI *	NiRTTI_BSSkyShaderProperty = (NiRTTI *)0x03233818;
const NiRTTI *	NiRTTI_BSFadeNodeCuller = (NiRTTI *)0x032838A0;
const NiRTTI *	NiRTTI_BSDistantTreeShaderProperty = (NiRTTI *)0x032838D0;
const NiRTTI *	NiRTTI_BSCubeMapCamera = (NiRTTI *)0x03283AB0;
const NiRTTI *	NiRTTI_BSFogProperty = (NiRTTI *)0x03283B68;
const NiRTTI *	NiRTTI_BSClearZNode = (NiRTTI *)0x03495C48;
const NiRTTI *	NiRTTI_NiCollisionObject = (NiRTTI *)0x03495D68;
const NiRTTI *	NiRTTI_BSOrderedNode = (NiRTTI *)0x03495D78;
const NiRTTI *	NiRTTI_BSLines = (NiRTTI *)0x03495D88;
const NiRTTI *	NiRTTI_BSDynamicLines = (NiRTTI *)0x03495D98;
const NiRTTI *	NiRTTI_BSMultiIndexTriShape = (NiRTTI *)0x03495DB8;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyFloatController = (NiRTTI *)0x03495E60;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyUShortController = (NiRTTI *)0x03495E78;
const NiRTTI *	NiRTTI_BSLightingShaderPropertyColorController = (NiRTTI *)0x03495E90;
const NiRTTI *	NiRTTI_BSEffectShaderPropertyFloatController = (NiRTTI *)0x03495EC8;
const NiRTTI *	NiRTTI_BSEffectShaderPropertyColorController = (NiRTTI *)0x03495EE0;
const NiRTTI *	NiRTTI_BSNiAlphaPropertyTestRefController = (NiRTTI *)0x03495EF0;
const NiRTTI *	NiRTTI_BSPSysSimpleColorModifier = (NiRTTI *)0x03495F00;
const NiRTTI *	NiRTTI_BSPSysLODModifier = (NiRTTI *)0x03495F10;
const NiRTTI *	NiRTTI_BSParabolicCullingProcess = (NiRTTI *)0x03496398;
const NiRTTI *	NiRTTI_BSMeshLODTriShape = (NiRTTI *)0x034963A8;
const NiRTTI *	NiRTTI_BSLODMultiIndexTriShape = (NiRTTI *)0x034963B8;
const NiRTTI *	NiRTTI_BSSubIndexLandTriShape = (NiRTTI *)0x034963D0;
