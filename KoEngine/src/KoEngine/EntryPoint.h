#pragma once
#include <Application/Interfaces/IApp.h>

#ifdef KE_WINDOWS_PLATFORM

extern KoEngine::Application* KoEngine::CreateApplication();

class KoEngineApp : public IApp
{
public:
	bool Init() override
	{
		KoEngine::Log::Init();
		KE_LOG_INFO("KoEngine application started!!\n");
		
		pApplication = KoEngine::CreateApplication();
		pApplication->Init();

		return 1;
	}

	void Update(float deltaTime) override
	{
		pApplication->Tick(deltaTime);
	}
	
	void Draw() override
	{
		pApplication->Draw();
	}
	
	bool Load(ReloadDesc* pReloadDesc) override
	{
		return pApplication->Load(pReloadDesc);
	}
	
	void Unload(ReloadDesc* pReloadDesc) override
	{
		pApplication->Unload(pReloadDesc);
	}
	
	const char* GetName() override
	{
		return "KoEngine Application";
	}
	
	void Exit() override
	{
		pApplication->Exit();
	}
	
private:
	KoEngine::Application* pApplication{};
};

DEFINE_APPLICATION_MAIN(KoEngineApp)

#else
	#error KoEngine only support Windows!
#endif