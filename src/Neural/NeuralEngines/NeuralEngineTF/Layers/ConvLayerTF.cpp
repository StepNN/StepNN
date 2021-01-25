#include "src/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTF.h"

namespace StepNN {

namespace {

class ConvLayerTF : public StepNN::BaseLayerTF<StepNN::ConvLayerSettings>
{
public:
	ConvLayerTF() = default;
	ConvLayerTF(const StepNN::BaseLayerSettings& settings)
	{
		StepNN::BaseLayerTF<StepNN::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::ConvLayerSettings& typedSettings)
	{
		StepNN::BaseLayerTF<StepNN::ConvLayerSettings>::SetSettings(typedSettings);
	}

private:

};

}

LayerUPtr CreateConvLayerTF() { return std::unique_ptr<ConvLayerTF>(); }

LayerUPtr CreateConvLayerTF(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTF>(settings); }

}