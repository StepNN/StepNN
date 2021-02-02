#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API CrossEntropyLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(CrossEntropyLayerSettings)

	CrossEntropyLayerSettings() = default;
	CrossEntropyLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const CrossEntropyLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const CrossEntropyLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}