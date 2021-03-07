#include "NeoML/Dnn/Layers/ConvLayer.h"

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

#define SET_SETTINGS(settings)																\
if constexpr (Size == 2)																	\
	BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings<Size>>::SetSettings(##settings);\
else																						\
	static_assert(false, "Incorrect size")

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

template<size_t Size>
class ConvLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings<Size>>
{
public:
	ConvLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CConvLayer, ConvLayerSettings<Size>>(mathEngine)
	{
		SET_SETTINGS(settings);
	}

	void SetSettings(const ConvLayerSettings<Size>& typedSettings) override
	{
		SET_SETTINGS(typedSettings);

		auto castedLayer = CheckCast<NeoML::CConvLayer>(m_layerImpl.Ptr());

		castedLayer->SetFilterCount(m_typedSettings.GetOutChannels()); // @todo check In or Out channels
		castedLayer->SetFilterWidth(m_typedSettings.GetKernel(0));
		castedLayer->SetFilterHeight(m_typedSettings.GetKernel(1));

		if (m_typedSettings.HasDilation())
		{
			castedLayer->SetDilationWidth(m_typedSettings.GetDilation(0));
			castedLayer->SetDilationHeight(m_typedSettings.GetDilation(1));
		}

		if (m_typedSettings.HasPadding())
		{
			castedLayer->SetPaddingWidth(m_typedSettings.GetPadding(0));
			castedLayer->SetPaddingHeight(m_typedSettings.GetPadding(1));
		}

		if (m_typedSettings.HasStride())
		{
			castedLayer->SetStrideWidth(m_typedSettings.GetStride(0));
			castedLayer->SetStrideHeight(m_typedSettings.GetStride(1));
		}
	}

	~ConvLayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateConv1DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { assert(!Defs::NOT_IMPL_STR); return nullptr; }
std::shared_ptr<ILayer> CreateConv2DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { return std::make_shared<ConvLayerNeoML<2>>(mathEngine, settings); }
std::shared_ptr<ILayer> CreateConv3DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { assert(!Defs::NOT_IMPL_STR); return nullptr; }

}