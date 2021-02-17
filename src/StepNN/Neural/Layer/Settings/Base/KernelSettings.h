#pragma once

#include "ValueArray.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API KernelSettings : virtual protected ValueArray<Size, Type>
{
public:
	bool operator==(const KernelSettings& rhs) const noexcept { return ValueArray<Size, Type>::operator==(rhs); }
	bool operator!=(const KernelSettings& rhs) const noexcept { return !(*this == rhs); }
	int operator[](int index) const noexcept { return GetKernel(index); }

	void SetKernel(Values&& values)			{ ValueArray<Size, Type>::SetValues(std::move(values))	; }
	void SetKernel(const Values& values)	{ ValueArray<Size, Type>::SetValues(values)				; }
	void SetKernel(int value)				{ ValueArray<Size, Type>::SetValues(value)				; }
	void SetKernel(int index, int value)	{ ValueArray<Size, Type>::SetValue(index, value)		; }

	int GetKernel(int index) const noexcept { return ValueArray<Size, Type>::GetValue(index); }
	const Values& GetKernel() const noexcept { return ValueArray<Size, Type>::GetValues(); }

	bool HasKernel() const noexcept { return !ValueArray<Size, Type>::IsEmpty(); }

protected:
	KernelSettings() = default;
	~KernelSettings() = default;
};

using KernelSettings1D = KernelSettings<1>;
using KernelSettings2D = KernelSettings<2>;
using KernelSettings3D = KernelSettings<3>;

}