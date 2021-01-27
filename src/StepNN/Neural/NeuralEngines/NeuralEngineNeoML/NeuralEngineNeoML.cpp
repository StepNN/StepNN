#include <cassert>

#include "CommonNeoML.h"

#include "StepNN/Types/CommonDefs.h"

#include "LayerEngine/LayerEngineNeoML.h"
#include "NeuralNet/NeuralNetNeoML.h"

#include "NeuralEngineNeoML.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralEngineNeoML::NeuralEngineNeoML()
	: m_layerEngine(std::make_unique<LayerEngineNeoML>())
	, m_net(std::make_unique<NeuralNetNeoML>(m_layerEngine.get()))
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

bool NeuralEngineNeoML::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

}