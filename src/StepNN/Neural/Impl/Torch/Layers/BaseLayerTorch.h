#pragma once

#include <cassert>
#include <stdexcept>

#include "StepNN/Types/CommonDefs.h"

#include "StepNN/Neural/Interfaces/ILayer.h"

#include "StepNN/Neural/Impl/Torch/CommonTorch.h"

using namespace StepNN::Neural::Interfaces;

namespace StepNN::Neural {

class BaseLayerTorch : public ILayer
{
protected:
	explicit BaseLayerTorch() = default;
	~BaseLayerTorch() = default;

	void SetSettings(const BaseLayerSettings& settings) override { throw std::runtime_error(Defs::NOT_IMPL_STR);  }
	const BaseLayerSettings& GetBaseSettings() const override { throw std::runtime_error(Defs::NOT_IMPL_STR);  }
	const std::string& GetId() const override { throw std::runtime_error(Defs::NOT_IMPL_STR); }

	void Connect(LayerPtr layer) override
	{
	//	m_
	}

private:
	torch::nn::Sequential m_layerImpl;
};

}