#pragma once

#include <memory>
#include <vector>

#include "src/Neural/Layer/Settings/BaseLayerSettings.h"

namespace StepNN {

namespace Interfaces {

class ILayer
{
public:
	virtual ~ILayer() = default;

	virtual void SetSettings(const BaseLayerSettings& settings) = 0;
	virtual const BaseLayerSettings& GetBaseSettings() const = 0;

	virtual const std::string& GetId() const noexcept = 0;
};

}

using LayerPtr   = Interfaces::ILayer*;
using LayerCPtr  = const LayerPtr;
using LayerPtrs  = std::vector<LayerPtr>;
using LayerUPtr  = std::unique_ptr<Interfaces::ILayer>;
using LayerUPtrs = std::vector<LayerUPtr>;

}