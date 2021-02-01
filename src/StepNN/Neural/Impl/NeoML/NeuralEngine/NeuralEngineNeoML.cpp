#include <cassert>

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Impl/NeoML/LayerEngine/LayerEngineNeoML.h"
#include "StepNN/Neural/Impl/NeoML/NeuralNet/NeuralNetNeoML.h"

#include "NeuralEngineNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralEngineNeoML::NeuralEngineNeoML()
{
	//@todo initilization of gpuManager and mathEngine
	assert(false);

	m_layerEngine = std::make_unique<LayerEngineNeoML>(m_mathEngine.get());
	m_net = std::make_unique<NeuralNetNeoML>(m_layerEngine.get(), *m_mathEngine.get());

	AddDatasetUser(m_net.get());
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