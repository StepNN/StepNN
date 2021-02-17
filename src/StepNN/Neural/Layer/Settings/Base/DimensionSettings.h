#pragma once

#include "ValueArray.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API DimensionSettings : virtual protected ValueArray<Size, Type>
{
public:
	bool operator==(const DimensionSettings& rhs) const noexcept { return ValueArray<Size, Type>::operator==(rhs); }
	bool operator!=(const DimensionSettings& rhs) const noexcept { return !(*this == rhs); }
	int operator[](int index) const noexcept { return GetDimension(index); }

	void SetDimension(Values&& values)		{ ValueArray<Size, Type>::SetValues(std::move(values))	; }
	void SetDimension(const Values& values)	{ ValueArray<Size, Type>::SetValues(values)				; }
	void SetDimension(int value)			{ ValueArray<Size, Type>::SetValues(value)				; }
	void SetDimension(int index, int value)	{ ValueArray<Size, Type>::SetValue(index, value)		; }

	int GetDimension(int index) const noexcept { return ValueArray<Size, Type>::GetValue(index); }
	const Values& GetDimension() const noexcept { return ValueArray<Size, Type>::GetValues(); }

	bool HasDimension() const noexcept { return !ValueArray<Size, Type>::IsEmpty(); }

protected:
	DimensionSettings() = default;
	~DimensionSettings() = default;
};

using DimensionSettings1D = DimensionSettings<1>;
using DimensionSettings2D = DimensionSettings<2>;
using DimensionSettings3D = DimensionSettings<3>;

}