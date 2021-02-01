#pragma once

#include "StepNN/Neural/Interfaces/INeuralEngine.h"
#include "StepNN/Neural/Interfaces/IDatasetController.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralEngineTF
	: public INeuralEngine
	, public IDatasetController
{
public:
	explicit NeuralEngineTF();
	~NeuralEngineTF();

/// Implementation of INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;
	INeuralConfigurator& GetConfigurator() override;
	const INeuralConfigurator& GetConfigurator() const override;
	IDatasetController& GetDatasetController() override { return *this; }
	const IDatasetController& GetDatasetController() const override { return *this; }
	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
	std::unique_ptr<INeuralConfigurator> m_configurator;
};

}