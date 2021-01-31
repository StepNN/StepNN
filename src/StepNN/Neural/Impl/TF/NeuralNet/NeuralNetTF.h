#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetTF : virtual public BaseNeuralNet
{
public:
	explicit NeuralNetTF(const ILayerEngine* layerEngine);
	~NeuralNetTF();

/// INeuralNet
///

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
///

private:
	void OnSetNeuralConfiguration();
};

}
