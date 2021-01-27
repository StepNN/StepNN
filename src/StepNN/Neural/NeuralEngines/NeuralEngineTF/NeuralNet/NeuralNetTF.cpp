#include "NeuralNetTF.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralNetTF::NeuralNetTF(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
{}

//.............................................................................

NeuralNetTF::~NeuralNetTF() = default;

}