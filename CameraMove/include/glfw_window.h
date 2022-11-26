#pragma once
#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include <string>

struct GLFWwindow;

namespace GLFW
{
	class GlfwWindow
	{
	public:
		GlfwWindow(const std::string& title, int w, int h);
		~GlfwWindow();

		void loop();
		GLFWwindow* window() const;

	private:
		GLFWwindow* window_instance = nullptr;
	};
}
#endif