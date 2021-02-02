#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"
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
	bool operator==(const BasePoolingSettings& rhs) const noexcept
	{
		return true
			&& m_poolingMode == rhs.m_poolingMode
			&& BaseCeilSettings		::operator==(rhs)
			&& BaseDilationSettings	::operator==(rhs)
			&& BaseKernelSettings	::operator==(rhs)
			&& BasePaddingSettings	::operator==(rhs)
			&& BaseStrideSettings	::operator==(rhs)
		;
	}
	bool operator!=(const BasePoolingSettings& rhs) const noexcept { return !(*this == rhs); }

	//void SetPoolingMode(PoolingMode value) { m_poolingMode = value; }
	PoolingMode GetPoolingMode() const noexcept { return m_poolingMode; }

	bool IsEmpty() const noexcept
	{
		return m_poolingMode.isDefault() ||
			(	true
				&& BaseCeilSettings		::IsEmpty()
				&& BaseDilationSettings	::IsEmpty()
				&& BaseKernelSettings	::IsEmpty()
				&& BasePaddingSettings	::IsEmpty()
				&& BaseStrideSettings	::IsEmpty()
			);
	}

protected:
	BasePoolingSettings() = default;
	BasePoolingSettings(PoolingMode mode) : m_poolingMode(mode) {}
	virtual ~BasePoolingSettings() = default;

protected:
	Z<PoolingMode, PoolingMode::Undefined> m_poolingMode;
};

}