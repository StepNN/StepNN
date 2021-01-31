#include "cassert"

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Impl/Torch/LayerEngine/LayerEngineTorch.h"
#include "NeuralEngineTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

NeuralEngineTorch::NeuralEngineTorch()
	: m_layerEngine(std::make_unique<LayerEngineTorch>())
{
}

//.............................................................................

NeuralEngineTorch::~NeuralEngineTorch() = default;

//.............................................................................

ILayerEngine& NeuralEngineTorch::GetLayerEngine()
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

const ILayerEngine& NeuralEngineTorch::GetLayerEngine() const
{
	assert(m_layerEngine);
	return *m_layerEngine;
}

//.............................................................................

INeuralConfigurator& NeuralEngineTorch::GetConfigurator()
{
	assert(m_configurator);
	return *m_configurator;
}

//.............................................................................

const INeuralConfigurator& NeuralEngineTorch::GetConfigurator() const
{
	assert(m_configurator);
	return *m_configurator;
}

//.............................................................................

bool NeuralEngineTorch::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

}