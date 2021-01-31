#include <algorithm>

#include "BaseDatasetController.h"

namespace StepNN::Neural {

void BaseDatasetController::AddDatasetUser(IDatasetUser* datasetUser)
{
	m_datasetUsers.push_back(datasetUser);
}

//.............................................................................

void BaseDatasetController::SetDataset(const std::shared_ptr<IDataset>& dataset)
{
	m_dataset = dataset;
	for (auto& user : m_datasetUsers)
		user->SetDataset(dataset);
}


}