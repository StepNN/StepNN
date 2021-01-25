#pragma once

#include "src/Neural/Interfaces/ILayer.h"

using namespace StepNN::Interfaces;

namespace StepNN {

template<typename SettingsTypeT>
class BaseLayerTorch : public ILayer
{
protected:
	using SettingsType = SettingsTypeT;

	BaseLayerTorch() = default;
	~BaseLayerTorch() = default;

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