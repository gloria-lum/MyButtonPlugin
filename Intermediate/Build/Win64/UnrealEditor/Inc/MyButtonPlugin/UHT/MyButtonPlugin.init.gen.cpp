// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyButtonPlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyButtonPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyButtonPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_MyButtonPlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MyButtonPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0306965D,
				0x018D62A2,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyButtonPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MyButtonPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyButtonPlugin(Z_Construct_UPackage__Script_MyButtonPlugin, TEXT("/Script/MyButtonPlugin"), Z_Registration_Info_UPackage__Script_MyButtonPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0306965D, 0x018D62A2));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
