#include "NeoML/Dnn/Layers/LossLayer.h"

#include "StepNN/Neural/Layer/Settings/CrossEntropyLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class CrossEntropyLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>
{
public:
	CrossEntropyLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>(mathEngine)
	{}

	CrossEntropyLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>::SetSettings(settings);
	}

	~CrossEntropyLayerNeoML() = default;
};

}

LayerUPtr CreateCrossEntropyLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<CrossEntropyLayerNeoML>(mathEngine);
	else
		return std::make_unique<CrossEntropyLayerNeoML>(settings, mathEngine);
}

}