#pragma once
#include <Application/Interfaces/IApp.h>

#ifdef KE_WINDOWS_PLATFORM

extern KoEngine::Application* KoEngine::CreateApplication();
//
// int main(int argc, char** argv) {
//
// 	KoEngine::Log::Init();
// 	
// 	auto app = KoEngine::CreateApplication();
// 	app->Run();
// 	delete app;
// }


class KoEngineApp : public IApp
{
public:
	bool Init() override
	{
		pApplication = KoEngine::CreateApplication();
		KoEngine::Log::Init();

		KE_LOG_INFO("KoEngine application started!!\n");
		return 1;
	}

	void Exit() override
	{ }

	bool Load(ReloadDesc* pReloadDesc) override
	{
		return true;
	}

	void Unload(ReloadDesc* pReloadDesc) override
	{
		
	}

	void Update(float deltaTime) override
	{
		KE_LOG_INFO("Application Running...\n");
		pApplication->Run();
	}

	void Draw() override
	{
		
	}

	const char* GetName() override
	{
		return "KoEngine Application";
	}

private:
	KoEngine::Application* pApplication{};
};

DEFINE_APPLICATION_MAIN(KoEngineApp)

#else
	#error KoEngine only support Windows!
#endif