#include "validation_layers.h"

#include <vulkan/vulkan.h>

namespace Vulkan
{
  ValidationLayers::ValidationLayers()
  {
    layers_ = { "VK_LAYER_KHRONOS_validation" };
  }

  bool ValidationLayers::enable() const
  {
#ifdef NDEBUG
    return false;
#else
    return true;
#endif
  }

  bool ValidationLayers::support() const
  {
    uint32_t layer_count;
    vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

    std::vector<VkLayerProperties> available_layers(layer_count);
    vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

    for (const char* layerName : layers_)
    {
      const auto findIt = std::find_if(available_layers.begin(), available_layers.end(),
        [&](const VkLayerProperties& layer_propery)
        {
          return strcmp(layerName, layer_propery.layerName) == 0;
        });
      if (findIt == available_layers.end())
        return false;
    }

    return true;
  }

  const char* const* ValidationLayers::data() const
  {
    return layers_.data();
  }

  size_t ValidationLayers::size() const
  {
    return layers_.size();
  }

}