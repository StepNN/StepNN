#pragma once

#include <cassert>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/INeuralEngine.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralEngineDummy : public INeuralEngine
{
public:
	explicit NeuralEngineDummy() = default;

/// Implementation of INeuralEngine
	ILayerEngine& GetLayerEngine() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	const ILayerEngine& GetLayerEngine() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	INeuralConfigurator& GetConfigurator() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	const INeuralConfigurator& GetConfigurator() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	IDatasetController& GetDatasetController() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	const IDatasetController& GetDatasetController() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	ITrainable& GetTrainable() override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	bool SwitchImpl(NeuralFrameworkType type) override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
///
};

}