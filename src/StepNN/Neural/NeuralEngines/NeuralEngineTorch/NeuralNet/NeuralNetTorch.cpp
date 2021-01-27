#include "NeuralNetTorch.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralNetTorch::NeuralNetTorch(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
{}

//.............................................................................

NeuralNetTorch::~NeuralNetTorch() = default;

}