#include "src/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerNeoML.h"

namespace StepNN {

namespace {

class ConvLayerNeoML : public StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>
{
public:
	ConvLayerNeoML() = default;
	ConvLayerNeoML(const StepNN::BaseLayerSettings& settings)
	{
		StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::ConvLayerSettings& typedSettings)
	{
		StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>::SetSettings(typedSettings);
	}

	~ConvLayerNeoML() = default;

private:

};

}

LayerUPtr CreateConvLayerNeoML() { return std::unique_ptr<ConvLayerNeoML>(); }

LayerUPtr CreateConvLayerNeoML(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerNeoML>(settings); }

}