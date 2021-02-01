#pragma once

#include "StepNN/Neural/Impl/NeoML/CommonNeoML.h"

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "BaseLayerNeoML.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

template<typename ImplTypeT, typename SettingsTypeT>
class BaseLayerNeoMLImpl : virtual public BaseLayerNeoML
{
protected:
	using SettingsType = SettingsTypeT;
	using ImplType = ImplTypeT;

	BaseLayerNeoMLImpl() = default;
	explicit BaseLayerNeoMLImpl(NeoMathEnginePtr mathEngine) : BaseLayerNeoML(mathEngine) {};
	explicit BaseLayerNeoMLImpl(const BaseLayerSettings& settings)
	{
		SetSettings(settings);
	}
	~BaseLayerNeoMLImpl() = default;

/// ILayer
	void SetSettings(const BaseLayerSettings& settings) override
	{
		const SettingsType& typedSettings = dynamic_cast<const SettingsType&>(settings);
		m_typedSettings = typedSettings;

		assert(m_mathEngine);
		//@todo check for release ptr
		m_layerImpl = new ImplType(*m_mathEngine);
		m_layerImpl->SetName(m_typedSettings.GetLayerId().data());
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