#include <torch/nn/modules/activation.h>

#include "StepNN/Neural/Layer/Settings/SoftmaxLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SoftmaxLayerTorch : public BaseLayerTorchImpl<SoftmaxLayerSettings, torch::nn::Softmax>
{
public:
	SoftmaxLayerTorch() = default;
	SoftmaxLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<SoftmaxLayerSettings, torch::nn::Softmax>::SetSettings(settings);
	}

	void SetSettings(const SoftmaxLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<SoftmaxLayerSettings, torch::nn::Softmax>::SetSettings(typedSettings);

		torch::nn::SoftmaxOptions options(m_typedSettings.GetDimension(0));
		m_layerImpl = std::make_shared<torch::nn::Softmax>(options);
	}
};

}

std::shared_ptr<ILayer> CreateSoftmaxLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_shared<SoftmaxLayerTorch>(settings);
}

}