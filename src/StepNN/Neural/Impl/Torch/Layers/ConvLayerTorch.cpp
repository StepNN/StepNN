#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTorch.h"

namespace StepNN::Neural {

namespace {

class ConvLayerTorch : public StepNN::Neural::BaseLayerTorch<StepNN::Neural::ConvLayerSettings>
{
public:
	ConvLayerTorch() = default;
	ConvLayerTorch(const StepNN::Neural::BaseLayerSettings& settings)
	{
		StepNN::Neural::BaseLayerTorch<StepNN::Neural::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::Neural::ConvLayerSettings& typedSettings)
	{
		StepNN::Neural::BaseLayerTorch<StepNN::Neural::ConvLayerSettings>::SetSettings(typedSettings);
	}

private:

};

}

LayerUPtr CreateConvLayerTorch() { return std::unique_ptr<ConvLayerTorch>(); }

LayerUPtr CreateConvLayerTorch(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTorch>(settings); }

}