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
    void ResourcePathDirs();
    Renderer* pRenderer = nullptr;
    
};

DEFINE_KOENGINE_APP(MyGameApp);