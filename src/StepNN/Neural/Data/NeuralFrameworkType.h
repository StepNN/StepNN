#pragma once

#include "StepNNLib.h"

namespace StepNN {

enum class STEPNN_API NeuralFrameworkType
{
	Unknown = -1,
	NeoML,
	TF,
	Torch,
};

}