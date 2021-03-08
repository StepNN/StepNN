#pragma once

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

namespace StepNN::Neural {

class ILossCriterionTorch
{
public:
	virtual ~ILossCriterionTorch() = default;

	virtual torch::Tensor CalculateLoss(const torch::Tensor& input, const torch::Tensor& target) = 0;
};

}