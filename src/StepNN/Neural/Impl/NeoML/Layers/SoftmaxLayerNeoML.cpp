#include "NeoML/Dnn/Layers/SoftmaxLayer.h"

#include "StepNN/Neural/Layer/Settings/SoftmaxLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SoftmaxLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>
{
public:
	SoftmaxLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>(mathEngine)
	{}

	SoftmaxLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>::SetSettings(settings);
	}

	~SoftmaxLayerNeoML() = default;
};

}

LayerUPtr CreateSoftmaxLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<SoftmaxLayerNeoML>(mathEngine);
	else
		return std::make_unique<SoftmaxLayerNeoML>(settings, mathEngine);
}

}