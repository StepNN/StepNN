#pragma once

#include "ILayer.h"

#include "StepNNLib.h"

using namespace StepNN;

namespace StepNN::Neural::Interfaces {

class STEPNN_API ILayerFactory
{
public:
	virtual ~ILayerFactory() = default;

	virtual LayerUPtr CreateLayer(const std::string& layerID) = 0;
	virtual LayerUPtr CreateLayer(const BaseLayerSettings& settings) = 0;
};

}