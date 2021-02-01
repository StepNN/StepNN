#pragma once

#include "StepNN/Types/CommonDefs.h"
#include "StepNN/Utils/Interfaces/AutoZero.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API TrainSettings
{
	// must be initialized
	Z<int, Defs::INVALID_VALUE_INT> epochCount;
	Z<int, Defs::INVALID_VALUE_INT> trainBatchWidth;
	Z<int, Defs::INVALID_VALUE_INT> testBatchWidth;

	// initializing can be skipped
	Z<int, 1> trainBatchLength;
	Z<int, 1> testBatchLength;
};

}