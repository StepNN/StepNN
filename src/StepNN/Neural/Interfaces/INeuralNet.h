#pragma once

#include "BaseNeuralConfigurator.h"

#include "StepNNLib.h"

namespace StepNN::Interfaces {

class STEPNN_API INeuralNet : virtual public BaseNeuralConfigurator
{
public:
	virtual ~INeuralNet() = default;
};

}