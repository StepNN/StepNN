#include "NeoML/Dnn/Layers/PoolingLayer.h"

#include "StepNN/Neural/Layer/Settings/MaxPoolingLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class MaxPoolingLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings>
{
public:
	MaxPoolingLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings>(mathEngine)
	{}

	MaxPoolingLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const MaxPoolingLayerSettings& typedSettings)
	{
		BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings>::SetSettings(typedSettings);

		auto castedLayer = CheckCast<NeoML::CMaxPoolingLayer>(m_layerImpl.Ptr());

		castedLayer->SetFilterWidth(m_typedSettings.GetKernelWidth());
		castedLayer->SetFilterHeight(m_typedSettings.GetKernelHeight());

		// if settings don't have a stride - don't set them (NeoML has assert for stride <= 0)
		if (m_typedSettings.GetStrideWidth() > 0)
			castedLayer->SetStrideWidth(m_typedSettings.GetStrideWidth());
		if (m_typedSettings.GetStrideHeight() > 0)
			castedLayer->SetStrideHeight(m_typedSettings.GetStrideHeight());
	}

	~MaxPoolingLayerNeoML() = default;
};

}

LayerUPtr CreateMaxPoolingLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<MaxPoolingLayerNeoML>(mathEngine);
	else
		return std::make_unique<MaxPoolingLayerNeoML>(settings, mathEngine);
}

}