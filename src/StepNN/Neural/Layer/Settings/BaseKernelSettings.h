#pragma once

#include <utility>

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseKernelSettings
{
public:
	bool operator==(const BaseKernelSettings& rhs) const noexcept { return true; }
	bool operator!=(const BaseKernelSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetKernel(int w, int h) { m_kernelWidth = w; m_kernelHeight = h; }
	void SetKernelWidth(int value) { m_kernelWidth = value; }
	void SetKernelHeigh(int value) { m_kernelHeight = value; }

	std::pair<int, int> GetKernel() const noexcept { return { m_kernelWidth, m_kernelHeight }; }
	int GetKernelWidth() const noexcept { return m_kernelWidth ; }
	int GetKernelHeight() const noexcept { return m_kernelHeight ; }

protected:
	BaseKernelSettings() = default;
	virtual ~BaseKernelSettings() = default;

protected:
	int m_kernelWidth, m_kernelHeight;
};

}