#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API ClassificationSettings
{
	Z<int, Defs::INVALID_VALUE_INT> outputDimension;
};

}