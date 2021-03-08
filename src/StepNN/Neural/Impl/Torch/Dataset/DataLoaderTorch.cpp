#include "DataLoaderTorch.h"

namespace StepNN::Neural {

std::unique_ptr<IDataLoaderTorch> IDataLoaderTorch::Create(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options, Interfaces::IDataset::AccessMode accessMode)
{
	switch (accessMode)
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