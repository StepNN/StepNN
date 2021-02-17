#pragma once

#include <utility>

#include "StepNN/Neural/Data/PaddingMode.h"

#include "BaseLayerSettings.h"
#include "Base/BiasSettings.h"
#include "Base/ChannelsSettings.h"
#include "Base/DilationSettings.h"
#include "Base/KernelSettings.h"
#include "Base/PaddingSettings.h"
#include "Base/StrideSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<int Size>
class STEPNN_API ConvLayerSettings
	: public BaseLayerSettings
	, public BiasSettings
	, public ChannelsSettings
	, public DilationSettings<Size>
	, public KernelSettings<Size>
	, public PaddingSettings<Size>
	, public StrideSettings<Size>
{
public:
	LAYER_SETTINGS(ConvLayerSettings)

	ConvLayerSettings() = default;
	ConvLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const ConvLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings		::operator==(rhs)
			&& BiasSettings				::operator==(rhs)
			&& ChannelsSettings			::operator==(rhs)
			&& DilationSettings<Size>	::operator==(rhs)
			&& KernelSettings<Size>		::operator==(rhs)
			&& PaddingSettings<Size>	::operator==(rhs)
			&& StrideSettings<Size>		::operator==(rhs)
			;
	}
	bool operator!=(const ConvLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	bool IsEmpty() const noexcept
	{
		return !(true
			&& ChannelsSettings			::HasChannels()
			&& KernelSettings<Size>		::HasKernel()
			//&& DilationSettings<Size>	::IsEmpty()
			//&& PaddingSettings<Size>	::IsEmpty()
			//&& StrideSettings<Size>	::IsEmpty()
			);
	}
};

using Conv1DLayerSettings = ConvLayerSettings<1>;
using Conv2DLayerSettings = ConvLayerSettings<2>;
using Conv3DLayerSettings = ConvLayerSettings<3>;

}