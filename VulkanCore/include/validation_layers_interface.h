#pragma once
#ifndef VALIDATION_LAYERS_INTERFACE_H
#define VALIDATION_LAYERS_INTERFACE_H

namespace Vulkan
{
  class ValidationLayersInterface
  {
  public:
    virtual ~ValidationLayersInterface() = default;

    virtual bool enable() const = 0;
    virtual bool support() const = 0;
    virtual const char* const* data() const = 0;
    virtual size_t size() const = 0;
  };
}

#endif