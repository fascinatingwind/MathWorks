#include <cstdlib>

#include "vulkan_instance.h"

int main(int argv, char* argc[])
{
	Vulkan::VulkanInstance instance;
	instance.run();
	return EXIT_SUCCESS;
}