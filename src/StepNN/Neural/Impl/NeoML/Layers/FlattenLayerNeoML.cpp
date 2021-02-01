#include "NeoML/Dnn/Layers/TransformLayer.h"

#include "StepNN/Neural/Layer/Settings/FlattenLayerSettings.h"

#include "BaseLayerNeoMLImpl.h"

namespace StepNN::Neural {

namespace {

using namespace StepNN::Neural;

class FlattenLayerNeoML : public BaseLayerNeoMLImpl<NeoML::CTransformLayer, FlattenLayerSettings>
{
public:
	FlattenLayerNeoML(NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CTransformLayer, FlattenLayerSettings>(mathEngine)
	{}

	FlattenLayerNeoML(const BaseLayerSettings& settings, NeoMathEnginePtr mathEngine)
		: BaseLayerNeoMLImpl<NeoML::CTransformLayer, FlattenLayerSettings>(mathEngine)
	{
		BaseLayerNeoMLImpl<NeoML::CTransformLayer, FlattenLayerSettings>::SetSettings(settings);
	}

	void SetSettings(const FlattenLayerSettings& typedSettings)
	{
		BaseLayerNeoMLImpl<NeoML::CTransformLayer, FlattenLayerSettings>::SetSettings(typedSettings);

		auto castedLayer = CheckCast<NeoML::CTransformLayer>(m_layerImpl.Ptr());

		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_BatchLength	, NeoML::CTransformLayer::TOperation::O_SetSize		, 1);
		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_BatchWidth	, NeoML::CTransformLayer::TOperation::O_Multiply	, 1);
		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_Channels		, NeoML::CTransformLayer::TOperation::O_SetSize		, 1);
		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_Depth			, NeoML::CTransformLayer::TOperation::O_SetSize		, 1);
		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_Height		, NeoML::CTransformLayer::TOperation::O_SetSize		, 1);
		castedLayer->SetDimensionRule(NeoML::TBlobDim::BD_Width			, NeoML::CTransformLayer::TOperation::O_Remainder	, 1);
	}

	~FlattenLayerNeoML() = default;
};

}

LayerUPtr CreateFlattenLayerNeoML(NeoMathEnginePtr mathEngine, const BaseLayerSettings& settings = EmptySettings())
{
	if (settings.GetSettingsID() == EmptySettings::SETTINGS_ID)
		return std::make_unique<FlattenLayerNeoML>(mathEngine);
	else
		return std::make_unique<FlattenLayerNeoML>(settings, mathEngine);
}

}