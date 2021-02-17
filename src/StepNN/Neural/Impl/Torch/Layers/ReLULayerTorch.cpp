#include <torch/nn/modules/activation.h>

#include "StepNN/Neural/Layer/Settings/ReLULayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ReLULayerTorch : public BaseLayerTorchImpl<ReLULayerSettings, torch::nn::ReLU>
{
public:
	ReLULayerTorch() = default;
	ReLULayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<ReLULayerSettings, torch::nn::ReLU>::SetSettings(settings);
	}

	void SetSettings(const ReLULayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<ReLULayerSettings, torch::nn::ReLU>::SetSettings(typedSettings);
		m_layerImpl = std::make_shared<torch::nn::ReLU>();
	}
};

}

LayerUPtr CreateReLULayerTorch(const BaseLayerSettings& settings)
{
	return std::make_unique<ReLULayerTorch>(settings);
}

}