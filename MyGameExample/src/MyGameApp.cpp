#include <KoEngine.h>

class KOENGINE_API MyGameApp : public KoEngine::Application
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