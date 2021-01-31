#pragma once

#include <vector>

#include "IDataset.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseDataset : public Interfaces::IDataset
{
public:
	void Open(const std::string& filename) override;
	size_t GetTrainSize() const override;
	size_t GetTestSize() const override;
	void Reshuffle() override;

protected:
	explicit BaseDataset() = default;

protected:
	std::vector<size_t> m_shuffleIndicies;
};

}