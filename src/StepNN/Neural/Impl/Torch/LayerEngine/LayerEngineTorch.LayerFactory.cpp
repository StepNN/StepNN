#include <map>

#include "StepNN/Utils/Algorithms/FindPair.h"

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"
#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "LayerEngineTorch.h"

namespace StepNN::Neural {

#define CREATE_LAYER(NAME) LayerUPtr Create##NAME(const BaseLayerSettings& settings);

CREATE_LAYER(ConvLayerTorch)

namespace {

using namespace StepNN::Neural;

template<typename T>
class LayerCreator
{
	using BaseSettingsCRef = const BaseLayerSettings&;
public:
	LayerUPtr Create(const T& param)
	{
		Initialize();

		if constexpr (std::is_same_v<T, std::string>)
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param);
			return creator != std::cend(creators) ? creator->second(EmptySettings()) : nullptr;
		}
		else
		{
			const auto creator = FindPairIteratorByFirst(std::cbegin(creators), std::cend(creators), param.GetSettingsID());
			return creator != std::cend(creators) ? creator->second(param) : nullptr;
		}
	}

private:
	void Initialize()
	{
		static bool isInitialized = false;
		RETURN_IF(isInitialized);

		creators = {
			{ ConvLayerSettings::SETTINGS_ID, static_cast<LayerUPtr(*)(BaseSettingsCRef)>(CreateConvLayerTorch) },
		};

		isInitialized = true;
	}

private:
	std::map<std::string, std::function<LayerUPtr(BaseSettingsCRef)>> creators;
};

LayerCreator<std::string> g_idCreator;
LayerCreator<BaseLayerSettings> g_settingsCreator;

}

//.............................................................................

LayerUPtr LayerEngineTorch::CreateLayer(const std::string& layerID) const
{
	return g_idCreator.Create(layerID);
}

//.............................................................................

LayerUPtr LayerEngineTorch::CreateLayer(const BaseLayerSettings& settings) const
{
	return nullptr;
}

}