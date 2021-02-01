#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/INeuralEngine.h"

#include "StepNNLib.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class STEPNN_API NeuralEngine : public INeuralEngine
{
public:
	explicit NeuralEngine(NeuralFrameworkType type = NeuralFrameworkType::Unknown);
	~NeuralEngine();

/// INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;

	INeuralConfigurator& GetConfigurator() override;
	const INeuralConfigurator& GetConfigurator() const override;

	IDatasetController& GetDatasetController() override;
	const IDatasetController& GetDatasetController() const override;

	ITrainable& GetTrainable() override;

	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	void CreateImpl(NeuralFrameworkType type);

private:
	std::unique_ptr<INeuralEngine> m_impl;
};

}