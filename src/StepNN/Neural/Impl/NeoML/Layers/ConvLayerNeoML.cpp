#include "NeoML/Dnn/Layers/ConvLayer.h"

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerNeoML.h"

namespace StepNN::Neural {

namespace {

class ConvLayerNeoML : public StepNN::Neural::BaseLayerNeoML<StepNN::Neural::ConvLayerSettings>
{
public:
	ConvLayerNeoML() = default;
	ConvLayerNeoML(const StepNN::Neural::BaseLayerSettings& settings)
	{
		StepNN::Neural::BaseLayerNeoML<StepNN::Neural::ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const StepNN::Neural::ConvLayerSettings& typedSettings)
	{
		StepNN::Neural::BaseLayerNeoML<StepNN::Neural::ConvLayerSettings>::SetSettings(typedSettings);

		/*if(!m_layer)
			m_layer = new NeoML::CConvLayer*/
	}

	~ConvLayerNeoML() = default;
};

}

LayerUPtr CreateConvLayerNeoML() { return std::unique_ptr<ConvLayerNeoML>(); }

LayerUPtr CreateConvLayerNeoML(const BaseLayerSettings& settings) { return std::make_unique<ConvLayerNeoML>(settings); }

}