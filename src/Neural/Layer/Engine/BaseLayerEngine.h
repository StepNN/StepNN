#pragma once

#include <cassert>
#include <memory>

#include "src/Types/CommonDefs.h"

#include "src/Neural/Interfaces/ILayerEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class BaseLayerEngine : public ILayerEngine
{
protected:
	BaseLayerEngine();

/// ILayerEngine
	bool AddLayer(const BaseLayerSettings& settings) override;
	LayerCPtr GetLayer(const std::string& id) const override;
	const StepNN::LayerUPtrs& GetLayers() const override;
	void ConnectLayers(const std::string& fromId, const std::string& toId) override;
	const ILayerGraph* GetLayerGraph() const noexcept override;
///

/// ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) const override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) const override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
///

protected:
	std::unique_ptr<ILayerGraph> m_graph;
	LayerUPtrs m_layers;
};

}