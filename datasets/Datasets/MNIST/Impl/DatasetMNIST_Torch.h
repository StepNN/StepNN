#pragma once

#include <memory>

#include "StepNN/Neural/Impl/Torch/Dataset/DataLoaderTorch.h"

namespace StepNN::Dataset {

class DatasetMNIST_Torch : public Neural::DatasetTorch
{
public:
// IDataset
	void Open(const std::string& filename) override;
	size_t GetTrainSize() const override;
	size_t GetTestSize() const override;

	// do nothing because torch's data loaders has abilities to shuffle itself
	void Reshuffle() override {}
};

}