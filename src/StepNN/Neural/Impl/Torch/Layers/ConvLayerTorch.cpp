#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ConvLayerTorch : public BaseLayerTorchImpl<ConvLayerSettings>
{
public:
	ConvLayerTorch() = default;
	ConvLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const ConvLayerSettings& typedSettings)
	{
		BaseLayerTorchImpl<ConvLayerSettings>::SetSettings(typedSettings);
	}
};

}

LayerUPtr CreateConvLayerTorch() { return std::unique_ptr<ConvLayerTorch>(); }

LayerUPtr CreateConvLayerTorch(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTorch>(settings); }

}