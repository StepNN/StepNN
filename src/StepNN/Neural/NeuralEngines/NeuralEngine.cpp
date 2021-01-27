#include <cassert>

#include "StepNN/Neural/NeuralEngines/NeuralEngineDummy/NeuralEngineDummy.h"
#include "StepNN/Neural/NeuralEngines/NeuralEngineNeoML/NeuralEngineNeoML.h"
#include "StepNN/Neural/NeuralEngines/NeuralEngineTF/NeuralEngineTF.h"
#include "StepNN/Neural/NeuralEngines/NeuralEngineTorch/NeuralEngineTorch.h"

#include "NeuralEngine.h"

namespace StepNN {

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