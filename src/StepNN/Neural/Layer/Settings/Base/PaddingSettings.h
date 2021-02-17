#pragma once

#include "ValueArray.h"

#include "StepNN/Neural/Data/PaddingMode.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API PaddingSettings : virtual protected ValueArray<Size, Type>
{
public:
	bool operator==(const PaddingSettings& rhs) const noexcept
	{
		return true
			&& m_paddingMode == rhs.m_paddingMode
			&& ValueArray<Size, Type>::operator==(rhs)
			;
	}
	bool operator!=(const PaddingSettings& rhs) const noexcept { return !(*this == rhs); }
	int operator[](int index) const noexcept { return GetPadding(index); }

	void SetPaddingMode(PaddingMode value) { m_paddingMode = value; }
	void SetPadding(Values&& values)		{ ValueArray<Size, Type>::SetValues(std::move(values))	; }
	void SetPadding(const Values& values)	{ ValueArray<Size, Type>::SetValues(values)				; }
	void SetPadding(int value)				{ ValueArray<Size, Type>::SetValues(value)				; }
	void SetPadding(int index, int value)	{ ValueArray<Size, Type>::SetValue(index, value)		; }

	PaddingMode GetPaddingMode() const noexcept { return m_paddingMode; }
	int GetPadding(int index) const noexcept { return ValueArray<Size, Type>::GetValue(index); }
	const Values& GetPadding() const noexcept { return ValueArray<Size, Type>::GetValues(); }

	bool HasPadding() const noexcept { return !(m_paddingMode.isDefault() || ValueArray<Size, Type>::IsEmpty()); }

protected:
	PaddingSettings() = default;
	~PaddingSettings() = default;

protected:
	Z<PaddingMode, PaddingMode::Undefined> m_paddingMode;
};

using PaddingSettings1D = PaddingSettings<1>;
using PaddingSettings2D = PaddingSettings<2>;
using PaddingSettings3D = PaddingSettings<3>;

}