#pragma once

#include <vector>

#include "IDatasetController.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseDatasetController : public IDatasetController
{
public:
	void AddDatasetUser(IDatasetUser* datasetUser);
	void SetDataset(const std::shared_ptr<IDataset>&);

protected:
	explicit BaseDatasetController() = default;

protected:
	std::shared_ptr<IDataset> m_dataset;
	std::vector<IDatasetUser*> m_datasetUsers;
};

}