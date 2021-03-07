#include "NeoML/Dnn/Layers/SourceLayer.h"

#include "StepNN/Neural/Layer/Settings/SourceLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SourceLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>
{
public:
	SourceLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CSourceLayer, SourceLayerSettings>::SetSettings(settings);
	}

	~SourceLayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateSourceLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_shared<SourceLayerNeoML>(mathEngine, settings);
}

}