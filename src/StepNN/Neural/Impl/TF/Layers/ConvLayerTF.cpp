#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTF.h"

namespace StepNN::Neural {

namespace {

class ConvLayerTF : public StepNN::Neural::BaseLayerTF<StepNN::Neural::ConvLayerSettings>
{
public:
	ConvLayerTF() = default;
	ConvLayerTF(const StepNN::Neural::BaseLayerSettings& settings)
	{
		StepNN::Neural::BaseLayerTF<StepNN::Neural::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::Neural::ConvLayerSettings& typedSettings)
	{
		StepNN::Neural::BaseLayerTF<StepNN::Neural::ConvLayerSettings>::SetSettings(typedSettings);
	}

private:

};

}

LayerUPtr CreateConvLayerTF() { return std::unique_ptr<ConvLayerTF>(); }

LayerUPtr CreateConvLayerTF(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTF>(settings); }

}