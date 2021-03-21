#include <iterator>

#include "StepNN/Utils/Containers/Graph.h"

#include "LayerGraph.h"

namespace StepNN::Neural {

class LayerGraph::Impl : public Graph<BaseLayerSettings, std::string> {};

//.............................................................................

LayerGraph::LayerGraph()
	: m_impl(std::make_unique<Impl>())
{}

//.............................................................................

LayerGraph::~LayerGraph() = default;

//.............................................................................

void LayerGraph::AddNode(const BaseLayerSettings& settings)
{
	m_impl->AddNode(settings, settings.GetLayerId());
}

//.............................................................................

void LayerGraph::AddEdge(const std::string& idFrom, const std::string& idTo)
{
	m_impl->AddEdge(idFrom, idTo);
}

//.............................................................................

LayerGraph::Nodes LayerGraph::GetNodes() const
{
	const auto& implNodes = m_impl->GetNodes();
	Nodes nodes;
	nodes.reserve(implNodes.size());

	std::transform(implNodes.begin(), implNodes.end(), std::back_inserter(nodes), [](const auto& implNode) { return implNode.GetData(); });
	return nodes;
}

//.............................................................................

LayerGraph::Edges LayerGraph::GetEdges() const
{
	const auto& implEdges = m_impl->GetEdges();
	Edges edges;
	edges.reserve(implEdges.size());

	std::transform(implEdges.cbegin(), implEdges.cend(), std::back_inserter(edges), [this](const auto& implEdge)
	{
		const auto& [nodeIdFrom, nodeIdTo] = implEdge.GetEdge();
		const auto& nodeFrom = m_impl->GetNode(nodeIdFrom);
		const auto& nodeTo = m_impl->GetNode(nodeIdTo);
		return Edge({ nodeFrom.GetData(), nodeTo.GetData()});
	});

	return edges;
}

//.............................................................................

LayerGraph::Edges LayerGraph::GetSortedEdges(bool ascending) const
{
	auto implEdges = m_impl->GetSortedEdgesByHierarchicalLevel(ascending);
	Edges edges;
	edges.reserve(implEdges.size());

	std::transform(implEdges.cbegin(), implEdges.cend(), std::back_inserter(edges), [this](const auto& implEdge)
	{
		const auto& [nodeIdFrom, nodeIdTo] = implEdge.GetEdge();
		const auto& nodeFrom = m_impl->GetNode(nodeIdFrom);
		const auto& nodeTo = m_impl->GetNode(nodeIdTo);
		return Edge({ nodeFrom.GetData(), nodeTo.GetData() });
	});

	return edges;
}

//.............................................................................

void LayerGraph::SetComplete()
{
	m_impl->SetComplete();
}

//.............................................................................

bool LayerGraph::IsCompleted() const noexcept
{
	return m_impl->IsCompleted();
}

}