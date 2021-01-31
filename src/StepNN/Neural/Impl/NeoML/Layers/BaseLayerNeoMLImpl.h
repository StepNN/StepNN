#pragma once

#include "NeoML/Dnn/Dnn.h"

#include "BaseLayerNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

template<typename SettingsTypeT>
class BaseLayerNeoMLImpl : virtual public BaseLayerNeoML
{
protected:
	using SettingsType = SettingsTypeT;

	BaseLayerNeoMLImpl() = default;
	~BaseLayerNeoMLImpl() = default;

/// ILayer
	void SetSettings(const BaseLayerSettings& settings) override
	{
		const SettingsType& typedSettings = dynamic_cast<const SettingsType&>(settings);
		m_typedSettings = typedSettings;
	}

	const BaseLayerSettings& GetBaseSettings() const override
	{
		return m_typedSettings;
	}

	const std::string& GetId() const noexcept override
	{
		return m_typedSettings.GetLayerId();
	}
///

protected:
	SettingsType m_typedSettings;
};

}