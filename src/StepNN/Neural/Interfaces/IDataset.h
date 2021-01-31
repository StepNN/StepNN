#pragma once

#include <string>

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API IDataset
{
public:
	virtual ~IDataset() = default;

	virtual void Open(const std::string&) = 0;

	virtual size_t GetTrainSize() const = 0;
	virtual size_t GetTestSize() const = 0;

	virtual void Reshuffle() = 0;
};

}