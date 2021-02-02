#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API ReLULayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(ReLULayerSettings)

	ReLULayerSettings() = default;
	ReLULayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const ReLULayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const ReLULayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}