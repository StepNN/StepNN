#include "NeoML/Dnn/Layers/ActivationLayers.h"

#include "StepNN/Neural/Layer/Settings/ReLULayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ReLULayerNeoML : public BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>
{
public:
	ReLULayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CReLULayer, ReLULayerSettings>::SetSettings(settings);
	}

	~ReLULayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateReLULayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_shared<ReLULayerNeoML>(mathEngine, settings);
}

}