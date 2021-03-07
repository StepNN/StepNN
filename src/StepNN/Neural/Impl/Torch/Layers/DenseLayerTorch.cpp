#include <torch/nn/modules/linear.h>

#include "StepNN/Neural/Layer/Settings/DenseLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class DenseLayerTorch : public BaseLayerTorchImpl<DenseLayerSettings, torch::nn::Linear>
{
public:
	DenseLayerTorch() = default;
	DenseLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<DenseLayerSettings, torch::nn::Linear>::SetSettings(settings);
	}

	void SetSettings(const DenseLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<DenseLayerSettings, torch::nn::Linear>::SetSettings(typedSettings);

		auto options = torch::nn::LinearOptions({ m_typedSettings.GetInChannels(), m_typedSettings.GetOutChannels() })
			.bias(m_typedSettings.GetBias())
			;

		m_layerImpl = std::make_shared<torch::nn::Linear>(options);
	}
};

}

std::shared_ptr<ILayer> CreateDenseLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_shared<DenseLayerTorch>(settings);
}

}