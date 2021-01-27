#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetTorch : virtual public BaseNeuralNet
{
public:
	explicit NeuralNetTorch(const ILayerEngine* layerEngine);
	~NeuralNetTorch();

/// INeuralNet
///

/// INeuralConfigurator
///

private:
	void OnSetNeuralConfiguration();
};

}
