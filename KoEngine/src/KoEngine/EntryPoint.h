#pragma once

#ifdef KE_WINDOWS_PLATFORM
#define DEFINE_KOENGINE_APP(appClass) DEFINE_APPLICATION_MAIN(appClass)
#else
	#error KoEngine only support Windows!
#endif