#include "StepNN/Neural/NeuralEngines/NeuralEngineNeoML/CommonNeoML.h"

#include "NeuralNetNeoML.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralNetNeoML::NeuralNetNeoML(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
	, m_gpuManager(nullptr)
	, m_mathEngine(nullptr)
{}

//.............................................................................

NeuralNetNeoML::~NeuralNetNeoML() = default;

}