#pragma once

#include <string>

#include "StepNNLib.h"

namespace StepNN {

class STEPNN_API BaseLayerSettings
{
public:
	virtual ~BaseLayerSettings() = default;
	virtual const std::string& GetSettingsID() const { return m_defaultSettingsId; }

	void SetLayerId(const std::string& id) { m_layerId = id; }
	const std::string& GetLayerId() const noexcept { return m_layerId; }

protected:
	BaseLayerSettings() = default;

protected:
	std::string m_layerId;

private:
	static const std::string m_defaultSettingsId;
};

#define LAYER_SETTINGS(ClassName) \
	static const std::string SETTINGS_ID; \
	virtual const std::string& GetSettingsID() const override { return SETTINGS_ID; } \
	~ClassName() = default;

}