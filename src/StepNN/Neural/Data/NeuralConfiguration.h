#pragma once

#include "BlobDataType.h"
#include "ClassificationSettings.h"
#include "DeviceType.h"

#include "StepNNLib.h"

namespace StepNN::Neural {

struct STEPNN_API NeuralConfiguration
{
	int epochCount;
	int trainBatchLength;
	int trainBatchWidth;
	int testBatchLength;
	int testBatchWidth;

	int sampleWidth;
	int sampleHeight;
	int channelsCount;

	DeviceType deviceType;
	size_t memoryLimit;

	BlobDataType blobDataType;
	ClassificationSettings classificationSettings;
};

}