#pragma once

#include "Core.h"
#include "Window.h"

namespace Marble
{
	class MARBLE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	private:
		std::shared_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//Defined in CLIENT
	Application* CreateApplication();
}



