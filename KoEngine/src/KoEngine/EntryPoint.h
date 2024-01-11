#pragma once

#ifdef KE_WINDOWS_PLATFORM

extern KoEngine::Application* KoEngine::CreateApplication();

int main(int argc, char** argv) {

	KoEngine::Log::Init();
	KE_CORE_LOG_WARN("Initialized Logger");
	
	auto app = KoEngine::CreateApplication();
	int number = 15;
	KE_LOG_INFO("App initialized! Hello! Var={0}", number);
	app->Run();
	delete app;
}

#else
	#error KoEngine only support Windows!
#endif