#pragma once

#include "StepNN/Neural/Interfaces/ILayer.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

template<typename SettingsTypeT>
class BaseLayerTF : public ILayer
{
protected:
	using SettingsType = SettingsTypeT;

	BaseLayerTF() = default;
	~BaseLayerTF() = default;

	void SetSettings(const BaseLayerSettings& settings) override
	{
		const SettingsType& typedSettings = dynamic_cast<const SettingsType&>(settings);
		this->SetSettings(typedSettings);
	}

	const BaseLayerSettings& GetBaseSettings() const override
	{
		return m_typedSettings;
	}

	const std::string& GetId() const noexcept override
	{
		return m_typedSettings.GetLayerId();
	}

protected:
	SettingsType m_typedSettings;
};

}