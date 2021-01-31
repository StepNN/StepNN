#pragma once

#include "StepNN/Neural/Interfaces/BaseLayerEngine.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

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