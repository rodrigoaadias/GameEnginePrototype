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

int main() {
	MyGameApp* app = new MyGameApp();
	app->Run();
	delete app;
}