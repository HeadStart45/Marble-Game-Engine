#pragma once

#include "mbpch.h"

#include "Marble/Core.h"
#include "Marble/Events/Event.h"


namespace Marble
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Marble: A Game Engine",
			unsigned int width = 1920,
			unsigned int height = 1080)
			: Title(title), Width(width), Height(height) {}
	};

	//virtual interface representing a window on a desktop. This is operating
	//system agnostic

	class MARBLE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}

