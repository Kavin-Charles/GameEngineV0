#include "hzpch.h"
#include "OpenGLContext.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <gl/GL.h>

namespace Hazel
{
	OpenGLContext::OpenGLContext(GLFWwindow* handle) : m_WindowHandle(handle)
	{
		HZ_CORE_ASSERT(handle, "WindowHandle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(staus, "Glad did not load properly!")

	}
	void OpenGLContext::SwapBuffers()
	{
		
		glfwSwapBuffers(m_WindowHandle);
	}
};