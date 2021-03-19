#pragma once

#include <memory>

#include "DatasetTorch.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API IDataLoaderTorch
{
public:
	virtual ~IDataLoaderTorch() = default;

	static std::unique_ptr<IDataLoaderTorch> Create(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options, Interfaces::IDataset::AccessMode accessMode);

	virtual torch::data::Iterator<torch::data::Example<>> begin() = 0;
	virtual torch::data::Iterator<torch::data::Example<>> end() = 0;

	c10::ScalarType GetSampleScalarType() const { return m_sampleScalarType; }
	c10::ScalarType GetLabelScalarType() const { return m_labelScalarType; }

protected:
	c10::ScalarType m_sampleScalarType, m_labelScalarType;
};

template<typename SamplerT, typename DataLoaderT>
class STEPNN_API BaseDataLoaderTorch : public IDataLoaderTorch
{
public:
	using Ptr = torch::disable_if_t<false, std::unique_ptr<DataLoaderT>>;

	BaseDataLoaderTorch(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options)
		: ptr(CreateImpl(std::move(dataset), std::move(options)))
	{}

	torch::data::Iterator<torch::data::Example<>> begin() { assert(ptr); return ptr->begin(); }
	torch::data::Iterator<torch::data::Example<>> end() { assert(ptr); return ptr->end(); }

private:
	Ptr CreateImpl(DatasetTorchImpl&& dataset, torch::data::DataLoaderOptions&& options)
	{
		m_sampleScalarType = dataset.GetSampleScalarType();
		m_labelScalarType = dataset.GetLabelScalarType();

		/*
		* Dataset should be mapped to Stack<>
		* ...
		* Because we applied the Stack collation earlier, the data loader returns only a single such example.
		* If we had not applied the collation, the data loader would yield std::vector<torch::data::Example<>> instead,
		* with one element per example in the batch.
		* ...
		*/
		auto mappedDataset = dataset.map(torch::data::transforms::Stack<>());

		//@todo Check which dataset (mapped or not) should provide size
		const auto size = dataset.size();
		SamplerT sampler(size.value());

		return torch::data::make_data_loader(std::move(mappedDataset), std::move(sampler), std::move(options));
	}

public:
	Ptr ptr;
};

using MapDatasetTorch = torch::data::datasets::MapDataset<DatasetTorchImpl, torch::data::transforms::Stack<>>;

using RandomSamplerTorch = torch::data::samplers::RandomSampler;
using SequentialSamplerTorch = torch::data::samplers::SequentialSampler;

using StatelessRandomDataLoaderTorch = BaseDataLoaderTorch<RandomSamplerTorch, torch::data::StatelessDataLoader<MapDatasetTorch, RandomSamplerTorch>>;
using StatelessSequentialDataLoaderTorch = BaseDataLoaderTorch<SequentialSamplerTorch, torch::data::StatelessDataLoader<MapDatasetTorch, SequentialSamplerTorch>>;

}