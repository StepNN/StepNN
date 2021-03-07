#pragma once

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API ITrainable
{
public:
	virtual ~ITrainable() = default;

	virtual void Train() = 0;
	virtual void Evaluate() = 0;
};

}