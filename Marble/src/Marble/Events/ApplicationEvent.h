#pragma once
#include "Marble/Events/Event.h"

namespace Marble
{
	class MARBLE_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		inline unsigned int GetHeight() { return m_height; }
		inline unsigned int GetWidth() { return m_width; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowResizedEvent: Width => " << m_width << " Height => " << m_height;
			return stream.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)


	private:
		unsigned int m_width;
		unsigned int m_height;
	};


	class MARBLE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MARBLE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MARBLE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MARBLE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}