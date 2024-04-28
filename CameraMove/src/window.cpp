#include "window.h"
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

namespace Ui
{
	using namespace Geometry;

	Window::Window(const SizeI& size)
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		window_ = glfwCreateWindow(size.w(), size.h(), "Vulkan", nullptr, nullptr);
	}

	Window::~Window()
	{
		glfwDestroyWindow(window_);
		glfwTerminate();
	}

	void Window::Loop()
	{
		while (!glfwWindowShouldClose(window_))
			glfwPollEvents();
	}
}