#include "StepNN/Neural/Layer/Settings/OutputLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class OutputLayerTorch : public BaseLayerTorchImpl<OutputLayerSettings>
{
public:
	OutputLayerTorch() = default;
	OutputLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<OutputLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const OutputLayerSettings& typedSettings) {}

	// It is a dummy layer
	void Connect(LayerPtr layer) override {}
};

}

std::shared_ptr<ILayer> CreateOutputLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_shared<OutputLayerTorch>(settings);
}

}