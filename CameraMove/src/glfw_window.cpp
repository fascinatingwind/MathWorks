#include "glfw_window.h"

#include <GLFW/glfw3.h>

namespace GLFW
{
	GlfwWindow::GlfwWindow(const std::string& title, int w, int h)
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		window_instance = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
	}

	GlfwWindow::~GlfwWindow()
	{
		glfwDestroyWindow(window_instance);
		glfwTerminate();
	}
	void GlfwWindow::loop()
	{
		while (!glfwWindowShouldClose(window_instance))
			glfwPollEvents();
	}

	GLFWwindow* GlfwWindow::window() const
	{
		return window_instance;
	}
}