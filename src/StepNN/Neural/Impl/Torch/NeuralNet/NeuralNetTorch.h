#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetTorch : virtual public BaseNeuralNet
{
public:
	explicit NeuralNetTorch(const ILayerEngine* layerEngine);
	~NeuralNetTorch();

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
///

/// ITrainable
	void Train() override;
///

private:
	void OnSetNeuralConfiguration();
};

}
