#include <map>

#include "StepNN/Utils/Algorithms/FindPair.h"

#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "LayerEngineTorch.h"

namespace StepNN::Neural {

#define CREATE_LAYER_BY_ID(NAME) LayerUPtr Create##NAME();
#define CREATE_LAYER_BY_SETTINGS(NAME) LayerUPtr Create##NAME(const BaseLayerSettings& settings);

#define CREATE_LAYER(NAME) \
CREATE_LAYER_BY_ID(##NAME) \
CREATE_LAYER_BY_SETTINGS(##NAME)

CREATE_LAYER(ConvLayerTorch)

namespace {

template<typename T, typename FuncParamType = void>
class LayerCreator
{
public:
	LayerUPtr Create(const T& param)
	{
		if constexpr (std::is_same_v<T, std::string>)
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param);
			return creator == std::cend(creators) ? creator->second() : nullptr;
		}
		else
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param.GetSettingsID());
			return creator == std::cend(creators) ? creator->second(param) : nullptr;
		}
	}

private:
	std::map<std::string, std::function<LayerUPtr(FuncParamType)>> creators {
		{ StepNN::Neural::ConvLayerSettings::SETTINGS_ID, static_cast<LayerUPtr(*)(FuncParamType)>(CreateConvLayerTorch) },
	};
};

LayerCreator<std::string> g_idCreator;
LayerCreator<StepNN::Neural::BaseLayerSettings, const StepNN::Neural::BaseLayerSettings&> g_settingsCreator;

}

//.............................................................................

LayerUPtr LayerEngineTorch::CreateLayer(const std::string& layerID) const
{
	//return g_idCreator.Create(layerID);
	return nullptr;
}

//.............................................................................

LayerUPtr LayerEngineTorch::CreateLayer(const BaseLayerSettings& settings) const
{
	//return g_settingsCreator.Create(settings);
	return nullptr;
}

}