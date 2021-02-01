#pragma once

#include "StepNN/Neural/Interfaces/BaseLayerEngine.h"

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"
#include "StepNN/Neural/Impl/NeoML/Interfaces/IUserNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class LayerEngineNeoML
	: public BaseLayerEngine
	, public IUserNeoML
{
public:
	explicit LayerEngineNeoML();

/// Implementation of ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) const override;
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) const override;
///
};

}