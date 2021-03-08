#include <torch/nn/modules/loss.h>

#include "StepNN/Neural/Layer/Settings/CrossEntropyLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace {

torch::nn::CrossEntropyLossOptions::reduction_t GetReduction(StepNN::Neural::CrossEntropyLayerSettings::Reduction reduction)
{
	switch (reduction)
	{
	case StepNN::Neural::CrossEntropyLayerSettings::Reduction::None:
		return torch::enumtype::kNone();
	case StepNN::Neural::CrossEntropyLayerSettings::Reduction::Mean:
		return torch::enumtype::kMean();
	case StepNN::Neural::CrossEntropyLayerSettings::Reduction::Sum:
		return torch::enumtype::kSum();
	}
}

torch::Tensor GetWeight()
{
	//@ todo
	return torch::Tensor();
}

}

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class CrossEntropyLayerTorch : public BaseLayerTorchImpl<CrossEntropyLayerSettings, torch::nn::CrossEntropyLoss>
{
public:
	CrossEntropyLayerTorch() = default;
	CrossEntropyLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<CrossEntropyLayerSettings, torch::nn::CrossEntropyLoss>::SetSettings(settings);
	}

	void SetSettings(const CrossEntropyLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<CrossEntropyLayerSettings, torch::nn::CrossEntropyLoss>::SetSettings(typedSettings);

		auto options = torch::nn::CrossEntropyLossOptions()
			.ignore_index(m_typedSettings.GetIgnoreIndex())
			.reduction(GetReduction(m_typedSettings.GetReduction()))
		//	.weight(GetWeight()) // @todo uncomment when weight will be implemented in CrossEntropyLayerSettings
			;

		m_layerImpl = std::make_shared<torch::nn::CrossEntropyLoss>(options);
	}

/// ILossCriterionTorch
	torch::Tensor CalculateLoss(const torch::Tensor& input, const torch::Tensor& target) override
	{
		return m_layerImpl->get()->forward(input, target);
	}
///
};

}

std::shared_ptr<ILayer> CreateCrossEntropyLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_shared<CrossEntropyLayerTorch>(settings);
}

}