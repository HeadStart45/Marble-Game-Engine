#include "mbpch.h"
#include "WindowsWindow.h"
#include "Marble/Log.h"
#include "Marble/Events/ApplicationEvent.h"
#include "Marble/Events/KeyEvent.h"
#include "Marble/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Marble
{

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* disc)
	{
		MB_CORE_ERROR("GLFW had an error {0} => {1}", error, disc);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;

		MB_CORE_LOG("Creating Window {0} => ({1}, {2})", props.Title, props.Width, props.Height);
		//Setup G
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();

			MB_CORE_ASSERT(success, "Unable to initialise GLFW window");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		//Setup Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MB_CORE_ASSERT(status, "Unable to initialise Glad");


		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//GLFW Window Callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				
			data.Width = width;
			data.Height = height;

			WindowResizedEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowClosedEvent event;
			data.EventCallback(event);
		});


		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			});

	}
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);

		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;

	}
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
	
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);

	}
}


