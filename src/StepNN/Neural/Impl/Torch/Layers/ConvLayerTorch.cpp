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

LayerUPtr CreateConvLayerTorch(const BaseLayerSettings& settings)
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<ConvLayerTorch>();
	else
		return std::make_unique<ConvLayerTorch>(settings);
}

}