#pragma once

#include <stdexcept>

#include "NeoML/Dnn/Dnn.h"

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/ILayer.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseLayerNeoML : public ILayer
{
public:
	FObj::CPtr<NeoML::CBaseLayer>& GetLayerImpl() { return m_layerImpl; }

protected:
	BaseLayerNeoML() = default;
	explicit BaseLayerNeoML(NeoMathEnginePtr mathEngine) : m_mathEngine(mathEngine) {}
	~BaseLayerNeoML() = default;

/// ILayer
	void SetSettings(const BaseLayerSettings& settings) override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	const BaseLayerSettings& GetBaseSettings() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); };
	const std::string& GetId() const noexcept override { assert(!Defs::NOT_IMPL_STR); return Defs::NOT_IMPL_STR; };
///

protected:
	FObj::CPtr<NeoML::CBaseLayer> m_layerImpl { nullptr };
	NeoMathEnginePtr m_mathEngine { nullptr };
};

}