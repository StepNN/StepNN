#include <cassert>

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "NeuralNetNeoML.h"

namespace {

constexpr size_t GIGABYTE = 1024 * 1024 * 1024;

}

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
	OnSetNeuralConfiguration();
}

//.............................................................................

void NeuralNetNeoML::SetDeviceType(DeviceType type)
{
	BaseNeuralConfigurator::SetDeviceType(type);

	assert(type != DeviceType::Unknown);
	if(type == DeviceType::CPU)
	{
		m_gpuManager.reset();
		m_mathEngine.reset(&NeoML::GetMultiThreadCpuMathEngine());
	}
	else
	{
		m_gpuManager.reset(NeoML::CreateGpuMathEngineManager());
		m_mathEngine.reset(m_gpuManager->CreateMathEngine(0, 0));
	}
}

//.............................................................................

void NeuralNetNeoML::OnSetNeuralConfiguration()
{
	assert(m_config.deviceType != DeviceType::Unknown);
	if (m_config.deviceType == DeviceType::CPU)
	{
		m_gpuManager.reset();
		m_mathEngine.reset(&NeoML::GetMultiThreadCpuMathEngine());
	}
	else
	{
		m_gpuManager.reset(NeoML::CreateGpuMathEngineManager());
		m_mathEngine.reset(m_gpuManager->CreateMathEngine(0, m_config.memoryLimit * GIGABYTE));
	}
}

}