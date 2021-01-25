#pragma once

#include <string>

namespace StepNN::Defs {

constexpr int INVALID_VALUE_INT = -1;

inline bool IsInvalid(int value) { return value == INVALID_VALUE_INT; }
inline bool IsValid(int value) { return !IsInvalid(value); }

//.............................................................................

constexpr const char* const NOT_IMPL_STR = "NOT_IMPL";

}