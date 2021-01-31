#pragma once

#include "IDatasetUser.h"
#include "BaseNeuralConfigurator.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API INeuralNet
	: virtual public IDatasetUser
	, virtual public BaseNeuralConfigurator
{
public:
	virtual ~INeuralNet() = default;

	virtual void Configure() = 0;

	virtual void ProcessTrain() = 0;
};

}