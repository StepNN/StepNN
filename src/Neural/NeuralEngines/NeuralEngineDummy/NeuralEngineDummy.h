#pragma once

#include "src/Neural/Interfaces/INeuralEngine.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralEngineDummy : public INeuralEngine
{
public:
	explicit NeuralEngineDummy();

/// Implementation of INeuralEngine
	ILayerEngine& GetLayerEngine() override;
	const ILayerEngine& GetLayerEngine() const override;
	bool SwitchImpl(NeuralFrameworkType type) override;
///

};

}