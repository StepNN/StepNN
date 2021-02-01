#pragma once

#include <utility>

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseDilationSettings
{
public:
	bool operator==(const BaseDilationSettings& rhs) const noexcept { return true; }
	bool operator!=(const BaseDilationSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetDilation(int w, int h) { m_dilationWidth = w; m_dilationHeight = h; }
	void SetDilationWidth(int value) { m_dilationWidth = value; }
	void SetDilationHeigh(int value) { m_dilationHeight = value; }

	std::pair<int, int> GetDilation() const noexcept { return { m_dilationWidth, m_dilationHeight }; }
	int GetDilationWidth() const noexcept { return m_dilationWidth; }
	int GetDilationHeight() const noexcept { return m_dilationHeight; }

protected:
	BaseDilationSettings() = default;
	virtual ~BaseDilationSettings() = default;

protected:
	int m_dilationWidth, m_dilationHeight;
};

}