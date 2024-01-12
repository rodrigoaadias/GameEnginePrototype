#include "MyGameApp.h"

bool MyGameApp::Init()
{
	return true;
}

void MyGameApp::Tick(float deltaTime)
{

}

void MyGameApp::Draw()
{
	
}

bool MyGameApp::Load(ReloadDesc* pReloadDesc)
{
	return true;
}

void MyGameApp::Unload(ReloadDesc* pReloadDesc)
{
}

const char* MyGameApp::GetAppName() const
{
	return "MyGameApp";
}

void MyGameApp::Exit()
{
	
}

KoEngine::Application* KoEngine::CreateApplication()
{
	return new MyGameApp();
}
