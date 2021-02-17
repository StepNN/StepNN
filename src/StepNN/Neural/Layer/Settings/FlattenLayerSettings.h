#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {


class STEPNN_API FlattenLayerSettings : public BaseLayerSettings
{
public:
	LAYER_SETTINGS(FlattenLayerSettings)

	FlattenLayerSettings() = default;
	FlattenLayerSettings(const std::string& layerId) : BaseLayerSettings(layerId) {};

	bool operator==(const FlattenLayerSettings& rhs) const noexcept { return BaseLayerSettings::operator==(rhs); }
	bool operator!=(const FlattenLayerSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetInDim(int value) { m_inDim = value; }
	void SetOutDim(int value) { m_outDim = value; }

	int GetInDim() const noexcept { return m_inDim; }
	int GetOutDim() const noexcept { return m_outDim; }

	bool IsEmpty() const noexcept { return m_inDim.isDefault() || m_outDim.isDefault(); }

protected:
	Z<int, Defs::INVALID_VALUE_INT> m_inDim, m_outDim;
};

}