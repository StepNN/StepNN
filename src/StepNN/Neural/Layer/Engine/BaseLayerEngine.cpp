#include "StepNN/Neural/Layer/Graph/LayerGraph.h"

#include "BaseLayerEngine.h"

namespace StepNN {

BaseLayerEngine::BaseLayerEngine()
	: m_graph(nullptr)
{
}

//.............................................................................

///
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

void BaseLayerEngine::ConnectLayers(const std::string& fromId, const std::string& toId)
{
	// @todo check layers in m_layers

	// @todo connect layers

	m_graph->AddEdge(fromId, toId);
}

//.............................................................................

const ILayerGraph* BaseLayerEngine::GetLayerGraph() const noexcept
{
	return m_graph ? m_graph.get() : nullptr;
}

}