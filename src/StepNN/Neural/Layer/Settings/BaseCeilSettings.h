#pragma once

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNN/Neural/Data/CeilMode.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseCeilSettings
{
public:
	bool operator==(const BaseCeilSettings& rhs) const noexcept { return m_ceilMode == rhs.m_ceilMode; }
	bool operator!=(const BaseCeilSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetCeilMode(CeilMode value) { m_ceilMode = value; }
	CeilMode GetCeilMode() const noexcept { return m_ceilMode; }

	bool IsEmpty() const noexcept { return m_ceilMode.isDefault(); }

protected:
	BaseCeilSettings() = default;
	virtual ~BaseCeilSettings() = default;

protected:
	Z<CeilMode, CeilMode::Ceil> m_ceilMode;
};

}