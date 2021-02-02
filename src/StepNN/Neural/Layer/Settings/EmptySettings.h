#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API EmptySettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(EmptySettings)

	EmptySettings() = default;

	bool operator==(const EmptySettings& rhs) const noexcept { return true; }
	bool operator!=(const EmptySettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}