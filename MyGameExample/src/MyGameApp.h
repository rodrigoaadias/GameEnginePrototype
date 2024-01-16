#pragma once
#include <KoEngine.h>

class MyGameApp : public KoEngine::Application
{
public:
    MyGameApp() = default;
    ~MyGameApp() = default;

    bool Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    bool Load(ReloadDesc* pReloadDesc) override;
    void Unload(ReloadDesc* pReloadDesc) override;
    const char* GetName() override;
    void Exit() override;

    void addDescriptorSets();
    void removeDescriptorSets();
    void prepareDescriptorSets();

    bool addSwapChain();
	void addRootSignatures();
	void removeRootSignatures();
	void addShaders();
	void removeShaders();
	void addPipelines();
	void removePipelines();
	bool addDepthBuffer();

private:
    void SetRenderer(); //FIXME: move to application when it no longer crashes
    void ResourcePathDirs(); //FIXME: move to application when it no longer crashes
    /// <summary>
    /// Binds the UI, draw it and then unbinds it. It's used at the end of the draw of the UI.
    /// </summary>
    /// <param name="cmd"></param>
    /// <param name="renderTarget"></param>
    void DrawUI(Cmd* cmd, RenderTarget* renderTarget);
    void SetupSwapChain();
    /// <summary>
    /// When we begin a frame draw we have to get the correct semaphores, targets and fences.
    /// They vary based on the state of the swap chain. It also returns where in the swap chain
    /// we are because that information will be needed later.
    /// </summary>
    /// <param name="pCurrentRenderTarget"></param>
    /// <param name="pCurrentRenderCompleteSemaphore"></param>
    /// <param name="pCurrentRenderCompleteFence"></param>
    uint32_t SetupCurrentTargetSemaphoreAndFence(RenderTarget** pCurrentRenderTarget,
        Semaphore** pCurrentRenderCompleteSemaphore, Fence** pCurrentRenderCompleteFence);
};

DEFINE_KOENGINE_APP(MyGameApp);