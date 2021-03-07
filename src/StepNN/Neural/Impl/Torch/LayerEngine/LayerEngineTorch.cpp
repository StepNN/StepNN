#include "LayerEngineTorch.h"

namespace StepNN::Neural {

void LayerEngineTorch::AddLossLayer(const BaseLayerSettings& settings)
{
	BaseLayerEngine::AddLossLayer(settings);
	SetLossCriterion(m_lossCriterion);
}

//.............................................................................

}