#include <utility>

#include "BaseNeuralConfigurator.h"

namespace StepNN {

void BaseNeuralConfigurator::SetNeuralConfiguration(const NeuralConfiguration& config)
{
	m_config = config;
}

//.............................................................................

void BaseNeuralConfigurator::SetNeuralConfiguration(NeuralConfiguration&& config)
{
	m_config = std::move(config);
}

//.............................................................................

const NeuralConfiguration& BaseNeuralConfigurator::GetNeuralConfiguration() const noexcept
{
	return m_config;
}

//.............................................................................

void BaseNeuralConfigurator::SetDeviceType(DeviceType type)
{
	m_config.deviceType = type;
}

//.............................................................................

StepNN::DeviceType BaseNeuralConfigurator::GetDeviceType() const noexcept
{
	return m_config.deviceType;
}

//.............................................................................

}