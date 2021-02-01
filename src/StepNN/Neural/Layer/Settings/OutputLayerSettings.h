#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API OutputLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(OutputLayerSettings)

	OutputLayerSettings() = default;
	OutputLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const OutputLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const OutputLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}