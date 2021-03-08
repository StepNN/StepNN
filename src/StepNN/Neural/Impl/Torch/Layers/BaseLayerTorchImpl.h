#pragma once

#include "StepNN/Neural/Layer/Settings/EmptySettings.h"

#include "BaseLayerTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

//@todo - enable_if for ImplTypeT that it's based on torch::nn::Module
template<typename SettingsTypeT, typename ImplTypeT = torch::nn::AnyModule>
class BaseLayerTorchImpl : virtual public BaseLayerTorch
{
protected:
	using SettingsType = SettingsTypeT;
	using ImplType = ImplTypeT;

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

	// Don't need LayerPtr in Connect,
	// layer implementation will be push_backed to common TorchSequential from IControllerTorchSequential (LayerEngineTorch)
	void Connect(LayerPtr) override
	{
		auto commonSequential = GetTorchSequential();
		if (!commonSequential)
		{
			assert(!"Invalid commonSequential");
			return;
		}

		if (!m_layerImpl)
		{
			assert(!"Invalid m_layerImpl");
			return;
		}
		commonSequential->get()->push_back(*m_layerImpl);
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
	std::shared_ptr<ImplType> m_layerImpl { nullptr };
};

}