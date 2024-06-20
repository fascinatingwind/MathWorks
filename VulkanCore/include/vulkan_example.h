#pragma once
#ifndef VULKAN_EXAMPLE_H
#define VULKAN_EXAMPLE_H

#include <vector>
#include <optional>
#include <vulkan/vulkan_core.h>

struct GLFWwindow;

struct queue_family_indices
{
	std::optional<uint32_t> graphics_family;
	std::optional<uint32_t> present_family;

	bool is_complete()
	{
		return graphics_family.has_value()
			&& present_family.has_value();
	}
};

struct swap_chain_support_details
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> present_modes;
};

namespace Vulkan
{
	class VulkanExample
	{
	public:
		explicit VulkanExample() = default;
		~VulkanExample() = default;

		void run();

		bool framebuffer_resized = false;

	private:
		uint32_t current_frame = 0;
		VkInstance instance = VK_NULL_HANDLE;
		VkPhysicalDevice physical_device = VK_NULL_HANDLE;
		VkDevice logical_device = VK_NULL_HANDLE;
		VkQueue graphics_queue = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		VkQueue present_queue = VK_NULL_HANDLE;
		VkSwapchainKHR swapchain = VK_NULL_HANDLE;
		VkCommandPool command_pool = VK_NULL_HANDLE;
		VkDebugUtilsMessengerEXT debug_messenger = VK_NULL_HANDLE;
		VkRenderPass render_pass = VK_NULL_HANDLE;
		VkDescriptorSetLayout descriptor_set_layout = VK_NULL_HANDLE;
		VkPipelineLayout pipeline_layout = VK_NULL_HANDLE;
		VkPipeline graphics_pipeline = VK_NULL_HANDLE;
		VkBuffer vertex_buffer = VK_NULL_HANDLE;
		VkDeviceMemory vertex_buffer_memory = VK_NULL_HANDLE;
		VkMemoryRequirements mem_requirements{};
		VkBuffer index_buffer = VK_NULL_HANDLE;
		VkDeviceMemory index_buffer_memory = VK_NULL_HANDLE;
		VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;
		VkImage texture_image;
		VkDeviceMemory texture_image_memory;
		VkImageView texture_image_view;
		VkSampler texture_sampler;

		std::vector<VkDescriptorSet> descriptor_sets;
		std::vector<VkBuffer> uniform_buffers;
		std::vector<VkDeviceMemory> uniform_buffers_memory;
		std::vector<void*> uniform_buffers_mapped;

		std::vector<VkCommandBuffer> command_buffers;
		std::vector<VkSemaphore> image_available_semaphores;
		std::vector<VkSemaphore> render_finished_semaphores;
		std::vector<VkFence> in_flight_fences;

		GLFWwindow* window = nullptr;
		VkFormat swap_chain_image_format = VK_FORMAT_UNDEFINED;
		VkExtent2D swap_chain_extent{};

		std::vector<VkImage> swap_chain_images;
		std::vector<VkImageView> swap_chain_image_views;
		std::vector<VkFramebuffer> swap_chain_framebuffers;

		void init_window();
		void create_instance();
		void init_vulkan();
		void clean_up();
		void setup_debug_messenger();
		void create_surface();
		void pick_physical_device();
		void create_logical_device();
		void create_swap_chain();
		void create_image_views();
		void create_graphics_pipeline();
		void create_render_pass();
		void create_framebuffers();
		void create_command_pool();
		void create_vertex_buffer();
		void create_index_buffer();
		void create_command_buffers();
		void record_command_buffer(VkCommandBuffer command_buffer, uint32_t image_index);
		void create_sync_objects();
		void recreate_swapchain();
		void cleanup_swapchain();
		void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& buffer_memory);
		void copy_buffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
		void create_descriptor_set_layout();
		void create_uniform_buffers();
		void create_descriptor_pool();
		void create_descriptor_sets();
		void update_uniform_buffer(uint32_t current_image);
		void create_texture_image();
		void create_texture_image_view();
		void create_image(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& image_memory);
		VkImageView create_image_view(VkImage image, VkFormat format);
		VkCommandBuffer begin_single_time_commands();
		void end_single_time_commands(VkCommandBuffer command_buffer);
		void transition_image_layout(VkImage image, VkFormat format, VkImageLayout old_layout, VkImageLayout new_layout);
		void copy_buffer_to_image(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
		void create_texture_sampler();
		void main_loop();
		void draw_frame();

		bool check_validation_layer_support() const;
		bool is_device_suitable(VkPhysicalDevice device) const;
		bool check_device_extension_support(VkPhysicalDevice device) const;

		int rate_device_suitability(VkPhysicalDevice device) const;

		std::vector<const char*> get_required_extensions();
		queue_family_indices find_queue_families(VkPhysicalDevice device) const;
		swap_chain_support_details query_swap_chain_support(VkPhysicalDevice device) const;
		VkExtent2D choose_swap_extent(const VkSurfaceCapabilitiesKHR& capabilities);
		VkShaderModule create_shader_module(const std::vector<char>& code);
		uint32_t find_memory_type(uint32_t type_filter, VkMemoryPropertyFlags properties);
	};
}
#endif