#include <torch/nn/modules/linear.h>

#include "StepNN/Neural/Layer/Settings/FlattenLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class FlattenLayerTorch : public BaseLayerTorchImpl<FlattenLayerSettings, torch::nn::Flatten>
{
public:
	FlattenLayerTorch() = default;
	FlattenLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<FlattenLayerSettings, torch::nn::Flatten>::SetSettings(settings);
	}

	void SetSettings(const FlattenLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<FlattenLayerSettings, torch::nn::Flatten>::SetSettings(typedSettings);

		auto options = torch::nn::FlattenOptions()
			.start_dim(m_typedSettings.GetInDim())
			.end_dim(m_typedSettings.GetOutDim())
			;

		m_layerImpl = std::make_shared<torch::nn::Flatten>(options);
	}
};

}

std::shared_ptr<ILayer> CreateFlattenLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_shared<FlattenLayerTorch>(settings);
}

}