#pragma once

#include "ILayerEngine.h"

#include "src/Neural/Data/NeuralFrameworkType.h"

namespace StepNN::Interfaces {

class INeuralEngine
{
public:
	virtual ~INeuralEngine() = default;

	virtual ILayerEngine& GetLayerEngine() = 0;
	virtual const ILayerEngine& GetLayerEngine() const = 0;

	virtual bool SwitchImpl(NeuralFrameworkType type) = 0;
};

}