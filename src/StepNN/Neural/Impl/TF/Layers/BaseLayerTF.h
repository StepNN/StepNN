#pragma once

#include <cassert>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/ILayer.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseLayerTF : public ILayer
{
protected:
	explicit BaseLayerTF() = default;
	~BaseLayerTF() = default;

	void SetSettings(const BaseLayerSettings& settings) override { throw std::runtime_error(Defs::NOT_IMPL_STR);  }
	const BaseLayerSettings& GetBaseSettings() const override { throw std::runtime_error(Defs::NOT_IMPL_STR);  }
	const std::string& GetId() const noexcept override { assert(!Defs::NOT_IMPL_STR); return Defs::NOT_IMPL_STR; }

	void Connect(LayerPtr) override { throw std::runtime_error(Defs::NOT_IMPL_STR); }
};

}