#pragma once

#include "StepNN/Neural/Interfaces/BaseLayerEngine.h"

#include "StepNN/Neural/Impl/Torch/Interfaces/IControllerTorchSequential.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class LayerEngineTorch
	: virtual public BaseLayerEngine
	, virtual public IControllerTorchSequential
{
public:
	explicit LayerEngineTorch() = default;

/// ILayerEngine
	void AddLossLayer(const BaseLayerSettings& settings);
///

/// ILayerFactory
	std::shared_ptr<ILayer> CreateLayer(const std::string& layerID) override;
	std::shared_ptr<ILayer> CreateLayer(const BaseLayerSettings& settings) override;
///
};

}