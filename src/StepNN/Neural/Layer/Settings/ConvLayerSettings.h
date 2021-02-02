#pragma once

#include <utility>

#include "StepNN/Neural/Data/PaddingMode.h"

#include "BaseLayerSettings.h"
#include "BaseChannelsSettings.h"
#include "BaseDilationSettings.h"
#include "BaseKernelSettings.h"
#include "BasePaddingSettings.h"
#include "BaseStrideSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API ConvLayerSettings
	: public BaseLayerSettings
	, public BaseChannelsSettings
	, public BaseDilationSettings
	, public BaseKernelSettings
	, public BasePaddingSettings
	, public BaseStrideSettings
{
public:
	LAYER_SETTINGS(ConvLayerSettings)

	ConvLayerSettings() = default;
	ConvLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const ConvLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings	::operator==(rhs)
			&& BaseChannelsSettings	::operator==(rhs)
			&& BaseDilationSettings	::operator==(rhs)
			&& BaseKernelSettings	::operator==(rhs)
			&& BasePaddingSettings	::operator==(rhs)
			&& BaseStrideSettings	::operator==(rhs)
			;
	}
	bool operator!=(const ConvLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept
	{
		return true
			&& BaseChannelsSettings	::IsEmpty()
			&& BaseDilationSettings	::IsEmpty()
			&& BaseKernelSettings	::IsEmpty()
			&& BasePaddingSettings	::IsEmpty()
			&& BaseStrideSettings	::IsEmpty()
			;
	}
};

}