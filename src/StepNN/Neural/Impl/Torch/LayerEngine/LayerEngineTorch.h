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
	explicit LayerEngineTorch();

/// Implementation of ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) override;
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) override;
///
};

}