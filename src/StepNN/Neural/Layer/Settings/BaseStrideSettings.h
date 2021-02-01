#pragma once

#include <utility>

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseStrideSettings
{
public:
	bool operator==(const BaseStrideSettings& rhs) const noexcept { return true; }
	bool operator!=(const BaseStrideSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetStride(int w, int h) { m_strideWidth = w; m_strideHeight = h; }
	void SetStrideWidth(int value) { m_strideWidth = value; }
	void SetStrideHeight(int value) { m_strideHeight = value; }

	std::pair<int, int> GetStride() const noexcept { return { m_strideWidth, m_strideHeight }; }
	int GetStrideWidth() const noexcept { return m_strideWidth; }
	int GetStrideHeight() const noexcept { return m_strideHeight; }

protected:
	BaseStrideSettings() = default;
	virtual ~BaseStrideSettings() = default;

protected:
	int m_strideWidth, m_strideHeight;
};

}