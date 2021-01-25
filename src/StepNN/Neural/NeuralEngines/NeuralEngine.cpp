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

bool NeuralEngine::SwitchImpl(NeuralFrameworkType type)
{
	return false;
}

//.............................................................................

void NeuralEngine::CreateImpl(NeuralFrameworkType type)
{
	switch (type)
	{
	case NeuralFrameworkType::Unknown:
		m_impl = std::make_unique<NeuralEngineDummy>();
		break;
	case NeuralFrameworkType::NeoML:
		m_impl = std::make_unique<NeuralEngineNeoML>();
		break;
	case NeuralFrameworkType::TF:
		m_impl = std::make_unique<NeuralEngineTF>();
		break;
	case NeuralFrameworkType::Torch:
		m_impl = std::make_unique<NeuralEngineTorch>();
		break;
	}
}

}