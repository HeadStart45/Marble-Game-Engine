#pragma once

#ifdef MB_PLATFORM_WINDOWS

extern Marble::Application* Marble::CreateApplication();

int main(int _argc, char** _argv)
{

	auto app = Marble::CreateApplication();
	app->Run();
	delete app;

}

#endif // MB_PLATFORM_WINDOWS
