#pragma once

#include "StepNN/Neural/Layer/Engine/BaseLayerEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class LayerEngineTorch : virtual public BaseLayerEngine
{
public:
	explicit LayerEngineTorch();

/// Implementation of ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) const override;
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) const override;
///
};

}