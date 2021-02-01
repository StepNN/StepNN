#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API SoftmaxLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(SoftmaxLayerSettings)

	SoftmaxLayerSettings() = default;

	bool operator==(const SoftmaxLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const SoftmaxLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}