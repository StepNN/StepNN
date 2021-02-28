#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/IDatasetUserImpl.h"
#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

#include "StepNN/Neural/Impl/Torch/Dataset/DatasetTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetTorch
	: virtual public BaseNeuralNet
	, virtual public IDatasetUserImpl<DatasetTorch>
{
public:
	explicit NeuralNetTorch(const ILayerEngine* layerEngine);
	~NeuralNetTorch();

/// INeuralConfigurator
	void SetNeuralConfiguration(const NeuralConfiguration&);
	void SetNeuralConfiguration(NeuralConfiguration&&);
///

/// ITrainable
	void Train() override;
///

private:
	void OnSetNeuralConfiguration();

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

}
