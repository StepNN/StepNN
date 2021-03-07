#include <stdexcept>

#include <torch/nn/modules/conv.h>

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTorchImpl.h"

#define SET_SETTINGS(settings)																\
if constexpr (Size <= 3)																	\
	BaseLayerTorchImpl<ConvLayerSettings<Size>, TorchT>::SetSettings(settings);				\
else																						\
	static_assert(false, "Incorrect size")

namespace {

torch::nn::Conv2dOptions::padding_mode_t GetPaddingMode(StepNN::Neural::PaddingMode mode)
{
	switch (mode)
	{
	case StepNN::Neural::PaddingMode::Circular:
		return torch::enumtype::kCircular();
	case StepNN::Neural::PaddingMode::Reflect:
		return torch::enumtype::kReflect();
	case StepNN::Neural::PaddingMode::Replicate:
		return torch::enumtype::kReplicate();
	case StepNN::Neural::PaddingMode::Zeros:
		return torch::enumtype::kZeros();
	default:
		assert(false);
		return torch::enumtype::kZeros();
	}
}

}

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

template<size_t Size, typename TorchT>
class ConvLayerTorch : public BaseLayerTorchImpl<ConvLayerSettings<Size>, TorchT>
{
public:
	ConvLayerTorch() = default;
	ConvLayerTorch(const BaseLayerSettings& settings)
	{
		SET_SETTINGS(settings);
	}

	void SetSettings(const ConvLayerSettings<Size>& typedSettings)
	{
		SET_SETTINGS(typedSettings);

		auto options = torch::nn::ConvOptions<Size>(
			m_typedSettings.GetInChannels(),
			m_typedSettings.GetOutChannels(),
			torch::ExpandingArray<Size>(m_typedSettings.GetKernel())
		);

		options.bias(m_typedSettings.GetBias());

		if (m_typedSettings.HasDilation())
			options.dilation(m_typedSettings.GetDilation());

		if (m_typedSettings.HasStride())
			options.dilation(m_typedSettings.GetStride());

		if (m_typedSettings.HasPadding())
		{
			options.padding_mode(GetPaddingMode(m_typedSettings.GetPaddingMode()));
			options.padding(m_typedSettings.GetPadding());
		}

		if constexpr (Size <= 3)
			m_layerImpl = std::make_shared<TorchT>(options);
		else
			static_assert(false, "Incorrect size");
	}
};

}

std::shared_ptr<ILayer> CreateConv1DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<ConvLayerTorch<1, torch::nn::Conv1d>>(settings); }
std::shared_ptr<ILayer> CreateConv2DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<ConvLayerTorch<2, torch::nn::Conv2d>>(settings); }
std::shared_ptr<ILayer> CreateConv3DLayerTorch(const BaseLayerSettings& settings) { return std::make_shared<ConvLayerTorch<3, torch::nn::Conv3d>>(settings); }

}