#pragma once

#include "StepNN/Neural/Data/CeilMode.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseCeilSettings
{
public:
	bool operator==(const BaseCeilSettings& rhs) const noexcept { return true; }
	bool operator!=(const BaseCeilSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetCeilMode(CeilMode value) { m_ceilMode = value; }
	CeilMode GetCeilMode() const noexcept { return m_ceilMode; }

protected:
	BaseCeilSettings() = default;
	virtual ~BaseCeilSettings() = default;

protected:
	CeilMode m_ceilMode { CeilMode::Ceil };
};

}