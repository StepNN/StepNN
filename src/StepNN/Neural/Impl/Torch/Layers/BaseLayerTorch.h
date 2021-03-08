#pragma once

#include <cassert>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/ILayer.h"

#include "StepNN/Neural/Impl/Torch/Interfaces/ILossCriterionTorch.h"
#include "StepNN/Neural/Impl/Torch/Interfaces/IUserTorchSequential.h"

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseLayerTorch
	: public ILayer
	, public IUserTorchSequential
	, public ILossCriterionTorch
{
public:
	~BaseLayerTorch() = default;

protected:
	explicit BaseLayerTorch() = default;

/// ILayer
	void SetSettings(const BaseLayerSettings& settings) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	const BaseLayerSettings& GetBaseSettings() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	const std::string& GetId() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	void Connect(LayerPtr) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
///

/// ILossCriterionTorch
	torch::Tensor CalculateLoss(const torch::Tensor& input, const torch::Tensor& targets) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
///
};

}