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
}