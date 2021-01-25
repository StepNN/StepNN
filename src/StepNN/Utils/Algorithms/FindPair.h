#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <type_traits>

//.............................................................................

namespace StepNN {

template<typename FuncType, typename ArgType> struct isBoolExecutableWithTwoSameTypeParams
{
private:
	static void detect(...);
	template<typename U, typename V>
	static decltype(std::declval<U>()(std::declval<V>(), std::declval<V>())) detect(const U&, const V&);

public:
	static constexpr bool value = std::is_same<bool, decltype(detect(std::declval<FuncType>(), std::declval<ArgType>()))>::value;
};

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::first_type>
	>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::first_type>::value, InputIterator>::type
FindPairIteratorByFirst(InputIterator begin, InputIterator end, const typename Value::first_type &key, KeyEqual comparer = KeyEqual{})
{
	return std::find_if(begin, end, std::bind(comparer, key, std::bind(&Value::first, std::placeholders::_1)));
}

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::first_type>
	>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::first_type>::value, typename Value::second_type>::type&
FindSecond(InputIterator begin, InputIterator end, const typename Value::first_type &key, KeyEqual comparer = KeyEqual{})
{
	const auto it = FindPairIteratorByFirst(begin, end, key, comparer);
	assert(it != end);
	return it->second;
}

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::first_type>
>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::first_type>::value, typename Value::second_type>::type&
FindSecond(InputIterator begin, InputIterator end, const typename Value::first_type &key, const typename Value::second_type &defaultValue, KeyEqual comparer = KeyEqual{})
{
	const auto it = FindPairIteratorByFirst(begin, end, key, comparer);
	return it != end ? it->second : defaultValue;
}

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::second_type>
	>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::second_type>::value, InputIterator>::type
FindPairIteratorBySecond(InputIterator begin, InputIterator end, const typename Value::second_type &key, KeyEqual comparer = KeyEqual{})
{
	return std::find_if(begin, end, std::bind(comparer, key, std::bind(&Value::second, std::placeholders::_1)));
}

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::second_type>
	>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::second_type>::value, typename Value::first_type>::type&
FindFirst(InputIterator begin, InputIterator end, const typename Value::second_type &key, KeyEqual comparer = KeyEqual{})
{
	const auto it = FindPairIteratorBySecond(begin, end, key, comparer);
	assert(it != end);
	return it->first;
}

//.............................................................................

template
	< typename InputIterator
	, typename Value = typename std::iterator_traits<InputIterator>::value_type
	, typename KeyEqual = std::equal_to<typename Value::second_type>
	>
const typename std::enable_if<isBoolExecutableWithTwoSameTypeParams<KeyEqual, typename Value::second_type>::value, typename Value::first_type>::type&
FindFirst(InputIterator begin, InputIterator end, const typename Value::second_type &key, const typename Value::first_type &defaultValue, KeyEqual comparer = KeyEqual{})
{
	const auto it = FindPairIteratorBySecond(begin, end, key, comparer);
	return it != end ? it->first : defaultValue;
}

//.............................................................................

template <typename U, typename V>
std::pair<U, V> MakePair(const U &u, const V &v)
{
	return std::make_pair(u, v);
}

template<typename T>
struct RefWrapComparer
{
	inline bool operator()(const T& lh, const std::reference_wrapper<const T>& rh) const
	{
		return lh == rh.get();
	}

	inline bool operator()(const std::reference_wrapper<const T>& lh, const T& rh) const
	{
		return lh.get() == rh;
	}

	inline bool operator()(const std::reference_wrapper<const T>& lh, const std::reference_wrapper<const T>& rh) const
	{
		return lh.get() == rh.get();
	}
};

using RefWrapComparerString = RefWrapComparer<std::string>;

}
