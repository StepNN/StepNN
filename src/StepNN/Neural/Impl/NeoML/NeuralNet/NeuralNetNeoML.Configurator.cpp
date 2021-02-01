#include <cassert>

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "NeuralNetNeoML.h"

namespace StepNN::Neural {

void NeuralNetNeoML::SetNeuralConfiguration(const NeuralConfiguration& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(config);
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetNeoML::SetNeuralConfiguration(NeuralConfiguration&& config)
{
	BaseNeuralConfigurator::SetNeuralConfiguration(std::move(config));

	PerformForEachEventHandler(std::bind(&IEventHandlerNeoML::OnSetNeuralConfiguration, std::placeholders::_1, std::cref(m_config)));

	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetNeoML::SetDeviceType(DeviceType type)
{
	BaseNeuralConfigurator::SetDeviceType(type);
}

//.............................................................................

void NeuralNetNeoML::OnSetNeuralConfiguration()
{
}

}