#pragma once
#include "Event.h"

#include <sstream>

namespace Marble
{
	class MARBLE_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(float width, float height) : m_width(width), m_height(height) {}

		inline float GetHeight() { return m_height; }
		inline float GetWidth() { return m_width; }
	private:
		float m_width;
		float m_height;
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