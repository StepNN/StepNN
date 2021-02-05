#pragma once

#include <memory>

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

namespace StepNN::Neural {

class IUserTorch
{
public:
	virtual ~IUserTorch() = default;

	virtual void SetSequential(const std::weak_ptr<TorchSequential>& torchSequential) { m_torchSequential = torchSequential; }

protected:
	std::shared_ptr<TorchSequential> GetTorchSequential(bool required = true) const
	{
		const auto torchSequential = m_torchSequential.lock();
		if (!torchSequential && required)
			assert(!"IUserTorch: torchSequential is nullptr!");

		return torchSequential;
	}

protected:
	std::weak_ptr<TorchSequential> m_torchSequential;
};

}
