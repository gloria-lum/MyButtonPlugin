// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyButtonPlugin/Public/MyActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	MYBUTTONPLUGIN_API UClass* Z_Construct_UClass_AMyActor();
	MYBUTTONPLUGIN_API UClass* Z_Construct_UClass_AMyActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MyButtonPlugin();
// End Cross Module References
	void AMyActor::StaticRegisterNativesAMyActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyActor);
	UClass* Z_Construct_UClass_AMyActor_NoRegister()
	{
		return AMyActor::StaticClass();
	}
	struct Z_Construct_UClass_AMyActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CubeMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VisualMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VisualMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMaterialInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMaterialInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyButtonPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyActor.h" },
		{ "ModuleRelativePath", "Public/MyActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_CubeMeshComponent_MetaData[] = {
		{ "Category", "MyActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_CubeMeshComponent = { "CubeMeshComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMyActor, CubeMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_CubeMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_CubeMeshComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_VisualMesh_MetaData[] = {
		{ "Category", "MyActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_VisualMesh = { "VisualMesh", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMyActor, VisualMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_VisualMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_VisualMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_DynamicMaterialInstance_MetaData[] = {
		{ "Category", "Materials" },
		{ "ModuleRelativePath", "Public/MyActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_DynamicMaterialInstance = { "DynamicMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AMyActor, DynamicMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_DynamicMaterialInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_DynamicMaterialInstance_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_CubeMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_VisualMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_DynamicMaterialInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyActor_Statics::ClassParams = {
		&AMyActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyActor()
	{
		if (!Z_Registration_Info_UClass_AMyActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyActor.OuterSingleton, Z_Construct_UClass_AMyActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyActor.OuterSingleton;
	}
	template<> MYBUTTONPLUGIN_API UClass* StaticClass<AMyActor>()
	{
		return AMyActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyActor);
	struct Z_CompiledInDeferFile_FID_MyPluginProject_Plugins_MyButtonPlugin_Source_MyButtonPlugin_Public_MyActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyPluginProject_Plugins_MyButtonPlugin_Source_MyButtonPlugin_Public_MyActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyActor, AMyActor::StaticClass, TEXT("AMyActor"), &Z_Registration_Info_UClass_AMyActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyActor), 1456229705U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyPluginProject_Plugins_MyButtonPlugin_Source_MyButtonPlugin_Public_MyActor_h_3062294626(TEXT("/Script/MyButtonPlugin"),
		Z_CompiledInDeferFile_FID_MyPluginProject_Plugins_MyButtonPlugin_Source_MyButtonPlugin_Public_MyActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyPluginProject_Plugins_MyButtonPlugin_Source_MyButtonPlugin_Public_MyActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
