#pragma once

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API BiasSettings
{
public:
	bool operator==(const BiasSettings& rhs) const noexcept { return m_bias == rhs.m_bias; }
	bool operator!=(const BiasSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetBias(bool value) { m_bias = value; }
	bool GetBias() const noexcept { return m_bias; }

	//bool IsEmpty() const noexcept { return m_bias.isDefault(); }

protected:
	BiasSettings() = default;
	virtual ~BiasSettings() = default;

protected:
	Z<bool, true> m_bias;
};

}