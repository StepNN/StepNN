#pragma once

#include "StepNNLib.h"

namespace StepNN {

enum class STEPNN_API OptimizerType
{
	Undefined,
	Adam,
	Adagrad,
	LBFGS,
	SGD,
};

struct STEPNN_API OptimizerSettings
{
	OptimizerType type;
};

struct AdamData
{

};

}