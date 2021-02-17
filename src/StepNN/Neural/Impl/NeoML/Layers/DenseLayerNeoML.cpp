#include "NeoML/Dnn/Layers/FullyConnectedLayer.h"

#include "StepNN/Neural/Layer/Settings/DenseLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class DenseLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CFullyConnectedLayer, DenseLayerSettings>
{
public:
	DenseLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CFullyConnectedLayer, DenseLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CFullyConnectedLayer, DenseLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const DenseLayerSettings& typedSettings)
	{
		BaseLayerNeoMLImpl<NeoML::CFullyConnectedLayer, DenseLayerSettings>::SetSettings(typedSettings);

		auto castedLayer = CheckCast<NeoML::CFullyConnectedLayer>(m_layerImpl.Ptr());

		castedLayer->SetNumberOfElements(m_typedSettings.GetOutChannels());
	}

	~DenseLayerNeoML() = default;
};

}

LayerUPtr CreateDenseLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
{
	return std::make_unique<DenseLayerNeoML>(mathEngine, settings);
}

}