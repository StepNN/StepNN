#include "src/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTorch.h"

namespace StepNN {

namespace {

class ConvLayerTorch : public StepNN::BaseLayerTorch<StepNN::ConvLayerSettings>
{
public:
	ConvLayerTorch() = default;
	ConvLayerTorch(const StepNN::BaseLayerSettings& settings)
	{
		StepNN::BaseLayerTorch<StepNN::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::ConvLayerSettings& typedSettings)
	{
		StepNN::BaseLayerTorch<StepNN::ConvLayerSettings>::SetSettings(typedSettings);
	}

private:

};

}

LayerUPtr CreateConvLayerTorch() { return std::unique_ptr<ConvLayerTorch>(); }

LayerUPtr CreateConvLayerTorch(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTorch>(settings); }

}