#include "NeoML/Dnn/Layers/ConvLayer.h"

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerNeoML.h"

namespace StepNN {

namespace {

class ConvLayerNeoML : public StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>
{
public:
	ConvLayerNeoML() = default;
	ConvLayerNeoML(const StepNN::BaseLayerSettings& settings)
	{
		StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::ConvLayerSettings& typedSettings)
	{
		StepNN::BaseLayerNeoML<StepNN::ConvLayerSettings>::SetSettings(typedSettings);

		/*if(!m_layer)
			m_layer = new NeoML::CConvLayer*/
	}

	~ConvLayerNeoML() = default;
};

}

LayerUPtr CreateConvLayerNeoML() { return std::unique_ptr<ConvLayerNeoML>(); }

LayerUPtr CreateConvLayerNeoML(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerNeoML>(settings); }

}