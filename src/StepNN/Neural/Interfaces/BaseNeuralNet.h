#pragma once

#include "ILayerEngine.h"
#include "INeuralNet.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseNeuralNet : public INeuralNet
{
protected:
	explicit BaseNeuralNet(const ILayerEngine* layerEnginePtr);

protected:
	const ILayerEngine* m_layerEnginePtr;
};

}