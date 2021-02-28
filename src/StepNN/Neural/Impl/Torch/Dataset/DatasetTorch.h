#pragma once

#include <optional>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/BaseDataset.h"

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class IDataLoaderTorch;

class STEPNN_API DatasetTorch
	: public BaseDataset
	, virtual public torch::data::Dataset<DatasetTorch>
{
public:
	explicit DatasetTorch() = default;
	virtual ~DatasetTorch() = default;

	virtual std::unique_ptr<IDataLoaderTorch> GetTrainDataLoader() { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	virtual std::unique_ptr<IDataLoaderTorch> GetTestDataLoader() { throw std::runtime_error(Defs::NOT_IMPL_STR); }

	torch::data::Example<> get(size_t index) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
	c10::optional<size_t> size() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
};

}