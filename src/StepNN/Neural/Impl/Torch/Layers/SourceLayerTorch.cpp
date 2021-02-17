#include "StepNN/Neural/Layer/Settings/SourceLayerSettings.h"

#include "BaseLayerTorchImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class SourceLayerTorch : public BaseLayerTorchImpl<SourceLayerSettings>
{
public:
	SourceLayerTorch() = default;
	SourceLayerTorch(const BaseLayerSettings& settings)
	{
		BaseLayerTorchImpl<SourceLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const SourceLayerSettings& typedSettings) {}

	// It is a dummy layer
	void Connect(LayerPtr layer) override {}
};

}

LayerUPtr CreateSourceLayerTorch(const BaseLayerSettings& settings)
{
	return std::make_unique<SourceLayerTorch>(settings);
}

}