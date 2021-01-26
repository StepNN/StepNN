#include <cassert>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "NeuralEngineDummy.h"

using namespace StepNN::Interfaces;

namespace StepNN {

NeuralEngineDummy::NeuralEngineDummy()
{}

//.............................................................................

ILayerEngine& NeuralEngineDummy::GetLayerEngine()
{
	throw std::runtime_error(Defs::NOT_IMPL_STR);
}

//.............................................................................

const ILayerEngine& NeuralEngineDummy::GetLayerEngine() const
{
	throw std::runtime_error(Defs::NOT_IMPL_STR);
}

//.............................................................................

bool NeuralEngineDummy::SwitchImpl(NeuralFrameworkType)
{
	throw std::runtime_error(Defs::NOT_IMPL_STR);
}

}