#pragma once

#include <memory>

#include "DatasetTorch.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API IDataLoaderTorch
{
public:
	virtual ~IDataLoaderTorch() = default;

	static std::unique_ptr<IDataLoaderTorch> Create(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options);

	/*
	* Dataset should be mapped to Stack<>
	* ...
	* Because we applied the Stack collation earlier, the data loader returns only a single such example.
	* If we had not applied the collation, the data loader would yield std::vector<torch::data::Example<>> instead,
	* with one element per example in the batch.
	* ...
	*/
	virtual torch::data::Iterator<torch::data::Example<>> begin() = 0;
	virtual torch::data::Iterator<torch::data::Example<>> end() = 0;
};

template<typename SamplerT, typename DataLoaderT>
struct STEPNN_API BaseDataLoaderTorch : public IDataLoaderTorch
{
	using Ptr = std::unique_ptr<DataLoaderT>;

	static Ptr Create(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options)
	{
		const auto size = dataset.size();
		SamplerT sampler(size.value());

		return torch::data::make_data_loader<DatasetTorchImpl, SamplerT>(std::move(dataset), std::move(sampler), std::move(options));
	}

	BaseDataLoaderTorch(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options)
		: ptr(Create(std::move(dataset), std::move(options)))
	{}

	torch::data::Iterator<torch::data::Example<>> begin() { assert(ptr); return ptr->begin(); }
	torch::data::Iterator<torch::data::Example<>> end() { assert(ptr); return ptr->end(); }

	Ptr ptr;
};

using RandomSamplerTorch = torch::data::samplers::RandomSampler;
using SequentialSamplerTorch = torch::data::samplers::SequentialSampler;

using StatelessRandomDataLoaderTorch = BaseDataLoaderTorch<RandomSamplerTorch, torch::data::StatelessDataLoader<DatasetTorchImpl, RandomSamplerTorch>>;
using StatelessSequentialDataLoaderTorch = BaseDataLoaderTorch<SequentialSamplerTorch, torch::data::StatelessDataLoader<DatasetTorchImpl, SequentialSamplerTorch>>;

}