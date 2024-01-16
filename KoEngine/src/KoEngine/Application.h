#pragma once
#include <Application/Interfaces/IApp.h>

#include "Core.h"

struct ReloadDesc;
class Renderer;
struct SwapChain;
struct Queue;
struct CmdPool;
struct Cmd;
struct Fence;
struct Semaphore;
namespace KoEngine {

	class KOENGINE_API Application : public IApp
	{
	public:
		static const uint32_t swapChainSize = 3;
	protected:
		Renderer* pRenderer = nullptr;
		SwapChain* pSwapChain = nullptr;

		Queue* pGraphicsQueue = NULL;
		Cmd* pCmds[KoEngine::Application::swapChainSize];
		CmdPool* pCmdPools[KoEngine::Application::swapChainSize];
		Fence* pRenderCompleteFences[KoEngine::Application::swapChainSize] = { NULL };
		Semaphore* pRenderCompleteSemaphores[KoEngine::Application::swapChainSize] = { NULL };
		/// <summary>
		/// Compares the settings of the vsync in IApp with the one in the swapChain.
		/// If they differ then wait for the end of the graphics queue and updates the
		/// swap chain with the new setting. This should be invoked in the beginning of
		/// the Draw() method and will run at least once, when the Draw() method runs 
		/// for the first time.
		/// </summary>
		void UpdateVSyncSettings();
	public:
		
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