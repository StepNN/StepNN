#include "NeuralNetTF.h"

namespace StepNN {

void NeuralNetTF::SetNeuralConfiguration(const NeuralConfiguration& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(config);
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetTF::SetNeuralConfiguration(NeuralConfiguration&& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(std::move(config));
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetTF::OnSetNeuralConfiguration()
{
}

}