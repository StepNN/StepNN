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

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "StepNN/Neural/Impl/Torch/Layers/BaseLayerTorch.h"

#include "LayerEngineTorch.h"

namespace StepNN::Neural {

#define CREATE_LAYER(NAME) LayerUPtr Create##NAME(const BaseLayerSettings& settings);

CREATE_LAYER(BatchNormalizationLayerTorch)
CREATE_LAYER(Conv1DLayerTorch)
CREATE_LAYER(Conv2DLayerTorch)
CREATE_LAYER(Conv3DLayerTorch)
CREATE_LAYER(CrossEntropyLayerTorch)
CREATE_LAYER(DenseLayerTorch)
CREATE_LAYER(FlattenLayerTorch)
CREATE_LAYER(MaxPooling1DLayerTorch)
CREATE_LAYER(MaxPooling2DLayerTorch)
CREATE_LAYER(MaxPooling3DLayerTorch)
CREATE_LAYER(OutputLayerTorch)
CREATE_LAYER(ReLULayerTorch)
CREATE_LAYER(SoftmaxLayerTorch)
CREATE_LAYER(SourceLayerTorch)

namespace {

using namespace StepNN::Neural;
using namespace StepNN::Neural::Interfaces;

template<typename T>
class LayerCreator
{
	using BaseSettingsCRef = const BaseLayerSettings&;
public:
	std::shared_ptr<ILayer> Create(const T& param)
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
			{ BatchNormalizationLayerSettings	::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateBatchNormalizationLayerTorch	) },
			{ Conv1DLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateConv1DLayerTorch				) },
			{ Conv2DLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateConv2DLayerTorch				) },
			{ Conv3DLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateConv3DLayerTorch				) },
			{ CrossEntropyLayerSettings			::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateCrossEntropyLayerTorch			) },
			{ DenseLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateDenseLayerTorch				) },
			{ FlattenLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateFlattenLayerTorch				) },
			{ MaxPooling1DLayerSettings			::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateMaxPooling1DLayerTorch			) },
			{ MaxPooling2DLayerSettings			::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateMaxPooling2DLayerTorch			) },
			{ MaxPooling3DLayerSettings			::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateMaxPooling3DLayerTorch			) },
			{ OutputLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateOutputLayerTorch				) },
			{ ReLULayerSettings					::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateReLULayerTorch					) },
			{ SoftmaxLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateSoftmaxLayerTorch				) },
			{ SourceLayerSettings				::SETTINGS_ID, static_cast<std::shared_ptr<ILayer>(*)(BaseSettingsCRef)>(CreateSourceLayerTorch				) },
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

std::shared_ptr<ILayer> LayerEngineTorch::CreateLayer(const std::string& layerID)
{
	auto layer = g_idCreator.Create(layerID);
	IUserController<IUserTorchSequential>::AddUser(dynamic_cast<BaseLayerTorch*>(layer.get()));
	return layer;
}

//.............................................................................

std::shared_ptr<ILayer> LayerEngineTorch::CreateLayer(const BaseLayerSettings& settings)
{
	auto layer = g_settingsCreator.Create(settings);
	IUserController<IUserTorchSequential>::AddUser(dynamic_cast<BaseLayerTorch*>(layer.get()));
	return layer;
}

}