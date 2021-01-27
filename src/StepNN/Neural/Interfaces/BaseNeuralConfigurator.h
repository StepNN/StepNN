#pragma once

#include "INeuralConfigurator.h"

#include "StepNNLib.h"

namespace StepNN {

class STEPNN_API BaseNeuralConfigurator : public Interfaces::INeuralConfigurator
{
public:
/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
	const NeuralConfiguration& GetNeuralConfiguration() const noexcept;

	void SetDeviceType(DeviceType type) override;
	StepNN::DeviceType GetDeviceType() const noexcept override;
///

protected:
	explicit BaseNeuralConfigurator() = default;

protected:
	NeuralConfiguration m_config;
};

}