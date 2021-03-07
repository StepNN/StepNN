#include <torch/nn/modules/pooling.h>

#include "StepNN/Neural/Layer/Settings/MaxPoolingLayerSettings.h"

#include "BaseLayerTorchImpl.h"

#define SET_SETTINGS(settings)																		\
if constexpr (Size <= 3)																			\
	BaseLayerTorchImpl<MaxPoolingLayerSettings<Size>, TorchT>::SetSettings(settings);				\
else																								\
	static_assert(false, "Incorrect size")

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

template<size_t Size, typename TorchT>
class MaxPoolingLayerTorch : public BaseLayerTorchImpl<MaxPoolingLayerSettings<Size>, TorchT>
{
public:
	MaxPoolingLayerTorch() = default;
	MaxPoolingLayerTorch(const BaseLayerSettings& settings)
	{
		SET_SETTINGS(settings);
	}

	void SetSettings(const MaxPoolingLayerSettings<Size>& typedSettings)
	{
		SET_SETTINGS(typedSettings);

		auto options = torch::nn::MaxPoolOptions<Size>(torch::ExpandingArray<Size>(m_typedSettings.GetKernel()));

		if(m_typedSettings.HasCeil())
			options.ceil_mode(m_typedSettings.GetCeilMode() == CeilMode::Ceil);

		if (m_typedSettings.HasDilation())
			options.dilation(m_typedSettings.GetDilation());

		if (m_typedSettings.HasStride())
			options.dilation(m_typedSettings.GetStride());

		if (m_typedSettings.HasPadding())
			options.dilation(m_typedSettings.GetPadding());

		if constexpr (Size <= 3)
			m_layerImpl = std::make_shared<TorchT>(options);
		else
			static_assert(false, "Incorrect size");
	}
};

}

std::shared_ptr<ILayer> CreateMaxPooling1DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<MaxPoolingLayerTorch<1, torch::nn::MaxPool1d>>(settings); }
std::shared_ptr<ILayer> CreateMaxPooling2DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<MaxPoolingLayerTorch<2, torch::nn::MaxPool2d>>(settings); }
std::shared_ptr<ILayer> CreateMaxPooling3DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<MaxPoolingLayerTorch<3, torch::nn::MaxPool3d>>(settings); }

}