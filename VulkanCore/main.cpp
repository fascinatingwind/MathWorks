#include <cstdlib>

#include "vulkan_instance.h"

int main(int argv, char* argc[])
{
	Vulkan::Instance::instance();
	return EXIT_SUCCESS;
}