#include "NeoML/Dnn/Layers/BatchNormalizationLayer.h"

#include "StepNN/Neural/Layer/Settings/BatchNormalizationLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class BatchNormalizationLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>
{
public:
	BatchNormalizationLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>::SetSettings(settings);
	}

	~BatchNormalizationLayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateBatchNormalizationLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_shared<BatchNormalizationLayerNeoML>(mathEngine, settings);
}

}