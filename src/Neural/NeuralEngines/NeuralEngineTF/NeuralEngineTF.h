#pragma once

#include "src/Neural/Interfaces/INeuralEngine.h"

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
	bool SwitchImpl(NeuralFrameworkType type) override;
///

private:
	std::unique_ptr<ILayerEngine> m_layerEngine;
};

}