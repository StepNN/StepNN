#pragma once

#include "ValueArray.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API DilationSettings : virtual protected ValueArray<Size, Type>
{
public:
	bool operator==(const DilationSettings& rhs) const noexcept { return ValueArray<Size, Type>::operator==(rhs); }
	bool operator!=(const DilationSettings& rhs) const noexcept { return !(*this == rhs); }
	int operator[](int index) const noexcept { return GetDilation(index); }

	void SetDilation(Values&& values)		{ ValueArray<Size, Type>::SetValues(std::move(values))	; }
	void SetDilation(const Values& values)	{ ValueArray<Size, Type>::SetValues(values)				; }
	void SetDilation(int value)				{ ValueArray<Size, Type>::SetValues(value)				; }
	void SetDilation(int index, int value)	{ ValueArray<Size, Type>::SetValue(index, value)		; }

	int GetDilation(int index) const noexcept { return ValueArray<Size, Type>::GetValue(index); }
	const Values& GetDilation() const noexcept { return ValueArray<Size, Type>::GetValues(); }

	bool HasDilation() const noexcept { return !ValueArray<Size, Type>::IsEmpty(); }

protected:
	DilationSettings() = default;
	~DilationSettings() = default;
};

using DilationSettings1D = DilationSettings<1>;
using DilationSettings2D = DilationSettings<2>;
using DilationSettings3D = DilationSettings<3>;

}