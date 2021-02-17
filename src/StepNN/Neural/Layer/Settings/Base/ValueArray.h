#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

template<size_t Size, typename Type = int64_t>
class STEPNN_API ValueArray
{
public:
	using ValuesZ = std::vector<Z<Type, static_cast<Type>(Defs::INVALID_VALUE_INT)>>;
	using Values = std::vector<Type>;

	size_t GetSize() const noexcept { return Size; }

protected:
	ValueArray()
	{
		m_values.reserve(Size);
		m_values.resize(Size);
		m_valuesImpl.reserve(Size);
		m_valuesImpl.resize(Size);
	}

	virtual ~ValueArray() = default;

	bool operator==(const ValueArray& rhs) const noexcept
	{
		bool result = true;
		for (size_t i = 0; i < Size; ++i)
			result = m_values[i] == rhs.m_values[i];
		return result;
	}

	bool operator!=(const ValueArray& rhs) const noexcept { return !(*this == rhs); }

	void SetValues(Values&& values)
	{
		assert(values.size() == Size);
		m_values = std::move(values);
		CopyToZ();
	}

	void SetValues(const Values& values)
	{
		assert(values.size() == Size);
		m_values = values;
		CopyToZ();
	}

	void SetValues(int value)
	{
		m_values.swap(decltype(m_values)(Size, value));
		CopyToZ();
	}

	void SetValue(int index, int value)
	{
		assert(index < m_values.size());
		m_values[index] = value;
	}

	Type GetValue(int index) const noexcept
	{
		if (m_values.size() <= index)
		{
			assert(!"Incorrect index in GetValue");
			return static_cast<Type>(Defs::INVALID_VALUE_INT);
		}
		return m_values[index];
	}

	const Values& GetValues() const noexcept
	{
		return m_values;
	}

	bool IsEmpty() const noexcept
	{
		return std::any_of(m_valuesImpl.cbegin(), m_valuesImpl.cend(), [](const auto& item) { return item.isDefault(); });
	}

private:
	void CopyToZ()
	{
		for (size_t i = 0; i < Size; ++i)
			m_values[i] = m_valuesImpl[i];
	}

private:
	ValuesZ m_valuesImpl;
	Values m_values;
};

}