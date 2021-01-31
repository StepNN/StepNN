#pragma once

#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "ILayerEngine.h"
#include "INeuralNet.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseNeuralNet : public INeuralNet
{
protected:
	explicit BaseNeuralNet(const ILayerEngine* layerEnginePtr);

	void Configure() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	void ProcessTrain() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };

protected:
	const ILayerEngine* m_layerEnginePtr;
};

}