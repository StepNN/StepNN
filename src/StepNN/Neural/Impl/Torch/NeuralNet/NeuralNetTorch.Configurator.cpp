#include "NeuralNetTorch.h"

namespace StepNN::Neural {

void NeuralNetTorch::SetNeuralConfiguration(const NeuralConfiguration& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(config);
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetTorch::SetNeuralConfiguration(NeuralConfiguration&& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(std::move(config));
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetTorch::OnSetNeuralConfiguration()
{
}

}