#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API CrossEntropyLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(CrossEntropyLayerSettings)

	CrossEntropyLayerSettings() = default;

	bool operator==(const CrossEntropyLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const CrossEntropyLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}