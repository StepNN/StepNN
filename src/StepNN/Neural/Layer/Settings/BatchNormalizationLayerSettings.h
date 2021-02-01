#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BatchNormalizationLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(BatchNormalizationLayerSettings)

	BatchNormalizationLayerSettings() = default;

	bool operator==(const BatchNormalizationLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const BatchNormalizationLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}