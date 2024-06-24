#include "mbpch.h"

#include "Application.h"
#include "Marble/Events/MouseEvent.h"
#include "Marble/Log.h"

namespace Marble
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		MouseButtonPressedEvent e(2);
		MB_CORE_LOG(e.ToString());
		
		
		
		while (true);
	}
}


