#pragma once

#include "TypeTraits.h"

namespace StepNN {

namespace AutoZero
{
template <typename T, typename = void>
struct SuitableType
{ typedef T Type; };

template <typename T>
struct SuitableType<T, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_floating_point<T>::value>::type>
{ typedef long long Type; };

template <typename T>
struct SuitableType<T, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_pointer<T>::value>::type>
{ typedef T Type; };

template <typename T, int value, typename = void>
struct SuitableTypeValue
{ static constexpr T val = T(value); };

template <typename T, int value>
struct SuitableTypeValue<T, value, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_floating_point<T>::value>::type>
{ static constexpr int val = int(value); };

template <typename T, int value>
struct SuitableTypeValue<T, value, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_enum<T>::value>::type>
{ static constexpr int val = value; };

template <typename T, int value>
struct SuitableTypeValue<T, value, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_pointer<T>::value>::type>
{ static constexpr T val = nullptr; };

}

//.............................................................................

template<typename T,
		 typename AutoZero::SuitableType<T>::Type value = static_cast<typename AutoZero::SuitableType<T>::Type>(AutoZero::SuitableTypeValue<T, 0>::val),
		 typename AutoZero::SuitableType<T>::Type divider = static_cast<typename AutoZero::SuitableType<T>::Type>(AutoZero::SuitableTypeValue<T, 1>::val),
		 typename = void>
class Z
{
	T t;
	static constexpr T defaultValue = T(value);
public:
	Z()             : t(defaultValue)   {}
	explicit Z(const T &t_)  : t(t_)         {}
	T& operator=(const T &rh) { t = rh; return t; }

	operator T&() { return t; }
	operator const T&() const { return t; }

	void reset() { t = defaultValue; }
	bool isDefault() const { return t == defaultValue; }
};

//.............................................................................

template<typename T, T value, T divider>
class Z<T, value, divider, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_enum<T>::value>::type>
{
	T t;
	static constexpr T defaultValue = static_cast<T>(value);
	using ThisType = Z<T, value, divider, void>;
	using UnderlyingType = typename TypeTraits::underlying_type<T>::type;
public:
	Z() : t(defaultValue) {}
	explicit Z(T t_) : t(t_) {}
	T& operator=(T rh) { t = rh; return t; }

	bool operator==(T rh) const { return t == rh; }
	bool operator!=(T rh) const { return t != rh; }

	operator T&() { return t; }
	operator const T&() const { return t; }

	void reset() { t = defaultValue; }
	bool isDefault() const { return t == defaultValue; }
	UnderlyingType toUnderlying() const { return static_cast<UnderlyingType>(t); }

	T operator|(T rh) const { return t | rh; }
	T operator&(T rh) const { return t & rh; }
	T operator^(T rh) const { return t ^ rh; }
	T operator~() const { return ~t; }
	ThisType& operator |= (T rh) { t |= rh; return *this; }
	ThisType& operator &= (T rh) { t &= rh; return *this; }
	ThisType& operator ^= (T rh) { t ^= rh; return *this; }

	bool operator!() const { return toUnderlying() == 0; }
};

//.............................................................................

template<typename T, long long value, long long divider>
class Z<T, value, divider, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_floating_point<T>::value>::type>
{
	T t;
	static constexpr T defaultValue = T(value) / divider;
public:
	Z()             : t(defaultValue) {}
	explicit Z(const T &t_)  : t(t_)                 {}
	T& operator=(const T &rh) { t = rh; return t; }
	bool operator==(const T &rh) const { return isEqual(rh); }
	bool operator!=(const T &rh) const { return !(*this == rh); }
	bool operator==(Z<T, value, divider, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_floating_point<T>::value>::type> rh) const { return isEqual(rh.t); }
	bool operator!=(Z<T, value, divider, typename StepNN::TypeTraits::enable_if<StepNN::TypeTraits::is_floating_point<T>::value>::type> rh) const { return !(*this == rh); }

	operator T&() { return t; }
	operator const T&() const { return t; }

	void reset() { t = defaultValue; }
	bool isDefault(T eps = 1.0e-5) const { return t <= defaultValue + eps && t >= defaultValue - eps; }
	bool isEqual(T rh, T eps = 1.0e-5) const { return t <= rh + eps && t >= rh - eps; }
};

//.............................................................................

template<typename T>
class ZF
{
	T t;
public:
	ZF() : t(nullptr) {}
	operator const T() const { return t; }
	T& operator=(const T &rh) { t = rh; return t; }
};

}
