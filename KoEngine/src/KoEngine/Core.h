#pragma once

#ifdef KE_WINDOWS_PLATFORM
	#ifdef KE_BUILD_DLL
		#define KOENGINE_API __declspec(dllexport)
	#else
		#define KOENGINE_API __declspec(dllimport)
	#endif // KE_BUILD_DLL
#else
	#error KoEngine only support Windows!
#endif
