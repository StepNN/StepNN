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

	void SetSettings(const ConvLayerSettings& typedSettings)
	{
		BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings>::SetSettings(typedSettings);

		auto castedLayer = CheckCast<NeoML::CConvLayer>(m_layerImpl.Ptr());

		castedLayer->SetFilterCount		(m_typedSettings.GetOutChannels		()); // @todo check In or Out channels
		castedLayer->SetFilterWidth		(m_typedSettings.GetKernelWidth		());
		castedLayer->SetFilterHeight	(m_typedSettings.GetKernelHeight	());
		castedLayer->SetDilationWidth	(m_typedSettings.GetDilationWidth	());
		castedLayer->SetDilationHeight	(m_typedSettings.GetDilationHeight	());
		castedLayer->SetPaddingWidth	(m_typedSettings.GetPaddingWidth	());
		castedLayer->SetPaddingHeight	(m_typedSettings.GetPaddingHeight	());
		castedLayer->SetStrideWidth		(m_typedSettings.GetStrideWidth		());
		castedLayer->SetStrideHeight	(m_typedSettings.GetStrideHeight	());
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