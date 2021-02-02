#include "NeoML/Dnn/Layers/SoftmaxLayer.h"

#include "StepNN/Neural/Layer/Settings/SoftmaxLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SoftmaxLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>
{
public:
	SoftmaxLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CSoftmaxLayer, SoftmaxLayerSettings>::SetSettings(settings);
	}

	~SoftmaxLayerNeoML() = default;
};

}

LayerUPtr CreateSoftmaxLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_unique<SoftmaxLayerNeoML>(mathEngine, settings);
}

}