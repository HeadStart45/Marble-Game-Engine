#include "mbpch.h"

#include "Application.h"
#include "Marble/Events/MouseEvent.h"
#include "Marble/Log.h"

///Remember to set GLFW project>CodeGeneration>Runtime library to /MT when you remake


namespace Marble
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}


