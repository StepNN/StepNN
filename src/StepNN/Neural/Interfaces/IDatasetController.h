#pragma once

#include "IDatasetUser.h"

namespace StepNN::Neural::Interfaces {

class IDatasetController
{
public:
	virtual ~IDatasetController() = default;

	virtual void AddDatasetUser(IDatasetUser* datasetUser) = 0;
	virtual void SetDataset(const std::shared_ptr<IDataset>&) = 0;
};

}