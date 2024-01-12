#pragma once
#include <KoEngine.h>

class MyGameApp : public KoEngine::Application
{
public:
    MyGameApp() = default;
    ~MyGameApp() = default;
    
    bool Init() override;
    void Tick(float deltaTime) override;
    void Draw() override;
    bool Load(ReloadDesc* pReloadDesc) override;
    void Unload(ReloadDesc* pReloadDesc) override;
    const char* GetAppName() const override;
    void Exit() override;

private:
    Renderer* pRenderer = nullptr;
    
};