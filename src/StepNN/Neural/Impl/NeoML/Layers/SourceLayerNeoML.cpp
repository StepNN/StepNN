#include "NeoML/Dnn/Layers/SourceLayer.h"

#include "StepNN/Neural/Layer/Settings/SourceLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SourceLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>
{
public:
	SourceLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>(mathEngine)
	{}

	SourceLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>::SetSettings(settings);
	}

	~SourceLayerNeoML() = default;
};

}

LayerUPtr CreateSourceLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<SourceLayerNeoML>(mathEngine);
	else
		return std::make_unique<SourceLayerNeoML>(settings, mathEngine);
}

}