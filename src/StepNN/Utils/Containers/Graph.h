#pragma once

#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include "StepNN/Types/CommonDefs.h"

namespace StepNN::Neural {

template<typename DataType, typename IdType>
class GraphNode
{
public:
	GraphNode() = default;
	explicit GraphNode(const DataType& data, const IdType& id) : m_data(data), m_id(id) {}

	void SetData(const DataType& data) { m_data = data; }
	void SetId(const IdType& id) { m_id = id; }

	const DataType& GetData() const { return m_data; }
	const IdType& GetId() const { return m_id; }

protected:
	DataType m_data;
	IdType m_id;
};

//.............................................................................

using NodePair = std::pair<int, int>;

struct GraphEdge
{
public:
	GraphEdge() = default;
	explicit GraphEdge(const NodePair& edge) : m_edge(edge) {}

	bool operator==(const GraphEdge& rhs) const noexcept { return m_edge == rhs.m_edge; }
	bool operator!=(const GraphEdge& rhs) const noexcept { return !(*this == rhs); }

	void SetEdge(const NodePair& edge) { m_edge = edge; }
	void SetHierarchicalLevel(int value) { m_hierarchicalLevel = value; }

	const NodePair& GetEdge() const noexcept { return m_edge; }
	int GetHierarchicalLevel() const noexcept { return m_hierarchicalLevel; }

	bool IsValid() const noexcept { return Defs::IsValid(m_hierarchicalLevel) && Defs::IsValid(m_edge.first) && Defs::IsValid(m_edge.second); }

private:
	NodePair m_edge { Defs::INVALID_VALUE_INT , Defs::INVALID_VALUE_INT };
	int m_hierarchicalLevel { Defs::INVALID_VALUE_INT };
};

//.............................................................................

template<typename DataType, typename IdType>
class Graph
{
public:
	using Node = GraphNode<DataType, IdType>;
	using Nodes = std::vector<Node>;
	using Edges = std::vector<GraphEdge>;

public:
	const Nodes& GetNodes() const noexcept { return m_nodes; }
	const Edges& GetEdges() const noexcept { return m_edges; }

	const Node& GetNode(int index) const;
	const Node& GetNode(const IdType& id) const;

	void AddNode(const DataType& data, const IdType& id) { m_nodes.push_back(Node(data, id)); m_isComplete = false; }
	void AddEdge(const IdType& idFrom, const IdType& idTo);

	void SetComplete(); // must be processed after adding all nodes
	bool IsCompleted() const noexcept { return m_isComplete; }

private:
	void CalculateHierarchicalLevels();

	int GetNodeIndexById(const IdType& id) const;
	int GetEdgeIndexByNodes(const NodePair& edge) const;

private:
	Nodes m_nodes;
	Edges m_edges;
	std::map<int, std::set<int>> m_nodesAdjMatrix; // nodes adjacency matrix
	bool m_isComplete { false };
};

//.............................................................................

template<typename DataType, typename IdType>
inline const GraphNode<DataType, IdType>& Graph<DataType, IdType>::GetNode(int index) const
{
	assert(Defs::IsValid(index) && index < m_nodes.size());
	return m_nodes[index];
}

template<typename DataType, typename IdType>
inline const GraphNode<DataType, IdType>& Graph<DataType, IdType>::GetNode(const IdType& id) const
{
	const auto it = std::find_if(m_nodes.cbegin(), m_nodes.cend(), [&id](const auto & item) { return item.GetId() == id; });
	assert(it != m_nodes.cend());
	return *it;
}

template<typename DataType, typename IdType>
inline void Graph<DataType, IdType>::AddEdge(const IdType& idFrom, const IdType& idTo)
{
	const auto nodeFrom = GetNodeIndexById(idFrom);
	const auto nodeTo = GetNodeIndexById(idTo);
	assert(Defs::IsValid(nodeFrom) && Defs::IsValid(nodeTo));

	m_edges.emplace_back(GraphEdge({ nodeFrom, nodeTo }));
	m_nodesAdjMatrix[nodeFrom].insert(nodeTo);

	m_isComplete = false;
}

template<typename DataType, typename IdType>
inline void Graph<DataType, IdType>::CalculateHierarchicalLevels()
{
	// Find empty node adjacency list - it is a list of the last node
	int lastNode;
	{
		const auto lastNodeIter = std::find_if(m_nodesAdjMatrix.cbegin(), m_nodesAdjMatrix.cend(), [](const auto& mapItem) { return mapItem.second.empty(); });
		//assert if there are many empty lists (must be one)
		assert(std::find_if(lastNodeIter, m_nodesAdjMatrix.cend(), [](const auto& mapItem) { return mapItem.second.empty(); }) == m_nodesAdjMatrix.cend());
		assert(lastNodeIter != m_nodesAdjMatrix.cend());
		lastNode = (*lastNodeIter).first;
	}

	const auto findParentNodes = [&adjMatrix = m_nodesAdjMatrix](int nodeIndex)
	{
		std::set<int> parentNodes;
		for (const auto& [index, list] : adjMatrix)
			if (std::any_of(list.cbegin(), list.cend(), [&nodeIndex](const auto& item) { return nodeIndex == item; }))
				parentNodes.insert(index);

		return parentNodes;
	};

	std::vector<int> usedIndiciesFlags(m_nodes.size(), 0); //@ todo - Use dynamic bitset
	std::set<int> processIndicies{ lastNode };
	int hLevel = 1;
	while (!processIndicies.empty())
	{
		std::set<int> newProcessIndicies;
		for (const auto& nodeIndex : processIndicies)
		{
			// Get parent nodes for processing node. There are edges (parentNode1, nodeIndex), (parentNode2, nodeIndex)...
			const auto parentNodes = findParentNodes(nodeIndex);
			newProcessIndicies.insert(parentNodes.begin(), parentNodes.end());
			for (const auto& parentNode : parentNodes)
			{
				// Find edge (parentNode, nodeIndex) and set current hLevel
				const auto edgeIndex = GetEdgeIndexByNodes({ parentNode, nodeIndex });
				assert(Defs::IsValid(edgeIndex));
				m_edges[edgeIndex].SetHierarchicalLevel(hLevel);

				// For every parent node:
				// Check if this parent node met before
				// If yes - we need to add it's children (which was processing before) to processIndicies to recalculate hLevels for that edges
				if (usedIndiciesFlags[parentNode] == 1)
				{
					assert(m_nodesAdjMatrix.find(parentNode) != m_nodesAdjMatrix.end());
					const auto parentAdjList = m_nodesAdjMatrix[parentNode];
					for (const auto& child : parentAdjList)
					{
						if (usedIndiciesFlags[child])
							processIndicies.insert(child);
					}
				}
			}
			usedIndiciesFlags[nodeIndex] = 1;
		}

		std::swap(processIndicies, newProcessIndicies);
		++hLevel;
	}
}

template<typename DataType, typename IdType>
inline int Graph<DataType, IdType>::GetNodeIndexById(const IdType& id) const
{
	const auto it = std::find_if(m_nodes.cbegin(), m_nodes.cend(), [&id](const auto& item) { return item.GetId() == id; });
	return it != m_nodes.cend() ? static_cast<int>(std::distance(m_nodes.cbegin(), it)) : Defs::INVALID_VALUE_INT;
}

template<typename DataType, typename IdType>
inline int Graph<DataType, IdType>::GetEdgeIndexByNodes(const NodePair& edge) const
{
	const auto it = std::find_if(m_edges.cbegin(), m_edges.cend(), [&edge](const auto& item) { return item.GetEdge() == edge; });
	return it != m_edges.cend() ? static_cast<int>(std::distance(m_edges.cbegin(), it)) : Defs::INVALID_VALUE_INT;
}

template<typename DataType, typename IdType>
inline void Graph<DataType, IdType>::SetComplete()
{
	// @todo some actions to check correct graph state
	CalculateHierarchicalLevels();
	std::sort(m_edges.begin(), m_edges.end(), [](const auto& edge0, const auto& edge1) { return edge1.GetHierarchicalLevel() < edge0.GetHierarchicalLevel(); });
	m_nodes.shrink_to_fit();
	m_edges.shrink_to_fit();
	m_isComplete = true;
}

}