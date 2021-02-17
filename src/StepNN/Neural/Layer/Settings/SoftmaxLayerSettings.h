#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"
#include "Base/DimensionSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API SoftmaxLayerSettings
	: public BaseLayerSettings
	, public DimensionSettings1D
{
public:
	LAYER_SETTINGS(SoftmaxLayerSettings)

	SoftmaxLayerSettings() = default;
	SoftmaxLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const SoftmaxLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const SoftmaxLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return DimensionSettings1D::IsEmpty(); }
};

}