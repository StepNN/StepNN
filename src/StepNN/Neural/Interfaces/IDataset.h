#pragma once

#include <string>

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API IDataset
{
public:
	enum class AccessMode { Undefined, Random, Sequential };

public:
	virtual ~IDataset() = default;

	virtual void Open(const std::string&) = 0;

	virtual size_t GetTrainSize() const = 0;
	virtual size_t GetTestSize() const = 0;

	virtual void SetAccessMode(AccessMode) = 0;
	virtual AccessMode GetAccessMode() const noexcept = 0;

	virtual void Reshuffle() = 0;
};

}