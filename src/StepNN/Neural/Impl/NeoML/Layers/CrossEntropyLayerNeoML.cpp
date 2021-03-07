#include "NeoML/Dnn/Layers/LossLayer.h"

#include "StepNN/Neural/Layer/Settings/CrossEntropyLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class CrossEntropyLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>
{
public:
	CrossEntropyLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CCrossEntropyLossLayer, CrossEntropyLayerSettings>::SetSettings(settings);
	}

	~CrossEntropyLayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateCrossEntropyLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_shared<CrossEntropyLayerNeoML>(mathEngine, settings);
}

}