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
	m_device = m_config.deviceType == DeviceType::GPU && torch::cuda::is_available() ? torch::kCUDA : torch::kCPU;

	//@todo create optimizer
	m_optimizer = nullptr;
}

}