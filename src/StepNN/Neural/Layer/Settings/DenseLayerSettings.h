#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"
#include "Base/BiasSettings.h"
#include "Base/ChannelsSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API DenseLayerSettings
	: public BaseLayerSettings
	, public BiasSettings
	, public ChannelsSettings
{
public:
	LAYER_SETTINGS(DenseLayerSettings)

	DenseLayerSettings() = default;
	DenseLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const DenseLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings	::operator==(rhs)
			&& BiasSettings			::operator==(rhs)
			&& ChannelsSettings		::operator==(rhs)
			;
	}
	bool operator!=(const DenseLayerSettings& rhs) const noexcept { return !(*this == rhs); }
};

}