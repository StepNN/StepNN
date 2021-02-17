#pragma once

#include "BlobDataType.h"
#include "ClassificationSettings.h"
#include "DeviceType.h"
#include "OptimizerSettings.h"
#include "SampleSettings.h"
#include "TrainSettings.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API NeuralConfiguration
{
	Z<DeviceType, DeviceType::Undefined> deviceType;
	Z<BlobDataType, BlobDataType::Undefined> blobDataType;
	Z<int, 0> memoryLimit;

	ClassificationSettings classificationSettings;
	OptimizerSettings optimizerSettings;
	SampleSettings sampleSettings;
	TrainSettings trainSettings;

	bool IsInvalid() const noexcept
	{
		// @todo IsInvalid implementation of each settings
		return false
			|| deviceType == DeviceType::Undefined
			|| blobDataType == BlobDataType::Undefined
			|| Defs::IsInvalid(trainSettings.epochCount)
			|| Defs::IsInvalid(trainSettings.trainBatchWidth)
			|| Defs::IsInvalid(trainSettings.testBatchWidth)
			|| Defs::IsInvalid(sampleSettings.channelsCount)
			|| Defs::IsInvalid(sampleSettings.sampleHeight)
			|| Defs::IsInvalid(sampleSettings.sampleWidth)
		;
	}
};

}