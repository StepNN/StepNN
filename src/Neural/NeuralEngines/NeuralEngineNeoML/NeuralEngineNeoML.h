#pragma once

#include "src/Neural/Interfaces/INeuralEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralEngineNeoML : public INeuralEngine
{
public:
	explicit NeuralEngineNeoML();
	~NeuralEngineNeoML();

/// Implementation of INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;
	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
};

}