#include "NeoML/Dnn/Layers/SinkLayer.h"

#include "StepNN/Neural/Layer/Settings/OutputLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class OutputLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CSinkLayer, OutputLayerSettings>
{
public:
	OutputLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CSinkLayer, OutputLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CSinkLayer, OutputLayerSettings>::SetSettings(settings);
	}

	~OutputLayerNeoML() = default;
};

}

LayerUPtr CreateOutputLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_unique<OutputLayerNeoML>(mathEngine, settings);
}

}