#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "BaseNeuralNet.h"

namespace StepNN::Neural {

BaseNeuralNet::BaseNeuralNet(const ILayerEngine* layerEnginePtr)
	: m_layerEnginePtr(layerEnginePtr)
{}

//.............................................................................

}