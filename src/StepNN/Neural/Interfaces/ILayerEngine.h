#pragma once

#include "ILayerFactory.h"
#include "ILayerGraph.h"

#include "StepNNLib.h"

namespace StepNN::Interfaces {

class STEPNN_API ILayerEngine
	: virtual public ILayerFactory
{
public:
	virtual ~ILayerEngine() = default;

	virtual bool AddLayer(const BaseLayerSettings& settings) = 0;
	virtual LayerCPtr GetLayer(const std::string& id) const = 0;
	virtual const StepNN::LayerUPtrs& GetLayers() const = 0;

	virtual void ConnectLayers(const std::string& fromId, const std::string& toId) = 0;

	virtual const ILayerGraph* GetLayerGraph() const noexcept = 0;
};

}