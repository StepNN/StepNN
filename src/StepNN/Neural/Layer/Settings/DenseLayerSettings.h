#pragma once

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API DenseLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(DenseLayerSettings)

	DenseLayerSettings() = default;

	bool operator==(const DenseLayerSettings& rhs) const noexcept { return true; }
	bool operator!=(const DenseLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetDenseSize(int value) { m_denseSize = value; }
	int GetDenseSize() const noexcept { return m_denseSize; }

	bool IsEmpty() const noexcept { return false; }

private:
	int m_denseSize;
};

}