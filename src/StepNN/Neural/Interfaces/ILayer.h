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

	virtual const std::string& GetId() const = 0;

	/*
	* layer1->Connect(layer2) is connection like ... ->layer2->layer1-> ...
	* layer2 is ABOVE then layer1
	*/ 
	virtual void Connect(ILayer*) = 0;
};

}

using LayerPtr		= Interfaces::ILayer*;
using LayerCPtr		= const LayerPtr;
using LayerPtrs		= std::vector<LayerPtr>;
using LayerUPtr		= std::unique_ptr<Interfaces::ILayer>;
using LayerUPtrs	= std::vector<LayerUPtr>;

}
