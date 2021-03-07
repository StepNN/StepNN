#include "StepNN/Neural/Layer/Settings/ConvLayerSettings.h"

#include "BaseLayerTFImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

template<size_t Size>
class ConvLayerTF : public BaseLayerTFImpl<ConvLayerSettings<Size>>
{
public:
	ConvLayerTF() = default;
	ConvLayerTF(const BaseLayerSettings& settings)
	{
		BaseLayerTFImpl<ConvLayerSettings<Size>>::SetSettings(settings);
	}

	void SetSettings(const ConvLayerSettings<Size>& typedSettings)
	{
		BaseLayerTFImpl<ConvLayerSettings<Size>>::SetSettings(typedSettings);
	}
};

}

std::shared_ptr<ILayer> CreateConvLayerTF(const BaseLayerSettings& settings)
{
	return nullptr;
}

}