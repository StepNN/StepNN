#pragma once

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "BaseLayerNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

template<typename ImplTypeT, typename SettingsTypeT>
class BaseLayerNeoMLImpl : public BaseLayerNeoML
{
protected:
	using SettingsType = SettingsTypeT;
	using ImplType = ImplTypeT;

	BaseLayerNeoMLImpl() = default;
	BaseLayerNeoMLImpl(NeoMathEnginePtr mathEngine) : BaseLayerNeoML(mathEngine) {};
	~BaseLayerNeoMLImpl() = default;

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

		assert(m_mathEngine);
		m_layerImpl.Release();
		m_layerImpl = new ImplType(*m_mathEngine);
		m_layerImpl->SetName(m_typedSettings.GetLayerId().data());
	}

protected:
	SettingsType m_typedSettings;
};

}