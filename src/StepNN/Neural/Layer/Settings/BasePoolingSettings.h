#pragma once

#include "StepNN/Neural/Data/PoolingMode.h"

#include "BaseCeilSettings.h"
#include "BaseDilationSettings.h"
#include "BaseKernelSettings.h"
#include "BasePaddingSettings.h"
#include "BaseStrideSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BasePoolingSettings
	: public BaseCeilSettings
	, public BaseDilationSettings
	, public BaseKernelSettings
	, public BasePaddingSettings
	, public BaseStrideSettings
{
public:
	bool operator==(const BasePoolingSettings& rhs) const noexcept { return true; }
	bool operator!=(const BasePoolingSettings& rhs) const noexcept { return !(*this == rhs); }

	//void SetPoolingMode(PoolingMode value) { m_poolingMode = value; }
	PoolingMode GetPoolingMode() const noexcept { return m_poolingMode; }

protected:
	BasePoolingSettings() = default;
	virtual ~BasePoolingSettings() = default;

protected:
	PoolingMode m_poolingMode;
};

}