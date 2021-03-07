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
	std::shared_ptr<ILayer> CreateLayer(const std::string& layerID) override;
	std::shared_ptr<ILayer> CreateLayer(const BaseLayerSettings& settings) override;
///
};

}