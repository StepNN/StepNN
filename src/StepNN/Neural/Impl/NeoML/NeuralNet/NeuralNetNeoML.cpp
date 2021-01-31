#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "NeuralNetNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralNetNeoML::NeuralNetNeoML(const ILayerEngine* layerEngine)
	: BaseNeuralNet(layerEngine)
	, m_gpuManager(nullptr)
	, m_mathEngine(nullptr)
{}

//.............................................................................

NeuralNetNeoML::~NeuralNetNeoML() = default;

//.............................................................................

}