#pragma once

#include "StepNNLib.h"

namespace StepNN {

enum class STEPNN_API NeuralFrameworkType
{
	Unknown = -1,
#ifdef STEPNN_USE_NEOML
	NeoML = 1,
#endif
#ifdef STEPNN_USE_TF
	TF = 2,
#endif
#ifdef STEPNN_USE_TORCH
	Torch = 3,
#endif
};

}