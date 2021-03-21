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
	std::shared_ptr<ILayer> GetLayer(const std::string& id) const override;
	const std::vector<std::shared_ptr<ILayer>>& GetLayers() const override;
	void AddLossLayer(const BaseLayerSettings& settings) override;
	std::shared_ptr<ILayer> GetLossLayer() const override;
	void ConnectLayers(const std::string& id, const std::string& prevId) override;
	void SequentialConnection(const std::vector<std::string>& ids) override;
	const ILayerGraph* GetLayerGraph() const noexcept override;

	void Connect() override;
///

protected:
	BaseLayerEngine();

/// ILayerFactory
	std::shared_ptr<ILayer> CreateLayer(const std::string& layerID) override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
	std::shared_ptr<ILayer> CreateLayer(const BaseLayerSettings& settings) override { assert(!(Defs::NOT_IMPL_STR)); return nullptr; };
///

protected:
	std::unique_ptr<ILayerGraph> m_graph;
	std::vector<std::shared_ptr<ILayer>> m_layers;
	std::shared_ptr<ILayer> m_lossLayer;
};

}