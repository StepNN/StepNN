#include "NeuralNetTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralNetTorch::NeuralNetTorch(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
{}

//.............................................................................

NeuralNetTorch::~NeuralNetTorch() = default;

}