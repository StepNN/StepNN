#pragma once

#include <memory>

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

namespace StepNN::Neural {

class IUserTorchSequential
{
public:
	virtual ~IUserTorchSequential() = default;

	virtual void SetTorchSequential(const std::weak_ptr<TorchSequential>& torchSequential) { m_torchSequential = torchSequential; }
	virtual void SetLossCriterion(const std::weak_ptr<TorchModule>& lossCriterion) { m_lossCriterion = lossCriterion; }

protected:
	std::shared_ptr<TorchSequential> GetTorchSequential(bool required = true) const
	{
		const auto torchSequential = m_torchSequential.lock();
		if (!torchSequential && required)
			assert(!"IUserTorch: torchSequential is nullptr!");

		return torchSequential;
	}

	std::shared_ptr<TorchModule> GetLossCriterion(bool required = true) const
	{
		const auto lossCriterion = m_lossCriterion.lock();
		if (!lossCriterion && required)
			assert(!"IUserTorch: lossCriterion is nullptr!");

		return lossCriterion;
	}

	std::vector<torch::Tensor> GetTrainableParams() const
	{
		const auto torchSequential = m_torchSequential.lock();
		std::vector<torch::Tensor> trainableParams;
		auto params = torchSequential->get()->named_parameters(true);
		for (auto& param : params)
		{
			if (param.value().requires_grad())
				trainableParams.push_back(param.value());
		}
		return trainableParams;
	}

protected:
	std::weak_ptr<TorchSequential> m_torchSequential;
	std::weak_ptr<TorchModule> m_lossCriterion;
};

}
