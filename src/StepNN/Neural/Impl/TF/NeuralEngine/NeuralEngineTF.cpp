#include "cassert"

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Impl/TF/LayerEngine/LayerEngineTF.h"
#include "NeuralEngineTF.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralEngineTF::NeuralEngineTF()
	: m_layerEngine(std::make_unique<LayerEngineTF>())
{
}

//.............................................................................

NeuralEngineTF::~NeuralEngineTF() = default;

//.............................................................................

ILayerEngine& NeuralEngineTF::GetLayerEngine()
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

const ILayerEngine& NeuralEngineTF::GetLayerEngine() const
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

INeuralConfigurator& NeuralEngineTF::GetConfigurator()
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

const INeuralConfigurator& NeuralEngineTF::GetConfigurator() const
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

ITrainable& NeuralEngineTF::GetTrainable()
{
	assert(m_net);
	return *m_net;
}

//.............................................................................

bool NeuralEngineTF::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

}