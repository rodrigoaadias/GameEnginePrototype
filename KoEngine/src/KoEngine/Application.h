#pragma once
#include "Core.h"

class ReloadDesc; 

namespace KoEngine {

	class KOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		virtual bool Init() = 0;
		virtual void Exit() = 0;
		virtual bool Load(ReloadDesc* pReloadDesc) = 0;
		virtual void Unload(ReloadDesc* pReloadDesc) = 0;
		virtual void Tick(float deltaTime) = 0;
		virtual void Draw() = 0;
		virtual const char* GetAppName() const = 0;
	};

	// to be defined on CLIENT
	KoEngine::Application* CreateApplication();
}