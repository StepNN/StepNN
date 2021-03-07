#pragma once

#include <optional>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/BaseDataset.h"

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class IDataLoaderTorch;

//.............................................................................

class STEPNN_API DatasetTorchImpl : virtual public torch::data::Dataset<DatasetTorchImpl>
{
public:
	torch::data::Example<> get(size_t index) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	c10::optional<size_t> size() const { throw std::runtime_error(Defs::NOT_IMPL_STR); }

public:
	std::vector<torch::Tensor> m_samples, m_labels;
	size_t m_size;
};

//.............................................................................

class STEPNN_API DatasetTorch : public BaseDataset
{
public:
	explicit DatasetTorch() = default;
	virtual ~DatasetTorch() = default;

	std::unique_ptr<IDataLoaderTorch> GetTrainDataLoader();
	std::unique_ptr<IDataLoaderTorch> GetTestDataLoader();

private:
	std::unique_ptr<DatasetTorchImpl> m_trainDataset, m_testDataset;
};

}