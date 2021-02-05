#pragma once

#include "StepNN/Utils/Interfaces/IUserController.h"

#include "IUserTorch.h"

namespace StepNN::Neural {

class IControllerTorch : virtual public IUserController<IUserTorch>
{
public:
	virtual ~IControllerTorch() = default;

	void SetTorchSequential(const std::shared_ptr<TorchSequential>& torchSequential)
	{
		m_torchSequential = torchSequential;
		for (auto& user : m_users)
			user->SetMathEngine(torchSequential);
	}

protected:
	std::shared_ptr<TorchSequential> m_torchSequential;
};

}
