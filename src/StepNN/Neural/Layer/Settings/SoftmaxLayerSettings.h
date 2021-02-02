#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API SoftmaxLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(SoftmaxLayerSettings)

	SoftmaxLayerSettings() = default;
	SoftmaxLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const SoftmaxLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const SoftmaxLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }
};

}