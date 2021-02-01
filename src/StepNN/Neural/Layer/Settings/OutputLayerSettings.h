#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API OutputLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(OutputLayerSettings)

	OutputLayerSettings() = default;

	bool operator==(const OutputLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const OutputLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}