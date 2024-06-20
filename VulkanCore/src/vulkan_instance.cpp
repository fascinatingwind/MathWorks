#include "vulkan_instance.h"

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan_core.h>
#include <mutex>
#include <iostream>
#include <GLFW/glfw3.h>

#include "validation_layers.h"

namespace
{
	constexpr std::string_view engine_name = "VEn";
	uint32_t engine_version = VK_MAKE_VERSION(1, 0, 0);

	constexpr std::string_view application_name = "VEn research";
	uint32_t application_version = VK_MAKE_VERSION(1, 0, 0);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
		VkDebugUtilsMessageTypeFlagsEXT message_type,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
	{
		if (message_severity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
		{
			// Message is important enough to show
		}
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
		return VK_FALSE;
	}

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& create_info)
	{
		create_info = {};
		create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		create_info.pfnUserCallback = debug_callback;
	}
}

namespace Vulkan
{
	void Instance::init_validation_layers()
	{
		validationLayers = std::make_unique<ValidationLayers>();
	}

	Instance::Instance()
	{
		init_validation_layers();
		init_vk_instance();
		setup_debug_messanger();
	}

  void Instance::init_vk_instance()
  {
		if (validationLayers->enable() && !validationLayers->support())
			throw std::runtime_error("validation layers requested, but not available!");

		VkApplicationInfo app_info{};
		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.pApplicationName = application_name.data();
		app_info.applicationVersion = application_version;
		app_info.pEngineName = engine_name.data();
		app_info.engineVersion = engine_version;
		app_info.apiVersion = VK_API_VERSION_1_3;

		VkInstanceCreateInfo create_info{};
		create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		create_info.pApplicationInfo = &app_info;

		const auto required_extensions = get_required_extensions();

		create_info.enabledExtensionCount = static_cast<uint32_t>(required_extensions.size());
		create_info.ppEnabledExtensionNames = required_extensions.data();
		if (validationLayers->enable())
		{
			create_info.enabledLayerCount = static_cast<uint32_t>(validationLayers->size());
			create_info.ppEnabledLayerNames = validationLayers->data();
			VkDebugUtilsMessengerCreateInfoEXT debug_create_info;
			populateDebugMessengerCreateInfo(debug_create_info);
			create_info.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debug_create_info;
		}
		else
		{
			create_info.enabledLayerCount = 0;
			create_info.pNext = nullptr;
		}

		if (vkCreateInstance(&create_info, nullptr, &vk_instance) != VK_SUCCESS)
			throw std::runtime_error("failed to create instance!");
  }

	void Instance::setup_debug_messanger()
	{
		if (!validationLayers->enable())
			return;

		VkDebugUtilsMessengerCreateInfoEXT create_info;
		populateDebugMessengerCreateInfo(create_info);
		auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vk_instance, "vkCreateDebugUtilsMessengerEXT");
		auto result = VK_ERROR_EXTENSION_NOT_PRESENT;
		if (func != nullptr)
			result = func(vk_instance, &create_info, nullptr, &debug_messenger);
		if(result != VK_SUCCESS)
			throw std::runtime_error("failed to set up debug messenger");
	}

	std::vector<const char*> Instance::get_required_extensions()
	{
		uint32_t glfw_extension_count = 0;
		const char** glfw_extensions;
		glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

		std::vector<const char*> extensions(glfw_extensions, glfw_extensions + glfw_extension_count);

		if (validationLayers->enable()) {
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		return extensions;
	}

  void Instance::cleanUp()
  {
    vkDestroyInstance(vk_instance, nullptr);
  }

	VkInstance_T* Instance::vk()
	{
		return vk_instance;
	}

  Instance& Instance::instance()
  {
    static std::once_flag flag;
		std::call_once(flag, []() { instance_.reset(new Instance()); });
    return *instance_;
  }
}