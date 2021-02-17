#include <torch/nn/modules/batchnorm.h>

#include "StepNN/Neural/Layer/Settings/BatchNormalizationLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class BatchNormalizationLayerTorch : public BaseLayerTorchImpl<BatchNormalizationLayerSettings, torch::nn::BatchNorm2d>
{
public:
	BatchNormalizationLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<BatchNormalizationLayerSettings, torch::nn::BatchNorm2d>::SetSettings(settings);
	}

	void SetSettings(const BatchNormalizationLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<BatchNormalizationLayerSettings, torch::nn::BatchNorm2d>::SetSettings(typedSettings);

		assert(!m_typedSettings.IsEmpty());

		auto options = torch::nn::BatchNormOptions(m_typedSettings.GetNumFeatures())
			.eps(m_typedSettings.GetEps())
			.momentum(m_typedSettings.GetMomentum())
			.affine(m_typedSettings.GetAffine())
			.track_running_stats(m_typedSettings.GetTrackRunningStats())
			;

		m_layerImpl = std::make_shared<torch::nn::BatchNorm2d>(options);
	}
};

}

LayerUPtr CreateBatchNormalizationLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_unique<BatchNormalizationLayerTorch>(settings);
}

}