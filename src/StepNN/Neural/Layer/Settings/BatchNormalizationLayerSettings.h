#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BatchNormalizationLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(BatchNormalizationLayerSettings)

	BatchNormalizationLayerSettings() = default;
	BatchNormalizationLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const BatchNormalizationLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const BatchNormalizationLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() { return false; }
};

}