#pragma once
#include <Application/Interfaces/IApp.h>

#include "Core.h"

struct ReloadDesc;

namespace KoEngine {

	class KOENGINE_API Application : public IApp
	{
	public:
		static const uint32_t swapChainSize = 3;
		Application() = default;
		virtual ~Application() = default;

		virtual bool Init() override;
		virtual void Exit() override;
		virtual bool Load(ReloadDesc* pReloadDesc) override;
		virtual void Unload(ReloadDesc* pReloadDesc) override;
		virtual void Update(float deltaTime) override;
		virtual void Draw() override;
		virtual const char* GetName() override;
	};
}