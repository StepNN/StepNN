#include "NeuralNetTF.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralNetTF::NeuralNetTF(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
{}

//.............................................................................

NeuralNetTF::~NeuralNetTF() = default;

}