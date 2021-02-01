#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API SourceLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(SourceLayerSettings)

	SourceLayerSettings() = default;

	bool operator==(const SourceLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const SourceLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}