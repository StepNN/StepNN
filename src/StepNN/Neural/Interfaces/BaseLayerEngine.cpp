#include "StepNN/Neural/Layer/LayerGraph.h"

#include "BaseLayerEngine.h"

namespace StepNN::Neural {

BaseLayerEngine::BaseLayerEngine()
	: m_graph(nullptr)
{
}

//.............................................................................

bool BaseLayerEngine::AddLayer(const BaseLayerSettings& settings)
{
	if (!m_graph)
		m_graph = std::make_unique<LayerGraph>();

	m_graph->AddNode(settings);
	m_layers.emplace_back(CreateLayer(settings));

	return true;
}

//.............................................................................

std::shared_ptr<ILayer> BaseLayerEngine::GetLayer(const std::string& id) const
{
	const auto it = std::find_if(m_layers.cbegin(), m_layers.cend(), [&id](const auto& layerPtr) { return layerPtr->GetId() == id; });
	return it != m_layers.cend() ? *it : nullptr;
}

//.............................................................................

const std::vector<std::shared_ptr<ILayer>>& BaseLayerEngine::GetLayers() const
{
	return m_layers;
}

//.............................................................................

void BaseLayerEngine::AddLossLayer(const BaseLayerSettings& settings)
{
	m_lossLayer = CreateLayer(settings);
}

//.............................................................................

std::shared_ptr<ILayer> BaseLayerEngine::GetLossLayer() const
{
	assert(m_lossLayer);
	return m_lossLayer ? m_lossLayer : nullptr;
}

//.............................................................................

void BaseLayerEngine::ConnectLayers(const std::string& id, const std::string& prevId)
{
	assert(GetLayer(id) && GetLayer(prevId));

	GetLayer(id)->Connect(GetLayer(prevId).get());

	m_graph->AddEdge(id, prevId);
}

//.............................................................................

void BaseLayerEngine::SequentialConnection(const std::vector<std::string>& ids)
{
	for (size_t i = 0; i < ids.size() - 1; ++i)
		ConnectLayers(ids[i+1], ids[i]);
}

//.............................................................................

const ILayerGraph* BaseLayerEngine::GetLayerGraph() const noexcept
{
	assert(m_graph);
	return m_graph ? m_graph.get() : nullptr;
}

}