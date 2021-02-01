#include "NeoML/Dnn/Layers/ConvLayer.h"

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class ConvLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>
{
public:
	ConvLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>(mathEngine)
	{}

	ConvLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const ConvLayerSettings& typedSettings) override
	{
		BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>::SetSettings(typedSettings);

		auto castedLayer = CheckCast<NeoML::CConvLayer>(m_layerImpl.Ptr());

		castedLayer->SetFilterCount		(m_typedSettings.GetOutChannels		()); // @todo check In or Out channels
		castedLayer->SetFilterWidth		(m_typedSettings.GetKernelWidth		());
		castedLayer->SetFilterHeight	(m_typedSettings.GetKernelHeight	());

		if (m_typedSettings.GetDilationWidth() > 0)
			castedLayer->SetDilationWidth(m_typedSettings.GetDilationWidth());
		if (m_typedSettings.GetDilationHeight() > 0)
			castedLayer->SetDilationHeight(m_typedSettings.GetDilationHeight());
		if (m_typedSettings.GetPaddingWidth() > 0)
			castedLayer->SetPaddingWidth(m_typedSettings.GetPaddingWidth());
		if (m_typedSettings.GetPaddingHeight() > 0)
			castedLayer->SetPaddingHeight(m_typedSettings.GetPaddingHeight());
		if (m_typedSettings.GetStrideWidth() > 0)
			castedLayer->SetStrideWidth(m_typedSettings.GetStrideWidth());
		if (m_typedSettings.GetStrideHeight() > 0)
			castedLayer->SetStrideHeight(m_typedSettings.GetStrideHeight());
	}

	~ConvLayerNeoML() = default;
};

}

LayerUPtr CreateConvLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<ConvLayerNeoML>(mathEngine);
	else
		return std::make_unique<ConvLayerNeoML>(settings, mathEngine);
}

}