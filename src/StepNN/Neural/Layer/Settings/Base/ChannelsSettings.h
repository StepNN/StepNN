#pragma once

#include <utility>

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

class STEPNN_API ChannelsSettings
{
public:
	bool operator==(const ChannelsSettings& rhs) const noexcept { return m_inChannels == rhs.m_inChannels && m_outChannels == rhs.m_outChannels; }
	bool operator!=(const ChannelsSettings& rhs) const noexcept { return !(*this == rhs); }

	void SetChannels(int ic, int oc) { m_inChannels = ic; m_outChannels = oc; }
	void SetInChannels(int value) { m_inChannels = value; }
	void SetOutChannels(int value) { m_outChannels = value; }

	std::pair<int, int> GetChannels() const noexcept { return { m_inChannels, m_outChannels }; }
	int GetInChannels() const noexcept { return m_inChannels; }
	int GetOutChannels() const noexcept { return m_outChannels; }

	bool HasChannels() const noexcept { return !(m_inChannels.isDefault() && m_outChannels.isDefault()); }

protected:
	ChannelsSettings() = default;
	virtual ~ChannelsSettings() = default;

protected:
	Z<int, Defs::INVALID_VALUE_INT> m_inChannels, m_outChannels;
};

}