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
