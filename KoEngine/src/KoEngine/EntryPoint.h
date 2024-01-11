#pragma once

#ifdef KE_WINDOWS_PLATFORM

extern KoEngine::Application* KoEngine::CreateApplication();

int main(int argc, char** argv) {
	printf("Starting KoEngine!\n");
	auto app = KoEngine::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error KoEngine only support Windows!
#endif