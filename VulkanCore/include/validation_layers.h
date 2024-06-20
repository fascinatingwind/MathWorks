#pragma once
#ifndef VALIDATION_LAYERS_H
#define VALIDATION_LAYERS_H

#include "validation_layers_interface.h"

#include <vector>

namespace Vulkan
{
  class ValidationLayers final : public ValidationLayersInterface
  {
    std::vector<const char*> layers_;

  public:
    explicit ValidationLayers();

    virtual bool enable() const override;
    virtual bool support() const override;
    virtual const char* const* data() const override;
    virtual size_t size() const override;
  };
}
#endif