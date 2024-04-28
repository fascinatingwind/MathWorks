#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "size.h"

struct GLFWwindow;

namespace Ui
{
	class Window
	{
	public:
		explicit Window(const Geometry::SizeI& size);
		~Window();

		void Loop();

	private:
		GLFWwindow* window_ = nullptr;
	};
}
#endif