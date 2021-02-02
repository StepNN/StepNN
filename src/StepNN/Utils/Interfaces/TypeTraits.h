#pragma once

namespace StepNN::TypeTraits {

/// integral_constant
template<typename _Tp, _Tp __v>
struct integral_constant
{
	static const _Tp						value = __v;
	typedef _Tp								value_type;
	typedef integral_constant<_Tp, __v>		type;
	operator value_type() { return value; }
};
template<typename _Tp, _Tp __v> const _Tp integral_constant<_Tp, __v>::value;

/// true and false types
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

/// enum traits
template<typename _Tp> struct is_enum : public integral_constant<bool, __is_enum(_Tp)> { };

/// float traits
template<class _Ty> struct is_floating_point        : false_type{};
template<> struct is_floating_point<float>          : true_type{};
template<> struct is_floating_point<double>         : true_type{};
template<> struct is_floating_point<long double>    : true_type{};

/// pointer traits
template<class _Ty> struct is_pointer               : false_type{};
template<class _Ty> struct is_pointer<_Ty *>        : true_type {};

/// enable_if
template<bool, typename _Tp = void> struct enable_if { };
template<typename _Tp> struct enable_if<true, _Tp>{ typedef _Tp type; };

/// remove_const
template<class _Ty> struct remove_const             { typedef _Ty type;};
template<class _Ty> struct remove_const<const _Ty>  { typedef _Ty type;};

/// remove_reference
template<class _Ty> struct remove_reference           {typedef _Ty type;};
template<class _Ty> struct remove_reference<_Ty&>     {typedef _Ty type;};
template<class _Ty> struct remove_reference<_Ty&&>    {typedef _Ty type;};

/// // determine type underlying type for enum
template<class _Ty> struct underlying_type {typedef __underlying_type(_Ty) type; };

}
