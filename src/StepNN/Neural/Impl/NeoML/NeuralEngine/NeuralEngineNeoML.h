#pragma once

#include "StepNN/Neural/Interfaces/INeuralEngine.h"
#include "StepNN/Neural/Interfaces/INeuralNet.h"
#include "StepNN/Neural/Interfaces/BaseDatasetController.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralEngineNeoML
	: public INeuralEngine
	, virtual public BaseDatasetController
{
public:
	explicit NeuralEngineNeoML();
	~NeuralEngineNeoML();

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
	std::unique_ptr<INeuralNet> m_net;
};

}