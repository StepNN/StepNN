#pragma once

#include "BaseLayerSettings.h"

namespace StepNN {

class ConvLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(ConvLayerSettings)

	ConvLayerSettings() = default;

	bool operator==(const ConvLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const ConvLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return false; }

private:
	int kernelWidth;
	int kernelHeight;
	int count;
};

}