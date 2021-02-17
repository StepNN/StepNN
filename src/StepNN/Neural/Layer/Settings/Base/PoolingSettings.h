#pragma once

#include "StepNN/Neural/Data/PoolingMode.h"

#include "CeilSettings.h"
#include "DilationSettings.h"
#include "KernelSettings.h"
#include "PaddingSettings.h"
#include "StrideSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API PoolingSettings
	: public CeilSettings
	, virtual public DilationSettings<Size, Type>
	, virtual public KernelSettings<Size, Type>
	, virtual public PaddingSettings<Size, Type>
	, virtual public StrideSettings<Size, Type>
{
public:
	bool operator==(const PoolingSettings& rhs) const noexcept
	{
		return true
			&& m_poolingMode == rhs.m_poolingMode
			&& CeilSettings					::operator==(rhs)
			&& DilationSettings<Size, Type>	::operator==(rhs)
			&& KernelSettings<Size, Type>	::operator==(rhs)
			&& PaddingSettings<Size, Type>	::operator==(rhs)
			&& StrideSettings<Size, Type>	::operator==(rhs)
		;
	}
	bool operator!=(const PoolingSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetPoolingMode(PoolingMode value) { m_poolingMode = value; }
	PoolingMode GetPoolingMode() const noexcept { return m_poolingMode; }

	bool IsEmpty() const noexcept
	{
		return false;
		// @todo
		return m_poolingMode.isDefault() ||
			(	true
				&& CeilSettings					::IsEmpty()
				&& DilationSettings<Size, Type>	::IsEmpty()
				&& KernelSettings<Size, Type>	::IsEmpty()
				&& PaddingSettings<Size, Type>	::IsEmpty()
				&& StrideSettings<Size, Type>	::IsEmpty()
			);
	}

protected:
	PoolingSettings() = default;
	PoolingSettings(PoolingMode mode) : m_poolingMode(mode) {}
	~PoolingSettings() = default;

protected:
	Z<PoolingMode, PoolingMode::Undefined> m_poolingMode;
};

using PoolingSettings1D = PoolingSettings<1>;
using PoolingSettings2D = PoolingSettings<2>;
using PoolingSettings3D = PoolingSettings<3>;

}