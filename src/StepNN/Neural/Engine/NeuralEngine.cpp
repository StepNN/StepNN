#include <cassert>

#include "StepNN/Neural/Impl/Dummy/NeuralEngine/NeuralEngineDummy.h"
#include "StepNN/Neural/Impl/NeoML/NeuralEngine/NeuralEngineNeoML.h"
#include "StepNN/Neural/Impl/TF/NeuralEngine/NeuralEngineTF.h"
#include "StepNN/Neural/Impl/Torch/NeuralEngine/NeuralEngineTorch.h"

#include "NeuralEngine.h"

namespace StepNN::Neural {

NeuralEngine::NeuralEngine(NeuralFrameworkType type/* = NeuralFrameworkType::Unknown*/)
{
	CreateImpl(type);
}

//.............................................................................

NeuralEngine::~NeuralEngine() = default;

//.............................................................................

ILayerEngine& NeuralEngine::GetLayerEngine()
{
	assert(m_impl);
	return m_impl->GetLayerEngine();
}

//.............................................................................

const ILayerEngine& NeuralEngine::GetLayerEngine() const
{
	assert(m_impl);
	return m_impl->GetLayerEngine();
}

//.............................................................................

INeuralConfigurator& NeuralEngine::GetConfigurator()
{
	assert(m_impl);
	return m_impl->GetConfigurator();
}

//.............................................................................

const INeuralConfigurator& NeuralEngine::GetConfigurator() const
{
	assert(m_impl);
	return m_impl->GetConfigurator();
}

//.............................................................................

IDatasetController& NeuralEngine::GetDatasetController()
{
	assert(m_impl);
	return m_impl->GetDatasetController();
}

//.............................................................................

const IDatasetController& NeuralEngine::GetDatasetController() const
{
	assert(m_impl);
	return m_impl->GetDatasetController();
}

//.............................................................................

ITrainable& NeuralEngine::GetTrainable()
{
	assert(m_impl);
	return m_impl->GetTrainable();
}

//.............................................................................

bool NeuralEngine::SwitchImpl(NeuralFrameworkType type)
{
	return false;
}

//.............................................................................

void NeuralEngine::CreateImpl(NeuralFrameworkType type)
{
	switch (type)
	{
#ifdef STEPNN_USE_NEOML
	case NeuralFrameworkType::NeoML:
		m_impl = std::make_unique<NeuralEngineNeoML>();
		break;
#endif
#ifdef STEPNN_USE_TF
	case NeuralFrameworkType::TF:
		m_impl = std::make_unique<NeuralEngineTF>();
		break;
#endif
#ifdef STEPNN_USE_TORCH
	case NeuralFrameworkType::Torch:
		m_impl = std::make_unique<NeuralEngineTorch>();
		break;
#endif
	case NeuralFrameworkType::Unknown:
	default:
		m_impl = std::make_unique<NeuralEngineDummy>();
		break;
	}
}

}