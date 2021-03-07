#pragma once

#include "StepNN/Neural/Interfaces/BaseLayerEngine.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class LayerEngineTF : virtual public BaseLayerEngine
{
public:
	explicit LayerEngineTF();

/// Implementation of ILayerFactory
	std::shared_ptr<ILayer> CreateLayer(const std::string& layerID) override;
	std::shared_ptr<ILayer> CreateLayer(const BaseLayerSettings& settings) override;
///
};

}