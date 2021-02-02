#include <cassert>
#include <utility>

#include "BaseNeuralConfigurator.h"

namespace StepNN::Neural {

void BaseNeuralConfigurator::SetNeuralConfiguration(const NeuralConfiguration& config)
{
	assert(!config.IsInvalid());
	m_config = config;
}

//.............................................................................

void BaseNeuralConfigurator::SetNeuralConfiguration(NeuralConfiguration&& config)
{
	assert(!config.IsInvalid());
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

StepNN::Neural::DeviceType BaseNeuralConfigurator::GetDeviceType() const noexcept
{
	return m_config.deviceType;
}

//.............................................................................

}