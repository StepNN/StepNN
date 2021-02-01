#pragma once

#include "BaseLayerSettings.h"
#include "BasePoolingSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API MaxPoolingLayerSettings
	: public BaseLayerSettings
	, public BasePoolingSettings
{
public:
	LAYER_SETTINGS(MaxPoolingLayerSettings)

	MaxPoolingLayerSettings()
	{
		m_poolingMode = PoolingMode::Max;
	}

	bool operator==(const MaxPoolingLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const MaxPoolingLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}