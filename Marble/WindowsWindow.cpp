#include "mbpch.h"
#include "WindowsWindow.h"
#include "Marble/Log.h"
namespace Marble
{

	static bool s_GLFWInitialized = false;

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

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();

			MB_CORE_ASSERT(success, "Unable to initialise GLFW window");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


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


