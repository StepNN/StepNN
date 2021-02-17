#pragma once

#include "StepNNLib.h"

namespace StepNN::Neural {

enum class STEPNN_API PaddingMode
{
	Undefined,
	Zeros,
	Reflect,
	Replicate,
	Circular,
};

}