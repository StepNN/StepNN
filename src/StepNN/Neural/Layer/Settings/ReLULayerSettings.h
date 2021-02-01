#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API ReLULayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(ReLULayerSettings)

	ReLULayerSettings() = default;

	bool operator==(const ReLULayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const ReLULayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}