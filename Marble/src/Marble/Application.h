#pragma once

#include "Core.h"
#include "Window.h"

#include "Marble/LayerStack.h"
#include "Marble/Events/Event.h"
#include "Marble/Events/ApplicationEvent.h"

namespace Marble
{
	class MARBLE_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowClosedEvent& e);
		
		std::shared_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	//Defined in CLIENT
	Application* CreateApplication();
}



