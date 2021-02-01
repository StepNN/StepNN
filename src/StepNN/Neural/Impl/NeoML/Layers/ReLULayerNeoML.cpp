#include "NeoML/Dnn/Layers/ActivationLayers.h"

#include "StepNN/Neural/Layer/Settings/ReLULayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ReLULayerNeoML : public BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>
{
public:
	ReLULayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>(mathEngine)
	{}

	ReLULayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>::SetSettings(settings);
	}

	~ReLULayerNeoML() = default;
};

}

LayerUPtr CreateReLULayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<ReLULayerNeoML>(mathEngine);
	else
		return std::make_unique<ReLULayerNeoML>(settings, mathEngine);
}

}