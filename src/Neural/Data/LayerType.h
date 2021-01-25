#pragma once

namespace StepNN {

enum class LayerType
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