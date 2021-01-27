#pragma once

#include "StepNN/Neural/Interfaces/INeuralEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralEngineTF : public INeuralEngine
{
public:
	explicit NeuralEngineTF();
	~NeuralEngineTF();

/// Implementation of INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;
	INeuralConfigurator& GetConfigurator() override;
	const INeuralConfigurator& GetConfigurator() const override;
	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
	std::unique_ptr<INeuralConfigurator> m_configurator;
};

}