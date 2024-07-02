#include "mbpch.h"

#include "Application.h"
#include "Marble/Events/MouseEvent.h"
#include "Marble/Log.h"

#include <glad/glad.h>

///Remember to set GLFW project>CodeGeneration>Runtime library to /MT when you remake


namespace Marble
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			
			
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));

		
		MB_CORE_LOG("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}



	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}
	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		
		return true;
	}
}


