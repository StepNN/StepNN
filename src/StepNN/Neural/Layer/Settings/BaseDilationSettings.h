#pragma once

#include <utility>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseDilationSettings
{
public:
	bool operator==(const BaseDilationSettings& rhs) const noexcept { return m_dilationWidth == rhs.m_dilationWidth && m_dilationHeight == rhs.m_dilationHeight; }
	bool operator!=(const BaseDilationSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetDilation(int w, int h) { m_dilationWidth = w; m_dilationHeight = h; }
	void SetDilationWidth(int value) { m_dilationWidth = value; }
	void SetDilationHeigh(int value) { m_dilationHeight = value; }

	std::pair<int, int> GetDilation() const noexcept { return { m_dilationWidth, m_dilationHeight }; }
	int GetDilationWidth() const noexcept { return m_dilationWidth; }
	int GetDilationHeight() const noexcept { return m_dilationHeight; }

	bool IsEmpty() const noexcept { return m_dilationWidth.isDefault() || m_dilationHeight.isDefault(); }

protected:
	BaseDilationSettings() = default;
	virtual ~BaseDilationSettings() = default;

protected:
	Z<int, Defs::INVALID_VALUE_INT> m_dilationWidth, m_dilationHeight;
};

}