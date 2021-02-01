#pragma once

#include <string>

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API DefaultLayerID
{
	static const std::string SOURCE_LAYER_ID;
	static const std::string LABEL_LAYER_ID;
	static const std::string LOSS_LAYER_ID;
};

}