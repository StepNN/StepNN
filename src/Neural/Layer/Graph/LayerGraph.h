#pragma once

#include <memory>

#include "src/Neural/Interfaces/ILayerGraph.h"

using namespace StepNN::Interfaces;

namespace StepNN {

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
	bool IsCompleted() const noexcept;
///

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}