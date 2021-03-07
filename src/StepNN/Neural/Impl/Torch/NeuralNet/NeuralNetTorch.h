#pragma once

#include <memory>

#include "StepNN/Neural/Interfaces/IDatasetUserImpl.h"
#include "StepNN/Neural/Interfaces/BaseNeuralNet.h"

#include "StepNN/Neural/Impl/Torch/Interfaces/IUserTorchSequential.h"
#include "StepNN/Neural/Impl/Torch/Dataset/DatasetTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class NeuralNetTorch
	: virtual public BaseNeuralNet
	, virtual public IDatasetUserImpl<DatasetTorch>
	, public IUserTorchSequential
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
	void Evaluate() override;
///

private:
	void OnSetNeuralConfiguration();

private:
	torch::Device m_device;
	std::unique_ptr<torch::optim::Optimizer> m_optimizer;
	std::function<torch::Tensor(torch::Tensor, torch::Tensor)> m_lossCriterion;
};

}
