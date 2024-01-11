#include <KoEngine.h>

class MyGameApp : public KoEngine::Application
{
public:
	MyGameApp() {

	}

	~MyGameApp()
	{

	}
};

KoEngine::Application* KoEngine::CreateApplication()
{
	return new MyGameApp();
}