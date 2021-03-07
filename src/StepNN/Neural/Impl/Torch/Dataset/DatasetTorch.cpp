#include "DataLoaderTorch.h"

#include "DatasetTorch.h"

namespace StepNN::Neural {

std::unique_ptr<IDataLoaderTorch> DatasetTorch::GetTrainDataLoader()
{
	assert(m_trainDataset);

	switch (m_accessMode)
	{
	case AccessMode::Random:
		return std::make_unique<StatelessRandomDataLoaderTorch>(std::move(*m_trainDataset), torch::data::DataLoaderOptions());
	case AccessMode::Sequential:
		return std::make_unique<StatelessSequentialDataLoaderTorch>(std::move(*m_trainDataset), torch::data::DataLoaderOptions());
	default:
		return nullptr;
	}
}

//.............................................................................

std::unique_ptr<IDataLoaderTorch> DatasetTorch::GetTestDataLoader()
{
	assert(m_testDataset);

	switch (m_accessMode)
	{
	case AccessMode::Random:
		return std::make_unique<StatelessRandomDataLoaderTorch>(std::move(*m_testDataset), torch::data::DataLoaderOptions());
	case AccessMode::Sequential:
		return std::make_unique<StatelessSequentialDataLoaderTorch>(std::move(*m_testDataset), torch::data::DataLoaderOptions());
	default:
		return nullptr;
	}
}

}