#pragma once

#include "ValueArray.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API StrideSettings : virtual protected ValueArray<Size, Type>
{
public:
	bool operator==(const StrideSettings& rhs) const noexcept { return ValueArray<Size, Type>::operator==(rhs); }
	bool operator!=(const StrideSettings& rhs) const noexcept { return !(*this == rhs); }
	int operator[](int index) const noexcept { return GetStride(index); }

	void SetStride(Values&& values)			{ ValueArray<Size, Type>::SetValues(std::move(values))	; }
	void SetStride(const Values& values)	{ ValueArray<Size, Type>::SetValues(values)				; }
	void SetStride(int value)				{ ValueArray<Size, Type>::SetValues(value)				; }
	void SetStride(int index, int value)	{ ValueArray<Size, Type>::SetValue(index, value)		; }

	int GetStride(int index) const noexcept { return ValueArray<Size, Type>::GetValue(index); }
	const Values& GetStride() const noexcept { return ValueArray<Size, Type>::GetValues(); }

	bool HasStride() const noexcept { return !ValueArray<Size, Type>::IsEmpty(); }

protected:
	StrideSettings() = default;
	~StrideSettings() = default;
};

using StrideSettings1D = StrideSettings<1>;
using StrideSettings2D = StrideSettings<2>;
using StrideSettings3D = StrideSettings<3>;

}