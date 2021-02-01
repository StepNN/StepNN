#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API DenseLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(DenseLayerSettings)

	DenseLayerSettings() = default;
	DenseLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const DenseLayerSettings& rhs) const noexcept
	{
		return true
			&& m_denseSize == rhs.m_denseSize
			&& BaseLayerSettings::operator==(rhs);
	}
	bool operator!=(const DenseLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetDenseSize(int value) { m_denseSize = value; }
	int GetDenseSize() const noexcept { return m_denseSize; }

	bool IsEmpty() const noexcept { return m_denseSize.isDefault(); }

private:
	Z<int, Defs::INVALID_VALUE_INT> m_denseSize;
};

}