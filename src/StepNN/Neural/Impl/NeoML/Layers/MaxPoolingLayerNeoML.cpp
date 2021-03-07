#include "NeoML/Dnn/Layers/PoolingLayer.h"

#include "StepNN/Neural/Layer/Settings/MaxPoolingLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

#define SET_SETTINGS(settings)																			\
if constexpr (Size == 2)																				\
	BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings<Size>>::SetSettings(##settings);\
else																									\
	static_assert(false, "Incorrect size")

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

template<size_t Size>
class MaxPoolingLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings<Size>>
{
public:
	MaxPoolingLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings)
		: BaseLayerNeoMLImpl<NeoML::CMaxPoolingLayer, MaxPoolingLayerSettings<Size>>(mathEngine)
	{
		SET_SETTINGS(settings);
	}

	void SetSettings(const MaxPoolingLayerSettings<Size>& typedSettings)
	{
		SET_SETTINGS(typedSettings);

		auto castedLayer = CheckCast<NeoML::CMaxPoolingLayer>(m_layerImpl.Ptr());

		castedLayer->SetFilterWidth(m_typedSettings.GetKernel(0));
		castedLayer->SetFilterHeight(m_typedSettings.GetKernel(1));

		if (m_typedSettings.HasStride())
		{
			castedLayer->SetStrideWidth(m_typedSettings.GetStride(0));
			castedLayer->SetStrideHeight(m_typedSettings.GetStride(1));
		}
	}

	~MaxPoolingLayerNeoML() = default;
};

}

std::shared_ptr<ILayer> CreateMaxPooling1DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { assert(!Defs::NOT_IMPL_STR); return nullptr; }
std::shared_ptr<ILayer> CreateMaxPooling2DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { return std::make_shared<MaxPoolingLayerNeoML<2>>(mathEngine, settings); }
std::shared_ptr<ILayer> CreateMaxPooling3DLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings) { assert(!Defs::NOT_IMPL_STR); return nullptr; }

}