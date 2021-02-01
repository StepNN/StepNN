#pragma once

#include "StepNN/Utils/Interfaces/IUserController.h"

#include "IDatasetUser.h"

namespace StepNN::Neural::Interfaces {

class IDatasetController : virtual public IUserController<IDatasetUser>
{
public:
	virtual ~IDatasetController() = default;

	virtual void SetDataset(const std::shared_ptr<IDataset>& dataset)
	{
		m_dataset = dataset;
		for (auto& user : m_users)
			user->SetDataset(dataset);
	}

protected:
	std::shared_ptr<IDataset> m_dataset;
};

}