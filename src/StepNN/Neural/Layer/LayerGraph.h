#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/ILayerGraph.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class LayerGraph : public ILayerGraph
{
public:
	LayerGraph();
	~LayerGraph();

/// ILayerGraph
	void AddNode(const BaseLayerSettings&) override;
	void AddEdge(const std::string& idFrom, const std::string& idTo) override;

	Nodes GetNodes() const override;
	Edges GetEdges() const override;

	void SetComplete() override;
	bool IsCompleted() const noexcept override;
///

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}
