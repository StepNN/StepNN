#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTFImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ConvLayerTF : public BaseLayerTFImpl<ConvLayerSettings>
{
public:
	ConvLayerTF() = default;
	ConvLayerTF(const BaseLayerSettings& settings)
	{
		BaseLayerTFImpl<ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const ConvLayerSettings& typedSettings)
	{
		BaseLayerTFImpl<ConvLayerSettings>::SetSettings(typedSettings);
	}
};

}

LayerUPtr CreateConvLayerTF() { return std::unique_ptr<ConvLayerTF>(); }

LayerUPtr CreateConvLayerTF(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerTF>(settings); }

}