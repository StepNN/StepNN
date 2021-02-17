#pragma once

#include "StepNN/Neural/Interfaces/BaseLayerEngine.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class LayerEngineTF : virtual public BaseLayerEngine
{
public:
	explicit LayerEngineTF();

/// Implementation of ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) override;
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) override;
///
};

}