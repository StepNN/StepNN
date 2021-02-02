#pragma once

#include <utility>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BaseKernelSettings
{
public:
	bool operator==(const BaseKernelSettings& rhs) const noexcept { return m_kernelWidth == rhs.m_kernelWidth && m_kernelHeight == rhs.m_kernelHeight; }
	bool operator!=(const BaseKernelSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetKernel(int w, int h) { m_kernelWidth = w; m_kernelHeight = h; }
	void SetKernelWidth(int value) { m_kernelWidth = value; }
	void SetKernelHeight(int value) { m_kernelHeight = value; }

	std::pair<int, int> GetKernel() const noexcept { return { m_kernelWidth, m_kernelHeight }; }
	int GetKernelWidth() const noexcept { return m_kernelWidth; }
	int GetKernelHeight() const noexcept { return m_kernelHeight; }

	bool IsEmpty() const noexcept { return m_kernelWidth.isDefault() || m_kernelHeight.isDefault(); }

protected:
	BaseKernelSettings() = default;
	virtual ~BaseKernelSettings() = default;

protected:
	Z<int, Defs::INVALID_VALUE_INT> m_kernelWidth, m_kernelHeight;
};

}