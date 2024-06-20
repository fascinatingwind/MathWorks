#pragma once
#ifndef VULKAN_INSTANCE_H
#define VULKAN_INSTANCE_H

#include "validation_layers_interface.h"

#include <memory>
#include <vector>

struct VkInstance_T;
struct VkDebugUtilsMessengerEXT_T;

namespace Vulkan
{
  class Instance
  {
    static inline VkInstance_T* vk_instance = nullptr;
    static inline std::unique_ptr<Instance> instance_;
    VkDebugUtilsMessengerEXT_T* debug_messenger = nullptr;

    std::unique_ptr<ValidationLayersInterface> validationLayers = nullptr;
    Instance();

  public:
    Instance(const Instance&) = delete;
    Instance(Instance&&) noexcept = delete;
    const Instance& operator=(const Instance&) = delete;
    Instance& operator=(Instance&&) noexcept = delete;

    static Instance& instance();
    void cleanUp();
    VkInstance_T* vk();

  private:
    void init_validation_layers();
    void init_vk_instance();
    void setup_debug_messanger();

    std::vector<const char*> get_required_extensions();
  };
}
#endif