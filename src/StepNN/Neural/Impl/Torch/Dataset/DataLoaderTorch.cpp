#include "DataLoaderTorch.h"

namespace StepNN::Neural {

std::unique_ptr<IDataLoaderTorch> IDataLoaderTorch::Create(DatasetTorch&& dataset, torch::data::DataLoaderOptions&& options)
{
	switch (dataset.GetAccessMode())
	{
	case Interfaces::IDataset::AccessMode::Random:
		return std::make_unique<StatelessRandomDataLoaderTorch>(std::move(dataset), std::move(options));

	case Interfaces::IDataset::AccessMode::Sequential:
		return std::make_unique<StatelessRandomDataLoaderTorch>(std::move(dataset), std::move(options));

	case Interfaces::IDataset::AccessMode::Undefined:
	default:
		assert(false);
		return nullptr;
	}
}

}