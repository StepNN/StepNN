#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API SampleSettings
{
	Z<int, Defs::INVALID_VALUE_INT> sampleWidth;
	Z<int, Defs::INVALID_VALUE_INT> sampleHeight;
	Z<int, Defs::INVALID_VALUE_INT> channelsCount;
};

}