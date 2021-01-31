#pragma once

#include "StepNNLib.h"

namespace StepNN::Neural {

enum class STEPNN_API LayerType
{
	// Activations
	ReLU,
	Softmax,
	CrossEntropy,

	// Convolutions
	Conv,

	// Poolings
	MaxPool,

	BatchNorm,
	Flatten,
	Dense,

	// Sources layers (NeoML)
	Source,
	Output,
};

}
