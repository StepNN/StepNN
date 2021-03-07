#include <map>

#include "StepNN/Utils/Algorithms/FindPair.h"

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"
#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "LayerEngineTF.h"

namespace StepNN::Neural {

#define CREATE_LAYER(NAME) std::shared_ptr<Interfaces::ILayer> Create##NAME(const BaseLayerSettings& settings);

CREATE_LAYER(Conv2DLayerTF)

namespace {

template<typename T>
class LayerCreator
{
	using BaseSettingsCRef = const BaseLayerSettings&;
public:
	std::shared_ptr<Interfaces::ILayer> Create(const T& param)
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
			//{ StepNN::Neural::ConvLayerSettings::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateConvLayerTF) },
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

std::shared_ptr<ILayer> LayerEngineTF::CreateLayer(const std::string& layerID)
{
	return g_idCreator.Create(layerID);
}

//.............................................................................

std::shared_ptr<ILayer> LayerEngineTF::CreateLayer(const BaseLayerSettings& settings)
{
	return g_settingsCreator.Create(settings);
}

}