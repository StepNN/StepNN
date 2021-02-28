#pragma once

#include <memory>

#include "DatasetTorch.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API IDataLoaderTorch
{
public:
	virtual ~IDataLoaderTorch() = default;

	static std::unique_ptr<IDataLoaderTorch> Create(DatasetTorch&& dataset, torch::data::DataLoaderOptions&& options);
};

template<typename SamplerT, typename DataLoaderT>
struct STEPNN_API BaseDataLoaderTorch : public IDataLoaderTorch
{
	using Ptr = std::unique_ptr<DataLoaderT>;

	static Ptr Create(DatasetTorch&& dataset, torch::data::DataLoaderOptions&& options)
	{
		const auto size = dataset.size();
		SamplerT sampler(size.value());

		return torch::data::make_data_loader<DatasetTorch, SamplerT>(std::move(dataset), std::move(sampler), std::move(options));
	}

	BaseDataLoaderTorch(DatasetTorch&& dataset, torch::data::DataLoaderOptions&& options)
		: ptr(Create(std::move(dataset), std::move(options)))
	{}

	Ptr ptr;
};

using RandomSamplerTorch = torch::data::samplers::RandomSampler;
using SequentialSamplerTorch = torch::data::samplers::SequentialSampler;

using StatelessRandomDataLoaderTorch = BaseDataLoaderTorch<RandomSamplerTorch, torch::data::StatelessDataLoader<DatasetTorch, RandomSamplerTorch>>;
using StatelessSequentialDataLoaderTorch = BaseDataLoaderTorch<SequentialSamplerTorch, torch::data::StatelessDataLoader<DatasetTorch, SequentialSamplerTorch>>;

}