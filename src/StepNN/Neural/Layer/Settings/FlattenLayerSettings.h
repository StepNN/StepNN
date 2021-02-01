#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API FlattenLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(FlattenLayerSettings)

	FlattenLayerSettings() = default;
	FlattenLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const FlattenLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const FlattenLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}