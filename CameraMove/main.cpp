#include <cstdlib>

#include "glfw_window.h"

int main(int argv, char* argc[])
{
	GLFW::GlfwWindow window("Example", 800, 600);
	window.loop();
	return EXIT_SUCCESS;
}