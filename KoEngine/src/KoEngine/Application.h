#pragma once
#include "Core.h"

namespace KoEngine {

	class KOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined on CLIENT
	KoEngine::Application* CreateApplication();
}