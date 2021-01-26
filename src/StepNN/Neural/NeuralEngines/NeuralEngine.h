#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/INeuralEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralEngine : public INeuralEngine
{
public:
	explicit NeuralEngine(NeuralFrameworkType type = NeuralFrameworkType::Unknown);
	~NeuralEngine();

/// INeuralEngine
	ILayerEngine& GetLayerEngine() = 0;
	const ILayerEngine& GetLayerEngine() const = 0;

	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	void CreateImpl(NeuralFrameworkType type);

private:
	std::unique_ptr<INeuralEngine> m_impl;
};

}