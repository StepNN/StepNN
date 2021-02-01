#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API SourceLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(SourceLayerSettings)

	SourceLayerSettings() = default;
	SourceLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const SourceLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const SourceLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}