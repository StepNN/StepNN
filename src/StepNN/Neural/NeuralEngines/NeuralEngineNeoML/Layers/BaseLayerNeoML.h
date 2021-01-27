#pragma once

#include "NeoML/Dnn/Dnn.h"

#include "StepNN/Neural/Interfaces/ILayer.h"

using namespace StepNN::Interfaces;

namespace StepNN {

template<typename SettingsTypeT>
class BaseLayerNeoML : public ILayer
{
protected:
	using SettingsType = SettingsTypeT;

	BaseLayerNeoML() = default;
	~BaseLayerNeoML() = default;

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

protected:
	SettingsType m_typedSettings;
	FObj::CPtr<NeoML::CBaseLayer> m_layer { nullptr };
};

}