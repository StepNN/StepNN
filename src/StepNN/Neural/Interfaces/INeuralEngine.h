#pragma once

#include "ILayerEngine.h"

#include "StepNN/Neural/Data/NeuralFrameworkType.h"

#include "StepNNLib.h"

namespace StepNN::Interfaces {

class STEPNN_API INeuralEngine
{
public:
	virtual ~INeuralEngine() = default;

	virtual ILayerEngine& GetLayerEngine() = 0;
	virtual const ILayerEngine& GetLayerEngine() const = 0;

	virtual bool SwitchImpl(NeuralFrameworkType type) = 0;
};

}