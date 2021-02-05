#pragma once

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "BaseLayerTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

template<typename SettingsTypeT>
class BaseLayerTorchImpl : virtual public BaseLayerTorch
{
protected:
	using SettingsType = SettingsTypeT;

	BaseLayerTorchImpl() = default;
	~BaseLayerTorchImpl() = default;

/// ILayer
	void SetSettings(const BaseLayerSettings& settings) override
	{
		try
		{
			const SettingsType& typedSettings = dynamic_cast<const SettingsType&>(settings);
			this->SetSettings(typedSettings);
		}
		catch (const std::bad_cast&)
		{}
	}

	const BaseLayerSettings& GetBaseSettings() const override
	{
		return m_typedSettings;
	}

	const std::string& GetId() const override
	{
		return m_typedSettings.GetLayerId();
	}
///

	virtual void SetSettings(const SettingsType& typedSettings)
	{
		if (this->m_typedSettings == typedSettings)
			return;

		this->m_typedSettings = typedSettings;
	}

protected:
	SettingsType m_typedSettings;
};

}