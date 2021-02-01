#pragma once

#include <utility>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseStrideSettings
{
public:
	bool operator==(const BaseStrideSettings& rhs) const noexcept { return m_strideWidth == rhs.m_strideHeight && m_strideHeight == rhs.m_strideHeight; }
	bool operator!=(const BaseStrideSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetStride(int w, int h) { m_strideWidth = w; m_strideHeight = h; }
	void SetStrideWidth(int value) { m_strideWidth = value; }
	void SetStrideHeight(int value) { m_strideHeight = value; }

	std::pair<int, int> GetStride() const noexcept { return { m_strideWidth, m_strideHeight }; }
	int GetStrideWidth() const noexcept { return m_strideWidth; }
	int GetStrideHeight() const noexcept { return m_strideHeight; }
	
	bool IsEmpty() const noexcept { return m_strideWidth.isDefault() || m_strideHeight.isDefault(); }

protected:
	BaseStrideSettings() = default;
	virtual ~BaseStrideSettings() = default;

protected:
	Z<int, Defs::INVALID_VALUE_INT> m_strideWidth, m_strideHeight;
};

}