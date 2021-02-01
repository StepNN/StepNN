#pragma once

#include "StepNN/Neural/Data/NeuralConfiguration/NeuralConfiguration.h"

namespace StepNN::Neural {

class IEventHandlerNeoML
{
public:
	virtual ~IEventHandlerNeoML() = default;

	virtual void OnSetNeuralConfiguration(const NeuralConfiguration&) {}
};

}