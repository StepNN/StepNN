#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

using namespace StepNN::Interfaces;

namespace StepNN {

class NeuralNetTF : virtual public BaseNeuralNet
{
public:
	explicit NeuralNetTF(const ILayerEngine* layerEngine);
	~NeuralNetTF();

/// INeuralNet
///

/// INeuralConfigurator
///

private:
	void OnSetNeuralConfiguration();
};

}
