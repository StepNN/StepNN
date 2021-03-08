#include "DataLoaderTorch.h"

#include "DatasetTorch.h"

namespace StepNN::Neural {

std::unique_ptr<IDataLoaderTorch> DatasetTorch::GetTrainDataLoader()
{
	assert(m_trainDataset);

	return m_accessMode != AccessMode::Undefined ? IDataLoaderTorch::Create(std::move(*m_trainDataset), torch::data::DataLoaderOptions(), m_accessMode) : nullptr;
}

//.............................................................................

std::unique_ptr<IDataLoaderTorch> DatasetTorch::GetTestDataLoader()
{
	assert(m_testDataset);

	return m_accessMode != AccessMode::Undefined ?  IDataLoaderTorch::Create(std::move(*m_testDataset), torch::data::DataLoaderOptions(), m_accessMode) : nullptr;
}

}