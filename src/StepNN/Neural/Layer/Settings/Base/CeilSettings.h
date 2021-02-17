#pragma once

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNN/Neural/Data/CeilMode.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API CeilSettings
{
public:
	bool operator==(const CeilSettings& rhs) const noexcept { return m_ceilMode == rhs.m_ceilMode; }
	bool operator!=(const CeilSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetCeilMode(CeilMode value) { m_ceilMode = value; }
	CeilMode GetCeilMode() const noexcept { return m_ceilMode; }

	bool HasCeil() const noexcept { return !m_ceilMode.isDefault(); }

protected:
	CeilSettings() = default;
	virtual ~CeilSettings() = default;

protected:
	Z<CeilMode, CeilMode::Undefined> m_ceilMode;
};

}