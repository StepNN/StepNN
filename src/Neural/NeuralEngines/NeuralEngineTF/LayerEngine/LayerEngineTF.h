#pragma once

#include "src/Neural/Layer/Engine/BaseLayerEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class LayerEngineTF : virtual public BaseLayerEngine
{
public:
	explicit LayerEngineTF();

/// Implementation of ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) const override;
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) const override;
///
};

}