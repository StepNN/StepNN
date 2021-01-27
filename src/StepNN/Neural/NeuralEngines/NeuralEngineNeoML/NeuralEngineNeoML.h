#pragma once

#include "StepNN/Neural/Interfaces/INeuralNet.h"
#include "StepNN/Neural/Interfaces/INeuralEngine.h"

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
	INeuralConfigurator& GetConfigurator() override;
	const INeuralConfigurator& GetConfigurator() const override;
	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
	std::unique_ptr<INeuralNet> m_net;
};

}