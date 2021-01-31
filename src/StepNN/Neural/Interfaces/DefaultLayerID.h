#pragma once

#include <string>

namespace StepNN::Neural {

struct DefaultLayerID
{
	static const std::string SOURCE_LAYER_ID;
	static const std::string LABEL_LAYER_ID;
	static const std::string LOSS_LAYER_ID;
};

}