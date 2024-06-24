#pragma once
#include "Event.h"

#include <sstream>

namespace Marble
{
	/// <summary>
	/// Called when the user moves the mouse, gives the mouses position in pixels
	/// </summary>
	class MARBLE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_mousePosY(y), m_mousePosX(x) {}
		
		inline float GetPosX() { return m_mousePosX; }
		inline float GetPosY() { return m_mousePosY; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMovedEvent: (" << m_mousePosX << ", " << m_mousePosY << ")";
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_mousePosX;
		float m_mousePosY;
	};
	/// <summary>
	/// Called when the mouse is scrolled. Handles both vertical and horizontal scrolling
	/// </summary>
	class MARBLE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetXOffset() { return m_xOffset; }
		inline float GetYOffset() { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseScrolledEvent: X => " << m_xOffset << " Y => " << m_yOffset;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_xOffset;
		float m_yOffset;
	};
	/// <summary>
	/// Abstract base class for pressed and released mouse button events
	/// </summary>
	class MARBLE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : m_button(button) {}
		int m_button;
	};
	/// <summary>
	/// Called when a mouse button is pressed
	/// </summary>
	class MARBLE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressed: " << m_button;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
			
	};
	/// <summary>
	/// Called when a mouse button is released
	/// </summary>
	class MARBLE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleased: " << m_button;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}