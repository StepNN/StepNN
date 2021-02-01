#pragma once

#include "BaseLayerSettings.h"
#include "BasePoolingSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API MaxPoolingLayerSettings
	: public BaseLayerSettings
	, public BasePoolingSettings
{
public:
	LAYER_SETTINGS(MaxPoolingLayerSettings)

	MaxPoolingLayerSettings()
		: BasePoolingSettings(PoolingMode::Max)
	{}

	MaxPoolingLayerSettings(const std::string& layerId)
		: BaseLayerSettings(layerId)
		, BasePoolingSettings(PoolingMode::Max)
	{};

	bool operator==(const MaxPoolingLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings	::operator==(rhs)
			&& BasePoolingSettings	::operator==(rhs);
	}
	bool operator!=(const MaxPoolingLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return BasePoolingSettings::IsEmpty(); }
};

}