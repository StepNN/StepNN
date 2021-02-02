#pragma once

#include <memory>
#include <vector>

#include "StepNN/Neural/Layer/Settings/BaseLayerSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

namespace Interfaces {

class STEPNN_API ILayer
{
public:
	virtual ~ILayer() = default;

	virtual void SetSettings(const BaseLayerSettings& settings) = 0;
	virtual const BaseLayerSettings& GetBaseSettings() const = 0;

	virtual const std::string& GetId() const noexcept = 0;

	// layer1->ConnectPrev(layer2) -> layerImpl1.Connect(layerImpl2)
	virtual void ConnectPrev(ILayer*) = 0;
	// layer1->ConnectNext(layer2) -> layerImpl2.Connect(layerImpl1)
	virtual void ConnectNext(ILayer*) = 0;
};

}

using LayerPtr		= Interfaces::ILayer*;
using LayerCPtr		= const LayerPtr;
using LayerPtrs		= std::vector<LayerPtr>;
using LayerUPtr		= std::unique_ptr<Interfaces::ILayer>;
using LayerUPtrs	= std::vector<LayerUPtr>;

}
