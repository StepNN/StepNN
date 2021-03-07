#pragma once

#include "StepNN/Utils/Interfaces/IUserController.h"

#include "IUserTorchSequential.h"

namespace StepNN::Neural {

class IControllerTorchSequential : virtual public IUserController<IUserTorchSequential>
{
public:
	virtual ~IControllerTorchSequential() = default;

	void SetTorchSequential(const std::shared_ptr<TorchSequential>& torchSequential)
	{
		m_torchSequential = torchSequential;
		for (auto& user : m_users)
			user->SetTorchSequential(torchSequential);
	}

	void SetLossCriterion(const std::shared_ptr<TorchModule>& lossCriterion)
	{
		m_lossCriterion = lossCriterion;
		for (auto& user : m_users)
			user->SetLossCriterion(lossCriterion);
	}

protected:
	// Common sequential of torch neural net
	std::shared_ptr<TorchSequential> m_torchSequential;
	std::shared_ptr<TorchModule> m_lossCriterion;
};

}
