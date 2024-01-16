#include "Application.h"
#include "Log.h"
#include "../KoEngine.h"

namespace KoEngine {
    void Application::UpdateVSyncSettings()
    {
        if (pSwapChain->mEnableVsync != mSettings.mVSyncEnabled)
        {
            waitQueueIdle(pGraphicsQueue);
            ::toggleVSync(pRenderer, &pSwapChain);
        }
    }
    bool Application::Init()
    {
        Log::Init();
        KE_LOG_INFO("KoEngine application started!!\n");

        // RendererDesc settings;
        // memset(&settings, 0, sizeof(settings));
        // settings.mD3D11Supported = true;
        // settings.mGLESSupported = false;
        // initRenderer(GetName(), &settings, &pRenderer);
        return true;
    }

    void Application::Update(float deltaTime)
    {
    }

    void Application::Draw()
    {
    }

    bool Application::Load(ReloadDesc* pReloadDesc)
    {
        return true;
    }

    void Application::Unload(ReloadDesc* pReloadDesc)
    {
    }

    const char* Application::GetName()
    {
        return "KoEngine Application";
    }

    void Application::Exit()
    {
        for (auto i = 0; i < swapChainSize; ++i) {
            removeFence(pRenderer, pRenderCompleteFences[i]);
            removeSemaphore(pRenderer, pRenderCompleteSemaphores[i]);
            removeCmd(pRenderer, pCmds[i]);
            removeCmdPool(pRenderer, pCmdPools[i]);
        }
        removeQueue(pRenderer, pGraphicsQueue);
        exitRenderer(pRenderer);
        pRenderer = NULL;
    }
}
