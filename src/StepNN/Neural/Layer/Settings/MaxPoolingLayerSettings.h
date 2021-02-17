#pragma once

#include "BaseLayerSettings.h"
#include "Base/PoolingSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size>
class STEPNN_API MaxPoolingLayerSettings
	: public BaseLayerSettings
	, public PoolingSettings<Size>
{
public:
	LAYER_SETTINGS(MaxPoolingLayerSettings)

	MaxPoolingLayerSettings()
		: PoolingSettings<Size>(PoolingMode::Max)
	{}

	MaxPoolingLayerSettings(const std::string& layerId)
		: BaseLayerSettings(layerId)
		, PoolingSettings<Size>(PoolingMode::Max)
	{};

	bool operator==(const MaxPoolingLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings	::operator==(rhs)
			&& PoolingSettings<Size>::operator==(rhs);
	}
	bool operator!=(const MaxPoolingLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept { return PoolingSettings<Size>::IsEmpty(); }
};

using MaxPooling1DLayerSettings = MaxPoolingLayerSettings<1>;
using MaxPooling2DLayerSettings = MaxPoolingLayerSettings<2>;
using MaxPooling3DLayerSettings = MaxPoolingLayerSettings<3>;

}