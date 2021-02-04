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

LayerCPtr BaseLayerEngine::GetLayer(const std::string& id) const
{
	const auto it = std::find_if(m_layers.cbegin(), m_layers.cend(), [&id](const auto& layerPtr) { return layerPtr->GetId() == id; });
	return it != m_layers.cend() ? it->get() : nullptr;
}

//.............................................................................

const LayerUPtrs& BaseLayerEngine::GetLayers() const
{
	return m_layers;
}

//.............................................................................

void BaseLayerEngine::ConnectLayers(const std::string& id, const std::string& prevId)
{
	assert(GetLayer(id) && GetLayer(prevId));

	GetLayer(id)->Connect(GetLayer(prevId));

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
	return m_graph ? m_graph.get() : nullptr;
}

}