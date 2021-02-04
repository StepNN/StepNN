#pragma once

#include "TypeTraits.h"

template<typename Enum>
struct EnableBitMaskOperators
{
	static constexpr bool enable = false;
};

#define ENABLE_BITMASK_OPERATORS(x)			\
template<>struct EnableBitMaskOperators<x>	\
{											\
static constexpr bool enable = true;		\
};

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator|(Enum lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	return static_cast<Enum> (
		static_cast<underlying>(lhs) |
		static_cast<underlying>(rhs)
		);
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator&(Enum lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	return static_cast<Enum> (
		static_cast<underlying>(lhs) &
		static_cast<underlying>(rhs)
		);
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator^(Enum lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	return static_cast<Enum> (
		static_cast<underlying>(lhs) ^
		static_cast<underlying>(rhs)
		);
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator~(Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	return static_cast<Enum> (
		~static_cast<underlying>(rhs)
	);
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type&
operator|=(Enum &lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	lhs = static_cast<Enum> (
		static_cast<underlying>(lhs) |
		static_cast<underlying>(rhs)
		);
	return lhs;
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type&
operator&=(Enum &lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	lhs = static_cast<Enum> (
		static_cast<underlying>(lhs) &
		static_cast<underlying>(rhs)
		);
	return lhs;
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type&
operator^=(Enum &lhs, Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	lhs = static_cast<Enum> (
		static_cast<underlying>(lhs) ^
		static_cast<underlying>(rhs)
		);
	return lhs;
}

template<typename Enum>
inline typename StepNN::TypeTraits::enable_if<EnableBitMaskOperators<Enum>::enable, bool>::type
operator!(Enum rhs) noexcept
{
	using underlying = typename StepNN::TypeTraits::underlying_type<Enum>::type;
	return static_cast<underlying>(rhs) == 0;
}
