#pragma once

#include <string>

namespace StepNN::Defs {

constexpr int INVALID_VALUE_INT = -1;
constexpr size_t INVALID_VALUE_SIZE_T = -1;

inline bool IsInvalid(int value) { return value == INVALID_VALUE_INT; }
inline bool IsValid(int value) { return !IsInvalid(value); }

inline bool IsInvalid(size_t value) { return value == INVALID_VALUE_SIZE_T; }
inline bool IsValid(size_t value) { return !IsInvalid(value); }

//.............................................................................

constexpr const char* const NOT_IMPL_STR = "NOT_IMPL";

//.............................................................................

#define RETURN_IF(expr) if(##expr) return;

}