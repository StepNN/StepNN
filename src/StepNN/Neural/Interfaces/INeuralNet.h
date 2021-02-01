#pragma once

#include "IDatasetUser.h"
#include "ITrainable.h"
#include "BaseNeuralConfigurator.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API INeuralNet
	: virtual public IDatasetUser
	, virtual public ITrainable
	, virtual public BaseNeuralConfigurator
{
public:
	virtual ~INeuralNet() = default;
};

}