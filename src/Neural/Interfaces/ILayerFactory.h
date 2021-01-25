#pragma once

#include "ILayer.h"

using namespace StepNN;

namespace StepNN::Interfaces {

class ILayerFactory
{
public:
	virtual ~ILayerFactory() = default;

	virtual LayerUPtr CreateLayer(const std::string& layerID) const = 0;
	virtual LayerUPtr CreateLayer(const BaseLayerSettings& settings) const = 0;
};

}