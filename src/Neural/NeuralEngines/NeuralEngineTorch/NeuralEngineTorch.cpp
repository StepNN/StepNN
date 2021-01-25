#include "cassert"

#include "src/Types/CommonDefs.h"

#include "LayerEngine/LayerEngineTorch.h"
#include "NeuralEngineTorch.h"

using namespace StepNN::Interfaces;

namespace StepNN {

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

bool NeuralEngineTorch::SwitchImpl(NeuralFrameworkType)
{
	assert(!Defs::NOT_IMPL_STR);
	return false;
}

}