#include "NeoML/Dnn/Layers/BatchNormalizationLayer.h"

#include "StepNN/Neural/Layer/Settings/BatchNormalizationLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class BatchNormalizationLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>
{
public:
	BatchNormalizationLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>(mathEngine)
	{}

	BatchNormalizationLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CBatchNormalizationLayer, BatchNormalizationLayerSettings>::SetSettings(settings);
	}

	~BatchNormalizationLayerNeoML() = default;
};

}

LayerUPtr CreateBatchNormalizationLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if(settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<BatchNormalizationLayerNeoML>(mathEngine);
	else
		return std::make_unique<BatchNormalizationLayerNeoML>(settings, mathEngine);
}

}