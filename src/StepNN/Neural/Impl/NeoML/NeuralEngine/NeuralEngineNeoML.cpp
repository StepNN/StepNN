#include <cassert>

#include "NeoMathEngine/MemoryHandle.h"

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Impl/NeoML/LayerEngine/LayerEngineNeoML.h"
#include "StepNN/Neural/Impl/NeoML/NeuralNet/NeuralNetNeoML.h"

#include "NeuralEngineNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace {

constexpr size_t GIGABYTE = 1024 * 1024 * 1024;

}

namespace StepNN::Neural {

NeuralEngineNeoML::NeuralEngineNeoML()
	: m_layerEngine(std::make_unique<LayerEngineNeoML>())
	, m_net(std::make_unique<NeuralNetNeoML>(m_layerEngine.get()))
{
	IUserController<IDatasetUser>::AddUser(m_net.get());

	auto netImplPtr = dynamic_cast<NeuralNetNeoML*>(m_net.get());
	netImplPtr->RegisterEventHandler(this);

	IUserController<IUserNeoML>::AddUser(netImplPtr);
	IUserController<IUserNeoML>::AddUser(dynamic_cast<LayerEngineNeoML*>(m_layerEngine.get()));
}

//.............................................................................

NeuralEngineNeoML::~NeuralEngineNeoML() = default;

//.............................................................................

ILayerEngine& NeuralEngineNeoML::GetLayerEngine()
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

const ILayerEngine& NeuralEngineNeoML::GetLayerEngine() const
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

INeuralConfigurator& NeuralEngineNeoML::GetConfigurator()
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

const INeuralConfigurator& NeuralEngineNeoML::GetConfigurator() const
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

ITrainable& NeuralEngineNeoML::GetTrainable()
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

bool NeuralEngineNeoML::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

//.............................................................................

void NeuralEngineNeoML::OnSetNeuralConfiguration(const NeuralConfiguration& config)
{
	assert(config.deviceType != DeviceType::Undefined);

	NeoML::SetMathEngineExceptionHandler(NeoML::GetExceptionHandler());

	std::shared_ptr<NeoML::IGpuMathEngineManager> gpuManager;
	std::shared_ptr<NeoML::IMathEngine> mathEngine;

	if (config.deviceType == DeviceType::CPU)
	{
		gpuManager = nullptr;
		mathEngine.reset(NeoML::CreateCpuMathEngine(0, static_cast<size_t>(config.memoryLimit * GIGABYTE)));
	}
	else
	{
		gpuManager.reset(NeoML::CreateGpuMathEngineManager());
		mathEngine.reset(m_gpuManager->CreateMathEngine(0, static_cast<size_t>(config.memoryLimit * GIGABYTE)));
	}
	SetGpuManager(gpuManager);
	SetMathEngine(mathEngine);
}

}