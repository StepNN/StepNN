#pragma once

#include <cassert>
#include <memory>

#include "StepNN/Types/CommonDefs.h"

#include "ILayerEngine.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseLayerEngine : public ILayerEngine
{
public:
/// ILayerEngine
	bool AddLayer(const BaseLayerSettings& settings) override;
	LayerCPtr GetLayer(const std::string& id) const override;
	const LayerUPtrs& GetLayers() const override;
	void ConnectLayers(const std::string& id, const std::string& prevId) override;
	void SequentialConnection(const std::vector<std::string>& ids) override;
	const ILayerGraph* GetLayerGraph() const noexcept override;
///

protected:
	BaseLayerEngine();

/// ILayerFactory
	LayerUPtr CreateLayer(const std::string& layerID) const override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
	LayerUPtr CreateLayer(const BaseLayerSettings& settings) const override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
///

protected:
	std::unique_ptr<ILayerGraph> m_graph;
	LayerUPtrs m_layers;
};

}