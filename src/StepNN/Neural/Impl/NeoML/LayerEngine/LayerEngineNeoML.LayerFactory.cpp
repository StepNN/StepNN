#include <map>

#include "StepNN/Types/CommonDefs.h"

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

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "LayerEngineNeoML.h"

namespace StepNN::Neural {

#define CREATE_LAYER(NAME) LayerUPtr Create##NAME(NeoMathEnginePtr, const BaseLayerSettings&);

CREATE_LAYER(BatchNormalizationLayerNeoML)
CREATE_LAYER(Conv1DLayerNeoML)
CREATE_LAYER(Conv2DLayerNeoML)
CREATE_LAYER(Conv3DLayerNeoML)
CREATE_LAYER(CrossEntropyLayerNeoML)
CREATE_LAYER(DenseLayerNeoML)
CREATE_LAYER(FlattenLayerNeoML)
CREATE_LAYER(MaxPooling1DLayerNeoML)
CREATE_LAYER(MaxPooling2DLayerNeoML)
CREATE_LAYER(MaxPooling3DLayerNeoML)
CREATE_LAYER(OutputLayerNeoML)
CREATE_LAYER(ReLULayerNeoML)
CREATE_LAYER(SoftmaxLayerNeoML)
CREATE_LAYER(SourceLayerNeoML)

namespace {

using namespace StepNN::Neural;

template<typename T>
class LayerCreator
{
	using BaseSettingsCRef = const BaseLayerSettings&;
public:
	LayerUPtr Create(const T& param, NeoMathEnginePtr mathEngine)
	{
		Initialize();

		if constexpr (std::is_same_v<T, std::string>)
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param);
			return creator != std::cend(creators) ? creator->second(mathEngine, EmptySettings()) : nullptr;
		}
		else
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param.GetSettingsID());
			return creator != std::cend(creators) ? creator->second(mathEngine, param) : nullptr;
		}
	}

private:
	void Initialize()
	{
		static bool isInitialized = false;
		RETURN_IF(isInitialized);

		creators = {
			{ BatchNormalizationLayerSettings	::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateBatchNormalizationLayerNeoML	) },
			{ Conv1DLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateConv1DLayerNeoML				) },
			{ Conv2DLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateConv2DLayerNeoML				) },
			{ Conv3DLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateConv3DLayerNeoML				) },
			{ CrossEntropyLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateCrossEntropyLayerNeoML		) },
			{ DenseLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateDenseLayerNeoML				) },
			{ FlattenLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateFlattenLayerNeoML			) },
			{ MaxPooling1DLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateMaxPooling1DLayerNeoML		) },
			{ MaxPooling2DLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateMaxPooling2DLayerNeoML		) },
			{ MaxPooling3DLayerSettings			::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateMaxPooling3DLayerNeoML		) },
			{ OutputLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateOutputLayerNeoML				) },
			{ ReLULayerSettings					::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateReLULayerNeoML				) },
			{ SoftmaxLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateSoftmaxLayerNeoML			) },
			{ SourceLayerSettings				::SETTINGS_ID, static_cast<LayerUPtr(*)(NeoMathEnginePtr, BaseSettingsCRef)>(CreateSourceLayerNeoML				) },
		};
		isInitialized = true;
	}

private:
	std::map<std::string, std::function<LayerUPtr(NeoMathEnginePtr, BaseSettingsCRef)>> creators;
};

LayerCreator<std::string> g_idCreator;
LayerCreator<StepNN::Neural::BaseLayerSettings> g_settingsCreator;

}

//.............................................................................

LayerUPtr LayerEngineNeoML::CreateLayer(const std::string& layerID)
{
	return g_idCreator.Create(layerID, GetMathEngine().get());
}

//.............................................................................

LayerUPtr LayerEngineNeoML::CreateLayer(const BaseLayerSettings& settings)
{
	return g_settingsCreator.Create(settings, GetMathEngine().get());
}

}