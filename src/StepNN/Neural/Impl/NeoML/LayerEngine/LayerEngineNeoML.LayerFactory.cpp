#include <map>

#include "StepNN/Utils/Algorithms/FindPair.h"

#include "StepNN/Neural/Layer/Settings/BatchNormalizationLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/CrossEntropyLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/DenseLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/FlattenLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/MaxPoolingLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/OutputLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/ReLULayerSettings.h"
#include "StepNN/Neural/Layer/Settings/SoftmaxLayerSettings.h"
#include "StepNN/Neural/Layer/Settings/SourceLayerSettings.h"

#include "LayerEngineNeoML.h"

namespace StepNN::Neural {

#define CREATE_LAYER(NAME) LayerUPtr Create##NAME(NeoMathEnginePtr, const BaseLayerSettings& settings);

CREATE_LAYER(BatchNormalizationLayerNeoML)
CREATE_LAYER(ConvLayerNeoML)
CREATE_LAYER(CrossEntropyLayerNeoML)
CREATE_LAYER(DenseLayerNeoML)
CREATE_LAYER(FlattenLayerNeoML)
CREATE_LAYER(MaxPoolingLayerNeoML)
CREATE_LAYER(OutputLayerNeoML)
CREATE_LAYER(ReLULayerNeoML)
CREATE_LAYER(SoftmaxLayerNeoML)
CREATE_LAYER(SourceLayerNeoML)

namespace {

template<typename T>
class LayerCreator
{
	using BaseSettingsCRef = const BaseLayerSettings&;
public:
	LayerUPtr Create(const T& param, NeoMathEnginePtr mathEngine)
	{
		if constexpr (std::is_same_v<T, std::string>)
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param);
			return creator == std::cend(creators) ? creator->second(mathEngine) : nullptr;
		}
		else
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param.GetSettingsID());
			return creator == std::cend(creators) ? creator->second(mathEngine, param) : nullptr;
		}
	}

private:
	std::map<std::string, std::function<LayerUPtr(NeoMathEnginePtr, BaseSettingsCRef)>> creators {
		{ StepNN::Neural::BatchNormalizationLayerSettings	::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateBatchNormalizationLayerNeoML	) },
		{ StepNN::Neural::ConvLayerSettings					::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateConvLayerNeoML				) },
		{ StepNN::Neural::CrossEntropyLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateCrossEntropyLayerNeoML		) },
		{ StepNN::Neural::DenseLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateDenseLayerNeoML				) },
		{ StepNN::Neural::FlattenLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateFlattenLayerNeoML			) },
		{ StepNN::Neural::MaxPoolingLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateMaxPoolingLayerNeoML			) },
		{ StepNN::Neural::OutputLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateOutputLayerNeoML				) },
		{ StepNN::Neural::ReLULayerSettings					::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateReLULayerNeoML				) },
		{ StepNN::Neural::SoftmaxLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateSoftmaxLayerNeoML			) },
		{ StepNN::Neural::SourceLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateSourceLayerNeoML				) },
	};
};

LayerCreator<std::string> g_idCreator;
LayerCreator<StepNN::Neural::BaseLayerSettings> g_settingsCreator;

}

//.............................................................................

LayerUPtr LayerEngineNeoML::CreateLayer(const std::string& layerID) const
{
	return g_idCreator.Create(layerID, m_mathEngine);
}

//.............................................................................

LayerUPtr LayerEngineNeoML::CreateLayer(const BaseLayerSettings& settings) const
{
	return g_settingsCreator.Create(settings, m_mathEngine);
}

}