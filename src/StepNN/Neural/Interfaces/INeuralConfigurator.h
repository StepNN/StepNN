#pragma once

#include "StepNN/Neural/Data/NeuralConfiguration/NeuralConfiguration.h"

#include "StepNNLib.h"

namespace StepNN::Neural::Interfaces {

class STEPNN_API INeuralConfigurator
{
public:
	virtual ~INeuralConfigurator() = default;

	virtual void SetNeuralConfiguration(const NeuralConfiguration&) = 0;
	virtual void SetNeuralConfiguration(NeuralConfiguration&&) = 0;
	virtual const NeuralConfiguration& GetNeuralConfiguration() const noexcept = 0;

	virtual void SetDeviceType(DeviceType type) = 0;
	virtual StepNN::Neural::DeviceType GetDeviceType() const noexcept = 0;
};

}