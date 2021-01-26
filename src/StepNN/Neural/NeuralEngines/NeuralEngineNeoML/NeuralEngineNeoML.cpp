#include "cassert"

#include "StepNN/Types/CommonDefs.h"

#include "LayerEngine/LayerEngineNeoML.h"
#include "NeuralEngineNeoML.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralEngineNeoML::NeuralEngineNeoML()
	: m_layerEngine(std::make_unique<LayerEngineNeoML>())
{
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

bool NeuralEngineNeoML::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

}