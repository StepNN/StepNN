#pragma once

#include "ILayerFactory.h"
#include "ILayerGraph.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API ILayerEngine
	: virtual public ILayerFactory
{
public:
	virtual ~ILayerEngine() = default;

	virtual bool AddLayer(const BaseLayerSettings& settings) = 0;
	virtual LayerCPtr GetLayer(const std::string& id) const = 0;
	virtual const StepNN::Neural::LayerUPtrs& GetLayers() const = 0;

	//virtual void AddLossLayer(const BaseLayerSettings& settings) = 0;

	virtual void ConnectLayers(const std::string& id, const std::string& prevId) = 0;

	virtual void SequentialConnection(const std::vector<std::string>& ids) = 0;

	virtual const ILayerGraph* GetLayerGraph() const noexcept = 0;
};

}