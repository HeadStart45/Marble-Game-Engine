#pragma once

#include "Core.h"


namespace Marble
{
	class MARBLE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	//Defined in CLIENT
	Application* CreateApplication();
}



