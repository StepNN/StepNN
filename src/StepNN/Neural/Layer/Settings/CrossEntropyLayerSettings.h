#pragma once

#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API CrossEntropyLayerSettings : public BaseLayerSettings
{
public:
	enum class Reduction { None, Mean, Sum };
public:
	LAYER_SETTINGS(CrossEntropyLayerSettings)

	CrossEntropyLayerSettings() = default;
	CrossEntropyLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const CrossEntropyLayerSettings& rhs) const noexcept
	{
		return true
			&& BaseLayerSettings::operator==(rhs)
			&& m_ignoreIndex == rhs.m_ignoreIndex
			&& m_reduction == rhs.m_reduction
			;
	}
	bool operator!=(const CrossEntropyLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetIgnoreIndex(int64_t value) { m_ignoreIndex = value; }
	void SetReduction(Reduction value) { m_reduction = value; }
	//void SetWeight() {};

	int64_t GetIgnoreIndex() const noexcept { return m_ignoreIndex; }
	Reduction GetReduction() const noexcept { return m_reduction; }
	//GetWeight() const noexcept {};

	bool IsEmpty() const noexcept { return false; }

protected:
	Z<int64_t, -100> m_ignoreIndex;
	Z<Reduction, Reduction::Mean> m_reduction;
	//@todo Add weights
};

}