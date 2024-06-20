#pragma once

#ifdef MB_PLATFORM_WINDOWS

extern Marble::Application* Marble::CreateApplication();

int main(int _argc, char** _argv)
{
	Marble::Log::Init();
	MB_LOG("Client logger macro is working!");
	MB_CORE_WARN("Core logger macro is working!");


	auto app = Marble::CreateApplication();
	app->Run();
	delete app;

}

#endif // MB_PLATFORM_WINDOWS
