#pragma once

#include <vector>

#include "StepNN/Neural/Layer/Settings/BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Interfaces {

class STEPNN_API ILayerGraph
{
public:
	using Node = BaseLayerSettings;
	using Nodes = std::vector<Node>;
	using Edge = std::pair<Node, Node>;
	using Edges = std::vector<Edge>;

public:
	virtual ~ILayerGraph() = default;

	virtual void AddNode(const BaseLayerSettings&) = 0;
	virtual void AddEdge(const std::string& idFrom, const std::string& idTo) = 0;
	
	virtual Nodes GetNodes() const = 0;
	virtual Edges GetEdges() const = 0;
	
	virtual void SetComplete() = 0;
	virtual bool IsCompleted() const noexcept = 0;
};

}