#pragma once

#include <utility>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"
#include "StepNN/Neural/Data/PaddingMode.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BasePaddingSettings
{
public:
	bool operator==(const BasePaddingSettings& rhs) const noexcept { return m_paddingMode == rhs.m_paddingMode && m_paddingWidth == rhs.m_paddingWidth && m_paddingHeight == rhs.m_paddingHeight; }
	bool operator!=(const BasePaddingSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetPaddingMode(PaddingMode value) { m_paddingMode = value; }
	void SetPadding(int pw, int ph) { m_paddingWidth = pw; m_paddingHeight = ph; }
	void SetPaddingWidth(int value) { m_paddingWidth = value; }
	void SetPaddingHeight(int value) { m_paddingHeight = value; }

	PaddingMode GetPaddingMode() const noexcept { return m_paddingMode; }
	std::pair<int, int> GetPadding() const noexcept { return { m_paddingWidth, m_paddingHeight }; }
	int GetPaddingWidth() const noexcept { return m_paddingWidth; }
	int GetPaddingHeight() const noexcept { return m_paddingHeight; }

	bool IsEmpty() const noexcept { return m_paddingMode.isDefault() || m_paddingWidth.isDefault() || m_paddingHeight.isDefault(); }

protected:
	BasePaddingSettings() = default;
	virtual ~BasePaddingSettings() = default;

protected:
	Z<PaddingMode, PaddingMode::Undefined> m_paddingMode;
	Z<int, Defs::INVALID_VALUE_INT> m_paddingWidth, m_paddingHeight;
};

}